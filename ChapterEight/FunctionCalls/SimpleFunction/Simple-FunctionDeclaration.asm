//  This file is to manually write the asm code to represent
//  function SimpleFunction.test 2

//  Start from Slide 119 in the Chapter 8 Lecture Note and read only Handling Function
//  Run the SimpleFunctionVME.tst in the VMEmulator and track it extremely carefully to understand 
//  how it works. I will recommend setting Animate to Program and Data Flow and set speed to slow so
//  you can watch how the whole thing works. It is really beautiful

//  Test Case:  function SimpleFunction.test 2
//              Number of local variables: 2. This means we have to push constant 0, two times

//  See VM representation of the initialization process of function SimpleFunction.test 2 below
//  push constant 0
//  push constant 0

//  See ASM representation of the initialization process of function SimpleFunction.test 2

    @0
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)
    
    @0
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)