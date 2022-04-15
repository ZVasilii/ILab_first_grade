/**   \brief   This program sort lines from Shekspeare's sonet
      \author  Zaitsev Vasilii, MIPT
      \version 3.0
      \date    October 2019

*/


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/stat.h>
#include <ctype.h>

#include "CONSTANTS.h"
#include "FUNCTIONS_DECLARATIONS.h"
#include "FUNCTIONS_SHEKSPEARE.h"

int main()
{
    unsigned NumberOfSymbols = ZERO;
    unsigned NumberOfStrings = ZERO;

    ///Reading file and sending data in buffer
    char *buffer = TextFromFile(File_in, &NumberOfSymbols);

    ///Creating array of pointers
    struct LINE_t *Arr_index_changed = Create_pointers(buffer, NumberOfSymbols, &NumberOfStrings);

    ///Creating copy of existing array
    struct LINE_t *Arr_index_not_changed = arraycopy(Arr_index_changed, NumberOfStrings);

    FILE *file = fopen(File_out, "w");
    fputs("\nWilliam Shekspeare\n\n", file);
    fputs("\nSONET 66\n\n", file);

    ///sorting left-right
    qsort(Arr_index_changed, NumberOfStrings, sizeof(Arr_index_changed[0]), strcmp_begin);
    ///Writing sorted sonet in file
    Filewrite(Arr_index_changed, NumberOfStrings, file);

    ///sorting right-left
    qsort(Arr_index_changed, NumberOfStrings, sizeof(Arr_index_changed[0]), strcmp_end);
    ///Writing sorted sonet in file
    Filewrite(Arr_index_changed, NumberOfStrings, file);
    ///Writing unsorted sonet in file
    Filewrite(Arr_index_not_changed, NumberOfStrings, file);

    fclose(file);
    free(Arr_index_changed);
    free(buffer);
    free(Arr_index_not_changed);

    return 0;
}
