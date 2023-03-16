#include "../ChapterSix/assembler/dictionary.c"
#include "../ChapterSix/assembler/util.c" 
 
#include "compiler.h"
#include "linkedlist.c"

 /**
  * 
  *         - - - -             - - - - -
  *     |                   |               |
  *     |                   |               |
  *     |                   |               |
  *     |                   |               |
  *         - - - -             - - - - - 
  * 
  *     JACK COMPILER
  * 
  *     Implementation Steps
  * 

  * 
  *     1.  Jack Tokenizer: The tokenizer will take the Jack file as input and provide an XML output
  *         
  *         STEPS
  * 
  *         -   0)  Read .jack file or files in a directory. 
  *                 Remove comments and whitespaces
  * 
  *         -   1)  Create a data structure to initialize and hold the lexical elements : The Jack Language includes 5 categories of terminal (lexical) elements or tokens ( See Slide 85 of Chapter 10 Lecture Note)
  *                 The token categories are : Keyword, symbol, integer constant, string constant and identifier
  * 
  *         -       Based on the different tokens in each category, breakdown the input code into a token stream and store the stream in a list
  * 
  *         -   2)  Create a tokenizer that will breakdown the input code character by character and compare with the lexical elements stores. 
  * 
  *   
  *                 
  *         -   2)  Write parser that generates the XML output of the tokens only which are the terminal elements . See Slide 105 for example of how XML output of only tokens looks.
  *                 
  * 
  *         -   3)  Wirte parser that generates the XML output of both terminal (token) and non-terminal elements
  * 
  *         Tokenizer Details:
  * 
  *         -   See 'tokenize' function below that implements the above
  * 
  *         NOTES:
  *         -   A token is a string of characters that has meaning. This means that we need to breakdown the input code character by character and constantly check if any single or character group matches any member of the token categories
  *             based on the Jack Grammar Lexical elements section
  * 
  * 
  * 
  *         
  *         
  * 
  * 
  *     2.  Compilation Engine: 
  * 
  * 
  * 
  *     
  *       
 */

//  Chapter 8 Projects
#define MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/Main.jack"
#define MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_COMMENT_OUTPUT "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/Main_no_comment.jack"
#define MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_WHITESPACE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/Main_no_whitespace.jack"
#define MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_TOKEN_XML_OUTPUT "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/MainT.xml"


#define SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/Square.jack"
#define SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_COMMENT_OUTPUT "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/Square_no_comment.jack"
#define SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_WHITESPACE "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/Square_no_whitespace.jack"
#define SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE_TOKEN_XML_OUTPUT "/Users/ugochukwu/Desktop/rony/ComputerBasics/ProjectFiles/Revamp/ChapterTen/ExpressionLessSquare/Project/SquareT.xml"


Dict defined_keyword_token_category_dictionary;                     //  this dictionary holds the already defined elements in the keyword category of the tokens
Dict defined_symbol_token_category_dictionary;                      //  this dictionary holds the already defined elements in the symbol category of the tokens

int token_counter = 1;                                              //  this variable tracks successful tokens that have been found

Dict found_keyword_token_dictionary;                                //  this dictionary holds the keywords that are found from the input code as value and token_counter as key
Dict found_symbol_token_dictionary;                                 //  this dictionary holds the symbols that are found from the input code as value and token_counter as key
Dict found_integerConstant_token_dictionary;                        //  this dictionary holds the integer constants that are found from the input code as value and token_counter as key
Dict found_stringConstant_token_dictionary;                         //  this dictionary holds the string constants that are found from the input code as value and token_counter as key
Dict found_identifier_token_dictionary;                             //  this dictionary holds the identifiers that are found from the input code as value and token_counter as key



linked_list * token_list = NULL;                                    //  linked list that holds all the tokens in sequential order while eating code from left to right and top to bottom



/**
 * @brief internal functions
 * @param _processCompoundWord : Processes words that contain symbols eg  text;  if(i){   a[i]   a=1;
*/

void _processCompoundWord(char * word);

/**
 * @brief: Tokenizer Module : This module contains functions that read the jack files , analyzes the syntax based on Jack Grammar, tokenizes and parses the code to generate XML output
 * @param parse_jack_input_file: This function takes the input jack file, removes comments a and then reads the jack code line by line and populates the token linked list
 * @param tokenize: Takes in each line of code and prints out the XML output as well as stores the XML output in a linkedList
 *
*/

void tokenize(char* sentence);
int isKeyword(char* word);
int isSymbol(char c);
void writeTokenizedXMLOutputToFile(char * tokenized_xml_output_filename);







