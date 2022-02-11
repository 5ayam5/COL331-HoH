#pragma once

#define cpp_concat2(x,y) x##y
#define cpp_concat(x,y)  cpp_concat2(x,y)

typedef void* coroutine_t;

#define coroutine_reset(ip)         do{ip=0;}while(false)

#define coroutine_switch2(ip)       do{coroutine_t& t_ip=(ip); if(t_ip){goto *(t_ip);}}while(false)
#define coroutine_yield2(ip)        do{(ip)=&&cpp_concat(label_,__LINE__);  return;       cpp_concat(label_,__LINE__): do{}while(false);}while(false)
#define coroutine_yieldv2(ip,ret)   do{(ip)=&&cpp_concat(label_,__LINE__);  return (ret); cpp_concat(label_,__LINE__): do{}while(false);}while(false)

#define h_begin(state)              coroutine_switch2(state)
#define h_yield(state)              coroutine_yield2(state)
#define h_end(state)                for(;;){h_yield(state);}

#define h_yieldv(state,ret)         coroutine_yieldv2(state,ret)
#define h_endv(state,ret)           for(;;){h_yieldv(state,ret);}


