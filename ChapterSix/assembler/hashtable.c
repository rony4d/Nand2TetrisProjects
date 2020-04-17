#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem{
    int data;
    int key;
};

struct DataItem *hashArray[SIZE];
struct DataItem *dummyItem;
struct DataItem *item;

int hashCode(int key){
    return key % SIZE;
}

struct DataItem *search(int key){
    //get the hash
    int hashIndex = hashCode(key);

    //move in array until empty
    while (hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key)
        {
            return hashArray[hashIndex];
        }
        
        // goto next cell
        ++hashIndex;

        //wrap around the table
        hashIndex = hashIndex % SIZE;
    }
    
    return NULL;
}

void insert(int key, int data){

    struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until empty or deleted cell
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        // goto the next cell
        ++hashIndex;

        //wrap around table
        hashIndex = hashIndex % SIZE;
    }
    
    hashArray[hashIndex] = item;
}

struct DataItem *delete(struct DataItem *item){
    int key = item->key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in the array until empty
    while (hashArray[hashIndex != NULL])
    {
       if (hashArray[hashIndex]->key == key)
       {
           struct DataItem *temp = hashArray[hashIndex];

           //assign a dummy item at deleted position
           hashArray[hashIndex] = dummyItem;
           return temp;
       }
        //goto next cell
        ++hashIndex;

        //wrap around the table
        hashIndex = hashIndex % SIZE;
       
    }
    
    return NULL;
}

void display(){

    for (size_t i = 0; i < SIZE; i++)
    {
        if (hashArray[i] != NULL)
        {
            printf("( %d, %d)", hashArray[i]->key, hashArray[i]->data);
        }else
        {
            printf(" -- ");
        }
        
        
    }
    
    printf("\n");
}


int main(int argc, char* argv[]){
    dummyItem = (struct DataItem *)malloc(sizeof(struct DataItem));
    dummyItem->key = -1;
    dummyItem->data = -1;
}