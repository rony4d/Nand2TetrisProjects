#include "../ChapterSix/assembler/dictionary.c"
#include "../ChapterSix/assembler/util.c"
/*

    This is the main VM Translator module . It  connects to other sub module for handling different tasks in the

    translation of VM Code code to assembly language. 

    This same VM Translator will be used to translate chapter seven VM Files
    
    This is where the magic happens. 

    @author: ugochukwu aronu

    references:
    -   Personal (Physical) Note
    -   Lecture Note - You can see how the parser and code writer modules are designed here from slide 107

    

    Steps
    -   Read the .vm file  - 
    -   Remove white space and comments and output the first file without comments or whitespace - 
    -   Create Arithmetic command code generator
    -   Create Push and Pop command code generator for each memory segment
    -  

    ToDo: Remove all imported .c files and replace them with their header files and link the .c files to the compiler 

*/


#define SIMPLE_ADD_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd.vm"
#define SIMPLE_ADD_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd_no_comment.vm"
#define SIMPLE_ADD_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd_no_whitespace.vm"
#define SIMPLE_ADD_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd.asm"

#define STACK_TEST_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/StackTest/StackTest.vm"
#define STACK_TEST_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/StackTest/StackTest_no_comment.vm"
#define STACK_TEST_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/StackTest/StackTest_no_whitespace.vm"
#define STACK_TEST_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/StackTest/StackTest.asm"

#define BASIC_TEST_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/BasicTest/BasicTest.vm"
#define BASIC_TEST_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/BasicTest/BasicTest_no_comment.vm"
#define BASIC_TEST_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/BasicTest/BasicTest_no_whitespace.vm"
#define BASIC_TEST_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/BasicTest/BasicTest.asm"


#define POINTER_TEST_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/PointerTest/PointerTest.vm"
#define POINTER_TEST_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/PointerTest/PointerTest_no_comment.vm"
#define POINTER_TEST_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/PointerTest/PointerTest_no_whitespace.vm"
#define POINTER_TEST_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/PointerTest/PointerTest.asm"


#define STATIC_TEST_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/StaticTest/StaticTest.vm"
#define STATIC_TEST_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/StaticTest/StaticTest_no_comment.vm"
#define STATIC_TEST_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/StaticTest/StaticTest_no_whitespace.vm"
#define STATIC_TEST_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/MemoryAccess/StaticTest/StaticTest.asm"
#define STATIC_FILENAME "StaticTest"    //  This will be used to build the static variable names : ToDo Write function to get this name from file path


//  Chapter 8 Projects
#define BASIC_LOOP_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/BasicLoop/BasicLoop.vm"
#define BASIC_LOOP_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/BasicLoop/BasicLoop_no_comment.vm"
#define BASIC_LOOP_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/BasicLoop/BasicLoop_no_whitespace.vm"
#define BASIC_LOOP_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/BasicLoop/BasicLoop.asm"


#define FIBONACCI_SERIES_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/FibonacciSeries/FibonacciSeries.vm"
#define FIBONACCI_SERIES_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/FibonacciSeries/FibonacciSeries_no_comment.vm"
#define FIBONACCI_SERIES_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/FibonacciSeries/FibonacciSeries_no_whitespace.vm"
#define FIBONACCI_SERIES_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/ProgramFlow/FibonacciSeries/FibonacciSeries.asm"


#define SIMPLE_FUNCTION_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/SimpleFunction/SimpleFunction.vm"
#define SIMPLE_FUNCTION_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/SimpleFunction/SimpleFunction_no_comment.vm"
#define SIMPLE_FUNCTION_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/SimpleFunction/SimpleFunction_no_whitespace.vm"
#define SIMPLE_FUNCTION_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/SimpleFunction/SimpleFunction.asm"

#define NESTED_CALL_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/NestedCall/Sys.vm"
#define NESTED_CALL_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/NestedCall/NestedCall_no_comment.vm"
#define NESTED_CALL_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/NestedCall/NestedCall_no_whitespace.vm"
#define NESTED_CALL_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/FunctionCalls/NestedCall/NestedCall.asm"


// todo: please remove 
#define NESTED_CALL_TEST_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/Test/NestedCall.asm"
#define NESTED_CALL_TEST_ASM_NO_COMMENT_OUTPUT_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/Test/NestedCall_Test_no_comment.asm"
#define NESTED_CALL_TEST_ASM_NO_WHITESPACE_VM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterEight/Test/NestedCall_Test_no_whitespace.asm"


//  Stack Arithmetic Commands
#define ADD_COMMAND "add"
#define SUB_COMMAND "sub"
#define NEG_COMMAND "neg"
#define EQ_COMMAND  "eq"
#define GT_COMMAND  "gt"
#define LT_COMMAND  "lt"
#define AND_COMMAND "and"
#define OR_COMMAND  "or"
#define NOT_COMMAND "not"

//  Memory Access Commands

#define PUSH_COMMAND "push"
#define POP_COMMAND "pop"


//  Memory Segments
#define LOCAL       "local"
#define ARGUMENT   "argument"
#define THIS        "this"
#define THAT        "that"
#define CONSTANT   "constant"
#define STATIC      "static"
#define TEMP        "temp"
#define POINTER     "pointer"

//  Program Control Commands - Branching Commands
#define GOTO_LABEL_COMMAND    "goto"
#define IF_GOTO_LABEL_COMMAND    "if-goto"
#define LABEL_COMMAND    "label"


//  Program Control Commands - Function Commands
#define CALL_FUNCTION_COMMAND   "call"                          //  call 'function'
#define FUNCTION_FUNCTION_COMMAND   "function"                  //  function 'function_name'
#define RETURN_FUNCTION_COMMAND   "return"



#define INITIALIZE_STACK_POINTER    0                                   //  set to 1 if you want the code to do the stack pointer initialization

int counter = 0;                                //  the universal counter for counting generated asm commands

Dict global_asm_dictionary;                     //  this dictionary holds all the asm commands
Dict global_caller_callee_function_dictionary;  

char * current_function_name = {0};         //  this is the current function which is being processed. NOTE: This function should change once a return is hit


//  Internal function declarations
void _initialize_asm_command_tables();
void _write_instructions_to_file(char * asm_output_filename);
void _make_label_variable_unique(char * label_variable, char * unique_label_variable, char * unique_label, int _counter);
void _make_variable_unique(char * variable, char * unique_variable, int _counter);


/**
 * Parser Module Function Initializations
*/

void parse_vm_command(char * vm_command, char *filename);
void parse_input_file(char * filename, char * input_vm_file, char * no_comment_output_vm_file,char * no_whitespace_output_vm_file, int max_file_zie);

void parse_command(char *memory_segment,int i,char *memory_access_command, char * filename );    

/**
 * Code Module Function Initializations
*/

//  Stack Arithmetic Code Generator Functions
void generate_add_asm_command();
void generate_eq_asm_command();
void generate_and_asm_command();
void generate_gt_asm_command();
void generate_lt_asm_command();
void generate_neg_asm_command();
void generate_not_asm_command();
void generate_or_asm_command();
void generate_sub_asm_command();

//  Stack Memory Access Code Generator Functions
void generate_constant_segment_asm_code(int constant_value);
void generate_local_segment_asm_code(int local_value, char * memory_access_command);
void generate_argument_segment_asm_code(int argument_value, char * memory_access_command);
void generate_this_segment_asm_code(int this_value, char * memory_access_command);
void generate_that_segment_asm_code(int that_value, char * memory_access_command);
void generate_temp_segment_asm_code(int temp_value, char * memory_access_command);
void generate_pointer_segment_asm_code(int pointer_value, char * memory_access_command);
void generate_static_segment_asm_code(int static_value, char * memory_access_command, char * filename);


