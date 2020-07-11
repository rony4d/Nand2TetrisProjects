//  This file is to manually write the asm code to represent

//  Start from Slide 99 in the Chapter 8 Lecture Note and read only Handling Call

//  Run the NestedCallVME.tst in the VMEmulator and track it extremely carefully to understand 
//  how it works. I will recommend setting Animate to Program and Data Flow and set speed to slow so
//  you can watch how the whole thing works. It is really beautiful

//  Breaking down the call operation below: Follow carefully

//  ASSUMPTIONS:
//  1.  We are running this function(Sys.init) below in the VMEmulator and we are now at the "call Sys.main 0" part
//       which is the call operation with Animation set to program and data and speed set to slow


// *************************************

//  call Sys.main 0 -> Call    functionName   nArgs

// function Sys.init 0
// push constant 4000	// test THIS and THAT context save
// pop pointer 0
// push constant 5000
// pop pointer 1
// call Sys.main 0  ---->   We are analyzing this guy here. Pay close attention
// pop temp 1
// label LOOP
// goto LOOP

// *************************************


//  STEPS INVOLVED IN PERFORMING THE CALL OPERATION

//  1. push retAddrLabel    //  Using a translator-generated label
//  This means we should generate a unique label and push the address of that label to the stack

//  2. push LCL     This simply saves the LCL value of the caller in the memory location being pointed to 
//                  by the stack pointer

//  3. push ARG     This simply saves the ARG value of the caller in the memory location being pointed to 
//                  by the stack pointer

//  4. push THIS
//  5. push THAT
//  6. ARG = SP - 5 - nArgs     //  Repositions ARG
//  7. LCL = SP                 //  Repostions LCL
//  8. goto functionName        //  Transfers control to the called function
//  9. (retAddressLabel)        //  the same translator-generated label  

//  Implementing the Code

//  1. push retAddrLabel

@retAddr
D=A

@SP
A=M     //  Let us go to memory location pointed to by stack pointer
M=D     //  Assign the value of LCL to memory location pointed to by the stack

@SP
M=M+1

//  2. push LCL
@LCL
D=M

@SP
A=M     //  Let us go to memory location pointed to by stack pointer
M=D     //  Assign the value of LCL to memory location pointed to by the stack

@SP
M=M+1

//  3. push ARG
@ARG
D=M

@SP
A=M     //  Let us go to memory location pointed to by stack pointer
M=D     //  Assign the value of ARG to memory location pointed to by the stack

@SP
M=M+1

//  4. push THIS
@THIS
D=M

@SP
A=M     //  Let us go to memory location pointed to by stack pointer
M=D     //  Assign the value of THIS to memory location pointed to by the stack

@SP
M=M+1

//  5. push THAT
@THAT
D=M

@SP
A=M     //  Let us go to memory location pointed to by stack pointer
M=D     //  Assign the value of THAT to memory location pointed to by the stack

@SP
M=M+1

//  6. ARG = SP - 5 - nArgs     //  Repositions ARG

//  Assume nArgs = 0

@SP
D=M

@5
D=D-A

@0  //nArgs
D=D-A

@ARG
M=D

//  7. LCL = SP

@SP
D=M

@LCL
M=D     //  LCL = SP


//  8. goto functionName

@functionName
0;JMP       //  Go to the function name address by force

//  9. (retAddressLabel) -> Just print the return address label

(retAddr)
