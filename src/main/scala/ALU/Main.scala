package ALU

object Main extends App {
    (new chisel3.stage.ChiselStage).emitVerilog(new ALU)
    (new chisel3.stage.ChiselStage).emitVerilog(new MUL)
}