//  Program Control Command Code Generator Functions

void generate_goto_label_command(char * function_name, char * label);
void generate_if_goto_label_command(char * function_name, char * label);
void generate_label_command(char * function_name, char * label);

void generate_call_function_command(char * caller_function_name, char * callee_function_name, int nArgs);  
void generate_function_function_command(char * function_name, int local_variables);
void generate_return_function_command(char * current_function_name);



/**
 * @brief: Code Module: This module generates appropriate assembly code for each VM command
 * @note: There should be a universal counter for each line of asm generated
 * @param generate_add_asm_command: This function is under the Code Module. It will generate the appropriate assembly code for add VM command
 *
*/


/**
 * @brief: Parser Module: This module parses the input
 * @param parse_input_file: This function takes the input file, removes comments a and then reads the VM Code line by line
 * @param parse_vm_command: This function parses the vm command into its component parts and then allows the code generator to do its magic
 *
*/




void parse_input_file(char * filename, char * input_vm_file, char * no_comment_output_vm_file,char * no_whitespace_output_vm_file, int max_file_zie)
{  
    //  1. remove comments and store in no_comment vm file

    remove_comment(input_vm_file,no_comment_output_vm_file);

    //  2. remove whitespace and write to no_whitespace asm file.

    remove_white_spaces(no_comment_output_vm_file,no_whitespace_output_vm_file,max_file_zie);

    //  3. read no_whitespace asm file and begin march through the lines. 

    FILE* file_ptr;
    char str[MAX_FILE_SIZE];

    file_ptr = fopen(no_whitespace_output_vm_file,"r");

    if (file_ptr == NULL)
    {
        printf("File can't be opened \n");
        exit(1);
    }
    
    //  read file line by line
    while (fgets(str,MAX_FILE_SIZE,file_ptr) != NULL)    
    {
        parse_vm_command(str,filename);        
        
    }

    fclose(file_ptr);
    
}


