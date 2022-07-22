//  This file enables me test out the proposed asm for nested function call and return VM commands with the full VM Command

//  nested function call and return VM command

//  The command below is what our nestedcall VM code should generate from the code generator

//  NOTE: The best way to test this large codebase is in chunks. I will add markers to show how I am testing the code. 

// // Sys.vm for NestedCall test.

// // Sys.init()
// //
// // Calls Sys.main() and stores return value in temp 1.
// // Does not return.  (Enters infinite loop.)

// function Sys.init 0
// push constant 4000	// test THIS and THAT context save
// pop pointer 0
// push constant 5000
// pop pointer 1
// call Sys.main 0      //  ---- Test code at this point : Write manual asm code and then run the VM code with VME.tst file up until this point and then compare memory values manually.    Test Done
// pop temp 1
// label LOOP
// goto LOOP

// // Sys.main()
// //
// // Sets locals 1, 2 and 3, leaving locals 0 and 4 unchanged to test
// // default local initialization to 0.  (RAM set to -1 by test setup.)
// // Calls Sys.add12(123) and stores return value (135) in temp 0.
// // Returns local 0 + local 1 + local 2 + local 3 + local 4 (456) to confirm
// // that locals were not mangled by function call.

// function Sys.main 5
// push constant 4001
// pop pointer 0
// push constant 5001
// pop pointer 1
// push constant 200
// pop local 1
// push constant 40
// pop local 2
// push constant 6
// pop local 3
// push constant 123
// call Sys.add12 1
// pop temp 0
// push local 0
// push local 1
// push local 2
// push local 3
// push local 4
// add
// add
// add
// add
// return

// // Sys.add12(int n)
// //
// // Returns n+12.

// function Sys.add12 0
// push constant 4002
// pop pointer 0
// push constant 5002
// pop pointer 1
// push argument 0
// push constant 12
// add
// return




//  NOTE:This is not a function call simce there is no 'call function_name n' code but the return will be handled like any normal function return. 

//  The test file has already handled caller state saving, so it is assumed that this function was called by another function. 


//  We are assuming this function has already been called so it should fall under Handling Function section ( Slide 119 on Lecture note )




//  ===================================================     Function Start       ========================================================================  
// function Sys.init 0

(Sys.init)

// push constant 4000	// test THIS and THAT context save
@4000
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// pop pointer 0
//  pop pointer 0 -> SP--; THIS = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THIS
M=D         //  THIS = *SP   

// push constant 5000

@5000
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


// pop pointer 1
//  pop pointer 1 -> SP--; THAT = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THAT
M=D         //  THIS = *SP  



//  ===================================================   Function Call Initialization    =======================================================================

// call Sys.main 0

//  Handling call -> call 'functionname nArgs'  (From Slide 100 on Lecture Note)


//  push retAddrLabel   //  Push the ROM address where execution will commence for this caller function. 

@Sys.init$retAddrLabel
D=A

@SP
A=M
M=D

@SP
M=M+1


//  push LCL                //  Saves LCL of the caller

@LCL
D=M

@SP
A=M
M=D

@SP
M=M+1


//  push ARG                //  Saves ARG of the caller
@ARG
D=M

@SP
A=M
M=D

@SP
M=M+1


//  push THIS               //  Saves THIS of the caller
@THIS
D=M

@SP
A=M
M=D

@SP
M=M+1

//  push THAT               //  Saves THAT of the caller
@THAT
D=M

@SP
A=M
M=D

@SP
M=M+1

//  ARG = SP - 5 - nArgs    //  Repositions ARG. This repositioning is important because we need to set ARG to the correct base address so the called function can access its arguments.

@0      //  nArgs is 0 for this function. NOTE: This value will be dynamically generated by the translator
D=A

@5
D=D+A

@SP
D=M-D   //  SP - 5 - nArgs = SP - (5 + nArgs)

@ARG
M=D


//  LCL = SP                //  Repositions LCL. Repositions LCL for the callee
@SP
D=M

@LCL
M=D

//  goto functionname       //  Transfers control to the called function

@Sys.main
0;JMP

//  (retAddrLabel)
(Sys.init$retAddrLabel)

//  return here and continue running the caller function's code

// pop temp 1

@1         //  i
D=A

@5    
D=D+A       //  Temp + i

@addr
M=D         //  addr = Temp + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP 

// label LOOP
(Sys.init$LOOP)

//  ==== Inifite Loop Zone  The man who knew infinity lives here :) :D :(  =====
// goto LOOP
@Sys.init$LOOP
0;JMP

//==================================================================    WE ARE ABOUT TO EXECUTE call Sys.main 0   ==============================================================

//  Start executing Sys.main from here. Sys.main is the called function

//=================== Function Initialization ( Initialize the 5 local variables ) =========================

// function Sys.main 5

(Sys.main)

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

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
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

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
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


//  pop local 2

@2          //  i
D=A

@LCL    
D=D+M       //  LCL + i

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
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


//  pop local 3

@3          //  i
D=A

@LCL    
D=D+M       //  LCL + i

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
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


//  pop local 4

@4          //  i
D=A

@LCL    
D=D+M       //  LCL + i

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP  

