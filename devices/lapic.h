#pragma once
#include "generated/xapic.dev.h"
#include "devices/config.h"

class dev_lapic_t{
  private:
    xapic_t m_dev;
  public:
    dev_lapic_t(addr_t base){
      xapic_initialize(&m_dev,base);
    }

  public:
    void reset(){
      xapic_dfr_model_wrf(&m_dev,xapic_flat);
      hoh_debug("log_id: "<<xapic_ldr_log_id_rdf(&m_dev));
      xapic_ldr_log_id_wrf(&m_dev,0);
      {
        xapic_priority_t x=xapic_priority_default;
        x=xapic_priority_sub_class_insert(x,0);
        x=xapic_priority_priority_insert(x,0);
        xapic_tpr_wr(&m_dev,x);
        hoh_debug("lapic_prio: "<<x);
      }
      reset_spurious(0,true);
      reset_timer(0,true,false,100,xapic_by1);
      reset_perfcnt(0,true);
      reset_thermal(0,true);
      reset_lint0(0,true,true);
      reset_lint1(0,true);
      reset_err(0,true);
      clear_esr();
      eoi();
      lapic_internal_reset();
    }

  public:
    void eoi(){
      xapic_eoi_wr(&m_dev, 0);
    }
    void seoi(uint8_t x){
      xapic_seoi_vector_wrf(&m_dev,x);
    }

    void dump(){
      //xapic_isr_pr(dout,&m_dev);
      //xapic_irr_pr(dout,&m_dev);
      hoh_debug("LAPIC: "<<&m_dev);
    }

    void reset_timer_count(uint32_t count){
      reset_timer_count(count,xapic_by1);
    }
    void reset_timer_count(uint32_t count, xapic_divide_t div_val){
      xapic_init_count_wr(&m_dev,count);
      xapic_dcr_div_val_wrf(&m_dev, div_val);
    }

  private:
    void lapic_internal_reset(){
      reset_spurious(lapic_internal_base+lapic_internal_spurious, true);
      reset_timer(   lapic_internal_base+lapic_internal_timer   , false  , false, 0, xapic_by1); //1000000000UL
      reset_perfcnt( lapic_internal_base+lapic_internal_perfcnt , false);
      reset_thermal( lapic_internal_base+lapic_internal_thermal , false);
      reset_lint0(   lapic_internal_base+lapic_internal_lint0   , false  , true);
      reset_lint1(   lapic_internal_base+lapic_internal_lint1   , false);
      reset_err(     lapic_internal_base+lapic_internal_err     , false);
      clear_esr();
      eoi();
    }

    void reset_spurious(uint8_t vector, bool enable){
      xapic_svr_t x=xapic_svr_default;
      x=xapic_svr_vector_insert(x,vector);
      x=xapic_svr_enable_insert(x,enable);
      x=xapic_svr_focus_insert(x,1);
      xapic_svr_wr(&m_dev,x);
    }

    void reset_timer(uint8_t vector, bool masked, bool periodic, uint32_t count, xapic_divide_t div_val){
      reset_timer_count(count,div_val);

      xapic_lvt_timer_t x=xapic_lvt_timer_default;
      x=xapic_lvt_timer_vector_insert(x,vector);
      x=xapic_lvt_timer_status_insert(x,0); //REMOVEME
      x=xapic_lvt_timer_mask_insert(x,masked?xapic_masked:xapic_not_masked);
      x=xapic_lvt_timer_mode_insert(x,periodic?xapic_periodic:xapic_one_shot);
      xapic_lvt_timer_wr(&m_dev,x);

    }

    void reset_perfcnt(uint8_t vector, bool masked){
      xapic_lvt_mon_t x=xapic_lvt_mon_default;
      x=xapic_lvt_mon_vector_insert(x,vector);
      x=xapic_lvt_mon_msgType_insert(x,0); //REMOVEME
      x=xapic_lvt_mon_status_insert(x,0); //REMOVEME
      x=xapic_lvt_mon_mask_insert(x,masked?xapic_masked:xapic_not_masked);
      xapic_lvt_perf_cnt_wr(&m_dev,x);
    }
    void reset_thermal(uint8_t vector, bool masked){
      xapic_lvt_mon_t x=xapic_lvt_mon_default;
      x=xapic_lvt_mon_vector_insert(x,vector);
      x=xapic_lvt_mon_msgType_insert(x,0); //REMOVEME
      x=xapic_lvt_mon_status_insert(x,0); //REMOVEME
      x=xapic_lvt_mon_mask_insert(x,masked?xapic_masked:xapic_not_masked);
      xapic_lvt_thermal_wr(&m_dev,x);
    }
    void reset_lint0(uint8_t vector, bool masked, bool fixed){
      if(fixed){
        xapic_lvt_lint_t x=xapic_lvt_lint_default;
        x=xapic_lvt_lint_vector_insert(x,vector);
        x=xapic_lvt_lint_dlv_mode_insert(x,xapic_fixed);
        x=xapic_lvt_lint_status_insert(x,0); //REMOVEME
        x=xapic_lvt_lint_pinpol_insert(x,0); //REMOVEME
        x=xapic_lvt_lint_rirr_insert(x,0); //REMOVEME
        x=xapic_lvt_lint_trig_mode_insert(x,xapic_edge); //REMOVEME
        x=xapic_lvt_lint_mask_insert(x,masked?xapic_masked:xapic_not_masked);
        xapic_lvt_lint0_wr(&m_dev,x);
      }else{
        xapic_lvt_lint_t x=xapic_lvt_lint_default;
        x=xapic_lvt_lint_vector_insert(x,0);
        x=xapic_lvt_lint_dlv_mode_insert(x,xapic_extint);
        x=xapic_lvt_lint_status_insert(x,0); //REMOVEME
        x=xapic_lvt_lint_pinpol_insert(x,0); //REMOVEME
        x=xapic_lvt_lint_rirr_insert(x,0); //REMOVEME
        x=xapic_lvt_lint_trig_mode_insert(x,xapic_edge); //REMOVEME
        x=xapic_lvt_lint_mask_insert(x,masked?xapic_masked:xapic_not_masked);
        xapic_lvt_lint0_wr(&m_dev,x);
      }
    }

