typedef struct{
    char *key;
    char *value;
} dict_couple;

#define create_and_copy(destination, source) destination = malloc(strlen(source)+1);\
strcpy(destination, source)

dict_couple dict_couple_init(char key[], char value[]);
void dict_couple_change_value(dict_couple couple, char value[]);
void dict_couple_free(dict_couple *couple);