/**
 * @brief:  This function parses the vm_command (e.g push constant 7 ) and breaks it down into its components( push, constant , 7)
 *          
 *          
*/
void parse_vm_command(char * vm_command, char * filename)
{
    char * empty_space_delimiter = " ";

    char * command_type = {0};
    char * memory_segment = {0};
    int i;

    command_type = strtok(vm_command,empty_space_delimiter);


        

    int current_function_argument_count = {0};      //  Number of Arguments that were pushed to stack for this function

    char * current_label = {0};                     //  This is the current label 

    if(strncmp(command_type,"",sizeof(BINARY_MAX_BITS)) == 0)
    {
        //  return if the command type is empty
        return;
    }

    eat_white_space(command_type);

    //  Check for appropriate arithmetic or memory access command

    if (strncmp(command_type,ADD_COMMAND,sizeof(ADD_COMMAND)) == 0)
    {
        generate_add_asm_command();
    }
    else if(strncmp(command_type,SUB_COMMAND,sizeof(SUB_COMMAND)) == 0)
    {
        generate_sub_asm_command();
    }
    else if(strncmp(command_type,NEG_COMMAND,sizeof(NEG_COMMAND)) == 0)
    {
        generate_neg_asm_command();
    }
    else if(strncmp(command_type,EQ_COMMAND,sizeof(EQ_COMMAND)) == 0)
    {
        generate_eq_asm_command();
    }
    else if(strncmp(command_type,GT_COMMAND,sizeof(GT_COMMAND)) == 0)
    {
        generate_gt_asm_command();
    }
    else if(strncmp(command_type,LT_COMMAND,sizeof(LT_COMMAND)) == 0)
    {
        generate_lt_asm_command();
    }
    else if(strncmp(command_type,AND_COMMAND,sizeof(AND_COMMAND)) == 0)
    {
        generate_and_asm_command();
    }
    else if(strncmp(command_type,OR_COMMAND,sizeof(OR_COMMAND)) == 0)
    {
        generate_or_asm_command();
    }

    else if(strncmp(command_type,NOT_COMMAND,sizeof(NOT_COMMAND)) == 0)
    {
        generate_not_asm_command();
    }
    else if(strncmp(command_type,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
    {
        //  parse push command code
        memory_segment = strtok(NULL,empty_space_delimiter);

        char * i_str = {0};

        i_str = strtok(NULL,empty_space_delimiter);

        i = convert_string_to_number(i_str);

        parse_command(memory_segment,i,PUSH_COMMAND,filename);

    }
    else if(strncmp(command_type,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
    {
        //  parse pop command code
        memory_segment = strtok(NULL,empty_space_delimiter);

        char * i_str = {0};

        i_str = strtok(NULL,empty_space_delimiter);

        i = convert_string_to_number(i_str);

        parse_command(memory_segment,i,POP_COMMAND,filename);
    }


    
    //  Check for appropriate program control command

    
    if (strncmp(command_type,FUNCTION_FUNCTION_COMMAND,sizeof(FUNCTION_FUNCTION_COMMAND)) == 0)
    {
       //   if current_function_name already exists then we will continuous use the name till another function name replaces or we hit a return statement ( we will process return later )

        current_function_name = strtok(NULL, empty_space_delimiter);

        char * function_argument_count_str = {0};


        function_argument_count_str = strtok(NULL,empty_space_delimiter);

        current_function_argument_count = convert_string_to_number(function_argument_count_str);

        generate_function_function_command(current_function_name,current_function_argument_count);

    }
    else if (strncmp(command_type,CALL_FUNCTION_COMMAND,sizeof(CALL_FUNCTION_COMMAND)) == 0)
    {
        char * caller_function_name = {0};        
        char * callee_function_name = {0}; 
        caller_function_name = current_function_name;

        callee_function_name = strtok(NULL, empty_space_delimiter);

        char * function_argument_count_str = {0};


        function_argument_count_str = strtok(NULL,empty_space_delimiter);

        current_function_argument_count = convert_string_to_number(function_argument_count_str);

        generate_call_function_command(caller_function_name,callee_function_name,current_function_argument_count);
    }

    else if (strncmp(command_type,RETURN_FUNCTION_COMMAND,sizeof(RETURN_FUNCTION_COMMAND)) == 0)
    {
        // //  NOTE:   Before a return command is triggered a function command must have been processed, hence the assumption that current_function_name can't be NULL. 
        // //          But previous_function_name can be NULL if there is no caller function and this function is the first function in the VM Code

        // if (previous_function_name == NULL)
        // {
        //     previous_function_name = strdup("null");
        // }
        
        generate_return_function_command(current_function_name);
    }
    
    
    
    if (strncmp(command_type,GOTO_LABEL_COMMAND,sizeof(GOTO_LABEL_COMMAND)) == 0)
    {

        //  if current_function_name is empty then use null as function name

        if (current_function_name == NULL)
        {          
            current_function_name = strndup("null",strlen("null"));
        }
        
        current_label = strtok(NULL, empty_space_delimiter);

        eat_white_space(current_label);
    
        generate_goto_label_command(current_function_name,current_label);
    }

    else if (strncmp(command_type,IF_GOTO_LABEL_COMMAND,sizeof(IF_GOTO_LABEL_COMMAND)) == 0)
    {

        //  if current_function_name is empty then use null as function name

        if (current_function_name == NULL)
        {           
            current_function_name = strndup("null",strlen("null"));
        }

        current_label = strtok(NULL, empty_space_delimiter);

        eat_white_space(current_label);

        generate_if_goto_label_command(current_function_name,current_label);
    }

    else if (strncmp(command_type,LABEL_COMMAND,sizeof(LABEL_COMMAND)) == 0)
    {
        //  if current_function_name is empty then use null as function name

        if (current_function_name == NULL)
        {           
            current_function_name = strndup("null",strlen("null"));
        }

        current_label = strtok(NULL, empty_space_delimiter);

        eat_white_space(current_label);

        generate_label_command(current_function_name,current_label);
    }
    

    
    
}

/**
 * @brief:  This function is under the Parser Module. It will process the push command based on the memory segment and then link the 
 *          code generation modeule to generate the appropriate assembly code
*/
void parse_command(char *memory_segment,int i, char* memory_access_command, char * filename)
{
    //  Check for appropriate memory segment of the stack we are pushing to
    if (strncmp(memory_segment,LOCAL,sizeof(LOCAL)) == 0)
    {
        generate_local_segment_asm_code(i,memory_access_command);
    }
    else if(strncmp(memory_segment,ARGUMENT,sizeof(ARGUMENT)) == 0)
    {
        generate_argument_segment_asm_code(i,memory_access_command);
    }
    else if(strncmp(memory_segment,THIS,sizeof(THIS)) == 0)
    {
        generate_this_segment_asm_code(i,memory_access_command);
    }
    else if(strncmp(memory_segment,THAT,sizeof(THAT)) == 0)
    {
        generate_that_segment_asm_code(i,memory_access_command);
    }
    else if(strncmp(memory_segment,CONSTANT,sizeof(CONSTANT)) == 0)
    {
        generate_constant_segment_asm_code(i);
    }
    else if(strncmp(memory_segment,STATIC,sizeof(STATIC)) == 0)
    {
        generate_static_segment_asm_code(i,memory_access_command,filename);
    }
    else if(strncmp(memory_segment,TEMP,sizeof(TEMP)) == 0)
    {
        generate_temp_segment_asm_code(i,memory_access_command);
    }
    else if(strncmp(memory_segment,POINTER,sizeof(POINTER)) == 0)
    {
        generate_pointer_segment_asm_code(i,memory_access_command);
    }
    
}

/**
 * @brief:  This function is under the Code Module. It will generate the appropriate assembly code for add VM command
*/
void generate_add_asm_command()
{
    
    //  add

    // @SP
    // M=M-1
    // A=M
    // D=M
    // @SP
    // M=M-1
    // A=M
    // D=D+M
    // @SP
    // A=M
    // M=D
    // @SP
    // M=M+1

    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=D+M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;
}

void generate_eq_asm_command()
{
    
    //  eq ( if operands are equal, return -1 which is true for the VM language and 0 which is 0 )

    // @SP
    // M=M-1

    // A=M
    // D=M

    // @SP
    // M=M-1

    // A=M
    // D=D-M


    // @EQUAL
    // D;JEQ

    // @NOT_EQUAL
    // D;JNE


    // (EQUAL)
    // @SP
    // A=M
    // M=-1
    // @INCREMENT_SP
    // 0;JMP



    // (NOT_EQUAL)
    // @SP
    // A=M
    // M=0
    // @INCREMENT_SP
    // 0;JMP


    // (INCREMENT_SP)  //  Jump here after either Equal or Not Equal is processed to finish the code block

    // @SP
    // M=M+1


    //   Ensure all user defined variables are unique in this code block to prevent conflict in the general codebase

    char unique_label_variable_equal[BINARY_MAX_BITS] = {0}; 
    char unique_label_equal[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("EQUAL",unique_label_variable_equal,unique_label_equal,counter);

    char unique_label_variable_notequal[BINARY_MAX_BITS] = {0}; 
    char unique_label_notequal[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("NOT_EQUAL",unique_label_variable_notequal,unique_label_notequal,counter);


    char unique_label_variable_increment_sp[BINARY_MAX_BITS] = {0}; 
    char unique_label_increment_sp[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("INCREMENT_SP",unique_label_variable_increment_sp,unique_label_increment_sp,counter);


    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);




    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;




    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=D-M");

    counter = counter + 1;




    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_equal);    // (@EQUAL)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D;JEQ");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_notequal);   //  @NOT_EQUAL

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D;JNE");

    counter = counter + 1;
 

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_equal); //  (EQUAL)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=-1");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_increment_sp);       //  @INCREMENT_SP

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_notequal);                    //  (NOT_EQUAL)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=0");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_increment_sp);       //  @INCREMENT_SP

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_increment_sp);                //  (INCREMENT_SP)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;
}

void generate_and_asm_command()
{
    //  and

    // @SP
    // M=M-1
    // A=M
    // D=M     //  operand two
    // @SP
    // M=M-1
    // A=M
    // D=D&M   //  operand one & operand two. Refer to Chapter 4 lecture note or text to see the table

    // @SP
    // A=M
    // M=D


    // @SP
    // M=M+1

    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=D&M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;


}

void generate_gt_asm_command()
{
    //  gt ( if first operand is greater than second operand, return -1 which is true for the VM language and 0 which is 0 )

    // @SP
    // M=M-1

    // A=M
    // D=M     //  second operand

    // @SP
    // M=M-1

    // A=M
    // D=M-D   //  first operand minus second operand 


    // @GREATER_THAN      //  if first operand minus second operand is greater than zero, then gt is satisfied
    // D;JGT

    // @NOT_GREATER_THAN  //  if first operand minus second operand is less than zero or equal to zero, then gt is not satisfied
    // D;JLE


    // (GREATER_THAN)
    // @SP
    // A=M
    // M=-1
    // @INCREMENT_SP
    // 0;JMP



    // (NOT_GREATER_THAN)
    // @SP
    // A=M
    // M=0
    // @INCREMENT_SP
    // 0;JMP


    // (INCREMENT_SP)  //  Jump here after either Greater Than or Not Greater Than is processed to finish the code block

    // @SP
    // M=M+1



    //   Ensure all user defined variables are unique in this code block to prevent conflict in the general codebase

    char unique_label_variable_greater_than[BINARY_MAX_BITS] = {0}; 
    char unique_label_greater_than[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("GREATER_THAN",unique_label_variable_greater_than,unique_label_greater_than,counter);

    char unique_label_variable_not_greater_than[BINARY_MAX_BITS] = {0}; 
    char unique_label_not_greater_than[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("NOT_GREATER_THAN",unique_label_variable_not_greater_than,unique_label_not_greater_than,counter);


    char unique_label_variable_increment_sp[BINARY_MAX_BITS] = {0}; 
    char unique_label_increment_sp[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("INCREMENT_SP",unique_label_variable_increment_sp,unique_label_increment_sp,counter);


    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;




    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_greater_than);      //  @GREATER_THAN

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D;JGT");

    counter = counter + 1;



    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_not_greater_than);  //  @NOT_GREATER_THAN

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D;JLE");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_greater_than);     //  (GREATER_THAN)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=-1");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_increment_sp);      //  @INCREMENT_SP

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");

    counter = counter + 1;



    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_not_greater_than);     //  (NOT_GREATER_THAN)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=0");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_increment_sp);      //  @INCREMENT_SP

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_increment_sp);     //  (INCREMENT_SP)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;

}

