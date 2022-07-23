//  This file enables me test out the proposed asm for branching VM commands

//  label branching VM command

//  The command below is what our add VM code should generate from the code generator

// Computes the sum 1 + 2 + ... + argument[0] and pushes the
// result onto the stack. Argument[0] is initialized by the test
// script before this code starts running.
// push constant 0
// pop local 0         // initializes sum = 0
// label LOOP_START
// push argument 0
// push local 0
// add
// pop local 0	        // sum = sum + counter
// push argument 0
// push constant 1
// sub
// pop argument 0      // counter--
// push argument 0
// if-goto LOOP_START  // If counter > 0, goto LOOP_START
// push local 0


//  Initialize SP to 256

@256
D=A

@SP
M=D

// push constant 0

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

@addr_local_0
M=D         //  addr = LCL + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr_local_0
A=M
M=D         //  *addr = *SP

//label LOOP_START

(null$LOOP_START)

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

// pop local 0	        // sum = sum + counter

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



// push argument 0

@0
D=A         //  i

@ARG
D=D+M       //  ARG + i


@addr_push_arg_01
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// push constant 1

@1
D=A

//  *SP = i
@SP
A=M
M=D

//  SP++
@SP
M=M+1


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


// pop argument 0      // counter--

@0          //  i
D=A

@ARG
D=D+M       //  ARG + i

@addr_pop_arg_02
M=D         //  addr = ARG + i


@SP
M=M-1       //  SP--

@SP
A=M
D=M         // *SP

@addr_pop_arg_02
A=M
M=D         //  *addr = *SP


// push argument 0
@0
D=A         //  i

@ARG
D=D+M       //  ARG + i


@addr_push_arg_02
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++

// if-goto LOOP_START  // If counter > 0, goto LOOP_START
@SP
M=M-1
A=M
D=M
@null$LOOP_START
D;JNE


// push local 0

@0
D=A         //  i

@LCL
D=D+M       //  LCL + i

@addr_push_local_02
M=D

A=M
D=M         //  *addr


@SP
A=M
M=D         //  *SP = *addr

@SP
M=M+1       //  SP++
