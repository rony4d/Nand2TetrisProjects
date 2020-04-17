// This asm file was manually written by Ugo Aronu
// to test his knowledge before writing the VM translator

// NOTE Read slide 120 on the lecture clearly to see how to test the program 
// NOTE Slide 30 to 39 clearly shows the flow for arithmetic operations. It will help in coding it


// VM code below should be translated into hack assembly code

// Pushes and adds two constants.
//push constant 7
//push constant 8
//add

//  Compare code is below
//|  RAM[0]  | RAM[256] |
//|     257  |      15  |

//Write your ASM below 

// Stack pointer initialization
@256
D=A

@SP
M=D

// push contant 7
@7
D=A

@SP
A=M
M=D

@SP
M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)

// push constant 8
@8
D=A

@SP
A=M
M=D

@SP
M=M+1   //SP move ++

// add
//To Add we have to pop i.e (SP at RAM[256] + SP at RAM[257])
@SP
M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

@SP     // We are at RAM[0] with value 257
A=M
D=M     // Assign value to D-register

@SP     // We are at RAM[0] with value 257
M=M-1   // SP move-- (Stack pointer moves one space backward the second time) We decrease RAM[0] value by 1 to give us 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
A=M
M=M+D

@SP
M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257

