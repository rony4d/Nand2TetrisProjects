//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  pop/push temp memory access command

//  The command below is what our add VM code should generate from the code generator

// Executes pop and push commands using the virtual memory segments.

// push constant 15
// push constant 45
// pop temp 6
// pop temp 7
// push temp 7

//  NOTE: Temp has a fixed 8-place memory segment from RAM[5] to RAM[12] . This means we can't have i to be > 7. It will throw out of segment error

//  NOTE the following general push/pop temp i formula

//  Now, where segment is local
//  push temp i -> addr = 5 + i; *SP = *addr ; SP++
//  pop  that i -> addr = 5 + i; SP-- ; *addr = *SP


//  NOTE[IMPORTANT]: You must run the BasicTest.tst file in the current directory so it can initialize the memory segments base addresses



//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 15

@15
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 45

@45
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1



//  pop temp 6

@6          //  i
D=A

@5          
D=D+A       //  Temp + i

@addr
M=D         //  addr = Temp + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP      


//  pop temp 7

@7         //  i
D=A

@5    
D=D+A       //  Temp + i

@addr
M=D         //  addr = Temp + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP  




// push temp 7

@7
D=A         //  i

@5
D=D+A       //  Temp + i


@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++





 














