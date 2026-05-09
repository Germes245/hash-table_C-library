//void   
#include <dyn_array.h>
#include <stddef.h>

typedef dyn_array str_hash_table_chain;

str_hash_table_chain str_hash_table_chain_init(){
    return dyn_array_init(0);
}

void str_hash_table_chain_put(str_hash_table_chain *chain, char* key, char* value){
    
}

int main(){
    str_hash_table_chain chain = str_hash_table_chain_init();
    return 0;
}