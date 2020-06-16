#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//define boolean expressions
#define TRUE 1
#define FALSE 0

//define stack base commands
#define STACK_PUSH  "push"
#define STACK_POP   "pop"

//define memory segment commands
#define MEM_SEGMENT_LOCAL "local"
#define MEM_SEGMENT_ARGUMENT "argument"
#define MEM_SEGMENT_THIS "this"
#define MEM_SEGMENT_THAT "that"
#define MEM_SEGMENT_CONSTANT "constant"
#define MEM_SEGMENT_STATIC "static"
#define MEM_SEGMENT_POINTER "pointer"
#define MEM_SEGMENT_TEMP "temp"

//define memory segment base address labels
#define SP_LABEL "SP"   // left out @ initially. I handled it in the code
#define ARG_LABEL "@ARG"
#define LCL_LABEL "@LCL"
#define THIS_LABEL "@THIS"
#define THAT_LABEL "@THAT"
#define TEMP_LABEL "@5"

//define some varaible labels
#define VAR_PUSH_ARG "@pusharg"
#define VAR_PUSH_LCL "@pushlocal"
#define VAR_PUSH_THIS "@pushthis"
#define VAR_PUSH_THAT "@pushthat"
#define VAR_PUSH_TEMP "@pushtemp"
#define VAR_ADDR "@addr"

//define stack arithmetic commands
#define STACK_ADD  "add"
#define STACK_SUB   "sub"

//define stack logical commands
#define STACK_NEG   "neg"
#define STACK_EQ   "eq"
#define STACK_GT   "gt"
#define STACK_LT  "lt"
#define STACK_AND   "and"
#define STACK_OR   "or"
#define STACK_NOT   "not"

//define program flow commands
#define LABEL_COMMAND   "label"
#define GOTO_COMMAND    "goto"          // unconditional branching 
#define IF_GOTO_COMMAND "if-goto"       // conditional branching 

//define function commands
#define FUNCTION_LABEL  "function"
#define FUNCTION_RETURN  "return"

//define other constants
#define SP_BASE_ADDRESS "256"
#define THIS_BASE_ADDRESS "@3000"
#define THAT_BASE_ADDRESS "@3010"
#define LCL_BASE_ADDRESS "@300"
#define ARG_BASE_ADDRESS "@400"
#define ASM_INSTRUCTION_LEN 64
#define EQUAL_LABEL "(EQUAL"
#define NOT_EQUAL_LABEL "(NOTEQUAL"
#define END_LABEL "(END"
#define GREATER_THAN_LABEL "(GREATERTHAN"
#define NOT_GREATER_THAN_LABEL "(NOTGREATERTHAN"
#define LESS_THAN_LABEL "(LESSTHAN"
#define NOT_LESS_THAN_LABEL "(NOTLESSTHAN"

#define EQUAL_INST "@EQUAL"
#define NOT_EQUAL_INST "@NOTEQUAL"
#define END_INST "@END"
#define GREATER_THAN_INST "@GREATERTHAN"
#define NOT_GREATER_THAN_INST "@NOTGREATERTHAN"
#define LESS_THAN_INST "@LESSTHAN"
#define NOT_LESS_THAN_INST "@NOTLESSTHAN"

#define ARRAY_MAX_LEN 4096
#define MAX_BUFF 4096

//define source files
#define SIMPLE_ADD_VM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd.vm"
#define SIMPLE_ADD_VM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd_Temp.vm"

#define STACK_TEST_VM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/StackArithmetic/StackTest/StackTest.vm"
#define STACK_TEST_VM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/StackArithmetic/StackTest/StackTest_Temp.vm"

#define BASIC_TEST_VM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/MemoryAccess/BasicTest/BasicTest.vm"
#define BASIC_TEST_VM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/MemoryAccess/BasicTest/BasicTest_Temp.vm"

#define POINTER_TEST_VM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/MemoryAccess/PointerTest/PointerTest.vm"
#define POINTER_TEST_VM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/MemoryAccess/PointerTest/PointerTest_Temp.vm"

#define STATIC_TEST_VM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/MemoryAccess/StaticTest/StaticTest.vm"
#define STATIC_TEST_VM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSeven/MemoryAccess/StaticTest/StaticTest_Temp.vm"
#define STATIC_TEST_VM_FILENAME_WITHOUT_EXTENSION "StaticTest" //for building static variable name

#define BASIC_LOOP_TEST_VM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterEight/ProgramFlow/BasicLoop/BasicLoop.vm"
#define BASIC_LOOP_TEST_VM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterEight/ProgramFlow/BasicLoop/BasicLoop_Temp.vm"

#define FIBONACCI_SERIES_VM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterEight/ProgramFlow/FibonacciSeries/FibonacciSeries.vm"
#define FIBONACCI_SERIES_VM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterEight/ProgramFlow/FibonacciSeries/FibonacciSeries_Temp.vm"
/**
 * NOTES: Reference: Elements of Computing Systems Text Book Page 170 (Memory Segments Mapping)
 * 1. For memory segments: Local, Argument, this, that: Each of these segments is mapped directly on the RAM
 * and its location is maintained by keeping its physical base address in a dedicated registrt(LCL,ARG,THIS and THAT) respectively.
 * 2. For memory segments: pointer, temp : These segments are each mapped directly onto a fixed area in the RAM.
 * The pointer segment is mapped on RAM locations  3-4 (also called THIS and THAT)
 * The temp segment is mapped on locations 5-12 (also called R5,R6...R12)
 * 3. constant: This segment is truly virtual as it does not occupy any physical space on the target architecture.
 * Instead, the VM implementation handles any VM access to constanti by simply supplying the constant i
 * 4. static: Each static variable j in file Xxx.vm is translated into the assembly symbol Xxx.j. In the
 * subsequent assembly process, these symbolic varaibles will be allocated RAM space by the Hack assembler starting
 * from address 16. 
 * 
*/
//  function definitions

void print_double_pointer_array(char ** double_pointer_array);
void build_stack_pointer_initialization_command(char ** hack_asm_array);
void build_push_constant_command(char *const_value, char **hack_asm_init_array);
void build_add_command(char **hack_asm_init_array);
void sentence_splitter(char *sentence, char **word_split_array);
void remove_comments(FILE *src_file,FILE *tmp_file);
void parse_vm_code(FILE *src_file);
static char *strip_whitespace(char* p1);

int counter = 0; //global hack asm code line counter variable
/**
 * @brief This code translates Virtual Machine(VM) code generated by 
 * the compiler to Hack Assembly Language
 * See VM code sample below
 * ---Pushes and adds two constants---
    push constant 7
    push constant 8
    add
*/

/**
 * @steps: 
 * 1.   Create parser that will parse each line and break it up into component parts
 *      a. stack_command
 *      b. memory segment 
 *      c. value
 * 
 * 2.   Create dictionary of stack_commands as key and number of additional arguments as value.
 *      for example, push/pop stack_commands have 2 other arguments while arithmetic and logical stack commands
 *      like add, or, not have 0 arguments
 * 
 * 3.   Create a dictionary of stack_command to stack_pointer movement and another of stack_command and stackpointer direction
 *      This should track the number of times the stack pointer should move and in what direction the stackpointer will move
 *      For example: (Reference I used for this example is my manually written SimpleAdd.asm file :D)
 *      1. push operation 1->SP moves 1 step in the forward direction i.e From RAM[256]->RAM[257] before any other operation will change the direction
 *      2. push operation 2->SP moves 1 step in the forward direction i.e From RAM[257]->RAM[258] before any other operation will change the direction
 *      2. add operation->SP moves 2 steps in the backward direction 1.e From RAM[258]->RAM[256] and then 1 step in the forward direction before any other operation will change the direction
 *         i.e from RAM[256]->RAM[257]
 * 
 * 4.   Create a dictionary that will hold command as key and array of characters as value:
 *      This should help us easily write the necessary assembly code when a VM operation is selected
*/


/**
 * @brief   This function initializes the SP based on the hack
 *          assembly language specification which states
 *          SP-> RAM[0] and value of RAM[0] = 256 which is the address that SP points to. 
 * 
*/
void build_stack_pointer_initialization_command(char ** hack_asm_array){

    /*
    @256
    D=A
    @SP
    M=D
    */
    char sp_address[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    // Concat @ and variable
    char *at_symbol = strdup("@");
    strncat(sp_address,at_symbol,strlen(at_symbol));            //@
    strncat(sp_address,SP_BASE_ADDRESS,strlen(SP_BASE_ADDRESS));//@256
    
    hack_asm_array[counter] = strdup(sp_address);
    counter++;
    
    hack_asm_array[counter] = strdup("D=A");
    counter++;

    strncat(sp_instruction,at_symbol,strlen(at_symbol));        //@
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));          //@SP
    hack_asm_array[counter] = strdup(sp_instruction);
    counter++;

    hack_asm_array[counter] = strdup("M=D");
    counter++;
}

