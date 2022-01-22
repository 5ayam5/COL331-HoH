#pragma once
#include "util/config.h"
#include "util/debug.h"
#define BUF_LEN 100
#define MAX_OPS 10
#define MAX_ARGS 10
#define FACTORIAL 16
#define FIBBONACCI 17
#define ADD 32

struct shellstate_t{
  uint32_t key_count;
  const char *options[MAX_OPS];
  uint8_t len, highlighted, state, refresh, curr_arg, max_args, input_len[MAX_ARGS];
  int active_func;
  char output[BUF_LEN];
  char input[MAX_ARGS][BUF_LEN];
};

struct renderstate_t{
  uint32_t key_count;
  const char *options[MAX_OPS];
  uint8_t len, highlighted, refresh, curr_arg;
  int active_func;
  char output[BUF_LEN];
  const char *input[MAX_ARGS];
};

void shell_init(shellstate_t& state);
void shell_update(uint8_t scankey, shellstate_t& stateinout);
void shell_step(shellstate_t& stateinout);
void shell_render(const shellstate_t& shell, renderstate_t& render);

bool render_eq(const renderstate_t& a, const renderstate_t& b);
void render(const renderstate_t& state, int w, int h, addr_t display_base);

