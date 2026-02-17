#include "config.h"
#include <stddef.h>

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

dict dict_init(size_t length);
void dict_put(dict hash_table, dict_value_t key, dict_value_t value);
dict_value_t dict_get(dict hash_table, dict_value_t key);
void dict_delete(dict *hash_table, dict_value_t key);
void dict_free(dict *hash_table);