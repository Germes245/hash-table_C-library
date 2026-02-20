#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*size_t contain(char *array, size_t bytes, char byte, size_t *i){
    for(*i = 0; *i < bytes; *i++){
        if(array[*i] == byte){
            return 1;
        }
    }
    return 0;
}*/

size_t contain(char array[], size_t bytes, char byte){
    for(size_t i = 0; i < bytes; i++){
        if(array[i] == byte){
            return ++i; // если найдено значение, то индекс + 1
        }
    }
    return 0; // если не найдено, то ноль
}

int main() {
    FILE *file = fopen("test.bin", "rb");
    if (file == NULL) {
        perror("Ошибка открытия");
        return 1;
    }
    char chars[6];
    size_t read = fread(chars, sizeof(char), sizeof(chars)/sizeof(char), file);
    size_t number_of_element = contain(chars, read, 0);
    size_t length = read;
    //printf("%d", number_of_element);
    char *string;
    if(number_of_element == 0){
        string = malloc(read); // выделение;
        memcpy(string, chars, read);
        write(1, string, read);
        //printf("ff");
    }
    else{
        string = malloc(number_of_element); // выделение;
        memcpy(string, chars, number_of_element);
        write(1, string, number_of_element);
    }
    /*while((read = fread(chars, sizeof(char), sizeof(chars)/sizeof(char), file)) != 0){
        //printf("%d\n", read);
        for(uint8_t i = 0; i < read; i++){
            printf("%d ", chars[i]);
            //putchar(chars[i]);
        }
        //putchar('\n');
        index = contain(chars, read, 0);
        if(index == 0){
            string = malloc(read); // выделение
            memcpy(string, chars, read);
            write(1, string, read);
        }
        else{

        }
    }*/
    free(string);
    return 0;
}