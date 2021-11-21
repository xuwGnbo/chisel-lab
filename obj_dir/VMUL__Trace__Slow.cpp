// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMUL__Syms.h"


//======================

void VMUL::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VMUL::traceInit, &VMUL::traceFull, &VMUL::traceChg, this);
}
void VMUL::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VMUL* t = (VMUL*)userthis;
    VMUL__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VMUL::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMUL* t = (VMUL*)userthis;
    VMUL__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VMUL::traceInitThis(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VMUL::traceFullThis(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMUL::traceInitThis__1(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+33,"clock", false,-1);
        vcdp->declBit(c+41,"reset", false,-1);
        vcdp->declBus(c+49,"io_multiplier", false,-1, 3,0);
        vcdp->declBus(c+57,"io_multiplicand", false,-1, 3,0);
        vcdp->declBus(c+65,"io_product", false,-1, 7,0);
        vcdp->declBit(c+73,"io_inputValid", false,-1);
        vcdp->declBit(c+81,"io_outputValid", false,-1);
        vcdp->declBit(c+33,"MUL clock", false,-1);
        vcdp->declBit(c+41,"MUL reset", false,-1);
        vcdp->declBus(c+49,"MUL io_multiplier", false,-1, 3,0);
        vcdp->declBus(c+57,"MUL io_multiplicand", false,-1, 3,0);
        vcdp->declBus(c+65,"MUL io_product", false,-1, 7,0);
        vcdp->declBit(c+73,"MUL io_inputValid", false,-1);
        vcdp->declBit(c+81,"MUL io_outputValid", false,-1);
        vcdp->declBus(c+1,"MUL multiplicandReg", false,-1, 7,0);
        vcdp->declBus(c+9,"MUL multiplierReg", false,-1, 3,0);
        vcdp->declBus(c+17,"MUL productReg", false,-1, 7,0);
        vcdp->declBus(c+25,"MUL cntReg", false,-1, 2,0);
    }
}

void VMUL::traceFullThis__1(VMUL__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMUL* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->MUL__DOT__multiplicandReg),8);
        vcdp->fullBus(c+9,(vlTOPp->MUL__DOT__multiplierReg),4);
        vcdp->fullBus(c+17,(vlTOPp->MUL__DOT__productReg),8);
        vcdp->fullBus(c+25,(vlTOPp->MUL__DOT__cntReg),3);
        vcdp->fullBit(c+33,(vlTOPp->clock));
        vcdp->fullBit(c+41,(vlTOPp->reset));
        vcdp->fullBus(c+49,(vlTOPp->io_multiplier),4);
        vcdp->fullBus(c+57,(vlTOPp->io_multiplicand),4);
        vcdp->fullBus(c+65,(vlTOPp->io_product),8);
        vcdp->fullBit(c+73,(vlTOPp->io_inputValid));
        vcdp->fullBit(c+81,(vlTOPp->io_outputValid));
    }
}
