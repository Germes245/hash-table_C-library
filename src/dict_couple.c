#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "dict_couple.h"

dict_couple dict_couple_init(char key[], char value[]){
    dict_couple couple;
    create_and_copy(couple.key, key);
    create_and_copy(couple.value, value);
    return couple;
}

void dict_couple_change_value(dict_couple couple, char value[]){
    free(couple.value);
    create_and_copy(couple.value, value);
}

void dict_couple_free(dict_couple *couple){
    free(couple->key);
    free(couple->value);
    couple->key = 0;
    couple->value = 0;
}