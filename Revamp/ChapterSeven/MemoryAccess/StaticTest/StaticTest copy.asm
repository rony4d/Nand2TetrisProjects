//  This file contains wrong code. I derived a wrong formula that passed the test but failed in the last project in chapter 8. I had to trace it to this place. 

//  See the StaticTest.asm file for the correct implementation. Also I had to update my VM Translator code base

//  push constant 111
@111
D=A
@SP
A=M
M=D
@SP
M=M+1

//  push constant 333
@333
D=A
@SP
A=M
M=D
@SP
M=M+1

//  push constant 888
@888
D=A
@SP
A=M
M=D
@SP
M=M+1

//  pop static 8
@8
D=A
@16
D=D+A
@StaticTest.8
M=D
@SP
M=M-1
@SP
A=M
D=M
@StaticTest.8
A=M
M=D


//  pop static 3
@3
D=A
@16
D=D+A
@StaticTest.3
M=D
@SP
M=M-1
@SP
A=M
D=M
@StaticTest.3
A=M
M=D


//  pop static 1
@1
D=A
@16
D=D+A
@StaticTest.1
M=D
@SP
M=M-1
@SP
A=M
D=M
@StaticTest.1
A=M
M=D

//  push static 3
@3
D=A
@16
D=D+A
@StaticTest.3
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1

//  push static 1
@1
D=A
@16
D=D+A
@StaticTest.1
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1

//  sub
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=M-D
@SP
A=M
M=D
@SP
M=M+1

//  push static 8
@8
D=A
@16
D=D+A
@StaticTest.8
A=D
D=M
@SP
A=M
M=D
@SP
M=M+1

//  add
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
