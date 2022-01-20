#pragma once

#include "generated/lpc_kbd.dev.h"

namespace lpc_kbd{

  static inline bool has_key(lpc_kbd_t& dev){
    return lpc_kbd_status_obf_extract(lpc_kbd_status_rd(&dev));
    //insert your code here
  }

  static inline uint8_t get_key(lpc_kbd_t& dev){
    return lpc_kbd_input_rd(&dev);
    //insert your code here
  }

}// namespace lpc_kbd

