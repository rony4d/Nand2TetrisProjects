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
#define ADD_HACK_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSix/add/add.hack"





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
void generate_c_instruction_binary(char * dest, char * comp, char * jump);



void parse_input_file(char * input_asm_file, char * no_comment_output_asm_file, char * no_whitespace_output_asm_file, int max_file_zie);
void parse_instruction(char * instruction, int counter);


/**
 * @internal function delarations
*/
void _remove_string(char * delimiter, char * source_string, char * dest_string);
void _initialize_c_instruction_tables();
void _split_c_instruction(char * source_string, char * dest, char * comp, char * jump);
void _write_instructions_to_file(char * hack_output_filename);





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
 * @brief: This function is under the Parser Module
 * -    This handles the a-instruction through the steps below
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

/**
 * @brief: This function is under the Parser Module
 * -    This function splits the c-instruction into dest, comp and jump symbols and then passes the symbols to the 
 *      code generation module to produce the binaries
*/

void c_instruction_handler(char * instruction, int counter){

    char dest_str[BINARY_MAX_BITS] = {0};
    char comp_str[BINARY_MAX_BITS] = {0};
    char jump_str[BINARY_MAX_BITS] = {0};

    _split_c_instruction(instruction,dest_str,comp_str,jump_str);

    // printf("Dest: %s ,Comp: %s , Jump: %s \n",dest_str,comp_str,jump_str);


    generate_c_instruction_binary(dest_str,comp_str,jump_str);

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
void generate_c_instruction_binary(char * dest, char * comp, char * jump)
{

    if(strcmp(dest,"") == 0)
        dest = "NULL";
    if(strcmp(jump,"") == 0)
        jump = "NULL";  

    
    eat_white_space(dest);
    eat_white_space(comp);
    eat_white_space(jump);

    char *a;

    //  check if comp contains M, if it contains M then "a=1" else "a=0"
    if(strstr(comp,"M"))
    {
        a = "1";
    }else{
        a = "0";
    }

    //  Search the dest_instruction_dictionary
    const char * dest_binary = DictSearch(dest_instruction_dictionary,dest);
    
    
    //  Search the comp_instruction_dictionary
    const char* comp_binary = DictSearch(comp_instruction_dictionary,comp);


    //  Search the jump_instruction_dictionary
    const char* jump_binary = DictSearch(jump_instruction_dictionary,jump);


    // build c-instruction to look like this 111accccccdddjjj

    char final_c_instruction_binary[BINARY_MAX_BITS] = {0};

    strncat(final_c_instruction_binary,"111",strlen("111"));

    strncat(final_c_instruction_binary,a,strlen(a));

    strncat(final_c_instruction_binary,comp_binary,strlen(comp_binary));

    strncat(final_c_instruction_binary,dest_binary,strlen(dest_binary));

    strncat(final_c_instruction_binary,jump_binary,strlen(jump_binary));

    //  insert into the global instruction dictionary

    char counter_str[BINARY_MAX_BITS] = {0};

    convert_to_string(counter,counter_str);

    DictInsert(instruction_dictionary,counter_str,final_c_instruction_binary);

}


/**
 * @brief: Symbol Table Module: This module handles symbols
*/



int main(int argc, char * argv[])
{
    _initialize_c_instruction_tables();

    parse_input_file(ADD_ASM_FILE,ADD_NO_COMMENT_OUTPUT_ASM_FILE,ADD_NO_WHITESPACE_OUTPUT_ASM_FILE,MAX_FILE_SIZE);

    _write_instructions_to_file(ADD_HACK_OUTPUT_FILE);
    
//     char dest_str[BINARY_MAX_BITS] = {0};
//     char comp_str[BINARY_MAX_BITS] = {0};
//     char jump_str[BINARY_MAX_BITS] = {0};

//     char src_str[BINARY_MAX_BITS] = "M=M+D";


//    _split_c_instruction(src_str,dest_str,comp_str,jump_str);

//    printf("Dest: %s ,Comp: %s , Jump: %s \n",dest_str,comp_str,jump_str);
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


/**
 * @internal function
 * @brief: This function will split the c-instruction into its component fields
 * 
 * -    c-instruction generally looks like this dest=comp;jump  . Either dest or jump fields may be empty
 * 
 * @note always use original source_string for comparison as strtok() function modifies the string. 
 * @param source_string: This is the c_instruction we want to process
 * @param dest_output: This is the variable that holds the return value for dest that will be accessed outside this function
 * @param comp_output: This is the variable that holds the return value for comp that will be accessed outside this function
 * @param jump_output: This is the variable that holds the return value for comp that will be accessed outside this function
*/
void _split_c_instruction(char * source_string, char * dest_output, char * comp_output, char * jump_output)
{
    char source_string_dest_copy[BINARY_MAX_BITS];
    char source_string_jump_copy[BINARY_MAX_BITS];

    memcpy(source_string_dest_copy,source_string,strlen(source_string)+1);
    memcpy(source_string_jump_copy,source_string,strlen(source_string)+1);


    char * equality_delimiter = "=";
    char * semi_colon_delimiter = ";";

    
    char *dest = {0};
    char *comp = {0};
    char *jump = {0};

    /*  Solve for dest  */
    dest = strtok(source_string_dest_copy,equality_delimiter);  //  This should return dest if it exists and should return original string if dest does not exist

    //  if dest == NULL then it means that dest is omitted

    //  if dest != source_string_dest_copy then the next string is our comp instruction. 
    if(strcmp(dest,source_string) != 0)
    {
        
        comp = strtok(NULL,semi_colon_delimiter);
    }else
    {
        //   if dest is equal then it means dest does not exist and then we set it to empty
        dest = "";
    }


    /*  Solve for jump  */

    char* jump_preceeding_characters = strtok(source_string_jump_copy,semi_colon_delimiter);  // This should return the characters before ";"


    //  if jump_preceeding_characters != source_string_jump_copy then it means jump is omitted but if not, then we need to do one more operation to get jump symbol

    if(strcmp(jump_preceeding_characters,source_string) != 0)
    {
        //  if jump_preceeding_characters is not null then the next string is simply the jump symbol and the previous string is the comp symbol

        jump = strtok(NULL, semi_colon_delimiter);

        //   process the jump_preceeding_characters string to get comp symbol by checking if it has a dest in it, if not then whole string is comp
        //   also check if comp has value, if it does then no need assign value to it again
        

        char original_jump_preceeding_characters[BINARY_MAX_BITS];  // since we will work on the jump_preceeding_characters, lets create a copy that will not be modified by strtok(), see note above in function description
        memcpy(original_jump_preceeding_characters,jump_preceeding_characters,strlen(jump_preceeding_characters)+1);    

        //  there must be a comp field so splitting original_jump_preceeding_characters with semi_colon_delimiter will return the comp field
        //  there can can also be a dest, so if dest is not empty, we know there is a dest, so we remove it
        if(dest != "" && comp == "")
        {
            //  remove dest from jump_preceeding_characters and don't use it for anything
           strtok(jump_preceeding_characters, equality_delimiter); 

           //   move to the next string which will be the comp 
           comp = strtok(NULL, jump_preceeding_characters);
        }
        if(strcmp(comp,"") == 0)
        {
            // no destination exists hence, we get comp from original_jump_preceeding_characters


            //   move to the next string which will be the comp 
            comp =  jump_preceeding_characters;
        }
        
          
    }
    else
    {
        //   if dest is equal then it means dest does not exist and then we set it to empty
        jump = "";
    }
    
    
    /*  Solve for comp if neither dest nor jump exists  */

    //  if dest == "" and jump == "" it means that "=" and ";" do not exist, hence we have only comp instruction
    if(dest == "" && jump == "" )
    {
        strcpy(comp,source_string);
    }
    

    strncat(dest_output,dest,BINARY_MAX_BITS);
    strncat(comp_output,comp,BINARY_MAX_BITS);
    strncat(jump_output,jump,BINARY_MAX_BITS);
}


/**
 * @internal function
 * @brief   This function marches through the global instruction dictionary using the counter variable as the key in increasing order from 1 
 *          till max count is reached to generate the .hack file with binary instructions
 * 
*/
void _write_instructions_to_file(char * hack_output_filename){

    int counter_copy = 1;
    
     // remove output file if already exists
    remove(hack_output_filename);

    FILE* file_ptr;
    file_ptr = fopen(hack_output_filename,"w");   
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

        const char * binary_result = DictSearch(instruction_dictionary,counter_str);

        if(binary_result != 0){

            //  insert only when a result is returned 

            fprintf(file_ptr,"%s\n", binary_result);

        }

        counter_copy += 1;
    }

    fclose(file_ptr);
    
}