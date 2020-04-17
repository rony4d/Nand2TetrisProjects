//Psudo-code
// Computes RAM[1] =  1+2+3+...+n

// n = R0
// sum = 0
// i = 1

// if i > n goto STOP, that is i - n > 0
// sum = sum + i
// i = i + 1
// goto LOOP

// STOP:
//  R1= sum

@R0
D=M
@n
M=D

@sum
M=0

@i
M=1

(LOOP)

    @i
    D=M
    @n
    D=D-M
    @STOP
    D;JGT       //if i > n goto STOP



    @sum
    D=M
    @i
    D=D+M
    @sum
    M=D         // sum = sum + i

    @i
    D=M
    M=D+1       // i = i + 1
    @LOOP
    0;JMP

(STOP)
    @sum
    D=M
    @R1
    M=D

(END)
    @END
    0;JMP