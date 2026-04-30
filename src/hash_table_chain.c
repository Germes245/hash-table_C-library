#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "hash_table_couple.h"

#define print_str_hash_table_chain(chain) {\
    printf("length: %ld. elements: ", chain.length);\
    for (size_t i = 0; i < chain.length; i++){\
        printf("(%s, %s), ", chain.array[i].key, chain.array[i].value);\
    }\
}

typedef struct{
    str_hash_table_couple *array;
    size_t length;
} str_hash_table_chain;

static void str_hash_table_chain_shift_left(str_hash_table_chain *chain, size_t index){
    while(index < chain->length-1){
        chain->array[index] = chain->array[index + 1];
        index++;
    }
}

static size_t str_hash_table_chain_has_couple_with_key(str_hash_table_chain *chain, char* key){ //если есть, то индекс структуры, иначе 0
    for(size_t i = 0; i < chain->length; i++){
        //printf("keyva: %s\n", chain->array[i].key);
        if(strcmp(chain->array[i].key,key)) return i+1;
    }
    return 0;
}

str_hash_table_chain str_hash_table_chain_init(){
    str_hash_table_chain chain;
    chain.array = 0;
    chain.length = 0;
    return chain;
}

void str_hash_table_chain_put(str_hash_table_chain *chain, char* key, char* value){
    if(chain->length){
        int index;
        if((index = str_hash_table_chain_has_couple_with_key(chain, key)) != -1){
            free(chain->array[index].value);
            create_and_copy(chain->array[index].value, value);
        }
        else{
            chain->array = realloc(chain->array, (++chain->length)*sizeof(str_hash_table_chain));
            create_and_copy(chain->array[chain->length-1].key, key);
            create_and_copy(chain->array[chain->length-1].value, value);
        }
        chain->length++;
    }
    else{
        chain->array = malloc(sizeof(str_hash_table_couple));
        chain->length = 1;
        create_and_copy(chain->array[0].key, key);
        create_and_copy(chain->array[0].value, value);
    }
}

char* str_hash_table_chain_get(str_hash_table_chain chain, char* key){
    size_t index = str_hash_table_chain_has_couple_with_key(&chain, key);
    if(index == 0) {
        return 0;
    }
    return chain.array[index-1].value;
}

#include <assert.h>

unsigned char str_hash_table_chain_delete(str_hash_table_chain *chain, char* key){
    size_t index = str_hash_table_chain_has_couple_with_key(chain, key);
    //printf("%d\n", index);
    assert(index==0);
    if(index == 0) return 0;
    //printf("%s\n", chain->array[index-1].key);
    str_hash_table_couple_free(&chain->array[index-1]);
    if (chain->length != 1) {
        str_hash_table_chain_shift_left(chain, index-1);
        chain->array = realloc(chain->array, (--chain->length)*sizeof(str_hash_table_couple));
    }
    free(chain->array);
    chain->array=0;
    return 1;
}

void str_hash_table_chain_free(str_hash_table_chain *chain){
    for(size_t i = 0; i < chain->length; i++){
        str_hash_table_couple_free(&chain->array[i]);
    }
    free(chain->array);
    chain->length = 0;
}