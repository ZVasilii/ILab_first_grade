/**
 *  Function that read file and returns pointer on buffer with text
 * @param FileName  - File with sonet
 * @param NumberOfSymbols - number of symbols in file
 * @return  pointer on buffer with text
 */
char *TextFromFile(const char FileName[], unsigned *NumberOfSymbols)
{
    assert(NumberOfSymbols != NULL);
    struct stat FileInfo = {};
    FILE *f = fopen(FileName, "r");
    assert(f != NULL);

    stat(FileName, &FileInfo);

    char *text = (char *) calloc(FileInfo.st_size + 1, sizeof(text[0]));
    *NumberOfSymbols = fread(text, sizeof(text[0]), FileInfo.st_size, f);
    assert(*NumberOfSymbols > 0);
    fclose(f);
    return text;
}

/**
 * Function that creates pointers on lines
 * @param text -  pointer on buffer with text
 * @param NumberOfSymbols - number of symbols in file
 * @param NumberOfStrings - number of lines in sonet
 * @return
 */
struct LINE_t *Create_pointers(char *text, unsigned NumberOfSymbols, unsigned *NumberOfStrings)
{
    assert(text != NULL);
    assert(NumberOfSymbols != ZERO);
    assert(NumberOfStrings != NULL);

    for (unsigned i = 0; i < NumberOfSymbols; i++)
        if (text[i] == '\n')
            *NumberOfStrings += 1;
    *NumberOfStrings += 1;

    struct LINE_t *Arr_index = (struct LINE_t *) calloc(*NumberOfStrings, sizeof(Arr_index[0]));
    *NumberOfStrings = 0;
    int chars = -1;
    Arr_index[0].index = text;
    for (unsigned i = 0; i <= NumberOfSymbols; i++)
    {
        chars++;
        if (text[i] == '\n')
        {
            text[i] = '\0';
            Arr_index[*NumberOfStrings + 1].index = text + i + 1;
            Arr_index[*NumberOfStrings].length = chars;
            chars = -1;
            *NumberOfStrings += 1;
        }
    }
    Arr_index[*NumberOfStrings].length = chars;
    *NumberOfStrings += 1;
    assert(Arr_index != NULL);

    return Arr_index;
}

/**
 *
 * @param array -  of given array of structures
 * @param NumberOfStrings - number of lines in sonet
 * @return - copy of given array of structures
 */
struct LINE_t *arraycopy(struct LINE_t *array, unsigned NumberOfStrings)
{
    assert(array != NULL);
    assert(NumberOfStrings > 0);

    struct LINE_t *copied = (struct LINE_t *) calloc(NumberOfStrings, sizeof(copied[0]));
    for (unsigned i = 0; i < NumberOfStrings; i++)
        copied[i] = array[i];
    return copied;
}
/**
 *
 * @param Arr_index - array of structures
 * @param NumberOfSymbols -   number of symbols in file
 * @param f - pointer on file, where we write new info
 */
void Filewrite(struct LINE_t Arr_index[], unsigned NumberOfSymbols, FILE *f)
{
    assert(Arr_index != NULL);
    assert(NumberOfSymbols > 0);
    assert(f != NULL);

    fputs("\n*****\n\n", f);
    for (unsigned i = 0; i < NumberOfSymbols; i++)
    {
        fwrite(Arr_index[i].index, sizeof(char), Arr_index[i].length, f);
        fputc('\n', f);
    }
}

/**
 * Comparator left-right
 * @param ELEM1
 * @param ELEM2
 * @return Elem1 > Elem2 or Elem1 < Elem2
 */
int strcmp_begin(const void *ELEM1, const void *ELEM2)
{
    assert(ELEM1 != NULL);
    assert(ELEM2 != NULL);

    const struct LINE_t a = *((struct LINE_t *) ELEM1);
    const struct LINE_t b = *((struct LINE_t *) ELEM2);

    int i = 0, j = 0;
    while ((i < a.length) && (j < b.length))
    {
        char c_a = *(a.index + i);
        char c_b = *(b.index + j);
        if (!isalpha(c_a))
        {
            i++;
            continue;
        }
        if (!isalpha(c_b))
        {
            j++;
            continue;
        }
        if (toupper(c_a) != toupper(c_b))
            return (toupper(c_a) - toupper(c_b));
        i++;
        j++;
    }
    return (a.length - b.length);
}

/**
 * Comparator right-left (rhymes)
 * @param ELEM1
 * @param ELEM2
 * @return Elem1 > Elem2 or Elem1 < Elem2
 */
int strcmp_end(const void *ELEM1, const void *ELEM2)
{
    assert(ELEM1 != NULL);
    assert(ELEM2 != NULL);

    const struct LINE_t a = *((struct LINE_t *) ELEM1);
    const struct LINE_t b = *((struct LINE_t *) ELEM2);

    int i = a.length, j = b.length;
    while ((i >= 0) && (j >= 0))
    {
        char c_a = *(a.index + i);
        char c_b = *(b.index + j);
        if (!isalpha(c_a))
        {
            i--;
            continue;
        }
        if (!isalpha(c_b))
        {
            j--;
            continue;
        }
        if (toupper(c_a) != toupper(c_b))
            return (toupper(c_a) - toupper(c_b));
        i--;
        j--;
    }
    return (a.length - b.length);
}