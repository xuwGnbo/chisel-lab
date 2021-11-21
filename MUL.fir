;buildInfoPackage: chisel3, version: 3.4.3, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit MUL : 
  module MUL : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip multiplier : UInt<4>, flip multiplicand : UInt<4>, product : UInt<8>, flip inputValid : UInt<1>, outputValid : UInt<1>}
    
    reg multiplicandReg : UInt<8>, clock with : (reset => (reset, UInt<8>("h00"))) @[MUL.scala 23:34]
    reg multiplierReg : UInt<4>, clock with : (reset => (reset, UInt<4>("h00"))) @[MUL.scala 24:32]
    reg productReg : UInt<8>, clock with : (reset => (reset, UInt<8>("h00"))) @[MUL.scala 25:29]
    reg cntReg : UInt, clock with : (reset => (reset, UInt<1>("h00"))) @[MUL.scala 26:25]
    node _T = neq(cntReg, UInt<1>("h00")) @[MUL.scala 28:17]
    when _T : @[MUL.scala 28:26]
      node _T_1 = bits(multiplierReg, 0, 0) @[MUL.scala 29:27]
      node _T_2 = eq(_T_1, UInt<1>("h01")) @[MUL.scala 29:31]
      when _T_2 : @[MUL.scala 29:40]
        node _productReg_T = add(productReg, multiplicandReg) @[MUL.scala 30:38]
        node _productReg_T_1 = tail(_productReg_T, 1) @[MUL.scala 30:38]
        productReg <= _productReg_T_1 @[MUL.scala 30:24]
        skip @[MUL.scala 29:40]
      node _multiplierReg_T = dshr(multiplierReg, UInt<1>("h01")) @[MUL.scala 32:40]
      multiplierReg <= _multiplierReg_T @[MUL.scala 32:23]
      node _multiplicandReg_T = dshl(multiplicandReg, UInt<1>("h01")) @[MUL.scala 33:44]
      multiplicandReg <= _multiplicandReg_T @[MUL.scala 33:25]
      node _cntReg_T = sub(cntReg, UInt<1>("h01")) @[MUL.scala 34:26]
      node _cntReg_T_1 = tail(_cntReg_T, 1) @[MUL.scala 34:26]
      cntReg <= _cntReg_T_1 @[MUL.scala 34:16]
      skip @[MUL.scala 28:26]
    else : @[MUL.scala 35:32]
      node _T_3 = eq(cntReg, UInt<1>("h00")) @[MUL.scala 35:23]
      when _T_3 : @[MUL.scala 35:32]
        when io.inputValid : @[MUL.scala 36:29]
          node multiplicandReg_hi = mux(UInt<1>("h00"), UInt<4>("h0f"), UInt<4>("h00")) @[Bitwise.scala 72:12]
          node _multiplicandReg_T_1 = cat(multiplicandReg_hi, io.multiplicand) @[Cat.scala 30:58]
          multiplicandReg <= _multiplicandReg_T_1 @[MUL.scala 37:29]
          multiplierReg <= io.multiplier @[MUL.scala 38:27]
          productReg <= UInt<1>("h00") @[MUL.scala 39:24]
          cntReg <= UInt<3>("h04") @[MUL.scala 40:20]
          skip @[MUL.scala 36:29]
        skip @[MUL.scala 35:32]
    node _io_outputValid_T = eq(cntReg, UInt<1>("h00")) @[MUL.scala 44:31]
    io.outputValid <= _io_outputValid_T @[MUL.scala 44:20]
    io.product <= productReg @[MUL.scala 45:16]
    