//  Increment SP since we are initializing the local variables

//  SP++
@SP
M=M+1

//  =======================  Implement functions execution code   =========================

// push constant 4001
// pop pointer 0
// push constant 5001
// pop pointer 1
// push constant 200
// pop local 1
// push constant 40
// pop local 2
// push constant 6
// pop local 3
// push constant 123
// call Sys.add12 1
@4001
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


// pop pointer 0
//  pop pointer 0 -> SP--; THIS = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THIS
M=D         //  THIS = *SP    

// push constant 5001
@5001
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// pop pointer 1
//  pop pointer 1 -> SP--; THAT = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THAT
M=D         //  THIS = *SP  


// push constant 200

@200
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// pop local 1


@1          //  i
D=A

@LCL    
D=D+M       //  LCL + i

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP  



// push constant 40

@40
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// pop local 2


@2          //  i
D=A

@LCL    
D=D+M       //  LCL + i

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP  



// push constant 6

@6
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// pop local 3
@3          //  i
D=A

@LCL    
D=D+M       //  LCL + i

@addr
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP 


// push constant 123

@123
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1



//  ===================================================   Function Call Initialization    =======================================================================

//  call Sys.add12 1
//  NOTE: nArgs here is 1. Also note that we pushed 123 before the function call so 123 is the Arg
//  Handling call -> call 'functionname nArgs'  (From Slide 100 on Lecture Note)


//  push retAddrLabel   //  Push the ROM address where execution will commence for this caller function. 


@Sys.main$retAddrLabel
D=A

@SP
A=M
M=D

@SP
M=M+1


//  push LCL                //  Saves LCL of the caller

@LCL
D=M

@SP
A=M
M=D

@SP
M=M+1


//  push ARG                //  Saves ARG of the caller
@ARG
D=M

@SP
A=M
M=D

@SP
M=M+1


//  push THIS               //  Saves THIS of the caller
@THIS
D=M

@SP
A=M
M=D

@SP
M=M+1

//  push THAT               //  Saves THAT of the caller
@THAT
D=M

@SP
A=M
M=D

@SP
M=M+1

//  ARG = SP - 5 - nArgs    //  Repositions ARG. This repositioning is important because we need to set ARG to the correct base address so the called function can access its arguments.

@1      //  nArgs is 1 for this function. NOTE: This value will be dynamically generated by the translator
D=A

@5
D=D+A

@SP
D=M-D   //  SP - 5 - nArgs = SP - (5 + nArgs)

@ARG
M=D


//  LCL = SP                //  Repositions LCL. Repositions LCL for the callee
@SP
D=M

@LCL
M=D

//  goto functionname       //  Transfers control to the called function

@Sys.add12
0;JMP


//  (retAddrLabel)

(Sys.main$retAddrLabel)


// pop temp 0

@0         //  i
D=A

@5    
D=D+A       //  Temp + i

@addr
M=D         //  addr = Temp + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr
A=M
M=D         //  *addr = *SP 

// push local 0

// push local i -> addr = LCL + i; *SP = *addr ; SP++

@0
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++



// push local 1
// push local i -> addr = LCL + i; *SP = *addr ; SP++

@1
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// push local 2
// push local i -> addr = LCL + i; *SP = *addr ; SP++

@2
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++


// push local 3
// push local i -> addr = LCL + i; *SP = *addr ; SP++

@3
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// push local 4
// push local i -> addr = LCL + i; *SP = *addr ; SP++

@4
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr
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



// return

//================================= Implement return of function Sys.main ( See from slide 126 on lecture note ) =================================


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

@Sys.init$retAddrLabel             //@retAddr  
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

@Sys.init$retAddrLabel              //@retAddr  
A=M
0;JMP






//==================================================================    WE ARE ABOUT TO EXECUTE call Sys.add12 1   ==============================================================

// In ' Sys.add12 1 ' function , '1' means 1 ARG is part of the function

//  Start executing Sys.add12 from here. Sys.add12 is the called function

//=================== Function Initialization ( Initialize the 0 local variables ) =========================

//  Since there are 0 local variables then there is nothing to initialize

// function Sys.add12 0

(Sys.add12)


//  =======================  Implement functions execution code   =========================

// push constant 4002

@4002
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// pop pointer 0
//  pop pointer 0 -> SP--; THIS = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THIS
M=D         //  THIS = *SP  

// push constant 5002

@5002
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1

// pop pointer 1
//  pop pointer 1 -> SP--; THAT = *SP


@SP
M=M-1       //  SP--


@SP
A=M
D=M         // *SP

@THAT
M=D         //  THIS = *SP  

// push argument 0 ( Problem de here: It is pushing the return address Sys.main$returnAddr instead of constant 123 that was the argument pushed before this function was called)

@0
D=A         //  i

@ARG
D=D+M       //  ARG + i


@addr
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// push constant 12
@12
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


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


// return

//================================= Implement return of function Sys.add12 ( See from slide 126 on lecture note ) =================================


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

@Sys.main$retAddrLabel             //@retAddr  
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

@Sys.main$retAddrLabel              //@retAddr  
A=M
0;JMP


//  Test all asm code before this comment before proceeding. Test the code by comparing the memory values


