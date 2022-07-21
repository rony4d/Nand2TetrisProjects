//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  neg stack_arithmetic : Arithmetic Negation 

//  The command below is what our add VM code should generate from the code generator

// Pushes one const and negates it.
// push constant 10
// neg


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



//  neg
@SP
M=M-1
A=M
M=-M    //  negate the value stored in RAM[A]


@SP
M=M+1