void generate_lt_asm_command()
{

    //  lt ( if first operand is less than second operand, return -1 which is true for the VM language and 0 which is 0 )

    // @SP
    // M=M-1

    // A=M
    // D=M     //  second operand

    // @SP
    // M=M-1

    // A=M
    // D=M-D   //  first operand minus second operand 


    // @LESS_THAN      //  if first operand minus second operand is less than zero, then lt is satisfied
    // D;JLT

    // @NOT_LESS_THAN  //  if first operand minus second operand is greater than zero or equal to zero, then lt is not satisfied
    // D;JGE


    // (LESS_THAN)
    // @SP
    // A=M
    // M=-1
    // @INCREMENT_SP
    // 0;JMP



    // (NOT_LESS_THAN)
    // @SP
    // A=M
    // M=0
    // @INCREMENT_SP
    // 0;JMP


    // (INCREMENT_SP)  //  Jump here after either Less Than or Not Less Than is processed to finish the code block

    // @SP
    // M=M+1


    //   Ensure all user defined variables are unique in this code block to prevent conflict in the general codebase

    char unique_label_variable_less_than[BINARY_MAX_BITS] = {0}; 
    char unique_label_less_than[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("LESS_THAN",unique_label_variable_less_than,unique_label_less_than,counter);

    char unique_label_variable_not_less_than[BINARY_MAX_BITS] = {0}; 
    char unique_label_not_less_than[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("NOT_LESS_THAN",unique_label_variable_not_less_than,unique_label_not_less_than,counter);


    char unique_label_variable_increment_sp[BINARY_MAX_BITS] = {0}; 
    char unique_label_increment_sp[BINARY_MAX_BITS] = {0};

    _make_label_variable_unique("INCREMENT_SP",unique_label_variable_increment_sp,unique_label_increment_sp,counter);


    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;




    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_less_than);     //  @LESS_THAN

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D;JLT");

    counter = counter + 1;



    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_not_less_than);     //  @NOT_LESS_THAN

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D;JGE");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_less_than);        //  (LESS_THAN)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=-1");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_increment_sp);          //  @INCREMENT_SP"

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");

    counter = counter + 1;



    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_not_less_than);        //  (NOT_LESS_THAN)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=0");

    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_variable_increment_sp);          //  @INCREMENT_SP

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,unique_label_increment_sp);         //  (INCREMENT_SP)

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;

}

void generate_neg_asm_command()
{
    //  neg

    // @SP
    // M=M-1
    // A=M
    // M=-M    //  negate the value stored in RAM[A]


    // @SP
    // M=M+1

    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=-M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;


}

void generate_not_asm_command()
{
     
    //  not

    // @SP
    // M=M-1
    // A=M
    // M=!M    //  not the value stored in RAM[A]


    // @SP
    // M=M+1


    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=!M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;

}

void generate_or_asm_command()
{
    //  or

    // @SP
    // M=M-1
    // A=M
    // D=M     //  operand two
    // @SP
    // M=M-1
    // A=M
    // D=D|M   //  operand one | operand two. Refer to Chapter 4 lecture note or text to see the table

    // @SP
    // A=M
    // M=D


    // @SP
    // M=M+1

    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");
    
    counter = counter + 1;
    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=D|M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;

}

void generate_sub_asm_command()
{
    
    
    //  sub

    // @SP
    // M=M-1
    // A=M
    // D=M     //  operand two
    // @SP
    // M=M-1
    // A=M
    // D=M-D   //  operand one minus operand two
    // @SP
    // A=M
    // M=D
    // @SP
    // M=M+1

    char counter_str[BINARY_MAX_BITS] = {0}; 
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");


    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");

    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");

    counter = counter + 1;
}

/**
 * @brief: This function pushes the 
 * @param constant_value: This is the value to be pushed into the stack virtual memory 
 * 
*/
void generate_constant_segment_asm_code(int constant_value)
{
    // push constant 7

    // @7
    // D=A

    // //  *SP = i
    // @SP
    // A=M
    // M=D


    char constant_value_str[BINARY_MAX_BITS] = {0};
    convert_to_string(constant_value,constant_value_str);

    char constant_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the constant_value. eg @7
    strncat(constant_value_asm_str,"@",strlen("@"));
    strncat(constant_value_asm_str,constant_value_str,strlen(constant_value_str));

    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,constant_value_asm_str);

    counter = counter + 1;

    
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"D=A");

    counter = counter + 1;

    
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");
    
    counter = counter + 1;

    
    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"A=M");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"M=D");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"@SP");
    
    counter = counter + 1;

    convert_to_string(counter,counter_str);

    DictInsert(global_asm_dictionary,counter_str,"M=M+1");
    
    counter = counter + 1;
}

