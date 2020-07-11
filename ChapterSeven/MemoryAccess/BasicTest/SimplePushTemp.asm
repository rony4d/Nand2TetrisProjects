// Manually written asm code to see how push argument works

// Read from Slide 77 of Lecture note to learn more about Temp
// General formula for push/pop temp i, where i is the number you want to push or pop

// pop temp i---> addr=5+i,SP--,*addr=*SP
// push temp i ---> addr=5+i,*SP=*addr,SP++

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

// temp segment initialization
@5
D=A
//M=D - remove this, temp segment is already initialized from test script, so all you need is the RAM address which is 5 and store in D-register

//push temp 6

@6
D=D+A   // 5 + i where i in this case is 6

// @pushtemp    - remove redundant line of code
// M=D          - remove redundant line of code //assign push temp value to pushtemp variable

//@5 (remove this line of code)         // we are at RAM[5] with value 5
//D=M+D  (remove this line of code)     // Temp + 2 => 5 + 2 -> D-register


// @pushtemp    - remove redundant line of code
// D=M          - remove redundant line of code

@addr
A=D
D=M     // RAM[5 + i] = i, this is *ADDR. This means we have stored *ADDR in D-register

@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = *ADDR -> RAM[256] = RAM[11] = 6

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257