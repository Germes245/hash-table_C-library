#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "hash_table_couple.h"

str_hash_table_couple str_hash_table_couple_init(char* key, char* value){
    str_hash_table_couple couple;
    create_and_copy(couple.key, key);
    create_and_copy(couple.value, value);
    return couple;
}

void str_hash_table_couple_change_value(str_hash_table_couple couple, char* value){
    free(couple.value);
    create_and_copy(couple.value, value);
}

void str_hash_table_couple_free(str_hash_table_couple *couple){
    free(couple->key);
    free(couple->value);
    couple->key = 0;
    couple->value = 0;
}