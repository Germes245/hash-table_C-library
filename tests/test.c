
#include <dyn_array_size_t.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef dyn_array_size_t hash_table_chain;

hash_table_chain hash_table_chain_init(){
    hash_table_chain array = dyn_array_size_t_init(0);
    /*for(size_t i = 0; i < length; i++){
        array.data[i]=0;
    }*/
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

size_t hash_table_chain_delete(hash_table_chain chain, uint8_t *error, size_t key){
    printf("\nhash_table_chain_delete\n");
    for(size_t i = 0; i < chain.length; i+=2){
        printf("index = %d\n", i);
        if(chain.data[i] == key){
            printf("ключ есть и его индекс: %d, а он сам: %d\n", i, chain.data[i]);
            *error = 0;
            printf("%d\n", *error);
            dyn_array_size_t_delete(&chain, i, error);
            printf("chain: ");
            for(size_t i = 0; i < chain.length; i++){
                printf("%d ", chain.data[i]);
            }
            putchar('\n');
            printf("%d\n", *error);
            printf("escape\n");
            return dyn_array_size_t_delete(&chain, i, error);
        }
    }
    *error = 1;
    printf("%d\n", *error);
    printf("escape\n\n");
    return 0;
}
//сутра сердца

int main(){
    hash_table_chain chain = hash_table_chain_init();
    hash_table_chain_put(&chain, 2, 6);
    uint8_t error;
    size_t number = hash_table_chain_get_number(chain, &error, 2);
    assert(error == 0 && number == 6);
    printf("chain: ");
    for(size_t i = 0; i < chain.length; i++){
        printf("%d ", chain.data[i]);
    }
    putchar('\n');
    number = hash_table_chain_delete(chain, &error, 2);
    printf("chain: ");
    for(size_t i = 0; i < chain.length; i++){
        printf("%d ", chain.data[i]);
    }
    putchar('\n');
    printf("error = %d and number = %ld\n", error, number);
    assert(error == 0 && number == 6);
    return 0;
}