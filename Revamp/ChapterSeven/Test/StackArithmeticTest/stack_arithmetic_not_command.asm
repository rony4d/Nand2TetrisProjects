//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  not stack_arithmetic : Bit-wise not 

//  The command below is what our add VM code should generate from the code generator

// Pushes one const and negates it.
// push constant 0
// not


//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 0 which is operand one

@0     
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1



//  not
@SP
M=M-1
A=M
M=!M    //  not the value stored in RAM[A]


@SP
M=M+1