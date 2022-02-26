#pragma once
#include "util/config.h"
#include "util/debug.h"

#define BUF_LEN 80
#define MAX_OPS 10
#define MAX_ARGS 10
#define MAX_LINES 9
#define MOD 1000000007

// shell states encoding
#define START_MENU 0 // from 0-15 we have states where are only taking no input
#define FUNCTIONS_MENU 1
#define SETTINGS_MENU 2
#define COLOR_SETTINGS_MENU 3
#define LONG_COMPUTATION_MENU 4
#define TEXT_COLOR                                                             \
  16 // from 16-31 we have states where we are taking 1 argument from user
#define OUTPUT_COLOR 17
#define BACKGROUND_COLOR 18
#define HIGHLIGHT_COLOR 19
#define SELECTED_COLOR 20
#define FACTORIAL 21
#define FIBBONACCI 22
#define ECHO 23
#define ADD 32 // from 32 we keep the states where we are taking 2 arguments
#define FIB_COROUTINE 48
#define FIB_FIBER                                                              \
  49 // from 48 we keep the states where we are doing long computation

// key encodings
#define RIGHT_KEY 0x4d
#define LEFT_KEY 0x4b
#define ENTER_KEY 0x1c
#define BACKSPACE_KEY 0x0e
#define ESCAPE_KEY 0x01

// color codings
#define BLACK 0x0
#define BLUE 0x1
#define GREEN 0x2
#define CYAN 0x3
#define RED 0x4
#define MAGENTA 0x5
#define ORANGE 0x6
#define WHITE 0x7

// execution state
#define START 0
#define RUNNING 1
#define DONE 2

struct fiber_t {
  uint32_t args[MAX_ARGS], ret_val;
  uint8_t state;
};

struct shellstate_t {
  uint32_t key_count;
  const char *options[MAX_OPS];
  uint8_t len, highlighted, state, refresh, curr_arg, max_args, active_func,
      input_len[MAX_ARGS];
  char output[MAX_LINES][BUF_LEN];
  char input[MAX_ARGS][BUF_LEN];
  uint8_t background_color, text_color, output_color, highlight_color,
      selected_color;
  struct fiber_t fiber;

  void shell_out(const char *buf);
};

struct renderstate_t {
  uint32_t key_count;
  const char *options[MAX_OPS];
  uint8_t len, highlighted, refresh, curr_arg, active_func;
  char output[MAX_LINES][BUF_LEN];
  const char *input[MAX_ARGS];
  uint8_t background_color, text_color, output_color, highlight_color,
      selected_color;
};

void shell_init(shellstate_t &state);
void shell_update(uint8_t scankey, shellstate_t &stateinout);
void shell_step(shellstate_t &stateinout);
void shell_render(const shellstate_t &shell, renderstate_t &render);

bool render_eq(const renderstate_t &a, const renderstate_t &b);
void render(const renderstate_t &state, int w, int h, addr_t display_base);

bool strcmp(const char *a, const char *b);
void strcpy(char *a, const char *b);
uint8_t strlen(const char *str);
uint32_t str_to_int(const char *str);
void parse_args(char input[MAX_ARGS][BUF_LEN], uint8_t curr_arg,
                uint32_t *output);
void int_to_string(uint32_t val, char *buf);
void shell_refresh(shellstate_t &state, uint8_t flag);
