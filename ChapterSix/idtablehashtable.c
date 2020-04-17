#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "idtablehashtable.h"

/**
 * @brief A low overhead hash table using open addressing. The application is rapidly verifying ID numbers in the range
 * 000000000 to 999999999 by checking them against a list of known IDs. Since the quantity of a valid ID number 
 * must be very large, a goal of the mechanism is to keep the value of extra storage used as small as possible.
 * This implementation uses a tunable overhead parameter.
 * Setting the parameter to a high value makes the lookups fast but requires more space per ID in the list.
 * Setting it to a low value can reduce the storage cost arbitrarily close to 4 bytes per ID, at the cost of increasing search times
 * 
 * 
 * Hash table using open addressing 
*/

/*  overhead parameter that determines both space ans search costs must be strictly greater than 1 */
#define OVERHEAD (1.1)
#define NULL_ID (-1)

IDList *IDListCreate(int n, int unsorted_id_list[]){

    IDList *list;
    int size;
    int i;
    int probe;
    int next;
    size = (int) (n * OVERHEAD + 1);

    list = malloc(sizeof(IDList) + sizeof(int) * (size - 1));
    if(list == NULL)
        return NULL;

    list->size = size;

    // clear the hash table 

    for (i = 0; i < n; i++)
    {
        list->ids[i] = NULL_ID;
    }
    
    // load up the hast tabele
    for ( i = 0; i < n; i++)
    {
        assert(unsorted_id_list[i] >= MIN_ID);
        assert(unsorted_id_list[i] <= MAX_ID);

        /* hashing with open addressing by division, this must be the same pattern as in IDListContains */
        
        /* This is doing the same thing  as insert function in hashtabletest.c, probe is the hashindex, list->size is SIZE macro used in hashcode function
           then probe = (probe + 1) % list->size) is the wrap around expression ++hashIndex; hashIndex = hashIndex % SIZE;
        */
        for (probe = unsorted_id_list[i] % list->size; list->ids[probe] != NULL_ID; probe = (probe + 1) % list->size);
        
        assert(list->ids[probe] == NULL_ID);

        list->ids[probe] = unsorted_id_list[i];
    }
    
    return list;
}

void IDListDestroy(IDList *list){
    free(list);
}

int IDListContains(IDList *list, int id)
{
    int probe;

    /* this must be the same pattern as in IDListCreate */
    for (probe = id % list->size; list->ids[probe] != NULL_ID; probe = (probe + 1) % list->size)
    {
        if (list->ids[probe] == id)
        {
           return 1;
        }
        if (list->ids[probe] != id && probe >= (list->size - 1))
        {
            return 0;
        }
        
    }
    
    return 0;

}

int main(int argc, char * argv[]){
    IDList *list;
    int ids[5] = {1,23,45,62,42};
    
    list = IDListCreate(sizeof(ids)/sizeof(int),ids);

    if (list != NULL)
    {
        printf("Size %d", list->size);
    }
    
    int result = IDListContains(list,93);

    return 0;
}