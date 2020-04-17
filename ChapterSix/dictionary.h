/**
 * String to string dictionary using chaining for collision resolution during hashing
*/

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
};

/* create a new empty dictionary */
Dictionary *DictCreate(void);

/* destroy  a dictionary */
void DictDestroy(Dictionary *dictionary);

/* insert a new key-value pair into an existing dictionary */
void DictInsert(Dictionary *dictionary, const char *key, const char *value);

/* return the most recently inserterd value associated with a key or return 0 if no matching key is present */
const char *DictSearch(Dictionary *dictionary, const char *key);

/* delete the most recently inserted record with the given key, if there is no such record do nothing */
void DictDelete(Dictionary *dictionary, const char *key);

/**
 * dest = comp ; jump.
 * This function builds the 'comp' part
 * Compute Instruction set for controlling the ALU (comp)
*/
Dictionary *buid_compute_instruction_set_ALU(char a);

/**
 * dest = comp ; jump
 * This function builds the 'dest' part 
*/
Dictionary *build_compute_instruction_set_destination();

/**
 * dest = comp ; jump
 * This function builds the 'jump' part 
*/

Dictionary *build_compute_instruction_set_jump();

/**
 * This builds a dictionary of the 23-predefined symbols
 * in the Hack Language Specification
 * NOTE: All values will be stored in binary
*/
Dictionary *build_a_inst_predefined_symbol_table();

/**
 * This builds a dictionary of the label symbols found in the Hack
 * assembly code. The content will be the symbol name as KEY and line number(in binary) as address which
 * is the value.
 * Eg (LOOP), line 4 translates to ["LOOP","0000000000000100"]
 * NOTE: All values will be stored in binary
*/
Dictionary *build_a_inst_label_symbol_table();

/**
 * This builds a dictionary of the variable symbols found in the Hack
 * assembly code. The content will be the symbol name as KEY and line number(in binary) as address which
 * is the value.
 * NOTE: Address for variables start from memory address 16. All values will be stored in binary
 * Eg @name, translates to ["name","0000000000010000"]
 * 
*/
Dictionary *build_a_inst_variable_symbol_table();

/**
 * This builds the overall symbol table for a instruction
 * NOTE: All values will be stored in binary
*/
Dictionary *build_a_inst_symbol_table();