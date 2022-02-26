#include "labs/shell.h"
#include "labs/vgatext.h"

// helpful functions

bool strcmp(const char *a, const char *b) {
  while (*a && *b && *a == *b)
    a++;
  return *a == *b;
}

void strcpy(char *a, const char *b) {
  while (*b)
    *a++ = *b++;
  *a = 0;
}

uint8_t strlen(const char *str) {
  uint8_t len = 0;
  while (*str++)
    len++;
  return len;
}

uint32_t str_to_int(const char *str) {
  uint8_t len = strlen(str);
  uint32_t val = 0;
  for (uint8_t i = 0; i < len; i++)
    val = val * 10 + str[i] - '0';
  return val;
}

void parse_args(char input[MAX_ARGS][BUF_LEN], uint8_t curr_arg,
                uint32_t *output) {
  for (int i = 0; i < curr_arg; i++) {
    output[i] = str_to_int(input[i]);
  }
}

void int_to_string(uint32_t val, char *buf) {
  if (val == 0) {
    buf[0] = '0';
    buf[1] = '\0';
    return;
  }
  uint8_t len = 0;
  while (val) {
    buf[len++] = '0' + val % 10;
    val /= 10;
  }
  buf[len] = '\0';
  for (uint8_t i = 0; i < len / 2; i++) {
    char tmp = buf[i];
    buf[i] = buf[len - i - 1];
    buf[len - i - 1] = tmp;
  }
}

// shell commands

uint32_t factorial(uint32_t n) {
  uint32_t ret = n;
  ret %= MOD;
  if (n == 0)
    ret = 1;
  while (n > 1)
    ret = (ret * (--n)) % MOD;
  return ret;
}

uint32_t fibonacci(uint32_t n) {
  uint32_t a = 1, b = 0, c = 0;
  while (n--) {
    c = (a + b) % MOD;
    a = b;
    b = c;
  }
  return c;
}

uint32_t add(uint32_t a, uint32_t b) { return a + b; }

void shellstate_t::shell_out(const char *buf)
{
  for (uint8_t i = 0; i < MAX_LINES - 1; i++)
    for (uint8_t j = 0; j < BUF_LEN; j++)
      this->output[i][j] = this->output[i + 1][j];
  for (uint8_t i = 0; i < BUF_LEN; i++)
    this->output[MAX_LINES - 1][i] = buf[i];
  this->refresh |= 4;
}

//
// initialize shellstate
//

// initialize renderstate
void colors_init(shellstate_t &state) {
  state.background_color = BLACK;
  state.text_color = WHITE;
  state.output_color = MAGENTA;
  state.highlight_color = GREEN;
  state.selected_color = RED;
}

void shell_init(shellstate_t &state) {
  state.active_func = -1;
  state.key_count = 0;
  state.options[0] = "functions";
  state.options[1] = "settings";
  state.len = 2;
  state.highlighted = 0;
  state.state = 0;
  for (uint8_t i = 0; i < MAX_ARGS; i++) {
    state.input[i][0] = 0;
    state.input_len[i] = 0;
  }
  for (uint8_t i = 0; i < MAX_LINES; i++)
    state.output[i][0] = 0;
  state.refresh = 7;
  state.curr_arg = 0;
  state.max_args = MAX_ARGS;
  colors_init(state);
}

