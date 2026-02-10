#include "../include/dict_couple.h"

dict_couple dict_couple_init(int key, int value){
    dict_couple couple;
    couple.key = key;
    couple.value = value;
    return couple;
}