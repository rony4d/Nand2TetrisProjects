#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "dictionary_arr.h"

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
            free(element->array_value);
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

static void growArray(Dictionary *dictionary){
    Dictionary *dictionary_new;          /* new dictionary we will create */
    Dictionary temp_dictionary;          /* temporary structure for brain transplant :D */

    struct element *element;

    dictionary_new = internalDictCreate(dictionary->size * GROWTH_FACTOR);

    for (int i = 0; i < dictionary->size; i++)
    {
        for (element = dictionary->table[i]; element != NULL; element=element->next)
        {
            /* copy all the elements from the existing dictionary to the newly created dictionary */
            DictInsertArray(dictionary_new, element->key, element->value,element->array_value);
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

/* insert a new key-value pair into an existing dictionary */
void DictInsertArray(Dictionary *dictionary, const char *key, const char *value, const char **array_value){

    struct element *element;
    unsigned long hash;

    assert(key);
    assert(value);

    element = malloc(sizeof(*element));

    assert(element);

    element->key = strdup(key);
    element->value = value;
    element->array_value = array_value;

    hash = hash_multiplier(key) % dictionary->size; // TODO: remove the wrap around using mod and use only hash multiplier

    element->next = dictionary->table[hash];    // Assign current element to the next element
    dictionary->table[hash] = element;          // and then assign new element to the current element. This is where the chain collision is handled by the linked list :D

    dictionary->n++;

    /* grow table if there not enough room */
    if (dictionary->n >= (dictionary->size * MAX_LOAD_FACTOR))
    {
        growArray(dictionary);
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
 * @brief:  Creates a stack function -> memory segment -> hack assembly instructions
 *          mapper
*/
Dictionary *stack_func_memory_segment_hack_assembly_mapper(char *stack_function, char *memory_segment, char **hack_assembly_instructions){

    Dictionary *dictionary;
    
    dictionary = DictCreate();
    
    /** map stack push command to memory segment to hack assembly instructions
     * key: Stack_function: eg push
     * value: Memory segment
     * value_array: Hack assembly instructions
     */
    DictInsertArray(dictionary,stack_function,memory_segment,hack_assembly_instructions);
    
    
    return dictionary;
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