// Manually written asm code to see how push THIS works

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
A=D
D=M

@SP         // We are at RAM[0] with value 256
A=M
M=D         // *SP = *ADDR -> RAM[256] = RAM[3006] = 6

@SP         // we are at RAM[0] with value 256
M=M+1       // SP++ , now value at RAM[0] is 257
