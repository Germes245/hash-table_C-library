#include <stddef.h>

#define print_dict_chain(chain) {\
    printf("length: %ld. elements: ", chain.length);\
    for (size_t i = 0; i < chain.length; i++){\
        printf("(%s, %s), ", chain.array[i].key, chain.array[i].value);\
    }\
}

typedef struct{
    char *key;
    char *value;
} dict_couple;

typedef struct{
    dict_couple *array;
    size_t length;
} dict_chain;

typedef struct{
    dict_chain *array;
    size_t length;
} dict;

dict dict_init(size_t length);
void dict_put(dict hash_table, char key[], char value[]);
char* dict_get(dict hash_table, char key[]);
void dict_delete(dict *hash_table, char key[]);
void dict_free(dict *hash_table);