void setMenu(shellstate_t &stateinout, uint8_t newState) {
  stateinout.refresh |= 1;
  switch (newState) {
  case START_MENU:
    stateinout.len = 2;
    stateinout.options[0] = "functions";
    stateinout.options[1] = "settings";
    break;
  case FUNCTIONS_MENU:
    stateinout.len = 6;
    stateinout.options[0] = "back";
    stateinout.options[1] = "factorial";
    stateinout.options[2] = "fibonacci";
    stateinout.options[3] = "add";
    stateinout.options[4] = "echo";
    stateinout.options[5] = "long";
    break;
  case SETTINGS_MENU:
    stateinout.len = 3;
    stateinout.options[0] = "back";
    stateinout.options[1] = "color";
    stateinout.options[2] = "reset";
    break;
  case COLOR_SETTINGS_MENU:
    stateinout.len = 6;
    stateinout.options[0] = "back";
    stateinout.options[1] = "text";
    stateinout.options[2] = "outputs";
    stateinout.options[3] = "background";
    stateinout.options[4] = "highlight";
    stateinout.options[5] = "selected";
    break;
  case LONG_COMPUTATION_MENU:
    stateinout.len = 3;
    stateinout.options[0] = "back";
    stateinout.options[1] = "coroutine_fib";
    stateinout.options[2] = "fiber_fib";
  }
}

void shell_refresh(shellstate_t &state, uint8_t flag) {
  state.active_func = -1;
  state.state = flag;
  setMenu(state, flag);

  for (int i = 0; i < MAX_ARGS; i++) {
    state.input[i][0] = 0;
    state.input_len[i] = 0;
  }
  state.refresh = 7;
  state.curr_arg = 0;
  state.max_args = MAX_ARGS;
}

//
// handle keyboard event.
// key is in scancode format.
// For ex:
// scancode for following keys are:
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     | esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  -
//      |  = |back|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 01  | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 0a | 0b | 0c
//      | 0d | 0e |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     | tab |  q |  w |  e |  r |  t |  y |  u |  i |  o |  p |  [
//      |  ] |entr|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 0f  | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 1a
//      | 1b | 1c |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     |ctrl |  a |  s |  d |  f |  g |  h |  j |  k |  l |  ; |  '
//      |    |shft|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 1d  | 1e | 1f | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28
//      | 29 | 2a |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
// so and so..
//
// - restrict yourself to: 0-9, a-z, esc, enter, arrows
// - ignore other keys like shift, control keys
// - only handle the keys which you're interested in
// - for example, you may want to handle up(0x48),down(0x50) arrow keys for
// menu.
//

char key_mapping(uint8_t scancode) {
  char key = 0;
  switch (scancode) {
  case 0x02:
    key = '1';
    break;
  case 0x03:
    key = '2';
    break;
  case 0x04:
    key = '3';
    break;
  case 0x05:
    key = '4';
    break;
  case 0x06:
    key = '5';
    break;
  case 0x07:
    key = '6';
    break;
  case 0x08:
    key = '7';
    break;
  case 0x09:
    key = '8';
    break;
  case 0x0a:
    key = '9';
    break;
  case 0x0b:
    key = '0';
    break;
  case 0x10:
    key = 'q';
    break;
  case 0x11:
    key = 'w';
    break;
  case 0x12:
    key = 'e';
    break;
  case 0x13:
    key = 'r';
    break;
  case 0x14:
    key = 't';
    break;
  case 0x15:
    key = 'y';
    break;
  case 0x16:
    key = 'u';
    break;
  case 0x17:
    key = 'i';
    break;
  case 0x18:
    key = 'o';
    break;
  case 0x19:
    key = 'p';
    break;
  case 0x1e:
    key = 'a';
    break;
  case 0x1f:
    key = 's';
    break;
  case 0x20:
    key = 'd';
    break;
  case 0x21:
    key = 'f';
    break;
  case 0x22:
    key = 'g';
    break;
  case 0x23:
    key = 'h';
    break;
  case 0x24:
    key = 'j';
    break;
  case 0x25:
    key = 'k';
    break;
  case 0x26:
    key = 'l';
    break;
  case 0x2c:
    key = 'z';
    break;
  case 0x2d:
    key = 'x';
    break;
  case 0x2e:
    key = 'c';
    break;
  case 0x2f:
    key = 'v';
    break;
  case 0x30:
    key = 'b';
    break;
  case 0x31:
    key = 'n';
    break;
  case 0x32:
    key = 'm';
    break;
  case 0x39:
    key = ' ';
    break;
  default:
    key = -1;
  }
  return key;
}

