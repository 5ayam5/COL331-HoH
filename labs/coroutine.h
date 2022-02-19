#pragma once

#include "labs/shell.h"
#include "util/coroutine.h"

// state for your coroutine implementation:
struct f_t{
    uint32_t n, a, b, c;
    bool done = true;
    uint32_t retVal;
    //insert your code here
};


void shell_step_coroutine(shellstate_t& shellstate, coroutine_t& f_coro, f_t& f_locals);


