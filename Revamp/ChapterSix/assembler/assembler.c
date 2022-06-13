#include "dictionary.h"
/*

    This is the main assembler module . It  connects to other sub module for handling different tasks in the

    translation of assembly code to machine language. 

    This is where the magic happens. 

    @author: ugochukwu aronu

    references:
    -   Building some data structures in c: https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
    -   LinkedLists: https://www.geeksforgeeks.org/linked-list-set-1-introduction/
    

    Steps
    -   Read the .asm file  - done
    -   Remove white space and comments and output the first file without comments or whitespace - done
    -   Initialzie C -instruction table using the dictionary
    -   Initialize predfefined instruction table using the dictionary
    -   Detect A- instructions
    -   Detect C- instructions
    -   Process A - instructions
    -   Process C - instructions

*/



Dict comp_instruction_dictionary_d;     //  comp_instruction when (a=0) meaning that we are using D-register in CPU
Dict comp_instruction_dictionary_m;     //  comp_instruction when (a=1) meaning that we are using Memory or RAM[A]
Dict dest_instruction_dictionary;       //  
Dict jump_instruction_dictionary;
Dict predefined_symbol_dictionary;      //  maps predefined symbols to the RAM address in decimal. 

void initialize_c_instruction_tables(){

    comp_instruction_dictionary_d = DictCreate();

    DictInsert(comp_instruction_dictionary_d,"0","101010");
    DictInsert(comp_instruction_dictionary_d,"1","111111");
    DictInsert(comp_instruction_dictionary_d,"-1","111010");
    DictInsert(comp_instruction_dictionary_d,"D","001100");
    DictInsert(comp_instruction_dictionary_d,"A","110000");
    DictInsert(comp_instruction_dictionary_d,"!D","001101");
    DictInsert(comp_instruction_dictionary_d,"!A","110001");
    DictInsert(comp_instruction_dictionary_d,"-D","001111");
    DictInsert(comp_instruction_dictionary_d,"-A","110011");
    DictInsert(comp_instruction_dictionary_d,"D+1","011111");
    DictInsert(comp_instruction_dictionary_d,"A+1","110111");
    DictInsert(comp_instruction_dictionary_d,"D-1","001110");
    DictInsert(comp_instruction_dictionary_d,"A-1","110010");
    DictInsert(comp_instruction_dictionary_d,"D+A","000010");
    DictInsert(comp_instruction_dictionary_d,"D-A","010011");
    DictInsert(comp_instruction_dictionary_d,"A-D","000111");
    DictInsert(comp_instruction_dictionary_d,"D&A","000000");
    DictInsert(comp_instruction_dictionary_d,"D|A","010101");

    comp_instruction_dictionary_m = DictCreate();

    DictInsert(comp_instruction_dictionary_m,"M","110000");
    DictInsert(comp_instruction_dictionary_m,"!M","110001");
    DictInsert(comp_instruction_dictionary_m,"-M","110011");
    DictInsert(comp_instruction_dictionary_m,"M+1","110111");
    DictInsert(comp_instruction_dictionary_m,"M-1","110010");
    DictInsert(comp_instruction_dictionary_m,"D+M","000010");
    DictInsert(comp_instruction_dictionary_m,"D-M","010011");
    DictInsert(comp_instruction_dictionary_m,"M-D","000111");
    DictInsert(comp_instruction_dictionary_m,"D&M","000000");
    DictInsert(comp_instruction_dictionary_m,"D|M","010101");


    dest_instruction_dictionary = DictCreate();

    DictInsert(dest_instruction_dictionary,"NULL","000");
    DictInsert(dest_instruction_dictionary,"M","001");
    DictInsert(dest_instruction_dictionary,"D","010");
    DictInsert(dest_instruction_dictionary,"MD","011");
    DictInsert(dest_instruction_dictionary,"A","100");
    DictInsert(dest_instruction_dictionary,"AM","101");
    DictInsert(dest_instruction_dictionary,"AD","110");
    DictInsert(dest_instruction_dictionary,"AMD","111");

    jump_instruction_dictionary = DictCreate();


    DictInsert(jump_instruction_dictionary,"NULL","000");
    DictInsert(jump_instruction_dictionary,"JGT","001");
    DictInsert(jump_instruction_dictionary,"JEQ","010");
    DictInsert(jump_instruction_dictionary,"JGE","011");
    DictInsert(jump_instruction_dictionary,"JLT","100");
    DictInsert(jump_instruction_dictionary,"JNE","101");
    DictInsert(jump_instruction_dictionary,"JLE","110");
    DictInsert(jump_instruction_dictionary,"JMP","111");

    predefined_symbol_dictionary = DictCreate();

    DictInsert(predefined_symbol_dictionary,"SP","0");
    DictInsert(predefined_symbol_dictionary,"LCL","1");
    DictInsert(predefined_symbol_dictionary,"ARG","2");
    DictInsert(predefined_symbol_dictionary,"THIS","3");
    DictInsert(predefined_symbol_dictionary,"THAT","4");

    DictInsert(predefined_symbol_dictionary,"R0","0");
    DictInsert(predefined_symbol_dictionary,"R1","1");
    DictInsert(predefined_symbol_dictionary,"R2","2");
    DictInsert(predefined_symbol_dictionary,"R3","3");
    DictInsert(predefined_symbol_dictionary,"R4","4");
    DictInsert(predefined_symbol_dictionary,"R5","5");
    DictInsert(predefined_symbol_dictionary,"R6","6");
    DictInsert(predefined_symbol_dictionary,"R7","7");
    DictInsert(predefined_symbol_dictionary,"R8","8");
    DictInsert(predefined_symbol_dictionary,"R9","9");
    DictInsert(predefined_symbol_dictionary,"R10","10");
    DictInsert(predefined_symbol_dictionary,"R11","11");
    DictInsert(predefined_symbol_dictionary,"R12","12");
    DictInsert(predefined_symbol_dictionary,"R13","13");
    DictInsert(predefined_symbol_dictionary,"R14","14");
    DictInsert(predefined_symbol_dictionary,"R15","15");
}

