











@256

D=A

@SP

M=D

@133

0;JMP

@R15

M=D

@SP

AM=M-1

D=M

A=A-1

D=M-D

M=0

@END_EQ

D;JNE

@SP

A=M-1

M=-1

(END_EQ)

@R15

A=M

0;JMP

@R15

M=D

@SP

AM=M-1

D=M

A=A-1

D=M-D

M=0

@END_GT

D;JLE

@SP

A=M-1

M=-1

(END_GT)

@R15

A=M

0;JMP

@R15

M=D

@SP

AM=M-1

D=M

A=A-1

D=M-D

M=0

@END_LT

D;JGE

@SP

A=M-1

M=-1

(END_LT)

@R15

A=M

0;JMP

@5

D=A

@LCL

A=M-D

D=M

@R13

M=D

@SP

AM=M-1

D=M

@ARG

A=M

M=D

D=A

@SP

M=D+1

@LCL

D=M

@R14

AM=D-1

D=M

@THAT

M=D

@R14

AM=M-1

D=M

@THIS

M=D

@R14

AM=M-1

D=M

@ARG

M=D

@R14

AM=M-1

D=M

@LCL

M=D

@R13

A=M

0;JMP

@SP

A=M

M=D

@LCL

D=M

@SP

AM=M+1

M=D

@ARG

D=M

@SP

AM=M+1

M=D

@THIS

D=M

@SP

AM=M+1

M=D

@THAT

D=M

@SP

AM=M+1

M=D

@4

D=A

@R13

D=D+M

@SP

D=M-D

@ARG

M=D

@SP

MD=M+1

@LCL

M=D

@R14

A=M

0;JMP

@0

D=A

@R13

M=D

@sys.init

D=A

@R14

M=D

@RET_ADDRESS_CALL0

D=A

@95

0;JMP

(RET_ADDRESS_CALL0)

(ball.new)

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.alloc

D=A

@R14

M=D

@RET_ADDRESS_CALL1

D=A

@95

0;JMP

(RET_ADDRESS_CALL1)

@SP

AM=M-1

D=M

@THIS

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@10

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@THIS

D=M

@11

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@12

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@THIS

D=M

@13

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@THIS

D=M

@14

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.show

D=A

@R14

M=D

@RET_ADDRESS_CALL2

D=A

@95

0;JMP

(RET_ADDRESS_CALL2)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(ball.dispose)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.dealloc

D=A

@R14

M=D

@RET_ADDRESS_CALL3

D=A

@95

0;JMP

(RET_ADDRESS_CALL3)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ball.show)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL4

D=A

@95

0;JMP

(RET_ADDRESS_CALL4)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.draw

D=A

@R14

M=D

@RET_ADDRESS_CALL5

D=A

@95

0;JMP

(RET_ADDRESS_CALL5)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ball.hide)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@SP

M=M+1

A=M-1

M=0

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL6

D=A

@95

0;JMP

(RET_ADDRESS_CALL6)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.draw

D=A

@R14

M=D

@RET_ADDRESS_CALL7

D=A

@95

0;JMP

(RET_ADDRESS_CALL7)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ball.draw)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@R13

M=D

@screen.drawrectangle

D=A

@R14

M=D

@RET_ADDRESS_CALL8

D=A

@95

0;JMP

(RET_ADDRESS_CALL8)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ball.getleft)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(ball.getright)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@54

0;JMP

(ball.setdestination)

@3

D=A

(LOOP_ball.setdestination)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_ball.setdestination

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL9

D=A

@95

0;JMP

(RET_ADDRESS_CALL9)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL10

D=A

@95

0;JMP

(RET_ADDRESS_CALL10)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT0

D=A

@38

0;JMP

(RET_ADDRESS_LT0)

@THIS

D=M

@7

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ball.setdestination$if_true0

D;JNE

@ball.setdestination$if_false0

0;JMP

(ball.setdestination$if_true0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT1

D=A

@38

0;JMP

(RET_ADDRESS_LT1)

@THIS

D=M

@8

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT2

D=A

@38

0;JMP

(RET_ADDRESS_LT2)

@THIS

D=M

@9

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ball.setdestination$if_end0

0;JMP

(ball.setdestination$if_false0)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT3

D=A

@38

0;JMP

(RET_ADDRESS_LT3)

@THIS

D=M

@8

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT4

D=A

@38

0;JMP

(RET_ADDRESS_LT4)

@THIS

D=M

@9

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

(ball.setdestination$if_end0)

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL11

D=A

@95

0;JMP

(RET_ADDRESS_CALL11)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL12

D=A

@95

0;JMP

(RET_ADDRESS_CALL12)

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL13

D=A

@95

0;JMP

(RET_ADDRESS_CALL13)

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ball.move)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.hide

D=A

@R14

M=D

@RET_ADDRESS_CALL14

D=A

@95

0;JMP

(RET_ADDRESS_CALL14)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT5

D=A

@38

0;JMP

(RET_ADDRESS_LT5)

@SP

AM=M-1

D=M

@ball.move$if_true0

D;JNE

@ball.move$if_false0

0;JMP

(ball.move$if_true0)

@THIS

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ball.move$if_end0

0;JMP

(ball.move$if_false0)

@THIS

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@THIS

D=M

@9

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ball.move$if_true1

D;JNE

@ball.move$if_false1

0;JMP

(ball.move$if_true1)

@THIS

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ball.move$if_true2

D;JNE

@ball.move$if_false2

0;JMP

(ball.move$if_true2)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@ball.move$if_end2

0;JMP

(ball.move$if_false2)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

(ball.move$if_end2)

@ball.move$if_end1

0;JMP

(ball.move$if_false1)

@THIS

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ball.move$if_true3

D;JNE

@ball.move$if_false3

0;JMP

(ball.move$if_true3)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@ball.move$if_end3

0;JMP

(ball.move$if_false3)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

(ball.move$if_end3)

(ball.move$if_end1)

(ball.move$if_end0)

@THIS

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ball.move$if_true4

D;JNE

@ball.move$if_false4

0;JMP

(ball.move$if_true4)

@THIS

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ball.move$if_true5

D;JNE

@ball.move$if_false5

0;JMP

(ball.move$if_true5)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

@ball.move$if_end5

0;JMP

(ball.move$if_false5)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M

M=D

(ball.move$if_end5)

@ball.move$if_end4

0;JMP

(ball.move$if_false4)

@THIS

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ball.move$if_true6

D;JNE

@ball.move$if_false6

0;JMP

(ball.move$if_true6)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

@ball.move$if_end6

0;JMP

(ball.move$if_false6)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

(ball.move$if_end6)

(ball.move$if_end4)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@10

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT0

D=A

@22

0;JMP

(RET_ADDRESS_GT0)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ball.move$if_true7

D;JNE

@ball.move$if_false7

0;JMP

(ball.move$if_true7)

@SP

M=M+1

A=M-1

M=1

@THIS

D=M

@14

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

D=M

@10

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

(ball.move$if_false7)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@11

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT6

D=A

@38

0;JMP

(RET_ADDRESS_LT6)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ball.move$if_true8

D;JNE

@ball.move$if_false8

0;JMP

(ball.move$if_true8)

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@14

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

D=M

@11

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

(ball.move$if_false8)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@12

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT1

D=A

@22

0;JMP

(RET_ADDRESS_GT1)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ball.move$if_true9

D;JNE

@ball.move$if_false9

0;JMP

(ball.move$if_true9)

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@14

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

D=M

@12

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

(ball.move$if_false9)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@13

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT7

D=A

@38

0;JMP

(RET_ADDRESS_LT7)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ball.move$if_true10

D;JNE

@ball.move$if_false10

0;JMP

(ball.move$if_true10)

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@14

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@THIS

D=M

@13

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

(ball.move$if_false10)

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.show

D=A

@R14

M=D

@RET_ADDRESS_CALL15

D=A

@95

0;JMP

(RET_ADDRESS_CALL15)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@14

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(ball.bounce)

@5

D=A

(LOOP_ball.bounce)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_ball.bounce

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL16

D=A

@95

0;JMP

(RET_ADDRESS_CALL16)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL17

D=A

@95

0;JMP

(RET_ADDRESS_CALL17)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ0

D=A

@6

0;JMP

(RET_ADDRESS_EQ0)

@SP

AM=M-1

D=M

@ball.bounce$if_true0

D;JNE

@ball.bounce$if_false0

0;JMP

(ball.bounce$if_true0)

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ball.bounce$if_end0

0;JMP

(ball.bounce$if_false0)

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT8

D=A

@38

0;JMP

(RET_ADDRESS_LT8)

@SP

A=M-1

M=!M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@RET_ADDRESS_EQ1

D=A

@6

0;JMP

(RET_ADDRESS_EQ1)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT9

D=A

@38

0;JMP

(RET_ADDRESS_LT9)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@RET_ADDRESS_EQ2

D=A

@6

0;JMP

(RET_ADDRESS_EQ2)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

@ball.bounce$if_true1

D;JNE

@ball.bounce$if_false1

0;JMP

(ball.bounce$if_true1)

@20

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ball.bounce$if_end1

0;JMP

(ball.bounce$if_false1)

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

(ball.bounce$if_end1)

(ball.bounce$if_end0)

@THIS

D=M

@14

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@RET_ADDRESS_EQ3

D=A

@6

0;JMP

(RET_ADDRESS_EQ3)

@SP

AM=M-1

D=M

@ball.bounce$if_true2

D;JNE

@ball.bounce$if_false2

0;JMP

(ball.bounce$if_true2)

@506

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@50

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL18

D=A

@95

0;JMP

(RET_ADDRESS_CALL18)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL19

D=A

@95

0;JMP

(RET_ADDRESS_CALL19)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL20

D=A

@95

0;JMP

(RET_ADDRESS_CALL20)

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@ball.bounce$if_end2

0;JMP

(ball.bounce$if_false2)

@THIS

D=M

@14

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ4

D=A

@6

0;JMP

(RET_ADDRESS_EQ4)

@SP

AM=M-1

D=M

@ball.bounce$if_true3

D;JNE

@ball.bounce$if_false3

0;JMP

(ball.bounce$if_true3)

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@50

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL21

D=A

@95

0;JMP

(RET_ADDRESS_CALL21)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL22

D=A

@95

0;JMP

(RET_ADDRESS_CALL22)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL23

D=A

@95

0;JMP

(RET_ADDRESS_CALL23)

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@ball.bounce$if_end3

0;JMP

(ball.bounce$if_false3)

@THIS

D=M

@14

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ5

D=A

@6

0;JMP

(RET_ADDRESS_EQ5)

@SP

AM=M-1

D=M

@ball.bounce$if_true4

D;JNE

@ball.bounce$if_false4

0;JMP

(ball.bounce$if_true4)

@250

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@25

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL24

D=A

@95

0;JMP

(RET_ADDRESS_CALL24)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL25

D=A

@95

0;JMP

(RET_ADDRESS_CALL25)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL26

D=A

@95

0;JMP

(RET_ADDRESS_CALL26)

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@ball.bounce$if_end4

0;JMP

(ball.bounce$if_false4)

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@25

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL27

D=A

@95

0;JMP

(RET_ADDRESS_CALL27)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL28

D=A

@95

0;JMP

(RET_ADDRESS_CALL28)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL29

D=A

@95

0;JMP

(RET_ADDRESS_CALL29)

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(ball.bounce$if_end4)

(ball.bounce$if_end3)

(ball.bounce$if_end2)

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@R13

M=D

@ball.setdestination

D=A

@R14

M=D

@RET_ADDRESS_CALL30

D=A

@95

0;JMP

(RET_ADDRESS_CALL30)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(bat.new)

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.alloc

D=A

@R14

M=D

@RET_ADDRESS_CALL31

D=A

@95

0;JMP

(RET_ADDRESS_CALL31)

@SP

AM=M-1

D=M

@THIS

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.show

D=A

@R14

M=D

@RET_ADDRESS_CALL32

D=A

@95

0;JMP

(RET_ADDRESS_CALL32)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(bat.dispose)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.dealloc

D=A

@R14

M=D

@RET_ADDRESS_CALL33

D=A

@95

0;JMP

(RET_ADDRESS_CALL33)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(bat.show)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL34

D=A

@95

0;JMP

(RET_ADDRESS_CALL34)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.draw

D=A

@R14

M=D

@RET_ADDRESS_CALL35

D=A

@95

0;JMP

(RET_ADDRESS_CALL35)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(bat.hide)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@SP

M=M+1

A=M-1

M=0

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL36

D=A

@95

0;JMP

(RET_ADDRESS_CALL36)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.draw

D=A

@R14

M=D

@RET_ADDRESS_CALL37

D=A

@95

0;JMP

(RET_ADDRESS_CALL37)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(bat.draw)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@R13

