//void
#include <dyn_array_int.h>
#include <dyn_array_size_t.h>
//#include <dyn_string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef dyn_array_size_t str_hash_table_chain;

str_hash_table_chain str_hash_table_chain_init(size_t length){
    length*=2;
    str_hash_table_chain array = dyn_array_size_t_init(length);
    for(size_t i = 0; i < length; i++){
        array.data[i]=0;
    }
    return array;    
}



int main(){
    str_hash_table_chain chain = str_hash_table_chain_init(5);
    //str_hash_table_chain_put(&chain, 2, 6);
    //str_hash_table_chain_put(&chain, 2, 10);
    //str_hash_table_chain_delete(chain, "shya");
    //printf("%s\n", str_hash_table_chain_get_pointer(chain, "shya"));
    return 0;
}