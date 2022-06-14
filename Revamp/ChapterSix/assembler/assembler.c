#include "dictionary.c"
#include "util.c"
/*

    This is the main assembler module . It  connects to other sub module for handling different tasks in the

    translation of assembly code to machine language. 

    This is where the magic happens. 

    @author: ugochukwu aronu

    references:
    -   Building some data structures in c: https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
    -   LinkedLists: https://www.geeksforgeeks.org/linked-list-set-1-introduction/
    

    Steps
    -   Read the .asm file  - done
    -   Remove white space and comments and output the first file without comments or whitespace - done
    -   Initialzie C -instruction table using the dictionary    - done
    -   Initialize predfefined instruction table using the dictionary   - done
    -   Create sub tables to tack different types of instructions such as A, C and Label instructions using the same universal counter as key. This will enable us have clearer information 
        different types of instructions
    -   Create a universal table that combines all the sub-tables based on the sequence of the keys(universal counter)

    -   Detect A- instructions
    -   Detect C- instructions
    -   Process A - instructions: Create a sub-table for variable names and keep count of their memory addresses starting from RAM 16. Each new variable will increment RAM 16 address by 1. 
    -   Process C - instructions

    ToDo: Remove all imported .c files and replace them with their header files and link the .c files to the compiler 

*/

#define ADD_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSix/add/Add.asm"
#define ADD_NO_COMMENT_OUTPUT_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSix/add/add_no_comment.asm"
#define ADD_NO_WHITESPACE_OUTPUT_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSix/add/add_no_whitespace.asm"





Dict comp_instruction_dictionary;       //  comp_instruction pre-defined symbols
Dict dest_instruction_dictionary;       //  
Dict jump_instruction_dictionary;
Dict predefined_symbol_dictionary;      //  maps predefined symbols to the RAM address in decimal. 

Dict instruction_dictionary;            //  global dictionary for instructions

int counter = 1;                        //  the universal counter for counting instructions in a consecutive order
int variable_counter = 16;              //  this tracks the current RAM address of user-defined variable


/**
 * Parser Module Function Initializations
*/
void a_instruction_handler(char * instruction, int counter);
void c_instruction_handler(char * instruction, int counter);
void label_instruction_handler(char * instruction, int counter);

/**
 * Code Module Function Initializations
*/

void generate_a_instruction_binary(char * a_instruction_str);
void generate_c_instruction_binary(char * c_instruction_str);



void parse_input_file(char * input_asm_file, char * no_comment_output_asm_file, char * no_whitespace_output_asm_file, int max_file_zie);
void parse_instruction(char * instruction, int counter);


/**
 * @internal function delarations
*/
void _remove_string(char * delimiter, char * source_string, char * dest_string);
void _initialize_c_instruction_tables();







/**
 * @brief: Parser Module: This module parses the input
 * @note: There should be a universal counter for each line
 * @param parse_input_file: This function takes the no-comment & no-whitespace file. It is responsible for updating the counter. Other functions are called within this function
 * @param detect_instruction: This function should detect A, C or Label instruction and store in a table with counter number as key
 * @param handle_a_instruction: This function should handle A- instruction and store in a table with counter number as key
 * @param handle_c_instruction: This function should detect C- instruction and store in a table with counter number as key
 * @param handle_l_instruction: This function should detect Label - instruction and store in a table with counter number as key
*/

/**
 *  @brief: This function is under the Parser Module
 *  -   remove comments and write to no_comment asm file. original asm file acts as input file
 *  -   remove whitespace and write to no_whitespace asm file. no_comment asm file acts as input file
 *  -   read no_whitespace asm file and begin march through the lines. 
 *  -   for each line increase counter
 *  -   check whether a-instruction, c-instruction or label (l) - instruction
 *  -   pass to appropriate intruction handler with counter as paramter so that handler build its sub instruction table
*/
void parse_input_file(char * input_asm_file, char * no_comment_output_asm_file, char * no_whitespace_output_asm_file, int max_file_zie)
{  
    //  1. remove comments and store in no_comment asm file

    remove_comment(input_asm_file,no_comment_output_asm_file);

    //  2. remove whitespace and write to no_whitespace asm file.

    remove_white_spaces(no_comment_output_asm_file,no_whitespace_output_asm_file,max_file_zie);

    //  3. read no_whitespace asm file and begin march through the lines. 

    FILE* file_ptr;
    char str[MAX_FILE_SIZE];

    file_ptr = fopen(no_whitespace_output_asm_file,"r");

    if (file_ptr == NULL)
    {
        printf("File can't be opened \n");
        exit(1);
    }
    
    //  read file line by line
    while (fgets(str,MAX_FILE_SIZE,file_ptr) != NULL)    
    {
        
        parse_instruction(str,counter);
        counter = counter + 1;

    }

    fclose(file_ptr);
    
}