/**
 * @brief: The function generates pushing a constant command e.g [push constant 4]
 * @params: const_value: the constant value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_constant_command(char *const_value, char **hack_asm_init_array){

    /*
    @7
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)
    */

    char constant_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP
    
    strncat(constant_instruction,at_symbol,strlen(at_symbol));      //@
    
    const_value = strip_whitespace(const_value);                    //remove new line that comes from word split
    strncat(constant_instruction,const_value,strlen(const_value));  //@const_value


    // From the value in counter, start inserting the 7 push asm commands
    hack_asm_init_array[counter] = strdup(constant_instruction);    //@const_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");
    counter++;
}

/**
 * @brief: The function generates pushing an argument  e.g [push argument 1]
 * @params: arg_value: the argument value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_argument_command(char *arg_value, char **hack_asm_init_array){

    /*
        //push argument 2
        @2
        D=A    

        @pusharg
        M=D         //assign push argument value to pusharg variable

        @ARG        // we are at RAM[1] with value 300
        D=M+D       // ARG + 2 => 400 + 2 -> D-register

        @addr
        A=D
        D=M

        @SP     // We are at RAM[0] with value 256
        A=M
        M=D     // *SP = *ADDR -> RAM[256] = RAM[402] = 2

        @SP     // we are at RAM[0] with value 256
        M=M+1   // SP++ , now value at RAM[0] is 257
    */

    char argument_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP
    
    strncat(argument_instruction,at_symbol,strlen(at_symbol));      //@
    
    arg_value = strip_whitespace(arg_value);                        //remove new line that comes from word split
    strncat(argument_instruction,arg_value,strlen(arg_value));      //@arg_value


    // From the value in counter, start inserting the push argument asm commands

    hack_asm_init_array[counter] = strdup(argument_instruction);    //@arg_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_PUSH_ARG);            //@pusharg
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(ARG_LABEL);               //@ARG
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=D");                   //A=D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief: The function generates pushing a local value  e.g [push local 4]
 * @params: local_value: the local value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_local_command(char *local_value, char **hack_asm_init_array){

    /*
        //push local 5
        @5
        D=A     

        @pushlocal
        M=D     //assign push local value  to pushlocal variable

        @LCL    // we are at RAM[1] with value 300
        D=M+D   // LCL + 5 -> D-register

        @addr
        A=D
        D=M

        @SP     // We are at RAM[0] with value 256
        A=M
        M=D     // *SP = *ADDR

        @SP     // we are at RAM[0] with value 256
        M=M+1   // SP++ , now value at RAM[0] is 257
    */

    char local_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(local_instruction,at_symbol,strlen(at_symbol));             //@
    
    local_value = strip_whitespace(local_value);                        //remove new line that comes from word split
    strncat(local_instruction,local_value,strlen(local_value));         //@local_value


    // From the value in counter, start inserting the push local asm commands

    hack_asm_init_array[counter] = strdup(local_instruction);    //@local_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_PUSH_LCL);            //@pushlocal
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(LCL_LABEL);               //@LCL
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=D");                   //A=D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief: The function generates pushing a temp value  e.g [push temp 4]
 * @params: temp_value: the temp value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_temp_command(char *temp_value, char **hack_asm_init_array){

    /*
        //push temp 6

        // temp segment initialization
        @5
        D=A
        M=D

        //push temp 6

        @6
        D=A

        @pushtemp
        M=D         //assign push temp value to pushtemp variable

        @5          // we are at RAM[5] with value 5
        D=M+D       // Temp + 6 => 5 + 6 -> D-register
        
        @addr
        A=D
        D=M


        @SP     // We are at RAM[0] with value 256
        A=M
        M=D     // *SP = *ADDR -> RAM[256] = RAM[11] = 6

        @SP     // we are at RAM[0] with value 256
        M=M+1   // SP++ , now value at RAM[0] is 257
    */

    char temp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(temp_instruction,at_symbol,strlen(at_symbol));              //@
    
    temp_value = strip_whitespace(temp_value);                          //remove new line that comes from word split
    strncat(temp_instruction,temp_value,strlen(temp_value));            //@temp_value


    // Intialize temp segment
    hack_asm_init_array[counter] = strdup(TEMP_LABEL);              //@5  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    // From the value in counter, start inserting the push temp asm commands

    hack_asm_init_array[counter] = strdup(temp_instruction);        //@temp_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_PUSH_TEMP);           //@pushtemp
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(TEMP_LABEL);              //@5
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=D");                   //A=D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;

    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief: The function generates pushing a this value  e.g [push this 4]
 * @params: this_value: the this value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_this_command(char *this_value, char **hack_asm_init_array){

    /*
        //push this 6

        @6
        D=A     

        @pushthis
        M=D         //assign push this value to pushthis variable

        @THIS       // we are at RAM[1] with value 3000
        D=M+D       // THIS + 2 => 3000 + 6

        @addr
        A=D
        D=M

        @SP         // We are at RAM[0] with value 256
        A=M
        M=D         // *SP = *ADDR -> RAM[256] = RAM[3006] = 6

        @SP         // we are at RAM[0] with value 256
        M=M+1       // SP++ , now value at RAM[0] is 257
    */

    char this_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(this_instruction,at_symbol,strlen(at_symbol));              //@
    
    this_value = strip_whitespace(this_value);                          //remove new line that comes from word split
    strncat(this_instruction,this_value,strlen(this_value));            //@this_value


    // From the value in counter, start inserting the push this asm commands

    hack_asm_init_array[counter] = strdup(this_instruction);        //@this_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_PUSH_THIS);           //@pushthis
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(THIS_LABEL);              //@THIS
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=D");                   //A=D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;

    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief: The function generates pushing a that value  e.g [push that 4]
 * @params: that_value: the that value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_that_command(char *that_value, char **hack_asm_init_array){

    /*
        //push that 8

        @8
        D=A     

        @pushthat
        M=D         //assign push that value to pushthat variable

        @THAT       // we are at RAM[1] with value 3010
        D=M+D       // THAT + 8 => 3010 + 8

        @addr
        A=D
        D=M

        @SP         // We are at RAM[0] with value 256
        A=M
        M=D         // *SP = *ADDR -> RAM[256] = RAM[3018] = 8

        @SP         // we are at RAM[0] with value 256
        M=M+1       // SP++ , now value at RAM[0] is 257
    */

    char that_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(that_instruction,at_symbol,strlen(at_symbol));              //@
    
    that_value = strip_whitespace(that_value);                          //remove new line that comes from word split
    strncat(that_instruction,that_value,strlen(that_value));            //@that_value


    // From the value in counter, start inserting the push "that" asm commands

    hack_asm_init_array[counter] = strdup(that_instruction);        //@that_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_PUSH_THAT);           //@pushthat
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(THAT_LABEL);              //@THAT
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;

    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=D");                   //A=D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;

    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief: The function generates pushing a pointer value  e.g [push pointer 0 or push pointer 1]
 * @params: pointer_value: the that value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_pointer_command(char *pointer_value, char **hack_asm_init_array){
    /*
        //push pointer 0

        // Applying formula :: push pointer 0 ---> *SP = THIS, SP++
        @THIS
        D=M    

        @SP     // We are at RAM[0] with value 256
        A=M
        M=D     // *SP = THIS -> RAM[256] = 3000

        @SP     // we are at RAM[0] with value 256
        M=M+1   // SP++ , now value at RAM[0] is 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    if(strcmp(pointer_value,"0") == 0){
        hack_asm_init_array[counter] = strdup(THIS_LABEL);              //@THIS
        counter++;
        hack_asm_init_array[counter] = strdup("D=M");                   //D=M
        counter++;
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("A=M");                   //A=M
        counter++;
        hack_asm_init_array[counter] = strdup("M=D");                   //M=D
        counter++;
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("M=M+1");                 //SP++
        counter++;     
    }

    /*
        //push pointer 1

        // Applying formula :: push pointer 0 ---> *SP = THAT, SP++
        @THAT
        D=M    

        @SP     // We are at RAM[0] with value 256
        A=M
        M=D     // *SP = THIS -> RAM[256] = 3000

        @SP     // we are at RAM[0] with value 256
        M=M+1   // SP++ , now value at RAM[0] is 257
    */
    if(strcmp(pointer_value,"1") == 0){
        hack_asm_init_array[counter] = strdup(THAT_LABEL);              //@THAT
        counter++;
        hack_asm_init_array[counter] = strdup("D=M");                   //D=M
        counter++;
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("A=M");                   //A=M
        counter++;
        hack_asm_init_array[counter] = strdup("M=D");                   //M=D
        counter++;
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("M=M+1");                 //SP++
        counter++;       
    }
}

/**
 * @brief: The function generates pushing a static value  e.g [push static5]
 * @params: static_value: the that value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
 *          filename: the name of the file will be used to to form static variable names
*/
void build_push_static_command(char *static_value, char **hack_asm_init_array, char *filename){
    /*
        //push static 5

        // Applying formula :: push static 5 ---> *SP = @statictest.5, SP++
        @statictest.5
        D=M    

        @SP     // We are at RAM[0] with value 256
        A=M
        M=D     // *SP = @statictest.5 -> RAM[16] => *SP = RAM[16]

        @SP     // we are at RAM[0] with value 256
        M=M+1   // SP++ , now value at RAM[0] is 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char static_variable[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP
    
    strncat(static_variable,at_symbol,strlen(at_symbol));           //@      
    strncat(static_variable,filename,strlen(filename));             //@filename
    strncat(static_variable,".",strlen("."));                       //@filename.
    strncat(static_variable,static_value,strlen(static_value));     //@filename.static_value
    
    hack_asm_init_array[counter] = strdup(static_variable);         //@filename.static_value
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //SP++
    counter++;

}
/**
 * @brief: The function generates poping an argument  e.g [pop argument 1]
 * @params: arg_value: the argument value we want to pop
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_pop_argument_command(char *arg_value, char **hack_asm_init_array){

    /*
        //pop argument 5

        @5
        D=A   

        @ARG
        D=M+D   //ARG + i => 400 + 5 => 405, this means register D will hold value of 405

        @addr
        M=D     // We assgin 405 to addr variable to hold the value

        @SP     // we are at RAM[0] with value 257
        M=M-1   // SP-- , now value at RAM[0] is 256

        @SP     // We are at RAM[0] with value 256
        A=M
        D=M     // We are at RAM[256] Store the value at RAM[256] in D-register

        @addr
        A=M         // Assgin A to 405, so we move to RAM[405]
        M=D         // RAM[407] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
    */

    char argument_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP
    
    strncat(argument_instruction,at_symbol,strlen(at_symbol));      //@
    
    arg_value = strip_whitespace(arg_value);                        //remove new line that comes from word split
    strncat(argument_instruction,arg_value,strlen(arg_value));      //@arg_value


    // From the value in counter, start inserting the push argument asm commands

    hack_asm_init_array[counter] = strdup(argument_instruction);    //@arg_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(ARG_LABEL);               //@ARG
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
}

/**
 * @brief: The function generates popping a local value  e.g [pop local 4]
 * @params: local_value: the local value we want to pop
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_pop_local_command(char *local_value, char **hack_asm_init_array){

    /*
        //pop local 10

        // General formula for push/pop local i, where i is the number you want to push or pop
        // pop local i ---> addr = LCL+ i, SP--, *addr = *SP

        // to pop local 10 ---> ADDR = LCL + 10, SP--, *addr = *SP

        @10
        D=A       

        @LCL        //we are in the LCL segment base register RAM[1] with value 300 based on LCL initialization
        D=M+D       // LCL + i => 300 + 10 => 310, this means register D will hold value of 310

        @addr
        M=D         // We assgin 314 to addr variable to hold the value

        @SP         // we are at RAM[0] with value 257
        M=M-1       // SP-- , now value at RAM[0] is 256

        @SP         // We are at RAM[0] with value 256
        A=M
        D=M         // We are at RAM[256] Store the value at RAM[256] in D-register

        @addr
        A=M         // Assgin A to 310, so we move to RAM[310]
        M=D         // RAM[310] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
    */

    char local_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(local_instruction,at_symbol,strlen(at_symbol));             //@
    
    local_value = strip_whitespace(local_value);                        //remove new line that comes from word split
    strncat(local_instruction,local_value,strlen(local_value));         //@local_value


    // From the value in counter, start inserting the push local asm commands

    hack_asm_init_array[counter] = strdup(local_instruction);       //@local_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(LCL_LABEL);               //@LCL
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
}

/**
 * @brief: The function generates popping a temp value  e.g [pop temp 4]
 * @params: temp_value: the temp value we want to pop
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_pop_temp_command(char *temp_value, char **hack_asm_init_array){

    /*


        // temp segment initialization
        @5
        D=A
        M=D

        //pop temp 8
        @8
        D=A       

        @5          // we are in the temp segment base register RAM[5] with value 5 based on temp initialization 5
        D=M+D       // 5 + i => 5 + 8 => 13, this means register D will hold value of 13

        @addr
        M=D         // We assgin 13 to addr variable to hold the value

        @SP         // we are at RAM[0] with value 257
        M=M-1       // SP-- , now value at RAM[0] is 256

        @SP         // We are at RAM[0] with value 256
        A=M
        D=M         // We are at RAM[256]. we store the value at RAM[256] in D-register

        @addr
        A=M         // Assgin A to 13, so we move to RAM[13]
        M=D         // RAM[13] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
    */

    char temp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(temp_instruction,at_symbol,strlen(at_symbol));              //@
    
    temp_value = strip_whitespace(temp_value);                          //remove new line that comes from word split
    strncat(temp_instruction,temp_value,strlen(temp_value));            //@temp_value


    // Intialize temp segment
    hack_asm_init_array[counter] = strdup(TEMP_LABEL);              //@5  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;

    // From the value in counter, start inserting the push temp asm commands

    hack_asm_init_array[counter] = strdup(temp_instruction);        //@temp_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(TEMP_LABEL);              //@5
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;

}

/**
 * @brief: The function generates popping a "this" value  e.g [pop this 4]
 * @params: this_value: the this value we want to pop
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_pop_this_command(char *this_value, char **hack_asm_init_array){

    /*
        //pop this 20

        @20
        D=A   

        @THIS   //we are in the this segment base register RAM[3] with value 3000 based on THIS initialization
        D=M+D   //THIS + i => 3000 + 20 => 3020, this means register D will hold value of 3020

        @addr
        M=D     // We assgin 3020 to addr variable to hold the value

        @SP     // we are at RAM[0] with value 257
        M=M-1   // SP-- , now value at RAM[0] is 256

        @SP     // We are at RAM[0] with value 256
        A=M
        D=M     // We are at RAM[256] Store the value at RAM[256] in D-register

        @addr
        A=M         // Assgin A to 3020, so we move to RAM[3020]
        M=D         // RAM[3020] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
    */

    char this_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(this_instruction,at_symbol,strlen(at_symbol));              //@
    
    this_value = strip_whitespace(this_value);                          //remove new line that comes from word split
    strncat(this_instruction,this_value,strlen(this_value));            //@this_value


    // From the value in counter, start inserting the push this asm commands

    hack_asm_init_array[counter] = strdup(this_instruction);        //@this_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;
    hack_asm_init_array[counter] = strdup(THIS_LABEL);              //@THIS
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
}


/**
 * @brief: The function generates popping a that value  e.g [pop that 4]
 * @params: that_value: the that value we want to pop
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_pop_that_command(char *that_value, char **hack_asm_init_array){

    /*
        //pop that 20

        @20
        D=A   

        @THAT   //we are in the this segment base register RAM[3] with value 3010 based on THAT initialization
        D=M+D   //THIS + i => 3010 + 20 => 3030, this means register D will hold value of 3030

        @addr
        M=D     // We assgin 3030 to addr variable to hold the value

        @SP     // we are at RAM[0] with value 257
        M=M-1   // SP-- , now value at RAM[0] is 256

        @SP     // We are at RAM[0] with value 256
        A=M
        D=M     // We are at RAM[256] Store the value at RAM[256] in D-register

        @addr
        A=M         // Assgin A to 3030, so we move to RAM[3030]
        M=D         // RAM[3030] = *SP => *addr = *SP . So we assgined the value of *SP to the location pointed to by addr which is *addr. This is the pop magic baby!!!
    */

    char that_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    strncat(that_instruction,at_symbol,strlen(at_symbol));              //@
    
    that_value = strip_whitespace(that_value);                          //remove new line that comes from word split
    strncat(that_instruction,that_value,strlen(that_value));            //@that_value


    // From the value in counter, start inserting the push "that" asm commands

    hack_asm_init_array[counter] = strdup(that_instruction);        //@that_value  
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");                   //D=A
    counter++;

    hack_asm_init_array[counter] = strdup(THAT_LABEL);              //@THAT
    counter++;
    hack_asm_init_array[counter] = strdup("D=M+D");                 //D=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(VAR_ADDR);                //@addr
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++;  
}

