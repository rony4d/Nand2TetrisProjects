#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BASE (256)
#define MULTIPLIER (37)

/**
 * @brief Implementing and testing different Hashfunctions
 * 1. Division method
 * 2. Multiplication method
 * 3. Universal hashing
*/

/** Division method
 *  treat strings as base-256 integers with digits in range 1-255.
 *  Division works best when m is a prime
 *  Modulus and division are expensive operations
*/


unsigned long hash_division(const char *s, unsigned long m){
    
    unsigned long hash;
    unsigned const char *us;    //unsigned string

    us = (unsigned const char *)s; // cast the string to unsigned const char *, this ensures that elements of s will be treated as having values >=0
    hash = 0;

    while (*us != '\0')
    {
       hash = (hash * BASE + *us) % m;
       us++;                        //goto next character in string sequence
    }
    
    return hash;
}
/**
 *  Unlike the division method, the base is replaced with a MULTIPLIER and this multiplier can be a small prime
 *  MULTIPLIER is used to break up patters in the input
 *  In the multiplier there is no modulus, m. This is because this line "hash = hash * MULTIPLIER + *us" has a hidden modulus
 *  operation happening and the value of the modulus is 2^32 or 2^64 depending on how big your unsigned longs are. 
*/
unsigned long hash_multiplier(const char *s){

    unsigned long hash;
    unsigned const char *us;    //unsigned string

    us = (unsigned const char *)s; // cast the string to unsigned const char *, this ensures that elements of s will be treated as having values >=0
    hash = 0;

    while (*us != '\0')
    {
        hash = hash * MULTIPLIER + *us; 
        us++;
    }
    
    return hash;
}

int main(int argc, char * argv[]){
    //unsigned long result = hash_division("192.168.4.4",37);
    unsigned long result2 = hash_multiplier("192.168.4.4");
    unsigned long result3 = hash_multiplier("D+A");

    printf("Prime: 37 -> Result: %lu \n",result2);
    printf("Prime: 37 -> Result: %lu \n",result3);

    // printf("Multiplier 256 -> Result: %lu \n",result2);
    // printf("Multiplier 256 -> Result: %lu \n",result3);
    return 0;
}