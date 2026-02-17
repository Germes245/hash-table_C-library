#include "config.h"
#include <stddef.h>
#include <stdint.h>

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

#if TYPE_FOR_DICT == TYPE_CHAR_P
    #define get_value_result dict_value_t
#elif TYPE_FOR_DICT == TYPE_INT
    typedef struct{
        dict_value_t value;
        uint8_t error;
    } get_value_result;
#endif

dict_chain dict_chain_init();
void dict_chain_put(dict_chain *chain, dict_value_t key, dict_value_t value);
dict_value_t dict_chain_get(dict_chain chain, dict_value_t key);
void dict_chain_delete(dict_chain *chain, dict_value_t key);
void dict_chain_free(dict_chain *chain);