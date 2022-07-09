//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  pop/push this memory access command

//  The command below is what our add VM code should generate from the code generator

// Executes pop and push commands using the virtual memory segments.

// push constant 21
// push constant 22
// pop this 6
// push this 6
// push this 6


//  NOTE the following general push/pop segment(local, argument, this, that ) i formula
//  push segment i -> addr = segmentPointer + i; *SP = *addr ; SP++
//  pop  segment i -> addr = segmentPointer + i; SP-- ; *addr = *SP

//  Now, where segment is this
//  push this i -> addr = THIS + i; *SP = *addr ; SP++
//  pop  this i -> addr = THIS + i; SP-- ; *addr = *SP


//  NOTE[IMPORTANT]: You must run the BasicTest.tst file in the current directory so it can initialize the memory segments base addresses



//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 21

@21
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 22

@22
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1



//  pop this 6

@6          //  i
D=A

@THIS    
D=D+M       //  THIS + i

@addr
M=D         //  addr = THIS + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP      





// push this 6

@6
D=A         //  i

@THIS
D=D+M       //  THIS + i


@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++


// push this 6

@6
D=A         //  i

@THIS
D=D+M       //  THIS + i


@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++


 














