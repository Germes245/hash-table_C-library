//void
#include <dyn_array.h>
#include <dyn_string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef dyn_array str_hash_table_chain;

str_hash_table_chain str_hash_table_chain_init(){
    return dyn_array_init(0);
}

static size_t find_index_of_key(str_hash_table_chain chain, char* key, uint8_t *has_string){
    for(size_t i = 0; i < chain.length; i+=2){
        if(strcmp(key, chain.data[i]) == 0) {
            *has_string = 1;
            return i;
        }
    }
    *has_string = 0;
}

void str_hash_table_chain_put(str_hash_table_chain *chain, char* key, char* value){
    uint8_t has_string;
    size_t index = find_index_of_key(*chain, key, &has_string);
    if (has_string) {
        size_t length_for_string = strlen(value)+1;
        chain->data[index+1] = realloc(chain->data[index+1], length_for_string);
        memcpy(chain->data[index+1], value, length_for_string);
    }
    else{
        size_t length_for_string = strlen(key)+1;
        char* array = malloc(length_for_string);
        memcpy(array, key, length_for_string);
        dyn_array_append(chain, array);

        length_for_string = strlen(value)+1;
        array = malloc(length_for_string);
        memcpy(array, value, length_for_string);
        dyn_array_append(chain, array);
    }
}

char* str_hash_table_chain_get_pointer(str_hash_table_chain chain, char* key){
    uint8_t has_string;
    size_t index = find_index_of_key(chain, key, &has_string);
    if (has_string) {
        return chain.data[index+1];
    }
    return 0;
}

void str_hash_table_chain_delete(str_hash_table_chain chain, char* key){
    uint8_t has_string;
    size_t index = find_index_of_key(chain, key, &has_string);
    if (has_string) {
        free(chain.data[index]);
        free(chain.data[index+1]);
        uint8_t has_element;
        dyn_array_delete(&chain, index, &has_element);
        dyn_array_delete(&chain, index, &has_element);
    }
}

int main(){
    str_hash_table_chain chain = str_hash_table_chain_init();
    str_hash_table_chain_put(&chain, "shya", "sha");
    str_hash_table_chain_put(&chain, "shya", "shaka");
    str_hash_table_chain_delete(chain, "shya");
    printf("%s\n", str_hash_table_chain_get_pointer(chain, "shya"));
    return 0;
}