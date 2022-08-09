//  bootstrap
@261
D=A
@SP
M=D


(Sys.init)
@4
D=A
@SP
A=M
M=D
@SP
M=M+1

//  call Main.fibonacci 1       
@RETURN23                      // @RETURN23    @Sys.init$retAddrLabel
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
(RETURN23)             // (RETURN23)    (Sys.init$retAddrLabel)



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
@addr_62
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

//  lt
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@LESS_THAN_82
D;JLT
@NOT_LESS_THAN_82
D;JGE
(LESS_THAN_82)
@SP
A=M
M=-1
@INCREMENT_SP_82
0;JMP
(NOT_LESS_THAN_82)
@SP
A=M
M=0
@INCREMENT_SP_82
0;JMP
(INCREMENT_SP_82)
@SP
M=M+1

//  if-goto IF_TRUE
@SP
M=M-1
A=M
D=M


@Main.fibonacci$IF_TRUE
D;JNE

//  goto IF_FALSE
@Main.fibonacci$IF_FALSE
0;JMP

//  label IF_TRUE
(Main.fibonacci$IF_TRUE)

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_118
M=D
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1

// return 
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
@ret                        // @ret     Sys.init$retAddrLabel

M=D                         //  RET = *(endframe - 5)
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
@ret                                        // @ret     @Sys.init$retAddrLabel 
A=M
0;JMP


//  label IF_FALSE
(Main.fibonacci$IF_FALSE)

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_192
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
@RETURN14               //  @RETURN14    @Main.fibonacci$retAddrLabel 
D=A
@SP
A=M
M=D         //  push return-address
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
0;JMP                       //  goto Main.fibonacci
(RETURN14)                       //  (RETURN14)  (Main.fibonacci$retAddrLabel)

//  push argument 0
@0
D=A
@ARG
D=D+M
@addr_275
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
@RETURN18                    //  @RETURN18
D=A
@SP
A=M
M=D     //  push return-address

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
0;JMP                               //  goto Main.fibonacci
(RETURN18)       //  (RETURN18)  (Main.fibonacci$retAddrLabel)


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


// return
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
@ret                        // @ret             @Main.fibonacci$retAddrLabel 
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
@ret                            //  @ret        @Main.fibonacci$retAddrLabel 
A=M
0;JMP


