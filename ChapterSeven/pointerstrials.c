#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//TODO: delete all MACROS below later
#define MAX_COMMANDS 64
#define SP_BASE_ADDRESS "256"
#define ASM_INSTRUCTION_LEN 64
#define SP_LABEL "SP"
#define ARRAY_MAX_LEN 4096

#define SP_BASE_ADDRESS "256"
#define ASM_INSTRUCTION_LEN 64
#define SP_LABEL "SP"
#define EQUAL_LABEL "(EQUAL"
#define NOT_EQUAL_LABEL "(NOTEQUAL"
#define END_LABEL "(END"
#define GREATER_THAN_LABEL "(GREATERTHAN"
#define NOT_GREATER_THAN_LABEL "(NOTGREATERTHAN"
#define LESS_THAN_LABEL "(LESSTHAN"
#define NOT_LESS_THAN_LABEL "(NOTLESSTHAN"

#define EQUAL_INST "@EQUAL"
#define NOT_EQUAL_INST "@NOTEQUAL"
#define END_INST "@END"
#define GREATER_THAN_INST "@GREATERTHAN"
#define NOT_GREATER_THAN_INST "@NOTGREATERTHAN"
#define LESS_THAN_INST "@LESSTHAN"
#define NOT_LESS_THAN_INST "@NOTLESSTHAN"

int counter = 0;
// HEX: 0 1 2 3 4 5 6 7 8 9 0A 0B 0C 0D 0E 0F

/**
 * @brief From my experiments and observation from the code below I can say that the array,
 * both 1D and 2D arrays are both assigned a contiguous memory location. 
 * See the pictorial view below for : int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };
 *      |   Value   |   Address     |
 *      |   16      |   0x00        |
 *      |   18      |   0x04        |
 *      |   20      |   0x08        |
 *      |   25      |   0x0C        |
 *      |   26      |   0x10        |
 *      |   27      |   0x14        |
 * 
 * I will try a 3D array and see the result
*/
void pointer_to_1_dimension_array(){

    int *array_ptr;
    int array[5] = {1,2,3,4,5};

    array_ptr = array;

    for (size_t i = 0; i < 5; i++)
    {
        printf("Value %d: Address: %p \n",array_ptr[i],(array_ptr+i));
    }
    
}

void pointer_to_2_dimension_array(){

    int array_ptr[5][2] = {{0,1}, {2,3} ,{4,5},{6,7},{8,9}};

    //To know this is correct, follow the addresses, you will see they all have a 4 byte diff and int takes 4 bytes of memory
    printf("\nValue of array[0][0] : %d Address of array[0][0]: %p \n",(**array_ptr),array_ptr);
    printf("Value of array[0][1] : %d Address of array[0][1]: %p \n",(*(*array_ptr + 1)),*array_ptr+1);
    printf("Value of array[1][0] : %d Address of array[1][0]: %p \n",(*(*array_ptr + 2)),*array_ptr+2);
    printf("Value of array[1][1] : %d Address of array[1][1]: %p \n",(*(*array_ptr + 3)),*array_ptr+3);
    printf("Value of array[2][0] : %d Address of array[2][0]: %p \n",(*(*array_ptr + 4)),*array_ptr+4);
    printf("Value of array[2][1] : %d Address of array[2][1]: %p \n",(*(*array_ptr + 5)),*array_ptr+5);
    printf("Value of array[3][0] : %d Address of array[3][0]: %p \n",(*(*array_ptr + 6)),*array_ptr+6);
    printf("Value of array[3][1] : %d Address of array[3][1]: %p \n",(*(*array_ptr + 7)),*array_ptr+7);
    printf("Value of array[4][0] : %d Address of array[4][0]: %p \n",(*(*array_ptr + 8)),*array_ptr+8);
    printf("Value of array[4][1] : %d Address of array[4][1]: %p \n",(*(*array_ptr + 9)),*array_ptr+9);
    //  The code below does not throw Array out of bound exception: Lol. It just goes to the next memory and shows a default value of an integer since it did not find anything there
    printf("Array Out of Bounds Exception: Value of array[x][x] : %d Address of array[x][x]: %p \n",(*(*array_ptr + 10)),*array_ptr+10); 

    // This example below is from Geeksforgeeks.com: I want to try my method and see if we get the same result
    int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };

    printf("\nValue of array[0][0] : %d Address of array[0][0]: %p \n",(*(*nums+0)),*nums + 0); //same as (**nums)
    printf("\nValue of array[0][1] : %d Address of array[0][1]: %p \n",(*(*nums + 1)),*nums+1);
    printf("\nValue of array[0][2] : %d Address of array[0][2]: %p \n",(*(*nums + 2)),*nums+2);
    printf("\nValue of array[1][0] : %d Address of array[1][0]: %p \n",(*(*nums + 3)),*nums+3);
    printf("\nValue of array[1][1] : %d Address of array[1][1]: %p \n",(*(*nums + 4)),*nums+4);
    printf("\nValue of array[1][2] : %d Address of array[1][2]: %p \n",(*(*nums + 5)),*nums+5);
}

