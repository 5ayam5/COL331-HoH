#include "labs/fiber.h"

void fiber_fib(addr_t *pmain_stack, addr_t *pf_stack, fiber_t *fiber) {
  addr_t &main_stack = *pmain_stack;
  addr_t &f_stack = *pf_stack;
  uint32_t &n = fiber->args[0];
  uint8_t &state = fiber->state;
  uint32_t &ret_val = fiber->ret_val;
  state = RUNNING;

  uint32_t a = 1, b = 0;
  ret_val = 0;
  while (n--) {
    ret_val = (a + b) % MOD;
    a = b;
    b = ret_val;
    if (n % 1000000 == 0)
      stack_saverestore(f_stack, main_stack);
  }

  state = DONE;
  while (true) {
    stack_saverestore(f_stack, main_stack);
  }
}

void shell_step_fiber(shellstate_t &shellstate, addr_t &main_stack, addr_t &f_stack, addr_t f_array, uint32_t f_arraysize) {
  if (shellstate.state != FIB_FIBER) {
    shellstate.fiber.state = START;
    stack_init3(f_stack, f_array, f_arraysize, &fiber_fib, &main_stack, &f_stack, &shellstate.fiber);
    return;
  }
  if (shellstate.curr_arg < shellstate.max_args)
    return;
  switch(shellstate.fiber.state) {
  case START:
    uint32_t args[MAX_ARGS];
    parse_args(shellstate.input, shellstate.max_args, args);
    for (uint8_t i = 0; i < shellstate.max_args; i++)
      shellstate.fiber.args[i] = args[i];
  case RUNNING:
    stack_saverestore(main_stack, f_stack);
    break;
  case DONE:
    int_to_string(shellstate.fiber.ret_val, shellstate.output);
    shell_refresh(shellstate, FUNCTIONS_MENU);
    shellstate.fiber.state = START;
    stack_init3(f_stack, f_array, f_arraysize, &fiber_fib, &main_stack, &f_stack, &shellstate.fiber);
    break;
  }
}
