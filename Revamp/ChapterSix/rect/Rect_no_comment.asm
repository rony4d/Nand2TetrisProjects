









   @0

   D=M

   @INFINITE_LOOP

   D;JLE 

   @counter

   M=D

   @SCREEN

   D=A

   @address

   M=D

(LOOP)

   @address

   A=M

   M=-1

   @address

   D=M

   @32

   D=D+A

   @address

   M=D

   @counter

   MD=M-1

   @LOOP

   D;JGT

(INFINITE_LOOP)

   @INFINITE_LOOP

   0;JMP

