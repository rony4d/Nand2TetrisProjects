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





int counter = 0;                        //  the universal counter for counting generated asm commands

Dict global_asm_dictionary;             //  this dictionary holds all the asm commands

char * current_function_name = {0};     //  this is the current function which is being processed. NOTE: This function should change once a return is hit


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

void generate_call_function_command(char * function_name);
void generate_function_function_command(char * function_name);
void generate_return_function_command(char * function_name);



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
 * @internal function
 * @brief: This function initializes the dictionaries for holding the assembly languages from the translated vm commands
*/
void _initialize_asm_command_tables(){


    global_asm_dictionary = DictCreate();

   

    //  Initialize SP to 256

    // @256
    // D=A

    // @SP
    // M=D

    //  Initialize SP to 256
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


    //  Static Test

     parse_input_file(NULL,BASIC_LOOP_VM_FILE,BASIC_LOOP_NO_COMMENT_OUTPUT_VM_FILE,BASIC_LOOP_NO_WHITESPACE_VM_FILE,MAX_FILE_SIZE);

     _write_instructions_to_file(BASIC_LOOP_ASM_OUTPUT_FILE); 

    return 0;
}