M=D

@screen.drawrectangle

D=A

@R14

M=D

@RET_ADDRESS_CALL38

D=A

@95

0;JMP

(RET_ADDRESS_CALL38)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(bat.setdirection)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(bat.getleft)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(bat.getright)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@54

0;JMP

(bat.setwidth)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.hide

D=A

@R14

M=D

@RET_ADDRESS_CALL39

D=A

@95

0;JMP

(RET_ADDRESS_CALL39)

@SP

AM=M-1

D=M

@R5

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.show

D=A

@R14

M=D

@RET_ADDRESS_CALL40

D=A

@95

0;JMP

(RET_ADDRESS_CALL40)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(bat.move)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@RET_ADDRESS_EQ6

D=A

@6

0;JMP

(RET_ADDRESS_EQ6)

@SP

AM=M-1

D=M

@bat.move$if_true0

D;JNE

@bat.move$if_false0

0;JMP

(bat.move$if_true0)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT10

D=A

@38

0;JMP

(RET_ADDRESS_LT10)

@SP

AM=M-1

D=M

@bat.move$if_true1

D;JNE

@bat.move$if_false1

0;JMP

(bat.move$if_true1)

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@THIS

A=M

M=D

(bat.move$if_false1)

@SP

M=M+1

A=M-1

M=0

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL41

D=A

@95

0;JMP

(RET_ADDRESS_CALL41)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@R13

M=D

@screen.drawrectangle

D=A

@R14

M=D

@RET_ADDRESS_CALL42

D=A

@95

0;JMP

(RET_ADDRESS_CALL42)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL43

D=A

@95

0;JMP

(RET_ADDRESS_CALL43)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@R13

M=D

@screen.drawrectangle

D=A

@R14

M=D

@RET_ADDRESS_CALL44

D=A

@95

0;JMP

(RET_ADDRESS_CALL44)

@SP

AM=M-1

D=M

@R5

M=D

@bat.move$if_end0

0;JMP

(bat.move$if_false0)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT2

D=A

@22

0;JMP

(RET_ADDRESS_GT2)

@SP

AM=M-1

D=M

@bat.move$if_true2

D;JNE

@bat.move$if_false2

0;JMP

(bat.move$if_true2)

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

(bat.move$if_false2)

@SP

M=M+1

A=M-1

M=0

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL45

D=A

@95

0;JMP

(RET_ADDRESS_CALL45)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@R13

M=D

@screen.drawrectangle

D=A

@R14

M=D

@RET_ADDRESS_CALL46

D=A

@95

0;JMP

(RET_ADDRESS_CALL46)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@1

D=A

@R13

M=D

@screen.setcolor

D=A

@R14

M=D

@RET_ADDRESS_CALL47

D=A

@95

0;JMP

(RET_ADDRESS_CALL47)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@R13

M=D

@screen.drawrectangle

D=A

@R14

M=D

@RET_ADDRESS_CALL48

D=A

@95

0;JMP

(RET_ADDRESS_CALL48)

@SP

AM=M-1

D=M

@R5

M=D

(bat.move$if_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(main.main)

@SP

AM=M+1

A=A-1

M=0

@0

D=A

@R13

M=D

@ponggame.newinstance

D=A

@R14

M=D

@RET_ADDRESS_CALL49

D=A

@95

0;JMP

(RET_ADDRESS_CALL49)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@ponggame.getinstance

D=A

@R14

M=D

@RET_ADDRESS_CALL50

D=A

@95

0;JMP

(RET_ADDRESS_CALL50)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ponggame.run

D=A

@R14

M=D

@RET_ADDRESS_CALL51

D=A

@95

0;JMP

(RET_ADDRESS_CALL51)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ponggame.dispose

D=A

@R14

M=D

@RET_ADDRESS_CALL52

D=A

@95

0;JMP

(RET_ADDRESS_CALL52)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ponggame.new)

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.alloc

D=A

@R14

M=D

@RET_ADDRESS_CALL53

D=A

@95

0;JMP

(RET_ADDRESS_CALL53)

@SP

AM=M-1

D=M

@THIS

M=D

@0

D=A

@R13

M=D

@screen.clearscreen

D=A

@R14

M=D

@RET_ADDRESS_CALL54

D=A

@95

0;JMP

(RET_ADDRESS_CALL54)

@SP

AM=M-1

D=M

@R5

M=D

@50

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@230

D=A

@SP

AM=M+1

A=A-1

M=D

@229

D=A

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@R13

M=D

@bat.new

D=A

@R14

M=D

@RET_ADDRESS_CALL55

D=A

@95

0;JMP

(RET_ADDRESS_CALL55)

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@253

D=A

@SP

AM=M+1

A=A-1

M=D

@222

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@229

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@R13

M=D

@ball.new

D=A

@R14

M=D

@RET_ADDRESS_CALL56

D=A

@95

0;JMP

(RET_ADDRESS_CALL56)

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@400

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@3

D=A

@R13

M=D

@ball.setdestination

D=A

@R14

M=D

@RET_ADDRESS_CALL57

D=A

@95

0;JMP

(RET_ADDRESS_CALL57)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@238

D=A

@SP

AM=M+1

A=A-1

M=D

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@240

D=A

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@R13

M=D

@screen.drawrectangle

D=A

@R14

M=D

@RET_ADDRESS_CALL58

D=A

@95

0;JMP

(RET_ADDRESS_CALL58)

@SP

AM=M-1

D=M

@R5

M=D

@22

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@2

D=A

@R13

M=D

@output.movecursor

D=A

@R14

M=D

@RET_ADDRESS_CALL59

D=A

@95

0;JMP

(RET_ADDRESS_CALL59)

@SP

AM=M-1

D=M

@R5

M=D

@8

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.new

D=A

@R14

M=D

@RET_ADDRESS_CALL60

D=A

@95

0;JMP

(RET_ADDRESS_CALL60)

@83

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL61

D=A

@95

0;JMP

(RET_ADDRESS_CALL61)

@99

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL62

D=A

@95

0;JMP

(RET_ADDRESS_CALL62)

@111

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL63

D=A

@95

0;JMP

(RET_ADDRESS_CALL63)

@114

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL64

D=A

@95

0;JMP

(RET_ADDRESS_CALL64)

@101

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL65

D=A

@95

0;JMP

(RET_ADDRESS_CALL65)

@58

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL66

D=A

@95

0;JMP

(RET_ADDRESS_CALL66)

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL67

D=A

@95

0;JMP

(RET_ADDRESS_CALL67)

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL68

D=A

@95

0;JMP

(RET_ADDRESS_CALL68)

@1

D=A

@R13

M=D

@output.printstring

D=A

@R14

M=D

@RET_ADDRESS_CALL69

D=A

@95

0;JMP

(RET_ADDRESS_CALL69)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(ponggame.dispose)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.dispose

D=A

@R14

M=D

@RET_ADDRESS_CALL70

D=A

@95

0;JMP

(RET_ADDRESS_CALL70)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.dispose

D=A

@R14

M=D

@RET_ADDRESS_CALL71

D=A

@95

0;JMP

(RET_ADDRESS_CALL71)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.dealloc

D=A

@R14

M=D

@RET_ADDRESS_CALL72

D=A

@95

0;JMP

(RET_ADDRESS_CALL72)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ponggame.newinstance)

@0

D=A

@R13

M=D

@ponggame.new

D=A

@R14

M=D

@RET_ADDRESS_CALL73

D=A

@95

0;JMP

(RET_ADDRESS_CALL73)

@SP

AM=M-1

D=M

@ponggame.0

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ponggame.getinstance)

@ponggame.0

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(ponggame.run)

@SP

AM=M+1

A=A-1

M=0

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

(ponggame.run$while_exp0)

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ponggame.run$while_end0

D;JNE

