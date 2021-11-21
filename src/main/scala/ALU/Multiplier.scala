package ALU

import chisel3._

object MulConst {
    val xlen = 4
}

import MulConst._
import chisel3.util._

class MultiplierIO extends Bundle {
    val multiplier = Input(UInt(xlen.W))
    val multiplicand = Input(UInt(xlen.W))
    val product = Output(UInt((xlen*2).W))
    
    val inputValid = Input(Bool())
    val outputValid = Output(Bool())
}

class Multiplier extends Module {
    var io = IO(new MultiplierIO)
    val multiplicandReg = RegInit(0.U((xlen*2).W))
    val multiplierReg = RegInit(0.U(xlen.W))
    val productReg = RegInit(0.U((xlen*2).W))
    val cntReg = RegInit(0.U)

    when(cntReg =/= 0.U) {
        when(multiplierReg(0) === 1.U) {
            productReg := productReg + multiplicandReg
        }
        multiplierReg := multiplierReg >> 1.U
        multiplicandReg := multiplicandReg << 1.U
        cntReg := cntReg - 1.U
    }.elsewhen(cntReg === 0.U) {
        when(io.inputValid) {
            multiplicandReg := Cat(Fill(xlen,0.U), io.multiplicand)
            multiplierReg := io.multiplier
            productReg := 0.U
            cntReg := xlen.U
        }
    }

    io.outputValid := (cntReg === 0.U)
    io.product := productReg
}