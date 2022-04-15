#ifndef STACKPUSPLUS_STACK_FUNCTIONS_H
#define STACKPUSPLUS_STACK_FUNCTIONS_H


#include "STACK_ERRORS.h"

#include "PRINT_FUNCTIONS.h"             ///Header file with print functions

/**
 * Function that creates stack and initialize it
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
bool StackDyn_t<T>::STACK_INIT()
{
    srand(time(NULL));
    capacity_ = STACK_CAPACITY_ADD;
    size_ = ZERO;
    ///data_ = (T *) calloc(STACK_CAPACITY_ADD, sizeof(T));
    data_ = (T*) new T [STACK_CAPACITY_ADD];

    CANARYREF1 = rand() % 100000;
    CANARYREF2 = rand() % 100000;

    CANARY1_ = CANARYREF1;
    CANARY2_ = CANARYREF2;
    hash_ = COUNTHASH();
    if (OK_W_O_SIZE())
        return false;
    return true;
}


/**
 * Function that deletes stack and frees memory
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
bool StackDyn_t<T>::STACK_DESTROY()
{
    if (OK())
        return false;
    ///free(data_);
    delete [] data_;
    size_ = ZERO;
    hash_ = COUNTHASH();
    if (OK_W_O_SIZE_POINTER())
        return false;
    return true;
}


/**
 * Function that expand memory for stack
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */


template<typename T>
bool StackDyn_t<T>::STACK_REALLOC()
{
    if (OK())
        return false;
    data_ = (T *) realloc(data_, (capacity_ + STACK_CAPACITY_ADD) * sizeof(T));
    capacity_ += STACK_CAPACITY_ADD;
    hash_ = COUNTHASH();
    if (OK())
        return false;
    return true;
}


/**
 * Function that pushes data INTO stack
 * @tparam T - type of data
 * @param Value - value which will be pushed into stack
 * @return true if everything works fine, false if errors occurred
 */


template<typename T>
bool StackDyn_t<T>::PUSH(T Value)
{
    bool check_errors = false;
    if (OK_W_O_SIZE())
        return false;
    this->data_[this->size_] = Value;
    this->size_++;
    hash_ = COUNTHASH();
    if (size_ == (capacity_ - 1))
    {
        check_errors = STACK_REALLOC();
        if (!check_errors) ERRORMANAGE(OK());
    }
    hash_ = COUNTHASH();
    if (OK_W_O_SIZE())
        return false;
    return true;
}


/**
 * Function that pulls data FROM stack
 * @tparam T - type of data
 * @param *Value - pointer on value which pulled from stack
 * @return true if everything works fine, false if errors occurred
 */


template<typename T>
bool StackDyn_t<T>::POP(T *Value)
{
    if (OK())
        return false;
    *Value = this->data_[this->size_ - 1];
    this->size_--;
    hash_ = COUNTHASH();
    if (OK_W_O_SIZE())
        return false;
    return true;
}


/**
 * Function, that calculates hash
 * @tparam T - type of data
 * @return Value of calculated hash
 */


template<typename T>
unsigned long long StackDyn_t<T>::COUNTHASH()
{
    return ((unsigned long long) (*((int*) (&data_)) * *((int*) (&data_)) + capacity_ +
                                  1923 * size_ % 24 * (CANARY1_ % 25) * (CANARY2_ % 37)));
}


/**
 * Function that checks if everything is working correctly
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */


template<typename T>
char StackDyn_t<T>::OK()
{
    if (this == nullptr) return STACK_POINTER;
    else if (capacity_ == 0) return ZERO_CAPACITY;
    else if (COUNTHASH() != hash_) return ERROR_HASH;
    else if ((CANARY1_ != CANARYREF1) || (CANARY2_ != CANARYREF2)) return ERROR_CANAREES;
    else if (data_ == nullptr) return DATA_POINTER;
    else if (size_ == 0) return STACK_EMPTY;
    else if (size_ > capacity_) return STACK_FULL;
    else return EVERYTHING_GOOD;
}


/**
 * Function that checks if everything is working correctly without checking (size_ == 0)
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */


template<typename T>
char StackDyn_t<T>::OK_W_O_SIZE()
{
    if (this == nullptr) return STACK_POINTER;
    else if (capacity_ == 0) return ZERO_CAPACITY;
    else if (COUNTHASH() != hash_) return ERROR_HASH;
    else if ((CANARY1_ != CANARYREF1) || (CANARY2_ != CANARYREF2)) return ERROR_CANAREES;
    else if (data_ == nullptr) return DATA_POINTER;
    else if (size_ > capacity_) return STACK_FULL;
    else return EVERYTHING_GOOD;
}


/**
 * Function that checks if everything is working correctly
 * without checking (size_ == 0) and pointer on data
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */


template<typename T>
char StackDyn_t<T>::OK_W_O_SIZE_POINTER()
{

    if (this == nullptr) return STACK_POINTER;
    else if (capacity_ == 0) return ZERO_CAPACITY;
    else if (COUNTHASH() != hash_) return ERROR_HASH;
    else if ((CANARY1_ != CANARYREF1) || (CANARY2_ != CANARYREF2)) return ERROR_CANAREES;
    else if (size_ > capacity_) return STACK_FULL;
    else return EVERYTHING_GOOD;
}


