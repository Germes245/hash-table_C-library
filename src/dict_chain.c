#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/dict_couple.h"

#define print_dict_chain(chain) {\
    printf("length: %ld. elements: ", chain.length);\
    for (size_t i = 0; i < chain.length; i++){\
        printf("(%s, %s), ", chain.array[i].key, chain.array[i].value);\
    }\
}

typedef struct{
    dict_couple *array;
    size_t length;
} dict_chain;

#if TYPE_FOR_DICT == TYPE_CHAR_P

static unsigned char strcmp_(char first[], char second[]){ // если строки равны, то 1, иначе 0
    while(*first != 0 || *second != 0){
        if(*first != *second) return 0;
        first++;
        second++;
    }
    if(*first == *second) return 1;
    return 0;
}

#define elcmp strcmp_

#elif TYPE_FOR_DICT == TYPE_INT

#define elcmp(a, b) ((a) == (b))

#endif

static void dict_chain_shift_left(dict_chain *chain, size_t index){
    while(index < chain->length-1){
        chain->array[index] = chain->array[index + 1];
        index++;
    }
}

static int dict_chain_has_couple_with_key(dict_chain *chain, dict_value_t key){ //если есть, то индекс структуры, иначе -1
    for(size_t i = 0; i < chain->length; i++){
        if(elcmp(chain->array[i].key,key)) return i;
    }
    return -1;
}

dict_chain dict_chain_init(){
    dict_chain chain;
    chain.array = 0;
    chain.length = 0;
    return chain;
}

void dict_chain_put(dict_chain *chain, dict_value_t key, dict_value_t value){
    if(chain->length){
        int index;
        if((index = dict_chain_has_couple_with_key(chain, key)) != -1){
            #if TYPE_FOR_DICT == TYPE_CHAR_P
            free(chain->array[index].value);
            #endif
            create_and_copy(chain->array[index].value, value);
        }
        else{
            chain->array = realloc(chain->array, (++chain->length)*sizeof(dict_chain));
            create_and_copy(chain->array[chain->length-1].key, key);
            create_and_copy(chain->array[chain->length-1].value, value);
        }
    }
    else{
        chain->array = malloc(sizeof(dict_couple));
        chain->length = 1;
        create_and_copy(chain->array[0].key, key);
        create_and_copy(chain->array[0].value, value);
    }
}

dict_value_t dict_chain_get(dict_chain chain, dict_value_t key){
    int index = dict_chain_has_couple_with_key(&chain, key);
    if(index == -1) return 0;
    return chain.array[index].value;
}

unsigned char dict_chain_delete(dict_chain *chain, dict_value_t key){
    int index = dict_chain_has_couple_with_key(chain, key);
    if(index == -1) return 0;
    #if TYPE_FOR_DICT == TYPE_CHAR_P
    dict_couple_free(&chain->array[index]);
    #endif
    dict_chain_shift_left(chain, index);
    chain->array = realloc(chain->array, (--chain->length)*sizeof(dict_couple));
    return 1;
}

void dict_chain_free(dict_chain *chain){
    #if TYPE_FOR_DICT == TYPE_CHAR_P
    for(size_t i = 0; i < chain->length; i++){
        dict_couple_free(&chain->array[i]);
    }
    #endif
    free(chain->array);
    chain->length = 0;
}