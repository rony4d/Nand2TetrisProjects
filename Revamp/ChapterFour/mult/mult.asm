// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.

//  Multiplication is continuous addition

//  if R0 = 0 or R1 = 0 then R2 = 0

//  if R0 = 0 return 0 as value of R2
// @R0
// D=M

// @R1
// D=M

@R2
M=0

@R0                     
D=M 
@ZERO                   
D;JEQ

@R1
D=M
@ZERO               
D;JEQ

(LOOP)
     
    @R0
    D=0
    D=D+M


    @R2
    M=D+M

    @R1
    M=M-1
    D=M
    @END
    D;JEQ

    @LOOP
    0;JMP



(ZERO)
    @R2
    M=0
    @END
    0;JMP

(END)
    @END
    0;JMP







