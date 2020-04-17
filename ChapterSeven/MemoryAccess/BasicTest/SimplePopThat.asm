// Manually written asm code to see how pop THAT works

// To Pop means, give me what is available in the *SP and let me put it in the memory segment I want
// I can decide to put it in the local, argument, this, that

//-----We want to test pop so let us push local first and then pop

// General formula for push/pop memory segment i, where i is the number you want to push or pop

// pop segmentPointer i ---> addr = segmentPointer + i, SP--, *addr = *SP
// push segmentPointer i ---> addr = segmentPointer + i, *SP = *addr, SP++

//push this 6


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

// this segment initialization
@3010
D=A
@THAT
M=D

//push that 8

@8
D=A     

@pushthat
M=D         //assign push that value to pushthat variable

@THAT       // we are at RAM[1] with value 3010
D=M+D       // THAT + 8 => 3010 + 8

@addr
M=D

@pushthat
D=M

@addr
A=M
M=D         // RAM[THAT + i] = i, this is *ADDR

@SP         // We are at RAM[0] with value 256
A=M
M=D         // *SP = *ADDR -> RAM[256] = RAM[3018] = 8

@SP         // we are at RAM[0] with value 256
M=M+1       // SP++ , now value at RAM[0] is 257


//pop that 20


@20
D=A   

@THAT   //we are in the this segment base register RAM[3] with value 3010 based on THAT initialization
D=M+D   //THIS + i => 3010 + 20 => 3030, this means register D will hold value of 3030

@addr
M=D     // We assgin 3030 to addr variable to hold the value

@SP     // we are at RAM[0] with value 257
M=M-1   // SP-- , now value at RAM[0] is 256

@SP     // We are at RAM[0] with value 256
A=M
D=M     // We are at RAM[256] Store the value at RAM[256] in D-register

@addr
A=M         // Assgin A to 3030, so we move to RAM[3030]
M=D         // RAM[3030] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