void parse_jack_input_file(char * filename, char * input_jack_file, char * no_comment_output_jack_file,char * no_whitespace_output_jack_file, int max_file_zie)
{  
    //  1. remove comments and store in no_comment vm file

    remove_comment(input_jack_file,no_comment_output_jack_file);

    //  2. remove whitespace and write to no_whitespace asm file.

    remove_white_spaces(no_comment_output_jack_file,no_whitespace_output_jack_file,max_file_zie);

    //  3. read no_whitespace asm file and begin march through the lines. 

    FILE* file_ptr;
    char str[MAX_FILE_SIZE];

    file_ptr = fopen(no_whitespace_output_jack_file,"r");

    if (file_ptr == NULL)
    {
        printf("File can't be opened \n");
        exit(1);
    }
    
    int counter = 1;
    //  read file line by line
    while (fgets(str,MAX_FILE_SIZE,file_ptr) != NULL)    
    {

        // printf("Line %d: \n", counter);     
        tokenize(str);
        counter++; 
        
    }   

    fclose(file_ptr);
    
}



/**
 * @internal function
 * @brief Function to check if a given string is a keyword
*/
int isKeyword(char* word) {
    char keywords[21][20] = {"class", "constructor", "function", "method", "field", "static", "var", "int", "char", "boolean", "void", "true", "false", "null", "this", "let", "do", "if", "else", "while", "return"};
    for (int i = 0; i < 21; i++) {
        if (strcmp(keywords[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}


/**
 * @internal function
 * @brief Function to check if a given character is a symbol
*/
int isSymbol(char c) {
    char symbols[19] = {'{', '}', '[', ']', '(', ')', ',', '.', ';', '+', '-', '=', '*', '/', '&', '|', '<', '>', '~'};
    for (int i = 0; i < 19; i++) {
        if (c == symbols[i]) {
            return 1;
        }
    }
    return 0;
}


/**
 * @brief Function to tokenize a given sentence
 * 
 * 1. Get the whole length of the sentence or line of code
 * 2. Initialize the maximum number of characters a token can hold to 100. This can change in future
 * 3. Initialize the cursor position to 0
 * 4. Create a holder for the XML output string
 * 
 * 5. Create a loop to go through the entire sentence character by character
 * 
 * This is where the magic happens ( in the loop )
 * 
 * 1. Check if the character is a whitespace, if it is then move to the next element in the loop or next iteration
 * 2. Check if the character is a symbol, if yes, process the symbol by adding to symbol XML
 * 
 * 3. Check if character is a digit. To achieve this we need to do the following
 * i) Look into the future of the sentence by taking future characters and checking if they are digits, we store all the allowed digits in the token variable
 * ii) set the position of the character back to the correct position (i--) after the last correct integer character was found
 * iii) create the integer constant XML
 * 
 * 4. Check if the character is a string constant by checking if it is a quote(") character. 
 * i) advance the character (i++) and then look into the future to check if the terminating character (") has reached. 
 * ii) once the single quote character is seen, stop and build the string constant XML
 * 
 * 5. Check if the character is a Keyword or Identifier
 * i) look into the future by checking if the current character is alphanumeric or starts with underscore (_) which are allowed for identifiers or keywords
 * ii) build up the token while looking into the future and once a character that is not any of the above is seen, stop and then use the token to check the following
 * iii) check if it is a keyword by using the function that contains all the allowable keywords. if it is a keyword then build Keyword XML
 * iv) if it is not a keyword then it must be an identifier, hence build the identifier XML
 * 
*/
void tokenize(char* sentence) {
    int len = strlen(sentence);
    char token[100];
    int pos = 0;
    char * formattedXMLString;

    for (int i = 0; i < len; i++) {
        char c = sentence[i];
        if (isspace(c)) {
            // Skip whitespace
            continue;
        }
        else if (isSymbol(c)) {
            // Tokenize symbols
            printf("<symbol> %c </symbol>", c);

           
            //  Store XML output in linked list
            int formattedXMLStringLength = snprintf(NULL,0, "<symbol> %c </symbol>", c);     // Determine the length of the formatted string
            formattedXMLString = (char *) malloc(formattedXMLStringLength + 1);             // Allocate memory for the formatted string
            sprintf(formattedXMLString, "<symbol> %c </symbol>", c);                      // Format the string and store it in the allocated memory


            append(&token_list,formattedXMLString,i);                                         //  push to linked list

        }
        else if (isdigit(c)) {
            // Tokenize integer constants
            pos = 0;
            while (i < len && isdigit(sentence[i])) {
                token[pos++] = sentence[i++];                           //  look into the future 
            }
            i--;
            token[pos] = '\0';
            printf("<integerConstant> %s </integerConstant>", token);

            //  Store XML output in linked list
            int formattedXMLStringLength = snprintf(NULL,0, "<integerConstant> %s </integerConstant>", token);       // Determine the length of the formatted string
            formattedXMLString = (char *) malloc(formattedXMLStringLength + 1);                                 // Allocate memory for the formatted string
            sprintf(formattedXMLString, "<integerConstant> %s </integerConstant>", token);                                          // Format the string and store it in the allocated memory


            append(&token_list,formattedXMLString,i);                                                             //  push to linked list


        }
        else if (c == '"') {
            // Tokenize string constants
            pos = 0;
            i++;
            while (i < len && sentence[i] != '"') {
                token[pos++] = sentence[i++];
            }
            token[pos] = '\0';
            printf("<stringConstant> %s </stringConstant>", token);


            //  Store XML output in linked list
            int formattedXMLStringLength = snprintf(NULL,0,"<stringConstant> %s </stringConstant>", token);       // Determine the length of the formatted string
            formattedXMLString = (char *) malloc(formattedXMLStringLength + 1);                                 // Allocate memory for the formatted string
            sprintf(formattedXMLString,"<stringConstant> %s </stringConstant>", token);                                          // Format the string and store it in the allocated memory


            append(&token_list,formattedXMLString,i);                                                             //  push to linked list

        }
        else {
            // Tokenize keywords and identifiers
            pos = 0;
            while (i < len && isalnum(sentence[i]) || sentence[i] == '_') {
                token[pos++] = sentence[i++];
            }
            i--;
            token[pos] = '\0';
            if (isKeyword(token)) {

                printf("<keyword> %s </keyword>", token);

                //  Store XML output in linked list
                int formattedXMLStringLength = snprintf(NULL,0,"<keyword> %s </keyword>", token);                 // Determine the length of the formatted string
                formattedXMLString = (char *) malloc(formattedXMLStringLength + 1);                                 // Allocate memory for the formatted string
                sprintf(formattedXMLString,"<keyword> %s </keyword>", token);                                     // Format the string and store it in the allocated memory


                append(&token_list,formattedXMLString,i);                                                             //  push to linked list

            }
            else {

                printf("<identifier> %s </identifier>", token);

                //  Store XML output in linked list
                int formattedXMLStringLength = snprintf(NULL,0,"<identifier> %s </identifier>", token);       // Determine the length of the formatted string
                formattedXMLString = (char *) malloc(formattedXMLStringLength + 1);                                 // Allocate memory for the formatted string
                sprintf(formattedXMLString,"<identifier> %s </identifier>", token);                                          // Format the string and store it in the allocated memory


                append(&token_list,formattedXMLString,i);                                                             //  push to linked list

            }
        }
    }

}



void writeTokenizedXMLOutputToFile(char * tokenized_xml_output_filename){
    
     // remove output file if already exists
    remove(tokenized_xml_output_filename);

    FILE* file_ptr;
    file_ptr = fopen(tokenized_xml_output_filename,"w");   
    char str[MAX_FILE_SIZE];

    if (file_ptr == NULL)
    {
        printf("File not found !!! \n");
        exit(1);
    }

    if (token_list == NULL)
    {
        printf("List cannot be NULL \n");
    }

    while (token_list != NULL)
    {
        fprintf(file_ptr,"%s\n", token_list->data_str);
        token_list = token_list->next;

    }
    fclose(file_ptr);
    
}


int main (int argc, char * argv[])
{

    //  MAIN.JACK FILE

    //  1.  This function takes the input jack file, removes comments a and then reads the jack code line by line and populated token linked

    // parse_jack_input_file(NULL,MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE,MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_COMMENT_OUTPUT,MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_WHITESPACE,MAX_FILE_SIZE);

    // //  2.  Write the XML Formatted tokens to a file

    // writeTokenizedXMLOutputToFile(MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_TOKEN_XML_OUTPUT);


    //  SQUARE.JACK FILE

    //  1.  This function takes the input jack file, removes comments a and then reads the jack code line by line and populated token linked

    parse_jack_input_file(NULL,SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE,SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_COMMENT_OUTPUT,SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_WHITESPACE,MAX_FILE_SIZE);

    //  2.  Write the XML Formatted tokens to a file

    writeTokenizedXMLOutputToFile(SQUARE_JACK_FILE_EXPRESSIONLESS_SQUARE_TOKEN_XML_OUTPUT);

    return 0;
}