typedef struct t_element{
    char* key;
    char* value;
    char* asm_commands;
} element;


void double_pointer_element_access(){

    int element_count = 5;
    element **element_holder = malloc(sizeof(element *) * element_count);
    int element_size = sizeof(element *);
    printf("Element size: %d \n", element_size);
    printf("Element Holder size: %lu \n", sizeof(element_holder));
    /**
     *  Initialize elements in holder to zero and print out addresses since double pointer is an array
        the array should look like this 2D array below: 
        element_holder = ( {element_0, element_1, element_2, element_3, element_4} }

        NOTE: To confirm my theory, if we inspect the address for each element 
        they should be spaced out by element_size since the memory is contiguously allocated.
        
        OBSERVATION: My theory failed, I have observed that double pointers initialized like
        element_holder behave differently when compared to using double pointers to access arrays 
        as seen in pointer_to_2_dimension_array() function above.

        When you initialize double pointers like element_holder, it looks like a 1D array:
        element_holder = {element_0, element_1, element_2, element_3, element_4}

        This enables you access the elements like this:
        First element = element_holder[0]
        Second element = element_holder[1]

        I also observed that the memory space(offset) between the elements is not the sizeof(element *)
        because when I printed sizeof(element*) I got 8 bytes but checking the address spacing(offset)
        between elements I observed 20 bytes space.
        IMPLEMENTATION: See the implementation below.
    */

    //Initialize first element of element_holder
    element *element_0 = malloc(sizeof(element *));
    element_holder[0] = element_0;
    element_holder[0]->key = strdup("KEY-0");
    printf("Element-0 size: %lu \n", sizeof(element_holder[0]));
    element *element_1 = malloc(sizeof(element *));
    element_holder[1] = element_1;
    element_holder[1]->key = strdup("KEY-1");
    element *element_2 = malloc(sizeof(element *));
    element_holder[2] = element_2;
    element_holder[2]->key = strdup("KEY-2");
    assert(element_holder != NULL);
    printf("\nValue of element_holder[0] key : %s Address of element_holder[0]: %p \n",(element_holder[0]->key),element_holder[0]);
    printf("\nValue of element_holder[1] key : %s Address of element_holder[1]: %p \n",(element_holder[1]->key),element_holder[1]);
    printf("\nValue of element_holder[2] key : %s Address of element_holder[1]: %p \n",(element_holder[2]->key),element_holder[2]);

    //The code below should simulate an invalid element, hence trying to access the key for element_holder[1000]->key
    //will give you segmentation fault and the address is a NULL address (0x0). Run the code to see, you can replace "Segmentation Fault Key" with element_holder[1000]->key
    //so you can see the error
    printf("\nArray Out of Bounds Exception: Value of element_holder[x][x] key : %s Address of element_holder[0][1]: %p \n","Segmentation Fault Key",element_holder[1000]);

}

void double_pointer_char_as_string_array(){


    char ** string_array = malloc(sizeof(char *) * MAX_COMMANDS);

    string_array[0] = "@256";
    string_array[1] = "D=A";
    string_array[2] = "@SP";
    string_array[3] = "This is a longer string, memory offset should be higher";

    printf("\nValue of string_array[0]: %s Address of string_array[0]: %p \n",(string_array[0]),string_array[0]);
    printf("\nValue of string_array[1]: %s Address of string_array[1]: %p \n",(string_array[1]),string_array[1]);
    printf("\nValue of string_array[2]: %s Address of string_array[2]: %p \n",(string_array[2]),string_array[2]);
    printf("\nValue of string_array[3]: %s Address of string_array[3]: %p \n",(string_array[3]),string_array[3]);
    // The code below will just show null so when printing we can check for null
    printf("\nValue of string_array[4]: %s Address of string_array[4]: %p \n",(string_array[4]),string_array[4]);

    char **second_string_array = string_array;
    printf("\nValue of second_string_array[0]: %s Address of second_string_array[0]: %p \n",(second_string_array[0]),second_string_array[0]);


}

