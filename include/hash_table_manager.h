#include "config.h"
#include <stddef.h>
#include <stdint.h>

typedef struct{
    dict_value_t key;
    dict_value_t value;
} dict_couple;

typedef struct{
    dict_couple *array;
    size_t length;
} dict_chain;

typedef struct{
    dict_chain *array;
    size_t length;
} dict;

#if TYPE_FOR_DICT == TYPE_CHAR_P
    #define get_value_result dict_value_t
#elif TYPE_FOR_DICT == TYPE_INT
    typedef struct{
        dict_value_t value;
        uint8_t error;
    } get_value_result;
#endif

dict dict_init(size_t length);
void dict_put(dict hash_table, dict_value_t key, dict_value_t value);
get_value_result dict_get(dict hash_table, dict_value_t key);
void dict_delete(dict *hash_table, dict_value_t key);
void dict_free(dict *hash_table);