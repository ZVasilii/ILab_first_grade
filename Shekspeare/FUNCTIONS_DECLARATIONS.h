char *TextFromFile(const char Name[], unsigned *NumberOfSymbols);

void Filewrite(struct LINE_t index[], unsigned NumberOfSymbols, FILE *f);

struct LINE_t *Create_pointers(char *text, unsigned NumberOfSymbols, unsigned *NumberOfStrings);

int strcmp_begin(const void *ELEM1, const void *ELEM2);

int strcmp_end(const void *ELEM1, const void *ELEM2);

struct LINE_t *arraycopy(struct LINE_t *array, unsigned NumberOfStrings);

