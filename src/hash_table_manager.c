#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "hash_table_chain.h"
#include "hash_table_couple.h"
#include "hash.h"
#define index_of_key_in_hash(key, length) hash_func(key)%length

typedef struct{
    str_hash_table_chain *array;
    size_t length;
} str_hash_table;

/**
 * @brief инициализирует хэш-таблицу
 * @param length -- количество бакетов в будущей хэш-таблице
 * @return новая хэш-таблица
*/
str_hash_table str_hash_table_init(size_t length){
    str_hash_table hash_table;
    hash_table.length = length;
    size_t size = length*sizeof(str_hash_table_chain);
    hash_table.array = malloc(size);
    for(size_t i = 0; i < length; i++){
        hash_table.array[i] = str_hash_table_chain_init();
    }
    return hash_table;
}

/**
 * @brief добавляет пару ключ:значение в хэш-таблицу
 * @param length -- количество бакетов в будущей хэш-таблице
 * @return новая хэш-таблица
*/
void str_hash_table_put(str_hash_table hash_table, char* key, char* value){
    size_t index = index_of_key_in_hash(key, hash_table.length);
    str_hash_table_chain_put(&hash_table.array[index], key, value);
    //exit(1);
}

char* str_hash_table_get(str_hash_table hash_table, char* key){
    size_t index = index_of_key_in_hash(key, hash_table.length);
    return str_hash_table_chain_get(hash_table.array[index], key);
}

void str_hash_table_delete(str_hash_table *hash_table, char* key){
    size_t index = index_of_key_in_hash(key, hash_table->length);
    //printf("shya1\n");
    str_hash_table_chain_delete(&hash_table->array[index], key);
    //printf("shya2\n");
}

void str_hash_table_free(str_hash_table *hash_table){
    for(size_t i = 0; i < hash_table->length; i++){
        str_hash_table_chain_free(&hash_table->array[i]);
    }
    free(hash_table->array);
    hash_table->array = 0;
    hash_table->length = 0;
}

typedef struct{
    char** array;
    size_t length;
} array_of_chars_pointers;

array_of_chars_pointers str_hash_table__get_pointers_of_strings(str_hash_table hash_table){
    array_of_chars_pointers result;
    result.length = 0;
    for(size_t i = 0; i < hash_table.length; i++){
        result.length += hash_table.array[i].length * 2;
    }
    result.array = malloc(result.length * sizeof(char*));
    size_t index = 0;
    for(size_t i = 0; i < hash_table.length; i++){
        size_t score_of_coulpes = hash_table.array[i].length;
        str_hash_table_couple* couple = hash_table.array[i].array;
        for (size_t j = 0; j < hash_table.array[i].length; j++) {
            result.array[index] = couple[j].key; //hash_table.array[i].array[j].key;
            result.array[(++index)] = couple[j].value;//hash_table.array[i].array[j].value;
            ++index;
        }
    }
    return result;
}

//void str_hash_table_put_