#include <stddef.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    char* value;
    char* key;
} str_hash_table_couple;

typedef struct{
    str_hash_table_couple *array;
    size_t length;
} str_hash_table_chain;

static size_t str_hash_table_chain_has_couple_with_key(str_hash_table_chain *chain, char* key){ //если есть, то индекс структуры, иначе 0
    for(size_t i = 0; i < chain->length; i++){
        //printf("keyva: %s\n", chain->array[i].key);
        if(strcmp(chain->array[i].key,key)) return i+1;
    }
    return 0;
}

int main(){
    str_hash_table_couple array;
    return 0;
}