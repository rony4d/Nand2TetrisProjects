#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

#define MAX_BUFF 4096
#define BINARY_RESULT 64
#define WORD_SIZE 16
#define SYMBOL_LESS_ASM "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSix/add_test.asm"
#define SYMBOL_LESS_ASM_TEMP "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/ChapterSix/add_test_tmp.asm"

int line_number = 0;
void eat_comment(char *line, char *new_line);
void read_file(char *filename, char *buffer);
void print_file_buffer(char *buffer);
void print_file_stream(FILE *stream);
void remove_comments(FILE *src_file,FILE *tmp_file);
void convert_decimal_to_binary(int n, char *binary_result);
void parse_a_instruction(char *instruction, char *binary_result);
void parse_c_instruction(char *instruction, char *binary_result);
void parse_instruction(FILE *src_file);
void build_c_instruction();
void destroy_c_instruction();
void dissect_c_symbolic_instruction(char *symbolic_instruction, char *symbolic_instruction_src,char *binary_result);
void get_binary_result(char *dest, char *comp, char *jump,char *binary_result);
static char* strip_whitespace(char* instruction);

Dictionary *c_inst_dictionary_A0_comp;
Dictionary *c_inst_dictionary_A1_comp;
Dictionary *c_inst_dictionary_dest;
Dictionary *c_inst_dictionary_jump;
/**
 * A. We want to parse a symbol-less assemby file 
 *  1. Read the assembly file
 *  2. Strip all white space lines
 *  2a. Check if a string or line is empty
 *  2b. Remove empty lines
*/

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
 * Removes comments from lines
 * 1. Read character by character, when you meet //, eat rest of the characters on that line
 * 2. Read character by character, when you meet / *, eat rest of the characters in the document till you meet * / then stop 
 * Assumption: We are working with file with non-empty lines
*/


