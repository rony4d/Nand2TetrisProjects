@256
D=A
@SP
M=D
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
@17
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
D=D-M
@EQUAL_18
D;JEQ
@NOT_EQUAL_18
D;JNE
(EQUAL_18)
@SP
A=M
M=-1
@INCREMENT_SP_18
0;JMP
(NOT_EQUAL_18)
@SP
A=M
M=0
@INCREMENT_SP_18
0;JMP
(INCREMENT_SP_18)
@SP
M=M+1
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
@16
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
D=D-M
@EQUAL_59
D;JEQ
@NOT_EQUAL_59
D;JNE
(EQUAL_59)
@SP
A=M
M=-1
@INCREMENT_SP_59
0;JMP
(NOT_EQUAL_59)
@SP
A=M
M=0
@INCREMENT_SP_59
0;JMP
(INCREMENT_SP_59)
@SP
M=M+1
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
@17
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
D=D-M
@EQUAL_100
D;JEQ
@NOT_EQUAL_100
D;JNE
(EQUAL_100)
@SP
A=M
M=-1
@INCREMENT_SP_100
0;JMP
(NOT_EQUAL_100)
@SP
A=M
M=0
@INCREMENT_SP_100
0;JMP
(INCREMENT_SP_100)
@SP
M=M+1
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
@891
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
D=M-D
@LESS_THAN_141
D;JLT
@NOT_LESS_THAN_141
D;JGE
(LESS_THAN_141)
@SP
A=M
M=-1
@INCREMENT_SP_141
0;JMP
(NOT_LESS_THAN_141)
@SP
A=M
M=0
@INCREMENT_SP_141
0;JMP
(INCREMENT_SP_141)
@SP
M=M+1
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
@892
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
D=M-D
@LESS_THAN_182
D;JLT
@NOT_LESS_THAN_182
D;JGE
(LESS_THAN_182)
@SP
A=M
M=-1
@INCREMENT_SP_182
0;JMP
(NOT_LESS_THAN_182)
@SP
A=M
M=0
@INCREMENT_SP_182
0;JMP
(INCREMENT_SP_182)
@SP
M=M+1
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
@891
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
D=M-D
@LESS_THAN_223
D;JLT
@NOT_LESS_THAN_223
D;JGE
(LESS_THAN_223)
@SP
A=M
M=-1
@INCREMENT_SP_223
0;JMP
(NOT_LESS_THAN_223)
@SP
A=M
M=0
@INCREMENT_SP_223
0;JMP
(INCREMENT_SP_223)
@SP
M=M+1
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
@32766
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
D=M-D
@GREATER_THAN_264
D;JGT
@NOT_GREATER_THAN_264
D;JLE
(GREATER_THAN_264)
@SP
A=M
M=-1
@INCREMENT_SP_264
0;JMP
(NOT_GREATER_THAN_264)
@SP
A=M
M=0
@INCREMENT_SP_264
0;JMP
(INCREMENT_SP_264)
@SP
M=M+1
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
@32767
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
D=M-D
@GREATER_THAN_305
D;JGT
@NOT_GREATER_THAN_305
D;JLE
(GREATER_THAN_305)
@SP
A=M
M=-1
@INCREMENT_SP_305
0;JMP
(NOT_GREATER_THAN_305)
@SP
A=M
M=0
@INCREMENT_SP_305
0;JMP
(INCREMENT_SP_305)
@SP
M=M+1
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
@32766
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
D=M-D
@GREATER_THAN_346
D;JGT
@NOT_GREATER_THAN_346
D;JLE
(GREATER_THAN_346)
@SP
A=M
M=-1
@INCREMENT_SP_346
0;JMP
(NOT_GREATER_THAN_346)
@SP
A=M
M=0
@INCREMENT_SP_346
0;JMP
(INCREMENT_SP_346)
@SP
M=M+1
@57
D=A
@SP
A=M
M=D
@SP
M=M+1
@31
D=A
@SP
A=M
M=D
@SP
M=M+1
@53
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
@112
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
D=M-D
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
M=-M
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
M=M-1
A=M
D=D&M
@SP
A=M
M=D
@SP
M=M+1
@82
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
D=D|M
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
M=!M
@SP
M=M+1