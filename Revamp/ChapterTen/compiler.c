#include "../ChapterSix/assembler/dictionary.c"
#include "../ChapterSix/assembler/util.c" 
 
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
  *         -   2)  Create a tokenizer that will breakdown the input code character by character and compare with the lexical elements stores. The output of this tokenizer will be a dictionary that contains all the tokens . 
  *                 The key will be the token category and the value will be the token itself. NOTE that we need to track the order in which these tokens are stored with a counter variable that continually increases.
  *                 We will use this counter variable to build the XML output of the tokens. 
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
  *         -   
  * 
  *         NOTES:
  *         -   A token is a string of characters that has meaning. This means that we need to breakdown the input code character by character and constantly check if any single or character group matches any member of the token categories
  *             based on the Jack Grammar Lexical elements section
  * 
  * 
  *         -   The data storage that will hold the tokenized output will be populated the following way
  * 
  *             1)  Create a token_counter variable that only increments on every successful detection of a valid token
  *             2)  This token_counter variable will be used to build a linked list that holds the value of the token_counter variable in sequential order. For example we will create a linked_list as seen below
  *                     
  *                     typedef struct token_node 
  *                     { 
  *                         int data; 
  *                         struct token_node * next;
  *                     }
  * 
  *                 The data in this linked list will be the value of the token_counter. We are using a linked_list because we need to maintain order of access from first to last
  * 
  *             3)  Create a dictionary by token-category (or lexicl element category) to store the detected valid tokens. Eg. Keyword_dictionary, Symbol_dictionary etc
  * 
  *             4)  Each token_counter variable will also be used as key based on the token-category (or lexicl element category) for which the detected token matches and the detected token will be used as value in the dictionary
  *                 For example: If we detect 'if' at token_counter value of '10'. It means we will store '10' as key in the Keyword_dictionary and then 'if' will be the value. Also
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




Dict keyword_token_category_dictionary;                     //  this dictionary holds the keyword category of the tokens
Dict symbol_token_category_dictionary;                      //  this dictionary holds the symbol category of the tokens







//  Token Category: Keyword  . Contains 21 Keywords

#define CLASS "class"
#define CONSTRUCTOR "constructor"
#define FUNCTION "function"
#define METHOD "method"
#define FIELD "field"
#define STATIC "static"
#define VAR "var"
#define INT "int"
#define CHAR "char"
#define BOOLEAN "boolean"
#define VOID "void"
#define TRUE "true"
#define FALSE "false"
#define NULL_POINTER "null"
#define THIS "this"
#define LET "let"
#define DO "do"
#define IF "if"
#define ELSE "else"
#define WHILE "while"
#define RETURN "return"


//  Token Category: Symbol  . Contains 19 Symbols
#define LEFT_CURLY_BRACKET "{"
#define RIGHT_CURLY_BRACKET "}"
#define LEFT_BRACKET "("
#define RIGHT_BRACKET ")"
#define LEFT_ANGLE_BRACKET "["
#define RIGHT_ANGLE_BRACKET "]"
#define FULLSTOP "."
#define COMMA ","
#define SEMICOLON ";"
#define PLUS "+"
#define MINUS "-"
#define ASTERISK "*"
#define FORWARD_SLASH "/"
#define AMPERSAND "&"
#define PIPE "|"
#define LESSTHAN "<"
#define GREATERTHAN ">"
#define EQUAL "="
#define TILDE "~"

//  Token Category: Integer Constant

#define INTEGER_CONSTANT_LOWER_LIMIT 0
#define INTEGER_CONSTANT_UPPER_LIMIT 32767



/**
 * @brief: Tokenizer Module : This module contains functions that read the jack files and generates the token symbols
 * @param parse_input_jack_file: This function takes the input jack file, removes comments a and then reads the jack code line by line
 * @param parse_vm_command: This function parses the vm command into its component parts and then allows the code generator to do its magic
 *
*/


void parse_input_file(char * filename, char * input_jack_file, char * no_comment_output_jack_file,char * no_whitespace_output_jack_file, int max_file_zie);




void parse_input_jack_file(char * filename, char * input_jack_file, char * no_comment_output_jack_file,char * no_whitespace_output_jack_file, int max_file_zie)
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
        // parse_vm_command(str,filename);  
        printf("Line %d: \n", counter);     

        counter++; 
        
    }   

    fclose(file_ptr);
    
}