void changeState(shellstate_t &stateinout) {
  uint8_t newState = stateinout.state;
  if (stateinout.state == START_MENU) {
    if (stateinout.highlighted == 0) {
      newState = FUNCTIONS_MENU;
    } else if (stateinout.highlighted == 1) {
      newState = SETTINGS_MENU;
    }
    stateinout.highlighted = 0;
  } else if (stateinout.state == FUNCTIONS_MENU) {
    switch (stateinout.highlighted) {
    case 0:
      newState = START_MENU;
      stateinout.highlighted = 0;
      break;
    case 1:
      stateinout.state = FACTORIAL;
      stateinout.max_args = 1;
      stateinout.active_func = stateinout.highlighted;
      return;
    case 2:
      stateinout.state = FIBBONACCI;
      stateinout.max_args = 1;
      stateinout.active_func = stateinout.highlighted;
      return;
    case 3:
      stateinout.state = ADD;
      stateinout.max_args = 2;
      stateinout.active_func = stateinout.highlighted;
      return;
    case 4:
      stateinout.state = ECHO;
      stateinout.max_args = 1;
      stateinout.active_func = stateinout.highlighted;
      return;
    case 5:
      newState = LONG_COMPUTATION_MENU;
      stateinout.highlighted = 0;
      break;
    }
  } else if (stateinout.state == SETTINGS_MENU) {
    switch (stateinout.highlighted) {
    case 0:
      newState = START_MENU;
      stateinout.highlighted = 0;
      break;
    case 1:
      newState = COLOR_SETTINGS_MENU;
      stateinout.highlighted = 0;
      break;
    case 2:
      shell_init(stateinout);
      shell_refresh(stateinout, stateinout.state);
      return;
    }
  } else if (stateinout.state == COLOR_SETTINGS_MENU) {
    if (stateinout.highlighted == 0) {
      stateinout.highlighted = 0;
      newState = SETTINGS_MENU;
    } else {
      switch (stateinout.highlighted) {
      case 1:
        stateinout.state = TEXT_COLOR;
        break;
      case 2:
        stateinout.state = OUTPUT_COLOR;
        break;
      case 3:
        stateinout.state = BACKGROUND_COLOR;
        break;
      case 4:
        stateinout.state = HIGHLIGHT_COLOR;
        break;
      case 5:
        stateinout.state = SELECTED_COLOR;
        break;
      }
      stateinout.max_args = 1;
      stateinout.active_func = stateinout.highlighted;
      const char *str = "0: Black, 1: Blue, 2: Green, 3: Cyan, 4: Red, 5: "
                        "Magenta, 6: Orange, 7: White";
      stateinout.shell_out(str);
      return;
    }
  } else if (stateinout.state == LONG_COMPUTATION_MENU) {
    switch (stateinout.highlighted) {
    case 0:
      newState = FUNCTIONS_MENU;
      stateinout.highlighted = 0;
      break;
    case 1:
      stateinout.state = FIB_COROUTINE;
      stateinout.max_args = 1;
      stateinout.active_func = stateinout.highlighted;
      return;
    case 2:
      stateinout.state = FIB_FIBER;
      stateinout.max_args = 1;
      stateinout.active_func = stateinout.highlighted;
      return;
    }
  } else if (stateinout.state >= 16) {
    stateinout.curr_arg++;
    return;
  }
  stateinout.state = newState;
  setMenu(stateinout, newState);
}

