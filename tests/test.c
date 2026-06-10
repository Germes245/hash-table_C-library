//void
//#include <dyn_array_int.h>
#include <dyn_array_size_t.h>
//#include <dyn_string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef dyn_array_size_t hash_table_chain;

hash_table_chain hash_table_chain_init(size_t length){
    length*=2;
    hash_table_chain array = dyn_array_size_t_init(length);
    for(size_t i = 0; i < length; i++){
        array.data[i]=0;
    }
    return array;    
}

void hash_table_chain_put(hash_table_chain *chain, size_t key, size_t value){
    dyn_array_size_t_append(chain, key);
    dyn_array_size_t_append(chain, value);
}

size_t hash_table_chain_get_number(hash_table_chain chain, uint8_t *error, size_t key){
    for(size_t i = 0; i < chain.length; i+=2){
        if(chain.data[i] == key){
            *error = 0;
            return chain.data[i+1];
        }
    }
    *error = 1;
    return 0;
}

size_t hash_table_chain_delete(hash_table_chain chain, size_t key);
сутра сердца

int main(){
    hash_table_chain chain = hash_table_chain_init(5);
    hash_table_chain_put(&chain, 2, 6);
    uint8_t error;
    size_t number = hash_table_chain_get_number(chain, &error, 2);
    assert(error == 0 && number == 6);
    return 0;
}