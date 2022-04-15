

#ifndef STACKPLUSPLUS_PRINT_FUNCTIONS_H
#define STACKPLUSPLUS_PRINT_FUNCTIONS_H

#include <cstdio>


void red();

void green();

void yellow();

void blue();

void magenta();

void cyan();

void B_red();

void B_green();

void B_yellow();

void B_blue();

void B_magenta();

void B_cyan();

void reset();

void Print(long long ValueL);                    ///Functions that print variables with different types

void Print(double ValueD);

void Print(char ValueC);

void Print(unsigned long long ValueU);

void Print(int ValueI);

void Print(unsigned ValueU);

void Print(unsigned char ValueUC);

void SetColor(int text, int background);         ///Function that changes color of text in console



void FilePrint(FILE *file, long long ValueL);    ///Functions that print variables with different types in file

void FilePrint(FILE *file, double ValueD);

void FilePrint(FILE *file, char ValueC);

void FilePrint(FILE *file, unsigned long long ValueU);

void FilePrint(FILE *file, int ValueI);

void FilePrint(FILE *file, unsigned ValueU);

void FilePrint(FILE *file, unsigned char ValueUC);


/**
 * Functions that print variables with different types
 * @tparam T - type of data
 * @param Values with different types
 */

void Print(long long ValueL)
{
    printf(" %lld\n",ValueL);
}

void Print(double ValueD)
{
    printf(" %lg\n", ValueD);
}

void Print(char ValueC)
{
    printf(" %c\n", ValueC);
}

void Print(unsigned long long ValueU)
{
    printf(" %llu\n", ValueU);
}

void Print(int ValueI)
{
    printf(" %d\n", ValueI);
}

void Print(unsigned ValueU)
{
    printf(" %u\n", ValueU);
}

void Print(unsigned char ValueUC)
{
    printf(" %u\n", ValueUC);
}


/**
 * Functions that write variables with different types in file
 * @tparam T - type of data
 * @param Values with different types
 */


void FilePrint(FILE *file, long long ValueL)
{
    fprintf(file," %lld\n", ValueL);
}

void FilePrint(FILE *file, double ValueD)
{
    fprintf(file, " %lg\n", ValueD);
}


void FilePrint(FILE *file, char ValueC)
{
    fprintf(file, " %c\n", ValueC);
}

void FilePrint(FILE *file, unsigned long long ValueU)
{
    fprintf(file, " %llu\n", ValueU);
}


void FilePrint(FILE *file, int ValueI)
{
    fprintf(file, " %d\n", ValueI);
}


void FilePrint(FILE *file, unsigned ValueU)
{
    fprintf(file, " %u\n", ValueU);
}


void FilePrint(FILE *file, unsigned char ValueUC)
{
    fprintf(file, " %u\n", ValueUC);
}

void red()                  ///Functions that changes colour of the text
{
  printf("\033[0;31m");
}

void green() 
{
  printf("\033[0;32m");
}

void yellow()
{
  printf("\033[0;33m");
}

void blue()
{
  printf("\033[034m");
}

void magenta()
{
  printf("\033[0;35m");
}

void cyan()
{
  printf("\033[0;36m");
}

void B_red()
{
  printf("\033[1;31m");
}

void B_green()
{
  printf("\033[1;32m");
}

void B_yellow()
{
  printf("\033[1;33m");
}

void B_blue()
{
  printf("\033[1;34m");
}

void B_magenta()
{
  printf("\033[1;35m");
}

void B_cyan()
{
  printf("\033[1;36m");
}

void reset()
 {
  printf("\033[0m");
}


/**
 * Function that changes color of text in console
 * @param text - color of the text in console
 * @param background - color of the background in console
 */

/*
void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
*/

#endif //STACKPLUSPLUS_PRINT_FUNCTIONS_H
