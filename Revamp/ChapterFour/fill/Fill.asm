// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

//  1. Fill up the screen 


//  Initialize the screen and loop parameters
@SCREEN
D=A

@addr       //  Store screen base address in addr variable
M=D

@i          //  Initialize counter for outer loop for rows to zero
M=0

@j          //  Initialize counter for inner loop for columns to zero
M=0

@256
D=A
@rows
M=D

@32
D=A
@columns    
M=D        //  There are actually 512 columns but since we are setting 16 bits to 1, in one iteration, we will have 512/16 = 32

(LOOP_ROW)

    @i
    D=M

    @rows
    D=D-M

    @END
    D;JEQ
    
    @i                  
    M=M+1               //  Increase row counter by 1

    @j
    M=0                 //  reset column counter 

    (LOOP_COLUMN)

        @j
        D=M

        @columns
        D=D-M

        @LOOP_ROW
        D;JEQ


        @addr           //  
        A=M             //  Recall that addr points to a an address (i.e a pointer), so we have to go to the address pointed by the pointed and then change the value
        M=-1            //  Set all 16 bits in the current RAM chip addressed by A to 1. This is blacken the entire screen

        
        @j              
        M=M+1           //  Increase column counter by 1

        @addr
        M=M+1           //  Increase the address pointed by addr by one so it can point to the next RAM chip. 

        @LOOP_COLUMN
        0;JMP           //  Continue in this loop till we breakout


    @LOOP_ROW
    0;JMP



(END)
    @END
    0;JMP