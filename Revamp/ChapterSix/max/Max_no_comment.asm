








   @R0

   D=M              
   @R1

   D=D-M            
   @OUTPUT_FIRST

   D;JGT            
   @R1

   D=M              
   @OUTPUT_D

   0;JMP            
(OUTPUT_FIRST)

   @R0             

   D=M              
(OUTPUT_D)

   @R2

   M=D              
(INFINITE_LOOP)

   @INFINITE_LOOP

   0;JMP            
