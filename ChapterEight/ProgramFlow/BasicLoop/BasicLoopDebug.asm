//          I used this file to debug my BasicLoop.asm file   
//  Please do not use the BasicLoop.tst script in testing in the CPU Emulator because it injects code. Don't know why

// Debug: Push contant 0, Count: 11 
// Debug: Pop local 0, Count: 25 
// Debug: Label LOOP_START Count: 26
// Debug: Push Argument 0, Count: 40 
// Debug: Push local 0, Count: 54 
// Debug: Add command, Count: 65  
// Debug: Pop local 0, Count: 79 
// Debug: Push Argument 0, Count: 93 
// Debug: Push contant 1, Count: 100 
// Debug: Sub command, Count: 111  
// Debug: Pop Argument 0, Count: 125 
// Debug: Push Argument 0, Count: 139 
// Debug: if-goto command Count: 153
// Debug: Push local 0, Count: 167 

@256 
D=A 
@SP 
M=D

//  Push contant 0 starts  
@0 
D=A 
@SP 
A=M 
M=D 
@SP 
M=M+1
//  Push contant 0 starts

//  Pop local 0 starts 
@0 
D=A 
@LCL 
D=M+D 
@addr 
M=D 
@SP 
M=M-1 
@SP 
A=M 
D=M 
@addr 
A=M 
M=D
//  Pop local 0 ends

//  Label LOOP_START starts 
(LOOP_START)
//  Label LOOP_START ends

//  Push Argument 0 starts
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
//  Push Argument 0 ends

//  Push local 0 starts 
@0 
D=A 
@pushlocal 
M=D 
@LCL 
D=M+D 
@addr 
A=D 
D=M 
@SP 
A=M 
M=D 
@SP 
M=M+1
//  Push local 0 ends

//  Add command starts 
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
//  Add command ends 

//  Pop local 0 starts
@0 
D=A 
@LCL 
D=M+D 
@addr 
M=D 
@SP 
M=M-1 
@SP 
A=M 
D=M 
@addr 
A=M 
M=D
//  pop local 0 ends

//  Push Argument 0 starts
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
//  Push Argument 0 ends 

//  Push contant 1 starts
@1 
D=A 
@SP 
A=M 
M=D 
@SP 
M=M+1
//  Push contant 1 ends

//  Sub command starts
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
//  Sub command ends

//  Pop Argument 0 starts 
@0 
D=A 
@ARG 
D=M+D 
@addr 
M=D 
@SP 
M=M-1 
@SP 
A=M 
D=M 
@addr 
A=M 
M=D
//  Pop Argument 0 ends

//  Push Argument 0 starts
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
//  Push Argument 0 ends 

//  if-goto command starts (pop the topmost element in the stack)
@SP 
M=M-1
// D=M 
// @addr 
// M=D 
// @SP 
// M=M-1 
// @SP 
// A=M 
// D=M 
// @addr 
// A=M 
// M=D 
@LOOP_START 
D;JNE
//  if-goto command ends

//  Push local 0 starts 
@0 
D=A 
@pushlocal 
M=D 
@LCL 
D=M+D 
@addr 
A=D 
D=M 
@SP 
A=M 
M=D 
@SP 
M=M+1
//  Push local 0 ends 