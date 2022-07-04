#include "../ChapterSix/assembler/dictionary.c"
#include "../ChapterSix/assembler/util.c"
/*

    This is the main VM Translator module . It  connects to other sub module for handling different tasks in the

    translation of VM Code code to assembly language. 

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
#define SIMPLE_ADD_NO_COMMENT_OUTPUT_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd_no_comment.vm"
#define SIMPLE_ADD_NO_WHITESPACE_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd_no_whitespace.vm"
#define SIMPLE_ADD_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd/SimpleAdd.asm"

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


int counter = 0;                        //  the universal counter for counting generated asm commands

Dict global_asm_dictionary;             //  this dictionary holds all the asm commands


//  Internal function declarations
void _initialize_asm_command_tables();
void _write_instructions_to_file(char * asm_output_filename);


/**
 * Parser Module Function Initializations
*/

void parse_vm_command(char * vm_command);
void parse_input_file(char * input_vm_file, char * no_comment_output_vm_file,char * no_whitespace_output_vm_file, int max_file_zie);

void parse_push_command(char *memory_segment,int i);    //  Recall: General command structure is push segment i
// void parse_pop_command(char *memory_segment,int i);     //  Recall: General command structure is pop segment i

/**
 * Code Module Function Initializations
*/
void generate_add_asm_command();
void generate_constant_segment_asm_code(int constant_value);

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




void parse_input_file(char * input_vm_file, char * no_comment_output_vm_file,char * no_whitespace_output_vm_file, int max_file_zie)
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
        
        parse_vm_command(str);        
        
    }

    fclose(file_ptr);
    
}


/**
 * @brief:  This function parses the vm_command (e.g push constant 7 ) and breaks it down into its components( push, constant , 7)
 *          
 *          
*/
void parse_vm_command(char * vm_command)
{
    char * empty_space_delimiter = " ";

    char * command_type = {0};
    char * memory_segment = {0};
    int i;

    command_type = strtok(vm_command,empty_space_delimiter);

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

    }
    else if(strncmp(command_type,NEG_COMMAND,sizeof(NEG_COMMAND)) == 0)
    {

    }
    else if(strncmp(command_type,EQ_COMMAND,sizeof(EQ_COMMAND)) == 0)
    {

    }
    else if(strncmp(command_type,GT_COMMAND,sizeof(GT_COMMAND)) == 0)
    {

    }
    else if(strncmp(command_type,LT_COMMAND,sizeof(LT_COMMAND)) == 0)
    {

    }
    else if(strncmp(command_type,AND_COMMAND,sizeof(AND_COMMAND)) == 0)
    {

    }
    else if(strncmp(command_type,OR_COMMAND,sizeof(OR_COMMAND)) == 0)
    {

    }
    else if(strncmp(command_type,SUB_COMMAND,sizeof(SUB_COMMAND)) == 0)
    {

    }
    else if(strncmp(command_type,PUSH_COMMAND,sizeof(PUSH_COMMAND)) == 0)
    {
        //  parse push command code
        memory_segment = strtok(NULL,empty_space_delimiter);

        char * i_str = {0};

        i_str = strtok(NULL,empty_space_delimiter);

        i = convert_string_to_number(i_str);

        parse_push_command(memory_segment,i);

    }
    else if(strncmp(command_type,POP_COMMAND,sizeof(POP_COMMAND)) == 0)
    {

    }


    
}

/**
 * @brief:  This function is under the Parser Module. It will process the push command based on the memory segment and then link the 
 *          code generation modeule to generate the appropriate assembly code
*/
void parse_push_command(char *memory_segment,int i)
{
    //  Check for appropriate memory segment of the stack we are pushing to
    printf("Segment: %s , i: %d \n", memory_segment, i);

    if (strncmp(memory_segment,LOCAL,sizeof(LOCAL)) == 0)
    {
        /* code */
    }
    else if(strncmp(memory_segment,ARGUMENT,sizeof(ARGUMENT)) == 0)
    {

    }
    else if(strncmp(memory_segment,THIS,sizeof(THIS)) == 0)
    {

    }
    else if(strncmp(memory_segment,THAT,sizeof(THAT)) == 0)
    {

    }
    else if(strncmp(memory_segment,CONSTANT,sizeof(CONSTANT)) == 0)
    {
        generate_constant_segment_asm_code(i);
    }
    else if(strncmp(memory_segment,STATIC,sizeof(STATIC)) == 0)
    {

    }
    else if(strncmp(memory_segment,TEMP,sizeof(TEMP)) == 0)
    {

    }
    else if(strncmp(memory_segment,POINTER,sizeof(POINTER)) == 0)
    {

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

int main(int argc, char * argv[])
{

    _initialize_asm_command_tables();

    //  Simple Add
    parse_input_file(SIMPLE_ADD_VM_FILE,SIMPLE_ADD_NO_COMMENT_OUTPUT_ASM_FILE,SIMPLE_ADD_NO_WHITESPACE_ASM_FILE,MAX_FILE_SIZE);

    _write_instructions_to_file(SIMPLE_ADD_ASM_OUTPUT_FILE);



    return 0;
}