//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  sub stack_arithmetic

//  The command below is what our add VM code should generate from the code generator

// Pushes and subs two constants. operand one should sub operand two. i.e operand one - operand two
// push constant 10
// push constant 8
// sub


//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 10 which is operand one

@10     
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 8 which is operand two
@8      
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


//  sub
@SP
M=M-1
A=M
D=M     //  operand two
@SP
M=M-1
A=M
D=M-D   //  operand one minus operand two
@SP
A=M
M=D
@SP
M=M+1