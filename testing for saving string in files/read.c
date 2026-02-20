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
    // ищет цифру в массиве. array -- массив, bytes -- размер массива в байтах, byte -- цифра, которую надо найти
    for(size_t i = 0; i < bytes; i++){
        if(array[i] == byte){
            return ++i; // если найдено значение, то индекс + 1
        }
    }
    return 0; // если не найдено, то ноль
}

typedef struct{
    char *string;
    size_t length;
    size_t number_of_element;
    char chars[6];
} readBytesFromFileResult;

#define chars_length 6

readBytesFromFileResult read_bytes_from_file(FILE *file){
    // читает файл и записывает строку до нулевого терминатора 
    readBytesFromFileResult result;
    size_t read = fread(result.chars, sizeof(char), sizeof(result.chars)/sizeof(char), file);
    result.number_of_element = contain(result.chars, read, 0);

    //чтение первый байтов текста
    if(result.number_of_element == 0){
        result.string = malloc(read); // выделение;
        memcpy(result.string, result.chars, read);
        result.length = read;
    }
    else{
        result.string = malloc(result.number_of_element); // выделение;
        memcpy(result.string, result.chars, result.number_of_element);
        result.length = result.number_of_element;
        goto adding_a_terminator;
    }

    while((read = fread(result.chars, sizeof(char), sizeof(result.chars)/sizeof(char), file)) != 0){
        result.number_of_element = contain(result.chars, read, 0);
        if(result.number_of_element == 0){
            size_t new_length = result.length+read;
            result.string = realloc(result.string, new_length); // выделение
            memcpy(result.string+result.length, result.chars, read);
            result.length = new_length;
        }
        else{
            size_t new_length = result.length+result.number_of_element;
            result.string = realloc(result.string, new_length); // выделение
            memcpy(result.string+result.length, result.chars, read);
            result.length = new_length;
            break;
        }
    }

    adding_a_terminator:

    result.string = realloc(result.string, result.length);
    result.string[result.length] = 0;
    result.length++;

    return result; // нужно будет сохранять указатель в отдельный массив указателей
}

int main() {
    FILE *file = fopen("test.bin", "rb");
    if (file == NULL) {
        perror("Ошибка открытия");
        return 1;
    }
    char **strings = malloc(2*sizeof(char*));

    readBytesFromFileResult result = read_bytes_from_file(file);
    //printf("%s\n%s\n",result.string, result.chars);
    //printf("%s. in end: %d\n",result.string, chars_length-result.number_of_element);
    //write(1, result.chars, chars_length);
    strings[0] = result.string;
    if(chars_length-result.number_of_element==1){
        
        result = read_bytes_from_file(file);
        printf("strings: %s, and %s", strings[0], result.string);
    }
    return 0;
}