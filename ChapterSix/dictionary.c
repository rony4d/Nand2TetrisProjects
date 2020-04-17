#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dictionary.h"

#define INITIAL_SIZE (1024)
#define GROWTH_FACTOR (2)
#define MAX_LOAD_FACTOR (1)
#define MULTIPLIER (97)

/* dictionary initialization code used in both DictCreate and grow */


Dictionary *internalDictCreate(int size){
    Dictionary *dictionary;
    
    dictionary = malloc(sizeof(*dictionary));

    assert(dictionary != NULL);

    dictionary->size = size;
    dictionary->n = 0;
    dictionary->table = malloc(sizeof(struct element *) * dictionary->size);

    assert(dictionary->table != NULL);

    for (int i = 0; i < dictionary->size; i++)
    {
        dictionary->table[i] = 0;
    }
    
    return dictionary;
}

Dictionary *DictCreate(void){
    return internalDictCreate(INITIAL_SIZE);
}

void DictDestroy(Dictionary *dictionary){

    struct element *element;
    struct element *next_element;

    for (int i = 0; i < dictionary->size; i++)
    {
        for (element = dictionary->table[i]; element != NULL; element = next_element)
        {
            next_element = element->next;

            free(element->key);
            free(element->value);
            free(element);
        }
        
    }
    
    free(dictionary->table);
    free(dictionary);

}

static unsigned long hash_multiplier(const char *s){

    unsigned long hash;
    unsigned const char *us;    //unsigned string

    us = (unsigned const char *)s; // cast the string to unsigned const char *, this ensures that elements of s will be treated as having values >=0
    hash = 0;

    while (*us != '\0')
    {
        hash = hash * MULTIPLIER + *us; 
        us++;
    }
    
    return hash;
}

static void grow(Dictionary *dictionary){
    Dictionary *dictionary_new;          /* new dictionary we will create */
    Dictionary temp_dictionary;          /* temporary structure for brain transplant :D */

    struct element *element;

    dictionary_new = internalDictCreate(dictionary->size * GROWTH_FACTOR);

    for (int i = 0; i < dictionary->size; i++)
    {
        for (element = dictionary->table[i]; element != NULL; element=element->next)
        {
            /* copy all the elements from the existing dictionary to the newly created dictionary */
            DictInsert(dictionary_new, element->key, element->value);
        }
        
    }
    
    /* We will swap the contents of dictionary and dictionary_new and then call DictDestroy on dictionary new */
    temp_dictionary = *dictionary;
    *dictionary = *dictionary_new;
    *dictionary_new = temp_dictionary;

    DictDestroy(dictionary_new);
}

/* insert a new key-value pair into an existing dictionary */
void DictInsert(Dictionary *dictionary, const char *key, const char *value){

    struct element *element;
    unsigned long hash;

    assert(key);
    assert(value);

    element = malloc(sizeof(*element));

    assert(element);

    element->key = strdup(key);
    element->value = strdup(value);

    hash = hash_multiplier(key) % dictionary->size; // TODO: remove the wrap around using mod and use only hash multiplier

    element->next = dictionary->table[hash];    // Assign current element to the next element
    dictionary->table[hash] = element;          // and then assign new element to the current element. This is where the chain collision is handled by the linked list :D

    dictionary->n++;

    /* grow table if there not enough room */
    if (dictionary->n >= (dictionary->size * MAX_LOAD_FACTOR))
    {
        grow(dictionary);
    }
    

}

const char * DictSearch(Dictionary *dictionary, const char *key){

    struct element *element;
    element = dictionary->table[hash_multiplier(key) % dictionary->size];

    while (element != NULL)
    {
       if (!strcmp(element->key,key))
       {
           return element->value;
       }
       
       element = element->next;
    }
    
    return 0;
}

