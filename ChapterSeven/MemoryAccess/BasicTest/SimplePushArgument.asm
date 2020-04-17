// Manually written asm code to see how push arg works

// General formula for push/pop memory segment i, where i is the number you want to push or pop

// pop segmentPointer i ---> addr = segmentPointer + i, SP--, *addr = *SP
// push segmentPointer i ---> addr = segmentPointer + i, *SP = *addr, SP++

//push argument 2

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

// argument segment initialization
@400
D=A
@ARG
M=D

//push argument 2
@2
D=A    

@pusharg
M=D         //assign push argument value to pusharg variable

@ARG        // we are at RAM[1] with value 300
D=M+D       // ARG + 2 => 400 + 2 -> D-register

@addr
A=D
D=M


@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = *ADDR -> RAM[256] = RAM[402] = 2

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257
