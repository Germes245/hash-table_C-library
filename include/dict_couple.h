typedef struct{
    char* value;
    char* key;
} dict_couple;

dict_couple dict_couple_init(char* key, char* value);

void dict_couple_change_value(dict_couple couple, char* value);
void dict_couple_free(dict_couple *couple);

#define create_and_copy(destination, source) destination = malloc(strlen(source)+1);\
strcpy(destination, source)