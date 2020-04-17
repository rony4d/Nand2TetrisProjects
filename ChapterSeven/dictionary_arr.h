/**
 * @brief: This dictionary is an upgrade on the exisiting dictionary in chapter 6 folder
 * This dictionary will have value as a string double pointer(char **)
 * This dictionary still uses chaining for collision resolution during hashing
*/

#define MAX_ARRAY_ELEMENTS 1024


typedef struct _dict{
    int size;                       /* size of the pointer table */
    int n;                          /* number of elements stored */
    struct element **table;         /* array of elements */
} Dictionary;

struct element
{
    struct element *next;
    char *key;
    char *value;
    char **array_value;
};

/* create a new empty dictionary */
Dictionary *DictCreate(void);

/* destroy  a dictionary */
void DictDestroy(Dictionary *dictionary);

/* insert a new key-value pair into an existing dictionary */
void DictInsert(Dictionary *dictionary, const char *key, const char *value);

/* insert a new key-value pair into an existing dictionary where value is array */
void DictInsertArray(Dictionary *dictionary, const char *key, const char *value, const char **array_value);


/* return the most recently inserterd value associated with a key or return 0 if no matching key is present */
const char *DictSearch(Dictionary *dictionary, const char *key);

/* delete the most recently inserted record with the given key, if there is no such record do nothing */
void DictDelete(Dictionary *dictionary, const char *key);

Dictionary *stack_func_memory_segment_hack_assembly_mapper(char *stack_function, char *memory_segment, char **hack_assembly_instructions);