void shell_update(uint8_t scankey, shellstate_t &stateinout) {
  stateinout.key_count++;
  stateinout.refresh = 0;
  uint8_t arg = stateinout.curr_arg;
  switch (scankey) {
  case LEFT_KEY:
    if (stateinout.highlighted > 0)
      stateinout.highlighted--;
    else
      stateinout.highlighted = stateinout.len - 1;
    break;
  case RIGHT_KEY:
    if (stateinout.highlighted < stateinout.len - 1)
      stateinout.highlighted++;
    else
      stateinout.highlighted = 0;
    break;
  case ENTER_KEY:
    if (stateinout.curr_arg < stateinout.max_args)
      changeState(stateinout);
    break;
  case BACKSPACE_KEY:
    if (stateinout.curr_arg < stateinout.max_args)
      if (stateinout.state >= 16) {
        stateinout.refresh |= 2;
        if (stateinout.input_len[arg] > 0) {
          stateinout.input[arg][--stateinout.input_len[arg]] = 0;
        }
      }
    break;
  case ESCAPE_KEY:
    if (TEXT_COLOR <= stateinout.state && stateinout.state <= SELECTED_COLOR) {
      shell_refresh(stateinout, COLOR_SETTINGS_MENU);
    } else if (FACTORIAL <= stateinout.state &&
               stateinout.state < FIB_COROUTINE) {
      shell_refresh(stateinout, FUNCTIONS_MENU);
    } else if (FIB_COROUTINE <= stateinout.state) {
      shell_refresh(stateinout, LONG_COMPUTATION_MENU);
    }
    break;
  default:
    if (stateinout.curr_arg < stateinout.max_args)
      if (stateinout.state >= 16) {
        stateinout.refresh |= 2;
        char key = key_mapping(scankey);
        if (stateinout.input_len[arg] < BUF_LEN - 1 && key != (char)-1) {
          stateinout.input[arg][stateinout.input_len[arg]++] = key;
          stateinout.input[arg][stateinout.input_len[arg]] = 0;
        }
      }
    break;
  }
  if (stateinout.refresh)
    stateinout.refresh |= 8;
  hoh_debug("Got: " << unsigned(scankey));
}

uint8_t contrast_color(uint8_t color) { return WHITE - color; }

// to switch the colors, this also takes care no 2 things are assigned the same
// color
void change_color(shellstate_t &stateinout, uint8_t color) {
  if (color > 7) {
    const char *str = "Invalid index entered, please choose an index from 0 to 7";
    stateinout.shell_out(str);
    return;
  }
  switch (stateinout.state) {
  case TEXT_COLOR:
    stateinout.text_color = color;
    break;
  case OUTPUT_COLOR:
    stateinout.output_color = color;
    break;
  case BACKGROUND_COLOR:
    stateinout.background_color = color;
    if (stateinout.background_color == stateinout.text_color) {
      stateinout.text_color = contrast_color(stateinout.background_color);
    }
    if (stateinout.background_color == stateinout.output_color) {
      stateinout.output_color = contrast_color(stateinout.background_color);
    }
    if (stateinout.background_color == stateinout.highlight_color) {
      stateinout.highlight_color = contrast_color(stateinout.background_color);
    }
    if (stateinout.background_color == stateinout.selected_color) {
      stateinout.selected_color = contrast_color(stateinout.background_color);
    }
    return;
  case HIGHLIGHT_COLOR:
    stateinout.highlight_color = color;
    break;
  case SELECTED_COLOR:
    stateinout.selected_color = color;
  }
  if (stateinout.background_color == color) {
    stateinout.background_color = contrast_color(color);
  }
}

//
// do computation
//
void shell_step(shellstate_t &stateinout) {
  if (stateinout.refresh & 8)
    stateinout.refresh ^= 8;
  else
    stateinout.refresh = 0;
  if (stateinout.state == FIB_COROUTINE || stateinout.state == FIB_FIBER)
    return;
  if (stateinout.state <= 3) {
    return;
  } else if (stateinout.state < 16) {
    return;
  } else {
    if (stateinout.curr_arg < stateinout.max_args) {
      return;
    }
    uint32_t args[MAX_ARGS];
    if (TEXT_COLOR <= stateinout.state && stateinout.state <= SELECTED_COLOR) {
      parse_args(stateinout.input, stateinout.max_args, args);
      change_color(stateinout, args[0]);
      shell_refresh(stateinout, COLOR_SETTINGS_MENU);
    } else {
        char buf[BUF_LEN] = {0};
      switch (stateinout.state) {
      case FACTORIAL:
        parse_args(stateinout.input, stateinout.max_args, args);
        int_to_string(factorial(args[0]), buf);
        stateinout.shell_out(buf);
        break;
      case FIBBONACCI:
        parse_args(stateinout.input, stateinout.max_args, args);
        int_to_string(fibonacci(args[0]), buf);
        stateinout.shell_out(buf);
        break;
      case ADD:
        parse_args(stateinout.input, stateinout.max_args, args);
        int_to_string(add(args[0], args[1]), buf);
        stateinout.shell_out(buf);
        break;
      case ECHO:
        stateinout.shell_out(stateinout.input[0]);
        break;
      }
      shell_refresh(stateinout, FUNCTIONS_MENU);
    }
  }
}