void DictDelete(Dictionary *dictionary, const char *key){

    struct element **element_holder;            /* what to change when element is deleted */
    struct element *element;                    /* element to delete */
    
    element_holder = &dictionary->table[hash_multiplier(key) % dictionary->size];

    while (*element_holder != NULL)
    {
        if (!strcmp((*element_holder)->key,key))
        {
            /* we found it */
            element = *element_holder;
            *element_holder = element->next;

            free(element->key);
            free(element->value);
            free(element);

            return;
        }
        
    }
    

}
/**
 * dest = comp ; jump.
 * This function builds the 'comp' part
 * Compute Instruction set for controlling the ALU (comp)
*/
Dictionary *buid_compute_instruction_set_ALU(char a){

    Dictionary *c_instruction_dictionary;
    
    if (a == '0')
    {
       c_instruction_dictionary = DictCreate();
       DictInsert(c_instruction_dictionary,"0","101010");    /* */
       DictInsert(c_instruction_dictionary,"1","111111");
       DictInsert(c_instruction_dictionary,"-1","111010");
       DictInsert(c_instruction_dictionary,"D","001100");
       DictInsert(c_instruction_dictionary,"A","110000");
       DictInsert(c_instruction_dictionary,"!D","001101");
       DictInsert(c_instruction_dictionary,"!A","110001");
       DictInsert(c_instruction_dictionary,"-D","001111");
       DictInsert(c_instruction_dictionary,"-A","110011");
       DictInsert(c_instruction_dictionary,"D+1","011111");
       DictInsert(c_instruction_dictionary,"A+1","110111");
       DictInsert(c_instruction_dictionary,"D-1","001110");
       DictInsert(c_instruction_dictionary,"A-1","110010");
       DictInsert(c_instruction_dictionary,"D+A","000010");
       DictInsert(c_instruction_dictionary,"D-A","010011");
       DictInsert(c_instruction_dictionary,"A-D","000111");
       DictInsert(c_instruction_dictionary,"D&A","000000");
       DictInsert(c_instruction_dictionary,"D|A","010101");
    }
    if (a == '1')
    {
       c_instruction_dictionary = DictCreate();

       DictInsert(c_instruction_dictionary,"M","110000");
       DictInsert(c_instruction_dictionary,"!M","110001");
       DictInsert(c_instruction_dictionary,"-M","110011");
       DictInsert(c_instruction_dictionary,"M+1","110111");
       DictInsert(c_instruction_dictionary,"M-1","110010");
       DictInsert(c_instruction_dictionary,"D+M","000010");
       DictInsert(c_instruction_dictionary,"D-M","010011");
       DictInsert(c_instruction_dictionary,"M-D","000111");
       DictInsert(c_instruction_dictionary,"D&M","000000");
       DictInsert(c_instruction_dictionary,"D|M","010101");

    }
    
    return c_instruction_dictionary;
}

/**
 * dest = comp ; jump
 * This function builds the 'dest' part 
*/
Dictionary *build_compute_instruction_set_destination(){

    Dictionary *c_instruction_dictionary;

    c_instruction_dictionary = DictCreate();

    DictInsert(c_instruction_dictionary, "null","000"); // Value is not stored
    DictInsert(c_instruction_dictionary, "M","001");    // RAM[A]
    DictInsert(c_instruction_dictionary, "D","010");    // D register
    DictInsert(c_instruction_dictionary, "MD","011");   // RAM[A] adn D register
    DictInsert(c_instruction_dictionary, "A","100");    // A register
    DictInsert(c_instruction_dictionary, "AM","101");   // A register and RAM[A]
    DictInsert(c_instruction_dictionary, "AD","110");   // A register and D register
    DictInsert(c_instruction_dictionary, "AMD","111");  // A register, RAM[A] and D register

    return c_instruction_dictionary;

}

/**
 * dest = comp ; jump
 * This function builds the 'jump' part 
*/

Dictionary *build_compute_instruction_set_jump(){

    Dictionary *c_instruction_dictionary;

    c_instruction_dictionary = DictCreate();

    DictInsert(c_instruction_dictionary, "null","000");     // no jump
    DictInsert(c_instruction_dictionary, "JGT","001");      // if out > 0 jump
    DictInsert(c_instruction_dictionary, "JEQ","010");      // if out = 0 jump
    DictInsert(c_instruction_dictionary, "JGE","011");      // if out >= 0 jump
    DictInsert(c_instruction_dictionary, "JLT","100");      // if out < 0 jump
    DictInsert(c_instruction_dictionary, "JNE","101");      // if out ≠ 0 jump
    DictInsert(c_instruction_dictionary, "JLE","110");      // if out <= 0 jump
    DictInsert(c_instruction_dictionary, "JMP","111");      // Unconditional jump

    return c_instruction_dictionary;

}


