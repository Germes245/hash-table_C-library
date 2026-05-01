#include <hash_table_chain.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(){
    str_hash_table_chain chain = str_hash_table_chain_init();

    assert((size_t)chain.array == 0);
    assert(chain.length == 0);

    str_hash_table_chain_put(&chain, "key1", "value1");
    assert(chain.length == 1 && strcmp(chain.array[0].key, "key1") == 0);

    str_hash_table_chain_put(&chain, "key2", "value2");
    assert(chain.length == 2 && strcmp(chain.array[1].key, "key2") == 0);

    //size_t index = str_hash_table_chain_has_couple_with_key(&chain, "key2");
    char* val = str_hash_table_chain_get(chain, "key1");
    //printf("%d\n", index);
    assert(val != 0);

    //printf("%d\n", str_hash_table_chain_has_couple_with_key(&chain, "key1"));
    str_hash_table_chain_delete(&chain, "key1");

    val = str_hash_table_chain_get(chain, "key1");

    assert(val == 0);

    str_hash_table_chain_free(&chain);
    return 0;
}