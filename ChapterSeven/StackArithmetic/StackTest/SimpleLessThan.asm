// This asm file was manually written by Ugo Aronu
// to test his knowledge before writing the VM translator

// NOTE Read slide 120 on the lecture clearly to see how to test the program 
// NOTE Slide 30 to 39 clearly shows the flow for arithmetic operations. It will help in coding it


// VM code below should be translated into hack assembly code

// Pushes and checks one of two constants is less than the other.
// push constant 891
// push constant 892
// lt



//Write your ASM below 

// Stack pointer initialization
@256
D=A

@SP
M=D

// push contant 891
@891
D=A

@SP
A=M
M=D

@SP
M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)

// push constant 892
@892
D=A

@SP
A=M
M=D

@SP
M=M+1   //SP move ++

// less than
//To check if less we have to pop i.e (SP at RAM[256] - SP at RAM[257] < 0)
@SP
M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

@SP     // We are at RAM[0] with value 257
A=M     // We are at RAM[257]
D=M     // Assign value to D-register

@SP     // We are at RAM[0] with value 257
M=M-1   // SP move-- 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
A=M     // We are at RAM[256]
M=M-D   // RAM[256] - RAM[257]  
D=M     // Assign result to D-register so we can check less than to zero 

@LESSTHAN
D;JLT

@NOTLESSTHAN
0;JMP

(LESSTHAN) // If RAM[256] < RAM[257] then run the code below which sets SP or RAM[256] to true or -1
    @SP
    A=M
    M=-1
    @END
    0;JMP
    
(NOTLESSTHAN) // If RAM[256] is not less than RAM[257] then run the code below which sets SP or RAM[256] to false or 0
    @SP
    A=M
    M=0
    @END
    0;JMP

(END)
    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    