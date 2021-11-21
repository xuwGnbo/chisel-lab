package ALU

import chisel3._

object ALUConst {
    val ALU_ADD = 0.U(2.W)
    val ALU_SUB = 1.U(2.W)
    val ALU_MUL = 2.U(2.W)
}

class ALUIO extends Bundle {
    val A = Input(UInt(32.W))
    val B = Input(UInt(32.W))
    val alu_op = Input(UInt(2.W))
    val out = Output(UInt(32.W))
}

import ALUConst._
import chisel3.util.MuxLookup

class ALU extends Module {
    val io = IO(new ALUIO)
    io.out := MuxLookup(io.alu_op, 0.U, Seq(
        ALU_ADD -> (io.A + io.B),
        ALU_SUB -> (io.A - io.B),
        ALU_MUL -> (io.A * io.B)
    ))
}
