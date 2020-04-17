// Manually written asm code to see how push pointer works

// Read from slide 81 on the Chapter 7 lecture Note

// General formula for push/pop pointer i, where i is the number you want to push or pop

// pop pointer 0/1 ---> SP--, THIS/THAT = *SP
// push pointer 0/1 ---> *SP = THIS/THAT, SP++

//NOTE: Accessing pointer 0 should result in accessing THIS (base address of this)
//      Accesing pointer 1 should result in accessing THAT  (base address of that)

// NOTE: This means you can only push or pop either pointer 0 or 1. You can't push or pop pointer 2 or 3 or ...n.

// I got the info below from the BasicTest.tst file.
// It will help me know how to initialize my memory segments

//set RAM[0] 256,   // stack pointer
//set RAM[1] 300,   // base address of the local segment
//set RAM[2] 400,   // base address of the argument segment
//set RAM[3] 3000,  // base address of the this segment
//set RAM[4] 3010,  // base address of the that segment

// push pointer 0
// push pointer 1


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

// that segment initialization
@3010
D=A
@THAT
M=D


//push pointer 0

// Applying formula :: push pointer 0 ---> *SP = THIS, SP++
@THIS
D=M    

@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = THIS -> RAM[256] = 3000

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257

//push pointer 1

// Applying formula :: push pointer 0 ---> *SP = THAT, SP++
@THAT
D=M    

@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = THIS -> RAM[256] = 3000

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257