/**
 * @brief To detect instruction type we need to check the following
 * A-Instruction 
 * -    Format : @xxx where xxx is a symbol or decimal number
 * -    i
*/
void parse_instruction(char * instruction, int counter)
{
    char firstChar = instruction[0];
    if (firstChar == '@')
    {
        /* a-instruction */
        a_instruction_handler(instruction,counter);

    }else if (firstChar == '('){
        /* label instruction */
    }
    else{
        /* c-instruction */
        c_instruction_handler(instruction, counter);
    }
    
}

/**
 * @brief: This handles the a-instruction through the steps below
 * -    Convert decimal to binary and store in sub table for a-instruction
 * -    If not decimal, check if it is a pre-defined symbol, check the pre-defined symbol table , get the decimal and store in sub table for a-instruction
 * -    If not a pre-defined symbol, then it is user-defined variable. Add this variable to the user defined variable sub table with its variable counter as key and also add it
 *      to the sub-table for a-instruction with the global counter as key
*/
void a_instruction_handler(char * instruction, int counter){

    printf("a-instruction: %s at line: %d \n", instruction, counter);

    //  remove @

    char a_instruction_str[BINARY_MAX_BITS];              //  no variable name, symbol should be more than BINARY_MAX_BITS
    _remove_string("@",instruction,a_instruction_str);

    generate_a_instruction_binary(a_instruction_str);



}

void c_instruction_handler(char * instruction, int counter){

    // printf("c-instruction: %s at line: %d \n", instruction, counter);
}

void label_instruction_handler(char * instruction, int counter){

    // printf("c-instruction: %s at line: %d \n", instruction, counter);
}


/**
 * @brief: Code Module: This module provides the binary codes of all the assemble mnemonics
 * @param generate_a_instruction_binary : Generates the a_instruction binary code 
*/


/**
 * @brief: This function is under the Code Module
 * -    Generates the a_instruction binary code through the following steps
 * -    check if a_instruction_str is a number, then find the binary representation : 
 *          if the first character is a number then, the instruction is a number. NOTE: varaible names don't start with numbers
 * -    else if a_instruction_str is not a number, check if it is a pre-defined symbol from the predefined_symbol_dictionary
 * -    else  a_instruction_str is not a pre-defined symbol then it is a variable
 * 
*/
void generate_a_instruction_binary(char * a_instruction_str){


    //  if the first character is a number then, the instruction is a number. NOTE: varaible names don't start with numbers
    if(isdigit(a_instruction_str[0]))
    {
       
        int decimal = convert_string_to_number(a_instruction_str);

        char binary_result[BINARY_MAX_BITS] = {0};

        convert_decimal_to_binary(decimal,binary_result);

        //  store the counter and binary value as key value pairts in the global instruction dictionary 
        char counter_str[BINARY_MAX_BITS] = {0};

        convert_to_string(counter,counter_str);

        DictInsert(instruction_dictionary,counter_str,binary_result);

        // printf("Counter: %s, Binary Result: %s \n", counter_str, binary_result);

    }

    //  Todo: handle symbols and variables 
    
    //  else if a_instruction_str is not a number, check if it is a pre-defined symbol from the predefined_symbol_dictionary

    //  else  a_instruction_str is not a pre-defined symbol then it is a variable



}

/**
 * @brief: This is a Code Module Function
 * -    This function will generate binary of the c-instruction through the following
 * -    c-instruction generally looks like this dest=comp;jump  . Either dest or jump fields may be empty
 *      if dest is empty, the ""="" is omitted
 *      if jump is empty, the ";" is omitted
 * -    split the instruction with  "=" and ";" to determine the comp, dest and jump components of the c-instruction
 * -    with the dest and jump components determined, use the value of each component as key to search the comp_instruction dictionary that has been initialized
 * -    we have to build the c-instruction binary to follow the c-instruction format "111accccccdddjjj". 
 * -    to determine the value of a, we need to perform a string operation on the comp function, if it contains M then "a=1" else "a=0"
 * -    once "a" is determined, we can do ahead and build the c-instruction in the format "111accccccdddjjj" then add it to the global instruction dictionary with counter as key
*/
void generate_c_instruction_binary(char * c_instruction_str)
{

}


/**
 * @brief: Symbol Table Module: This module handles symbols
*/



int main(int argc, char * argv[])
{
    _initialize_c_instruction_tables();
    parse_input_file(ADD_ASM_FILE,ADD_NO_COMMENT_OUTPUT_ASM_FILE,ADD_NO_WHITESPACE_OUTPUT_ASM_FILE,MAX_FILE_SIZE);

   
    return 0;
}