void remove_comments(FILE *src_file,FILE *tmp_file){

    char buffer[MAX_BUFF] = {0};
    
    // read file line by line


    while ((fgets(buffer,MAX_BUFF,src_file)) != NULL)
    {
        char new_line_without_comment[MAX_BUFF] = {0};
        //If current line has comment, eat the comment and copy to new line
       
        eat_comment(buffer,new_line_without_comment);
        if (new_line_without_comment[0] != '\n') // do not allow empty line to pass
        {
            // printf("No comment Line %d: %s",count,new_line_without_comment);
             ++line_number;
            fputs(new_line_without_comment,tmp_file);
        }
        
    }
    
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
 * Detect A-instruction and convert the value to binary
 * Detect C-instruction
*/
void parse_instruction(FILE *src_file){
    
    char instructions[MAX_BUFF] = {0};
    
    //read file line by line
    while (fgets(instructions,MAX_BUFF,src_file) != NULL)
    {
        char binary_result[BINARY_RESULT] = {0};
        //check the first character on the line, if it is @ then A-instruction, else C-instruction
        if (instructions[0] == '@')
        {
            /* Handle A-instruction */
            char binary_result[BINARY_RESULT] = {0};
            parse_a_instruction(instructions,binary_result);
            printf("Binary Result: %s \n", binary_result);
        }else
        {
            /* Handle C-instruction */
            char *instructions_result = strip_whitespace(instructions);
            parse_c_instruction(instructions_result,binary_result);
            printf("Binary Result: %s \n", binary_result);
        }
        
    }
    
}

/**
 * @brief Parse the c-instruction and get the binary result
*/
void parse_c_instruction(char *instruction, char *binary_result){
    /** For C-instruction, either the dest or jump fields may be empty
      * C-inst full format-> dest=comp;jump
      * C-inst part format-> dest=comp
      * C-inst part format-> comp;jump
    */

    //Build dest, comp and jump truth tables using hash tables - Done
    build_c_instruction();

    //Spilt c_inst into format fields, then match non-empty fields with respective truth tables.

    char *instruction_src = strdup(instruction); // create duplicate that will not be modified when either dest or jump is empty
    dissect_c_symbolic_instruction(instruction,instruction_src,binary_result);
    
}

/**
 * Use the parameters as Keys in their respective dictionaries to get binary result
 * a is the a part of the c instruction
*/
void get_binary_result(char *dest, char *comp, char *jump,char *binary_result){

    const char *dest_binary_result;
    const char *jump_binary_result;
    const char *comp_binary_result;
    int size = sizeof(binary_result) - strlen(binary_result) - 1; // maximum size of character to be contatenated to the src

    if (dest != NULL)
    {
        dest_binary_result = DictSearch(c_inst_dictionary_dest, dest);
    }
    else
    {
        dest_binary_result = "000";
    }
    if (jump != NULL)
    {
        jump_binary_result = DictSearch(c_inst_dictionary_jump, jump);
    }
    else
    {
        jump_binary_result = "000";
    }


    comp_binary_result = DictSearch(c_inst_dictionary_A1_comp, comp);
    // is 'a' part of the c instruction equal to 1?
    if(comp_binary_result != 0)
    {
        // a part of the c instruction is 1
        //add binary result head, 111a,
        strncat(binary_result, "1111", size);
    }else{

        comp_binary_result = DictSearch(c_inst_dictionary_A0_comp,comp);
        if(comp_binary_result != 0)
        {         
            // 'a' part of the c instruction equal to 1
            //add binary result head, 111a, 
            strncat(binary_result,"1110",size);
        }
    }
    

    strncat(binary_result,comp_binary_result,size);
    strncat(binary_result,dest_binary_result,size);
    strncat(binary_result,jump_binary_result,size);
        
}

/**
 *  splits the symbolic instruction and returns the binary equivalient
 *  example: MD=D+1 returns 1110011111011000
 *  NOTE: either dest or jump fields may be empty, if dest field is empty '=' is omitted, if jump is empty ';' is omitted
 */
void dissect_c_symbolic_instruction(char *symbolic_instruction, char *symbolic_instruction_src,char *binary_result)
{
    char *dest = {0};
    char *comp = {0}; 
    char *jump = {0};
    char *dest_tmp = {0};
    char dest_str[BINARY_RESULT] = {0};
    char comp_str[BINARY_RESULT] = {0};
    char jump_str[BINARY_RESULT] = {0};


    const char *dest_delimiter = "=";
    const char *jump_delimiter = ";";

    dest = strtok(symbolic_instruction,dest_delimiter);   //dest instruction   
    

    if (!(strcmp(dest,symbolic_instruction_src) == 0))
    {
        // '=' exists in the instruction
        while (dest != NULL)
        {
            dest_tmp = strtok(NULL,dest_delimiter);
            
            //next instruction field is comp if jump field ";" does not exist
            symbolic_instruction = strdup(symbolic_instruction_src);
            char *jump_internal = strtok(symbolic_instruction,jump_delimiter);
            
            if( strcmp(jump_internal,symbolic_instruction_src) == 0 ){
                
                // values are equal so jump does not exist so we assign dest_tmp to comp field and break from loop, we are done
                comp = strdup(dest_tmp);
                break;

            }else
            {
                // ------>dest, comp and jump exist in the instruction<--------
                // jump exits so we handle it by getting smart and eating the instruction
                // we first eat dest
                char ch = *(symbolic_instruction_src++);
                while (ch != '=')
                {
                    //copy ch to dest
                    char *str = &ch;          
                    strncat(dest_str,str,1); //concatenate ch to dest
                    ch = *(symbolic_instruction_src++);
                }
                
                dest = strdup(dest_str); // copy fresh dest_str to dest

                // eat '=' and move to next character
                ch = *(symbolic_instruction_src++);

                while(ch != ';'){
                    //copy ch to comp
                    char *str = &ch;
                    strncat(comp_str,str,1); //concatenate ch to comp
                    ch = *(symbolic_instruction_src++);
                }

                comp = strdup(comp_str); // copy fresh comp_str to comp

                // eat ';' and move to next character
                ch = *(symbolic_instruction_src++);

                while(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0'){
                    //copy ch to comp
                    char *str = &ch;
             
                    strncat(jump_str,str,1); //concatenate ch to jump
                    ch = *(symbolic_instruction_src++);
                }

                jump = strdup(jump_str); // copy fresh jump_str to jump. we are done time to bail
                break;
            }
            
            
            
        }
        
    }

    //if current character in symbolic_instruction_src is empty it means we have finished eating it so we just bail
    if(*(symbolic_instruction_src) == '\0'){

        // printf("dest: %s, comp: %s, jump %s \n",dest,comp,jump);
        get_binary_result(dest,comp,jump,binary_result);
        return;
    }
        

    // since we have processed dest, we now have only comp and jump to worry about
    symbolic_instruction = strdup(symbolic_instruction_src);
    
    // comp part of the jump
    char *jump_comp = strtok(symbolic_instruction,jump_delimiter); 
    
    if (!(strcmp(jump_comp,symbolic_instruction_src) == 0))
    {
        // ------->only jump and comp exist in the instruction<------

        // ';' exists in the instruction 
       comp = strdup(jump_comp); // we found comp next we assign jump

        while (jump_comp != NULL)
        {
            // we just assign jump and bail
            jump = strtok(NULL,jump_delimiter);

            break;

        }
        
        dest = NULL; // set dest to NULL
    }

    // print result
    // printf("dest: %s, comp: %s, jump %s \n",dest,comp,jump);
    get_binary_result(dest,comp,jump,binary_result);    
}



void build_c_instruction(){
    
    if ((c_inst_dictionary_A0_comp == NULL) && (c_inst_dictionary_A1_comp == NULL) && (c_inst_dictionary_dest == NULL) && (c_inst_dictionary_jump == NULL))
    {
        c_inst_dictionary_A0_comp = buid_compute_instruction_set_ALU('0');
        c_inst_dictionary_A1_comp = buid_compute_instruction_set_ALU('1');
        c_inst_dictionary_dest = build_compute_instruction_set_destination();
        c_inst_dictionary_jump = build_compute_instruction_set_jump();
    }
    
}

void destroy_c_instruction(){

    if ((c_inst_dictionary_A0_comp != NULL) && (c_inst_dictionary_A1_comp != NULL) && (c_inst_dictionary_dest != NULL) && (c_inst_dictionary_jump != NULL))
    {
        DictDestroy(c_inst_dictionary_A0_comp);
        DictDestroy(c_inst_dictionary_A1_comp);
        DictDestroy(c_inst_dictionary_dest);
        DictDestroy(c_inst_dictionary_jump);
    }
}

void parse_a_instruction(char *instruction, char *binary_result){

    //check the next character after @
    if (isalpha(instruction[1]))
    {
        /* Symbol A-instruction */
    }
    
    if (isdigit(instruction[1]))
    {
        /* Symbol-less A-instruction */
        
        int size = strlen(instruction); 

        //copy the rest of the characters into a new string
        char new_a_inst[WORD_SIZE] = {0}; // We just need a string big enough to hold the decimal value in the a_inst

        for (size_t i = 1; i < size; i++)
        {
            // start from index 1 because we are ignoring the @ sign at index 0
            char ch = instruction[i];
            strncat(new_a_inst,&ch,1); // concatenate one character at a time
        }
        
        //Convert the decimal string to binary
        int decimal_number = atoi(new_a_inst);
        convert_decimal_to_binary(decimal_number,binary_result);
    }
    
}

void convert_decimal_to_binary(int n, char *binary_result) {
    char bin_str[BINARY_RESULT] = {0};
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    snprintf(bin_str,BINARY_RESULT,"%llu",bin);

    //pad the binary string to 16 bits

    int bin_str_count = strlen(bin_str);
    int pad_number = WORD_SIZE - bin_str_count;

    for (size_t i = 0; i < pad_number; i++)
    {
        char zero = '0';
        strncat(binary_result,&zero,1);
    }
    
    int size = sizeof(binary_result) - strlen(binary_result) - 1; // maximum size of character to be contatenated to the src

    strncat(binary_result,bin_str,size);

}

int main(int argc, char *argv[]){


    //1. Read File
    char buff[MAX_BUFF] = {0};
    char line_without_comment[MAX_BUFF] = {0};
    

    read_file(SYMBOL_LESS_ASM,buff);
    print_file_buffer(buff);

    //2a. Check if line is empty
    char *line1 = "My name is ugochukwu aronu";
    char *line2 = "                          ";

    if (!is_empty(line1))
        printf("Line 1 not empty \n");
    if(is_empty(line2))
        printf("Line 2 is empty \n");
    
    
    /**2b. Remove empty lines from file
     * 
    */
    FILE *src_file;
    FILE *tmp_file;

    src_file = fopen(SYMBOL_LESS_ASM, "r");          // opens source file for reading
    tmp_file = fopen(SYMBOL_LESS_ASM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    if (src_file == NULL || tmp_file == NULL)
    {
       printf("Unable to open files \n");
    }
    
    printf("\n File contents before removing all empty lines \n\n");
    print_file_stream(src_file);

    //Move source file pointer to the beginning 
    rewind(src_file);

    //Remove empty lines from file.
    remove_empty_lines(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Test eating comment

    // eat_comment("Hello I have a comment //Test eating comment",line_without_comment);
    // printf("%s \n",line_without_comment);

    //Delete src file and rename tmp file as src file
    remove(SYMBOL_LESS_ASM);
    rename(SYMBOL_LESS_ASM_TEMP,SYMBOL_LESS_ASM);

    printf("\n File contents after removing all empty lines \n\n");
    
    //Open src file and print its contents
    src_file = fopen(SYMBOL_LESS_ASM, "r");
    print_file_stream(src_file);
    fclose(src_file);
    

    //Remove comments from file

    //Open src file and read from it and open tmp file
    src_file = fopen(SYMBOL_LESS_ASM, "r");
    tmp_file = fopen(SYMBOL_LESS_ASM_TEMP, "w");    // opens tmp file for writing, creates file if it does not exist

    //Move src file pointer to the beginning
    rewind(src_file);

    //Remove the comments from file
    remove_comments(src_file,tmp_file);

    //Close all open files
    fclose(src_file);
    fclose(tmp_file);

    //Delete src file and rename tmp file as src file
    remove(SYMBOL_LESS_ASM);
    rename(SYMBOL_LESS_ASM_TEMP,SYMBOL_LESS_ASM);

    printf("\n File contents after removing all comments - Line Count : %d \n\n",line_number);
    
    //Open src file and print its contents
    src_file = fopen(SYMBOL_LESS_ASM, "r");
    print_file_stream(src_file);
    fclose(src_file);

    // Parse Instruction

    printf("\n Parsing instructions in assembly file \n\n");

    // Open src file 
    src_file = fopen(SYMBOL_LESS_ASM, "r");

    parse_instruction(src_file);

    //close file
    fclose(src_file);

    //build c instruction dictionaries
    c_inst_dictionary_A0_comp = buid_compute_instruction_set_ALU('0');
    c_inst_dictionary_A1_comp = buid_compute_instruction_set_ALU('1');
    c_inst_dictionary_dest = build_compute_instruction_set_destination();
    c_inst_dictionary_jump = build_compute_instruction_set_jump();

    
    //destroy c_instruction dictionaries after parsing file
    /* Dissection test */
    // char dest_result[BINARY_RESULT] = {0};
    // char comp_result[BINARY_RESULT] = {0};
    // char jump_result[BINARY_RESULT] = {0};
    // char binary_result[BINARY_RESULT] = {0};

    // char input[] = "MD=D+1";
    // char *input_dup = strdup(input);
    // dissect_c_symbolic_instruction(input,input_dup,binary_result);

    // char input1[] = "D=D+1;JLE";
    // char * input_dup = strdup(input1);
    // dissect_c_symbolic_instruction(input1,input_dup,binary_result);

    // char input2[] = "0;JMP";
    // char *input_dup = strdup(input2);
    // dissect_c_symbolic_instruction(input2,input_dup,binary_result);


    // printf("Binary result: %s \n", binary_result);

    return 0;

}