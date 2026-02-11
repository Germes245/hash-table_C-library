#include "config.h"

/*#define print_dict_chain(chain) {\
    printf("length: %ld. elements: ", chain.length);\
    for (size_t i = 0; i < chain.length; i++){\
        printf("(%s, %s), ", chain.array[i].key, chain.array[i].value);\
    }\
}*/

typedef struct{
    TYPE_FOR_DICT key;
    TYPE_FOR_DICT value;
} dict_couple;

typedef struct{
    dict_couple *array;
    size_t length;
} dict_chain;

dict_chain dict_chain_init();
void dict_chain_put(dict_chain *chain, TYPE_FOR_DICT key, TYPE_FOR_DICT value);
TYPE_FOR_DICT dict_chain_get(dict_chain chain, TYPE_FOR_DICT key);
void dict_chain_delete(dict_chain *chain, TYPE_FOR_DICT key);
void dict_chain_free(dict_chain *chain);