void generate_local_segment_asm_code(int local_value, char * memory_access_command)
{
    if (strncmp(memory_access_command,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
    {
        // push local 0

        // push local i -> addr = LCL + i; *SP = *addr ; SP++

        // @0
        // D=A         //  i

        // @LCL
        // D=D+M       //  LCL + i

        // @addr
        // M=D

        // A=M
        // D=M         //  *addr


        // @SP
        // A=M
        // M=D         //  *SP = *addr

        // @SP
        // M=M+1       //  SP++

        char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

        _make_variable_unique("addr",unique_addr_variable,counter);


        char local_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(local_value,local_value_str);

        char local_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the local_value. eg @7
        strncat(local_value_asm_str,"@",strlen("@"));
        strncat(local_value_asm_str,local_value_str,strlen(local_value_str));

        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,local_value_asm_str);  //  @i

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=A");                

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@LCL");

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  LCL + i

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;
        

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  

        counter = counter + 1;

    }
    else if(strncmp(memory_access_command,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
    {
        //  pop local 0

        // @0          //  i
        // D=A

        // @LCL    
        // D=D+M       //  LCL + i

        // @addr
        // M=D         //  addr = LCL + i


        // @SP
        // M=M-1       //  SP--

        // @SP
        // A=M
        // D=M         // *SP

        // @addr
        // A=M
        // M=D         //  *addr = *SP 

        char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

        _make_variable_unique("addr",unique_addr_variable,counter);


        char local_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(local_value,local_value_str);

        char local_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the local_value. eg @7
        strncat(local_value_asm_str,"@",strlen("@"));
        strncat(local_value_asm_str,local_value_str,strlen(local_value_str));

        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,local_value_asm_str);  //  i

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=A");                

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@LCL");

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  LCL + i

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

    }
    else
    {
        printf("Error finding local memory access command !!! \n");
        return;
    }
    
    
}
void generate_argument_segment_asm_code(int argument_value, char * memory_access_command)
{
    if (strncmp(memory_access_command,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
    {
        // push argument 2

        // @2
        // D=A         //  i

        // @ARG
        // D=D+M       //  ARG + i


        // @addr
        // M=D

        // A=M
        // D=M         //  *addr


        // @SP
        // A=M
        // M=D         //  *SP = *addr

        // @SP
        // M=M+1       //  SP++

        char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

        _make_variable_unique("addr",unique_addr_variable,counter);


        char argument_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(argument_value,argument_value_str);

        char argument_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the argument_value. eg @7
        strncat(argument_value_asm_str,"@",strlen("@"));
        strncat(argument_value_asm_str,argument_value_str,strlen(argument_value_str));

        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,argument_value_asm_str);  //  @i

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=A");                

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@ARG");

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  ARG + i

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;
        

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  

        counter = counter + 1;

    }
    else if(strncmp(memory_access_command,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
    {
        //  pop argument 1

        // @1          //  i
        // D=A

        // @ARG    
        // D=D+M       //  ARG + i

        // @addr
        // M=D         //  addr = ARG + i


        // @SP
        // M=M-1       //  SP--

        // @SP
        // A=M
        // D=M         // *SP

        // @addr
        // A=M
        // M=D         //  *addr = *SP  

         char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

        _make_variable_unique("addr",unique_addr_variable,counter);


        char argument_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(argument_value,argument_value_str);

        char argument_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the argument_value. eg @7
        strncat(argument_value_asm_str,"@",strlen("@"));
        strncat(argument_value_asm_str,argument_value_str,strlen(argument_value_str));

        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,argument_value_asm_str);  //  @i

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=A");                

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@ARG");

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  ARG + i

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

    }
    else
    {
        printf("Error finding argument memory access command !!! \n");
        return;
    }
}
void generate_this_segment_asm_code(int this_value, char * memory_access_command)
{
    if (strncmp(memory_access_command,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
    {
        // push this 6

        // @6
        // D=A         //  i

        // @THIS
        // D=D+M       //  THIS + i


        // @addr
        // M=D

        // A=M
        // D=M         //  *addr


        // @SP
        // A=M
        // M=D         //  *SP = *addr

        // @SP
        // M=M+1       //  SP++

        char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

        _make_variable_unique("addr",unique_addr_variable,counter);


        char this_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(this_value,this_value_str);

        char this_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the this_value. eg @7
        strncat(this_value_asm_str,"@",strlen("@"));
        strncat(this_value_asm_str,this_value_str,strlen(this_value_str));

        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,this_value_asm_str);  //  @i

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=A");                

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@THIS");

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  THIS + i

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;
        

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  

        counter = counter + 1;

    }
    else if(strncmp(memory_access_command,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
    {
        //  pop this 6

        // @6          //  i
        // D=A

        // @THIS    
        // D=D+M       //  THIS + i

        // @addr
        // M=D         //  addr = THIS + i


        // @SP
        // M=M-1       //  SP--

        // @SP
        // A=M
        // D=M         // *SP

        // @addr
        // A=M
        // M=D         //  *addr = *SP    

        char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

        _make_variable_unique("addr",unique_addr_variable,counter);


        char this_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(this_value,this_value_str);

        char this_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the this_value. eg @7
        strncat(this_value_asm_str,"@",strlen("@"));
        strncat(this_value_asm_str,this_value_str,strlen(this_value_str));

        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,this_value_asm_str);  //  @i

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=A");                

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@THIS");

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  THIS + i

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        
        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;

    }
    else
    {
        printf("Error finding this memory access command !!! \n");
        return;
    } 
}
void generate_that_segment_asm_code(int that_value, char * memory_access_command)
{
    if(strncmp(memory_access_command,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
        {

            // push that 6

            // @6
            // D=A         //  i

            // @THAT
            // D=D+M       //  THIS + i


            // @addr
            // M=D

            // A=M
            // D=M         //  *addr


            // @SP
            // A=M
            // M=D         //  *SP = *addr

            // @SP
            // M=M+1       //  SP++

            char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

            _make_variable_unique("addr",unique_addr_variable,counter);


            char that_value_str[BINARY_MAX_BITS] = {0};
            convert_to_string(that_value,that_value_str);

            char that_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the that_value. eg @7
            strncat(that_value_asm_str,"@",strlen("@"));
            strncat(that_value_asm_str,that_value_str,strlen(that_value_str));

            char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
            convert_to_string(counter,counter_str);
            DictInsert(global_asm_dictionary,counter_str,that_value_asm_str);  //  @i

            counter = counter + 1;


            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=A");                

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@THAT");

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  THAT + i

            counter = counter + 1;


            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

            counter = counter + 1;

            
            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;
            

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  

            counter = counter + 1;

        }
        else if(strncmp(memory_access_command,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
        {
            //  pop that 4

            // @4         //  i
            // D=A

            // @THAT    
            // D=D+M       //  THAT + i

            // @addr
            // M=D         //  addr = THAT + i


            // @SP
            // M=M-1       //  SP--

            // @SP
            // A=M
            // D=M         // *SP

            // @addr
            // A=M
            // M=D         //  *addr = *SP      

            char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

            _make_variable_unique("addr",unique_addr_variable,counter);


            char that_value_str[BINARY_MAX_BITS] = {0};
            convert_to_string(that_value,that_value_str);

            char that_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the that_value. eg @7
            strncat(that_value_asm_str,"@",strlen("@"));
            strncat(that_value_asm_str,that_value_str,strlen(that_value_str));

            char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
            convert_to_string(counter,counter_str);
            DictInsert(global_asm_dictionary,counter_str,that_value_asm_str);  //  @i

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=A");                

            counter = counter + 1;


            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@THAT");

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=D+M");                  //  THAT + i

            counter = counter + 1;

            
            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

            counter = counter + 1;

            
            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;

        }
        else
        {
            printf("Error finding that memory access command !!! \n");
            return;
        } 
}
void generate_temp_segment_asm_code(int temp_value, char * memory_access_command)
{
        if (strncmp(memory_access_command,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
        {

            // push temp 7

            // @7
            // D=A         //  i

            // @5
            // D=D+A       //  Temp + i


            // @addr
            // M=D

            // A=M
            // D=M         //  *addr


            // @SP
            // A=M
            // M=D         //  *SP = *addr

            // @SP
            // M=M+1       //  SP++

            char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

            _make_variable_unique("addr",unique_addr_variable,counter);


            char temp_value_str[BINARY_MAX_BITS] = {0};
            convert_to_string(temp_value,temp_value_str);

            char temp_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the temp_value. eg @7
            strncat(temp_value_asm_str,"@",strlen("@"));
            strncat(temp_value_asm_str,temp_value_str,strlen(temp_value_str));

            char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
            convert_to_string(counter,counter_str);
            DictInsert(global_asm_dictionary,counter_str,temp_value_asm_str);  //  @i

            counter = counter + 1;


            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=A");                

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@5");

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=D+A");                  //  Temp + i

            counter = counter + 1;


            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

            counter = counter + 1;

            
            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;
            

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  

            counter = counter + 1;

        }
        else if(strncmp(memory_access_command,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
        {
            //  pop temp 7

            // @7         //  i
            // D=A

            // @5    
            // D=D+A       //  Temp + i

            // @addr
            // M=D         //  addr = Temp + i


            // @SP
            // M=M-1       //  SP--

            // @SP
            // A=M
            // D=M         // *SP

            // @addr
            // A=M
            // M=D         //  *addr = *SP      

            char unique_addr_variable[BINARY_MAX_BITS] = {0}; 

            _make_variable_unique("addr",unique_addr_variable,counter);


            char temp_value_str[BINARY_MAX_BITS] = {0};
            convert_to_string(temp_value,temp_value_str);

            char temp_value_asm_str[BINARY_MAX_BITS] = {0}; //  asm code for the temp_value. eg @7
            strncat(temp_value_asm_str,"@",strlen("@"));
            strncat(temp_value_asm_str,temp_value_str,strlen(temp_value_str));

            char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
            convert_to_string(counter,counter_str);
            DictInsert(global_asm_dictionary,counter_str,temp_value_asm_str);  //  @i

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=A");                

            counter = counter + 1;


            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@5");

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=D+A");                  //  Temp + i

            counter = counter + 1;

            
            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

            counter = counter + 1;

            
            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"@SP");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"D=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,unique_addr_variable);     //  @addr            

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"A=M");                  

            counter = counter + 1;

            convert_to_string(counter,counter_str);

            DictInsert(global_asm_dictionary,counter_str,"M=D");                  

            counter = counter + 1;

        }
        else
        {
            printf("Error finding temp memory access command !!! \n");
            return;
        } 
}

void generate_pointer_segment_asm_code(int pointer_value, char * memory_access_command)
{
    char * memory_segment;

    if (pointer_value == 0) 
    {
        memory_segment = strdup("@THIS");
    }
    else if(pointer_value == 1)
    {
        memory_segment = strdup("@THAT");
    }

    if (strncmp(memory_access_command,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
    {
        //  push pointer 0/1
        //  push pointer 0/1 -> *SP = THIS; SP++

        // @THIS/@THAT
        // D=M


        // @SP
        // A=M
        // M=D         //  *SP = THIS/THAT

        // @SP
        // M=M+1       //  SP++




        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,memory_segment);  //  @THIS or @THAT

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;


        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"@SP");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  

        counter = counter + 1;
        
    }
    else if(strncmp(memory_access_command,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
    {

        //  pop pointer 0/1
        //  pop pointer 0/1 -> SP--; THAT = *SP


        // @SP
        // M=M-1       //  SP--


        // @SP
        // A=M
        // D=M         // *SP

        // @THAT/@THIS
        // M=D         //  THIS/THAT = *SP  


        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");

        counter = counter + 1;
        
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=M-1");  

        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"A=M");                  

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"D=M");                  

        counter = counter + 1;


        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,memory_segment);  //  @THIS or @THAT

        counter = counter + 1;

        convert_to_string(counter,counter_str);

        DictInsert(global_asm_dictionary,counter_str,"M=D");                  

        counter = counter + 1;      

    }
    else
    {
        printf("Error finding pointer memory access command !!! \n");
        return;
    }
    
    
    
}

void generate_static_segment_asm_code(int static_value, char * memory_access_command, char * filename)
{
    if (strncmp(memory_access_command,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
    {
        // push static 3

        // @3
        // D=A         //  i

        // @16
        // D=D+A       //  16 + i


        // @MemoryAccessStatic.3
        // A=D
        // D=M         //  *addr


        // @SP
        // A=M
        // M=D         //  *SP = *addr

        // @SP
        // M=M+1       //  SP++

        char static_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(static_value,static_value_str);

        char static_value_asm_str[BINARY_MAX_BITS] = {0};   //  asm code for the temp_value. eg @7
        strncat(static_value_asm_str,"@",strlen("@"));
        strncat(static_value_asm_str,static_value_str,strlen(static_value_str));

        char static_variable_str[BINARY_MAX_BITS] = {0};        //  static variable format - @filename.n eg. @StaticTest.3
        strncat(static_variable_str,"@",strlen("@"));
        strncat(static_variable_str,filename,strlen(filename));
        strncat(static_variable_str,".",strlen("."));
        strncat(static_variable_str,static_value_str,strlen(static_value_str));


        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,static_value_asm_str);  //  @i

        counter = counter + 1;    


        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"D=A");                  
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@16");                        
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"D=D+A");                  
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,static_variable_str);                 //   eg @StaticTest.3
        counter = counter + 1;     

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"A=D");                  
        counter = counter + 1;  

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"D=M");                  
        counter = counter + 1;  

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");                  
        counter = counter + 1;  

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"A=M");                  
        counter = counter + 1;         

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=D");                  
        counter = counter + 1;  

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");                  
        counter = counter + 1; 

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  
        counter = counter + 1; 
    }
    else if(strncmp(memory_access_command,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
    {
        //  pop static 1

        // @1          //  i
        // D=A

        // @16          
        // D=D+A       //  16 + i

        // @MemoryAccessStatic.1
        // M=D         //  addr = Temp + i


        // @SP
        // M=M-1       //  SP--

        // @SP
        // A=M
        // D=M         // *SP


        // @MemoryAccessStatic.1
        // A=M
        // M=D         //  *addr = *SP

        char static_value_str[BINARY_MAX_BITS] = {0};
        convert_to_string(static_value,static_value_str);

        char static_value_asm_str[BINARY_MAX_BITS] = {0};   //  asm code for the temp_value. eg @7
        strncat(static_value_asm_str,"@",strlen("@"));
        strncat(static_value_asm_str,static_value_str,strlen(static_value_str));

        char static_variable_str[BINARY_MAX_BITS] = {0};        //  static variable format - @filename.n eg. @StaticTest.3
        strncat(static_variable_str,"@",strlen("@"));
        strncat(static_variable_str,filename,strlen(filename));
        strncat(static_variable_str,".",strlen("."));
        strncat(static_variable_str,static_value_str,strlen(static_value_str));


        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,static_value_asm_str);  //  @i

        counter = counter + 1; 

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"D=A");                  
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@16");                        
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"D=D+A");                  
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,static_variable_str);                 //   eg @StaticTest.3
        counter = counter + 1;     

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=D");                  
        counter = counter + 1; 

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");                  
        counter = counter + 1;  

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  
        counter = counter + 1;         

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");                  
        counter = counter + 1;  

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"A=M");                  
        counter = counter + 1; 

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"D=M");                  
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,static_variable_str);                 //   eg @StaticTest.3
        counter = counter + 1; 

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"A=M");                  
        counter = counter + 1; 

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=D");                  
        counter = counter + 1;
    }
    else
    {
        printf("Error finding static memory access command !!! \n");
        return;
    }
    

}

