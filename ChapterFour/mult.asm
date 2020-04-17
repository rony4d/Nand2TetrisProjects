// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

//  Multiplication is continuos addition in a loop

//  for(i=0;i<n;i++){
//  add R0 R1 times to R0
//}


//Pseudocode

//  R0 = 6
//  R1 = 7
//  i = 0           counter
//  n = R1          store R1 in n

//  (LOOP)
//      if n - i == 0 goto END
//      i = i + 1
//      R0 = R0 
//      R2 = R2 + R0

//  (END)

@i
M=0

@R1
D=M
@n
M=D


(LOOP)
    @i
    D=M
    @n
    D=M-D
    @END
    D;JEQ               //goto END if n - i ==0 

    @i
    M=M+1               //i = i + 1

    @R0
    D=M
    @R2
    M=M+D
    @LOOP
    0;JMP

(END)
    @END
    0;JMP
