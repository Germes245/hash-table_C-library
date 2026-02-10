typedef struct{
    int key;
    int value;
} dict_couple;

dict_couple dict_couple_init(int key, int value);
void dict_couple_change_value(dict_couple couple, int value[]);