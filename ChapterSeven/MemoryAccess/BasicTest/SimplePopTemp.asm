// Manually written asm code to see how pop argument works

// To Pop means, give me what is available in the *SP and let me put it in the memory segment I want
// I can decide to put it in the local, argument, this, that

//-----We want to test pop so let us push local first and then pop

// General formula for push/pop memory segment i, where i is the number you want to push or pop

// pop segmentPointer i ---> addr = segmentPointer + i, SP--, *addr = *SP
// push segmentPointer i ---> addr = segmentPointer + i, *SP = *addr, SP++

//stack pointer initialization
@256
D=A

@SP
M=D

// temp segment initialization
@5
D=A
M=D

//push temp 6

@6
D=A

@pushtemp
M=D         //assign push temp value to pushtemp variable

@5          // we are at RAM[5] with value 5
D=M+D       // Temp + 2 => 5 + 2 -> D-register

@addr
M=D

@pushtemp
D=M

@addr
A=M
M=D     // RAM[5 + i] = i, this is *ADDR

@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = *ADDR -> RAM[256] = RAM[11] = 6

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257


//pop temp 8


@8
D=A       

@5          // we are in the temp segment base register RAM[5] with value 5 based on temp initialization 5
D=M+D       // 5 + i => 5 + 8 => 13, this means register D will hold value of 13

@addr
M=D         // We assgin 13 to addr variable to hold the value

@SP         // we are at RAM[0] with value 257
M=M-1       // SP-- , now value at RAM[0] is 256

@SP         // We are at RAM[0] with value 256
A=M
D=M         // We are at RAM[256]. we store the value at RAM[256] in D-register

@addr
A=M         // Assgin A to 13, so we move to RAM[13]
M=D         // RAM[13] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
