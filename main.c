#include "../include/hash_table_manager.h"
#include <stdio.h>

int main(){
    dict my_dict = dict_init(5);
    dict_put(my_dict, 10, 5);
    dict_put(my_dict, 30, 5);
    printf("%d", dict_get(my_dict, 9).error);
    dict_free(&my_dict);
    //dict_free(&my_dict);
    //printf(dict_get(my_dict, "key"));
    return 0;
}