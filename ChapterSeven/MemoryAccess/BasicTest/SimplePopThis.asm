// Manually written asm code to see how pop THIS works

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
@3000
D=A
@THIS
M=D

//push this 6

@6
D=A     

@pushthis
M=D         //assign push this value to pushthis variable

@THIS       // we are at RAM[1] with value 3000
D=M+D       // THIS + 2 => 3000 + 6

@addr
M=D

@pushthis
D=M

@addr
A=M
M=D         // RAM[THIS + i] = i, this is *ADDR

@SP         // We are at RAM[0] with value 256
A=M
M=D         // *SP = *ADDR -> RAM[256] = RAM[3006] = 6

@SP         // we are at RAM[0] with value 256
M=M+1       // SP++ , now value at RAM[0] is 257


//pop this 20


@20
D=A   

@THIS   //we are in the this segment base register RAM[3] with value 3000 based on THIS initialization
D=M+D   //THIS + i => 3000 + 20 => 3020, this means register D will hold value of 3020

@addr
M=D     // We assgin 3020 to addr variable to hold the value

@SP     // we are at RAM[0] with value 257
M=M-1   // SP-- , now value at RAM[0] is 256

@SP     // We are at RAM[0] with value 256
A=M
D=M     // We are at RAM[256] Store the value at RAM[256] in D-register

@addr
A=M         // Assgin A to 3020, so we move to RAM[3020]
M=D         // RAM[3020] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
