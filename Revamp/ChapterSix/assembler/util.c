/*
    This is a utility file for handling utility functions such as

    1.  Reading files       -   done
    2.  Writing to files    -   done
    3.  Check for comments and remove comments from files   -   done
    4.  Remove white space  -   done

    references
    -   https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/
    -   https://www.programiz.com/c-programming/c-file-input-output
    -   https://www.thedailyprogrammer.com/2016/02/c-program-to-remove-comments-from-file.html
    -   check man page: 'man fopen' and others to see documentation
    -   https://linuxhint.com/split-strings-delimiter-c/


    Todo: Improve printf by creating a logger or debug wrapper with colour codes, line numbers and different debug cateroies(info, warning, error). All debug to be turned off by
    changing one variable 

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_FILE_SIZE 4096  
#define BINARY_MAX_BITS 64
#define WORD_SIZE 16
#define TEST_NO_COMMENT_TXT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSix/assembler/test/test_no_comment.txt"
#define TEST_NO_WHITESPACE_TXT_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSix/assembler/test/test_no_whitespace.txt"
#define TEST_ASM_FILE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterSix/assembler/test/Add.asm"


//  Todo: move all function delcarations to util.h
void write_to_file(char* location, char * content);
void read_file(char *filename, int max_size);

void check_comment(char c, FILE* input_file_pointer, FILE* output_file_pointer);       //  checks for both block or multiline comment or single line comment and passes control to the respective handler
void block_comment_handler(FILE* input_file_pointer);           //  handles block or multiline comments  
void single_comment_handler(FILE* input_file_pointer);          //  handles single line comments
void remove_white_spaces(char * input_file, char * output_file, int file_max_size);
static char * eat_white_space(char *p1);
void convert_decimal_to_binary(int n, char *binary_result);     //  converts decimal to 16-bit binary number
void convert_to_string(int n, char* result);                      //  conver integer to string    
void split_string(char * delimiter, char * source_string, char * dest_string);  
int convert_string_to_number(char * input_str);



void read_file(char *filename, int max_size)
{
    FILE* file_ptr;
    char str[MAX_FILE_SIZE];

    file_ptr = fopen(filename,"r");

    if (file_ptr == NULL)
    {
        printf("File can't be opened \n");
        exit(1);
    }

    printf("Content of this file are \n");
    
    //  read file line by line
    while (fgets(str,max_size,file_ptr) != NULL)    
    {
        //printf("%s", str);
    
    }

    fclose(file_ptr);
    
}
/**
 * @brief: This is a test function to check if fgetc called multiple times on a File pointer tracks the next character called by the previous fgetc
 * @result: The result is correct, multiple fgetc function calls to the same file pointer will tract the next character in the output stream
*/
void read_file_with_multiple_fgetc_calls(char *filename, int max_size)
{
    FILE* file_ptr;
    char str[MAX_FILE_SIZE];

    file_ptr = fopen(filename,"r");

    if (file_ptr == NULL)
    {
        printf("File can't be opened \n");
        exit(1);
    }

    printf("Content of this file are \n");
    
    //  read file character by character
    char first_char = fgetc(file_ptr);
    
    if(first_char != NULL){
        // read next char
        char next_char = fgetc(file_ptr);

        printf("First char: %c ; Second char: %c ", first_char, next_char);
    }
    

    fclose(file_ptr);
    
}

void write_to_file(char* location, char * content)
{
    FILE* file_ptr;
    file_ptr = fopen(location,"ab+");   //  ab+ mode creates a file if it does not exist and also opens it for for reading and writing
    char str[MAX_FILE_SIZE];

    if (file_ptr == NULL)
    {
        printf("File not found !!! \n");
        exit(1);
    }

    fprintf(file_ptr,"%s", content);
    fclose(file_ptr);
    
}


void remove_comment(char* input_filename, char *output_filename){

    // remove output file if already exists so it does not 
    remove(output_filename);

    FILE* input_file_pointer;
    FILE* output_file_pointer;
    char c;

    input_file_pointer = fopen(input_filename,"r");         //  open the input file in read mode
    output_file_pointer = fopen(output_filename, "ab+");     //  open the output file in read-write mode and if file does not exist, create it

    while ((c=fgetc(input_file_pointer)) && c!= EOF)              //  read the input file character by character
    {
        check_comment(c,input_file_pointer,output_file_pointer);                                   //  check each character to know if it is the beginning of a comment
    }
    
    //  close both the files at the end of the program
    fclose(input_file_pointer);
    fclose(output_file_pointer);
}


void check_comment(char c, FILE* input_file_pointer, FILE* output_file_pointer)
{
    char next_char;

    if (c == '/')   
    {
        next_char = fgetc(input_file_pointer);
        if(next_char == '*')
        {
            //  block comment
            block_comment_handler(input_file_pointer);
        }
        else if(next_char == '/')
        {
            //  single comment
            single_comment_handler(input_file_pointer);
        }
        else
        {
            //  If both cases fail, it is not a comment, so we add the character as it is in the new file
            fputc(c,output_file_pointer);
            fputc(next_char,output_file_pointer);
        }


    }
    else{

        fputc(c, output_file_pointer);

    }
    
}


