#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 
*/
void pass_reference(char** name){

    *name = (char *)malloc(sizeof(char *));
    *name = strdup("ugo");

}

int main(int argc, char * argv[]){

    char *name = {0};

    pass_reference(&name);

    printf("Name: %s \n",name);
    return 0;
}