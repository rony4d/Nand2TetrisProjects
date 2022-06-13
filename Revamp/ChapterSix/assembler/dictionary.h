typedef struct dict * Dict;

/*  create a new empty dictionary */
Dict DictCreate(void);

/*  destroy a dictionary */
void DictDestroy(Dict);

/**
 * @brief: Inserts a new key-value pairt into an existing dictionary
 * 
*/

void DictInsert(Dict, const char *key, const char *value);

/**
 * @brief: returns the most recently inserterd value associated with a key or 0 if no matching key is
*/
const char * DictSearch(Dict,const char* key);

/**
 * @brief: delete the most recently inserted record with the given key , if such record does not exist, do nothing
 */

void DeleteDict(Dict, const char* key);