/**
 * @brief: The function generates popping a pointer value  e.g [pop pointer 0 or pop pointer 1]
 * @params: that_value: the that value we want to pop
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_pop_pointer_command(char *pointer_value, char **hack_asm_init_array){

    /*
        //pop pointer 0

        // Applying formula :: pop pointer 0 ---> SP--, THIS = *SP
        @SP
        M=M-1

        @SP
        A=M     // Let us go to RAM[256]
        D=M     //Assign *SP to D-register first

        @THIS
        M=D     // THIS = *SP
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                  //@SP
    
    if(strcmp(pointer_value,"0") == 0){
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
        counter++;
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("A=M");                   //A=M
        counter++;
        hack_asm_init_array[counter] = strdup("D=M");                   //D=M
        counter++;
        hack_asm_init_array[counter] = strdup(THIS_LABEL);              //@THIS
        counter++;
        hack_asm_init_array[counter] = strdup("M=D");                   //M=D
        counter++;     
    }

    /*
        //pop pointer 1

        // Applying formula :: pop pointer 1 ---> SP--, THAT = *SP
        @SP
        M=M-1

        @SP
        A=M     // Let us go to RAM[256]
        D=M     //Assign *SP to D-register first

        @THAT
        M=D     // THIS = *SP
    */

    if(strcmp(pointer_value,"1") == 0){
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
        counter++;
        hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("A=M");                   //A=M
        counter++;
        hack_asm_init_array[counter] = strdup("D=M");                   //D=M
        counter++;
        hack_asm_init_array[counter] = strdup(THAT_LABEL);              //@THAT
        counter++;
        hack_asm_init_array[counter] = strdup("M=D");                   //M=D
        counter++;        
    }
}

