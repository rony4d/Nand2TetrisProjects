// Manually written asm code to see how push static works

// Read from slide 74 on the Chapter 7 lecture Note

//  General Formula -> static i [in file statictest.vm] is translated into assembly [@statictest.i]
//  For our target platform Hack, the hack assembler will map these references onto
//  RAM[16], ... RAM[255] in the order in which they appear in the program just like other
//  custom label variables  


//  HOW IT WILL WORK

//  1.  Normally push operation means you will take the value in a memory location
//      and assign it to the location pointed to by the stack pointer. i.e *SP = RAM[16]
//      it to will be the memory between RAM[16], ... RAM[255] sequentially. Don't worry the hack
//      assembler handles the memory allocation for us.

//  2.  Apply the regular push operation formula for memory segment taking the static memory
//      memory location as the memory location to get the data to push into the stack pointer
//      See example below

//      General Formula: push static 5 ---> *SP = @statictest.5, SP++

//      Push static 5 inside filename: statictest.vm
//      @statictest.5       // Get the value from RAM between RAM[16] and RAM[255]
//      See complete code below


//stack pointer initialization
@256
D=A

@SP
M=D

//push static 5

// Applying formula :: push static 5 ---> *SP = @statictest.5, SP++
@statictest.5
D=M    

@SP     // We are at RAM[0] with value 256
A=M
M=D     // *SP = @statictest.5 -> RAM[16] => *SP = RAM[16]

@SP     // we are at RAM[0] with value 256
M=M+1   // SP++ , now value at RAM[0] is 257
