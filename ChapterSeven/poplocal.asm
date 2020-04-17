// Implementing pop local i
// addr=LCL+ i, SP--, *addr=*SP

// NOTE THE ASSUMPTIONS (Please follow Chapter 7 Lecture Note Slide 65):
// SP stored in RAM[0]
// Stack base addr = 258
// LCL base addr = 1015

// Implementation
// addr=LCL + i, SP--
// *addr=*SP

// Write the hack assembly below

@i
D=M

@LCL
D=M+D   //LCL + i

@addr
M=D

@SP
M=M-1   //SP--
A=M
D=M

@addr
A=M
M=D     //*addr=*SP