//TODO: delete 
void build_stack_pointer_initialization_command(char ** hack_asm_array){

    /*
    @256
    D=A
    @SP
    M=D
    */
    char sp_address[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    // Concat @ and variable
    char *at_symbol = strdup("@");
    strncat(sp_address,at_symbol,strlen(at_symbol));            //@
    strncat(sp_address,SP_BASE_ADDRESS,strlen(SP_BASE_ADDRESS));//@256
    
    hack_asm_array[counter] = strdup(sp_address);
    counter++;
    
    hack_asm_array[counter] = strdup("D=A");
    counter++;

    strncat(sp_instruction,at_symbol,strlen(at_symbol));        //@
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));          //@SP
    hack_asm_array[counter] = strdup(sp_instruction);
    counter++;

    hack_asm_array[counter] = strdup("M=D");
    counter++;
}

/** TODO: delete
 * @brief: The function generates pushing a constant command e.g [push constant 4]
 * @params: const_value: the constant value we want to push
 *          hack_asm_init_array: the stack pointer initialization commands
*/
void build_push_constant_command(const char *const_value, char **hack_asm_init_array){

    /*
    @7
    D=A
    @SP
    A=M
    M=D
    @SP
    M=M+1   //SP move ++ (Stack pointer moves one space forward after every push)
    */

    char constant_instruction[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));                //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP
    
    strncat(constant_instruction,at_symbol,strlen(at_symbol));              //@
    strncat(constant_instruction,const_value,strlen(const_value));          //@const_value

    // To append the commands to the array, we need to use a while loop
    int counter = 0;

    // Get the last element count in the array 
    while (hack_asm_init_array[counter] != NULL)
    {
        counter++;
    }

    // From the value in counter, start inserting the 7 push commands
    hack_asm_init_array[counter] = strdup(constant_instruction); 
    counter++;
    hack_asm_init_array[counter] = strdup("D=A");
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");
    counter++;
    hack_asm_init_array[counter] = strdup("M=D");
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");

}

/**
 * TODO: delete
 * @brief This function builds the add command that adds the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_add_command(char **hack_asm_init_array){

    /*
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[257]
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- (Stack pointer moves one space backward the second time) We decrease RAM[0] value by 1 to give us 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=M+D

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // To append the commands to the array, we need to use a while loop
    int counter = 0;

    // Get the last element count in the array 
    while (hack_asm_init_array[counter] != NULL)
    {
        counter++;
    }

    // From the value in counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+D");                 //M=M+D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
}

/**
 * TODO: delete
*/
void sentence_splitter(char *sentence, char **word_split_array){
    // Extract the first token
    char *token = strtok(sentence," ");

    // loop through the string to extract all other tokens
    int line_counter = 0;
    while (token != NULL)
    {
        word_split_array[line_counter] = strdup(token);
        token = strtok(NULL, " ");
        line_counter++;
    }
    

}

//TODO: delete
void print_double_pointer_array(char ** double_pointer_array){
    int line_counter = 0;
    while (double_pointer_array[line_counter] != NULL)
    {
        printf("%s \n",double_pointer_array[line_counter]);
        line_counter++;
    }
}

