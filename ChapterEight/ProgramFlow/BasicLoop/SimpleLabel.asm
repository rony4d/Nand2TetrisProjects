// Manually written asm code to see how label works

//  label LOOP_START
(LOOP_START)



//  The code blow is just me trying to wrap my head around how we can move from VM to High level, to better under-
//  stand how to handle if-goto LOOP_START

// push constant 0    
// pop local 0         // initializes sum = 0
// label LOOP_START
// push argument 0    
// push local 0
// add
// pop local 0	        // sum = sum + counter
// push argument 0
// push constant 1
// sub
// pop argument 0      // counter--
// push argument 0
// if-goto LOOP_START  // If counter > 0, goto LOOP_START
// push local 0

//  Intepret to high level language
//  push constant 0 -> 0;
//  pop local 0 -> sum = 0;

//  label LOOP_START -> while(...)
//  push argument 0 -> while(...){ counter }
//  push local 0 -> while(...){ sum }
//  add -> while(...){ counter + sum }
//  pop local 0 -> while(...){ sum = counter + sum }
//  push argument 0 -> while(...){ counter }
//  push constant 1 -> while(...){ 1 }
//  sub -> while(...){ counter - 1 }
//  pop argument 0 -> while(...){ counter = counter - 1}
//  push argument 0 -> while(...){ counter }
//  if-goto LOOP_START [ this means, if true and true is a number greater than zero. 
//  I still need to prove this] -> while( counter > 0 ) { ... }

//  push local 0 -> while(...){ sum }

//  Final high level language should look like this

int sum = 0;
int counter = 5;    // this is an arbitrary number chosen
while(counter != 0){
    sum = sum + counter;

    counter = counter - 1;

}