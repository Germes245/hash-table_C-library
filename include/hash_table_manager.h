#include <stddef.h>
#include <stdint.h>

typedef struct{
    void *array;
    size_t length;
} str_hash_table;

str_hash_table str_hash_table_init(size_t length);
void str_hash_table_put(str_hash_table hash_table, char* key, char* value);
char* str_hash_table_get(str_hash_table hash_table, char* key);
void str_hash_table_delete(str_hash_table *hash_table, char* key);
void str_hash_table_free(str_hash_table *hash_table);
//char** str_hash_table__get_pointers_of_strings(str_hash_table hash_table);

typedef struct{
    char** array;
    size_t length;
} array_of_chars_pointers;

array_of_chars_pointers str_hash_table__get_pointers_of_strings(str_hash_table hash_table);