//
// shellstate --> renderstate
//
void shell_render(const shellstate_t &shell, renderstate_t &render) {
  render.active_func = shell.active_func;
  render.key_count = shell.key_count;
  render.len = shell.len;
  for (int i = 0; i < shell.len; i++) {
    render.options[i] = shell.options[i];
  }
  render.highlighted = shell.highlighted;
  render.refresh = shell.refresh;
  for (uint8_t i = 0; i < MAX_LINES; i++)
    for (uint8_t j = 0; j < BUF_LEN; j++)
      render.output[i][j] = shell.output[i][j];
  render.curr_arg = shell.curr_arg;
  for (uint8_t i = 0; i <= shell.curr_arg; i++) {
    render.input[i] = shell.input[i];
  }
  render.background_color = shell.background_color;
  render.text_color = shell.text_color;
  render.highlight_color = shell.highlight_color;
  render.selected_color = shell.selected_color;
  render.output_color = shell.output_color;
}

//
// compare a and b
//
bool render_eq(const renderstate_t &a, const renderstate_t &b) {
  bool ret = a.key_count == b.key_count && a.len == b.len &&
             a.highlighted == b.highlighted && a.refresh == b.refresh &&
             a.curr_arg == b.curr_arg && a.active_func == b.active_func &&
             strcmp(a.output[MAX_LINES - 1], b.output[MAX_LINES - 1]) == 0;
  if (!ret)
    return ret;
  for (int i = 0; i < a.len; i++) {
    ret = ret && strcmp(a.options[i], b.options[i]) == 0;
  }
  for (int i = 0; i < a.curr_arg; i++) {
    ret = ret && strcmp(a.input[i], b.input[i]) == 0;
  }
  return ret;
}

static void writecharxy(int x, int y, uint8_t c, uint8_t bg, uint8_t fg, int w,
                        int h, addr_t vgatext_base);
static void fillrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg,
                     int w, int h, addr_t vgatext_base);
static void drawrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg,
                     int w, int h, addr_t vgatext_base);
static void drawtext(int x, int y, const char *str, int maxw, uint8_t bg,
                     uint8_t fg, int w, int h, addr_t vgatext_base);
static void drawnumberinhex(int x, int y, uint32_t number, int maxw, uint8_t bg,
                            uint8_t fg, int w, int h, addr_t vgatext_base);

