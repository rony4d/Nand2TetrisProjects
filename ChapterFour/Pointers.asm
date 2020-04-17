//  for(i=0; i < n; i++){
//  array[i] = -1;
//  }

//Declare the value of the variables

@100                //value of the array, i.e the number of elements the array will hold
D=A
@array
M=D

@10                 //value of the number of iterations we want to perform
D=A
@n
M=D

@i                  //i starts from 0
M=0

(LOOP)
    //if i==n stop i.e, if n-i == 0 stop
    @i
    D=M
    @n
    D=M-D           //keep removing i from n till the result becomes 0
    @END
    D;JEQ           //stop if the result is equal to 0

    //RAM [arr + i] = -1
    @array          
    D=M
    @i
    A=D+M
    M=-1

    //i++
    @i
    M=M+1   

    @LOOP
    0;JMP


(END)
    @END
    0;JMP
    

