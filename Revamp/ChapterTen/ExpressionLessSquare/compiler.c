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
  *         -   1)  Create a data structure to hold the lexical elements : The Jack Language includes 5 categories of terminal (lexical) elements or tokens ( See Slide 85 of Chapter 10 Lecture Note)
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
  *                     { int data; 
  *                       struct token_node * next;
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
 */


#include "../ChapterSix/assembler/dictionary.c"
#include "../ChapterSix/assembler/util.c"