/**
 * @internal function
 * @brief : Creates data storage to hold the token categories Keyword, symbol, integer constant, string constant and identifier
*/

void  _initialize_token_categories() {

    keyword_token_category_dictionary = DictCreate();

    DictInsert(keyword_token_category_dictionary,CLASS,CLASS);
    DictInsert(keyword_token_category_dictionary,CONSTRUCTOR,CONSTRUCTOR);
    DictInsert(keyword_token_category_dictionary,FUNCTION,FUNCTION);
    DictInsert(keyword_token_category_dictionary,METHOD,METHOD);
    DictInsert(keyword_token_category_dictionary,FIELD,FIELD);
    DictInsert(keyword_token_category_dictionary,STATIC,STATIC);
    DictInsert(keyword_token_category_dictionary,VAR,VAR);
    DictInsert(keyword_token_category_dictionary,INT,INT);
    DictInsert(keyword_token_category_dictionary,CHAR,CHAR);
    DictInsert(keyword_token_category_dictionary,BOOLEAN,BOOLEAN);
    DictInsert(keyword_token_category_dictionary,VOID,VOID);
    DictInsert(keyword_token_category_dictionary,TRUE,TRUE);
    DictInsert(keyword_token_category_dictionary,FALSE,FALSE);
    DictInsert(keyword_token_category_dictionary,NULL_POINTER,NULL_POINTER);
    DictInsert(keyword_token_category_dictionary,THIS,THIS);
    DictInsert(keyword_token_category_dictionary,LET,LET);
    DictInsert(keyword_token_category_dictionary,DO,DO);
    DictInsert(keyword_token_category_dictionary,IF,IF);
    DictInsert(keyword_token_category_dictionary,ELSE,ELSE);
    DictInsert(keyword_token_category_dictionary,WHILE,WHILE);
    DictInsert(keyword_token_category_dictionary,RETURN,RETURN);


    symbol_token_category_dictionary = DictCreate();
    DictInsert(symbol_token_category_dictionary,LEFT_CURLY_BRACKET,LEFT_CURLY_BRACKET);
    DictInsert(symbol_token_category_dictionary,RIGHT_CURLY_BRACKET,RIGHT_CURLY_BRACKET);
    DictInsert(symbol_token_category_dictionary,LEFT_BRACKET,LEFT_BRACKET);
    DictInsert(symbol_token_category_dictionary,RIGHT_BRACKET,RIGHT_BRACKET);
    DictInsert(symbol_token_category_dictionary,LEFT_ANGLE_BRACKET,LEFT_ANGLE_BRACKET);
    DictInsert(symbol_token_category_dictionary,RIGHT_ANGLE_BRACKET,RIGHT_ANGLE_BRACKET);
    DictInsert(symbol_token_category_dictionary,FULLSTOP,FULLSTOP);
    DictInsert(symbol_token_category_dictionary,COMMA,COMMA);
    DictInsert(symbol_token_category_dictionary,SEMICOLON,SEMICOLON);
    DictInsert(symbol_token_category_dictionary,PLUS,PLUS);
    DictInsert(symbol_token_category_dictionary,MINUS,MINUS);
    DictInsert(symbol_token_category_dictionary,ASTERISK,ASTERISK);
    DictInsert(symbol_token_category_dictionary,FORWARD_SLASH,FORWARD_SLASH);
    DictInsert(symbol_token_category_dictionary,AMPERSAND,AMPERSAND);
    DictInsert(symbol_token_category_dictionary,PIPE,PIPE);
    DictInsert(symbol_token_category_dictionary,LESSTHAN,LESSTHAN);
    DictInsert(symbol_token_category_dictionary,GREATERTHAN,GREATERTHAN);
    DictInsert(symbol_token_category_dictionary,EQUAL,EQUAL);
    DictInsert(symbol_token_category_dictionary,TILDE,TILDE);
}


int main (int argc, char * argv[])
{


    _initialize_token_categories();

    //  Expressionless Square (Main.jack)

    parse_input_jack_file(NULL,MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE,MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_COMMENT_OUTPUT,MAIN_JACK_FILE_EXPRESSIONLESS_SQUARE_NO_WHITESPACE,MAX_FILE_SIZE);



    return 0;
}


