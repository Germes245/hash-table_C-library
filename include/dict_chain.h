#include "config.h"
#include <stddef.h>

/*#define print_dict_chain(chain) {\
    printf("length: %ld. elements: ", chain.length);\
    for (size_t i = 0; i < chain.length; i++){\
        printf("(%s, %s), ", chain.array[i].key, chain.array[i].value);\
    }\
}*/

typedef struct{
    dict_value_t key;
    dict_value_t value;
} dict_couple;

typedef struct{
    dict_couple *array;
    size_t length;
} dict_chain;

dict_chain dict_chain_init();
void dict_chain_put(dict_chain *chain, dict_value_t key, dict_value_t value);
dict_value_t dict_chain_get(dict_chain chain, dict_value_t key);
void dict_chain_delete(dict_chain *chain, dict_value_t key);
void dict_chain_free(dict_chain *chain);