void generate_goto_label_command(char * function_name, char * label)
{

    // @null$LOOP_START
    // 0;JMP

    // if the function_name is null, which means that this command is not under any declared function name then use null to build the label command with format: @function_name$label
    // hence ->  (null$label) 

    char internal_function_name[BINARY_MAX_BITS] = {0};

    if (strncmp(function_name,"null",sizeof("null")) == 0)
    {
        strncat(internal_function_name,"null",strlen("null"));
    }
    else{
        strncat(internal_function_name,function_name,strlen(function_name));
    }

    char label_command[BINARY_MAX_BITS] = {0};
    strncat(label_command,"@",strlen("@"));
    strncat(label_command,internal_function_name,strlen(internal_function_name));
    strncat(label_command,"$",strlen("$"));
    strncat(label_command,label,strlen(label));


    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,label_command);                  //    @function_name$label
    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");                          //  0;JMP
    counter = counter + 1;
}

void generate_if_goto_label_command(char * function_name, char * label)
{
    // if-goto LOOP_START  // If counter > 0, goto LOOP_START

    // @SP
    // M=M-1
    // A=M
    // D=M
    // @null$LOOP_START
    // D;JNE

    // if the function_name is null, which means that this command is not under any declared function name then use null to build the label command with format: @function_name$label
    // hence ->  (null$label) 

    char internal_function_name[BINARY_MAX_BITS] = {0};

    if (strncmp(function_name,"null",sizeof("null")) == 0)
    {
        strncat(internal_function_name,"null",strlen("null"));
    }
    else{
        strncat(internal_function_name,function_name,strlen(function_name));
    }

    char label_command[BINARY_MAX_BITS] = {0};
    strncat(label_command,"@",strlen("@"));
    strncat(label_command,internal_function_name,strlen(internal_function_name));
    strncat(label_command,"$",strlen("$"));
    strncat(label_command,label,strlen(label));

    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  
    counter = counter + 1;     

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,label_command);  //  @function_name$label
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D;JNE");                  
    counter = counter + 1; 
}

void generate_label_command(char * function_name, char * label)
{
    //  (null$LOOP_START)


    char internal_function_name[BINARY_MAX_BITS] = {0};

    // if the function_name is null, which means that this command is not under any declared function name then use null to build the label command with format: (function_name$label) 
    // hence ->  (null$label) 

    if (strncmp(function_name,"null",sizeof("null")) == 0)
    {
        strncat(internal_function_name,"null",strlen("null"));
    }
    else{
        strncat(internal_function_name,function_name,strlen(function_name));
    }

    char label_command[BINARY_MAX_BITS] = {0};
    strncat(label_command,"(",strlen("("));
    strncat(label_command,internal_function_name,strlen(internal_function_name));
    strncat(label_command,"$",strlen("$"));
    strncat(label_command,label,strlen(label));
    strncat(label_command,")",strlen(")"));


    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
        
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,label_command);  //  (function_name$label) 

    counter = counter + 1; 


}

