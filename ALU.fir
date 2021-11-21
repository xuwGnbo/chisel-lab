;buildInfoPackage: chisel3, version: 3.4.3, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit ALU : 
  module ALU : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip A : UInt<32>, flip B : UInt<32>, flip alu_op : UInt<2>, out : UInt<32>}
    
    node _io_out_T = add(io.A, io.B) @[ALU.scala 24:26]
    node _io_out_T_1 = tail(_io_out_T, 1) @[ALU.scala 24:26]
    node _io_out_T_2 = sub(io.A, io.B) @[ALU.scala 25:26]
    node _io_out_T_3 = tail(_io_out_T_2, 1) @[ALU.scala 25:26]
    node _io_out_T_4 = mul(io.A, io.B) @[ALU.scala 26:26]
    node _io_out_T_5 = eq(UInt<2>("h00"), io.alu_op) @[Mux.scala 80:60]
    node _io_out_T_6 = mux(_io_out_T_5, _io_out_T_1, UInt<1>("h00")) @[Mux.scala 80:57]
    node _io_out_T_7 = eq(UInt<2>("h01"), io.alu_op) @[Mux.scala 80:60]
    node _io_out_T_8 = mux(_io_out_T_7, _io_out_T_3, _io_out_T_6) @[Mux.scala 80:57]
    node _io_out_T_9 = eq(UInt<2>("h02"), io.alu_op) @[Mux.scala 80:60]
    node _io_out_T_10 = mux(_io_out_T_9, _io_out_T_4, _io_out_T_8) @[Mux.scala 80:57]
    io.out <= _io_out_T_10 @[ALU.scala 23:12]
    
