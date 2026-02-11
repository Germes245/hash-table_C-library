#include "config.h"
#include <stddef.h>

typedef struct{
    TYPE_FOR_DICT key;
    TYPE_FOR_DICT value;
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
void dict_put(dict hash_table, TYPE_FOR_DICT key, TYPE_FOR_DICT value);
TYPE_FOR_DICT dict_get(dict hash_table, TYPE_FOR_DICT key);
void dict_delete(dict *hash_table, TYPE_FOR_DICT key);
void dict_free(dict *hash_table);