void block_comment_handler(FILE* input_file_pointer){

    char current_char, next_char;

    while ( (current_char =  fgetc(input_file_pointer)) && current_char != EOF)
    {
        //  the block comment has started, just keep eating the characters and do nothing. 

        if (current_char == '*')    
        {
            /* seems like the comment is ending */
            next_char=fgetc(input_file_pointer);    // get the next character and check if it actually ends. (block comments end with '*/')

            if (next_char == '/')
            {
                /* return from function */
                return;
            }
            
        }
        
    }
    

}

void single_comment_handler(FILE* input_file_pointer)
{

    char current_char, next_char;

    while ((current_char = fgetc(input_file_pointer)) && current_char != EOF)
    {
        //  the single comment has started, just keep eating the characters and do nothing

        if (current_char == '\n')   //  check if the comment ends ( single line comments end with '\n' or newline )
        {
            /* it seems the single line comment is about to end*/

            return;
        }
        
    }
    

}


void remove_white_spaces(char * input_file, char * output_file, int file_max_size)
{
        // remove output file if already exists so it does not 
        remove(output_file);

        FILE* input_file_pointer;
        FILE* output_file_pointer;

        char str[MAX_FILE_SIZE];

        input_file_pointer = fopen(input_file,"r");
        output_file_pointer = fopen(output_file,"w");

        if (input_file_pointer == NULL)
        {
            printf("File can't be opened \n");
            exit(1);
        }
        
        printf("Content below has no spaces!!! \n");
        //  read file line by line
        while (fgets(str,file_max_size,input_file_pointer) != NULL)    
        {
            
            int value = strlen(str);
            char* result = eat_white_space(str);
            
            if(strcmp(result,"\0") != 0){             
                /*  
                    This if statement check removes completely empty lines. Remove this if statement and see how the output file will look 
                */              
                fprintf(output_file_pointer,"%s\n", result);
            }
        
        }

        fclose(input_file_pointer);
        fclose(output_file_pointer);
}


static char * eat_white_space(char *p1)
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


void convert_decimal_to_binary(int n, char *binary_result) {
    char bin_str[BINARY_MAX_BITS] = {0};
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    snprintf(bin_str,BINARY_MAX_BITS,"%llu",bin);     //NOTE: this is a simple line of code used to convert a number to a string AKA toString() :)

    //pad the binary string to 16 bits

    int bin_str_count = strlen(bin_str);
    int pad_number = WORD_SIZE - bin_str_count;

    for (size_t i = 0; i < pad_number; i++)
    {
        char zero = '0';
        strncat(binary_result,&zero,1);
    }
    
    int size = BINARY_MAX_BITS - strlen(binary_result) - 1; // maximum size of character to be contatenated to the src

    strncat(binary_result,bin_str,size);            //  NOTE: binary_result pointer will be modified by this function 

}

/**
 * @brief: Converts an integer to a string
*/
void convert_to_string(int n, char* result){

    if(result == NULL){
        printf("Initiazlize result ");
    }
    snprintf(result,BINARY_MAX_BITS,"%d",n);     

}

/**
 * @brief: Converts string to an integer
*/
int convert_string_to_number(char * input_str)
{
    if (input_str != NULL)
    {
        int result;
        sscanf(input_str,"%d", &result);
        return result;
    }
    
    return 0;
}

/**
 * @brief: This functions uses a delimeter to split a string 
*/
void split_string(char * delimiter, char * source_string, char * dest_string)
{
    unsigned count = 0;
    /* First call to strtok should be done with string and delimiter as first and second parameter*/
    char *token = strtok(source_string,delimiter);
    
    /* Consecutive calls to the strtok should be with first parameter as NULL and second parameter as delimiter
         * * return value of the strtok will be the split string based on delimiter*/
    
    while (token != NULL)
    {
        printf("Token no. %d : %s \n", count, token);
        token = strtok(NULL, delimiter);
        count++;
    }
    


}



/**
 * @brief: This main function is used  to test the different functions here to ensure they work properly 
 * Uncomment to test the dictionary data structure here 
 * 
*/

// int main(int argc, char* argv[])
// {

//     remove_comment(TEST_ASM_FILE,TEST_NO_COMMENT_TXT_FILE);                                     // remove comment from .asm file and write to a new text file without comment
//     remove_white_spaces(TEST_NO_COMMENT_TXT_FILE,TEST_NO_WHITESPACE_TXT_FILE,MAX_FILE_SIZE);    //  remove  whitespace from comment file and write to a new text file without whitespace
    
//     char result[WORD_SIZE] = {0};
//     convert_decimal_to_binary(282,result);

//     printf("Result: %s \n", result);

//     char str[BINARY_MAX_BITS] = {0};
    
//     convert_to_string(345669,str);

//     printf("String Value: %s \n", str);

//     char dest_str[MAX_FILE_SIZE] = {0};

//     char src_str[MAX_FILE_SIZE] = "A=D+A;JGT";
//     split_string(";",src_str,dest_str);

//     char  input_str[MAX_FILE_SIZE] = "123456789";
    
//     int x = convert_string_to_number(input_str);
//     printf("%d", x);

//     read_file_with_multiple_fgetc_calls(TEST_ASM_FILE,MAX_FILE_SIZE);   // this was done to test a query

//     return 0;
// }