/**
 * @brief: The function generates popping a static value  e.g [pop staitc 5]
 * @params: that_value: the that value we want to pop
 *          hack_asm_init_array: the stack pointer initialization commands
 *          filename: the name of the file will be used to to form static variable names
*/
void build_pop_static_command(char *static_value, char **hack_asm_init_array,char *filename){

    /*
        //pop static 5

        // Applying formula :: pop static 5 ---> SP--, @statictest.5 = *SP

        @SP
        M=M-1

        @SP
        A=M     // Let us go to RAM[256]
        D=M     //Assign *SP to D-register first

        @@statictest.5
        M=D     // @statictest.5 = *SP => RAM[16] = *SP
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char static_variable[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP
    
    strncat(static_variable,at_symbol,strlen(at_symbol));           //@      
    strncat(static_variable,filename,strlen(filename));             //@filename
    strncat(static_variable,".",strlen("."));                       //@filename.
    strncat(static_variable,static_value,strlen(static_value));     //@filename.static_value
    
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(static_variable);         //@filename.static_value
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");                   //M=D
    counter++; 

}

/**
 * @brief This function builds the add command that adds the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_add_command(char **hack_asm_init_array){

    /*
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] value 257
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- (Stack pointer moves one space backward the second time) We decrease RAM[0] value by 1 to give us 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=M+D

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+D");                 //M=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief This function builds the sub command that subtracts the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_sub_command(char **hack_asm_init_array){

    /*
    // sub
    //To Sub we have to pop i.e (SP at RAM[256] - SP at RAM[257])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- we are at RAM[0] value 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=M-D   // Subtraction happens here

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief This function builds the and command that performs bitwise AND on the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_and_command(char **hack_asm_init_array){

    /*
    // and
    //To AND we have to pop i.e (SP at RAM[256] & SP at RAM[257])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- we are at RAM[0] value 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=D&M   // AND happens here

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M&D");                 //M=M&D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief This function builds the equal command that checks if the content of the two previous
 * registers are equal
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_equal_command(char **hack_asm_init_array){

    /*
    // eq
    //To check if equal we have to pop i.e (SP at RAM[257] - SP at RAM[256] == 0)
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M     // We are at RAM[257]
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M     // We are at RAM[256]
    M=M-D   // RAM[256] - RAM[257]  
    D=M     // Assign result to D-register so we can check equality to zero finally

    @EQUAL
    D;JEQ

    @NOTEQUAL
    0;JMP

    (EQUAL) // If two operands are equal then value of SP is -1 else value is 0
        @SP
        A=M
        M=-1
        @END
        0;JMP
        
    (NOTEQUAL)
        @SP
        A=M
        M=0
        @END
        0;JMP

    (END)
        @SP
        M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char counter_str[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char equal_instruction[ASM_INSTRUCTION_LEN] = {0};
    char not_equal_instruction[ASM_INSTRUCTION_LEN] = {0};
    char end_instruction[ASM_INSTRUCTION_LEN] = {0};
    char equal_label[ASM_INSTRUCTION_LEN] = {0};
    char not_equal_label[ASM_INSTRUCTION_LEN] = {0};
    char end_label[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // build @EQUALi instruction
    strncat(equal_instruction,EQUAL_INST,strlen(EQUAL_INST));       //@EQUAL
    snprintf(counter_str,ASM_INSTRUCTION_LEN,"%d",counter);         //converts int to string
    strncat(equal_instruction,counter_str,strlen(counter_str));     //@EQUALi -> appends counter to @EQUAL instruction to make it unique for every call of this function.

    // build @NOTEQUALi instruction
    strncat(not_equal_instruction,NOT_EQUAL_INST,strlen(NOT_EQUAL_INST));       //@NOTEQUAL
    strncat(not_equal_instruction,counter_str,strlen(counter_str));             //@NOTEQUALi -> appends counter to @NOTEQUAL instruction to make it unique for every call of this function.

    // build @ENDi instruction
    strncat(end_instruction,END_INST,strlen(END_INST));                         //@END
    strncat(end_instruction,counter_str,strlen(counter_str));             //@ENDi -> appends counter to @END instruction to make it unique for every call of this function.

    // build (EQUALi) label
    strncat(equal_label,EQUAL_LABEL,strlen(EQUAL_LABEL));                   //(EQUAL
    strncat(equal_label,counter_str,strlen(counter_str));                   //(EQUALi
    strncat(equal_label,")",strlen(")"));                                   //(EQUALi)
    
    // build (NOTEQUALi) label
    strncat(not_equal_label,NOT_EQUAL_LABEL,strlen(NOT_EQUAL_LABEL));           //(NOTEQUAL
    strncat(not_equal_label,counter_str,strlen(counter_str));                   //(NOTEQUALi
    strncat(not_equal_label,")",strlen(")"));                                   //(NOTEQUALi)

    // build (ENDi) label
    strncat(end_label,END_LABEL,strlen(END_LABEL));                         //(END
    strncat(end_label,counter_str,strlen(counter_str));                     //(ENDi
    strncat(end_label,")",strlen(")"));                                     //(ENDi)

    // From the value in global counter, start inserting the asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(equal_instruction);       //@EQUALi
    counter++;
    hack_asm_init_array[counter] = strdup("D;JEQ");                 //D;JEQ
    counter++;
    hack_asm_init_array[counter] = strdup(not_equal_instruction);   //@NOTEQUALi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                 //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(equal_label);             //(EQUALi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);           //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                    //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-1");                   //M=-1 [true] 
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);          //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                  //0;JMP
    counter++;

    hack_asm_init_array[counter] = strdup(not_equal_label);          //(NOTEQUALi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);           //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                    //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=0");                    //M=0   [false]
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);          //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                  //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(end_label);               //(ENDi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);           //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}


/**
 * @brief This function builds the greater_than command that checks content of previous register is 
 * greater than content of the current register
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_greater_than_command(char **hack_asm_init_array){

    /*
    // greater than
    //To check if less we have to pop i.e (SP at RAM[256] - SP at RAM[257] > 0)
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M     // We are at RAM[257]
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M     // We are at RAM[256]
    M=M-D   // RAM[256] - RAM[257]  
    D=M     // Assign result to D-register so we can check greater than to zero 

    @GREATERTHAN
    D;JGT

    @NOTGREATERTHAN
    0;JMP

    (GREATERTHAN) // If RAM[256] < RAM[257] then run the code below which sets SP or RAM[256] to true or -1
        @SP
        A=M
        M=-1
        @END
        0;JMP
        
    (NOTGREATERTHAN) // If RAM[256] is not less than RAM[257] then run the code below which sets SP or RAM[256] to false or 0
        @SP
        A=M
        M=0
        @END
        0;JMP

    (END)
        @SP
        M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char counter_str[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char greather_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char not_greater_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char end_instruction[ASM_INSTRUCTION_LEN] = {0};
    char greater_than_label[ASM_INSTRUCTION_LEN] = {0};
    char not_greater_than_label[ASM_INSTRUCTION_LEN] = {0};
    char end_label[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // build @GREATERTHANi instruction
    strncat(greather_than_instruction,GREATER_THAN_INST,strlen(GREATER_THAN_INST));         //@GREATERTHAN
    snprintf(counter_str,ASM_INSTRUCTION_LEN,"%d",counter);                                 //converts int to string
    strncat(greather_than_instruction,counter_str,strlen(counter_str));                     //@GREATERTHANi -> appends counter to @GREATERTHAN instruction to make it unique for every call of this function.

    // build @NOTGREATERTHANi instruction
    strncat(not_greater_than_instruction,NOT_GREATER_THAN_INST,strlen(NOT_GREATER_THAN_INST));          //@NOTGREATERTHAN
    strncat(not_greater_than_instruction,counter_str,strlen(counter_str));                              //@NOTGREATERTHANi -> appends counter to @NOTGREATERTHAN instruction to make it unique for every call of this function.

    // build @ENDi instruction
    strncat(end_instruction,END_INST,strlen(END_INST));                         //@END
    strncat(end_instruction,counter_str,strlen(counter_str));                   //@ENDi -> appends counter to @END instruction to make it unique for every call of this function.

    // build (GREATERTHANi) label
    strncat(greater_than_label,GREATER_THAN_LABEL,strlen(GREATER_THAN_LABEL));  //(GREATERTHAN
    strncat(greater_than_label,counter_str,strlen(counter_str));                //(GREATERTHANi
    strncat(greater_than_label,")",strlen(")"));                                //(GREATERTHANi)
    
    // build (NOTGREATERTHANi) label
    strncat(not_greater_than_label,NOT_GREATER_THAN_LABEL,strlen(NOT_GREATER_THAN_LABEL));                  //(NOTGREATERTHAN
    strncat(not_greater_than_label,counter_str,strlen(counter_str));                                               //(NOTGREATERTHANi
    strncat(not_greater_than_label,")",strlen(")"));                                                               //(NOTGREATERTHANi)

    // build (ENDi) label
    strncat(end_label,END_LABEL,strlen(END_LABEL));                         //(END
    strncat(end_label,counter_str,strlen(counter_str));                     //(ENDi
    strncat(end_label,")",strlen(")"));                                     //(ENDi)



    // From the value in global counter, start inserting the asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(greather_than_instruction);       //@GREATERTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("D;JGT");                         //D;JGT
    counter++;
    hack_asm_init_array[counter] = strdup(not_greater_than_instruction);    //@NOTREATERTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(greater_than_label);              //(GREATERTHANi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                    //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-1");                   //M=-1 [true] 
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);          //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                  //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(not_greater_than_label);    //(NOTGREATERTHANi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                           //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=0");                           //M=0   [false]
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);                 //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(end_label);                       //(ENDi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                          //M=M+1
    counter++;
}

/**
 * @brief This function builds the less_than command that checks content of previous register is 
 * less than content of the current register
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_less_than_command(char **hack_asm_init_array){

    /*
    // less than
    //To check if less we have to pop i.e (SP at RAM[256] - SP at RAM[257] < 0)
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M     // We are at RAM[257]
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M     // We are at RAM[256]
    M=M-D   // RAM[256] - RAM[257]  
    D=M     // Assign result to D-register so we can check less than to zero 

    @LESSTHAN
    D;JLT

    @NOTLESSTHAN
    0;JMP

    (LESSTHAN) // If RAM[256] < RAM[257] then run the code below which sets SP or RAM[256] to true or -1
        @SP
        A=M
        M=-1
        @END
        0;JMP
        
    (NOTLESSTHAN) // If RAM[256] is not less than RAM[257] then run the code below which sets SP or RAM[256] to false or 0
        @SP
        A=M
        M=0
        @END
        0;JMP

    (END)
        @SP
        M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char counter_str[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char less_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char not_less_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char end_instruction[ASM_INSTRUCTION_LEN] = {0};
    char less_than_label[ASM_INSTRUCTION_LEN] = {0};
    char not_less_than_label[ASM_INSTRUCTION_LEN] = {0};
    char end_label[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // build @LESSTHANi instruction
    strncat(less_than_instruction,LESS_THAN_INST,strlen(LESS_THAN_INST));                   //@LESSTHAN
    snprintf(counter_str,ASM_INSTRUCTION_LEN,"%d",counter);                                 //converts int to string
    strncat(less_than_instruction,counter_str,strlen(counter_str));                         //@LESSTHANi -> appends counter to @LESS instruction to make it unique for every call of this function.

    // build @NOTLESSTHANi instruction
    strncat(not_less_than_instruction,NOT_LESS_THAN_INST,strlen(NOT_LESS_THAN_INST));       //@NOTLESSTHAN
    strncat(not_less_than_instruction,counter_str,strlen(counter_str));                     //@NOTLESSTHANi -> appends counter to @NOTLESSTHAN instruction to make it unique for every call of this function.

    // build @ENDi instruction
    strncat(end_instruction,END_INST,strlen(END_INST));                         //@END
    strncat(end_instruction,counter_str,strlen(counter_str));                   //@ENDi -> appends counter to @END instruction to make it unique for every call of this function.

    // build (LESSTHANi) label
    strncat(less_than_label,LESS_THAN_LABEL,strlen(LESS_THAN_LABEL));           //(LESSTHAN
    strncat(less_than_label,counter_str,strlen(counter_str));                   //(LESSTHANi
    strncat(less_than_label,")",strlen(")"));                                   //(LESSTHANi)
    
    // build (NOTLESSTHANi) label
    strncat(not_less_than_label,NOT_LESS_THAN_LABEL,strlen(NOT_LESS_THAN_LABEL));                   //(NOTLESSTHAN
    strncat(not_less_than_label,counter_str,strlen(counter_str));                                //(NOTLESSTHANi
    strncat(not_less_than_label,")",strlen(")"));                                                //(NOTLESSTHANi)

    // build (ENDi) label
    strncat(end_label,END_LABEL,strlen(END_LABEL));                         //(END
    strncat(end_label,counter_str,strlen(counter_str));                     //(ENDi
    strncat(end_label,")",strlen(")"));                                     //(ENDi)



    // From the value in global counter, start inserting the asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(less_than_instruction);           //@LESSTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("D;JLT");                         //D;JLT
    counter++;
    hack_asm_init_array[counter] = strdup(not_less_than_instruction);       //@NOTLESSTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(less_than_label);                 //(LESSTHANi)
    counter++;  
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                           //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-1");                          //M=-1 [true] 
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);                 //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(not_less_than_label);             //(NOTLESSTHANi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                           //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=0");                           //M=0   [false]
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);                 //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(end_label);                       //(ENDi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                          //M=M+1
    counter++;
}

/**
 * @brief This function builds the neg command that performs negation on the value of the previous register
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_neg_command(char **hack_asm_init_array){

    /*
    // neg
    //To negate we move a step back and -M or -D i.e (- SP at RAM[256])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 256
    A=M     // We are at RAM[256]
    M=-M    // negate M and assign value to M

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-M");                  //M=-M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief This function builds the not command that performs NOT on the value of the previous register.
 * NOT is bitwise flip of every bit in a number (!value)
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_not_command(char **hack_asm_init_array){

    /*
    // not
    //To not we move a step back and !M or !A or !D i.e (!SP at RAM[256])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 256
    A=M     // We are at RAM[256]
    M=!M    // not M and assign value to M

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=!M");                  //M=!M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief This function builds the or command that performs bitwise OR on the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_or_command(char **hack_asm_init_array){

    /*
    // or
    //To OR we have to pop i.e (SP at RAM[256] | SP at RAM[257])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- we are at RAM[0] value 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=D|M   // OR happens here

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M|D");                 //M=M|D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief This function builds the label command used in program flow control(branching)
 * eg. //  label LOOP_START should produce (LOOP_START)
*/
void build_label_command(char **hack_asm_init_array, char *label){
    
    char label_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *open_bracket_symbol = "(";
    char *close_bracket_symbol = ")";
    
    strncat(label_instruction,open_bracket_symbol,strlen(open_bracket_symbol));     //(
    
    label = strip_whitespace(label);                                                //remove new line that comes from word split
    strncat(label_instruction,label,strlen(label));                                 //(label
    strncat(label_instruction,close_bracket_symbol,strlen(close_bracket_symbol));   //(label)

    // From the value in counter, start inserting the push local asm commands

    hack_asm_init_array[counter] = strdup(label_instruction);       //()  
    counter++;
}

/**
 * @brief This function builds the if-goto label command used in program flow control(conditional branching)
*/
void build_if_goto_command(char **hack_asm_init_array, char *label){
    
    /*
    
        ASM Code

        pop the stacks topmost value. This simply means taking the SP back one level i.e M=M-1
        NOTE: before we execute an if-goto, we must first push the value we want to use to check
        the condition. For example, before the if-goto asm code below, we need to have something like
        
        ** push argument 0 **
        and in pushing argument 0, we will store the value in D-register and then use
        the D-register as destination in our conditional goto statement. 
        NOTE: This stuff took me about 24 hours to figure out. 
        How you can confirm this is by
        running tests with  the VMEmulator for BasicLoop.vm file . Observe the Local, Argument memory
        segments as well as Global stack and RAM. It will give you very good insights. 
        
        if-goto asm code:

        @SP
        M=M-1   
        
        @LOOP_START
        D;JNE   //  go to LOOP_START if M is not equal to zero. D-register contains the condtional value which has been
                //  pushed before the if-goto Label statement.
    */

    char label_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};

    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));                            //@
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                              //@SP

    strncat(label_instruction,at_symbol,strlen(at_symbol));                         //@
    
    label = strip_whitespace(label);                                                //remove new line that comes from word split
    strncat(label_instruction,label,strlen(label));                                 //@label

    // From the value in counter, start inserting the push local asm commands

    hack_asm_init_array[counter] = strdup(sp_instruction);                          //@SP   
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(label_instruction);                       //@label
    counter++;
    hack_asm_init_array[counter] = strdup("D;JNE");                                 //D;JNE
    counter++;   
}