/**
 * TODO: delete
 * @brief This function builds the equal command that checks if the content of the two previous
 * registers are equal
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_equal_command(char **hack_asm_init_array){

    /*
    // eq
    //To check if equal we have to pop i.e (SP at RAM[257] - SP at RAM[256] == 0)
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M     // We are at RAM[257]
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M     // We are at RAM[256]
    M=M-D   // RAM[256] - RAM[257]  
    D=M     // Assign result to D-register so we can check equality to zero finally

    @EQUAL
    D;JEQ

    @NOTEQUAL
    0;JMP

    (EQUAL) // If two operands are equal then value of SP is -1 else value is 0
        @SP
        A=M
        M=-1
        @END
        0;JMP
        
    (NOTEQUAL)
        @SP
        A=M
        M=0
        @END
        0;JMP

    (END)
        @SP
        M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char counter_str[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char equal_instruction[ASM_INSTRUCTION_LEN] = {0};
    char not_equal_instruction[ASM_INSTRUCTION_LEN] = {0};
    char end_instruction[ASM_INSTRUCTION_LEN] = {0};
    char equal_label[ASM_INSTRUCTION_LEN] = {0};
    char not_equal_label[ASM_INSTRUCTION_LEN] = {0};
    char end_label[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // build @EQUAL1 instruction
    strncat(equal_instruction,EQUAL_INST,strlen(EQUAL_INST));       //@EQUAL
    snprintf(counter_str,ASM_INSTRUCTION_LEN,"%d",counter);         //converts int to string
    strncat(equal_instruction,counter_str,strlen(counter_str));     //@EQUALi -> appends counter to @EQUAL instruction to make it unique for every call of this function.

    // build @NOTEQUAL1 instruction
    strncat(not_equal_instruction,NOT_EQUAL_INST,strlen(NOT_EQUAL_INST));       //@NOTEQUAL
    strncat(not_equal_instruction,counter_str,strlen(counter_str));             //@NOTEQUALi -> appends counter to @NOTEQUAL instruction to make it unique for every call of this function.

    // build @END1 instruction
    strncat(end_instruction,END_INST,strlen(END_INST));                         //@END
    strncat(end_instruction,counter_str,strlen(counter_str));             //@ENDi -> appends counter to @END instruction to make it unique for every call of this function.

    // build (EQUALi) label
    strncat(equal_label,EQUAL_LABEL,strlen(EQUAL_LABEL));                   //(EQUAL
    strncat(equal_label,counter_str,strlen(counter_str));                   //(EQUALi
    strncat(equal_label,")",strlen(")"));                                   //(EQUALi)
    
    // build (NOTEQUALi) label
    strncat(not_equal_label,EQUAL_LABEL,strlen(EQUAL_LABEL));                   //(NOTEQUAL
    strncat(not_equal_label,counter_str,strlen(counter_str));                   //(NOTEQUALi
    strncat(not_equal_label,")",strlen(")"));                                   //(NOTEQUALi)

    // build (ENDi) label
    strncat(end_label,END_LABEL,strlen(END_LABEL));                         //(END
    strncat(end_label,counter_str,strlen(counter_str));                     //(ENDi
    strncat(end_label,")",strlen(")"));                                     //(ENDi)

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(equal_instruction);       //@EQUALi
    counter++;
    hack_asm_init_array[counter] = strdup("D;JEQ");                 //D;JEQ
    counter++;
    hack_asm_init_array[counter] = strdup(not_equal_instruction);   //@NOTEQUALi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                 //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(equal_label);             //(EQUALi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);           //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                    //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-1");                   //M=-1 [true] 
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);          //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                  //0;JMP
    counter++;

    hack_asm_init_array[counter] = strdup(not_equal_label);          //(NOTEQUALi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);           //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                    //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=0");                    //M=0   [false]
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);          //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                  //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(end_label);               //(ENDi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);           //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * TODO: delete
 * @brief This function builds the greater_than command that checks content of previous register is 
 * greater than content of the current register
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_greater_than_command(char **hack_asm_init_array){

    /*
    // greater than
    //To check if less we have to pop i.e (SP at RAM[256] - SP at RAM[257] > 0)
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M     // We are at RAM[257]
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M     // We are at RAM[256]
    M=M-D   // RAM[256] - RAM[257]  
    D=M     // Assign result to D-register so we can check greater than to zero 

    @GREATERTHAN
    D;JGT

    @NOTGREATERTHAN
    0;JMP

    (GREATERTHAN) // If RAM[256] < RAM[257] then run the code below which sets SP or RAM[256] to true or -1
        @SP
        A=M
        M=-1
        @END
        0;JMP
        
    (NOTGREATERTHAN) // If RAM[256] is not less than RAM[257] then run the code below which sets SP or RAM[256] to false or 0
        @SP
        A=M
        M=0
        @END
        0;JMP

    (END)
        @SP
        M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char counter_str[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char greather_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char not_greater_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char end_instruction[ASM_INSTRUCTION_LEN] = {0};
    char greater_than_label[ASM_INSTRUCTION_LEN] = {0};
    char not_greater_than_label[ASM_INSTRUCTION_LEN] = {0};
    char end_label[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // build @GREATERTHANi instruction
    strncat(greather_than_instruction,GREATER_THAN_INST,strlen(GREATER_THAN_INST));         //@GREATERTHAN
    snprintf(counter_str,ASM_INSTRUCTION_LEN,"%d",counter);                                 //converts int to string
    strncat(greather_than_instruction,counter_str,strlen(counter_str));                     //@GREATERTHANi -> appends counter to @EQUAL instruction to make it unique for every call of this function.

    // build @NOTGREATERTHANi instruction
    strncat(not_greater_than_instruction,NOT_GREATER_THAN_INST,strlen(NOT_GREATER_THAN_INST));          //@NOTGREATERTHAN
    strncat(not_greater_than_instruction,counter_str,strlen(counter_str));                              //@NOTGREATERTHANi -> appends counter to @NOTEQUAL instruction to make it unique for every call of this function.

    // build @ENDi instruction
    strncat(end_instruction,END_INST,strlen(END_INST));                         //@END
    strncat(end_instruction,counter_str,strlen(counter_str));                   //@ENDi -> appends counter to @END instruction to make it unique for every call of this function.

    // build (GREATERTHANi) label
    strncat(greater_than_label,GREATER_THAN_LABEL,strlen(GREATER_THAN_LABEL));  //(GREATERTHAN
    strncat(greater_than_label,counter_str,strlen(counter_str));                //(GREATERTHANi
    strncat(greater_than_label,")",strlen(")"));                                //(GREATERTHANi)
    
    // build (NOTGREATERTHANi) label
    strncat(not_greater_than_label,NOT_GREATER_THAN_LABEL,strlen(NOT_GREATER_THAN_LABEL));                  //(NOTGREATERTHAN
    strncat(not_greater_than_label,counter_str,strlen(counter_str));                                               //(NOTGREATERTHANi
    strncat(not_greater_than_label,")",strlen(")"));                                                               //(NOTGREATERTHANi)

    // build (ENDi) label
    strncat(end_label,END_LABEL,strlen(END_LABEL));                         //(END
    strncat(end_label,counter_str,strlen(counter_str));                     //(ENDi
    strncat(end_label,")",strlen(")"));                                     //(ENDi)



    // From the value in global counter, start inserting the asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(greather_than_instruction);       //@GREATERTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("D;JGT");                         //D;JGT
    counter++;
    hack_asm_init_array[counter] = strdup(not_greater_than_instruction);    //@NOTREATERTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(greater_than_label);              //(GREATERTHANi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                    //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-1");                   //M=-1 [true] 
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);          //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                  //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(not_greater_than_instruction);    //(NOTGREATERTHANi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                           //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=0");                           //M=0   [false]
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);                 //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(end_label);                       //(ENDi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                          //M=M+1
    counter++;
}

/**
 * TODO: delete
 * @brief This function builds the less_than command that checks content of previous register is 
 * less than content of the current register
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_less_than_command(char **hack_asm_init_array){

    /*
    // less than
    //To check if less we have to pop i.e (SP at RAM[256] - SP at RAM[257] < 0)
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M     // We are at RAM[257]
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M     // We are at RAM[256]
    M=M-D   // RAM[256] - RAM[257]  
    D=M     // Assign result to D-register so we can check less than to zero 

    @LESSTHAN
    D;JLT

    @NOTLESSTHAN
    0;JMP

    (LESSTHAN) // If RAM[256] < RAM[257] then run the code below which sets SP or RAM[256] to true or -1
        @SP
        A=M
        M=-1
        @END
        0;JMP
        
    (NOTLESSTHAN) // If RAM[256] is not less than RAM[257] then run the code below which sets SP or RAM[256] to false or 0
        @SP
        A=M
        M=0
        @END
        0;JMP

    (END)
        @SP
        M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char counter_str[ASM_INSTRUCTION_LEN] = {0};
    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char less_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char not_less_than_instruction[ASM_INSTRUCTION_LEN] = {0};
    char end_instruction[ASM_INSTRUCTION_LEN] = {0};
    char less_than_label[ASM_INSTRUCTION_LEN] = {0};
    char not_less_than_label[ASM_INSTRUCTION_LEN] = {0};
    char end_label[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";

    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // build @LESSTHANi instruction
    strncat(less_than_instruction,LESS_THAN_INST,strlen(LESS_THAN_INST));                   //@LESSTHAN
    snprintf(counter_str,ASM_INSTRUCTION_LEN,"%d",counter);                                 //converts int to string
    strncat(less_than_instruction,counter_str,strlen(counter_str));                         //@LESSTHANi -> appends counter to @LESS instruction to make it unique for every call of this function.

    // build @NOTLESSTHANi instruction
    strncat(not_less_than_instruction,NOT_LESS_THAN_INST,strlen(NOT_LESS_THAN_INST));       //@NOTLESSTHAN
    strncat(not_less_than_instruction,counter_str,strlen(counter_str));                     //@NOTLESSTHANi -> appends counter to @NOTLESSTHAN instruction to make it unique for every call of this function.

    // build @ENDi instruction
    strncat(end_instruction,END_INST,strlen(END_INST));                         //@END
    strncat(end_instruction,counter_str,strlen(counter_str));                   //@ENDi -> appends counter to @END instruction to make it unique for every call of this function.

    // build (LESSTHANi) label
    strncat(less_than_label,LESS_THAN_LABEL,strlen(LESS_THAN_LABEL));           //(LESSTHAN
    strncat(less_than_label,counter_str,strlen(counter_str));                   //(LESSTHANi
    strncat(less_than_label,")",strlen(")"));                                   //(LESSTHANi)
    
    // build (NOTLESSTHANi) label
    strncat(not_less_than_label,NOT_LESS_THAN_LABEL,strlen(NOT_LESS_THAN_LABEL));                   //(NOTLESSTHAN
    strncat(not_less_than_label,counter_str,strlen(counter_str));                                //(NOTLESSTHANi
    strncat(not_less_than_label,")",strlen(")"));                                                //(NOTLESSTHANi)

    // build (ENDi) label
    strncat(end_label,END_LABEL,strlen(END_LABEL));                         //(END
    strncat(end_label,counter_str,strlen(counter_str));                     //(ENDi
    strncat(end_label,")",strlen(")"));                                     //(ENDi)



    // From the value in global counter, start inserting the asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(less_than_instruction);           //@LESSTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("D;JLT");                         //D;JLT
    counter++;
    hack_asm_init_array[counter] = strdup(not_less_than_instruction);       //@NOTLESSTHANi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(less_than_label);                 //(LESSTHANi)
    counter++;  
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                           //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-1");                          //M=-1 [true] 
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);                 //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(not_less_than_label);             //(NOTLESSTHANi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                           //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=0");                           //M=0   [false]
    counter++;
    hack_asm_init_array[counter] = strdup(end_instruction);                 //@ENDi
    counter++;
    hack_asm_init_array[counter] = strdup("0;JMP");                         //0;JMP
    counter++;
    hack_asm_init_array[counter] = strdup(end_label);                       //(ENDi)
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);                  //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                          //M=M+1
    counter++;
}

/**
 * TODO: delete
 * @brief This function builds the neg command that performs negation on the value of the previous register
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_neg_command(char **hack_asm_init_array){

    /*
    // neg
    //To negate we move a step back and -M or -D i.e (- SP at RAM[256])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 256
    A=M     // We are at RAM[256]
    M=-M    // negate M and assign value to M

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=-M");                  //M=-M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}


/**
 * TODO: delete
 * @brief This function builds the not command that performs NOT on the value of the previous register.
 * NOT is bitwise flip of every bit in a number (!value)
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_not_command(char **hack_asm_init_array){

    /*
    // not
    //To not we move a step back and !M or !A or !D i.e (!SP at RAM[256])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 256
    A=M     // We are at RAM[256]
    M=!M    // not M and assign value to M

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=!M");                  //M=!M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}


/**
 * @brief This function builds the or command that performs bitwise OR on the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_or_command(char **hack_asm_init_array){

    /*
    // or
    //To OR we have to pop i.e (SP at RAM[256] | SP at RAM[257])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- we are at RAM[0] value 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=D|M   // OR happens here

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M|D");                 //M=M|D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}


/**
 * @brief This function builds the and command that performs bitwise AND on the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_and_command(char **hack_asm_init_array){

    /*
    // and
    //To AND we have to pop i.e (SP at RAM[256] & SP at RAM[257])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- we are at RAM[0] value 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=D&M   // AND happens here

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M&D");                 //M=M&D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

/**
 * @brief This function builds the sub command that subtracts the content
 * of the two previous registers
 * @params: hack_asm_init_array: This is the hack asm array returned from previous functions
*/
void build_sub_command(char **hack_asm_init_array){

    /*
    // sub
    //To Sub we have to pop i.e (SP at RAM[256] - SP at RAM[257])
    @SP
    M=M-1   //SP move-- (Stack pointer moves one space backward the first time)

    @SP     // We are at RAM[0] with value 257
    A=M
    D=M     // Assign value to D-register

    @SP     // We are at RAM[0] with value 257
    M=M-1   // SP move-- we are at RAM[0] value 256 so we can jump to RAM[256] and add the value to what we stored in the D-register
    A=M
    M=M-D   // Subtraction happens here

    @SP
    M=M+1   // SP move ++ (Stack pointer moves one space forward to await next instruction). So we are back to RAM[0] with value 257
    */

    char sp_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *at_symbol = "@";
    
    strncat(sp_instruction,at_symbol,strlen(at_symbol));            //@      
    strncat(sp_instruction,SP_LABEL,strlen(SP_LABEL));              //@SP

    // From the value in global counter, start inserting the 11 add asm commands
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("D=M");                   //D=M
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-1");                 //M=M-1
    counter++;
    hack_asm_init_array[counter] = strdup("A=M");                   //A=M
    counter++;
    hack_asm_init_array[counter] = strdup("M=M-D");                 //M=M-D
    counter++;
    hack_asm_init_array[counter] = strdup(sp_instruction);          //@SP
    counter++;
    hack_asm_init_array[counter] = strdup("M=M+1");                 //M=M+1
    counter++;
}

