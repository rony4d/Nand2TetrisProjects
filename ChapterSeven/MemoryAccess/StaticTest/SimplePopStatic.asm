// Manually written asm code to see how pop static works

// Read from slide 74 on the Chapter 7 lecture Note

//  General Formula -> static i [in file statictest.vm] is translated into assembly [@statictest.i]
//  For our target platform Hack, the hack assembler will map these references onto
//  RAM[16], ... RAM[255] in the order in which they appear in the program just like other
//  custom label variables  


//  HOW IT WILL WORK

//  1.  Normally pop operation means you will take the value pointed to by stack pointer i.e *SP
//      and assign it to a memory location in the RAM. ie RAM[16] = *SP. 
//      In this case the memory location we will assign
//      it to will be the memory between RAM[16], ... RAM[255] sequentially. Don't worry the hack
//      assembler handles the memory allocation for us.

//  2.  Apply the regular push operation formula for memory segment taking the static memory
//      memory location as the memory location to get the data to push into the stack pointer
//      See example below

//      General Formula: pop static 5 ---> SP--, @statictest.5 = *SP

//      Push static 5 inside filename: statictest.vm
//      @statictest.5       // Get the value from RAM between RAM[16] and RAM[255]
//      See complete code below


//stack pointer initialization
@256
D=A

@SP
M=D

//pop static 5

// Applying formula :: pop static 5 ---> SP--, @statictest.5 = *SP

@SP
M=M-1

@SP
A=M     // Let us go to RAM[256]
D=M     //Assign *SP to D-register first

@@statictest.5
M=D     // @statictest.5 = *SP => RAM[16] = *SP
