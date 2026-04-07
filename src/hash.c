#include <stddef.h>

size_t hash_func(unsigned char* text){
    size_t hash_value = 0;
    while((*text) != 0){
        hash_value = (hash_value * 31 + (*text)) % 1000000007;
        text++;
    }
    return hash_value;
}