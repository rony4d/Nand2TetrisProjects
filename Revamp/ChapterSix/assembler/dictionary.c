/*
    Dictionary.c is an implementation of the dictionary data structure in c

    This dictionary is implemented using Chaining as a collision resolution method. Other method that can be used is Open addressing

    Reference:  https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
                -   [6.2] A string to string dictionary using chaining

    ToDo: Stress test this dictionary to know its limits 
*/


#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dictionary.h"
#include <stdio.h>

/**
 * @brief:  The element struct is a linked list . The element struct describes the nodes in the linked.
 * @param next: This points to the next node on the list
 * @param key: This is the unique key used to identify each element or node
 * @param value: This is the value associated with each element or node
*/
struct element{     
    char * key;
    char * value;
    struct element * next;     

};

/**
 * @brief:  The dict struct is the dictionary that contains the elements. 
 * @param table: The table is a double pointer of elements and this was done as it will allow the dictionary access each element in the table with a key just like an array. See example: /Users/ugochukwu/Desktop/c/C_Revamp/GeeksForGeeks/LinkedList.c
 * @param n: number of elements stored in the table
 * @param size: size of the pointer table
 * NOTE: This dictionary contains a table of elements and each element is a linked list. The linked list is used based on the chaining collision resolution method. 
 *          
*/
struct dict{
    int size;           
    int n;              
    struct element ** table;   
};


#define INITIAL_SIZE (1024)
#define GROWTH_FACTOR (2)
#define MAX_LOAD_FACTOR (1)

/*  dictionary initialization code used in both Dictcreate and grow */

Dict internalDictCreate(int size)
{
    Dict dictionary;
    int i;

    dictionary = malloc(sizeof(*dictionary));

    assert (dictionary != 0);

    dictionary->size = size;
    dictionary->n = 0;
    dictionary->table = malloc(sizeof(struct element *) * dictionary->size);

    assert(dictionary->table != 0);

    for (i = 0; i < dictionary->size; i++)
    {
        dictionary->table[i] = 0;
    }
    
    return dictionary;
}

Dict DictCreate(void)
{
    return internalDictCreate(INITIAL_SIZE);
}

void DictDestroy(Dict dictionary)
{
    int i;
    struct element* e;
    struct element* next;

    for (i = 0; i < dictionary->size; i++)
    {
        for ( e = dictionary->table[i]; e != 0; e = next)
        {
        
                next = e->next;

                free(e->key);
                free(e->value);
                free(e);
            
        }
        
    }

    free(dictionary->table);
    free(dictionary);
    
}



/*
    We will be using the Multiplication Method for generating a hash function
*/

#define MULTIPLIER (47)     //  Multiplier should be a prime number

/**
 * @param input_key : This is the input string we want to hash
*/
static unsigned long hash_function(const char* input_key)
{
    unsigned const char* us;
    unsigned long hash;

    hash = 0;

    //  Loops through all the characters of the the varaiable 'us' that holds the value from input_key
    for ( us = (unsigned const char *)input_key; *us; us++)
    {
        unsigned long current_character_number = *us;       // this variable holds the number representation of the current character. 
                                                            //  An implicit cast has already happened here. *us means unwrapping the 'us' pointer. Inspect in debug mode and see

        hash = hash * MULTIPLIER + current_character_number;
    }
    
    return hash;

}

/**
 * @brief:  This function increases the size of the table in the dictionary by copying the contents into a new dictionary and destroying the old contents
 * @param:  Dictionary object
*/
static void grow(Dict dictionary)
{
    Dict dictionary_new;            /*  new dictionary we will create */
    struct dict swap;               /*  temporary structure to hold original dictionary */
    int i;
    struct element* element;

    dictionary_new = internalDictCreate(dictionary_new->size * GROWTH_FACTOR);

    for (i = 0; i < dictionary->size; i++)
    {
        for ( element = dictionary->table[i]; element != 0; element = element->next)
        {
            /* This recopies all the elements into the new dictionary */
            DictInsert(dictionary_new, element->key, element->value);
        }
        
    }

    /*  We will swap the contents of dictionary_new into dictionary and then call DictDestroy on dictionary_new */

    swap = *dictionary;                 //  put content of original dictionary into a temporary dictionary struct
    *dictionary = *dictionary_new;      //  replace the content of original disctionary with content of the newly created dictionary
    *dictionary_new = swap;             //  replace the content of the new dictionary with the content of the temporary dictionary that contains original dictionary content


    DictDestroy(dictionary_new);        //  destroy the new dictionary that contains the content of the old dictionary

    
}


