// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMUL_H_
#define _VMUL_H_  // guard

#include "verilated.h"

//==========

class VMUL__Syms;
class VMUL_VerilatedVcd;


//----------

VL_MODULE(VMUL) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_multiplier,3,0);
    VL_IN8(io_multiplicand,3,0);
    VL_OUT8(io_product,7,0);
    VL_IN8(io_inputValid,0,0);
    VL_OUT8(io_outputValid,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*7:0*/ MUL__DOT__multiplicandReg;
    CData/*3:0*/ MUL__DOT__multiplierReg;
    CData/*7:0*/ MUL__DOT__productReg;
    CData/*2:0*/ MUL__DOT__cntReg;
    CData/*7:0*/ MUL__DOT___productReg_T_1;
    CData/*3:0*/ MUL__DOT___multiplierReg_T;
    CData/*2:0*/ MUL__DOT___cntReg_T_1;
    SData/*8:0*/ MUL__DOT___GEN_11;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VMUL__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMUL);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VMUL(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMUL();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMUL__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMUL__Syms* symsp, bool first);
  private:
    static QData _change_request(VMUL__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__3(VMUL__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VMUL__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VMUL__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VMUL__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VMUL__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VMUL__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
