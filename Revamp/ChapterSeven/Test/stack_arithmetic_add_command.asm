//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  add_arithmetic

//  The command below is what our add VM code should generate from the code generator

// Pushes and adds two constants.
// push constant 7
// push constant 8
// add


//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 7

@7
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 8
@8
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
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