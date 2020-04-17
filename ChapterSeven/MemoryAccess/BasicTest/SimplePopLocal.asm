// Manually written asm code to see how pop local works

// To Pop means, give me what is available in the *SP and let me put it in the memory segment I want
// I can decide to put it in the local, argument, this, that
//pop local 4

//LCL RAM[1] points to the base of the current VM function's local segment

// I got the info below from the BasicTest.tst file.
// It will help me know how to initialize my memory segments

//set RAM[0] 256,   // stack pointer
//set RAM[1] 300,   // base address of the local segment
//set RAM[2] 400,   // base address of the argument segment
//set RAM[3] 3000,  // base address of the this segment
//set RAM[4] 3010,  // base address of the that segment

//stack pointer initialization
@256
D=A

@SP
M=D

// local segment initialization
@300
D=A
@LCL
M=D

//-----We want to test pop so let us push local first and then pop

//push local 5

// General formula for push/pop local i, where i is the number you want to push or pop
// pop local i ---> addr = LCL+ i, SP--, *addr = *SP
// push local i ---> addr = LCL+ i, *SP = *addr, SP++

// to push local 5 ---> ADDR = LCL + 5, *SP = *addr, SP++

@5
D=A     

@pushlocal
M=D     //assign push local value  to pushlocal variable

@LCL    // we are at RAM[1] with value 300
D=M+D   // LCL + 5 -> D-register

@addr
M=D     //  LCL + 2 => 300 + 2, hold in addr variable

@pushlocal
D=M

@addr
A=M
M=D     //  RAM[LCL + i] = i, this is *ADDR

@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = *ADDR

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257

//pop local 10

// General formula for push/pop local i, where i is the number you want to push or pop
// pop local i ---> addr = LCL+ i, SP--, *addr = *SP

// to pop local 10 ---> ADDR = LCL + 10, SP--, *addr = *SP

@10
D=A       

@LCL        //we are in the LCL segment base register RAM[1] with value 300 based on LCL initialization
D=M+D       // LCL + i => 300 + 10 => 310, this means register D will hold value of 310

@addr
M=D         // We assgin 314 to addr variable to hold the value

@SP         // we are at RAM[0] with value 257
M=M-1       // SP-- , now value at RAM[0] is 256

@SP         // We are at RAM[0] with value 256
A=M
D=M         // We are at RAM[256] Store the value at RAM[256] in D-register

@addr
A=M         // Assgin A to 310, so we move to RAM[310]
M=D         // RAM[310] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!

