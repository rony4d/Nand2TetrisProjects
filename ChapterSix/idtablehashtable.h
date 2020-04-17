
typedef struct id_list{
    int size;
    int ids[1];         /* we will malloc more space than this*/
} IDList;

#define MIN_ID (0)
#define MAX_ID (999999999)

/** build an IDList out of an unsorted array of n good ids
 *  returns 0 on allocation failure   
 */

IDList *IDListCreate(int n, int unsorted_id_list[]);

/* destroy and IDList */
void IDListDestroy(IDList *list);

/**
 * check an id against the list
 * resturns nonzero if id is in the list
*/
int IDListContains(IDList *list, int id);