#include "config.h"

typedef struct{
    TYPE_FOR_DICT key;
    TYPE_FOR_DICT value;
} dict_couple;

#define create_and_copy(destination, source) destination = malloc(strlen(source)+1);\
strcpy(destination, source)

dict_couple dict_couple_init(TYPE_FOR_DICT key, TYPE_FOR_DICT value);
void dict_couple_change_value(dict_couple couple, TYPE_FOR_DICT value);
void dict_couple_free(dict_couple *couple);