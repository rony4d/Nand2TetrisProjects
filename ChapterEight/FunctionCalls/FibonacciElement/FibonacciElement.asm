// Debug: function declaration command Sys.init Count: 6
// Debug: Push contant 4, Count: 14 
// Debug:call command for function Sys.init Count: 66
// Debug: Label WHILE Count: 68
// Debug: goto command WHILE Count: 71
// Debug: function declaration command Main.fibonacci Count: 73
// Debug: Push Argument 0, Count: 88 
// Debug: Push contant 2, Count: 96 
// Debug: LT command, Count: 126 
// Debug: if-goto command IF_TRUE Count: 131
// Debug: goto command IF_FALSE Count: 134
// Debug: Label IF_TRUE Count: 136
// Debug: Push Argument 0, Count: 151 
// Debug:return command for function Main.fibonacci Count: 208
// Debug: Label IF_FALSE Count: 210
// Debug: Push Argument 0, Count: 225 
// Debug: Push contant 2, Count: 233 
// Debug: Sub command, Count: 245  
// Debug:call command for function Main.fibonacci Count: 297
// Debug: Push Argument 0, Count: 312 
// Debug: Push contant 1, Count: 320 
// Debug: Sub command, Count: 332  
// Debug:call command for function Main.fibonacci Count: 384
// Debug: Add command, Count: 396  
// Debug:return command for function Main.fibonacci Count: 453
@261 
D=A 
@SP 
M=D 
// S.P Initialization
(Sys.init) 
// Debug: Function Declaration command 
@4 
D=A 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push contant command 
@retAddrSys.init14 
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
@SP 
D=M 
@5 
D=D-A 
@1 
D=D-A 
@ARG 
M=D 
@SP 
D=M 
@LCL 
M=D 
@Main.fibonacci 
0;JMP 
(retAddrSys.init14) 
// Debug: Label command 
// Debug:  Call command ( First call to Main.Fibonacci)
(WHILE) 
// Debug: Label command 
@WHILE 
0;JMP 
// Debug: goto command 
(Main.fibonacci) 
// Debug: Function Declaration command 
@0 
D=A 
@pusharg 
M=D 
@ARG 
D=M+D 
@addr 
A=D 
D=M 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push argument command 
@2 
D=A 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push contant command 
@SP 
M=M-1 
@SP 
A=M 
D=M 
@SP 
M=M-1 
A=M 
M=M-D 
D=M 
@LESSTHAN96 
D;JLT 
@NOTLESSTHAN96 
0;JMP 
(LESSTHAN96) 
@SP 
A=M 
M=-1 
@END96 
0;JMP 
(NOTLESSTHAN96) 
@SP 
A=M 
M=0 
@END96 
0;JMP 
(END96) 
@SP 
M=M+1 
// Debug: Less Than(<) command 
@SP 
M=M-1 
@IF_TRUE 
D;JNE 
// Debug: if-goto command 
@IF_FALSE 
0;JMP 
// Debug: goto command 
(IF_TRUE) 
// Debug: Label command 
@0 
D=A 
@pusharg 
M=D 
@ARG 
D=M+D 
@addr 
A=D 
D=M 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push argument command 
@LCL 
D=M 
@endFrameMain.fibonacci151 
M=D 
@5 
D=A 
@endFrameMain.fibonacci151 
A=M-D 
D=M 
@retAddrMain.fibonacci151 
M=D 
@SP 
M=M-1 
@SP 
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
@endFrameMain.fibonacci151 
A=M-D 
D=M 
@THAT 
M=D 
@2 
D=A 
@endFrameMain.fibonacci151 
A=M-D 
D=M 
@THIS 
M=D 
@3 
D=A 
@endFrameMain.fibonacci151 
A=M-D 
D=M 
@ARG 
M=D 
@4 
D=A 
@endFrameMain.fibonacci151 
A=M-D 
D=M 
@LCL 
M=D 
@retAddrMain.fibonacci151 
A=M 
0;JMP 
// Debug: return command Main.Fibonacci 
(IF_FALSE) 
// Debug: Label command 
@0 
D=A 
@pusharg 
M=D 
@ARG 
D=M+D 
@addr 
A=D 
D=M 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push argument command 
@2 
D=A 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push contant command 
@SP 
M=M-1 
@SP 
A=M 
D=M 
@SP 
M=M-1 
A=M 
M=M-D 
@SP 
M=M+1 
// Debug: Sub command 
@retAddrMain.fibonacci245 
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
@SP 
D=M 
@5 
D=D-A 
@1 
D=D-A 
@ARG 
M=D 
@SP 
D=M 
@LCL 
M=D 
@Main.fibonacci 
0;JMP 
(retAddrMain.fibonacci245) 
// Debug: Label command 
// Debug:  Call Main Fibonacci command ( Second call to Main.Fibonacci)
@0 
D=A 
@pusharg 
M=D 
@ARG 
D=M+D 
@addr 
A=D 
D=M 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push argument command 
@1 
D=A 
@SP 
A=M 
M=D 
@SP 
M=M+1 
// Debug: Push contant command 
@SP 
M=M-1 
@SP 
A=M 
D=M 
@SP 
M=M-1 
A=M 
M=M-D 
@SP 
M=M+1 
// Debug: Sub command 
@retAddrMain.fibonacci332 
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
@SP 
D=M 
@5 
D=D-A 
@1 
D=D-A 
@ARG 
M=D 
@SP 
D=M 
@LCL 
M=D 
@Main.fibonacci 
0;JMP 
(retAddrMain.fibonacci332) 
// Debug: Label command 
// Debug:  Call Main Fibonacci command ( Third call to Main.Fibonacci)
@SP 
M=M-1 
@SP 
A=M 
D=M 
@SP 
M=M-1 
A=M 
M=M+D 
@SP 
M=M+1 
// Debug: Add command 
@LCL 
D=M 
@endFrameMain.fibonacci396 
M=D 
@5 
D=A 
@endFrameMain.fibonacci396 
A=M-D 
D=M 
@retAddrMain.fibonacci396 
M=D 
@SP 
M=M-1 
@SP 
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
@endFrameMain.fibonacci396 
A=M-D 
D=M 
@THAT 
M=D 
@2 
D=A 
@endFrameMain.fibonacci396 
A=M-D 
D=M 
@THIS 
M=D 
@3 
D=A 
@endFrameMain.fibonacci396 
A=M-D 
D=M 
@ARG 
M=D 
@4 
D=A 
@endFrameMain.fibonacci396 
A=M-D 
D=M 
@LCL 
M=D 
@retAddrMain.fibonacci396 
A=M 
0;JMP 
// Debug: return command (final return command to First call of Main.Fibonacci)