// Manually written asm code to see how if-goto works

// if-goto LOOP_START  

//  From page 186 Section 8.2.1 Program Flow Commands, you can get an idea on how the if-goto command should work

//  if-goto label: This command effects a conditional goto operation. 
//  The stack’s topmost value is popped; if the value is not zero, execution continues 
//  from the location marked by the label; otherwise, execution continues from the next command in the program. The jump destination must be located in the same function.

//  Also looking at Slide 12 in Chapter 8 Lecture note:
//  For if-goto label
//  VM-Logic
//  1.  condition = pop() -> Pop stacks's topmost value. This simply means taking the SP back one level i.e M=M-1
//  2.  if condition, jump to execute command just after the label-> this means if value is not zero
//      hence we have something like this below: eg if-goto LOOP_START to asm:

//      VM Code
//      push argument 0
//      if-goto LOOP_START  // If counter > 0, goto LOOP_START

//      Pseudo Code Breakdown
//      Pop argument 0
//      check get the result then check if the result is equal to 0, if not, go back to Label

//      ASM Code

        //  pop the stacks topmost value. Use
        //  NOTE: before we execute an if-goto, we must first push the value we want to use to check
        //  the condition for example, before the if-goto asm code below, we need to have something like
        
        //  push argument 0 
        //  and in pushing argument 0, we will store the value in D-register and then use
        //  the D-register as destination in our conditional goto statement. 
        //  NOTE: This stuff took me about 24 hours to figure out. How you can confirm this is by
        //  running tests with  the VMEmulator for BasicLoop.vm file . Observe the Local, Argument memory
        //  segments as well as Global stack and RAM. It will give you very good insights. 
        
        //  NOTE: Please do not use the BasicLoop.tst script in testing in the CPU Emulator because it injects code. Don't know why

        @SP
        M=M-1   
        
        @LOOP_START
        D;JNE   //  go to LOOP_START if M is not equal to zero. D-register contains the condtional value which has been
                //  pushed before the if-goto Label statement. 
