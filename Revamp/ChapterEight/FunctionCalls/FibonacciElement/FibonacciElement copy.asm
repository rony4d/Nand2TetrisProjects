//  Bootstrap code
@256
D=A
@SP
M=D

//  call Sys.init 0
@returnBootstrap
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
@Sys.init
0;JMP
(returnBootstrap)


//  function Sys.init 0
(Sys.init)

//  push constant 4
@4
D=A
@SP
A=M
M=D
@SP
M=M+1

//  call Main.fibonacci 1
@Sys.init$retAddrLabel_62
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
@Main.fibonacci
0;JMP
(Sys.init$retAddrLabel_62)

//  Infinite Loop
(Sys.init$WHILE)
@Sys.init$WHILE
0;JMP

//  function Main.fibonacci 0
(Main.fibonacci)

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_116
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1

//  less than
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@LESS_THAN_136
D;JLT
@NOT_LESS_THAN_136
D;JGE
(LESS_THAN_136)
@SP
A=M
M=-1
@INCREMENT_SP_136
0;JMP
(NOT_LESS_THAN_136)
@SP
A=M
M=0
@INCREMENT_SP_136
0;JMP
(INCREMENT_SP_136)
@SP
M=M+1

// if-goto IF-TRUE
@SP
M=M-1
A=M
D=M
@Main.fibonacci$IF_TRUE
D;JNE

//  goto IF-FALSE
@Main.fibonacci$IF_FALSE
0;JMP

//  IF TRUE
(Main.fibonacci$IF_TRUE)

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_172
M=D
A=M
D=M
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
@ret          //  Sys.init$retAddrLabel
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
@ret      //  Sys.init$retAddrLabel
A=M
0;JMP

//  If False
(Main.fibonacci$IF_FALSE)

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_246
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push constant 2
@2
D=A
@SP
A=M
M=D
@SP
M=M+1

//  sub
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@SP
A=M
M=D
@SP
M=M+1

//  call Main.fibonacci 1
@Sys.init$retAddrLabel_279
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
@Main.fibonacci
0;JMP
(Sys.init$retAddrLabel_279)

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_329
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push constant 1
@1
D=A
@SP
A=M
M=D
@SP
M=M+1

//  sub
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@SP
A=M
M=D
@SP
M=M+1

//  call Main.fibonacci 1
@Sys.init$retAddrLabel_362
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
@Main.fibonacci
0;JMP
(Sys.init$retAddrLabel_362)

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
@xyz123          //  @Sys.init$retAddrLabel
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
@xyz123         //  @Sys.init$retAddrLabel
A=M
0;JMP
