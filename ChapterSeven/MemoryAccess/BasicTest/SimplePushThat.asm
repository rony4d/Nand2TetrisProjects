// Manually written asm code to see how push THAT works

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

// that segment initialization
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
A=D
D=M

@SP         // We are at RAM[0] with value 256
A=M
M=D         // *SP = *ADDR -> RAM[256] = RAM[3018] = 8

@SP         // we are at RAM[0] with value 256
M=M+1       // SP++ , now value at RAM[0] is 257