/**
 * @brief This function builds the igoto label command used in program flow control(unconditional branching)
*/
void build_goto_command(char **hack_asm_init_array, char *label){
    
    /*
    
        ASM Code


        // @SP
        // M=M-1   
        
        @END_PROGRAM
        0;JMP   //  goto label END_PROGRAM by force.
    */

    char label_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};

    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));                            //@
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                              //@SP

    strncat(label_instruction,at_symbol,strlen(at_symbol));                         //@
    
    label = strip_whitespace(label);                                                //remove new line that comes from word split
    strncat(label_instruction,label,strlen(label));                                 //@label

    // From the value in counter, start inserting the push local asm commands
    hack_asm_init_array[counter] = strdup(label_instruction);                       //@label
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                                 //0;JMP
    counter++;   
}

/**
 * @brief This function builds the function_declaration command
 * example: function SimpleFunction.test 2
*/
void build_function_declaration_command(char **hack_asm_init_array, char *function_name, int local_variable_count){
    
    /*
    
        //  Test Case:  function SimpleFunction.test 2
              Number of local variables: 2. This means we have to push constant 0, two times

        //  See VM representation of the initialization process of function SimpleFunction.test 2 below
        //  push constant 0
        //  push constant 0

        //  See ASM representation of the initialization process of function SimpleFunction.test 2

        @0
        D=A
        @SP
        A=M
        M=D
        @SP
        M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)
    
        @0
        D=A
        @SP
        A=M
        M=D
        @SP
        M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)
    */

    
    char label_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};

    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));                                //@
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));                                  //@SP

    //  Initial the local variables to 0, based on local_variable_count
    for (size_t i = 0; i < local_variable_count; i++)
    {

        hack_asm_init_array[counter] = strdup("@0");                                    //@0
        counter++;
        hack_asm_init_array[counter] = strdup("D=A");                                   //D=A
        counter++;      
        hack_asm_init_array[counter] = strdup(sp_instruction);                          //@SP   
        counter++;
        hack_asm_init_array[counter] = strdup("A=M");                                   //A=M
        counter++;
        hack_asm_init_array[counter] = strdup("M=D");                                   //M=D
        counter++;
        hack_asm_init_array[counter] = strdup(sp_instruction);                          //@SP
        counter++;
        hack_asm_init_array[counter] = strdup("M=M+1");                                 //M=M+1
        counter++; 
    }

  
}
/**
 * @brief: splits a sentence into words and outs an array
 * NOTE: the word_split_array has to be "malloced" before passing to this function
*/
void sentence_splitter(char *sentence, char **word_split_array){
    // Extract the first token
    char *token = strtok(sentence," ");

    // loop through the string to extract all other tokens
    int line_counter = 0;
    while (token != NULL)
    {
        token = strip_whitespace(token);    //remove white space or new line :( you been de cause troube for me. I don catch you
        word_split_array[line_counter] = strdup(token);
        token = strtok(NULL, " ");
        line_counter++;
    }
    

}



