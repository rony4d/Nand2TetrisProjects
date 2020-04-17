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



//To fill up the screen
//for(i=0; i < n; i++){
//  Turn the 16 bits * 32 words black on each row
//}

//  To detect keyboard input
//  We need to probe the RAM[24576] which is the keyboard address on the Hack RAM
//  If the value == 0, turn screen white else turn screen black


//Pseudo-code

//  n=8192                                  // n is the total size of screen memory = 8k = 8 * 1024 = 8192 
//  screenBaseAddress = SCREEN              // Screen base address and has a total of 8k registers(16-bits each) assigned to it  
//  keyboardAddress =   KBD                 // keyboard has only one register(16-bits)
//  i=0


//  (INFINTELOOP)
//      if RAM[keyboardAddress] == 0, goto OFFLOOP
//      goto ONLOOP    


//  (ONLOOP)
//      if n - i == 0, goto INFINITELOOP
//      RAM[screenBaseAddress] = -1                     // Turns all bits in word to black(1)
//      screenBaseAddress = screenBaseAddress + 1       // Go to the next word
//      i = i + 1
//      goto ONLOOP  

//  (OFFLOOP)
//      if n - i == 0, goto INFINITELOOP
//      RAM[screenBaseAddress] = 0                      // Turns all bits in word to white(0)
//      screenBaseAddress = screenBaseAddress + 1       // Go to the next word
//      i = i + 1
//      goto OFFLOOP 







(INFINITELOOP)
        @8192
        D=A
        @n
        M=D
        
        @SCREEN
        D=A
        @screenBaseAddress
        M=D

        @KBD
        D=A
        @keyboardAddress
        M=D

        @i
        M=0                                 //reset the counter i to zero
        @keyboardAddress
        A=M
        D=M
        @OFFLOOP
        D;JEQ                               //if RAM[keyboardAddress] == 0, goto OFFLOOP
        @ONLOOP
        0;JMP                               //else goto ONLOOP


(ONLOOP)
        @i
        D=M
        @n
        D=M-D
        @INFINITELOOP
        D;JEQ                               // if n - i == 0, goto INFINITELOOP

        @screenBaseAddress
        A=M
        M=-1                                //RAM[screenBaseAddress] = -1       //1111111111111111

        @screenBaseAddress
        M=M+1                               //screenBaseAddress = screenBaseAddress + 1

        @i
        M=M+1
        @ONLOOP
        0;JMP

(OFFLOOP)
        @i
        D=M
        @n
        D=M-D
        @INFINITELOOP
        D;JEQ                               // if n - i == 0, goto INFINITELOOP

        @screenBaseAddress
        A=M
        M=0                                //RAM[screenBaseAddress] = 0       //0000000000000000

        @screenBaseAddress
        M=M+1                               //screenBaseAddress = screenBaseAddress + 1

        @i
        M=M+1
        @OFFLOOP
        0;JMP