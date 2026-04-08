#include <stddef.h>
#include <stdint.h>

/*#define print_str_hash_table_chain(chain) {\
    printf("length: %ld. elements: ", chain.length);\
    for (size_t i = 0; i < chain.length; i++){\
        printf("(%s, %s), ", chain.array[i].key, chain.array[i].value);\
    }\
}*/

typedef struct{
    void *array;
    size_t length;
} str_hash_table_chain;

str_hash_table_chain str_hash_table_chain_init();
void str_hash_table_chain_put(str_hash_table_chain *chain, char* key, char* value);
char* str_hash_table_chain_get(str_hash_table_chain chain, char* key);
void str_hash_table_chain_delete(str_hash_table_chain *chain, char* key);
void str_hash_table_chain_free(str_hash_table_chain *chain);