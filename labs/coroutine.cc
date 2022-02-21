#include "labs/coroutine.h"

void coroutine_fib(shellstate_t &shellstate, coroutine_t &f_coro, f_t &f_locals){
  uint32_t &tmp = f_locals.tmp;
  uint32_t &n = f_locals.n;
  uint8_t &state = f_locals.state;
  uint32_t &ret_val = f_locals.ret_val;

  h_begin(f_coro);
  state = RUNNING;
  tmp = 1, ret_val = 0;

  while (n--) {
    int tmp1 = ret_val;
    ret_val = (ret_val + tmp) % MOD;
    tmp = tmp1;
    if (n % 1000000 == 0)
      h_yield(f_coro);
  }
  state = DONE;
  h_end(f_coro);
}


void shell_step_coroutine(shellstate_t &shellstate, coroutine_t &f_coro, f_t &f_locals){
  if (shellstate.state != FIB_COROUTINE) {
    f_locals.state = START;
    coroutine_reset(f_coro);
    return;
  }
  if (shellstate.curr_arg < shellstate.max_args)
    return;
  switch (f_locals.state) {
  case START:
    uint32_t args[MAX_ARGS];
    parse_args(shellstate.input, shellstate.max_args, args);
    f_locals.n = args[0];
  case RUNNING:
    coroutine_fib(shellstate, f_coro, f_locals);
    break;
  case DONE:
    int_to_string(f_locals.ret_val, shellstate.output);
    shell_refresh(shellstate, FUNCTIONS_MENU);
    f_locals.state = START;
    coroutine_reset(f_coro);
    break;
  }
}
