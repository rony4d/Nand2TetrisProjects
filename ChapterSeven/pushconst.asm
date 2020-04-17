// Convert VM Code to ASM

// NOTE THE ASSUMPTIONS (Please follow Chapter 7 Lecture Note Slide 59):
// SP stored in RAM[0]
// Stack base addr = 256

// Push constant 17

// Logic
// *SP = 17
// SP++

// Assembly code below
@17
D=A

@SP     // Stack Pointer base address value is 256 i.e value at RAM[0]. We add 256 in the CPUEmulator RAM[0]
A=M
M=D     // *SP = 17

@SP
M=M+1   // SP++