//
// Given a render state, we need to write it into vgatext buffer
//
void render(const renderstate_t &state, int w, int h, addr_t vgatext_base) {
  if (state.refresh & 1) {
    fillrect(0, h - 3, w, h, state.background_color, state.background_color, w,
             h, vgatext_base);
  }
  if (state.refresh & 2) {
    fillrect(0, 0, w, MAX_ARGS, state.background_color, state.background_color, w,
             h, vgatext_base);
  }
  if (state.refresh & 4) {
    fillrect(0, MAX_ARGS + 2, w, h - 3, state.background_color, state.background_color, w,
             h, vgatext_base);
  }
  for (int i = 0; i <= state.curr_arg; i++) {
    drawtext(0, i, state.input[i], BUF_LEN, state.background_color,
             state.text_color, w, h, vgatext_base);
  }
  for (int x = 0; x + 1 <= w; x++) {
    writecharxy(x, MAX_ARGS + 1, 0xc4, state.background_color,
                contrast_color(state.background_color), w, h, vgatext_base);
  }
  for (uint8_t i = 0; i < MAX_LINES; i++)
    drawtext(0, MAX_ARGS + 2 + i, state.output[i], BUF_LEN, state.background_color,
             state.output_color, w, h, vgatext_base);

  // menu rendering
  drawrect(0, h - 3, w, h, contrast_color(state.background_color),
           state.background_color, w, h, vgatext_base);
  drawnumberinhex(w - 10, h - 2, state.key_count, 8, state.background_color,
                  state.text_color, w, h, vgatext_base);
  uint8_t loc = 2;
  for (int i = 0; i < state.len; i++) {
    if (i == state.active_func) {
      drawtext(loc, h - 2, state.options[i], BUF_LEN, state.selected_color,
               contrast_color(state.selected_color), w, h, vgatext_base);
    } else if (i == state.highlighted)
      drawtext(loc, h - 2, state.options[i], BUF_LEN, state.highlight_color,
               contrast_color(state.highlight_color), w, h, vgatext_base);
    else
      drawtext(loc, h - 2, state.options[i], BUF_LEN, state.background_color,
               state.text_color, w, h, vgatext_base);
    loc += strlen(state.options[i]) + 2;
  }
}

//
//
// helper functions
//
//

static void writecharxy(int x, int y, uint8_t c, uint8_t bg, uint8_t fg, int w,
                        int h, addr_t vgatext_base) {
  vgatext::writechar(y * w + x, c, bg, fg, vgatext_base);
}

static void fillrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg,
                     int w, int h, addr_t vgatext_base) {
  for (int y = y0; y < y1; y++) {
    for (int x = x0; x < x1; x++) {
      writecharxy(x, y, 0, bg, fg, w, h, vgatext_base);
    }
  }
}

static void drawrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg,
                     int w, int h, addr_t vgatext_base) {

  writecharxy(x0, y0, 0xc9, bg, fg, w, h, vgatext_base);
  writecharxy(x1 - 1, y0, 0xbb, bg, fg, w, h, vgatext_base);
  writecharxy(x0, y1 - 1, 0xc8, bg, fg, w, h, vgatext_base);
  writecharxy(x1 - 1, y1 - 1, 0xbc, bg, fg, w, h, vgatext_base);

  for (int x = x0 + 1; x + 1 < x1; x++) {
    writecharxy(x, y0, 0xcd, bg, fg, w, h, vgatext_base);
  }

  for (int x = x0 + 1; x + 1 < x1; x++) {
    writecharxy(x, y1 - 1, 0xcd, bg, fg, w, h, vgatext_base);
  }

  for (int y = y0 + 1; y + 1 < y1; y++) {
    writecharxy(x0, y, 0xba, bg, fg, w, h, vgatext_base);
  }

  for (int y = y0 + 1; y + 1 < y1; y++) {
    writecharxy(x1 - 1, y, 0xba, bg, fg, w, h, vgatext_base);
  }
}

static void drawtext(int x, int y, const char *str, int maxw, uint8_t bg,
                     uint8_t fg, int w, int h, addr_t vgatext_base) {
  for (int i = 0; i < maxw; i++) {
    if (!str[i]) {
      break;
    }
    writecharxy(x + i, y, str[i], bg, fg, w, h, vgatext_base);
  }
}

static void drawnumberinhex(int x, int y, uint32_t number, int maxw, uint8_t bg,
                            uint8_t fg, int w, int h, addr_t vgatext_base) {
  enum { max = sizeof(uint32_t) * 2 + 1 };
  char a[max];
  for (int i = 0; i < max - 1; i++) {
    a[max - 1 - i - 1] = hex2char(number % 16);
    number = number / 16;
  }
  a[max - 1] = '\0';

  drawtext(x, y, a, maxw, bg, fg, w, h, vgatext_base);
}
