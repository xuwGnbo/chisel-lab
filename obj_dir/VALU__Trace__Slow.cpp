// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VALU__Syms.h"


//======================

void VALU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VALU::traceInit, &VALU::traceFull, &VALU::traceChg, this);
}
void VALU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VALU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VALU* t = (VALU*)userthis;
    VALU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VALU::traceInitThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VALU::traceFullThis(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VALU::traceInitThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clock", false,-1);
        vcdp->declBit(c+9,"reset", false,-1);
        vcdp->declBus(c+17,"io_A", false,-1, 31,0);
        vcdp->declBus(c+25,"io_B", false,-1, 31,0);
        vcdp->declBus(c+33,"io_alu_op", false,-1, 1,0);
        vcdp->declBus(c+41,"io_out", false,-1, 31,0);
        vcdp->declBit(c+1,"ALU clock", false,-1);
        vcdp->declBit(c+9,"ALU reset", false,-1);
        vcdp->declBus(c+17,"ALU io_A", false,-1, 31,0);
        vcdp->declBus(c+25,"ALU io_B", false,-1, 31,0);
        vcdp->declBus(c+33,"ALU io_alu_op", false,-1, 1,0);
        vcdp->declBus(c+41,"ALU io_out", false,-1, 31,0);
    }
}

void VALU::traceFullThis__1(VALU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->clock));
        vcdp->fullBit(c+9,(vlTOPp->reset));
        vcdp->fullBus(c+17,(vlTOPp->io_A),32);
        vcdp->fullBus(c+25,(vlTOPp->io_B),32);
        vcdp->fullBus(c+33,(vlTOPp->io_alu_op),2);
        vcdp->fullBus(c+41,(vlTOPp->io_out),32);
    }
}
