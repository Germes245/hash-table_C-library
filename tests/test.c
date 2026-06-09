//void
//#include <dyn_array_int.h>
#include <dyn_array_size_t.h>
//#include <dyn_string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef dyn_array_size_t hash_table;

hash_table hash_table_init(size_t length){
    length*=2;
    hash_table array = dyn_array_size_t_init(length);
    for(size_t i = 0; i < length; i++){
        array.data[i]=0;
    }
    return array;    
}

void hash_table_put(hash_table *chain, size_t key, size_t value){
    dyn_array_size_t_append(chain, key);
    dyn_array_size_t_append(chain, value);
}

size_t hash_table_get_number(hash_table chain, uint8_t *error, size_t key){
    for(size_t i = 0; i < chain.length; i+=2){
        if(chain.data[i] == key){
            *error = 0;
            return chain.data[i+1];
        }
    }
    *error = 1;
}

int main(){
    hash_table chain = hash_table_init(5);
    hash_table_put(&chain, 2, 6);
    //hash_table_put(&chain, 2, 10);
    //hash_table_delete(chain, "shya");
    //printf("%d\n", hash_table_get_pointer(chain, "shya"));
    return 0;
}