/**
 * @internal function
 * @brief: This function initializes the necessary symbols and binary mappings
*/
void _initialize_c_instruction_tables(){

    comp_instruction_dictionary = DictCreate();

    DictInsert(comp_instruction_dictionary,"0","101010");
    DictInsert(comp_instruction_dictionary,"1","111111");
    DictInsert(comp_instruction_dictionary,"-1","111010");
    DictInsert(comp_instruction_dictionary,"D","001100");
    DictInsert(comp_instruction_dictionary,"A","110000");
    DictInsert(comp_instruction_dictionary,"!D","001101");
    DictInsert(comp_instruction_dictionary,"!A","110001");
    DictInsert(comp_instruction_dictionary,"-D","001111");
    DictInsert(comp_instruction_dictionary,"-A","110011");
    DictInsert(comp_instruction_dictionary,"D+1","011111");
    DictInsert(comp_instruction_dictionary,"A+1","110111");
    DictInsert(comp_instruction_dictionary,"D-1","001110");
    DictInsert(comp_instruction_dictionary,"A-1","110010");
    DictInsert(comp_instruction_dictionary,"D+A","000010");
    DictInsert(comp_instruction_dictionary,"D-A","010011");
    DictInsert(comp_instruction_dictionary,"A-D","000111");
    DictInsert(comp_instruction_dictionary,"D&A","000000");
    DictInsert(comp_instruction_dictionary,"D|A","010101");

    DictInsert(comp_instruction_dictionary,"M","110000");
    DictInsert(comp_instruction_dictionary,"!M","110001");
    DictInsert(comp_instruction_dictionary,"-M","110011");
    DictInsert(comp_instruction_dictionary,"M+1","110111");
    DictInsert(comp_instruction_dictionary,"M-1","110010");
    DictInsert(comp_instruction_dictionary,"D+M","000010");
    DictInsert(comp_instruction_dictionary,"D-M","010011");
    DictInsert(comp_instruction_dictionary,"M-D","000111");
    DictInsert(comp_instruction_dictionary,"D&M","000000");
    DictInsert(comp_instruction_dictionary,"D|M","010101");


    dest_instruction_dictionary = DictCreate();

    DictInsert(dest_instruction_dictionary,"NULL","000");
    DictInsert(dest_instruction_dictionary,"M","001");
    DictInsert(dest_instruction_dictionary,"D","010");
    DictInsert(dest_instruction_dictionary,"MD","011");
    DictInsert(dest_instruction_dictionary,"A","100");
    DictInsert(dest_instruction_dictionary,"AM","101");
    DictInsert(dest_instruction_dictionary,"AD","110");
    DictInsert(dest_instruction_dictionary,"AMD","111");

    jump_instruction_dictionary = DictCreate();


    DictInsert(jump_instruction_dictionary,"NULL","000");
    DictInsert(jump_instruction_dictionary,"JGT","001");
    DictInsert(jump_instruction_dictionary,"JEQ","010");
    DictInsert(jump_instruction_dictionary,"JGE","011");
    DictInsert(jump_instruction_dictionary,"JLT","100");
    DictInsert(jump_instruction_dictionary,"JNE","101");
    DictInsert(jump_instruction_dictionary,"JLE","110");
    DictInsert(jump_instruction_dictionary,"JMP","111");

    predefined_symbol_dictionary = DictCreate();

    DictInsert(predefined_symbol_dictionary,"SP","0");
    DictInsert(predefined_symbol_dictionary,"LCL","1");
    DictInsert(predefined_symbol_dictionary,"ARG","2");
    DictInsert(predefined_symbol_dictionary,"THIS","3");
    DictInsert(predefined_symbol_dictionary,"THAT","4");

    DictInsert(predefined_symbol_dictionary,"R0","0");
    DictInsert(predefined_symbol_dictionary,"R1","1");
    DictInsert(predefined_symbol_dictionary,"R2","2");
    DictInsert(predefined_symbol_dictionary,"R3","3");
    DictInsert(predefined_symbol_dictionary,"R4","4");
    DictInsert(predefined_symbol_dictionary,"R5","5");
    DictInsert(predefined_symbol_dictionary,"R6","6");
    DictInsert(predefined_symbol_dictionary,"R7","7");
    DictInsert(predefined_symbol_dictionary,"R8","8");
    DictInsert(predefined_symbol_dictionary,"R9","9");
    DictInsert(predefined_symbol_dictionary,"R10","10");
    DictInsert(predefined_symbol_dictionary,"R11","11");
    DictInsert(predefined_symbol_dictionary,"R12","12");
    DictInsert(predefined_symbol_dictionary,"R13","13");
    DictInsert(predefined_symbol_dictionary,"R14","14");
    DictInsert(predefined_symbol_dictionary,"R15","15");


    instruction_dictionary = DictCreate();
}

/**
 * @internal function
 * @brief: This functions uses a delimeter to split a string by removing the delimiter and characters before it and leaving the rest
*/
void _remove_string(char * delimiter, char * source_string, char * dest_string)
{
    /* First call to strtok should be done with string and delimiter as first and second parameter*/
    char *token = strtok(source_string,delimiter);
    
    strcpy(dest_string,token);

    printf("After split %s \n",dest_string);
}