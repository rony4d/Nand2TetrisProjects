// Manually written asm code to see how push local works

//push local 0

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
A=D
D=M


@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = *ADDR

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257