/**
 * @brief   This function processes a command with format : 'function SimpleFunction.test 2'. 
 *          Steps involved
 *          1. Use function name to create a translator-generated label with format: (functionname) 
 *          2. Update the current_function gloabl variable with this function name
 *          3. Create a for-loop that generates local variable initialization asm code based on the number of local variables in local_variables param
 *          
 *          
 * 
 * @param   function_name: This is the name of the function 
 * @param   local_variables: This is the number of local variables the function will require to perform its operation
*/
void generate_function_function_command(char * function_name, int local_variables)
{
    //  1. Use function name to create a translator-generated label with format: (functionname)

    char label_command[BINARY_MAX_BITS] = {0};
    strncat(label_command,"(",strlen("("));
    strncat(label_command,function_name,strlen(function_name));
    strncat(label_command,")",strlen(")"));

    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,label_command);                  
    counter = counter + 1;


    //  2. Update the current_function gloabl variable with this function name 

    // if (current_function_name != NULL)
    // {
    //     previous_function_name = strdup(current_function_name);
    // }

    current_function_name = strdup(function_name);

    //  3. Create for-loop for local variable initialization

    for (int i = 0; i < local_variables; i++)
    {
        //  push constant 0

        generate_constant_segment_asm_code(0);

        //  pop local i

        generate_local_segment_asm_code(i,POP_COMMAND);

        //  Increment SP since we are initializing the local variables

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");                  
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  
        counter = counter + 1; 
        
    }
    
}

/**
 * @brief   This function implements the return design as seen below
 *          
 *          @note: Build the return address  by searching the dictionary for the caller function (value) associated with this callee function (key) . Delete entry after building the return address
 * 
 *          //  1. endFrame = LCL              //  endFrame is a temporary variable
            //  2. retAddr = *(endFrame-5)     //  gets the return address of caller function
            //  3. *ARG = pop()                //  pops the current value from the stack which is the return value and then puts that value inside ARG 0
            //  4. SP = ARG + 1                //  repositions to SP of the caller.
            //  5. THAT = *(endFrame - 1)      //  restores THAT of the caller
            //  6. THIS = *(endFrame - 2)      //  restores THIS of the caller
            //  7. ARG =  *(endFrame - 3)      //  restores ARG of the caller
            //  8. LCL =  *(endFrame - 4)      //  restores LCL of the caller
            //  9. goto retAddr                //  goes to the caller's return address.This is the first item in the caller's saved frame and this address should be
                                            //  next line of code that continues the caller's execution
            
            //  
            

                        
    @param  current_function_name : This is the current function or the callee function that has the return statement within it
    @param  caller_function_name  : This is the caller function that called the callee and the callee must return control to the caller function. NOTE: if there is not caller function
                                    then caller_function_name will be null
    
*/

void generate_return_function_command(char * current_function_name)
{

    //  Build the retAddr by searching the dictionary for the caller function (value) associated with this callee function (key)

    const char * caller_function_name = DictSearch(global_caller_callee_function_dictionary,current_function_name); //  search with callee as key

    if(caller_function_name == 0)
    {
        caller_function_name = strdup("null");
    }
    char return_address_label_command[BINARY_MAX_BITS] = {0};

    strncat(return_address_label_command,"@",strlen("@"));
    strncat(return_address_label_command,caller_function_name,strlen(caller_function_name));
    strncat(return_address_label_command,"$",strlen("$"));
    strncat(return_address_label_command,"retAddrLabel",strlen("retAddrLabel"));        // @function$retAddrLabel





    //  endFrame = LCL

    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@LCL");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@endFrame");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    //  retAddr = *(endFrame-5)

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@5");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@endFrame");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;





    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,return_address_label_command);                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    //  *ARG = pop() 

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M-1");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@ARG");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    //  SP = ARG + 1 
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@1");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@ARG");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M+D");                  
    counter = counter + 1;

    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    //  THAT = *(endFrame - 1)

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@1");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@endFrame");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");                  
    counter = counter + 1;

    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@THAT");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    //  THIS = *(endFrame - 2)

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@2");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@endFrame");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");                  
    counter = counter + 1;

    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@THIS");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;


    //  ARG =  *(endFrame - 3)

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@3");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@endFrame");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");                  
    counter = counter + 1;

    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@ARG");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;


    //  LCL =  *(endFrame - 4) 

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@4");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@endFrame");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");                  
    counter = counter + 1;

    
    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@LCL");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    //  goto retAddr 


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,return_address_label_command);                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");                  
    counter = counter + 1;


    //  delete entry from dictionary
    DictDelete(global_caller_callee_function_dictionary,current_function_name);
}


/**
 * @brief   This function generates the asm code when a 'call function_name nArgs' command is triggered. There are operations that have before and after a call is triggered. 
 *          
 *         
 *          Handling call -> call 'functionname nArgs'  
 *          
 *          Before call: These are operations that need to occur to save the state of the caller function
 * 
 *          1. push retAddrLabel        - Push the return address label of the caller function
 *          2. push LCL                 - Saves LCL of the caller
 *          3. push ARG                 - Saves ARG of the caller
 *          4. push THIS                - Saves THIS of the caller
 *          5. push THAT                - Saves THAT of the caller
 *          6. ARG = SP - 5 - nArgs     - Repositions ARG. This repositioning is important because we need to set ARG to the correct base address so the called function can access 
 *                                        its arguments that were pushed to stack by caller
 *          7. LCL = SP                 - Repositions LCL. Repositions LCL for the callee (called function)
 *          8. goto Functionname        - Transfers control to the called function
 *          9. retAddrLabel             - return here and continue caller function's code after executing callee function
 *          10. map the caller function and the callee function using a dictionary . @note: whenever return is called, we should delete this entry from the dictionary . Key: callee_function_name , Value: caller_function_name 
 * 
 * @todo use key value pairs to hold function call and return mapping. Once return is executed, remove from dictionary
 * 
 * @param caller_function_name : This is the current function that is being executed and now wants to call a new function
 * @param callee_function_name : This is the function that is called here:  call 'functionname nArgs' . This function is the function that the caller will transfer control to. 
 * @param nArgs : This is the number of arguments or nArgs pushed to the stack by the caller for the callee to use to run its operations effectively
*/
void generate_call_function_command(char * caller_function_name, char * callee_function_name, int nArgs)
{
    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value

    //   1. push retAddrLabel        - Push the return address label of the caller function
    char return_address_command[BINARY_MAX_BITS] = {0};

    strncat(return_address_command,"@",strlen("@"));
    strncat(return_address_command,caller_function_name,strlen(caller_function_name));
    strncat(return_address_command,"$",strlen("$"));
    strncat(return_address_command,"retAddrLabel",strlen("retAddrLabel"));        // @function$retAddrLabel


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,return_address_command);                  
    counter = counter + 1;


    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  
    counter = counter + 1;

    //  2. push LCL                 - Saves LCL of the caller

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@LCL");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  
    counter = counter + 1;

    //  3. push ARG                 - Saves ARG of the caller

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@ARG");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  
    counter = counter + 1;


    //  4. push THIS                - Saves THIS of the caller

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@THIS");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  
    counter = counter + 1;

    //  5. push THAT                - Saves THAT of the caller

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@THAT");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"A=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=M+1");                  
    counter = counter + 1;   

    //  6. ARG = SP - 5 - nArgs     - Repositions ARG. nArgs is the number of arguments pushed by the caller to the stack for the callee to use to function properly

    convert_to_string(counter,counter_str);
    char nArgs_str[BINARY_MAX_BITS] = {0};

    convert_to_string(nArgs,nArgs_str);

    char nArgs_command[BINARY_MAX_BITS] = {0};

    strncat(nArgs_command,"@",strlen("@"));
    strncat(nArgs_command,nArgs_str,strlen(nArgs_str));


    DictInsert(global_asm_dictionary,counter_str,nArgs_command);    //  @nArgs eg. @1                
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@5");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=D+A");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M-D");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@ARG");                  
    counter = counter + 1; 

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1; 

    //  7. LCL = SP         - Repositions LCL. Repositions LCL for the callee (called function)

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@SP");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"D=M");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"@LCL");                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"M=D");                  
    counter = counter + 1;


    //  8. goto Functionname        - Transfers control to the called or callee function

    char called_function_label_command[BINARY_MAX_BITS] = {0};

    strncat(called_function_label_command,"@",strlen("@"));
    strncat(called_function_label_command,callee_function_name,strlen(callee_function_name));

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,called_function_label_command);                  
    counter = counter + 1;

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,"0;JMP");                  
    counter = counter + 1;  

    //  9. retAddrLabel             - return here and continue caller function's code after executing callee function

    char return_address_label_command[BINARY_MAX_BITS] = {0};

    strncat(return_address_label_command,"(",strlen("("));
    strncat(return_address_label_command,caller_function_name,strlen(caller_function_name));
    strncat(return_address_label_command,"$",strlen("$"));
    strncat(return_address_label_command,"retAddrLabel",strlen("retAddrLabel"));        
    strncat(return_address_label_command,")",strlen(")"));        // (function$retAddrLabel)

    convert_to_string(counter,counter_str);
    DictInsert(global_asm_dictionary,counter_str,return_address_label_command);                  
    counter = counter + 1;

    //  10. map the caller function and the callee function using a dictionary . Key: callee_function_name  , Value:  caller_function_name 

    DictInsert(global_caller_callee_function_dictionary,callee_function_name,caller_function_name);
}


