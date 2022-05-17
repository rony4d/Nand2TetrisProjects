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

// *  2. Probe Keyboard RAM section * //
@KBD
D=A

@keyboard
M=D                     //  Store keyboard base address in a variable 

// *  Create an infinte loop to probe keyboard* //

(KEYBOARD_LOOP)

    //  Initialize the screen and loop parameters
    @SCREEN
    D=A

    @addr       //  Store screen base address in addr variable
    M=D

    @i          //  Reset row counter 
    M=0

    @256
    D=A
    @rows
    M=D

    @32
    D=A
    @columns    
    M=D    

    @keyboard
    A=M                 //  Go to the RAM address pointed by pointer
    D=M                 //  Now we have collected the value at the address pointed by the pointer. We can now use this value to know when a key is typed

    @LOOP_ROW_BLACK
    D;JGT               //  If value read from RAM[24576] is greater than zero then go to set the pixel colour as black 


    @LOOP_ROW_WHITE
    D;JEQ               //  If value read from RAM[24576] is equal to zero then go to set the pixel colour as white 

    @KEYBOARD_LOOP
    0;JMP



(LOOP_ROW_BLACK)

    @i
    D=M

    @rows
    D=D-M

    @KEYBOARD_LOOP
    D;JEQ
    
    @i                  
    M=M+1               //  Increase row counter by 1

    @j
    M=0                 //  reset column counter 


    (LOOP_COLUMN_BLACK)

        @j
        D=M

        @columns
        D=D-M

        @LOOP_ROW_BLACK
        D;JEQ


        @addr           //  
        A=M             //  Recall that addr points to a an address (i.e a pointer), so we have to go to the address pointed by the pointer and then change the value
        M=-1             //  Set all 16 bits in the current RAM chip addressed by A to value in setpixel variable. -1 for black and 0 for white

        
        @j              
        M=M+1           //  Increase column counter by 1

        @addr
        M=M+1           //  Increase the address pointed by addr by one so it can point to the next RAM chip. 

        @LOOP_COLUMN_BLACK
        0;JMP           //  Continue in this loop till we breakout


    @LOOP_ROW_BLACK
    0;JMP

(LOOP_ROW_WHITE)

    @i
    D=M

    @rows
    D=D-M

    @KEYBOARD_LOOP
    D;JEQ
    
    @i                  
    M=M+1               //  Increase row counter by 1

    @j
    M=0                 //  reset column counter 


    (LOOP_COLUMN_WHITE)

        @j
        D=M

        @columns
        D=D-M

        @LOOP_ROW_WHITE
        D;JEQ

        @addr           //  
        A=M             //  Recall that addr points to a an address (i.e a pointer), so we have to go to the address pointed by the pointer and then change the value
        M=0             //  Set all 16 bits in the current RAM chip addressed by A to value in setpixel variable. -1 for black and 0 for white

        
        @j              
        M=M+1           //  Increase column counter by 1

        @addr
        M=M+1           //  Increase the address pointed by addr by one so it can point to the next RAM chip. 

        @LOOP_COLUMN_WHITE
        0;JMP           //  Continue in this loop till we breakout



    @LOOP_ROW_WHITE
    0;JMP






