// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU.h"
#include "VALU__Syms.h"

//==========

VL_CTOR_IMP(VALU) {
    VALU__Syms* __restrict vlSymsp = __VlSymsp = new VALU__Syms(this, name());
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VALU::__Vconfigure(VALU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VALU::~VALU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VALU::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU::eval\n"); );
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("ALU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VALU::_eval_initial_loop(VALU__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("ALU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VALU::_combo__TOP__1(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_combo__TOP__1\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_out = (IData)(((2U == (IData)(vlTOPp->io_alu_op))
                               ? ((QData)((IData)(vlTOPp->io_A)) 
                                  * (QData)((IData)(vlTOPp->io_B)))
                               : (QData)((IData)(((1U 
                                                   == (IData)(vlTOPp->io_alu_op))
                                                   ? 
                                                  (vlTOPp->io_A 
                                                   - vlTOPp->io_B)
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlTOPp->io_alu_op))
                                                    ? 
                                                   (vlTOPp->io_A 
                                                    + vlTOPp->io_B)
                                                    : 0U))))));
}

void VALU::_eval(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VALU::_eval_initial(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_initial\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::final\n"); );
    // Variables
    VALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VALU::_eval_settle(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_settle\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VALU::_change_request(VALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_change_request\n"); );
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_alu_op & 0xfcU))) {
        Verilated::overWidthError("io_alu_op");}
}
#endif  // VL_DEBUG

void VALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_A = VL_RAND_RESET_I(32);
    io_B = VL_RAND_RESET_I(32);
    io_alu_op = VL_RAND_RESET_I(2);
    io_out = VL_RAND_RESET_I(32);
    __Vm_traceActivity = 0;
}
