#include <stddef.h>
#include <stdint.h>

typedef struct{
    void *array;
    size_t length;
} dict;

dict dict_init(size_t length);
void dict_put(dict hash_table, char* key, char* value);
char* dict_get(dict hash_table, char* key);
void dict_delete(dict *hash_table, char* key);
void dict_free(dict *hash_table);