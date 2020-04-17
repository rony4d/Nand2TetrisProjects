// Program: Signum.asm
// Computes: if R0 > 0
//              R1 = 1
//           else
//              R1=0

//   @R0       
//   D=M

//   @8
//   D;JGT     // If R0 is greater than 0, goto line 8

//   @R1
//   M=0       //  RAM[1]=0

//   @10
//   0;JMP

//   @R1
//   M=1       //  RAM[1]=1

//   @10
//   0;JMP

  //APPLYING LABELS

  @R0       
  D=M

  @POSITIVE
  D;JGT     // If R0 is greater than 0, goto line 8

  @R1
  M=0       //  RAM[1]=0

  @END
  0;JMP

(POSITIVE)
  @R1
  M=1       //  RAM[1]=1

(END)
  @10
  0;JMP

  