(ponggame.run$while_exp1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ7

D=A

@6

0;JMP

(RET_ADDRESS_EQ7)

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ponggame.run$while_end1

D;JNE

@0

D=A

@R13

M=D

@keyboard.keypressed

D=A

@R14

M=D

@RET_ADDRESS_CALL74

D=A

@95

0;JMP

(RET_ADDRESS_CALL74)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.move

D=A

@R14

M=D

@RET_ADDRESS_CALL75

D=A

@95

0;JMP

(RET_ADDRESS_CALL75)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ponggame.moveball

D=A

@R14

M=D

@RET_ADDRESS_CALL76

D=A

@95

0;JMP

(RET_ADDRESS_CALL76)

@SP

AM=M-1

D=M

@R5

M=D

@ponggame.run$while_exp1

0;JMP

(ponggame.run$while_end1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@130

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ8

D=A

@6

0;JMP

(RET_ADDRESS_EQ8)

@SP

AM=M-1

D=M

@ponggame.run$if_true0

D;JNE

@ponggame.run$if_false0

0;JMP

(ponggame.run$if_true0)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@2

D=A

@R13

M=D

@bat.setdirection

D=A

@R14

M=D

@RET_ADDRESS_CALL77

D=A

@95

0;JMP

(RET_ADDRESS_CALL77)

@SP

AM=M-1

D=M

@R5

M=D

@ponggame.run$if_end0

0;JMP

(ponggame.run$if_false0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@132

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ9

D=A

@6

0;JMP

(RET_ADDRESS_EQ9)

@SP

AM=M-1

D=M

@ponggame.run$if_true1

D;JNE

@ponggame.run$if_false1

0;JMP

(ponggame.run$if_true1)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@bat.setdirection

D=A

@R14

M=D

@RET_ADDRESS_CALL78

D=A

@95

0;JMP

(RET_ADDRESS_CALL78)

@SP

AM=M-1

D=M

@R5

M=D

@ponggame.run$if_end1

0;JMP

(ponggame.run$if_false1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@140

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ10

D=A

@6

0;JMP

(RET_ADDRESS_EQ10)

@SP

AM=M-1

D=M

@ponggame.run$if_true2

D;JNE

@ponggame.run$if_false2

0;JMP

(ponggame.run$if_true2)

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

M=D

(ponggame.run$if_false2)

(ponggame.run$if_end1)

(ponggame.run$if_end0)

(ponggame.run$while_exp2)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ11

D=A

@6

0;JMP

(RET_ADDRESS_EQ11)

@SP

A=M-1

M=!M

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ponggame.run$while_end2

D;JNE

@0

D=A

@R13

M=D

@keyboard.keypressed

D=A

@R14

M=D

@RET_ADDRESS_CALL79

D=A

@95

0;JMP

(RET_ADDRESS_CALL79)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.move

D=A

@R14

M=D

@RET_ADDRESS_CALL80

D=A

@95

0;JMP

(RET_ADDRESS_CALL80)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ponggame.moveball

D=A

@R14

M=D

@RET_ADDRESS_CALL81

D=A

@95

0;JMP

(RET_ADDRESS_CALL81)

@SP

AM=M-1

D=M

@R5

M=D

@ponggame.run$while_exp2

0;JMP

(ponggame.run$while_end2)

@ponggame.run$while_exp0

0;JMP

(ponggame.run$while_end0)

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ponggame.run$if_true3

D;JNE

@ponggame.run$if_false3

0;JMP

(ponggame.run$if_true3)

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@output.movecursor

D=A

@R14

M=D

@RET_ADDRESS_CALL82

D=A

@95

0;JMP

(RET_ADDRESS_CALL82)

@SP

AM=M-1

D=M

@R5

M=D

@9

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.new

D=A

@R14

M=D

@RET_ADDRESS_CALL83

D=A

@95

0;JMP

(RET_ADDRESS_CALL83)

@71

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL84

D=A

@95

0;JMP

(RET_ADDRESS_CALL84)

@97

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL85

D=A

@95

0;JMP

(RET_ADDRESS_CALL85)

@109

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL86

D=A

@95

0;JMP

(RET_ADDRESS_CALL86)

@101

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL87

D=A

@95

0;JMP

(RET_ADDRESS_CALL87)

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL88

D=A

@95

0;JMP

(RET_ADDRESS_CALL88)

@79

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL89

D=A

@95

0;JMP

(RET_ADDRESS_CALL89)

@118

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL90

D=A

@95

0;JMP

(RET_ADDRESS_CALL90)

@101

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL91

D=A

@95

0;JMP

(RET_ADDRESS_CALL91)

@114

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL92

D=A

@95

0;JMP

(RET_ADDRESS_CALL92)

@1

D=A

@R13

M=D

@output.printstring

D=A

@R14

M=D

@RET_ADDRESS_CALL93

D=A

@95

0;JMP

(RET_ADDRESS_CALL93)

@SP

AM=M-1

D=M

@R5

M=D

(ponggame.run$if_false3)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(ponggame.moveball)

@5

D=A

(LOOP_ponggame.moveball)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_ponggame.moveball

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.move

D=A

@R14

M=D

@RET_ADDRESS_CALL94

D=A

@95

0;JMP

(RET_ADDRESS_CALL94)

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT3

D=A

@22

0;JMP

(RET_ADDRESS_GT3)

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ12

D=A

@6

0;JMP

(RET_ADDRESS_EQ12)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

@ponggame.moveball$if_true0

D;JNE

@ponggame.moveball$if_false0

0;JMP

(ponggame.moveball$if_true0)

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.getleft

D=A

@R14

M=D

@RET_ADDRESS_CALL95

D=A

@95

0;JMP

(RET_ADDRESS_CALL95)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@bat.getright

D=A

@R14

M=D

@RET_ADDRESS_CALL96

D=A

@95

0;JMP

(RET_ADDRESS_CALL96)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.getleft

D=A

@R14

M=D

@RET_ADDRESS_CALL97

D=A

@95

0;JMP

(RET_ADDRESS_CALL97)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@ball.getright

D=A

@R14

M=D

@RET_ADDRESS_CALL98

D=A

@95

0;JMP

(RET_ADDRESS_CALL98)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ13

D=A

@6

0;JMP

(RET_ADDRESS_EQ13)

@SP

AM=M-1

D=M

@ponggame.moveball$if_true1

D;JNE

@ponggame.moveball$if_false1

0;JMP

(ponggame.moveball$if_true1)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT4

D=A

@22

0;JMP

(RET_ADDRESS_GT4)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT11

D=A

@38

0;JMP

(RET_ADDRESS_LT11)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

M=D

@THIS

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@ponggame.moveball$if_true2

D;JNE

@ponggame.moveball$if_false2

0;JMP

(ponggame.moveball$if_true2)

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@RET_ADDRESS_LT12

D=A

@38

0;JMP

(RET_ADDRESS_LT12)

@SP

AM=M-1

D=M

@ponggame.moveball$if_true3

D;JNE

@ponggame.moveball$if_false3

0;JMP

(ponggame.moveball$if_true3)

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@ponggame.moveball$if_end3

0;JMP

(ponggame.moveball$if_false3)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@RET_ADDRESS_GT5

D=A

@22

0;JMP

(RET_ADDRESS_GT5)

@SP

AM=M-1

D=M

@ponggame.moveball$if_true4

D;JNE

@ponggame.moveball$if_false4

0;JMP

(ponggame.moveball$if_true4)

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(ponggame.moveball$if_false4)

(ponggame.moveball$if_end3)

@THIS

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@bat.setwidth

D=A

@R14

M=D

@RET_ADDRESS_CALL99

D=A

@95

0;JMP

(RET_ADDRESS_CALL99)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@22

D=A

@SP

AM=M+1

A=A-1

M=D

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@output.movecursor

D=A

@R14

M=D

@RET_ADDRESS_CALL100

D=A

@95

0;JMP

(RET_ADDRESS_CALL100)

@SP

AM=M-1

D=M

@R5

M=D

@THIS

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.printint

D=A

@R14

M=D

@RET_ADDRESS_CALL101

D=A

@95

0;JMP

(RET_ADDRESS_CALL101)

@SP

AM=M-1

D=M

@R5

M=D

(ponggame.moveball$if_false2)

(ponggame.moveball$if_false1)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@ball.bounce

D=A

@R14

M=D

@RET_ADDRESS_CALL102

D=A

@95

0;JMP

(RET_ADDRESS_CALL102)

@SP

AM=M-1

D=M

@R5

M=D

(ponggame.moveball$if_false0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(array.new)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT6

D=A

@22

0;JMP

(RET_ADDRESS_GT6)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@array.new$if_true0

D;JNE

@array.new$if_false0

0;JMP

(array.new$if_true0)

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL103

D=A

@95

0;JMP

(RET_ADDRESS_CALL103)

@SP

AM=M-1

D=M

@R5

M=D

(array.new$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.alloc

D=A

@R14

M=D

@RET_ADDRESS_CALL104

D=A

@95

0;JMP

(RET_ADDRESS_CALL104)

@54

0;JMP

(array.dispose)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.dealloc

D=A

@R14

M=D

@RET_ADDRESS_CALL105

D=A

@95

0;JMP

(RET_ADDRESS_CALL105)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(keyboard.init)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(keyboard.keypressed)

@24576

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.peek

D=A

@R14

M=D

@RET_ADDRESS_CALL106

D=A

@95

0;JMP

(RET_ADDRESS_CALL106)

@54

0;JMP

(keyboard.readchar)

@SP

A=M

M=0

AD=A+1

M=0

@SP

M=D+1

@SP

M=M+1

A=M-1

M=0

@1

D=A

@R13

M=D

@output.printchar

D=A

@R14

M=D

@RET_ADDRESS_CALL107

D=A

@95

0;JMP

(RET_ADDRESS_CALL107)

@SP

AM=M-1

D=M

@R5

M=D

(keyboard.readchar$while_exp0)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ14

D=A

@6

0;JMP

(RET_ADDRESS_EQ14)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT7

D=A

@22

0;JMP

(RET_ADDRESS_GT7)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@keyboard.readchar$while_end0

D;JNE

@0

D=A

@R13

M=D

@keyboard.keypressed

D=A

@R14

M=D

@RET_ADDRESS_CALL108

D=A

@95

0;JMP

(RET_ADDRESS_CALL108)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT8

D=A

@22

0;JMP

(RET_ADDRESS_GT8)

@SP

AM=M-1

D=M

@keyboard.readchar$if_true0

D;JNE

@keyboard.readchar$if_false0

0;JMP

(keyboard.readchar$if_true0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

(keyboard.readchar$if_false0)

@keyboard.readchar$while_exp0

0;JMP

(keyboard.readchar$while_end0)

@0

D=A

@R13

M=D

@string.backspace

D=A

@R14

M=D

@RET_ADDRESS_CALL109

D=A

@95

0;JMP

(RET_ADDRESS_CALL109)

@1

D=A

@R13

M=D

@output.printchar

D=A

@R14

M=D

@RET_ADDRESS_CALL110

D=A

@95

0;JMP

(RET_ADDRESS_CALL110)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.printchar

D=A

@R14

M=D

@RET_ADDRESS_CALL111

D=A

@95

0;JMP

(RET_ADDRESS_CALL111)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(keyboard.readline)

@5

D=A

(LOOP_keyboard.readline)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_keyboard.readline

D;JGT

@80

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.new

D=A

@R14

M=D

@RET_ADDRESS_CALL112

D=A

@95

0;JMP

(RET_ADDRESS_CALL112)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.printstring

D=A

@R14

M=D

@RET_ADDRESS_CALL113

D=A

@95

0;JMP

(RET_ADDRESS_CALL113)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@string.newline

D=A

@R14

M=D

@RET_ADDRESS_CALL114

D=A

@95

0;JMP

(RET_ADDRESS_CALL114)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@0

D=A

@R13

M=D

@string.backspace

D=A

@R14

M=D

@RET_ADDRESS_CALL115

D=A

@95

0;JMP

(RET_ADDRESS_CALL115)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

(keyboard.readline$while_exp0)

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@keyboard.readline$while_end0

D;JNE

@0

D=A

@R13

M=D

@keyboard.readchar

D=A

@R14

M=D

@RET_ADDRESS_CALL116

D=A

@95

0;JMP

(RET_ADDRESS_CALL116)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ15

D=A

@6

0;JMP

(RET_ADDRESS_EQ15)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@keyboard.readline$if_true0

D;JNE

@keyboard.readline$if_false0

0;JMP

(keyboard.readline$if_true0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ16

D=A

@6

0;JMP

(RET_ADDRESS_EQ16)

@SP

AM=M-1

D=M

@keyboard.readline$if_true1

D;JNE

@keyboard.readline$if_false1

0;JMP

(keyboard.readline$if_true1)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.eraselastchar

D=A

@R14

M=D

@RET_ADDRESS_CALL117

D=A

@95

0;JMP

(RET_ADDRESS_CALL117)

@SP

AM=M-1

D=M

@R5

M=D

@keyboard.readline$if_end1

0;JMP

(keyboard.readline$if_false1)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL118

D=A

@95

0;JMP

(RET_ADDRESS_CALL118)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

(keyboard.readline$if_end1)

(keyboard.readline$if_false0)

@keyboard.readline$while_exp0

0;JMP

(keyboard.readline$while_end0)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(keyboard.readint)

@SP

A=M

M=0

AD=A+1

M=0

@SP

M=D+1

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@keyboard.readline

D=A

@R14

M=D

@RET_ADDRESS_CALL119

D=A

@95

0;JMP

(RET_ADDRESS_CALL119)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.intvalue

D=A

@R14

M=D

@RET_ADDRESS_CALL120

D=A

@95

0;JMP

(RET_ADDRESS_CALL120)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.dispose

D=A

@R14

M=D

@RET_ADDRESS_CALL121

D=A

@95

0;JMP

(RET_ADDRESS_CALL121)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(math.init)

@SP

AM=M+1

A=A-1

M=0

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL122

D=A

@95

0;JMP

(RET_ADDRESS_CALL122)

@SP

AM=M-1

D=M

@math.1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL123

D=A

@95

0;JMP

(RET_ADDRESS_CALL123)

@SP

AM=M-1

D=M

@math.0

M=D

@SP

M=M+1

A=M-1

M=0

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

(math.init$while_exp0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT13

D=A

@38

0;JMP

(RET_ADDRESS_LT13)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.init$while_end0

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@math.init$while_exp0

0;JMP

(math.init$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(math.abs)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT14

D=A

@38

0;JMP

(RET_ADDRESS_LT14)

@SP

AM=M-1

D=M

@math.abs$if_true0

D;JNE

@math.abs$if_false0

0;JMP

(math.abs$if_true0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@SP

AM=M-1

D=M

@ARG

A=M

M=D

(math.abs$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(math.multiply)

@5

D=A

(LOOP_math.multiply)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_math.multiply

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT15

D=A

@38

0;JMP

(RET_ADDRESS_LT15)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT9

D=A

@22

0;JMP

(RET_ADDRESS_GT9)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT10

D=A

@22

0;JMP

(RET_ADDRESS_GT10)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT16

D=A

@38

0;JMP

(RET_ADDRESS_LT16)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL124

D=A

@95

0;JMP

(RET_ADDRESS_CALL124)

@SP

AM=M-1

D=M

@ARG

A=M

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL125

D=A

@95

0;JMP

(RET_ADDRESS_CALL125)

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT17

D=A

@38

0;JMP

(RET_ADDRESS_LT17)

@SP

AM=M-1

D=M

@math.multiply$if_true0

D;JNE

@math.multiply$if_false0

0;JMP

(math.multiply$if_true0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

(math.multiply$if_false0)

(math.multiply$while_exp0)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT18

D=A

@38

0;JMP

(RET_ADDRESS_LT18)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.multiply$while_end0

D;JNE

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT11

D=A

@22

0;JMP

(RET_ADDRESS_GT11)

@SP

AM=M-1

D=M

@math.multiply$if_true1

D;JNE

@math.multiply$if_false1

0;JMP

(math.multiply$if_true1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

(math.multiply$if_false1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@ARG

A=M

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@math.multiply$while_exp0

0;JMP

(math.multiply$while_end0)

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@math.multiply$if_true2

D;JNE

@math.multiply$if_false2

0;JMP

(math.multiply$if_true2)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(math.multiply$if_false2)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(math.divide)

@4

D=A

(LOOP_math.divide)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_math.divide

D;JGT

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ17

D=A

@6

0;JMP

(RET_ADDRESS_EQ17)

@SP

AM=M-1

D=M

@math.divide$if_true0

D;JNE

@math.divide$if_false0

0;JMP

(math.divide$if_true0)

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL126

D=A

@95

0;JMP

(RET_ADDRESS_CALL126)

@SP

AM=M-1

D=M

@R5

M=D

(math.divide$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT19

D=A

@38

0;JMP

(RET_ADDRESS_LT19)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT12

D=A

@22

0;JMP

(RET_ADDRESS_GT12)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT13

D=A

@22

0;JMP

(RET_ADDRESS_GT13)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT20

D=A

@38

0;JMP

(RET_ADDRESS_LT20)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL127

D=A

@95

0;JMP

(RET_ADDRESS_CALL127)

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL128

D=A

@95

0;JMP

(RET_ADDRESS_CALL128)

@SP

AM=M-1

D=M

@ARG

A=M

M=D

(math.divide$while_exp0)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.divide$while_end0

D;JNE

@32767

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT21

D=A

@38

0;JMP

(RET_ADDRESS_LT21)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.divide$if_true1

D;JNE

@math.divide$if_false1

0;JMP

(math.divide$if_true1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT14

D=A

@22

0;JMP

(RET_ADDRESS_GT14)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.divide$if_true2

D;JNE

@math.divide$if_false2

0;JMP

(math.divide$if_true2)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(math.divide$if_false2)

(math.divide$if_false1)

@math.divide$while_exp0

0;JMP

(math.divide$while_end0)

(math.divide$while_exp1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@RET_ADDRESS_GT15

D=A

@22

0;JMP

(RET_ADDRESS_GT15)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.divide$while_end1

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT16

D=A

@22

0;JMP

(RET_ADDRESS_GT16)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.divide$if_true3

D;JNE

@math.divide$if_false3

0;JMP

(math.divide$if_true3)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@ARG

A=M

M=D

(math.divide$if_false3)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@math.divide$while_exp1

0;JMP

(math.divide$while_end1)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@math.divide$if_true4

D;JNE

@math.divide$if_false4

0;JMP

(math.divide$if_true4)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

(math.divide$if_false4)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(math.sqrt)

@4

D=A

(LOOP_math.sqrt)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_math.sqrt

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT22

D=A

@38

0;JMP

(RET_ADDRESS_LT22)

@SP

AM=M-1

D=M

@math.sqrt$if_true0

D;JNE

@math.sqrt$if_false0

0;JMP

(math.sqrt$if_true0)

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL129

D=A

@95

0;JMP

(RET_ADDRESS_CALL129)

@SP

AM=M-1

D=M

@R5

M=D

(math.sqrt$if_false0)

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(math.sqrt$while_exp0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@RET_ADDRESS_GT17

D=A

@22

0;JMP

(RET_ADDRESS_GT17)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@math.sqrt$while_end0

D;JNE

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@math.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL130

D=A

@95

0;JMP

(RET_ADDRESS_CALL130)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT18

D=A

@22

0;JMP

(RET_ADDRESS_GT18)

@SP

A=M-1

M=!M

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT23

D=A

@38

0;JMP

(RET_ADDRESS_LT23)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

@math.sqrt$if_true1

D;JNE

@math.sqrt$if_false1

0;JMP

(math.sqrt$if_true1)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

(math.sqrt$if_false1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@math.sqrt$while_exp0

0;JMP

(math.sqrt$while_end0)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(math.max)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT19

D=A

@22

0;JMP

(RET_ADDRESS_GT19)

@SP

AM=M-1

D=M

@math.max$if_true0

D;JNE

@math.max$if_false0

0;JMP

(math.max$if_true0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

(math.max$if_false0)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(math.min)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT24

D=A

@38

0;JMP

(RET_ADDRESS_LT24)

@SP

AM=M-1

D=M

@math.min$if_true0

D;JNE

@math.min$if_false0

0;JMP

(math.min$if_true0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

(math.min$if_false0)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(memory.init)

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@memory.0

M=D

@2048

D=A

@SP

AM=M+1

A=A-1

M=D

@memory.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@14334

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@2049

D=A

@SP

AM=M+1

A=A-1

M=D

@memory.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@2050

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(memory.peek)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@memory.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(memory.poke)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@memory.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(memory.alloc)

@SP

AM=M+1

A=A-1

M=0

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@RET_ADDRESS_LT25

D=A

@38

0;JMP

(RET_ADDRESS_LT25)

@SP

AM=M-1

D=M

@memory.alloc$if_true0

D;JNE

@memory.alloc$if_false0

0;JMP

(memory.alloc$if_true0)

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL131

D=A

@95

0;JMP

(RET_ADDRESS_CALL131)

@SP

AM=M-1

D=M

@R5

M=D

(memory.alloc$if_false0)

@2048

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(memory.alloc$while_exp0)

@SP

M=M+1

A=M-1

M=0

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT26

D=A

@38

0;JMP

(RET_ADDRESS_LT26)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@memory.alloc$while_end0

D;JNE

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@memory.alloc$while_exp0

0;JMP

(memory.alloc$while_end0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@16379

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT20

D=A

@22

0;JMP

(RET_ADDRESS_GT20)

@SP

AM=M-1

D=M

@memory.alloc$if_true1

D;JNE

@memory.alloc$if_false1

0;JMP

(memory.alloc$if_true1)

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL132

D=A

@95

0;JMP

(RET_ADDRESS_CALL132)

@SP

AM=M-1

D=M

@R5

M=D

(memory.alloc$if_false1)

@SP

M=M+1

A=M-1

M=0

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@RET_ADDRESS_GT21

D=A

@22

0;JMP

(RET_ADDRESS_GT21)

@SP

AM=M-1

D=M

@memory.alloc$if_true2

D;JNE

@memory.alloc$if_false2

0;JMP

(memory.alloc$if_true2)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=0

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@RET_ADDRESS_EQ18

D=A

@6

0;JMP

(RET_ADDRESS_EQ18)

@SP

AM=M-1

D=M

@memory.alloc$if_true3

D;JNE

@memory.alloc$if_false3

0;JMP

(memory.alloc$if_true3)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@memory.alloc$if_end3

0;JMP

(memory.alloc$if_false3)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

(memory.alloc$if_end3)

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

(memory.alloc$if_false2)

@SP

M=M+1

A=M-1

M=0

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@54

0;JMP

(memory.dealloc)

@SP

A=M

M=0

AD=A+1

M=0

@SP

M=D+1

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@SP

M=M+1

A=M-1

M=0

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ19

D=A

@6

0;JMP

(RET_ADDRESS_EQ19)

@SP

AM=M-1

D=M

@memory.dealloc$if_true0

D;JNE

@memory.dealloc$if_false0

0;JMP

(memory.dealloc$if_true0)

@SP

M=M+1

A=M-1

M=0

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@memory.dealloc$if_end0

0;JMP

(memory.dealloc$if_false0)

@SP

M=M+1

A=M-1

M=0

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

M=M+1

A=M-1

M=0

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=1

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@RET_ADDRESS_EQ20

D=A

@6

0;JMP

(RET_ADDRESS_EQ20)

@SP

AM=M-1

D=M

@memory.dealloc$if_true1

D;JNE

@memory.dealloc$if_false1

0;JMP

(memory.dealloc$if_true1)

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@memory.dealloc$if_end1

0;JMP

(memory.dealloc$if_false1)

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=1

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

(memory.dealloc$if_end1)

(memory.dealloc$if_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.init)

@16384

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.4

M=D

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.2

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@output.0

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.new

D=A

@R14

M=D

@RET_ADDRESS_CALL133

D=A

@95

0;JMP

(RET_ADDRESS_CALL133)

@SP

AM=M-1

D=M

@output.3

M=D

@0

D=A

@R13

M=D

@output.initmap

D=A

@R14

M=D

@RET_ADDRESS_CALL134

D=A

@95

0;JMP

(RET_ADDRESS_CALL134)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@output.createshiftedmap

D=A

@R14

M=D

@RET_ADDRESS_CALL135

D=A

@95

0;JMP

(RET_ADDRESS_CALL135)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.initmap)

@127

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL136

D=A

@95

0;JMP

(RET_ADDRESS_CALL136)

@SP

AM=M-1

D=M

@output.5

M=D

@SP

M=M+1

A=M-1

M=0

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL137

D=A

@95

0;JMP

(RET_ADDRESS_CALL137)

@SP

AM=M-1

D=M

@R5

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL138

D=A

@95

0;JMP

(RET_ADDRESS_CALL138)

@SP

AM=M-1

D=M

@R5

M=D

@33

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL139

D=A

@95

0;JMP

(RET_ADDRESS_CALL139)

@SP

AM=M-1

D=M

@R5

M=D

@34

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@20

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL140

D=A

@95

0;JMP

(RET_ADDRESS_CALL140)

@SP

AM=M-1

D=M

@R5

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL141

D=A

@95

0;JMP

(RET_ADDRESS_CALL141)

@SP

AM=M-1

D=M

@R5

M=D

@36

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL142

D=A

@95

0;JMP

(RET_ADDRESS_CALL142)

@SP

AM=M-1

D=M

@R5

M=D

@37

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@49

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL143

D=A

@95

0;JMP

(RET_ADDRESS_CALL143)

@SP

AM=M-1

D=M

@R5

M=D

@38

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL144

D=A

@95

0;JMP

(RET_ADDRESS_CALL144)

@SP

AM=M-1

D=M

@R5

M=D

@39

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL145

D=A

@95

0;JMP

(RET_ADDRESS_CALL145)

@SP

AM=M-1

D=M

@R5

M=D

@40

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL146

D=A

@95

0;JMP

(RET_ADDRESS_CALL146)

@SP

AM=M-1

D=M

@R5

M=D

@41

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL147

D=A

@95

0;JMP

(RET_ADDRESS_CALL147)

@SP

AM=M-1

D=M

@R5

M=D

@42

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL148

D=A

@95

0;JMP

(RET_ADDRESS_CALL148)

@SP

AM=M-1

D=M

@R5

M=D

@43

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL149

D=A

@95

0;JMP

(RET_ADDRESS_CALL149)

@SP

AM=M-1

D=M

@R5

M=D

@44

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL150

D=A

@95

0;JMP

(RET_ADDRESS_CALL150)

@SP

AM=M-1

D=M

@R5

M=D

@45

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL151

D=A

@95

0;JMP

(RET_ADDRESS_CALL151)

@SP

AM=M-1

D=M

@R5

M=D

@46

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL152

D=A

@95

0;JMP

(RET_ADDRESS_CALL152)

@SP

AM=M-1

D=M

@R5

M=D

@47

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL153

D=A

@95

0;JMP

(RET_ADDRESS_CALL153)

@SP

AM=M-1

D=M

@R5

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL154

D=A

@95

0;JMP

(RET_ADDRESS_CALL154)

@SP

AM=M-1

D=M

@R5

M=D

@49

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@14

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL155

D=A

@95

0;JMP

(RET_ADDRESS_CALL155)

@SP

AM=M-1

D=M

@R5

M=D

@50

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL156

D=A

@95

0;JMP

(RET_ADDRESS_CALL156)

@SP

AM=M-1

D=M

@R5

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL157

D=A

@95

0;JMP

(RET_ADDRESS_CALL157)

@SP

AM=M-1

D=M

@R5

M=D

@52

D=A

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@26

D=A

@SP

AM=M+1

A=A-1

M=D

@25

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@60

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL158

D=A

@95

0;JMP

(RET_ADDRESS_CALL158)

@SP

AM=M-1

D=M

@R5

M=D

@53

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL159

D=A

@95

0;JMP

(RET_ADDRESS_CALL159)

@SP

AM=M-1

D=M

@R5

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL160

D=A

@95

0;JMP

(RET_ADDRESS_CALL160)

@SP

AM=M-1

D=M

@R5

M=D

@55

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@49

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL161

D=A

@95

0;JMP

(RET_ADDRESS_CALL161)

@SP

AM=M-1

D=M

@R5

M=D

@56

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL162

D=A

@95

0;JMP

(RET_ADDRESS_CALL162)

@SP

AM=M-1

D=M

@R5

M=D

@57

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@62

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@14

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL163

D=A

@95

0;JMP

(RET_ADDRESS_CALL163)

@SP

AM=M-1

D=M

@R5

M=D

@58

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL164

D=A

@95

0;JMP

(RET_ADDRESS_CALL164)

@SP

AM=M-1

D=M

@R5

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL165

D=A

@95

0;JMP

(RET_ADDRESS_CALL165)

@SP

AM=M-1

D=M

@R5

M=D

@60

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL166

D=A

@95

0;JMP

(RET_ADDRESS_CALL166)

@SP

AM=M-1

D=M

@R5

M=D

@61

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL167

D=A

@95

0;JMP

(RET_ADDRESS_CALL167)

@SP

AM=M-1

D=M

@R5

M=D

@62

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL168

D=A

@95

0;JMP

(RET_ADDRESS_CALL168)

@SP

AM=M-1

D=M

@R5

M=D

@64

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL169

D=A

@95

0;JMP

(RET_ADDRESS_CALL169)

@SP

AM=M-1

D=M

@R5

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL170

D=A

@95

0;JMP

(RET_ADDRESS_CALL170)

@SP

AM=M-1

D=M

@R5

M=D

@65

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL171

D=A

@95

0;JMP

(RET_ADDRESS_CALL171)

@SP

AM=M-1

D=M

@R5

M=D

@66

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL172

D=A

@95

0;JMP

(RET_ADDRESS_CALL172)

@SP

AM=M-1

D=M

@R5

M=D

@67

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL173

D=A

@95

0;JMP

(RET_ADDRESS_CALL173)

@SP

AM=M-1

D=M

@R5

M=D

@68

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL174

D=A

@95

0;JMP

(RET_ADDRESS_CALL174)

@SP

AM=M-1

D=M

@R5

M=D

@69

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL175

D=A

@95

0;JMP

(RET_ADDRESS_CALL175)

@SP

AM=M-1

D=M

@R5

M=D

@70

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL176

D=A

@95

0;JMP

(RET_ADDRESS_CALL176)

@SP

AM=M-1

D=M

@R5

M=D

@71

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@44

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL177

D=A

@95

0;JMP

(RET_ADDRESS_CALL177)

@SP

AM=M-1

D=M

@R5

M=D

@72

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL178

D=A

@95

0;JMP

(RET_ADDRESS_CALL178)

@SP

AM=M-1

D=M

@R5

M=D

@73

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL179

D=A

@95

0;JMP

(RET_ADDRESS_CALL179)

@SP

AM=M-1

D=M

@R5

M=D

@74

D=A

@SP

AM=M+1

A=A-1

M=D

@60

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@14

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL180

D=A

@95

0;JMP

(RET_ADDRESS_CALL180)

@SP

AM=M-1

D=M

@R5

M=D

@75

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL181

D=A

@95

0;JMP

(RET_ADDRESS_CALL181)

@SP

AM=M-1

D=M

@R5

M=D

@76

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL182

D=A

@95

0;JMP

(RET_ADDRESS_CALL182)

@SP

AM=M-1

D=M

@R5

M=D

@77

D=A

@SP

AM=M+1

A=A-1

M=D

@33

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL183

D=A

@95

0;JMP

(RET_ADDRESS_CALL183)

@SP

AM=M-1

D=M

@R5

M=D

@78

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@55

D=A

@SP

AM=M+1

A=A-1

M=D

@55

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL184

D=A

@95

0;JMP

(RET_ADDRESS_CALL184)

@SP

AM=M-1

D=M

@R5

M=D

@79

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL185

D=A

@95

0;JMP

(RET_ADDRESS_CALL185)

@SP

AM=M-1

D=M

@R5

M=D

@80

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL186

D=A

@95

0;JMP

(RET_ADDRESS_CALL186)

@SP

AM=M-1

D=M

@R5

M=D

@81

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@59

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL187

D=A

@95

0;JMP

(RET_ADDRESS_CALL187)

@SP

AM=M-1

D=M

@R5

M=D

@82

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL188

D=A

@95

0;JMP

(RET_ADDRESS_CALL188)

@SP

AM=M-1

D=M

@R5

M=D

@83

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL189

D=A

@95

0;JMP

(RET_ADDRESS_CALL189)

@SP

AM=M-1

D=M

@R5

M=D

@84

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@45

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL190

D=A

@95

0;JMP

(RET_ADDRESS_CALL190)

@SP

AM=M-1

D=M

@R5

M=D

@85

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL191

D=A

@95

0;JMP

(RET_ADDRESS_CALL191)

@SP

AM=M-1

D=M

@R5

M=D

@86

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL192

D=A

@95

0;JMP

(RET_ADDRESS_CALL192)

@SP

AM=M-1

D=M

@R5

M=D

@87

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL193

D=A

@95

0;JMP

(RET_ADDRESS_CALL193)

@SP

AM=M-1

D=M

@R5

M=D

@88

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL194

D=A

@95

0;JMP

(RET_ADDRESS_CALL194)

@SP

AM=M-1

D=M

@R5

M=D

@89

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL195

D=A

@95

0;JMP

(RET_ADDRESS_CALL195)

@SP

AM=M-1

D=M

@R5

M=D

@90

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@49

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@35

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL196

D=A

@95

0;JMP

(RET_ADDRESS_CALL196)

@SP

AM=M-1

D=M

@R5

M=D

@91

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL197

D=A

@95

0;JMP

(RET_ADDRESS_CALL197)

@SP

AM=M-1

D=M

@R5

M=D

@92

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=1

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL198

D=A

@95

0;JMP

(RET_ADDRESS_CALL198)

@SP

AM=M-1

D=M

@R5

M=D

@93

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL199

D=A

@95

0;JMP

(RET_ADDRESS_CALL199)

@SP

AM=M-1

D=M

@R5

M=D

@94

D=A

@SP

AM=M+1

A=A-1

M=D

@8

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL200

D=A

@95

0;JMP

(RET_ADDRESS_CALL200)

@SP

AM=M-1

D=M

@R5

M=D

@95

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL201

D=A

@95

0;JMP

(RET_ADDRESS_CALL201)

@SP

AM=M-1

D=M

@R5

M=D

@96

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL202

D=A

@95

0;JMP

(RET_ADDRESS_CALL202)

@SP

AM=M-1

D=M

@R5

M=D

@97

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@14

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL203

D=A

@95

0;JMP

(RET_ADDRESS_CALL203)

@SP

AM=M-1

D=M

@R5

M=D

@98

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL204

D=A

@95

0;JMP

(RET_ADDRESS_CALL204)

@SP

AM=M-1

D=M

@R5

M=D

@99

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL205

D=A

@95

0;JMP

(RET_ADDRESS_CALL205)

@SP

AM=M-1

D=M

@R5

M=D

@100

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@60

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL206

D=A

@95

0;JMP

(RET_ADDRESS_CALL206)

@SP

AM=M-1

D=M

@R5

M=D

@101

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL207

D=A

@95

0;JMP

(RET_ADDRESS_CALL207)

@SP

AM=M-1

D=M

@R5

M=D

@102

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@38

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL208

D=A

@95

0;JMP

(RET_ADDRESS_CALL208)

@SP

AM=M-1

D=M

@R5

M=D

@103

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@62

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL209

D=A

@95

0;JMP

(RET_ADDRESS_CALL209)

@SP

AM=M-1

D=M

@R5

M=D

@104

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@55

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL210

D=A

@95

0;JMP

(RET_ADDRESS_CALL210)

@SP

AM=M-1

D=M

@R5

M=D

@105

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@14

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL211

D=A

@95

0;JMP

(RET_ADDRESS_CALL211)

@SP

AM=M-1

D=M

@R5

M=D

@106

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@56

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL212

D=A

@95

0;JMP

(RET_ADDRESS_CALL212)

@SP

AM=M-1

D=M

@R5

M=D

@107

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL213

D=A

@95

0;JMP

(RET_ADDRESS_CALL213)

@SP

AM=M-1

D=M

@R5

M=D

@108

D=A

@SP

AM=M+1

A=A-1

M=D

@14

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL214

D=A

@95

0;JMP

(RET_ADDRESS_CALL214)

@SP

AM=M-1

D=M

@R5

M=D

@109

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@29

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@43

D=A

@SP

AM=M+1

A=A-1

M=D

@43

D=A

@SP

AM=M+1

A=A-1

M=D

@43

D=A

@SP

AM=M+1

A=A-1

M=D

@43

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL215

D=A

@95

0;JMP

(RET_ADDRESS_CALL215)

@SP

AM=M-1

D=M

@R5

M=D

@110

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@29

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL216

D=A

@95

0;JMP

(RET_ADDRESS_CALL216)

@SP

AM=M-1

D=M

@R5

M=D

@111

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL217

D=A

@95

0;JMP

(RET_ADDRESS_CALL217)

@SP

AM=M-1

D=M

@R5

M=D

@112

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL218

D=A

@95

0;JMP

(RET_ADDRESS_CALL218)

@SP

AM=M-1

D=M

@R5

M=D

@113

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@62

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL219

D=A

@95

0;JMP

(RET_ADDRESS_CALL219)

@SP

AM=M-1

D=M

@R5

M=D

@114

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@29

D=A

@SP

AM=M+1

A=A-1

M=D

@55

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL220

D=A

@95

0;JMP

(RET_ADDRESS_CALL220)

@SP

AM=M-1

D=M

@R5

M=D

@115

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL221

D=A

@95

0;JMP

(RET_ADDRESS_CALL221)

@SP

AM=M-1

D=M

@R5

M=D

@116

D=A

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@28

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL222

D=A

@95

0;JMP

(RET_ADDRESS_CALL222)

@SP

AM=M-1

D=M

@R5

M=D

@117

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@54

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL223

D=A

@95

0;JMP

(RET_ADDRESS_CALL223)

@SP

AM=M-1

D=M

@R5

M=D

@118

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL224

D=A

@95

0;JMP

(RET_ADDRESS_CALL224)

@SP

AM=M-1

D=M

@R5

M=D

@119

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL225

D=A

@95

0;JMP

(RET_ADDRESS_CALL225)

@SP

AM=M-1

D=M

@R5

M=D

@120

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@30

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL226

D=A

@95

0;JMP

(RET_ADDRESS_CALL226)

@SP

AM=M-1

D=M

@R5

M=D

@121

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@62

D=A

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@24

D=A

@SP

AM=M+1

A=A-1

M=D

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL227

D=A

@95

0;JMP

(RET_ADDRESS_CALL227)

@SP

AM=M-1

D=M

@R5

M=D

@122

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@27

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@51

D=A

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL228

D=A

@95

0;JMP

(RET_ADDRESS_CALL228)

@SP

AM=M-1

D=M

@R5

M=D

@123

D=A

@SP

AM=M+1

A=A-1

M=D

@56

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@56

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL229

D=A

@95

0;JMP

(RET_ADDRESS_CALL229)

@SP

AM=M-1

D=M

@R5

M=D

@124

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL230

D=A

@95

0;JMP

(RET_ADDRESS_CALL230)

@SP

AM=M-1

D=M

@R5

M=D

@125

D=A

@SP

AM=M+1

A=A-1

M=D

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@56

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL231

D=A

@95

0;JMP

(RET_ADDRESS_CALL231)

@SP

AM=M-1

D=M

@R5

M=D

@126

D=A

@SP

AM=M+1

A=A-1

M=D

@38

D=A

@SP

AM=M+1

A=A-1

M=D

@45

D=A

@SP

AM=M+1

A=A-1

M=D

@25

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@SP

M=M+1

A=M-1

M=0

@12

D=A

@R13

M=D

@output.create

D=A

@R14

M=D

@RET_ADDRESS_CALL232

D=A

@95

0;JMP

(RET_ADDRESS_CALL232)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.create)

@SP

AM=M+1

A=A-1

M=0

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL233

D=A

@95

0;JMP

(RET_ADDRESS_CALL233)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@output.5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=1

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@4

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@8

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@9

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@9

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@10

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

D=M

@11

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.createshiftedmap)

@4

D=A

(LOOP_output.createshiftedmap)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_output.createshiftedmap

D;JGT

@127

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL234

D=A

@95

0;JMP

(RET_ADDRESS_CALL234)

@SP

AM=M-1

D=M

@output.6

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

(output.createshiftedmap$while_exp0)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@127

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT27

D=A

@38

0;JMP

(RET_ADDRESS_LT27)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.createshiftedmap$while_end0

D;JNE

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@output.5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL235

D=A

@95

0;JMP

(RET_ADDRESS_CALL235)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@output.6

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

(output.createshiftedmap$while_exp1)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT28

D=A

@38

0;JMP

(RET_ADDRESS_LT28)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.createshiftedmap$while_end1

D;JNE

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@256

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL236

D=A

@95

0;JMP

(RET_ADDRESS_CALL236)

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@output.createshiftedmap$while_exp1

0;JMP

(output.createshiftedmap$while_end1)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ21

D=A

@6

0;JMP

(RET_ADDRESS_EQ21)

@SP

AM=M-1

D=M

@output.createshiftedmap$if_true0

D;JNE

@output.createshiftedmap$if_false0

0;JMP

(output.createshiftedmap$if_true0)

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@output.createshiftedmap$if_end0

0;JMP

(output.createshiftedmap$if_false0)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

(output.createshiftedmap$if_end0)

@output.createshiftedmap$while_exp0

0;JMP

(output.createshiftedmap$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.getmap)

@SP

AM=M+1

A=A-1

M=0

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT29

D=A

@38

0;JMP

(RET_ADDRESS_LT29)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@126

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT22

D=A

@22

0;JMP

(RET_ADDRESS_GT22)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@output.getmap$if_true0

D;JNE

@output.getmap$if_false0

0;JMP

(output.getmap$if_true0)

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@ARG

A=M

M=D

(output.getmap$if_false0)

@output.2

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.getmap$if_true1

D;JNE

@output.getmap$if_false1

0;JMP

(output.getmap$if_true1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@output.5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@output.getmap$if_end1

0;JMP

(output.getmap$if_false1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@output.6

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(output.getmap$if_end1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(output.drawchar)

@4

D=A

(LOOP_output.drawchar)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_output.drawchar

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.getmap

D=A

@R14

M=D

@RET_ADDRESS_CALL237

D=A

@95

0;JMP

(RET_ADDRESS_CALL237)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@output.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(output.drawchar$while_exp0)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@11

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT30

D=A

@38

0;JMP

(RET_ADDRESS_LT30)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.drawchar$while_end0

D;JNE

@output.2

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.drawchar$if_true0

D;JNE

@output.drawchar$if_false0

0;JMP

(output.drawchar$if_true0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@output.4

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@256

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@output.drawchar$if_end0

0;JMP

(output.drawchar$if_false0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@output.4

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@255

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

(output.drawchar$if_end0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@output.4

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@output.drawchar$while_exp0

0;JMP

(output.drawchar$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.movecursor)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT31

D=A

@38

0;JMP

(RET_ADDRESS_LT31)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@22

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT23

D=A

@22

0;JMP

(RET_ADDRESS_GT23)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT32

D=A

@38

0;JMP

(RET_ADDRESS_LT32)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@63

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT24

D=A

@22

0;JMP

(RET_ADDRESS_GT24)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@output.movecursor$if_true0

D;JNE

@output.movecursor$if_false0

0;JMP

(output.movecursor$if_true0)

@20

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL238

D=A

@95

0;JMP

(RET_ADDRESS_CALL238)

@SP

AM=M-1

D=M

@R5

M=D

(output.movecursor$if_false0)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL239

D=A

@95

0;JMP

(RET_ADDRESS_CALL239)

@SP

AM=M-1

D=M

@output.0

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@352

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL240

D=A

@95

0;JMP

(RET_ADDRESS_CALL240)

@SP

AM=M-1

D=M

A=A-1

M=D+M

@output.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@output.1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@output.0

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL241

D=A

@95

0;JMP

(RET_ADDRESS_CALL241)

@RET_ADDRESS_EQ22

D=A

@6

0;JMP

(RET_ADDRESS_EQ22)

@SP

AM=M-1

D=M

@output.2

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.drawchar

D=A

@R14

M=D

@RET_ADDRESS_CALL242

D=A

@95

0;JMP

(RET_ADDRESS_CALL242)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.printchar)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@0

D=A

@R13

M=D

@string.newline

D=A

@R14

M=D

@RET_ADDRESS_CALL243

D=A

@95

0;JMP

(RET_ADDRESS_CALL243)

@RET_ADDRESS_EQ23

D=A

@6

0;JMP

(RET_ADDRESS_EQ23)

@SP

AM=M-1

D=M

@output.printchar$if_true0

D;JNE

@output.printchar$if_false0

0;JMP

(output.printchar$if_true0)

@0

D=A

@R13

M=D

@output.println

D=A

@R14

M=D

@RET_ADDRESS_CALL244

D=A

@95

0;JMP

(RET_ADDRESS_CALL244)

@SP

AM=M-1

D=M

@R5

M=D

@output.printchar$if_end0

0;JMP

(output.printchar$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@0

D=A

@R13

M=D

@string.backspace

D=A

@R14

M=D

@RET_ADDRESS_CALL245

D=A

@95

0;JMP

(RET_ADDRESS_CALL245)

@RET_ADDRESS_EQ24

D=A

@6

0;JMP

(RET_ADDRESS_EQ24)

@SP

AM=M-1

D=M

@output.printchar$if_true1

D;JNE

@output.printchar$if_false1

0;JMP

(output.printchar$if_true1)

@0

D=A

@R13

M=D

@output.backspace

D=A

@R14

M=D

@RET_ADDRESS_CALL246

D=A

@95

0;JMP

(RET_ADDRESS_CALL246)

@SP

AM=M-1

D=M

@R5

M=D

@output.printchar$if_end1

0;JMP

(output.printchar$if_false1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.drawchar

D=A

@R14

M=D

@RET_ADDRESS_CALL247

D=A

@95

0;JMP

(RET_ADDRESS_CALL247)

@SP

AM=M-1

D=M

@R5

M=D

@output.2

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.printchar$if_true2

D;JNE

@output.printchar$if_false2

0;JMP

(output.printchar$if_true2)

@output.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@output.0

M=D

@output.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@output.1

M=D

(output.printchar$if_false2)

@output.0

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ25

D=A

@6

0;JMP

(RET_ADDRESS_EQ25)

@SP

AM=M-1

D=M

@output.printchar$if_true3

D;JNE

@output.printchar$if_false3

0;JMP

(output.printchar$if_true3)

@0

D=A

@R13

M=D

@output.println

D=A

@R14

M=D

@RET_ADDRESS_CALL248

D=A

@95

0;JMP

(RET_ADDRESS_CALL248)

@SP

AM=M-1

D=M

@R5

M=D

@output.printchar$if_end3

0;JMP

(output.printchar$if_false3)

@output.2

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.2

M=D

(output.printchar$if_end3)

(output.printchar$if_end1)

(output.printchar$if_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.printstring)

@SP

A=M

M=0

AD=A+1

M=0

@SP

M=D+1

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.length

D=A

@R14

M=D

@RET_ADDRESS_CALL249

D=A

@95

0;JMP

(RET_ADDRESS_CALL249)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

(output.printstring$while_exp0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT33

D=A

@38

0;JMP

(RET_ADDRESS_LT33)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.printstring$while_end0

D;JNE

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.charat

D=A

@R14

M=D

@RET_ADDRESS_CALL250

D=A

@95

0;JMP

(RET_ADDRESS_CALL250)

@1

D=A

@R13

M=D

@output.printchar

D=A

@R14

M=D

@RET_ADDRESS_CALL251

D=A

@95

0;JMP

(RET_ADDRESS_CALL251)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@output.printstring$while_exp0

0;JMP

(output.printstring$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.printint)

@output.3

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.setint

D=A

@R14

M=D

@RET_ADDRESS_CALL252

D=A

@95

0;JMP

(RET_ADDRESS_CALL252)

@SP

AM=M-1

D=M

@R5

M=D

@output.3

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.printstring

D=A

@R14

M=D

@RET_ADDRESS_CALL253

D=A

@95

0;JMP

(RET_ADDRESS_CALL253)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.println)

@output.1

D=M

@SP

AM=M+1

A=A-1

M=D

@352

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@output.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@output.1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@output.0

M=D

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.2

M=D

@output.1

D=M

@SP

AM=M+1

A=A-1

M=D

@8128

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ26

D=A

@6

0;JMP

(RET_ADDRESS_EQ26)

@SP

AM=M-1

D=M

@output.println$if_true0

D;JNE

@output.println$if_false0

0;JMP

(output.println$if_true0)

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.1

M=D

(output.println$if_false0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(output.backspace)

@output.2

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.backspace$if_true0

D;JNE

@output.backspace$if_false0

0;JMP

(output.backspace$if_true0)

@output.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT25

D=A

@22

0;JMP

(RET_ADDRESS_GT25)

@SP

AM=M-1

D=M

@output.backspace$if_true1

D;JNE

@output.backspace$if_false1

0;JMP

(output.backspace$if_true1)

@output.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@output.0

M=D

@output.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@output.1

M=D

@output.backspace$if_end1

0;JMP

(output.backspace$if_false1)

@31

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.0

M=D

@output.1

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ27

D=A

@6

0;JMP

(RET_ADDRESS_EQ27)

@SP

AM=M-1

D=M

@output.backspace$if_true2

D;JNE

@output.backspace$if_false2

0;JMP

(output.backspace$if_true2)

@8128

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@output.1

M=D

(output.backspace$if_false2)

@output.1

D=M

@SP

AM=M+1

A=A-1

M=D

@321

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@output.1

M=D

(output.backspace$if_end1)

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@output.2

M=D

@output.backspace$if_end0

0;JMP

(output.backspace$if_false0)

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@output.2

M=D

(output.backspace$if_end0)

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.drawchar

D=A

@R14

M=D

@RET_ADDRESS_CALL254

D=A

@95

0;JMP

(RET_ADDRESS_CALL254)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.init)

@SP

AM=M+1

A=A-1

M=0

@16384

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@screen.1

M=D

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.2

M=D

@17

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL255

D=A

@95

0;JMP

(RET_ADDRESS_CALL255)

@SP

AM=M-1

D=M

@screen.0

M=D

@SP

M=M+1

A=M-1

M=0

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

(screen.init$while_exp0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT34

D=A

@38

0;JMP

(RET_ADDRESS_LT34)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.init$while_end0

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@screen.init$while_exp0

0;JMP

(screen.init$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.clearscreen)

@SP

AM=M+1

A=A-1

M=0

(screen.clearscreen$while_exp0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@8192

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT35

D=A

@38

0;JMP

(RET_ADDRESS_LT35)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.clearscreen$while_end0

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@screen.clearscreen$while_exp0

0;JMP

(screen.clearscreen$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.updatelocation)

@screen.2

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@screen.updatelocation$if_true0

D;JNE

@screen.updatelocation$if_false0

0;JMP

(screen.updatelocation$if_true0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@screen.updatelocation$if_end0

0;JMP

(screen.updatelocation$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

(screen.updatelocation$if_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.setcolor)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@screen.2

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.drawpixel)

@3

D=A

(LOOP_screen.drawpixel)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_screen.drawpixel

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT36

D=A

@38

0;JMP

(RET_ADDRESS_LT36)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT26

D=A

@22

0;JMP

(RET_ADDRESS_GT26)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT37

D=A

@38

0;JMP

(RET_ADDRESS_LT37)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@255

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT27

D=A

@22

0;JMP

(RET_ADDRESS_GT27)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@screen.drawpixel$if_true0

D;JNE

@screen.drawpixel$if_false0

0;JMP

(screen.drawpixel$if_true0)

@7

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL256

D=A

@95

0;JMP

(RET_ADDRESS_CALL256)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawpixel$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL257

D=A

@95

0;JMP

(RET_ADDRESS_CALL257)

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL258

D=A

@95

0;JMP

(RET_ADDRESS_CALL258)

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL259

D=A

@95

0;JMP

(RET_ADDRESS_CALL259)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL260

D=A

@95

0;JMP

(RET_ADDRESS_CALL260)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.drawconditional)

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@screen.drawconditional$if_true0

D;JNE

@screen.drawconditional$if_false0

0;JMP

(screen.drawconditional$if_true0)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@screen.drawpixel

D=A

@R14

M=D

@RET_ADDRESS_CALL261

D=A

@95

0;JMP

(RET_ADDRESS_CALL261)

@SP

AM=M-1

D=M

@R5

M=D

@screen.drawconditional$if_end0

0;JMP

(screen.drawconditional$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@screen.drawpixel

D=A

@R14

M=D

@RET_ADDRESS_CALL262

D=A

@95

0;JMP

(RET_ADDRESS_CALL262)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawconditional$if_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.drawline)

@11

D=A

(LOOP_screen.drawline)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_screen.drawline

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT38

D=A

@38

0;JMP

(RET_ADDRESS_LT38)

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT28

D=A

@22

0;JMP

(RET_ADDRESS_GT28)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT39

D=A

@38

0;JMP

(RET_ADDRESS_LT39)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@255

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT29

D=A

@22

0;JMP

(RET_ADDRESS_GT29)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@screen.drawline$if_true0

D;JNE

@screen.drawline$if_false0

0;JMP

(screen.drawline$if_true0)

@8

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL263

D=A

@95

0;JMP

(RET_ADDRESS_CALL263)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawline$if_false0)

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL264

D=A

@95

0;JMP

(RET_ADDRESS_CALL264)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@1

D=A

@R13

M=D

@math.abs

D=A

@R14

M=D

@RET_ADDRESS_CALL265

D=A

@95

0;JMP

(RET_ADDRESS_CALL265)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT40

D=A

@38

0;JMP

(RET_ADDRESS_LT40)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT41

D=A

@38

0;JMP

(RET_ADDRESS_LT41)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

M=!M

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT42

D=A

@38

0;JMP

(RET_ADDRESS_LT42)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@screen.drawline$if_true1

D;JNE

@screen.drawline$if_false1

0;JMP

(screen.drawline$if_true1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M+1

A=A+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M+1

A=A+1

A=A+1

M=D

(screen.drawline$if_false1)

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@screen.drawline$if_true2

D;JNE

@screen.drawline$if_false2

0;JMP

(screen.drawline$if_true2)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@8

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT30

D=A

@22

0;JMP

(RET_ADDRESS_GT30)

@LCL

D=M

@7

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@screen.drawline$if_end2

0;JMP

(screen.drawline$if_false2)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@8

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT31

D=A

@22

0;JMP

(RET_ADDRESS_GT31)

@LCL

D=M

@7

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

(screen.drawline$if_end2)

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL266

D=A

@95

0;JMP

(RET_ADDRESS_CALL266)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL267

D=A

@95

0;JMP

(RET_ADDRESS_CALL267)

@LCL

D=M

@9

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL268

D=A

@95

0;JMP

(RET_ADDRESS_CALL268)

@LCL

D=M

@10

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@R13

M=D

@screen.drawconditional

D=A

@R14

M=D

@RET_ADDRESS_CALL269

D=A

@95

0;JMP

(RET_ADDRESS_CALL269)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawline$while_exp0)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT43

D=A

@38

0;JMP

(RET_ADDRESS_LT43)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.drawline$while_end0

D;JNE

@LCL

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT44

D=A

@38

0;JMP

(RET_ADDRESS_LT44)

@SP

AM=M-1

D=M

@screen.drawline$if_true3

D;JNE

@screen.drawline$if_false3

0;JMP

(screen.drawline$if_true3)

@LCL

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@9

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@screen.drawline$if_end3

0;JMP

(screen.drawline$if_false3)

@LCL

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@10

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@LCL

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@screen.drawline$if_true4

D;JNE

@screen.drawline$if_false4

0;JMP

(screen.drawline$if_true4)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@screen.drawline$if_end4

0;JMP

(screen.drawline$if_false4)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(screen.drawline$if_end4)

(screen.drawline$if_end3)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@3

D=A

@R13

M=D

@screen.drawconditional

D=A

@R14

M=D

@RET_ADDRESS_CALL270

D=A

@95

0;JMP

(RET_ADDRESS_CALL270)

@SP

AM=M-1

D=M

@R5

M=D

@screen.drawline$while_exp0

0;JMP

(screen.drawline$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.drawrectangle)

@9

D=A

(LOOP_screen.drawrectangle)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_screen.drawrectangle

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT32

D=A

@22

0;JMP

(RET_ADDRESS_GT32)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT33

D=A

@22

0;JMP

(RET_ADDRESS_GT33)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT45

D=A

@38

0;JMP

(RET_ADDRESS_LT45)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT34

D=A

@22

0;JMP

(RET_ADDRESS_GT34)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT46

D=A

@38

0;JMP

(RET_ADDRESS_LT46)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@255

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT35

D=A

@22

0;JMP

(RET_ADDRESS_GT35)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@screen.drawrectangle$if_true0

D;JNE

@screen.drawrectangle$if_false0

0;JMP

(screen.drawrectangle$if_true0)

@9

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL271

D=A

@95

0;JMP

(RET_ADDRESS_CALL271)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawrectangle$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL272

D=A

@95

0;JMP

(RET_ADDRESS_CALL272)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL273

D=A

@95

0;JMP

(RET_ADDRESS_CALL273)

@SP

AM=M-1

D=M

A=A-1

M=M-D

@LCL

D=M

@7

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL274

D=A

@95

0;JMP

(RET_ADDRESS_CALL274)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL275

D=A

@95

0;JMP

(RET_ADDRESS_CALL275)

@SP

AM=M-1

D=M

A=A-1

M=M-D

@LCL

D=M

@8

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@LCL

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@LCL

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL276

D=A

@95

0;JMP

(RET_ADDRESS_CALL276)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

(screen.drawrectangle$while_exp0)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT36

D=A

@22

0;JMP

(RET_ADDRESS_GT36)

@SP

A=M-1

M=!M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.drawrectangle$while_end0

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ28

D=A

@6

0;JMP

(RET_ADDRESS_EQ28)

@SP

AM=M-1

D=M

@screen.drawrectangle$if_true1

D;JNE

@screen.drawrectangle$if_false1

0;JMP

(screen.drawrectangle$if_true1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D&M

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL277

D=A

@95

0;JMP

(RET_ADDRESS_CALL277)

@SP

AM=M-1

D=M

@R5

M=D

@screen.drawrectangle$if_end1

0;JMP

(screen.drawrectangle$if_false1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL278

D=A

@95

0;JMP

(RET_ADDRESS_CALL278)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(screen.drawrectangle$while_exp1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT47

D=A

@38

0;JMP

(RET_ADDRESS_LT47)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.drawrectangle$while_end1

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL279

D=A

@95

0;JMP

(RET_ADDRESS_CALL279)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@screen.drawrectangle$while_exp1

0;JMP

(screen.drawrectangle$while_end1)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL280

D=A

@95

0;JMP

(RET_ADDRESS_CALL280)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawrectangle$if_end1)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@screen.drawrectangle$while_exp0

0;JMP

(screen.drawrectangle$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.drawhorizontal)

@11

D=A

(LOOP_screen.drawhorizontal)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_screen.drawhorizontal

D;JGT

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.min

D=A

@R14

M=D

@RET_ADDRESS_CALL281

D=A

@95

0;JMP

(RET_ADDRESS_CALL281)

@LCL

D=M

@7

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.max

D=A

@R14

M=D

@RET_ADDRESS_CALL282

D=A

@95

0;JMP

(RET_ADDRESS_CALL282)

@LCL

D=M

@8

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@RET_ADDRESS_GT37

D=A

@22

0;JMP

(RET_ADDRESS_GT37)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@256

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT48

D=A

@38

0;JMP

(RET_ADDRESS_LT48)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@LCL

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@512

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT49

D=A

@38

0;JMP

(RET_ADDRESS_LT49)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@LCL

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@RET_ADDRESS_GT38

D=A

@22

0;JMP

(RET_ADDRESS_GT38)

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

AM=M-1

D=M

@screen.drawhorizontal$if_true0

D;JNE

@screen.drawhorizontal$if_false0

0;JMP

(screen.drawhorizontal$if_true0)

@LCL

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@2

D=A

@R13

M=D

@math.max

D=A

@R14

M=D

@RET_ADDRESS_CALL283

D=A

@95

0;JMP

(RET_ADDRESS_CALL283)

@LCL

D=M

@7

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@LCL

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.min

D=A

@R14

M=D

@RET_ADDRESS_CALL284

D=A

@95

0;JMP

(RET_ADDRESS_CALL284)

@LCL

D=M

@8

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@LCL

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL285

D=A

@95

0;JMP

(RET_ADDRESS_CALL285)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

D=M

@7

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL286

D=A

@95

0;JMP

(RET_ADDRESS_CALL286)

@SP

AM=M-1

D=M

A=A-1

M=M-D

@LCL

D=M

@9

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@LCL

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL287

D=A

@95

0;JMP

(RET_ADDRESS_CALL287)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@LCL

D=M

@8

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL288

D=A

@95

0;JMP

(RET_ADDRESS_CALL288)

@SP

AM=M-1

D=M

A=A-1

M=M-D

@LCL

D=M

@10

D=D+A

@R13

M=D

@SP

AM=M-1

D=M

@R13

A=M

M=D

@LCL

D=M

@9

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@LCL

D=M

@10

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@screen.0

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@32

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL289

D=A

@95

0;JMP

(RET_ADDRESS_CALL289)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

A=A+1

A=A+1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@LCL

D=M

@6

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ29

D=A

@6

0;JMP

(RET_ADDRESS_EQ29)

@SP

AM=M-1

D=M

@screen.drawhorizontal$if_true1

D;JNE

@screen.drawhorizontal$if_false1

0;JMP

(screen.drawhorizontal$if_true1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D&M

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL290

D=A

@95

0;JMP

(RET_ADDRESS_CALL290)

@SP

AM=M-1

D=M

@R5

M=D

@screen.drawhorizontal$if_end1

0;JMP

(screen.drawhorizontal$if_false1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@5

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL291

D=A

@95

0;JMP

(RET_ADDRESS_CALL291)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(screen.drawhorizontal$while_exp0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT50

D=A

@38

0;JMP

(RET_ADDRESS_LT50)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.drawhorizontal$while_end0

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

A=M-1

D=!M

M=D+1

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL292

D=A

@95

0;JMP

(RET_ADDRESS_CALL292)

@SP

AM=M-1

D=M

@R5

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@screen.drawhorizontal$while_exp0

0;JMP

(screen.drawhorizontal$while_end0)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@screen.updatelocation

D=A

@R14

M=D

@RET_ADDRESS_CALL293

D=A

@95

0;JMP

(RET_ADDRESS_CALL293)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawhorizontal$if_end1)

(screen.drawhorizontal$if_false0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.drawsymetric)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@3

D=A

@R13

M=D

@screen.drawhorizontal

D=A

@R14

M=D

@RET_ADDRESS_CALL294

D=A

@95

0;JMP

(RET_ADDRESS_CALL294)

@SP

AM=M-1

D=M

@R5

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@3

D=A

@R13

M=D

@screen.drawhorizontal

D=A

@R14

M=D

@RET_ADDRESS_CALL295

D=A

@95

0;JMP

(RET_ADDRESS_CALL295)

@SP

AM=M-1

D=M

@R5

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@3

D=A

@R13

M=D

@screen.drawhorizontal

D=A

@R14

M=D

@RET_ADDRESS_CALL296

D=A

@95

0;JMP

(RET_ADDRESS_CALL296)

@SP

AM=M-1

D=M

@R5

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@3

D=A

@R13

M=D

@screen.drawhorizontal

D=A

@R14

M=D

@RET_ADDRESS_CALL297

D=A

@95

0;JMP

(RET_ADDRESS_CALL297)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(screen.drawcircle)

@3

D=A

(LOOP_screen.drawcircle)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_screen.drawcircle

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT51

D=A

@38

0;JMP

(RET_ADDRESS_LT51)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT39

D=A

@22

0;JMP

(RET_ADDRESS_GT39)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT52

D=A

@38

0;JMP

(RET_ADDRESS_LT52)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@255

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT40

D=A

@22

0;JMP

(RET_ADDRESS_GT40)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@screen.drawcircle$if_true0

D;JNE

@screen.drawcircle$if_false0

0;JMP

(screen.drawcircle$if_true0)

@12

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL298

D=A

@95

0;JMP

(RET_ADDRESS_CALL298)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawcircle$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT53

D=A

@38

0;JMP

(RET_ADDRESS_LT53)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@511

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT41

D=A

@22

0;JMP

(RET_ADDRESS_GT41)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT54

D=A

@38

0;JMP

(RET_ADDRESS_LT54)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@255

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT42

D=A

@22

0;JMP

(RET_ADDRESS_GT42)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@screen.drawcircle$if_true1

D;JNE

@screen.drawcircle$if_false1

0;JMP

(screen.drawcircle$if_true1)

@13

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL299

D=A

@95

0;JMP

(RET_ADDRESS_CALL299)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawcircle$if_false1)

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@SP

M=M+1

A=M-1

M=1

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@R13

M=D

@screen.drawsymetric

D=A

@R14

M=D

@RET_ADDRESS_CALL300

D=A

@95

0;JMP

(RET_ADDRESS_CALL300)

@SP

AM=M-1

D=M

@R5

M=D

(screen.drawcircle$while_exp0)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT43

D=A

@22

0;JMP

(RET_ADDRESS_GT43)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@screen.drawcircle$while_end0

D;JNE

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT55

D=A

@38

0;JMP

(RET_ADDRESS_LT55)

@SP

AM=M-1

D=M

@screen.drawcircle$if_true2

D;JNE

@screen.drawcircle$if_false2

0;JMP

(screen.drawcircle$if_true2)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL301

D=A

@95

0;JMP

(RET_ADDRESS_CALL301)

@SP

AM=M-1

D=M

A=A-1

M=D+M

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@screen.drawcircle$if_end2

0;JMP

(screen.drawcircle$if_false2)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL302

D=A

@95

0;JMP

(RET_ADDRESS_CALL302)

@SP

AM=M-1

D=M

A=A-1

M=D+M

@5

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

(screen.drawcircle$if_end2)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@4

D=A

@R13

M=D

@screen.drawsymetric

D=A

@R14

M=D

@RET_ADDRESS_CALL303

D=A

@95

0;JMP

(RET_ADDRESS_CALL303)

@SP

AM=M-1

D=M

@R5

M=D

@screen.drawcircle$while_exp0

0;JMP

(screen.drawcircle$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(string.new)

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.alloc

D=A

@R14

M=D

@RET_ADDRESS_CALL304

D=A

@95

0;JMP

(RET_ADDRESS_CALL304)

@SP

AM=M-1

D=M

@THIS

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT56

D=A

@38

0;JMP

(RET_ADDRESS_LT56)

@SP

AM=M-1

D=M

@string.new$if_true0

D;JNE

@string.new$if_false0

0;JMP

(string.new$if_true0)

@14

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL305

D=A

@95

0;JMP

(RET_ADDRESS_CALL305)

@SP

AM=M-1

D=M

@R5

M=D

(string.new$if_false0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT44

D=A

@22

0;JMP

(RET_ADDRESS_GT44)

@SP

AM=M-1

D=M

@string.new$if_true1

D;JNE

@string.new$if_false1

0;JMP

(string.new$if_true1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL306

D=A

@95

0;JMP

(RET_ADDRESS_CALL306)

@SP

AM=M-1

D=M

@THIS

A=M+1

M=D

(string.new$if_false1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(string.dispose)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT45

D=A

@22

0;JMP

(RET_ADDRESS_GT45)

@SP

AM=M-1

D=M

@string.dispose$if_true0

D;JNE

@string.dispose$if_false0

0;JMP

(string.dispose$if_true0)

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.dispose

D=A

@R14

M=D

@RET_ADDRESS_CALL307

D=A

@95

0;JMP

(RET_ADDRESS_CALL307)

@SP

AM=M-1

D=M

@R5

M=D

(string.dispose$if_false0)

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@memory.dealloc

D=A

@R14

M=D

@RET_ADDRESS_CALL308

D=A

@95

0;JMP

(RET_ADDRESS_CALL308)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(string.length)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(string.charat)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT57

D=A

@38

0;JMP

(RET_ADDRESS_LT57)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT46

D=A

@22

0;JMP

(RET_ADDRESS_GT46)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ30

D=A

@6

0;JMP

(RET_ADDRESS_EQ30)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@string.charat$if_true0

D;JNE

@string.charat$if_false0

0;JMP

(string.charat$if_true0)

@15

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL309

D=A

@95

0;JMP

(RET_ADDRESS_CALL309)

@SP

AM=M-1

D=M

@R5

M=D

(string.charat$if_false0)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(string.setcharat)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT58

D=A

@38

0;JMP

(RET_ADDRESS_LT58)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT47

D=A

@22

0;JMP

(RET_ADDRESS_GT47)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ31

D=A

@6

0;JMP

(RET_ADDRESS_EQ31)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

AM=M-1

D=M

@string.setcharat$if_true0

D;JNE

@string.setcharat$if_false0

0;JMP

(string.setcharat$if_true0)

@16

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL310

D=A

@95

0;JMP

(RET_ADDRESS_CALL310)

@SP

AM=M-1

D=M

@R5

M=D

(string.setcharat$if_false0)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(string.appendchar)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ32

D=A

@6

0;JMP

(RET_ADDRESS_EQ32)

@SP

AM=M-1

D=M

@string.appendchar$if_true0

D;JNE

@string.appendchar$if_false0

0;JMP

(string.appendchar$if_true0)

@17

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL311

D=A

@95

0;JMP

(RET_ADDRESS_CALL311)

@SP

AM=M-1

D=M

@R5

M=D

(string.appendchar$if_false0)

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@THIS

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(string.eraselastchar)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ33

D=A

@6

0;JMP

(RET_ADDRESS_EQ33)

@SP

AM=M-1

D=M

@string.eraselastchar$if_true0

D;JNE

@string.eraselastchar$if_false0

0;JMP

(string.eraselastchar$if_true0)

@18

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL312

D=A

@95

0;JMP

(RET_ADDRESS_CALL312)

@SP

AM=M-1

D=M

@R5

M=D

(string.eraselastchar$if_false0)

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(string.intvalue)

@5

D=A

(LOOP_string.intvalue)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_string.intvalue

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ34

D=A

@6

0;JMP

(RET_ADDRESS_EQ34)

@SP

AM=M-1

D=M

@string.intvalue$if_true0

D;JNE

@string.intvalue$if_false0

0;JMP

(string.intvalue$if_true0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(string.intvalue$if_false0)

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=0

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@45

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_EQ35

D=A

@6

0;JMP

(RET_ADDRESS_EQ35)

@SP

AM=M-1

D=M

@string.intvalue$if_true1

D;JNE

@string.intvalue$if_false1

0;JMP

(string.intvalue$if_true1)

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

A=A+1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(string.intvalue$if_false1)

(string.intvalue$while_exp0)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT59

D=A

@38

0;JMP

(RET_ADDRESS_LT59)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D&M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@string.intvalue$while_end0

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT60

D=A

@38

0;JMP

(RET_ADDRESS_LT60)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@9

D=A

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_GT48

D=A

@22

0;JMP

(RET_ADDRESS_GT48)

@SP

AM=M-1

D=M

A=A-1

M=D|M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@string.intvalue$if_true2

D;JNE

@string.intvalue$if_false2

0;JMP

(string.intvalue$if_true2)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL313

D=A

@95

0;JMP

(RET_ADDRESS_CALL313)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(string.intvalue$if_false2)

@string.intvalue$while_exp0

0;JMP

(string.intvalue$while_end0)

@LCL

D=M

@4

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@string.intvalue$if_true3

D;JNE

@string.intvalue$if_false3

0;JMP

(string.intvalue$if_true3)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

(string.intvalue$if_false3)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(string.setint)

@4

D=A

(LOOP_string.setint)

D=D-1

@SP

AM=M+1

A=A-1

M=0

@LOOP_string.setint

D;JGT

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THIS

M=D

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ36

D=A

@6

0;JMP

(RET_ADDRESS_EQ36)

@SP

AM=M-1

D=M

@string.setint$if_true0

D;JNE

@string.setint$if_false0

0;JMP

(string.setint$if_true0)

@19

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL314

D=A

@95

0;JMP

(RET_ADDRESS_CALL314)

@SP

AM=M-1

D=M

@R5

M=D

(string.setint$if_false0)

@6

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.new

D=A

@R14

M=D

@RET_ADDRESS_CALL315

D=A

@95

0;JMP

(RET_ADDRESS_CALL315)

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT61

D=A

@38

0;JMP

(RET_ADDRESS_LT61)

@SP

AM=M-1

D=M

@string.setint$if_true1

D;JNE

@string.setint$if_false1

0;JMP

(string.setint$if_true1)

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@LCL

A=M+1

A=A+1

A=A+1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

A=M-1

D=!M

M=D+1

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

(string.setint$if_false1)

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

(string.setint$while_exp0)

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT49

D=A

@22

0;JMP

(RET_ADDRESS_GT49)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@string.setint$while_end0

D;JNE

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.divide

D=A

@R14

M=D

@RET_ADDRESS_CALL316

D=A

@95

0;JMP

(RET_ADDRESS_CALL316)

@SP

AM=M-1

D=M

@LCL

A=M+1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@ARG

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@10

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@math.multiply

D=A

@R14

M=D

@RET_ADDRESS_CALL317

D=A

@95

0;JMP

(RET_ADDRESS_CALL317)

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@LCL

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@ARG

A=M+1

M=D

@string.setint$while_exp0

0;JMP

(string.setint$while_end0)

@LCL

D=M

@3

A=D+A

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@string.setint$if_true2

D;JNE

@string.setint$if_false2

0;JMP

(string.setint$if_true2)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@45

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(string.setint$if_false2)

@THIS

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT62

D=A

@38

0;JMP

(RET_ADDRESS_LT62)

@SP

AM=M-1

D=M

@string.setint$if_true3

D;JNE

@string.setint$if_false3

0;JMP

(string.setint$if_true3)

@19

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL318

D=A

@95

0;JMP

(RET_ADDRESS_CALL318)

@SP

AM=M-1

D=M

@R5

M=D

(string.setint$if_false3)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_EQ37

D=A

@6

0;JMP

(RET_ADDRESS_EQ37)

@SP

AM=M-1

D=M

@string.setint$if_true4

D;JNE

@string.setint$if_false4

0;JMP

(string.setint$if_true4)

@SP

M=M+1

A=M-1

M=0

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@48

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@string.setint$if_end4

0;JMP

(string.setint$if_false4)

@SP

M=M+1

A=M-1

M=0

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

(string.setint$while_exp1)

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@RET_ADDRESS_LT63

D=A

@38

0;JMP

(RET_ADDRESS_LT63)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@string.setint$while_end1

D;JNE

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

A=A-1

M=M-D

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THAT

M=D

@THAT

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@R5

M=D

@SP

AM=M-1

D=M

@THAT

M=D

@R5

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@THAT

A=M

M=D

@THIS

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=D+M

@SP

AM=M-1

D=M

@THIS

A=M+1

A=A+1

M=D

@string.setint$while_exp1

0;JMP

(string.setint$while_end1)

(string.setint$if_end4)

@LCL

A=M+1

A=A+1

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@array.dispose

D=A

@R14

M=D

@RET_ADDRESS_CALL319

D=A

@95

0;JMP

(RET_ADDRESS_CALL319)

@SP

AM=M-1

D=M

@R5

M=D

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(string.newline)

@128

D=A

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(string.backspace)

@129

D=A

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(string.doublequote)

@34

D=A

@SP

AM=M+1

A=A-1

M=D

@54

0;JMP

(sys.init)

@0

D=A

@R13

M=D

@memory.init

D=A

@R14

M=D

@RET_ADDRESS_CALL320

D=A

@95

0;JMP

(RET_ADDRESS_CALL320)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@math.init

D=A

@R14

M=D

@RET_ADDRESS_CALL321

D=A

@95

0;JMP

(RET_ADDRESS_CALL321)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@screen.init

D=A

@R14

M=D

@RET_ADDRESS_CALL322

D=A

@95

0;JMP

(RET_ADDRESS_CALL322)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@output.init

D=A

@R14

M=D

@RET_ADDRESS_CALL323

D=A

@95

0;JMP

(RET_ADDRESS_CALL323)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@keyboard.init

D=A

@R14

M=D

@RET_ADDRESS_CALL324

D=A

@95

0;JMP

(RET_ADDRESS_CALL324)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@main.main

D=A

@R14

M=D

@RET_ADDRESS_CALL325

D=A

@95

0;JMP

(RET_ADDRESS_CALL325)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@sys.halt

D=A

@R14

M=D

@RET_ADDRESS_CALL326

D=A

@95

0;JMP

(RET_ADDRESS_CALL326)

@SP

AM=M-1

D=M

@R5

M=D

(sys.halt)

(sys.halt$while_exp0)

@SP

M=M+1

A=M-1

M=0

@SP

A=M-1

M=!M

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@sys.halt$while_end0

D;JNE

@sys.halt$while_exp0

0;JMP

(sys.halt$while_end0)

(sys.wait)

@SP

AM=M+1

A=A-1

M=0

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_LT64

D=A

@38

0;JMP

(RET_ADDRESS_LT64)

@SP

AM=M-1

D=M

@sys.wait$if_true0

D;JNE

@sys.wait$if_false0

0;JMP

(sys.wait$if_true0)

@SP

M=M+1

A=M-1

M=1

@1

D=A

@R13

M=D

@sys.error

D=A

@R14

M=D

@RET_ADDRESS_CALL327

D=A

@95

0;JMP

(RET_ADDRESS_CALL327)

@SP

AM=M-1

D=M

@R5

M=D

(sys.wait$if_false0)

(sys.wait$while_exp0)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT50

D=A

@22

0;JMP

(RET_ADDRESS_GT50)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@sys.wait$while_end0

D;JNE

@50

D=A

@SP

AM=M+1

A=A-1

M=D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

(sys.wait$while_exp1)

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=0

@RET_ADDRESS_GT51

D=A

@22

0;JMP

(RET_ADDRESS_GT51)

@SP

A=M-1

M=!M

@SP

AM=M-1

D=M

@sys.wait$while_end1

D;JNE

@LCL

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@LCL

A=M

M=D

@sys.wait$while_exp1

0;JMP

(sys.wait$while_end1)

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@SP

M=M+1

A=M-1

M=1

@SP

AM=M-1

D=M

A=A-1

M=M-D

@SP

AM=M-1

D=M

@ARG

A=M

M=D

@sys.wait$while_exp0

0;JMP

(sys.wait$while_end0)

@SP

M=M+1

A=M-1

M=0

@54

0;JMP

(sys.error)

@3

D=A

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@string.new

D=A

@R14

M=D

@RET_ADDRESS_CALL328

D=A

@95

0;JMP

(RET_ADDRESS_CALL328)

@69

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL329

D=A

@95

0;JMP

(RET_ADDRESS_CALL329)

@82

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL330

D=A

@95

0;JMP

(RET_ADDRESS_CALL330)

@82

D=A

@SP

AM=M+1

A=A-1

M=D

@2

D=A

@R13

M=D

@string.appendchar

D=A

@R14

M=D

@RET_ADDRESS_CALL331

D=A

@95

0;JMP

(RET_ADDRESS_CALL331)

@1

D=A

@R13

M=D

@output.printstring

D=A

@R14

M=D

@RET_ADDRESS_CALL332

D=A

@95

0;JMP

(RET_ADDRESS_CALL332)

@SP

AM=M-1

D=M

@R5

M=D

@ARG

A=M

D=M

@SP

AM=M+1

A=A-1

M=D

@1

D=A

@R13

M=D

@output.printint

D=A

@R14

M=D

@RET_ADDRESS_CALL333

D=A

@95

0;JMP

(RET_ADDRESS_CALL333)

@SP

AM=M-1

D=M

@R5

M=D

@0

D=A

@R13

M=D

@sys.halt

D=A

@R14

M=D

@RET_ADDRESS_CALL334

D=A

@95

0;JMP

(RET_ADDRESS_CALL334)

@SP

AM=M-1

D=M

@R5

M=D