void build_label_command(char **hack_asm_init_array, char *label){
    
    char label_instruction[ASM_INSTRUCTION_LEN] = {0};
    char *open_bracket_symbol = "(";
    char *close_bracket_symbol = ")";
    
    strncat(label_instruction,open_bracket_symbol,strlen(open_bracket_symbol));     //(
    
    // label = strip_whitespace(label);                                                //remove new line that comes from word split
    strncat(label_instruction,label,strlen(label));                                 //(label
    strncat(label_instruction,close_bracket_symbol,strlen(close_bracket_symbol));   //(label)

    // From the value in counter, start inserting the push local asm commands

    hack_asm_init_array[counter] = strdup(label_instruction);       //()  
    counter++;
}

int main(int argc, char * argv[]){

    //Split word

    char word[64] = "Hello    ";
    char **word_split_array = malloc(sizeof(char *) * ARRAY_MAX_LEN);
    sentence_splitter(word,word_split_array);
    printf("%lu \n",strlen(word_split_array[0]));
    print_double_pointer_array(word_split_array);


    //Testing some vm translator functions
    char **hack_asm_array = malloc(sizeof(char *) * ARRAY_MAX_LEN);

    // build_stack_pointer_initialization_command(hack_asm_array);
    build_label_command(hack_asm_array,"LOOP_START");
    print_double_pointer_array(hack_asm_array);

    //build_equal_command(hack_asm_array);
    //build_greater_than_command(hack_asm_array);
    //build_less_than_command(hack_asm_array);
    //build_neg_command(hack_asm_array);
    //build_not_command(hack_asm_array);
    //build_or_command(hack_asm_array);
    //build_and_command(hack_asm_array);

    // build_push_constant_command("7",hack_asm_array);
    // build_push_constant_command("8",hack_asm_array);
    // build_add_command(hack_asm_array);
    // build_sub_command(hack_asm_array);
    //print_double_pointer_array(hack_asm_array);
    
    //double_pointer_char_as_string_array();
    // pointer_to_1_dimension_array();
    // pointer_to_2_dimension_array();
    // double_pointer_element_access();
    return 0;
}