void DictInsert(Dict dictionary, const char* key, const char* value)
{
    struct element* element;
    unsigned long hash;

    assert(key);
    assert(value);

    element = malloc(sizeof(*element));

    assert(element != NULL);

    element->key = strdup(key);
    element->value = strdup(value);

    hash = hash_function(key) % dictionary->size;   //  by doing % and returning the remainder, we ensure the hash falls within the size of the dictionary which is between 0 and INITIAL_SIZE(1024)

    /*
        element->next = dictionary->table[hash]; 

        1. Assigns the next element(element->next) in the element linked list node to 'an' existing element in the table if the element exists. This is done incase
        there is a collision (same hash exists), so instead of replacing the existing element, we assign it to the next element of the current element. 
        This is the chaining technique for collision resolution.

        dictionary->table[hash] = element;

        2. Assing the current element on the table with the hash to the new element we are inserting. Note that at this point, the new element now contains old element with the hash
        if that old element exists. So if we want to check for collisions we can march through the linked list on the element. 

    */

    element->next = dictionary->table[hash];    
    dictionary->table[hash] = element;

    dictionary->n++;

    //  grow the table in the dictionary if there is not enough room
    if(dictionary->n >= dictionary->size * MAX_LOAD_FACTOR)
    {
        grow(dictionary);
    }

}


const char* DictSearch(Dict dictionary, const char *key)
{
    struct element *element;

    /*
        This for loop clearly shows that we are using the Chaining method of collision resolution.
        This is because we are actually searching an element object with complexity O(1) and if this element object exists we just need to 
        do another comparison to be sure they key is the same. 
        We do this comparison because the mod(%) operation when getting final hash during insert function call might generate same hash at extreme cases (@ToDo: stress test extreme cases).
        If we notice that the key is wrong during string compare after a successful element search from the forloop then we know we have gotten an error
    */
    for (element = dictionary->table[hash_function(key) % dictionary->size]; element != 0; element = element->next)
    {
        if (element != NULL && !strcmp(element->key, key))
        {
            /* got it */
            return element->value;
        }else{

            /*Log edge case where same hash is produced from different keys :(*/
            printf("Investigate hash: %lu and key: %s", hash_function(key) % dictionary->size, key);
        }
        
    }
    
    return 0;
}


void DictDelete(Dict dictionary, const char* key)
{
    struct element **prev;
    struct element *element;

    for (prev = &(dictionary->table[hash_function(key)*dictionary->size]); *prev != 0; prev = &((*prev)->next))
    {
        if (!strcmp((*prev)->key,key))
        {
            element = *prev;
            *prev = element->next;

            free(element->key);
            free(element->value);
            free(element);

            return;
        }
        
    }
    
}


/**
 * @brief: This main function is used  to test the different functions here to ensure they work properly 
 * Uncomment to test the dictionary data structure here 
 * 
*/


// int main(int agrc , char * argv[])
// {
//     //  create a dictionary
//     Dict myDictionary = DictCreate();
    
//     //  insert an element into a dictionary
//     DictInsert(myDictionary, "ugo", "ugochukwu aronu the one and only Jedi Master");
   
//    struct element * element_result = myDictionary->table[237];  //  testing out a direct access with hash value of ugo(237) as index to see if it returns element in the table and it does

//    const char* value = DictSearch(myDictionary,"ugo");

//     //  grow(myDictionary); //  test grow function. NOTE: comment after test as it can cause errors when other functions are called later. 
   
//     // //  destroy the dictionary
//     DictDestroy(myDictionary);

//     //  perform hash
//     unsigned long result = hash_function("ugo");
//     unsigned long result2 = hash_function("ugochukwu aronu the one and only Jedi Master");

//     printf("size of unsigned long: %lu bits", sizeof(long) * __CHAR_BIT__);

    


//     return 0;
// }