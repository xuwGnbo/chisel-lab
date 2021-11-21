// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMUL__Syms.h"


//======================

void VMUL::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMUL* t = (VMUL*)userthis;
    VMUL__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VMUL::traceChgThis(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMUL::traceChgThis__2(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->MUL__DOT__multiplicandReg),8);
        vcdp->chgBus(c+9,(vlTOPp->MUL__DOT__multiplierReg),4);
        vcdp->chgBus(c+17,(vlTOPp->MUL__DOT__productReg),8);
        vcdp->chgBus(c+25,(vlTOPp->MUL__DOT__cntReg),3);
    }
}

void VMUL::traceChgThis__3(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+33,(vlTOPp->clock));
        vcdp->chgBit(c+41,(vlTOPp->reset));
        vcdp->chgBus(c+49,(vlTOPp->io_multiplier),4);
        vcdp->chgBus(c+57,(vlTOPp->io_multiplicand),4);
        vcdp->chgBus(c+65,(vlTOPp->io_product),8);
        vcdp->chgBit(c+73,(vlTOPp->io_inputValid));
        vcdp->chgBit(c+81,(vlTOPp->io_outputValid));
    }
}
