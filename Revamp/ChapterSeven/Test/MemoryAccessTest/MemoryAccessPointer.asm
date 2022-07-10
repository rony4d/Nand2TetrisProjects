//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  pop/push pointer memory access command

//  The command below is what our add VM code should generate from the code generator

// pointer, this, and that segments.
// push constant 3030
// pop pointer 0
// push constant 3040
// pop pointer 1
// push pointer 0
// push pointer 1


//  Implementing push/pop pointer 0/1

//  push pointer 0 -> *SP = THIS; SP++
//  push pointer 1 -> *SP = THAT; SP++

//  pop pointer 0 -> SP--; THIS = *SP
//  pop pointer 1 -> SP--; THAT = *SP



//  NOTE[IMPORTANT]: You must run the PointerTest.tst file in the current directory so it can initialize the memory segments base addresses



//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 3030

@3030
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1





//  pop pointer 0
//  pop pointer 0 -> SP--; THIS = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THIS
M=D         //  THIS = *SP      



// push constant 3040

@3040
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

//  pop pointer 1
//  pop pointer 1 -> SP--; THAT = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THAT
M=D         //  THIS = *SP      

  

//  push pointer 0
//  push pointer 0 -> *SP = THIS; SP++

@THIS
D=M


@SP
A=M
M=D         //  *SP = THIS

@SP
M=M+1       //  SP++


//  push pointer 1
//  push pointer 1 -> *SP = THAT; SP++

@THAT
D=M


@SP
A=M
M=D         //  *SP = THAT

@SP
M=M+1       //  SP++



 














