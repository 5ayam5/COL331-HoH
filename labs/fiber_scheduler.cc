#include "labs/fiber_scheduler.h"

//
// stackptrs:      Type: addr_t[stackptrs_size].  array of stack pointers (generalizing: main_stack and f_stack)
// stackptrs_size: number of elements in 'stacks'.
//
// arrays:      Type: uint8_t [arrays_size]. array of memory region for stacks (generalizing: f_array)
// arrays_size: size of 'arrays'. equal to stackptrs_size*STACK_SIZE.
//
// Tip: divide arrays into stackptrs_size parts.
// Tip: you may implement a circular buffer using arrays inside shellstate_t
//      if you choose linked lists, create linked linked using arrays in
//      shellstate_t. (use array indexes as next pointers)
// Note: malloc/new is not available at this point.
//

uint32_t fib(addr_t &main_stack, addr_t &f_stack, preempt_t &preempt, uint32_t n) {
  if (n == 0)
      return 0;
  if (n == 1)
      return 1;
  // stack_saverestore(f_stack, main_stack);
  hoh_debug(n);
  return fib(main_stack, f_stack, preempt, n - 1) + fib(main_stack, f_stack, preempt, n - 2);
}

uint32_t hanoi(addr_t &main_stack, addr_t &f_stack, preempt_t &preempt, uint32_t n) {
  if (n == 0)
      return 0;
  preempt.self_yield = true;
  stack_saverestore(f_stack, main_stack);
  return hanoi(main_stack, f_stack, preempt, n - 1) + hanoi(main_stack, f_stack, preempt, n - 1) + 1;
}

void scheduler1(addr_t *pmain_stack, addr_t *pf_stack, preempt_t *ppreempt, fiber_t *fiber) {
  addr_t &main_stack = *pmain_stack;
  addr_t &f_stack = *pf_stack;
  preempt_t &preempt = *ppreempt;
  uint32_t &arg1 = fiber->args[0];
  fptr &f = fiber->f;
  uint8_t &state = fiber->state;
  uint32_t &ret_val = fiber->ret_val;
  state = RUNNING;

  ret_val = ((uint32_t(*)(addr_t &, addr_t &, preempt_t &, uint32_t)) f)(main_stack, f_stack, preempt, arg1);

  state = DONE;
  while (true) {
    preempt.self_yield = true;
    stack_saverestore(f_stack, main_stack);
  }
}

void shell_step_fiber_scheduler(shellstate_t &shellstate, addr_t &main_stack, preempt_t &preempt, addr_t stackptrs[], size_t stackptrs_size, addr_t arrays, size_t arrays_size, dev_lapic_t &lapic) {
  shellstate.curr_fiber = (shellstate.curr_fiber + 1) % MAX_FIBERS;
  size_t f_arraysize = arrays_size / stackptrs_size;
  fiber_t &fiber = shellstate.fibers[shellstate.curr_fiber];
  addr_t &f_stack = stackptrs[shellstate.curr_fiber];
  addr_t f_array = arrays + shellstate.curr_fiber * f_arraysize;
  preempt.self_yield = false;

  switch (fiber.state) {
  case START:
    if (shellstate.state < SCHEDULER_FIB || shellstate.curr_arg < shellstate.max_args)
      return;

    switch(shellstate.state) {
    case SCHEDULER_FIB:
      fiber.f = (fptr)&fib;
      strcpy(fiber.fun_name, "scheduler_fib(");
      stack_init4(f_stack, f_array, f_arraysize, &scheduler1, &main_stack, &f_stack, &preempt, &fiber);
      break;
    case SCHEDULER_HANOI:
      fiber.f = (fptr)&hanoi;
      strcpy(fiber.fun_name, "scheduler_hanoi(");
      stack_init4(f_stack, f_array, f_arraysize, &scheduler1, &main_stack, &f_stack, &preempt, &fiber);
      break;
    }

    uint32_t args[MAX_ARGS];
    for (uint8_t i = 0; i < shellstate.max_args - 1; i++) {
      strcpy(fiber.fun_name + strlen(fiber.fun_name), shellstate.input[i]);
      strcpy(fiber.fun_name + strlen(fiber.fun_name), ", ");
    }
    strcpy(fiber.fun_name + strlen(fiber.fun_name), shellstate.input[shellstate.max_args - 1]);
    strcpy(fiber.fun_name + strlen(fiber.fun_name), ") = ");
    parse_args(shellstate.input, shellstate.max_args, args);
    for (uint8_t i = 0; i < shellstate.max_args; i++)
      fiber.args[i] = args[i];
    shell_refresh(shellstate, LONG_COMPUTATION_MENU);

  case RUNNING:
    lapic.reset_timer_count(TIMER_COUNT);
    stack_saverestore(main_stack, f_stack);
    if (preempt.self_yield)
      lapic.reset_timer_count(0);
    else {
      hoh_debug("preempted!");
      f_stack = preempt.saved_stack;
    }
    break;

  case DONE:
    char buf[BUF_LEN] = {0};
    strcpy(buf, fiber.fun_name);
    int_to_string(fiber.ret_val, buf + strlen(fiber.fun_name));
    shellstate.shell_out(buf);
    fiber.state = START;
    break;
  }
}
