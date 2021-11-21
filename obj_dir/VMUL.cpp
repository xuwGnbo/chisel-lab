// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMUL.h for the primary calling header

#include "VMUL.h"
#include "VMUL__Syms.h"

//==========

VL_CTOR_IMP(VMUL) {
    VMUL__Syms* __restrict vlSymsp = __VlSymsp = new VMUL__Syms(this, name());
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMUL::__Vconfigure(VMUL__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMUL::~VMUL() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VMUL::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMUL::eval\n"); );
    VMUL__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("MUL.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VMUL::_eval_initial_loop(VMUL__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("MUL.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VMUL::_sequent__TOP__1(VMUL__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_sequent__TOP__1\n"); );
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__MUL__DOT__multiplierReg;
    CData/*2:0*/ __Vdly__MUL__DOT__cntReg;
    // Body
    __Vdly__MUL__DOT__multiplierReg = vlTOPp->MUL__DOT__multiplierReg;
    __Vdly__MUL__DOT__cntReg = vlTOPp->MUL__DOT__cntReg;
    vlTOPp->MUL__DOT__multiplicandReg = ((IData)(vlTOPp->reset)
                                          ? 0U : (0xffU 
                                                  & (IData)(vlTOPp->MUL__DOT___GEN_11)));
    if (vlTOPp->reset) {
        __Vdly__MUL__DOT__multiplierReg = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->MUL__DOT__cntReg))) {
            __Vdly__MUL__DOT__multiplierReg = vlTOPp->MUL__DOT___multiplierReg_T;
        } else {
            if ((0U == (IData)(vlTOPp->MUL__DOT__cntReg))) {
                if (vlTOPp->io_inputValid) {
                    __Vdly__MUL__DOT__multiplierReg 
                        = vlTOPp->io_multiplier;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->MUL__DOT__productReg = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->MUL__DOT__cntReg))) {
            if ((1U & (IData)(vlTOPp->MUL__DOT__multiplierReg))) {
                vlTOPp->MUL__DOT__productReg = vlTOPp->MUL__DOT___productReg_T_1;
            }
        } else {
            if ((0U == (IData)(vlTOPp->MUL__DOT__cntReg))) {
                if (vlTOPp->io_inputValid) {
                    vlTOPp->MUL__DOT__productReg = 0U;
                }
            }
        }
    }
    if (vlTOPp->reset) {
        __Vdly__MUL__DOT__cntReg = 0U;
    } else {
        if ((0U != (IData)(vlTOPp->MUL__DOT__cntReg))) {
            __Vdly__MUL__DOT__cntReg = vlTOPp->MUL__DOT___cntReg_T_1;
        } else {
            if ((0U == (IData)(vlTOPp->MUL__DOT__cntReg))) {
                if (vlTOPp->io_inputValid) {
                    __Vdly__MUL__DOT__cntReg = 4U;
                }
            }
        }
    }
    vlTOPp->MUL__DOT__multiplierReg = __Vdly__MUL__DOT__multiplierReg;
    vlTOPp->MUL__DOT__cntReg = __Vdly__MUL__DOT__cntReg;
    vlTOPp->MUL__DOT___multiplierReg_T = (7U & ((IData)(vlTOPp->MUL__DOT__multiplierReg) 
                                                >> 1U));
    vlTOPp->io_product = vlTOPp->MUL__DOT__productReg;
    vlTOPp->MUL__DOT___productReg_T_1 = (0xffU & ((IData)(vlTOPp->MUL__DOT__productReg) 
                                                  + (IData)(vlTOPp->MUL__DOT__multiplicandReg)));
    vlTOPp->MUL__DOT___cntReg_T_1 = (7U & ((IData)(vlTOPp->MUL__DOT__cntReg) 
                                           - (IData)(1U)));
    vlTOPp->io_outputValid = (0U == (IData)(vlTOPp->MUL__DOT__cntReg));
}

