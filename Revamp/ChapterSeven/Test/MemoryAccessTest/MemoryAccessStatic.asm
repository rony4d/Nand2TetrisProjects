//  This file enables me test out the proposed asm for the different stack arithmetic and memory access commands

//  pop/push pointer memory access command

//  The command below is what our VM code should generate from the code generator

// Executes pop and push commands using the static segment.
// push constant 111
// push constant 333
// push constant 888
// pop static 8
// pop static 3
// pop static 1
// push static 3
// push static 1


//  Implementing push/pop static i


//  push static i -> addr = 16 + i; *SP = *addr ; SP++
//  pop  static i -> addr = 16 + i; SP-- ; *addr = *SP

//  NOTE: addr = filename.i 
//  NOTE[IMPORTANT]: You must run the StaticTest.tst file in the current directory so it can initialize the memory segments base addresses



//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 111

@111
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1



// push constant 333

@333
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// push constant 888

@888
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


//  pop static 8

@8          //  i
D=A

@16          
D=D+A       //  16 + i

@MemoryAccessStatic.8
M=D         //  addr = Temp + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP


@MemoryAccessStatic.8
A=M
M=D         //  *addr = *SP  



//  pop static 3

@3          //  i
D=A

@16          
D=D+A       //  16 + i

@MemoryAccessStatic.3
M=D         //  addr = Temp + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP


@MemoryAccessStatic.3
A=M
M=D         //  *addr = *SP 


//  pop static 1

@1          //  i
D=A

@16          
D=D+A       //  16 + i

@MemoryAccessStatic.1
M=D         //  addr = Temp + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP


@MemoryAccessStatic.1
A=M
M=D         //  *addr = *SP



// push static 3

@3
D=A         //  i

@16
D=D+A       //  16 + i


@MemoryAccessStatic.3
A=D
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++


// push static 1

@1
D=A         //  i

@16
D=D+A       //  16 + i


@MemoryAccessStatic.1
A=D
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++