#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "../include/dict_couple.h"

dict_couple dict_couple_init(dict_value_t key, dict_value_t value){
    dict_couple couple;
    #if TYPE_FOR_DICT == TYPE_CHAR_P
        create_and_copy(couple.key, key);
        create_and_copy(couple.value, value);
    #elif TYPE_FOR_DICT == TYPE_INT
        couple.key = key;
        couple.value = value;
    #endif
    return couple;
}

#if TYPE_FOR_DICT == TYPE_CHAR_P

void dict_couple_change_value(dict_couple couple, dict_value_t value){
    free(couple.value);
    create_and_copy(couple.value, value);
}

void dict_couple_free(dict_couple *couple){
    free(couple->key);
    free(couple->value);
    couple->key = 0;
    couple->value = 0;
}

#elif TYPE_FOR_DICT == TYPE_INT

#define dict_couple_change_value(couple, value) {\
    couple.value = value\
}

#endif