void VMUL::_settle__TOP__2(VMUL__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_settle__TOP__2\n"); );
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MUL__DOT___multiplierReg_T = (7U & ((IData)(vlTOPp->MUL__DOT__multiplierReg) 
                                                >> 1U));
    vlTOPp->MUL__DOT___cntReg_T_1 = (7U & ((IData)(vlTOPp->MUL__DOT__cntReg) 
                                           - (IData)(1U)));
    vlTOPp->io_product = vlTOPp->MUL__DOT__productReg;
    vlTOPp->io_outputValid = (0U == (IData)(vlTOPp->MUL__DOT__cntReg));
    vlTOPp->MUL__DOT___productReg_T_1 = (0xffU & ((IData)(vlTOPp->MUL__DOT__productReg) 
                                                  + (IData)(vlTOPp->MUL__DOT__multiplicandReg)));
    vlTOPp->MUL__DOT___GEN_11 = ((0U != (IData)(vlTOPp->MUL__DOT__cntReg))
                                  ? ((IData)(vlTOPp->MUL__DOT__multiplicandReg) 
                                     << 1U) : ((0U 
                                                == (IData)(vlTOPp->MUL__DOT__cntReg))
                                                ? ((IData)(vlTOPp->io_inputValid)
                                                    ? (IData)(vlTOPp->io_multiplicand)
                                                    : (IData)(vlTOPp->MUL__DOT__multiplicandReg))
                                                : (IData)(vlTOPp->MUL__DOT__multiplicandReg)));
}

VL_INLINE_OPT void VMUL::_combo__TOP__3(VMUL__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_combo__TOP__3\n"); );
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MUL__DOT___GEN_11 = ((0U != (IData)(vlTOPp->MUL__DOT__cntReg))
                                  ? ((IData)(vlTOPp->MUL__DOT__multiplicandReg) 
                                     << 1U) : ((0U 
                                                == (IData)(vlTOPp->MUL__DOT__cntReg))
                                                ? ((IData)(vlTOPp->io_inputValid)
                                                    ? (IData)(vlTOPp->io_multiplicand)
                                                    : (IData)(vlTOPp->MUL__DOT__multiplicandReg))
                                                : (IData)(vlTOPp->MUL__DOT__multiplicandReg)));
}

void VMUL::_eval(VMUL__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_eval\n"); );
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMUL::_eval_initial(VMUL__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_eval_initial\n"); );
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VMUL::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::final\n"); );
    // Variables
    VMUL__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMUL::_eval_settle(VMUL__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_eval_settle\n"); );
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VMUL::_change_request(VMUL__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_change_request\n"); );
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMUL::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_multiplier & 0xf0U))) {
        Verilated::overWidthError("io_multiplier");}
    if (VL_UNLIKELY((io_multiplicand & 0xf0U))) {
        Verilated::overWidthError("io_multiplicand");}
    if (VL_UNLIKELY((io_inputValid & 0xfeU))) {
        Verilated::overWidthError("io_inputValid");}
}
#endif  // VL_DEBUG

void VMUL::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMUL::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_multiplier = VL_RAND_RESET_I(4);
    io_multiplicand = VL_RAND_RESET_I(4);
    io_product = VL_RAND_RESET_I(8);
    io_inputValid = VL_RAND_RESET_I(1);
    io_outputValid = VL_RAND_RESET_I(1);
    MUL__DOT__multiplicandReg = VL_RAND_RESET_I(8);
    MUL__DOT__multiplierReg = VL_RAND_RESET_I(4);
    MUL__DOT__productReg = VL_RAND_RESET_I(8);
    MUL__DOT__cntReg = VL_RAND_RESET_I(3);
    MUL__DOT___productReg_T_1 = VL_RAND_RESET_I(8);
    MUL__DOT___multiplierReg_T = VL_RAND_RESET_I(4);
    MUL__DOT___cntReg_T_1 = VL_RAND_RESET_I(3);
    MUL__DOT___GEN_11 = VL_RAND_RESET_I(9);
    __Vm_traceActivity = 0;
}