Dictionary *build_a_inst_predefined_symbol_table(){

    Dictionary *a_instruction_dictionary;

    a_instruction_dictionary = DictCreate();

    DictInsert(a_instruction_dictionary, "R0","0000000000000000");     
    DictInsert(a_instruction_dictionary, "R1","0000000000000001");      
    DictInsert(a_instruction_dictionary, "R2","0000000000000010");     
    DictInsert(a_instruction_dictionary, "R3","0000000000000011");      
    DictInsert(a_instruction_dictionary, "R4","0000000000000100");      
    DictInsert(a_instruction_dictionary, "R5","0000000000000101");      
    DictInsert(a_instruction_dictionary, "R6","0000000000000110");      
    DictInsert(a_instruction_dictionary, "R7","0000000000000111");
    DictInsert(a_instruction_dictionary, "R8","0000000000001000");
    DictInsert(a_instruction_dictionary, "R9","0000000000001001");
    DictInsert(a_instruction_dictionary, "R10","0000000000001010");   
    DictInsert(a_instruction_dictionary, "R11","0000000000001011");
    DictInsert(a_instruction_dictionary, "R12","0000000000001100");
    DictInsert(a_instruction_dictionary, "R13","0000000000001101");
    DictInsert(a_instruction_dictionary, "R14","0000000000001110");
    DictInsert(a_instruction_dictionary, "R15","0000000000001111");

    DictInsert(a_instruction_dictionary, "SCREEN","0100000000000000");
    DictInsert(a_instruction_dictionary, "KBD","0110000000000000");

    DictInsert(a_instruction_dictionary, "SP","0000000000000000");
    DictInsert(a_instruction_dictionary, "LCL","0000000000000001");
    DictInsert(a_instruction_dictionary, "ARG","0000000000000010");
    DictInsert(a_instruction_dictionary, "THIS","0000000000000011");
    DictInsert(a_instruction_dictionary, "THAT","0000000000000100");

    return a_instruction_dictionary;

}

Dictionary *build_a_inst_symbol_table(){

    Dictionary *a_instruction_dictionary;

    a_instruction_dictionary = DictCreate();

    DictInsert(a_instruction_dictionary, "R0","0000000000000000");     
    DictInsert(a_instruction_dictionary, "R1","0000000000000001");      
    DictInsert(a_instruction_dictionary, "R2","0000000000000010");     
    DictInsert(a_instruction_dictionary, "R3","0000000000000011");      
    DictInsert(a_instruction_dictionary, "R4","0000000000000100");      
    DictInsert(a_instruction_dictionary, "R5","0000000000000101");      
    DictInsert(a_instruction_dictionary, "R6","0000000000000110");      
    DictInsert(a_instruction_dictionary, "R7","0000000000000111");
    DictInsert(a_instruction_dictionary, "R8","0000000000001000");
    DictInsert(a_instruction_dictionary, "R9","0000000000001001");
    DictInsert(a_instruction_dictionary, "R10","0000000000001010");   
    DictInsert(a_instruction_dictionary, "R11","0000000000001011");
    DictInsert(a_instruction_dictionary, "R12","0000000000001100");
    DictInsert(a_instruction_dictionary, "R13","0000000000001101");
    DictInsert(a_instruction_dictionary, "R14","0000000000001110");
    DictInsert(a_instruction_dictionary, "R15","0000000000001111");

    DictInsert(a_instruction_dictionary, "SCREEN","0100000000000000");
    DictInsert(a_instruction_dictionary, "KBD","0110000000000000");

    DictInsert(a_instruction_dictionary, "SP","0000000000000000");
    DictInsert(a_instruction_dictionary, "LCL","0000000000000001");
    DictInsert(a_instruction_dictionary, "ARG","0000000000000010");
    DictInsert(a_instruction_dictionary, "THIS","0000000000000011");
    DictInsert(a_instruction_dictionary, "THAT","0000000000000100");

    

    return a_instruction_dictionary;

}
// TODO: uncomment if you want to test dictionary.c in isolation
// int main(int argc, char *argv[])
// {
//     Dictionary *dictionary;
//     char buffer[512];

//     dictionary = DictCreate();

//     DictInsert(dictionary, "192.168.4.4","Luci Gateway");
//     puts(DictSearch(dictionary, "192.168.4.4"));
//     DictInsert(dictionary, "192.168.4.4","Chidelu Internet Services");
//     puts(DictSearch(dictionary, "192.168.4.4"));
//     DictDelete(dictionary,"192.168.4.4");
//     puts(DictSearch(dictionary, "192.168.4.4"));
//     DictDelete(dictionary,"192.168.4.4");
//     assert(DictSearch(dictionary,"192.168.4.4") == 0);
//     DictDelete(dictionary,"192.168.4.4");

//     for (int i = 0; i < 10000; i++)
//     {
//         sprintf(buffer,"%d",i);
//         DictInsert(dictionary,buffer,buffer);
//     }
    
//     for (int i = 0; i < 50; i++)
//     {
//         char ch[4];
//         snprintf(ch,sizeof(ch),"%d",i);
//         puts(DictSearch(dictionary, ch));
//     }


//     DictDestroy(dictionary);


//     return 0;
// }