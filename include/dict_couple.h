#include "config.h"

typedef struct{
    dict_value_t key;
    dict_value_t value;
} dict_couple;

dict_couple dict_couple_init(dict_value_t key, dict_value_t value);

#if TYPE_FOR_DICT == TYPE_CHAR_P

void dict_couple_change_value(dict_couple couple, dict_value_t value);
void dict_couple_free(dict_couple *couple);

#define create_and_copy(destination, source) destination = malloc(strlen(source)+1);\
strcpy(destination, source)

#elif TYPE_FOR_DICT == TYPE_INT

#define dict_couple_change_value(couple, value_) couple.value = value_

#define create_and_copy(destination, source) destination = source

#endif