    void reset_lint1(uint8_t vector, bool masked){
      xapic_lvt_lint_t x=xapic_lvt_lint_default;
      x=xapic_lvt_lint_vector_insert(x,vector);
      x=xapic_lvt_lint_dlv_mode_insert(x,xapic_nmi);
      x=xapic_lvt_lint_status_insert(x,0); //REMOVEME
      x=xapic_lvt_lint_pinpol_insert(x,0); //REMOVEME
      x=xapic_lvt_lint_rirr_insert(x,0); //REMOVEME
      x=xapic_lvt_lint_trig_mode_insert(x,xapic_edge); //REMOVEME
      x=xapic_lvt_lint_mask_insert(x,masked?xapic_masked:xapic_not_masked);
      xapic_lvt_lint1_wr(&m_dev,x);
    }

    void reset_err(uint8_t vector, bool masked){
      xapic_lvt_err_t x=xapic_lvt_err_default;
      x=xapic_lvt_err_vector_insert(x,vector);
      x=xapic_lvt_err_status_insert(x,0); //REMOVEME
      x=xapic_lvt_err_mask_insert(x,masked?xapic_masked:xapic_not_masked);
      xapic_lvt_err_wr(&m_dev,x);
    }

    void clear_esr(){
      xapic_esr_rawwr(&m_dev,xapic_esr_default);
      xapic_esr_rawwr(&m_dev,xapic_esr_default);
    }

    void mask_timer(bool masked){
      xapic_lvt_timer_mask_wrf(&m_dev,masked?xapic_masked:xapic_not_masked);
    }

  public:
    void icr_rawwr(uint8_t vector, xapic_vdm_t dlv_mode,
        xapic_int_level_t level, xapic_trigm_t trig_mode,
        xapic_dst_shorthand_t dst_short, uint8_t dest){
      clear_esr();
      {
        xapic_icr_hi_t x=xapic_icr_hi_default;
        x=xapic_icr_hi_dest_insert(x, dest);
        xapic_icr_hi_rawwr(&m_dev, x);
      }
      {
        xapic_icr_lo_t x=xapic_icr_lo_default;
        x=xapic_icr_lo_vector_insert(x,vector);
        x=xapic_icr_lo_dlv_mode_insert(x, dlv_mode);
        x=xapic_icr_lo_dst_mode_insert(x, xapic_dst_phys);
        x=xapic_icr_lo_level_insert(x, level);
        x=xapic_icr_lo_trig_mode_insert(x, trig_mode);
        x=xapic_icr_lo_dst_short_insert(x, dst_short);
        xapic_icr_lo_rawwr(&m_dev,x);
      }
    }

    bool poll_wait(){
      return (xapic_icr_lo_dlv_stat_rdf(&m_dev)==0);
    }


    //INIT (level triggered) - reset CPU
    void icr_init(bool is_set,uint8_t coreid){
      icr_rawwr(0, xapic_init, is_set?xapic_lvl_set:xapic_lvl_clr, xapic_level, xapic_none, coreid);
    }

    //Startup IPI (edge triggered)
    //Startup works only if the other is in halted state due to INIT
    void icr_startup(addr_t startaddr,uint8_t coreid){
      hoh_assert(((uintptr_t)startaddr& 0xfff00fff)==0,"Invalid address");
      icr_rawwr(get_bits<19,12>(uintptr_t(startaddr)), xapic_startup, xapic_lvl_set, xapic_edge, xapic_none, coreid);
    }

    //IPI
    void icr_fixed(uint8_t vector, uint8_t coreid){
      icr_rawwr(vector, xapic_fixed, xapic_lvl_clr, xapic_edge, xapic_none, coreid);
    }

};