/**
 * @brief   this function parses the .vm file  line by line and generates the correspondng 
 *          set of hack assembly commands per vm code line. 
 * NOTE:    ensure the following have been done before calling this function
 *          1. Empty lines have been removed from the file
 *          2. Comments have been removed from the file      
*/
void parse_vm_code(FILE *src_file){
    
    //Initialize hack assembly array
    char **hack_asm_init_array = malloc(sizeof(char *) * ARRAY_MAX_LEN);

    //build stack pointer initialization command
    build_stack_pointer_initialization_command(hack_asm_init_array);

    char vm_code_instruction[MAX_BUFF] = {0};
    
    //read file line by line
    while (fgets(vm_code_instruction,MAX_BUFF,src_file) != NULL)
    {
       
        //1.    Split the vm_code_instructions into words
        //2.    Check the first element in the word_split_array
        //2a.   The first element should be a "push, pop, add, sub, neg, eq, gt, lt, and, or, not" command
        //3.    If the element is either a push or pop command then it must have a follow up element which is a memory segment
        //3a.   Check the follow up element(memeory segment) to know which memory segment function to call that is tied to push or pop operation
        //4.    If the first element is an arithmetic or logical command like "add, sub, neg, eq, gt, lt, and, or, not", then there will be no other followup element
        /*
                Example for 3a.
                if(strcmp(word_split_array[0],"push") == 0){
                    if(strcmp(word_split_array[1],"constant") == 0){
                        char *const_value = word_split_array[1];
                        build_push_constant_command(const char *const_value, char **hack_asm_init_array);
                    }
                    if(strcmp(word_split_array[1],"static") == 0){
                        / call the push static command /
                    }
                }

                Example for 4.
                if(strcmp(word_split_array[0] == "add") == 0){
                    build_add_command(char **hack_asm_init_array);
                }

        */


        //Initialize array to be returned
        char **word_split_array = malloc(sizeof(char *) * ARRAY_MAX_LEN);
        //1.    Split the vm_code_instructions into words
        sentence_splitter(vm_code_instruction,word_split_array);
        //2.    Check the first element in the word_split_array
        if (strcmp(word_split_array[0],STACK_PUSH) == 0)
        {
            //  Push command

            //  CONSTANT MEM SEGMENT
            if(strcmp(word_split_array[1],MEM_SEGMENT_CONSTANT) == 0){
                
                //  constant memory segment
                char *const_value = word_split_array[2];
                build_push_constant_command(const_value, hack_asm_init_array);
                //debug line remove later
                printf("Debug: Push contant %s, Count: %d \n",const_value,counter);
            }

            //  ARG MEMORY SEGMENT
            if(strcmp(word_split_array[1],MEM_SEGMENT_ARGUMENT) == 0){
                char *arg_value = word_split_array[2];
                build_push_argument_command(arg_value,hack_asm_init_array);
                printf("Debug: Push Argument %s, Count: %d \n",arg_value,counter);
            }

            //  LOCAL MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_LOCAL) == 0)
            {
                char *local_value = word_split_array[2];
                build_push_local_command(local_value,hack_asm_init_array);
                printf("Debug: Push local %s, Count: %d \n",local_value,counter);
            }
            
            //  TEMP MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_TEMP) == 0)
            {
                char *temp_value = word_split_array[2];
                build_push_temp_command(temp_value,hack_asm_init_array);
                printf("Debug: Push temp %s, Count: %d \n",temp_value,counter);
            }  

            //  THAT MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_THAT) == 0)
            {
                char *that_value = word_split_array[2];
                build_push_that_command(that_value,hack_asm_init_array);
                printf("Debug: Push that %s, Count: %d \n",that_value,counter);
            }

            //  THIS MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_THIS) == 0)
            {
                char *this_value = word_split_array[2];
                build_push_this_command(this_value,hack_asm_init_array);
                printf("Debug: Push this %s, Count: %d \n",this_value,counter);
            }

            //  POINTER MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_POINTER) == 0)
            {
                char *pointer_value = word_split_array[2];
                build_push_pointer_command(pointer_value,hack_asm_init_array);
                printf("Debug: Push pointer %s, Count: %d \n",pointer_value,counter);
            }
            
            //  STATIC MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_STATIC) == 0)
            {
                char *static_value = word_split_array[2];
                build_push_static_command(static_value,hack_asm_init_array,STATIC_TEST_VM_FILENAME_WITHOUT_EXTENSION);
                printf("Debug: Push static %s, Count: %d \n",static_value,counter);
            }
            
                    
        }

        if(strcmp(word_split_array[0],STACK_POP) == 0){
            
            //  Pop command

            //  ARG MEMORY SEGMENT
            if(strcmp(word_split_array[1],MEM_SEGMENT_ARGUMENT) == 0){
                char *arg_value = word_split_array[2];
                build_pop_argument_command(arg_value,hack_asm_init_array);
                printf("Debug: Pop Argument %s, Count: %d \n",arg_value,counter);
            }

            //  LOCAL MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_LOCAL) == 0)
            {
                char *local_value = word_split_array[2];
                build_pop_local_command(local_value,hack_asm_init_array);
                printf("Debug: Pop local %s, Count: %d \n",local_value,counter);
            }
            
            //  TEMP MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_TEMP) == 0)
            {
                char *temp_value = word_split_array[2];
                build_pop_temp_command(temp_value,hack_asm_init_array);
                printf("Debug: Pop temp %s, Count: %d \n",temp_value,counter);
            }  

            //  THAT MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_THAT) == 0)
            {
                char *that_value = word_split_array[2];
                build_pop_that_command(that_value,hack_asm_init_array);
                printf("Debug: Pop that %s, Count: %d \n",that_value,counter);
            }

            //  THIS MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_THIS) == 0)
            {
                char *this_value = word_split_array[2];
                build_pop_this_command(this_value,hack_asm_init_array);
                printf("Debug: Pop this %s, Count: %d \n",this_value,counter);
            }

            //  POINTER MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_POINTER) == 0)
            {
                char *pointer_value = word_split_array[2];
                build_pop_pointer_command(pointer_value,hack_asm_init_array);
                printf("Debug: Pop pointer %s, Count: %d \n",pointer_value,counter);
            }
            
            //  STATIC MEMORY SEGMENT
            if (strcmp(word_split_array[1],MEM_SEGMENT_STATIC) == 0)
            {
                char *static_value = word_split_array[2];
                build_pop_static_command(static_value,hack_asm_init_array,STATIC_TEST_VM_FILENAME_WITHOUT_EXTENSION);
                printf("Debug: Pop static %s, Count: %d \n",static_value,counter);
            }

        }
        // ADD
        if (strcmp(word_split_array[0],STACK_ADD) == 0)
        {
            build_add_command(hack_asm_init_array);
            printf("Debug: Add command, Count: %d  \n",counter);
        }
        // SUB
        if (strcmp(word_split_array[0],STACK_SUB) == 0)
        {
            build_sub_command(hack_asm_init_array);
            printf("Debug: Sub command, Count: %d  \n",counter);
        }    
        // EQUAL
        if (strcmp(word_split_array[0],STACK_EQ) == 0)
        {
            build_equal_command(hack_asm_init_array);
             printf("Debug: EQ command, Count: %d \n",counter);
        }

        // GREATER THAN
        if (strcmp(word_split_array[0],STACK_GT) == 0)
        {
            build_greater_than_command(hack_asm_init_array);
            printf("Debug: GT command, Count: %d \n",counter);
        }

        // LESS THAN
        if (strcmp(word_split_array[0],STACK_LT) == 0)
        {
            build_less_than_command(hack_asm_init_array);
            printf("Debug: LT command, Count: %d \n",counter);
        }

        // NEG
        if (strcmp(word_split_array[0],STACK_NEG) == 0)
        {
            build_neg_command(hack_asm_init_array);
            printf("Debug: NEG command, Count: %d \n",counter);
        }

        // NOT
        if (strcmp(word_split_array[0],STACK_NOT) == 0)
        {
            build_not_command(hack_asm_init_array);
            printf("Debug: NOT command, Count: %d\n",counter);
        }

        // OR
        if (strcmp(word_split_array[0],STACK_OR) == 0)
        {
            build_or_command(hack_asm_init_array);
            printf("Debug: OR command, Count: %d \n",counter);
        }
        // AND
        if (strcmp(word_split_array[0],STACK_AND) == 0)
        {
            build_and_command(hack_asm_init_array);
            printf("Debug: AND command , Count: %d\n",counter);
        }
        
        //  LABEL
        if (strcmp(word_split_array[0],LABEL_COMMAND) == 0)
        {
            
            char *label_value = word_split_array[1];
            build_label_command(hack_asm_init_array, word_split_array[1]);
            printf("Debug: Label %s Count: %d\n",label_value,counter);
        }
        //  IF-GOTO
        if (strcmp(word_split_array[0],IF_GOTO_COMMAND) == 0)
        {
            
            char *label_value = word_split_array[1];
            build_if_goto_command(hack_asm_init_array, word_split_array[1]);
            printf("Debug: if-goto command %s Count: %d\n",label_value,counter);
        }
        //  GOTO
        if (strcmp(word_split_array[0],GOTO_COMMAND) == 0)
        {
            char *label_value = word_split_array[1];
            build_goto_command(hack_asm_init_array, word_split_array[1]);
            printf("Debug: goto command %s Count: %d\n",label_value,counter);
        }
        
        char *function_name = {0};
        //  FUNCTION DECLARATION
        if (strcmp(word_split_array[0],FUNCTION_LABEL) == 0)
        {
            function_name = word_split_array[1];
            int local_variable_count = atoi(word_split_array[2]); //  Convert string to int
            build_function_declaration_command(hack_asm_init_array,function_name,local_variable_count);
            printf("Debug: function declaration command %s Count: %d\n",function_name,counter);
        }

        if (strcmp(word_split_array[0],FUNCTION_RETURN) == 0)
        {
            char *function_name = word_split_array[1];
            int local_variable_count = atoi(word_split_array[2]); //  Convert string to int
            build_function_declaration_command(hack_asm_init_array,function_name,local_variable_count);
            printf("Debug: function return command %s Count: %d\n",function_name,counter);
        }
        //  RETURN
        
        
        

    }

    //print contents of the hack asm which is the final result
    print_double_pointer_array(hack_asm_init_array);
    
}

