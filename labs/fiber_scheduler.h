#pragma once


#include "labs/shell.h"
#include "util/fiber.h"

void shell_step_fiber_scheduler(shellstate_t& shellstate, addr_t stackptrs[], size_t stackptrs_size, addr_t arrays, size_t arrays_size);


