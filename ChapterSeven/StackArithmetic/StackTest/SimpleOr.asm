// This asm file was manually written by Ugo Aronu
// to test his knowledge before writing the VM translator

// NOTE Read slide 120 on the lecture clearly to see how to test the program 
// NOTE Slide 30 to 39 clearly shows the flow for arithmetic operations. It will help in coding it


// VM code below should be translated into hack assembly code

// Pushes and bitwise-ORs two constants.
//push constant 7
//push constant 8
//and

//Write your ASM below 

// Stack pointer initialization
@256
D=A

@SP
M=D

// push contant 15
@15
D=A

@SP
A=M
M=D

@SP
M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)

// push constant 9
@9
D=A

@SP
A=M
M=D

@SP
M=M+1   //SP move ++

// or
//To OR we have to pop i.e (SP at RAM[256] | SP at RAM[257])
@SP
M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

@SP     // We are at RAM[0] with value 257
A=M
D=M     // Assign value to D-register

@SP     // We are at RAM[0] with value 257
M=M-1   // SP move-- we are at RAM[0] value 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
A=M
M=D|M   // OR happens here

@SP
M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257

