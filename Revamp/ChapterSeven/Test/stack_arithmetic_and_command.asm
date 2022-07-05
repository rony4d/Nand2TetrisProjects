//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  and stack_arithmetic    . Bit-wise and

//  The command below is what our add VM code should generate from the code generator

// Pushes and subs two constants and performs bitwise-and on both operands
// push constant 17
// push constant 0
// and


//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 17 which is operand one

@17     
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 0 which is operand two
@0      
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


//  and
@SP
M=M-1
A=M
D=M     //  operand two
@SP
M=M-1
A=M
D=D&M   //  operand one & operand two. Refer to Chapter 4 lecture note or text to see the table

@SP
A=M
M=D


@SP
M=M+1