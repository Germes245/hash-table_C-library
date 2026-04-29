#pragma once
typedef struct{
    char* value;
    char* key;
} str_hash_table_couple;

str_hash_table_couple str_hash_table_couple_init(char* key, char* value);

void str_hash_table_couple_change_value(str_hash_table_couple couple, char* value);
void str_hash_table_couple_free(str_hash_table_couple *couple);

#define create_and_copy(destination, source) destination = malloc(strlen(source)+1);\
strcpy(destination, source)