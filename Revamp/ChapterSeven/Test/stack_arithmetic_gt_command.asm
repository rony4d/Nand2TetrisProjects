//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  greater than (gt) stack_arithmetic

//  The command below is what our add VM code should generate from the code generator

// Executes a sequence of arithmetic and logical operations
// on the stack. 

// pushes 2 constants and checks if first operand is greater than second operand . Return -1 which is true for the VM language and 0 which is 0 )

// push constant 892
// push constant 891
// lt

//  Initialize SP to 256

@256
D=A

@SP
M=D


// push constant 892

@892
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 891
@891
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

//  gt ( if first operand is greater than second operand, return -1 which is true for the VM language and 0 which is 0 )

@SP
M=M-1

A=M
D=M     //  second operand

@SP
M=M-1

A=M
D=M-D   //  first operand minus second operand 


@GREATER_THAN      //  if first operand minus second operand is greater than zero, then gt is satisfied
D;JGT

@NOT_GREATER_THAN  //  if first operand minus second operand is less than zero or equal to zero, then gt is not satisfied
D;JLE


(GREATER_THAN)
@SP
A=M
M=-1
@INCREMENT_SP
0;JMP



(NOT_GREATER_THAN)
@SP
A=M
M=0
@INCREMENT_SP
0;JMP


(INCREMENT_SP)  //  Jump here after either Greater Than or Not Greater Than is processed to finish the code block

@SP
M=M+1



