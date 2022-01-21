#include "labs/shell.h"
#include "labs/vgatext.h"

bool strcmp(const char *a, const char *b){
  while (*a && *b && *a == *b)
    a++;
  return *a == *b;
}

uint8_t strlen(const char *str){
  uint8_t len = 0;
  while (*str++)
    len++;
  return len;
}

uint32_t str_to_int(const char *str){
  uint8_t len = strlen(str);
  uint32_t val = 0;
  for (uint8_t i = 0; i < len; i++)
    val = val * 10 + str[i] - '0';
  // hoh_debug(val<<" "<<str);
  return val;
}

void parseArgs(char input[MAX_ARGS][BUF_LEN], uint8_t curr_arg, uint32_t *output){
  for(int i=0;i<curr_arg;i++){
    output[i] = str_to_int(input[i]);
  }
}

//
// initialize shellstate
//


//functions settings
void shell_init(shellstate_t& state){
  state.key_count = 0;
  state.options[0] = "functions";
  state.options[1] = "settings";
  state.len = 2;
  state.highlighted = 0;
  state.state = 0;
  state.execution = 0;
  state.output = NULL;
  for(int i=0;i<MAX_ARGS;i++){
    state.input[i][0] = 0;
    state.input_len[i] = 0;
  }
  state.refresh = 0;
  state.curr_arg = 0;
}

//
// handle keyboard event.
// key is in scancode format.
// For ex:
// scancode for following keys are:
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     | esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |back|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 01  | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 0a | 0b | 0c | 0d | 0e |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     | tab |  q |  w |  e |  r |  t |  y |  u |  i |  o |  p |  [ |  ] |entr|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 0f  | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 1a | 1b | 1c |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | keys     |ctrl |  a |  s |  d |  f |  g |  h |  j |  k |  l |  ; |  ' |    |shft|
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//      | scancode | 1d  | 1e | 1f | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 2a |
//      +----------+-----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//
// so and so..
//
// - restrict yourself to: 0-9, a-z, esc, enter, arrows
// - ignore other keys like shift, control keys
// - only handle the keys which you're interested in
// - for example, you may want to handle up(0x48),down(0x50) arrow keys for menu.
//

char key_mapping(uint8_t scancode){
  char key = 0;
  switch(scancode){
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
    default:
      key = -1;
  }
  return key;
}


void changeState(shellstate_t& stateinout){
  int8_t newState;
  if(stateinout.state == 0){
    if(stateinout.highlighted == 0){
      newState = 1;
    }else if(stateinout.highlighted == 1){
      newState = 2;
    }
  }else if(stateinout.state == 1){
    switch(stateinout.highlighted){
      case 0: 
        newState = 3;
        break;
      case 1:
        newState = 4;
        break;
      case 2:
        newState = 0;
        break;  
    }
  }else if(stateinout.state == 2){
    if(stateinout.highlighted == 2){
      newState = 0;
    }
  }else if(stateinout.state >= 3){
    stateinout.curr_arg++;
    return;
  }
  stateinout.state = newState;
  stateinout.highlighted = 0;
  stateinout.output = NULL;
  stateinout.refresh=1;
  switch(newState){
    case 0: 
      stateinout.len = 2;
      stateinout.options[0] = "functions";
      stateinout.options[1] = "settings";
      break;
    case 1:
      stateinout.len = 3;
      stateinout.options[0] = "factorial";
      stateinout.options[1] = "fibonacci";
      stateinout.options[2] = "back";
      break;
    case 2:
      stateinout.len = 3;
      stateinout.options[0] = "color";
      stateinout.options[1] = "reset";
      stateinout.options[2] = "back";
      break;
  }
}

void shell_update(uint8_t scankey, shellstate_t& stateinout){
  stateinout.key_count++;
  uint8_t arg = stateinout.curr_arg;
  switch (scankey){
    case 0x4b:
      if (stateinout.highlighted > 0)
        stateinout.highlighted--;
      break;
    case 0x4d:
      if (stateinout.highlighted < stateinout.len - 1)
        stateinout.highlighted++;
      break;
    case 0x1c:
      changeState(stateinout);
      break;
    case 0x0e:
      if(stateinout.state>2){
        if(stateinout.input_len[arg] > 0){
          stateinout.input[arg][--stateinout.input_len[arg]] = 0;
        }
      }
      break;
    default:
      if(stateinout.state>2){
        char key = key_mapping(scankey);
        if(stateinout.input_len[arg] < BUF_LEN-1 && key != -1){
          stateinout.input[arg][stateinout.input_len[arg]++] = key;
          stateinout.input[arg][stateinout.input_len[arg]] = 0;
        }
      }
      break;
  }
  hoh_debug("Got: "<<unsigned(scankey));
}


