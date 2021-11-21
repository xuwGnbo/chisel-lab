module MUL(
  input        clock,
  input        reset,
  input  [3:0] io_multiplier,
  input  [3:0] io_multiplicand,
  output [7:0] io_product,
  input        io_inputValid,
  output       io_outputValid
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] multiplicandReg; // @[MUL.scala 23:34]
  reg [3:0] multiplierReg; // @[MUL.scala 24:32]
  reg [7:0] productReg; // @[MUL.scala 25:29]
  reg [2:0] cntReg; // @[MUL.scala 26:25]
  wire [7:0] _productReg_T_1 = productReg + multiplicandReg; // @[MUL.scala 30:38]
  wire [3:0] _multiplierReg_T = {{1'd0}, multiplierReg[3:1]}; // @[MUL.scala 32:40]
  wire [8:0] _multiplicandReg_T = {multiplicandReg, 1'h0}; // @[MUL.scala 33:44]
  wire [2:0] _cntReg_T_1 = cntReg - 3'h1; // @[MUL.scala 34:26]
  wire [7:0] _multiplicandReg_T_1 = {4'h0,io_multiplicand}; // @[Cat.scala 30:58]
  wire [7:0] _GEN_1 = io_inputValid ? _multiplicandReg_T_1 : multiplicandReg; // @[MUL.scala 36:29 MUL.scala 37:29 MUL.scala 23:34]
  wire [7:0] _GEN_5 = cntReg == 3'h0 ? _GEN_1 : multiplicandReg; // @[MUL.scala 35:32 MUL.scala 23:34]
  wire [8:0] _GEN_11 = cntReg != 3'h0 ? _multiplicandReg_T : {{1'd0}, _GEN_5}; // @[MUL.scala 28:26 MUL.scala 33:25]
  assign io_product = productReg; // @[MUL.scala 45:16]
  assign io_outputValid = cntReg == 3'h0; // @[MUL.scala 44:31]
  always @(posedge clock) begin
    if (reset) begin // @[MUL.scala 23:34]
      multiplicandReg <= 8'h0; // @[MUL.scala 23:34]
    end else begin
      multiplicandReg <= _GEN_11[7:0];
    end
    if (reset) begin // @[MUL.scala 24:32]
      multiplierReg <= 4'h0; // @[MUL.scala 24:32]
    end else if (cntReg != 3'h0) begin // @[MUL.scala 28:26]
      multiplierReg <= _multiplierReg_T; // @[MUL.scala 32:23]
    end else if (cntReg == 3'h0) begin // @[MUL.scala 35:32]
      if (io_inputValid) begin // @[MUL.scala 36:29]
        multiplierReg <= io_multiplier; // @[MUL.scala 38:27]
      end
    end
    if (reset) begin // @[MUL.scala 25:29]
      productReg <= 8'h0; // @[MUL.scala 25:29]
    end else if (cntReg != 3'h0) begin // @[MUL.scala 28:26]
      if (multiplierReg[0]) begin // @[MUL.scala 29:40]
        productReg <= _productReg_T_1; // @[MUL.scala 30:24]
      end
    end else if (cntReg == 3'h0) begin // @[MUL.scala 35:32]
      if (io_inputValid) begin // @[MUL.scala 36:29]
        productReg <= 8'h0; // @[MUL.scala 39:24]
      end
    end
    if (reset) begin // @[MUL.scala 26:25]
      cntReg <= 3'h0; // @[MUL.scala 26:25]
    end else if (cntReg != 3'h0) begin // @[MUL.scala 28:26]
      cntReg <= _cntReg_T_1; // @[MUL.scala 34:16]
    end else if (cntReg == 3'h0) begin // @[MUL.scala 35:32]
      if (io_inputValid) begin // @[MUL.scala 36:29]
        cntReg <= 3'h4; // @[MUL.scala 40:20]
      end
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  multiplicandReg = _RAND_0[7:0];
  _RAND_1 = {1{`RANDOM}};
  multiplierReg = _RAND_1[3:0];
  _RAND_2 = {1{`RANDOM}};
  productReg = _RAND_2[7:0];
  _RAND_3 = {1{`RANDOM}};
  cntReg = _RAND_3[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
