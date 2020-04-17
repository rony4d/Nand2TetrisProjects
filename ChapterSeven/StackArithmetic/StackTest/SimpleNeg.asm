// This asm file was manually written by Ugo Aronu
// to test his knowledge before writing the VM translator

// NOTE Read slide 120 on the lecture clearly to see how to test the program 
// NOTE Slide 30 to 39 clearly shows the flow for arithmetic operations. It will help in coding it


// VM code below should be translated into hack assembly code

// Negates a constant value
// push constant 17
// neg


// Negation is simply -value and a command exists in our ALU instruction as -M or -D. We will use that


//Write your ASM below 

// Stack pointer initialization
@256
D=A

@SP
M=D

// push contant 456
@456
D=A

@SP
A=M
M=D

@SP
M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)

// neg
//To negate we move a step back and -M or -D i.e (- SP at RAM[256])
@SP
M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

@SP     // We are at RAM[0] with value 256
A=M     // We are at RAM[256]
M=-M    // negate M and assign value to M

@SP
M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    