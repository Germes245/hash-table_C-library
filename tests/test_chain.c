#include <hash_table_chain.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

static size_t str_hash_table_chain_has_couple_with_key(str_hash_table_chain *chain, char* key){ //если есть, то индекс структуры, иначе 0
    for(size_t i = 0; i < chain->length; i++){
        printf("string: %s, and %s\n", chain->array[i].key, key);
        if(strcmp(chain->array[i].key,key) == 0) return i+1;
    }
    return 0;
}

int main(){
    str_hash_table_chain chain = str_hash_table_chain_init();

    assert((size_t)chain.array == 0);
    assert(chain.length == 0);

    str_hash_table_chain_put(&chain, "key1", "value1");
    assert(chain.length == 1);

    str_hash_table_chain_put(&chain, "key2", "value2");
    assert(chain.length == 2);

    char* val = str_hash_table_chain_get(chain, "key2");
    assert(val != 0);

    printf("%d\n", str_hash_table_chain_has_couple_with_key(&chain, "key1"));
    str_hash_table_chain_delete(&chain, "key1");
    return 0;
}