// Manually written asm code to see how if-goto works

// goto END_PROGRAM  

//  From page 186 Section 8.2.1 Program Flow Commands, you can get an idea on how the if-goto command should work

//  goto label: This command effects an unconditional goto operation. 

//      VM Code
//      goto END_PROGRAM  // unconditional goto


//      ASM Code


        // @SP
        // M=M-1   
        
        @END_PROGRAM
        0;JMP   //  goto label END_PROGRAM by force.
