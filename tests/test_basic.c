#include "hash_table_manager.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main() {
    str_hash_table manager = str_hash_table_init(16);
    printf("init\n");
    //assert((size_t)(manager.array) != 0);
    
    // Вставка
    str_hash_table_put(manager, "key1", "value1");
    str_hash_table_put(manager, "key2", "value2");
    printf("вставка\n");
    
    // Поиск
    char* val = str_hash_table_get(manager, "key3");
    printf("get\n");
    printf("%d\n", val);
    
    // Удаление
    str_hash_table_delete(&manager, "key1");
    printf("delete\n");
    //printf("shya3\n");
    val = str_hash_table_get(manager, "key1");
    printf("get\n");
    //printf("shya4\n");
    printf("%d\n", val);
    //printf("shya\n");
    
    str_hash_table_free(&manager);
    printf("All tests passed!\n");
    return 0;
}