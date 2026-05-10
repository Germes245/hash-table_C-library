//void   
#include <dyn_array.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef dyn_array str_hash_table_chain;

str_hash_table_chain str_hash_table_chain_init(){
    return dyn_array_init(0);
}

void str_hash_table_chain_put(str_hash_table_chain *chain, char* key, char* value){
    size_t length_for_string = strlen(key)+1;
    char* array = malloc(length_for_string);
    memcpy(array, key, length_for_string);
    dyn_array_append(chain, array);

    length_for_string = strlen(value)+1;
    array = malloc(length_for_string);
    memcpy(array, value, length_for_string);
    dyn_array_append(chain, array);
}

char* str_hash_table_chain_get_pointer(str_hash_table_chain chain, char* key){
    for(size_t i = 0; i < chain.length; i+=2){
        if(strcmp(key, chain.data[i]) == 0) return chain.data[i+1];
    }
}

int main(){
    str_hash_table_chain chain = str_hash_table_chain_init();
    str_hash_table_chain_put(&chain, "shya", "sha");
    printf("%s\n", str_hash_table_chain_get_pointer(chain, "shya"));
    return 0;
}