//Draw a rectangle of height R0
//for(i=0; i < n; i++){
//  Turn the first 16 bits black on each row
//}

//Pseudo-code

//  addressBase = SCREEN    base memory address of screen (To be used for pointer manipulation)
//  i=0                     row counter
//  n = R0                  height of the rectangle

//  (LOOP)
//      if n - i == 0, goto STOP
//      RAM[addressBase] = -1               // 1111111111111111, this affects only the first word(word 0)
//      addressBase = addressBase + 32      // Jump to the next row
//      i = i + 1
//      goto LOOP

//  (END)
//      goto END


@SCREEN
D=A
@addressBase
M=D

@i
M=0

@R0
D=M
@n
M=D

(LOOP)
    @i
    D=M
    @n
    D=M-D
    @END
    D;JEQ           //if n - i == 0 END

    @addressBase
    A=M
    M=-1            //RAM[addressBase] = -1

    @32
    D=A
    @addressBase
    M=M+D           //addressBase = addressBase + 32

    @i
    M=M+1

    @LOOP
    0;JMP

(END)
    @END
    0;JMP    