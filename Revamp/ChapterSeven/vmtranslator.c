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
#define SIMPLE_ADD_NO_COMMENT_OUTPUT_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd_no_comment.vm"
#define SIMPLE_ADD_NO_WHITESPACE_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd_no_whitespace.vm"
#define SIMPLE_ADD_ASM_OUTPUT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSeven/StackArithmetic/SimpleAdd.asm"




void parse_input_file(char * input_vm_file, char * no_comment_output_vm_file,char * no_whitespace_output_vm_file, int max_file_zie);


/**
 * @brief: Parser Module: This module parses the input
 * @note: There should be a universal counter for each line
 * @param parse_input_file: This function takes the input file, removes comments a and then reads the VM Code line by line
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
        
        // parse_instruction(str,counter);
        printf("%s",str);
        
    }

    fclose(file_ptr);
    
}






int main(int argc, char * argv[])
{

    parse_input_file(SIMPLE_ADD_VM_FILE,SIMPLE_ADD_NO_COMMENT_OUTPUT_ASM_FILE,SIMPLE_ADD_NO_WHITESPACE_ASM_FILE,MAX_FILE_SIZE);



    return 0;
}