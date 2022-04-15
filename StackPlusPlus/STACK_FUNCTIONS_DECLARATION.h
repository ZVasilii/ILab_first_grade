#ifndef STACKPUSPLUS_STACK_FUNCTIONS_DECLARATION_H
#define STACKPUSPLUS_STACK_FUNCTIONS_DECLARATION_H


#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ctime>


const int ZERO = 0;
const int STACK_CAPACITY_ADD = 10;                                           ///Maximum size of stack
const char FILENAME[] = "DUMP.txt";                                          ///File with dumped information
const int TEST_NUMBER = 20;                                                  ///Number of elements in testing function

typedef int DATATYPE;                                                         ///Changing type of data



template<typename T>
class StackDyn_t
{
    
private:

    unsigned long long CANARY1_;         ///Canary #1
    unsigned long long CANARYREF1;
    unsigned long long CANARYREF2;
    T *data_;                            ///Pointer on data, which contained in stack
    size_t size_;                        ///Current size of stack
    size_t capacity_;                    ///Maximum capacity of stack
    unsigned long long  hash_;           ///Hash, which calculates on every step

    unsigned long long COUNTHASH();      ///Function that calculates hash

public:

    bool PUSH(T value);                  ///Function that pushes data INTO stack

    bool POP(T *Value);                  ///Function that pulls data FROM stack

    bool STACK_INIT();                   ///Function that creates stack and initialize it

    bool STACK_DESTROY();                ///Function that deletes stack and frees memory

    bool STACK_REALLOC();                ///Function that adds memory in stack

    char OK();                           ///Function that checks if everything is working correctly

    char OK_W_O_SIZE();                  ///Function that checks if everything is working correctly

    char OK_W_O_SIZE_POINTER();          ///Function that checks if everything is working correctly

    void DUMP();                         ///Function that shows all current information about stack

    void DUMP_IN_FILE();                 ///Function that write all current information about stack in file

    void UNIT_TEST();                    ///Function that testing function push and pop

    void INTRODUCTION();                 /// Function that prints main information about the programm

    void ERRORMANAGE(char Errorcode);    ///Function that shows information about different errors in stack


private:
    unsigned long long CANARY2_;         ///Canary #2
};

#include "STACK_FUNCTIONS.h"             ///Header file with all functions

#endif //STACKPUSPLUS_STACK_FUNCTIONS_DECLARATION_H









