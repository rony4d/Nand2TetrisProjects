/**
 * References : https://www.geeksforgeeks.org/insertion-in-linked-list/
 *              https://www.geeksforgeeks.org/what-is-linked-list/?tab=article
 * 
*/

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"







void push(linked_list ** head_node_ref, char * new_data_str, int key)
{

    //  1. Allocate memory to the new node

    linked_list * new_node = (linked_list * ) malloc(sizeof(linked_list));

    //  2. Put data in the new node and increase node_count
    
    new_node->data_str = new_data_str;
    new_node->key = key;

    //  3. Make the next of the new_node the head_node

    new_node->next = (*head_node_ref);

    //  4. Move the head_node to point to the new node (NOTE: new_node already contains the head node)
    (*head_node_ref) = new_node;


}


void insert_after(linked_list * prev_node, char * new_data_str, int key)
{
    //  1. check ig the given prev_node is NULL
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL \n");
        return;

    }

    //  2. Allocate memory to the new node

    linked_list *  new_node = (linked_list *) malloc(sizeof(linked_list));

    //  3. put data in the new node and increase node_count
    new_node->data_str = new_data_str;
    new_node->key = key;

    //  4. make next of the new_node to be equal to the next of prev_node
    new_node->next = prev_node->next;

    //  5. move the next of the prev_node to be equal to the new_node

    prev_node->next = new_node;

}


void append(linked_list ** head_node_ref, char * new_data_str, int key)
{

    //  1. Allocate memory to the new node

    linked_list * new_node = (linked_list *) malloc(sizeof(struct node));

    //  Extract the actual head_node ( NOTE: any change on last affects the actual head_node)
    linked_list * last = *head_node_ref;


    //  2. Put data in the new node and increase node_count
    
    new_node->data_str = new_data_str;
    new_node->key = key;

    //  3. This new node is going to be the last node, so make sure the next of the new_node is null
    new_node->next = NULL;

    //  4. If the linked list is empty, then make the new node as head
    if ((*head_node_ref) == NULL)
    {
        (*head_node_ref) = new_node;
        return;
    }

    //  5. Else traverse till the last node

    while (last->next != NULL)
    {
        last = last->next;
    }
    
    //  6. Change the next of the last node to the new node
    last->next = new_node;
    
    return;
    /*
        Time complexity: O(N), where N is the number of nodes in the linked list. Since there is a loop from head to end, the function does O(n) work. 
        This method can also be optimized to work in O(1) by keeping an extra pointer to the tail of the linked list/
        
        @todo- Implement O(1) version:
    */

}



void delete_node(linked_list ** head_node_ref, int key)
{
    //  store head node . NOTE that prev also keeps a reference to the head node with this assignment below as well as temp. They contain the same reference to the head node
    linked_list * temp = (*head_node_ref), * prev;

    //  If head node itself holds the key to be deleted
    if (temp != NULL && temp->key == key)
    {
        (* head_node_ref) = temp->next;   //  change head
        free(temp);                     //  free old head
        return;
    }

    //  Search for the key to be deleted, keep track of the previous node as we need to change ' prev->next'
    while (temp != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }
    
    //  If key was not present in the list
    if (temp == NULL)
    {
        return;
    }
    
    //  Else if key was present in the list, Unlink the node from the linked list
    prev->next = temp->next;
    free(temp); //  Free memory


}



//  This function prints contents of the linked list starting from head
void print_list(linked_list * node)
{
    if (node == NULL)
    {
        printf("List cannot be NULL \n");
    }

    while (node != NULL)
    {
        printf("Key %d - Data: %s \n", node->key, node->data_str);

        node = node->next;

    }
    
}

//  uncomment to test code 
// int main(int argc , char * argv[])
// {

//     int counter = 1;    //  use this to generate unique key for every node

//     //  To define a new linked list we need to create a head node

//     linked_list head_one = NULL;

//     //  Insert "Jedi" and 1 . So the linked list becomes ("Jedi",1)->NULL

//     append(&head_one,"Jedi",counter);

//     counter++;

//     //  Insert "Master" and 2 at the beginning . So the linked list becomes ("Master",2)->("Jedi",1)->NULL

//     push(&head_one,"Master", counter);

//     counter++;

//     //  Insert "Ugo" and 3 at the beginning . So the linked list becomes ("Ugo",3)->("Master",2)->("Jedi",1)->NULL

//     push(&head_one,"Ugo", counter);


//     //  delete node with key 2

//     delete_node(&head_one,2);


//     print_list(head_one);







//     return 0;
// }