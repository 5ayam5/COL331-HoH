#pragma once
#include "util/config.h"
#include "util/debug.h"
#define BUF_LEN 100
#define MAX_OPS 10
#define MAX_ARGS 10

struct shellstate_t{
  uint32_t key_count;
  const char *options[MAX_OPS];
  uint8_t len, highlighted, state, execution, refresh, curr_arg, input_len[MAX_ARGS];
  const char *output;
  char input[MAX_ARGS][BUF_LEN];
};

struct renderstate_t{
  uint32_t key_count;
  const char *options[MAX_OPS];
  uint8_t len, highlighted, refresh;
  const char *output;
  const char *input[MAX_ARGS];
};

void shell_init(shellstate_t& state);
void shell_update(uint8_t scankey, shellstate_t& stateinout);
void shell_step(shellstate_t& stateinout);
void shell_render(const shellstate_t& shell, renderstate_t& render);

bool render_eq(const renderstate_t& a, const renderstate_t& b);
void render(const renderstate_t& state, int w, int h, addr_t display_base);

