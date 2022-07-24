//  This file enables me test out the proposed asm for function call and return VM commands

//  function call and return VM command

//  The command below is what our simple function VM code should generate from the code generator




// Performs a simple calculation and returns the result.
// function SimpleFunction.test 2
// push local 0
// push local 1
// add
// not
// push argument 0
// add
// push argument 1
// sub
// return


//  NOTE:This is not a function call simce there is no 'call function_name n' code but the return will be handled like any normal function return.

//  The test file has already handled caller state saving, so it is assumed that this function was called by another function.

//  See SimpleFunctionVME.tst to understand all the initializations that have occured

//  We are assuming this function has already been called so it should fall under Handling Function section ( Slide 119 on Lecture note )

(SimpleFunction.test)

//=================== Function Initialization ( Initialize the 2 local variables ) =========================

//  push constant 0

@0
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

//  pop local 0

@0          //  i
D=A

@LCL
D=D+M       //  LCL + i


@addr_pop_local_01
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr_pop_local_01
A=M
M=D         //  *addr = *SP

//  Increment SP since we are initializing the local variables

//  SP++
@SP
M=M+1

//  push constant 0
@0
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


//  pop local 1
@1          //  i
D=A

@LCL
D=D+M       //  LCL + i

@addr_pop_local_1
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr_pop_local_1
A=M
M=D         //  *addr = *SP


//  Increment SP since we are initializing the local variables

//  SP++
@SP
M=M+1


//  =======================  Implement functions execution code   =========================

// push local 0


@0
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr_push_local_0
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// push local 1
@1
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr_push_local_1
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// add

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D+M
@SP
A=M
M=D
@SP
M=M+1


// not

@SP
M=M-1
A=M
M=!M    //  not the value stored in RAM[A]


@SP
M=M+1

// push argument 0

@0
D=A         //  i

@ARG
D=D+M       //  ARG + i


@addr_arg_0
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++


// add

@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D+M
@SP
A=M
M=D
@SP
M=M+1

// push argument 1

@1
D=A         //  i

@ARG
D=D+M       //  ARG + i


@addr_push_arg_1
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// sub
@SP
M=M-1
A=M
D=M     //  operand two
@SP
M=M-1
A=M
D=M-D   //  operand one minus operand two
@SP
A=M
M=D
@SP
M=M+1



//================================= Implement return ( See from slide 126 on lecture note ) =================================

//  For this function call we need to assume that the caller state has already been saved because it was done in the test file


//  endFrame = LCL              //  endFrame is a temporary variable
//  retAddr = *(endFrame-5)     //  gets the return address of caller function
//  *ARG = pop()                //  pops the current value from the stack which is the return value and then puts that value inside ARG 0
//  SP = ARG + 1                //  repositions to SP of the caller.
//  THAT = *(endFrame - 1)      //  restores THAT of the caller
//  THIS = *(endFrame - 2)      //  restores THIS of the caller
//  ARG =  *(endFrame - 3)      //  restores ARG of the caller
//  LCL =  *(endFrame - 4)      //  restores LCL of the caller
//  goto retAddr                //  goes to the caller's return address.This is the first item in the caller's saved frame and this address should be
                                //  next line of code that continues the caller's execution


//  endFrame = LCL
@LCL
D=M

@endFrame
M=D

//  retAddr = *(endFrame-5)      //  gets the return address of caller function
@5
D=A
@endFrame
D=M-D
A=D
D=M

@retAddr
M=D

//  *ARG = pop()                //  pops the current value from the stack which is the return value and then puts that value inside ARG 0
@SP
M=M-1
A=M
D=M

@ARG
A=M
M=D


//  SP = ARG + 1                //  repositions to SP of the caller.
@1
D=A

@ARG
D=M+D

@SP
M=D

//  THAT = *(endFrame - 1)      //  restores THAT of the caller
@1
D=A
@endFrame
D=M-D
A=D
D=M

@THAT
M=D

//  THIS = *(endFrame - 2)      //  restores THIS of the caller
@2
D=A
@endFrame
D=M-D
A=D
D=M

@THIS
M=D

//  ARG =  *(endFrame - 3)      //  restores ARG of the caller
@3
D=A
@endFrame
D=M-D
A=D
D=M

@ARG
M=D

//  LCL =  *(endFrame - 4)      //  restores LCL of the caller
@4
D=A
@endFrame
D=M-D
A=D
D=M

@LCL
M=D


//  goto retAddr                //  goes to the caller's return address.

@retAddr
A=M
0;JMP