/**
 * Function that shows information about different errors in stack and abort program
 * @tparam T - type of data
 * @param Errorcode - Code of error from function OK()
 */

template<typename T>
void StackDyn_t<T>::ERRORMANAGE(char Errorcode)
{
    printf("\n");
    red();
    if (Errorcode == ZERO_CAPACITY)
    {
        printf("SOMETHING WENT WRONG!!!\n");
        printf("CHECK YOUR STACK CAPACITY!\n");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == ERROR_HASH)
    {
        printf("SOMETHING WENT WRONG!!!\n");
        printf("CHECK YOUR HASH!\n");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == ERROR_CANAREES)
    {
        printf("SOMETHING WENT WRONG!!!\n");
        printf("CHECK YOUR CANAREES!\n");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == DATA_POINTER)
    {
        printf("SOMETHING WENT WRONG!!!\n");
        printf("CHECK YOUR DATA POINTER!\n");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == STACK_POINTER)
    {
        printf("SOMETHING WENT WRONG!!!\n");
        printf("CHECK YOUR STACK POINTER!\n");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == STACK_EMPTY)
    {
        printf("SOMETHING WENT WRONG!!!\n");
        printf("YOUR STACK IS EMPTY!\n");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == STACK_FULL)
    {
        printf("SOMETHING WENT WRONG!!!\n");
        printf("YOUR STACK IS FULL!\n");
        DUMP();
        DUMP_IN_FILE();
        abort();
    }
    reset();
}


/**
 * Function that shows all current information about stack
 * @tparam T - type of data
 */


template<typename T>
void StackDyn_t<T>::DUMP()
{
    int Elem = 0;
    red();
    printf("\n");
    printf("\n");
    printf("***DUMP***\n");
    printf("\n");
    blue();
    printf("Pointer on stack: %p\n", this);
    printf("Capacity of stack: %lu\n", capacity_);
    printf("Calculated hash: %llu\n", hash_);
    printf("Canary 1: %llu\n", CANARY1_);
    printf("Canary 2: %llu\n", CANARY2_);
    printf("Size of stack: %lu\n", size_);
    printf("Pointer on data: %p\n", data_);
    printf("\n");
    magenta();
    for (Elem = 0; Elem < size_; Elem++)
    {
        printf("Element # %d is ", Elem + 1);
        Print(data_[Elem]);
    }
    red();
    printf("\n");
    printf("***END OF DUMP***\n");
    printf("\n");
    printf("\n");
    reset();
}


/**
 * Function that write all current information about stack in file
 * @tparam T
 */


template<typename T>
void StackDyn_t<T>::DUMP_IN_FILE()
{
    int Elem = 0;
    FILE *File = fopen(FILENAME, "w");
    fprintf(File, "\n");
    fprintf(File, "***DUMP***\n");
    fprintf(File, "\n");
    fprintf(File, "Pointer on stack: %p\n", this);
    fprintf(File, "Capacity of stack: %lu\n", capacity_);
    fprintf(File, "Calculated hash: %llu\n", hash_);
    fprintf(File, "Canary 1: %llu\n", CANARY1_);
    fprintf(File, "Canary 2: %llu\n", CANARY2_);
    fprintf(File, "Size of stack: %lu\n", size_);
    fprintf(File, "Pointer on data: %p\n", data_);
    fprintf(File, "\n");
    for (Elem = 0; Elem < size_; Elem++)
    {
        fprintf(File, "Element # %d is ", Elem + 1);
        FilePrint(File, data_[Elem]);
    }
    fprintf(File, "\n");
    fprintf(File, "***END OF DUMP***\n");
    fprintf(File, "\n");
    fclose(File);

}


/**
 * Function that testing stack functionality
 * @tparam T - type of data
 */


template<typename T>
void StackDyn_t<T>::UNIT_TEST()
{

    bool check_errors = false;
    DATATYPE Value = ZERO;

    printf("***UNIT TEST***\n");
    printf("\n");
    printf("***PUSHING...***\n");
    printf("\n");

    srand(time(nullptr));
    for (int i = 0; i < TEST_NUMBER; i++)
    {
        check_errors = PUSH(rand() % 100000);
        if (!check_errors) ERRORMANAGE(OK_W_O_SIZE());
    }

    DUMP();
    DUMP_IN_FILE();

    printf("\n");
    printf("***POPPING...***\n");
    printf("\n");

    magenta();

    for (int j = 0; j < TEST_NUMBER; j++)
    {
        check_errors = POP(&Value);
        if (!check_errors) ERRORMANAGE(OK());
        printf("Popped element is ");
        Print( Value);
       // printf("\n");
    }

    reset();


    printf("\n");

    DUMP();
    DUMP_IN_FILE();
}


/**
 * Function that prints main information about the programm
 * @tparam T - type of data
 */


template<typename T>
void StackDyn_t<T>::INTRODUCTION()
{
    printf("\n");
    green();
    printf("************************\n");
    printf("This program is a model of Stack\n");
    printf("(Visit Wikipedia for more information)\n");
    printf("https://en.wikipedia.org/wiki/Stack_(abstract_data_type)\n");
    printf("Zaitsev Vasilii, MIPT\n");
    printf("Version 5.0\n");
    printf("November 2019\n");
    printf("************************\n");
    reset();
    printf("\n");
  
}


#endif //STACKPUSPLUS_STACK_FUNCTIONS_H
