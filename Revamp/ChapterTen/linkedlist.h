 typedef struct node{
    int key;                        //  unique identifier
    char * data_str;
    struct node * next;
} linked_list;
/**
 * INSERT FUNCTIONS
 * @param push              insert to the beginning of the list
 * @param insertAfter       insert after a particular position
 * @param append            insert at the end of the list
*/


/**
 * @brief Given a reference (pointer to pointer) to the head node, this function inserts a new node on the front of the list
*/
void push(linked_list ** head_node_ref, char * new_data_str, int key);


/**
 * @brief Given a node prev_node, insert a new node after the given prev_node
*/
void insert_after(linked_list *  prev_node, char * new_data_str, int key);

/**
 * @brief Given a reference (pointer to pointer) to the head node, this function inserts a new node at the end
*/
void append(linked_list ** head_node_ref, char * new_data_str, int key);




/**
 * DELET FUNCTIONS
 * @param delete_node
*/

/**
 * @brief Given a reference (pointer to pointer) to the head of a list and a key, deletes the first occurence of key in the linked list
*/
void delete_node(linked_list ** head_node_ref, int key);

/**
 * @brief frees the memory location held by the linked_list
*/
void free_list(linked_list ** head_node);