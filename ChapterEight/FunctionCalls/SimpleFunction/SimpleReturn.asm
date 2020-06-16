//  This file is to manually write the asm code to represent return in a function

//  Start from Slide 126 in the Chapter 8 Lecture Note and read only Handling Return

//  Run the SimpleFunctionVME.tst in the VMEmulator and track it extremely carefully to understand 
//  how it works. I will recommend setting Animate to Program and Data Flow and set speed to slow so
//  you can watch how the whole thing works. It is really beautiful

//  Breaking down the return operation below: Follow carefully

//  ASSUMPTIONS:
//  1.  We have finished running this function below in the VMEmulator and we are now at the last
//      part which is the return operation with Animation set to program and data and speed set to slow

// *************************************
// function SimpleFunction.test 2
// push local 0
// push local 1
// add
// not
// push argument 0
// add
// push argument 1
// sub
// return   ---->   We are analyzing this guy here. Pay close attention
// *************************************

//  2. Memory segment values that were stored in a frame before we entered this function
//  SP:		317
//  LCL:	317
//  ARG:	310
//  THIS:	3000
//  THAT:	4000
//  Value that was calculated in the function that is to be returned = 1196.

//  Initial Memory segment values that were stored in a frame before we entered this function
//  NOTE: These memory segment values that were stored in the frame are stored as arguments


//  STEPS INVOLVED IN PERFORMING THE RETURN OPERATION

//  1.  endFrame = LCL
//  The endFrame value is 317 and this is because 317 is the last value in the stack after the previous
//  values from the caller function were saved in the frame and NOTE that this value must be equal to
//  the LCL since we will have to initialize the local variables first. So it means that when a function
//  is called the SP and the LCL must be the same. I hope this observation holds true.

//  2.  retAddr = *(endFrame - 5) => *(317 - 5) => *(312). This simply means that the return address is
//  the value stored in memory location 312 that is RAM[312]. Why remove 5? 5 was removed because if
//  you look at the frame holding the values of the caller function you will see that there are 5 memory
//  segments captured in that frame:
//  1. return address, 2. saved LCL, 3. saved ARG, 4. saved THIS, 5. saved THAT. 
//  After these values are saved which means S.P moved 5 times. Then the starting LCL for the new function
//  we entered will be endFrame which is equal to the S.P for the new function as well.
//  So now that we are returning back to the caller function, to get the return address(retAddr) we need to
//  subtract 5 from the LCL which is the endframe and then the return value will be the value pointed to 
//  by that address which is *(endfram - 5) and in this case the value is 9. Run the VMEmulator and see the value as 9

//  3. *ARG = pop() => This repositions the return value for the caller function
//  This means that the value that is pointed to by the ARG memory location  is equal to 
//  the current value pointed to by the Stack pointer. 
//  In this example it means RAM[310] = 1196. You can see this magic on Slide 129. 

//  4. SP = ARG + 1 => This repositions the stack pointer of the caller function.
//  This means the value of the Stack Pointer of the caller function = 300 + 1 = 311

//  5. THAT = *(endFrame – 1) restores THAT of the caller
//  6. THIS = *(endFrame – 2) restores THIS of the caller
//  7. ARG = *(endFrame – 3)  restores ARG of the caller
//  8. LCL = *(endFrame – 4)  restores LCL of the caller
//  9. goto retAddr           goes to the callers return address 


//  Implementing the code

//  1.  endFrame = LCL -> Assing LCL to a temporary variable -> endFrame = 317

@LCL
D=A

@endFrame
M=D

//  2.  retAddr = *(endFrame - 5) => *(317 - 5) => *(312)

@5
D=A

@endFrame   //  We are at temporary variable memory address with value inside the address to be 317
A=M-D       //  We are preparing to move to memory location (317 -5) by putting 312 in A-register
D=M         //  We are at RAM[312] and we assign the value there to D-register to hold

@retAddr    //  we create another temporary address and then assign the value of D-register to it
M=D

//  3. *ARG = pop() -> Take the current value in the stack and put it into the ARG memory location

//  Let us pop the value from the Stack and then assign the value to ARG memory location

@SP
M=M-1

@SP
A=M     // Let us go to RAM[256]
D=M     //Assign *SP to D-register first

@ARG
M=D     // *ARG = *SP

//  4. SP = ARG + 1

@1
D=A

@ARG
D=D+A

@SP
M=D

//  5. THAT = *(endFrame – 1)

@1
D=A

@endFrame   //  We are at temporary variable memory address with value inside the address to be 317
A=M-D       //  We are preparing to move to memory location (317 -1) by putting 316 in A-register
D=M         //  We are at RAM[316] and we assign the value there to D-register to hold

@THAT
M=D

//  6. THIS = *(endFrame – 2)

@2
D=A

@endFrame   //  We are at temporary variable memory address with value inside the address to be 317
A=M-D       //  We are preparing to move to memory location (317 - 2) by putting 315 in A-register
D=M         //  We are at RAM[315] and we assign the value there to D-register to hold

@THIS
M=D

//  7. ARG = *(endFrame – 3)

@3
D=A

@endFrame   //  We are at temporary variable memory address with value inside the address to be 317
A=M-D       //  We are preparing to move to memory location (317 - 3) by putting 314 in A-register
D=M         //  We are at RAM[314] and we assign the value there to D-register to hold

@ARG
M=D

//  8. LCL = *(endFrame – 4)

@4
D=A

@endFrame   //  We are at temporary variable memory address with value inside the address to be 317
A=M-D       //  We are preparing to move to memory location (317 - 4) by putting 313 in A-register
D=M         //  We are at RAM[313] and we assign the value there to D-register to hold

@LCL
M=D

//  9. goto retAddr
 
        
@retAddr
0;JMP   //  goto label retAddr by force.