/**
 * @internal function
 * @brief: This function initializes the dictionaries for holding the assembly languages from the translated vm commands
*/
void _initialize_asm_command_tables(){


    global_asm_dictionary = DictCreate();

   global_caller_callee_function_dictionary = DictCreate();

    //  Initialize SP to 256

    // @256
    // D=A

    // @SP
    // M=D

    //  Initialize SP to 256

    if (INITIALIZE_STACK_POINTER)
    {

        char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@256");

        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"D=A");
        
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"@SP");
        
        counter = counter + 1;

        convert_to_string(counter,counter_str);
        DictInsert(global_asm_dictionary,counter_str,"M=D");
        
        counter = counter + 1;
    }
    

    

}


/**
 * @internal function
 * @brief   This function marches through the global asm dictionary using the counter variable as the key in increasing order from 1 
 *          till max count is reached to generate the .asm file with assembly code
 * 
*/
void _write_instructions_to_file(char * asm_output_filename){

    int counter_copy = 0;
    
     // remove output file if already exists
    remove(asm_output_filename);

    FILE* file_ptr;
    file_ptr = fopen(asm_output_filename,"w");   
    char str[MAX_FILE_SIZE];

    if (file_ptr == NULL)
    {
        printf("File not found !!! \n");
        exit(1);
    }

    //  counter - 1 because there is always an extra line with empty space added when writing to the previous files ( no_whitespace and no_comment files)
    while (counter_copy <= counter - 1)
    {

        char counter_str[BINARY_MAX_BITS] = {0};

        convert_to_string(counter_copy,counter_str);

        const char * binary_result = DictSearch(global_asm_dictionary,counter_str);

        if(binary_result != 0){

            //  insert only when a result is returned 

            fprintf(file_ptr,"%s\n", binary_result);

        }

        counter_copy += 1;
    }

    fclose(file_ptr);
    
}


/**
 * @brief   This function uses the current counter to make a label variable & label used in the code generators to be unique
 *          eg. It will convert a variable from @NOTGREATER to @NOTGREATER_2 where 2 is the current counter string
 *              It will convert a label from (NOTGREATER) to (NOTGREATER_2) where 2 is the current counter string
*/
void _make_label_variable_unique(char * label_variable, char * unique_label_variable, char * unique_label, int _counter)
{
    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
    convert_to_string(_counter,counter_str);

    //  Generate unique label variable with format: @xxx_n
    strncat(unique_label_variable,"@",strlen("@"));
    strncat(unique_label_variable,label_variable,strlen(label_variable));
    strncat(unique_label_variable,"_",strlen("_"));
    strncat(unique_label_variable,counter_str,strlen(counter_str));

    //  Generate unique label with format: (xxx_n)
    strncat(unique_label,"(",strlen("("));
    strncat(unique_label,label_variable,strlen(label_variable));
    strncat(unique_label,"_",strlen("_"));
    strncat(unique_label,counter_str,strlen(counter_str));
    strncat(unique_label,")",strlen(")"));



}
/**
 * @brief   This function uses the current counter to make a  variable used in the code generators to be unique
 *          eg. It will convert a variable from @NOTGREATER to @NOTGREATER_2 where 2 is the current counter string
 *              
*/
void _make_variable_unique(char * variable, char * unique_variable, int _counter)
{
    char counter_str[BINARY_MAX_BITS] = {0}; // string equivalent of counter value
    
    convert_to_string(_counter,counter_str);

    //  Generate unique variable with format: @xxx_n
    strncat(unique_variable,"@",strlen("@"));
    strncat(unique_variable,variable,strlen(variable));
    strncat(unique_variable,"_",strlen("_"));
    strncat(unique_variable,counter_str,strlen(counter_str));



}

int main(int argc, char * argv[])
{

    _initialize_asm_command_tables();

    //  Simple Add
    //  parse_input_file(NULL,SIMPLE_ADD_VM_FILE,SIMPLE_ADD_NO_COMMENT_OUTPUT_VM_FILE,SIMPLE_ADD_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    //  _write_instructions_to_file(SIMPLE_ADD_ASM_OUTPUT_FILE);


    //  Stack Test
    //  parse_input_file(NULL,STACK_TEST_VM_FILE,STACK_TEST_NO_COMMENT_OUTPUT_VM_FILE,STACK_TEST_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    //  _write_instructions_to_file(STACK_TEST_ASM_OUTPUT_FILE);


    //  Basic Test

    //  parse_input_file(NULL,BASIC_TEST_VM_FILE,BASIC_TEST_NO_COMMENT_OUTPUT_VM_FILE,BASIC_TEST_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    //  _write_instructions_to_file(BASIC_TEST_ASM_OUTPUT_FILE); 

    
    //  Pointer Test

    //  parse_input_file(NULL,POINTER_TEST_VM_FILE,POINTER_TEST_NO_COMMENT_OUTPUT_VM_FILE,POINTER_TEST_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    //  _write_instructions_to_file(POINTER_TEST_ASM_OUTPUT_FILE); 


    //  Static Test

    //  parse_input_file(STATIC_FILENAME,STATIC_TEST_VM_FILE,STATIC_TEST_NO_COMMENT_OUTPUT_VM_FILE,STATIC_TEST_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    //  _write_instructions_to_file(STATIC_TEST_ASM_OUTPUT_FILE); 


    //  Chapter 8 Projects Below


    //  Basic Loop

    //  parse_input_file(NULL,BASIC_LOOP_VM_FILE,BASIC_LOOP_NO_COMMENT_OUTPUT_VM_FILE,BASIC_LOOP_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    //  _write_instructions_to_file(BASIC_LOOP_ASM_OUTPUT_FILE); 


    //  Fibonnaci Series 

    // parse_input_file(NULL,FIBONACCI_SERIES_VM_FILE,FIBONACCI_SERIES_NO_COMMENT_OUTPUT_VM_FILE,FIBONACCI_SERIES_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    // _write_instructions_to_file(FIBONACCI_SERIES_ASM_OUTPUT_FILE);  

    //  Simple Function 

    // parse_input_file(NULL,SIMPLE_FUNCTION_VM_FILE,SIMPLE_FUNCTION_NO_COMMENT_OUTPUT_VM_FILE,SIMPLE_FUNCTION_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    // _write_instructions_to_file(SIMPLE_FUNCTION_ASM_OUTPUT_FILE); 



    //  Nested Call
    parse_input_file(NULL,NESTED_CALL_VM_FILE,NESTED_CALL_NO_COMMENT_OUTPUT_VM_FILE,NESTED_CALL_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

    _write_instructions_to_file(NESTED_CALL_ASM_OUTPUT_FILE);   




    return 0;
}