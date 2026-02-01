#include <stdio.h>

static unsigned char strcmp_(char first[], char second[]){ // если строки равны, то 1, иначе 0
    while(*first != 0 || *second != 0){
        if(*first != *second) return 0;
        first++;
        second++;
    }
    if(*first == *second) return 1;
    return 0;
}

static unsigned char dict_chain_has_couple_with_key(dict_chain *chain, char key[]){ //если есть, то 1, иначе 0
    for(size_t i = 0; i < chain->length; i++){
        if(strcmp_(chain->array[i].key,key)) return 1;
    }
    return 0;
}

int main(){
    printf("%d", strcmp_("ha","ha"));
    return 0;
}