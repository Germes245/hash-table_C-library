#include <hash_table_chain.h>
#include <stdio.h>

int main(){
    str_hash_table_chain chain = str_hash_table_chain_init();

    str_hash_table_chain_put(&chain, "key1", "value1");
    printf("%d\n", chain.length);
    str_hash_table_chain_put(&chain, "key2", "value2");

    printf("%d\n", chain.length);
    char* val = str_hash_table_chain_get(chain, "key2");
    printf("%s\n", val);
    /*str_hash_table_chain_delete(&chain, "key1");
    val = str_hash_table_chain_get(chain, "key1");
    str_hash_table_chain_free(&chain);*/
    return 0;
}