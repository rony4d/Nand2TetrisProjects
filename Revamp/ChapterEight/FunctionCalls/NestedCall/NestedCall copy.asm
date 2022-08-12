//  function Sys.init 0
(Sys.init)
@4000
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
@SP
A=M
D=M
@THIS
M=D
@5000
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
@SP
A=M
D=M
@THAT
M=D

//  call Sys.main 0
@Sys.init$retAddrLabel_29
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@0
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.main
0;JMP
(Sys.init$retAddrLabel_29)



//  pop temp 1
@1
D=A
@5
D=D+A
@addr_79
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_79
A=M
M=D

//  Infinite loop
(Sys.init$LOOP)
@Sys.init$LOOP
0;JMP

//  function Sys.main 5
(Sys.main)

//  Initialize 5 local variables

//  n = 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
@0
D=A
@LCL
D=D+M
@addr_104
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_104
A=M
M=D
@SP
M=M+1

//  n = 1
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
@1
D=A
@LCL
D=D+M
@addr_127
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_127
A=M
M=D
@SP
M=M+1

//  n = 2
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
@2
D=A
@LCL
D=D+M
@addr_150
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_150
A=M
M=D
@SP
M=M+1

//  n = 3
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
@3
D=A
@LCL
D=D+M
@addr_173
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_173
A=M
M=D
@SP
M=M+1

//  n = 4
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
@4
D=A
@LCL
D=D+M
@addr_196
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_196
A=M
M=D
@SP
M=M+1

//  push constant 4001
@4001
D=A
@SP
A=M
M=D
@SP
M=M+1

//  pop pointer 0
@SP
M=M-1
@SP
A=M
D=M
@THIS
M=D

//  push constant 5001
@5001
D=A
@SP
A=M
M=D
@SP
M=M+1

//   pop pointer 1
@SP
M=M-1
@SP
A=M
D=M
@THAT
M=D

//  push constant 200
@200
D=A
@SP
A=M
M=D
@SP
M=M+1

//  push local 1
@1
D=A
@LCL
D=D+M
@addr_247
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_247
A=M
M=D

//  push constant 40
@40
D=A
@SP
A=M
M=D
@SP
M=M+1

//  pop local 2
@2
D=A
@LCL
D=D+M
@addr_268
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_268
A=M
M=D

//  push constant 6
@6
D=A
@SP
A=M
M=D
@SP
M=M+1

//  pop local 3
@3
D=A
@LCL
D=D+M
@addr_289
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_289
A=M
M=D

// push constant 123
@123
D=A
@SP
A=M
M=D
@SP
M=M+1

//  call Sys.add12 1
@Sys.init$retAddrLabel_310
D=A
@SP
A=M
M=D
@SP
M=M+1
@LCL
D=M
@SP
A=M
M=D
@SP
M=M+1
@ARG
D=M
@SP
A=M
M=D
@SP
M=M+1
@THIS
D=M
@SP
A=M
M=D
@SP
M=M+1
@THAT
D=M
@SP
A=M
M=D
@SP
M=M+1
@1
D=A
@5
D=D+A
@SP
D=M-D
@ARG
M=D
@SP
D=M
@LCL
M=D
@Sys.add12
0;JMP
(Sys.init$retAddrLabel_310)

//  pop temp 0
@0
D=A
@5
D=D+A
@addr_360
M=D
@SP
M=M-1
@SP
A=M
D=M
@addr_360
A=M
M=D

//  push local 0
@0
D=A
@LCL
D=D+M
@addr_374
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push local 1
@1
D=A
@LCL
D=D+M
@addr_387
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push local 2
@2
D=A
@LCL
D=D+M
@addr_400
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push local 3
@3
D=A
@LCL
D=D+M
@addr_413
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push local 4
@4
D=A
@LCL
D=D+M
@addr_426
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  add
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D+M
@SP
A=M
M=D
@SP
M=M+1

//  add
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D+M
@SP
A=M
M=D
@SP
M=M+1

//  add
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D+M
@SP
A=M
M=D
@SP
M=M+1

//  add
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D+M
@SP
A=M
M=D
@SP
M=M+1

//  return
@LCL
D=M
@endFrame
M=D
@5
D=A
@endFrame
D=M-D
A=D
D=M
@Sys.init$retAddrLabel
M=D
@SP
M=M-1
A=M
D=M
@ARG
A=M
M=D
@1
D=A
@ARG
D=M+D
@SP
M=D
@1
D=A
@endFrame
D=M-D
A=D
D=M
@THAT
M=D
@2
D=A
@endFrame
D=M-D
A=D
D=M
@THIS
M=D
@3
D=A
@endFrame
D=M-D
A=D
D=M
@ARG
M=D
@4
D=A
@endFrame
D=M-D
A=D
D=M
@LCL
M=D
@Sys.init$retAddrLabel
A=M
0;JMP


//  function Sys.add12 0
(Sys.add12)

//  push constant 4002
@4002
D=A
@SP
A=M
M=D
@SP
M=M+1

//  pop pointer 0
@SP
M=M-1
@SP
A=M
D=M
@THIS
M=D

//  push constant 5002
@5002
D=A
@SP
A=M
M=D
@SP
M=M+1

//  pop pointer 1
@SP
M=M-1
@SP
A=M
D=M
@THAT
M=D

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_580
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push constant 12
@12
D=A
@SP
A=M
M=D
@SP
M=M+1

//  add
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D+M
@SP
A=M
M=D
@SP
M=M+1

//  return
@LCL
D=M
@endFrame
M=D
@5
D=A
@endFrame
D=M-D
A=D
D=M
@Sys.init$retAddrLabel_xyz
M=D
@SP
M=M-1
A=M
D=M
@ARG
A=M
M=D
@1
D=A
@ARG
D=M+D
@SP
M=D
@1
D=A
@endFrame
D=M-D
A=D
D=M
@THAT
M=D
@2
D=A
@endFrame
D=M-D
A=D
D=M
@THIS
M=D
@3
D=A
@endFrame
D=M-D
A=D
D=M
@ARG
M=D
@4
D=A
@endFrame
D=M-D
A=D
D=M
@LCL
M=D
@Sys.init$retAddrLabel_xyz
A=M
0;JMP
