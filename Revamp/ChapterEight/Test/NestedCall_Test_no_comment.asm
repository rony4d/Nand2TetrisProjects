













































































































(Sys.init)




@4000

D=A




@SP

A=M

M=D




@SP

M=M+1









@SP

M=M-1       




@SP

A=M

D=M         


@THIS

M=D         





@5000

D=A




@SP

A=M

M=D




@SP

M=M+1











@SP

M=M-1       




@SP

A=M

D=M         


@THAT

M=D         




















@Sys.init$retAddrLabel

D=A



@SP

A=M

M=D



@SP

M=M+1








@LCL

D=M



@SP

A=M

M=D



@SP

M=M+1






@ARG

D=M



@SP

A=M

M=D



@SP

M=M+1






@THIS

D=M



@SP

A=M

M=D



@SP

M=M+1




@THAT

D=M



@SP

A=M

M=D



@SP

M=M+1






@0      
D=A



@5

D=D+A



@SP

D=M-D   


@ARG

M=D






@SP

D=M



@LCL

M=D






@Sys.main

0;JMP




(Sys.init$retAddrLabel)









@1         
D=A



@5

D=D+A       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         



(Sys.init$LOOP)





@Sys.init$LOOP

0;JMP















(Sys.main)






@0

D=A




@SP

A=M

M=D




@SP

M=M+1






@0          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         






@SP

M=M+1




@0

D=A




@SP

A=M

M=D




@SP

M=M+1










@1          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         






@SP

M=M+1






@0

D=A




@SP

A=M

M=D




@SP

M=M+1








@2          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         






@SP

M=M+1






@0

D=A




@SP

A=M

M=D




@SP

M=M+1








@3          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         






@SP

M=M+1






@0

D=A




@SP

A=M

M=D




@SP

M=M+1








@4          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         






@SP

M=M+1


















@4001

D=A




@SP

A=M

M=D




@SP

M=M+1











@SP

M=M-1       




@SP

A=M

D=M         


@THIS

M=D         



@5001

D=A




@SP

A=M

M=D




@SP

M=M+1









@SP

M=M-1       




@SP

A=M

D=M         


@THAT

M=D         







@200

D=A




@SP

A=M

M=D




@SP

M=M+1








@1          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         









@40

D=A




@SP

A=M

M=D




@SP

M=M+1








@2          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         









@6

D=A




@SP

A=M

M=D




@SP

M=M+1




@3          
D=A



@LCL

D=D+M       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         







@123

D=A




@SP

A=M

M=D




@SP

M=M+1






















@Sys.main$retAddrLabel

D=A



@SP

A=M

M=D



@SP

M=M+1








@LCL

D=M



@SP

A=M

M=D



@SP

M=M+1






@ARG

D=M



@SP

A=M

M=D



@SP

M=M+1






@THIS

D=M



@SP

A=M

M=D



@SP

M=M+1




@THAT

D=M



@SP

A=M

M=D



@SP

M=M+1






@1      
D=A



@5

D=D+A



@SP

D=M-D   


@ARG

M=D






@SP

D=M



@LCL

M=D






@Sys.add12

0;JMP








(Sys.main$retAddrLabel)








@0         
D=A



@5

D=D+A       


@addr

M=D         




@SP

M=M-1       


@SP

A=M

D=M         


@addr

A=M

M=D         








@0

D=A         


@LCL

D=D+M       


@addr

M=D



A=M

D=M         




@SP

A=M

M=D         


@SP

M=M+1       










@1

D=A         


@LCL

D=D+M       


@addr

M=D



A=M

D=M         




@SP

A=M

M=D         


@SP

M=M+1       






@2

D=A         


@LCL

D=D+M       


@addr

M=D



A=M

D=M         




@SP

A=M

M=D         


@SP

M=M+1       








@3

D=A         


@LCL

D=D+M       


@addr

M=D



A=M

D=M         




@SP

A=M

M=D         


@SP

M=M+1       






@4

D=A         


@LCL

D=D+M       


@addr

M=D



A=M

D=M         




@SP

A=M

M=D         


@SP

M=M+1       





@SP

M=M-1

A=M

D=M

@SP

M=M-1

A=M

D=D+M

@SP

A=M

M=D

@SP

M=M+1




@SP

M=M-1

A=M

D=M

@SP

M=M-1

A=M

D=D+M

@SP

A=M

M=D

@SP

M=M+1




@SP

M=M-1

A=M

D=M

@SP

M=M-1

A=M

D=D+M

@SP

A=M

M=D

@SP

M=M+1




@SP

M=M-1

A=M

D=M

@SP

M=M-1

A=M

D=D+M

@SP

A=M

M=D

@SP

M=M+1
























                                



@LCL

D=M



@endFrame

M=D




@5

D=A

@endFrame

D=M-D

A=D

D=M



@Sys.init$retAddrLabel             
M=D




@SP

M=M-1

A=M

D=M



@ARG

A=M

M=D






@1

D=A



@ARG

D=M+D



@SP

M=D




@1

D=A

@endFrame

D=M-D

A=D

D=M



@THAT

M=D




@2

D=A

@endFrame

D=M-D

A=D

D=M



@THIS

M=D




@3

D=A

@endFrame

D=M-D

A=D

D=M



@ARG

M=D




@4

D=A

@endFrame

D=M-D

A=D

D=M



@LCL

M=D








@Sys.init$retAddrLabel              
A=M

0;JMP































(Sys.add12)











@4002

D=A




@SP

A=M

M=D




@SP

M=M+1









@SP

M=M-1       




@SP

A=M

D=M         


@THIS

M=D         





@5002

D=A




@SP

A=M

M=D




@SP

M=M+1









@SP

M=M-1       




@SP

A=M

D=M         


@THAT

M=D         





@0

D=A         


@ARG

D=D+M       




@addr

M=D



A=M

D=M         




@SP

A=M

M=D         


@SP

M=M+1       



@12

D=A




@SP

A=M

M=D




@SP

M=M+1






@SP

M=M-1

A=M

D=M

@SP

M=M-1

A=M

D=D+M

@SP

A=M

M=D

@SP

M=M+1






















                                





@LCL

D=M



@endFrame

M=D




@5

D=A

@endFrame

D=M-D

A=D

D=M



@Sys.main$retAddrLabel             
M=D




@SP

M=M-1

A=M

D=M



@ARG

A=M

M=D






@1

D=A



@ARG

D=M+D



@SP

M=D




@1

D=A

@endFrame

D=M-D

A=D

D=M



@THAT

M=D




@2

D=A

@endFrame

D=M-D

A=D

D=M



@THIS

M=D




@3

D=A

@endFrame

D=M-D

A=D

D=M



@ARG

M=D




@4

D=A

@endFrame

D=M-D

A=D

D=M



@LCL

M=D








@Sys.main$retAddrLabel              
A=M

0;JMP