void print_double_pointer_array(char ** double_pointer_array){
    int line_counter = 0;
    while (double_pointer_array[line_counter] != NULL)
    {
        printf("%s \n",double_pointer_array[line_counter]);
        line_counter++;
    }
}

void read_file(char *filename, char *buffer){

    FILE *filepointer;
    filepointer = fopen(filename, "r");
    if (filepointer != NULL)
    {
        fread(buffer,MAX_BUFF,1,filepointer);
        fclose(filepointer);
    }else
    {
        printf("File %s does not exist",filename);
        buffer = NULL;
    }
    
}

/**
 * Checks, whether a given string is empty or not
 * A string is empty if it only contains white space characters
 * 
 * Returns 1 if the string is empty otherwise 0
*/

int is_empty(const char *str){

    char ch;

    do
    {
        ch = *(str++); //eat the string character by character
        
        //Check for non-whitespace character
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
        {
           return 0;
        }
        

    } while (ch != '\0');

    return 1;
    
}
/**
 * Removes empty line from a file and copies the content to a temp file
*/
void remove_empty_lines(FILE *src_file,FILE *tmp_file){

    char buffer[MAX_BUFF];

    // read the source file line by line with fgets with MAX_BUFF as the maximum size of characters in one line
    // --->You must be mad to have up to 4096 characters on one line :(
    
    while ((fgets(buffer,MAX_BUFF,src_file)) != NULL)
    {
        //If current line is not empty then write to temporary file
        if (!is_empty(buffer))
        {
            fputs(buffer,tmp_file);
        }
       
    }
    
}

/**
 * @brief this function is an flavour of eat_comment
 * This function only removes comment lines and leaves the rest of the commands as they are
 * while eat_comment removes comment and space between words
*/
void eat_comment_allow_space_between_command(char *line, char *new_line){

    char ch;
    size_t count = 0;
    size_t forwardslash_count = 0;

    do
    {
        ch = *(line++); //eat line, character by character and keep track of count
        ++count;

        if (ch == '/')
        {
            ++forwardslash_count;
        }else {
            
            // if(ch != ' '){ // do not copy space
                char *ch_ptr = &ch;
                strncat(new_line,ch_ptr,1);
            // }
                      
        }
        
        // when we are sure this is a comment, append \n to the last postion of the new_line,
        // we do this because when eating the comment, we don't get to the end of the line so
        // the line does not terminate with \n, therefore we have to add this manually
        if (forwardslash_count == 2) 
        {          
            char new_line_ch = '\n';
            char *new_line_ch_ptr = &new_line_ch;
            strncat(new_line,new_line_ch_ptr,1);
        }

    } while (ch != '\0' && forwardslash_count != 2);
    
    //make sure new_line terminates with \n
    int new_line_length = strlen(new_line);
    char last_char = new_line[new_line_length - 1];
    
}

void eat_comment(char *line, char *new_line){

    char ch;
    size_t count = 0;
    size_t forwardslash_count = 0;

    do
    {
        ch = *(line++); //eat line, character by character and keep tract of count
        ++count;

        if (ch == '/')
        {
            ++forwardslash_count;
        }else {
            
            if(ch != ' '){ // do not copy space
                char *ch_ptr = &ch;
                strncat(new_line,ch_ptr,1);
            }
                      
        }
        
        // when we are sure this is a comment, append \n to the last postion of the new_line,
        // we do this because when eating the comment, we don't get to the end of the line so
        // the line does not terminate with \n, therefore we have to add this manually
        if (forwardslash_count == 2) 
        {          
            char new_line_ch = '\n';
            char *new_line_ch_ptr = &new_line_ch;
            strncat(new_line,new_line_ch_ptr,1);
        }

    } while (ch != '\0' && forwardslash_count != 2);
    
    //make sure new_line terminates with \n
    int new_line_length = strlen(new_line);
    char last_char = new_line[new_line_length - 1];
    
}

void remove_comments(FILE *src_file,FILE *tmp_file){

    int line_number = 0;
    char buffer[MAX_BUFF] = {0};
    
    // read file line by line


    while ((fgets(buffer,MAX_BUFF,src_file)) != NULL)
    {
        char new_line_without_comment[MAX_BUFF] = {0};
        //If current line has comment, eat the comment and copy to new line
       
        eat_comment_allow_space_between_command(buffer,new_line_without_comment);
        if (new_line_without_comment[0] != '\n') // do not allow empty line to pass
        {
            // printf("No comment Line %d: %s",count,new_line_without_comment);
             ++line_number;
            fputs(new_line_without_comment,tmp_file);
        }
        
    }
    
}

void print_file_buffer(char *buffer){

    if (buffer != NULL)
    {
          printf("%s \n", buffer);
    }else
    {
        printf("File is empty");

    }
      
}

void print_file_stream(FILE *stream){

    char buffer[MAX_BUFF] = {0};

     if (stream != NULL)
    {
        fread(buffer,MAX_BUFF,1,stream);
    }else
    {
        printf("File does not exist");
    }
    
    print_file_buffer(buffer);

    //Close the stream after this function is called
}

/** @internal
Strip comments and leading and trailing whitespace from a string.
Return a pointer to the first nonspace char in the string.
*/
static char *strip_whitespace(char* p1)
{
	char *p2, *p3;

	p3 = p1;
	while ((p2 = strchr(p3,'#')) != 0) {  /* strip the comment */
		/* but allow # to be escaped by \ */
		if (p2 > p1 && (*(p2 - 1) == '\\')) {
			p3 = p2 + 1;
			continue;
		}
		*p2 = '\0';
		break;
	}

	/* strip leading whitespace */
	while(isspace(p1[0])) p1++;
	/* strip trailing whitespace */
	while(p1[0] != '\0' && isspace(p1[strlen(p1)-1]))
		p1[strlen(p1)-1] = '\0';

	return p1;
}


