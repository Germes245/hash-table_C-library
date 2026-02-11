#include <stdlib.h>
#include <stddef.h>
#include "../include/dict_chain.h"
#include "../include/hash.h"

#define index_of_key_in_hash(key, length) hash_func(key)%length

typedef struct{
    dict_chain *array;
    size_t length;
} dict;

dict dict_init(size_t length){
    dict hash_table;
    hash_table.length = length;
    size_t size = length*sizeof(dict_chain);
    hash_table.array = malloc(size);
    for(size_t i = 0; i < length; i++){
        hash_table.array[i] = dict_chain_init();
    }
    return hash_table;
}

void dict_put(dict hash_table, TYPE_FOR_DICT key, TYPE_FOR_DICT value){
    uint index = index_of_key_in_hash(key, hash_table.length);
    dict_chain_put(&hash_table.array[index], key, value);
    //exit(1);
}

TYPE_FOR_DICT dict_get(dict hash_table, TYPE_FOR_DICT key){
    uint index = index_of_key_in_hash(key, hash_table.length);
    return dict_chain_get(hash_table.array[index], key);
}

void dict_delete(dict *hash_table, TYPE_FOR_DICT key){
    uint index = index_of_key_in_hash(key, hash_table->length);
    dict_chain_delete(&hash_table->array[index], key);
}

void dict_free(dict *hash_table){
    for(size_t i = 0; i < hash_table->length; i++){
        dict_chain_free(&hash_table->array[i]);
    }
    free(hash_table->array);
    hash_table->array = 0;
    hash_table->length = 0;
}