//
// do computation
//
void shell_step(shellstate_t& stateinout){
  if(stateinout.state < 3){
    return;
  }else if (stateinout.state <= 7){
    if(stateinout.curr_arg < 2){
      return;
    }
    uint32_t args[MAX_ARGS];
    parseArgs(stateinout.input, stateinout.curr_arg,args);
    hoh_debug("args: "<<args[0]<<" "<<args[1]);
  }
}


//
// shellstate --> renderstate
//
void shell_render(const shellstate_t& shell, renderstate_t& render){
  render.key_count = shell.key_count;
  render.len = shell.len;
  for (int i = 0; i < shell.len; i++){
    render.options[i] = shell.options[i];
  }
  render.highlighted = shell.highlighted;
  render.output = shell.output;
  render.refresh = shell.refresh;
  for(int i = 0; i < MAX_ARGS; i++){
    render.input[i] = shell.input[i];
  }
}


//
// compare a and b
//
bool render_eq(const renderstate_t& a, const renderstate_t& b){
  bool ret = a.key_count == b.key_count && a.len == b.len && a.highlighted == b.highlighted && a.refresh == b.refresh && strcmp(a.output, b.output) == 0;
  if (!ret)
    return ret;
  for (int i = 0; i < a.len; i++){
    ret = ret && strcmp(a.options[i], b.options[i]) == 0;
  }
  return ret;
}


static void writecharxy(int x, int y, uint8_t c, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);
static void fillrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);
static void drawrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);
static void drawtext(int x,int y, const char* str, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);
static void drawnumberinhex(int x,int y, uint32_t number, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base);

//
// Given a render state, we need to write it into vgatext buffer
//
void render(const renderstate_t& state, int w, int h, addr_t vgatext_base){
  if(state.refresh){
    fillrect(0, h - 3, w, h, 0x0, 0x0, w, h, vgatext_base);
  }
  fillrect(0, 0, w, h-3, 0x0, 0x0, w, h, vgatext_base);
  for(int i=0;i<MAX_ARGS;i++){
    drawtext(0, i, state.input[i], BUF_LEN, 0x0, 0x7, w, h, vgatext_base);
  }
  drawrect(0, h - 3, w, h, 0x7, 0x0, w, h, vgatext_base);
  drawnumberinhex(w - 10, h - 2, state.key_count, 8, 0, 0x7, w, h, vgatext_base);
  uint8_t loc = 2;
  for (int i = 0; i < state.len; ++i){
    if (i == state.highlighted)
      drawtext(loc, h - 2, state.options[i], 10, 0x2, 0x6, w, h, vgatext_base);
    else
      drawtext(loc, h - 2, state.options[i], 10, 0, 0x7, w, h, vgatext_base);
    loc += strlen(state.options[i]) + 4;
  }
}


//
//
// helper functions
//
//

static void writecharxy(int x, int y, uint8_t c, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  vgatext::writechar(y*w+x,c,bg,fg,vgatext_base);
}

static void fillrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  for(int y=y0;y<y1;y++){
    for(int x=x0;x<x1;x++){
      writecharxy(x,y,0,bg,fg,w,h,vgatext_base);
    }
  }
}

static void drawrect(int x0, int y0, int x1, int y1, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){

  writecharxy(x0,  y0,  0xc9, bg,fg, w,h,vgatext_base);
  writecharxy(x1-1,y0,  0xbb, bg,fg, w,h,vgatext_base);
  writecharxy(x0,  y1-1,0xc8, bg,fg, w,h,vgatext_base);
  writecharxy(x1-1,y1-1,0xbc, bg,fg, w,h,vgatext_base);

  for(int x=x0+1; x+1 < x1; x++){
    writecharxy(x,y0, 0xcd, bg,fg, w,h,vgatext_base);
  }

  for(int x=x0+1; x+1 < x1; x++){
    writecharxy(x,y1-1, 0xcd, bg,fg, w,h,vgatext_base);
  }

  for(int y=y0+1; y+1 < y1; y++){
    writecharxy(x0,y, 0xba, bg,fg, w,h,vgatext_base);
  }

  for(int y=y0+1; y+1 < y1; y++){
    writecharxy(x1-1,y, 0xba, bg,fg, w,h,vgatext_base);
  }
}

static void drawtext(int x,int y, const char* str, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  for(int i=0;i<maxw;i++){
    if(!str[i]){
      break;
    }
    writecharxy(x+i,y,str[i],bg,fg,w,h,vgatext_base);
  }
}

static void drawnumberinhex(int x,int y, uint32_t number, int maxw, uint8_t bg, uint8_t fg, int w, int h, addr_t vgatext_base){
  enum {max=sizeof(uint32_t)*2+1};
  char a[max];
  for(int i=0;i<max-1;i++){
    a[max-1-i-1]=hex2char(number%16);
    number=number/16;
  }
  a[max-1]='\0';

  drawtext(x,y,a,maxw,bg,fg,w,h,vgatext_base);
}