/**
 * @brief: This is the function that runs the first project [Simple Add] Chapter 7: Part 1
*/
void simple_add_vm_file(FILE *src_file,FILE *tmp_file){

    // Remove empty lines from file

    src_file = fopen(SIMPLE_ADD_VM, "r");          // opens source file for reading
    tmp_file = fopen(SIMPLE_ADD_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);  
    
    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(SIMPLE_ADD_VM); 
    rename(SIMPLE_ADD_VM_TEMP,SIMPLE_ADD_VM);

    //TODO: debug line remove
    //Open src file and print its contents so we can see empty lines removed
    printf("Print content after removing empty lines \n\n");
    src_file = fopen(SIMPLE_ADD_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(SIMPLE_ADD_VM, "r");
    tmp_file = fopen(SIMPLE_ADD_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(SIMPLE_ADD_VM);
    rename(SIMPLE_ADD_VM_TEMP,SIMPLE_ADD_VM);
    
    //TODO: debug line remove
    //Open src file and print its contents
    printf("Print content after removing comment \n\n");
    src_file = fopen(SIMPLE_ADD_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);


    // Parse the VM code to generate hack asm code

    printf("\n Parsing VM code -> Hack ASM code \n\n");

    // Open src file 
    src_file = fopen(SIMPLE_ADD_VM, "r");
    parse_vm_code(src_file);
    //close file
    fclose(src_file);

}

/**
 * @brief: This is the function that runs the second project [Stack Test] Chapter 7: Part 1
*/
void stack_test_vm_file(FILE *src_file,FILE *tmp_file){

    // Remove empty lines from file

    src_file = fopen(STACK_TEST_VM, "r");           // opens source file for reading
    tmp_file = fopen(STACK_TEST_VM_TEMP, "w");      // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);  
    
    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(STACK_TEST_VM); 
    rename(STACK_TEST_VM_TEMP,STACK_TEST_VM);

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(STACK_TEST_VM, "r");
    tmp_file = fopen(STACK_TEST_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(STACK_TEST_VM);
    rename(STACK_TEST_VM_TEMP,STACK_TEST_VM);
    
    //TODO: debug line remove
    //Open src file and print its contents
    printf("Print content after removing comment \n\n");
    src_file = fopen(STACK_TEST_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    // Parse the VM code to generate hack asm code

    printf("\n Parsing STACKTEST VM code -> Hack ASM code \n\n");

    // Open src file 
    src_file = fopen(STACK_TEST_VM, "r");
    parse_vm_code(src_file);
    //close file
    fclose(src_file);
}
/**
 * @brief: This is the function that runs the first project [Basic Test] Chapter 7: Part 2
*/
void basic_test_vm_file(FILE *src_file,FILE *tmp_file){
    // Remove empty lines from file

    src_file = fopen(BASIC_TEST_VM, "r");           // opens source file for reading
    tmp_file = fopen(BASIC_TEST_VM_TEMP, "w");      // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);  
    
    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(BASIC_TEST_VM); 
    rename(BASIC_TEST_VM_TEMP,BASIC_TEST_VM);

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(BASIC_TEST_VM, "r");
    tmp_file = fopen(BASIC_TEST_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(BASIC_TEST_VM);
    rename(BASIC_TEST_VM_TEMP,BASIC_TEST_VM);
    
    //TODO: debug line remove
    //Open src file and print its contents
    printf("Print content after removing comment \n\n");
    src_file = fopen(BASIC_TEST_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    // Parse the VM code to generate hack asm code

    printf("\n Parsing STACKTEST VM code -> Hack ASM code \n\n");

    // Open src file 
    src_file = fopen(BASIC_TEST_VM, "r");
    parse_vm_code(src_file);
    //close file
    fclose(src_file);
}

void pointer_test_vm_file(FILE *src_file,FILE *tmp_file){

    // Remove empty lines from file

    src_file = fopen(POINTER_TEST_VM, "r");           // opens source file for reading
    tmp_file = fopen(POINTER_TEST_VM_TEMP, "w");      // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);  
    
    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(POINTER_TEST_VM); 
    rename(POINTER_TEST_VM_TEMP,POINTER_TEST_VM);

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(POINTER_TEST_VM, "r");
    tmp_file = fopen(POINTER_TEST_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(POINTER_TEST_VM);
    rename(POINTER_TEST_VM_TEMP,POINTER_TEST_VM);
    
    //TODO: debug line remove
    //Open src file and print its contents
    printf("Print content after removing comment \n\n");
    src_file = fopen(POINTER_TEST_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    // Parse the VM code to generate hack asm code

    printf("\n Parsing POINTER TEST VM code -> Hack ASM code \n\n");

    // Open src file 
    src_file = fopen(POINTER_TEST_VM, "r");
    parse_vm_code(src_file);
    //close file
    fclose(src_file);
}

void static_test_vm_file(FILE *src_file,FILE *tmp_file){

    // Remove empty lines from file

    src_file = fopen(STATIC_TEST_VM, "r");           // opens source file for reading
    tmp_file = fopen(STATIC_TEST_VM_TEMP, "w");      // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);  
    
    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(STATIC_TEST_VM); 
    rename(STATIC_TEST_VM_TEMP,STATIC_TEST_VM);

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(STATIC_TEST_VM, "r");
    tmp_file = fopen(STATIC_TEST_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(STATIC_TEST_VM);
    rename(STATIC_TEST_VM_TEMP,STATIC_TEST_VM);
    
    //TODO: debug line remove
    //Open src file and print its contents
    printf("Print content after removing comment \n\n");
    src_file = fopen(STATIC_TEST_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    // Parse the VM code to generate hack asm code

    printf("\n Parsing POINTER TEST VM code -> Hack ASM code \n\n");

    // Open src file 
    src_file = fopen(STATIC_TEST_VM, "r");
    parse_vm_code(src_file);
    //close file
    fclose(src_file);
}

void basic_loop_vm_file(FILE *src_file,FILE *tmp_file){

    // Remove empty lines from file

    src_file = fopen(BASIC_LOOP_TEST_VM, "r");           // opens source file for reading
    tmp_file = fopen(BASIC_LOOP_TEST_VM_TEMP, "w");      // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);  
    
    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(BASIC_LOOP_TEST_VM); 
    rename(BASIC_LOOP_TEST_VM_TEMP,BASIC_LOOP_TEST_VM);

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(BASIC_LOOP_TEST_VM, "r");
    tmp_file = fopen(BASIC_LOOP_TEST_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(BASIC_LOOP_TEST_VM);
    rename(BASIC_LOOP_TEST_VM_TEMP,BASIC_LOOP_TEST_VM);
    
    //TODO: debug line remove
    //Open src file and print its contents
    printf("Print content after removing comment \n\n");
    src_file = fopen(BASIC_LOOP_TEST_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    // Parse the VM code to generate hack asm code

    printf("\n Parsing POINTER TEST VM code -> Hack ASM code \n\n");

    // Open src file 
    src_file = fopen(BASIC_LOOP_TEST_VM, "r");
    parse_vm_code(src_file);
    //close file
    fclose(src_file);
}
void fibonacci_series_vm_file(FILE *src_file,FILE *tmp_file){

    // Remove empty lines from file

    src_file = fopen(FIBONACCI_SERIES_VM, "r");           // opens source file for reading
    tmp_file = fopen(FIBONACCI_SERIES_VM_TEMP, "w");      // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);  
    
    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(FIBONACCI_SERIES_VM); 
    rename(FIBONACCI_SERIES_VM_TEMP,FIBONACCI_SERIES_VM);

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(FIBONACCI_SERIES_VM, "r");
    tmp_file = fopen(FIBONACCI_SERIES_VM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(FIBONACCI_SERIES_VM);
    rename(FIBONACCI_SERIES_VM_TEMP,FIBONACCI_SERIES_VM);
    
    //TODO: debug line remove
    //Open src file and print its contents
    printf("Print content after removing comment \n\n");
    src_file = fopen(FIBONACCI_SERIES_VM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    // Parse the VM code to generate hack asm code

    printf("\n Parsing POINTER TEST VM code -> Hack ASM code \n\n");

    // Open src file 
    src_file = fopen(FIBONACCI_SERIES_VM, "r");
    parse_vm_code(src_file);
    //close file
    fclose(src_file);
}

int main(int argc, char * argv[]){

    
    /********************* Process SIMPLE ADD VM file *****************/
    
    //1. Read File

    // 2b. Remove empty lines from file
    FILE *src_file;
    FILE *tmp_file;

    if(FALSE){  // just dont run the block of code below.
        simple_add_vm_file(src_file,tmp_file); 
    }
    
    /**************** Process STACK TEST VM file **********************/

    if(FALSE){
        stack_test_vm_file(src_file,tmp_file);
    }

    /**************** Process BASIC TEST VM file **********************/

    if (FALSE)
    {
        basic_test_vm_file(src_file,tmp_file);
    }

    /**************** Process POINTER TEST VM file **********************/   

    if(FALSE){
        pointer_test_vm_file(src_file,tmp_file);
    }

    /**************** Process STATIC TEST VM file **********************/   

    if(FALSE){
        static_test_vm_file(src_file,tmp_file);
    }

    if(FALSE){
        basic_loop_vm_file(src_file,tmp_file);
    }
    if(TRUE){
        fibonacci_series_vm_file(src_file,tmp_file);
    }
    return 0;
}