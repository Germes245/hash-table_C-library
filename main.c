#include "hash_table_manager/hash_table_manager.h"
#include <stdio.h>

int main(){
    dict hash_table = dict_init(3);
    //dict_put(hash_table, "basa", "aaa");
    for(size_t j = 0; j < 3; j++){
        print_dict_chain(hash_table.array[j])
        putchar('\n');
    }
    //printf(dict_get(hash_table, "basa"));
    //dict_delete(&hash_table, "basa");
    /*for(size_t j = 0; j < 5; j++){
        print_dict_chain(hash_table.array[j])
        putchar('\n');
    }*/
    dict_free(&hash_table);
    return 0;
}