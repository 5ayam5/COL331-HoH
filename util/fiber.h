#pragma once

#include <util/debug.h>

#define _ALL_REGISTERS "edx","esi","edi"


//
// Switch stacks.
//
// Algo:
//   1. Save _c's context to stack,
//   2. push ip of _c's restore handler
//   3. switch stacks
//   4. execute ip of _n's restore handler to restore _n's context from stack.
//
//
// stack layout:
//  teip[-1:-32]: continuation to restore,
//  Stack layout expected by teip:
//     ebp[ -33: -64],
//     ebx[ -65: -96],
//     eax[ -97:-128],
//     Stack layout expected by eip+4:
//        Preserved.

#define stack_saverestore(from_stack,to_stack) do {                  \
 asm volatile(                                                       \
   "  pushl %%eax      \n\t"                                         \
   "  pushl %%ecx      \n\t"                                         \
   "  pushl %%ebx      \n\t"                                         \
   "  pushl %%ebp      \n\t"                                         \
   "  pushl $1f        \n\t"                                         \
   "                   \n\t"                                         \
   "  movl  %%esp,(%0) \n\t"                                         \
   "  movl  (%1),%%esp \n\t"                                         \
   "                   \n\t"                                         \
   "  ret              \n\t"                                         \
   "1:                 \n\t"                                         \
   "  popl %%ebp       \n\t"                                         \
   "  popl %%ebx       \n\t"                                         \
   "  popl %%ecx       \n\t"                                         \
   "  popl %%eax       \n\t"                                         \
  :                                                                  \
  :"a" (&from_stack), "c"  (&to_stack)                               \
  :_ALL_REGISTERS, "memory"                                          \
 );                                                                  \
} while(false)


//
// Initializes stack.
//
// Algo:
//   1. Push Ip of reset handler
//         (which will reset ebp and jmp to actual eip etc)
//
// stack layout:
//  teip[-1:-32]: continuation to restore(1f),
//  Stack layout expected by teip:
//     args passed in registers when calling eip (NONE),
//     eip[-33:-64],
//     args passed in stack when calling eip (NONE),
//
// initial values: teip=t_start; eip=f_start;
//

#define stack_inithelper(_teip)  do{                                 \
 asm volatile(                                                       \
   "  movl $1f,%0      \n\t"                                         \
   "  jmp  2f          \n\t"                                         \
   "1:                 \n\t"                                         \
   "  movl $0, %%ebp   \n\t"                                         \
   "  jmp *(%%esp)    \n\t"                                         \
   "2:                 \n\t"                                         \
  :"=m" (_teip)                                                      \
  :                                                                  \
 );                                                                  \
}while(false)


//
// Legacy.
//
// TODO  Take a poll on number of students using ancient g++ (<4.8)
// FIXME Revert to: use type of f_start and variadic template, if g++>4.8
//
//

template<typename T>
struct Param{
  static inline addr_t stack_push(addr_t stack, T x){
    stack-=sizeof(T);
    *((T*)stack)= x;
    return stack;
  }
};

template<typename T>
static inline addr_t stack_push(addr_t stack, T x){
  return Param<T>::stack_push(stack,x);
}


#define stack_init0(f_stack,f_array,f_arraysize,f_start) do{         \
 uintptr_t teip;                                                     \
 stack_inithelper(teip);                                             \
 addr_t  stack=addr_t(f_array)+f_arraysize;                          \
 stack=stack_push(stack,f_start);                                    \
 stack=stack_push(stack,teip);                                       \
 f_stack=stack;                                                      \
}while(false)

#define stack_init1(f_stack,f_array,f_arraysize,f_start,f_arg1) do{  \
 uintptr_t teip;                                                     \
 stack_inithelper(teip);                                             \
 addr_t  stack=addr_t(f_array)+f_arraysize;                          \
 stack=stack_push(stack,f_arg1);                                     \
 stack=stack_push(stack,f_start);                                    \
 stack=stack_push(stack,teip);                                       \
 f_stack=stack;                                                      \
}while(false)

#define stack_init2(f_stack,f_array,f_arraysize,f_start,f_arg1,f_arg2) do{  \
 uintptr_t teip;                                                     \
 stack_inithelper(teip);                                             \
 addr_t  stack=addr_t(f_array)+f_arraysize;                          \
 stack=stack_push(stack,f_arg2);                                     \
 stack=stack_push(stack,f_arg1);                                     \
 stack=stack_push(stack,f_start);                                    \
 stack=stack_push(stack,teip);                                       \
 f_stack=stack;                                                      \
}while(false)

#define stack_init3(f_stack,f_array,f_arraysize,f_start,f_arg1,f_arg2,f_arg3) do{  \
 uintptr_t teip;                                                     \
 stack_inithelper(teip);                                             \
 addr_t  stack=addr_t(f_array)+f_arraysize;                          \
 stack=stack_push(stack,f_arg3);                                     \
 stack=stack_push(stack,f_arg2);                                     \
 stack=stack_push(stack,f_arg1);                                     \
 stack=stack_push(stack,f_start);                                    \
 stack=stack_push(stack,teip);                                       \
 f_stack=stack;                                                      \
}while(false)

#define stack_init4(f_stack,f_array,f_arraysize,f_start,f_arg1,f_arg2,f_arg3,f_arg4) do{  \
 uintptr_t teip;                                                     \
 stack_inithelper(teip);                                             \
 addr_t  stack=addr_t(f_array)+f_arraysize;                          \
 stack=stack_push(stack,f_arg4);                                     \
 stack=stack_push(stack,f_arg3);                                     \
 stack=stack_push(stack,f_arg2);                                     \
 stack=stack_push(stack,f_arg1);                                     \
 stack=stack_push(stack,f_start);                                    \
 stack=stack_push(stack,teip);                                       \
 f_stack=stack;                                                      \
}while(false)

#define stack_init5(f_stack,f_array,f_arraysize,f_start,f_arg1,f_arg2,f_arg3,f_arg4,f_arg5) do{  \
 uintptr_t teip;                                                     \
 stack_inithelper(teip);                                             \
 addr_t  stack=addr_t(f_array)+f_arraysize;                          \
 stack=stack_push(stack,f_arg5);                                     \
 stack=stack_push(stack,f_arg4);                                     \
 stack=stack_push(stack,f_arg3);                                     \
 stack=stack_push(stack,f_arg2);                                     \
 stack=stack_push(stack,f_arg1);                                     \
 stack=stack_push(stack,f_start);                                    \
 stack=stack_push(stack,teip);                                       \
 f_stack=stack;                                                      \
}while(false)


#define stack_init6(f_stack,f_array,f_arraysize,f_start,f_arg1,f_arg2,f_arg3,f_arg4,f_arg5,f_arg6) do{  \
 uintptr_t teip;                                                     \
 stack_inithelper(teip);                                             \
 addr_t  stack=addr_t(f_array)+f_arraysize;                          \
 stack=stack_push(stack,f_arg6);                                     \
 stack=stack_push(stack,f_arg5);                                     \
 stack=stack_push(stack,f_arg4);                                     \
 stack=stack_push(stack,f_arg3);                                     \
 stack=stack_push(stack,f_arg2);                                     \
 stack=stack_push(stack,f_arg1);                                     \
 stack=stack_push(stack,f_start);                                    \
 stack=stack_push(stack,teip);                                       \
 f_stack=stack;                                                      \
}while(false)





