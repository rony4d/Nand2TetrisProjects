//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  equal (eq) stack_arithmetic

//  The command below is what our add VM code should generate from the code generator

// Executes a sequence of arithmetic and logical operations
// on the stack. 

// pushes 2 constants and checks if they are equal.  If they are equal, return -1 which is true for the VM language and 0 which is 0 )

// push constant 17
// push constant 17
// eq

//  Initialize SP to 256

@256
D=A

@SP
M=D


// push constant 17

@8
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 17
@17
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

//  eq ( if operands are equal, return -1 which is true for the VM language and 0 which is 0 )

@SP
M=M-1

A=M
D=M

@SP
M=M-1

A=M
D=D-M


@EQUAL
D;JEQ

@NOT_EQUAL
D;JNE


(EQUAL)
@SP
A=M
M=-1
@INCREMENT_SP
0;JMP



(NOT_EQUAL)
@SP
A=M
M=0
@INCREMENT_SP
0;JMP


(INCREMENT_SP)  //  Jump here after either Equal or Not Equal is processed to finish the code block

@SP
M=M+1



