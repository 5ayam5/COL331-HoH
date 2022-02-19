#include "labs/coroutine.h"
// #include "shell.cc"

void coroutine_fib(shellstate_t& shellstate, coroutine_t& f_coro, f_t* f_locals){
    uint32_t& a = f_locals->a;
    uint32_t& b = f_locals->b;
    uint32_t& n = f_locals->n;
    bool& done = f_locals->done;
    uint32_t& retVal = f_locals->retVal;

    h_begin(f_coro);

    a = 1;b = 0; retVal = 0;
    uint32_t args[MAX_ARGS];
    parse_args(shellstate.input, shellstate.max_args, args);
    n = args[0];
    done = false;

    while(n--){
        retVal = (a+b)%MOD;
        a = b;
        b = retVal;
        if(n%10==0)h_yield(f_coro);
    }
    int_to_string(retVal, shellstate.output);
    done = true; h_end(f_coro);
}


void shell_step_coroutine(shellstate_t& shellstate, coroutine_t& f_coro, f_t& f_locals){
    if (shellstate.state != COR){
        coroutine_reset(f_coro);
        return;
    }
    if (shellstate.curr_arg < shellstate.max_args) {
      return;
    }
    coroutine_fib(shellstate, f_coro, &f_locals);
    if(f_locals.done){
        shell_refresh(shellstate, FUNCTIONS_MENU);
        coroutine_reset(f_coro);
    }
}


