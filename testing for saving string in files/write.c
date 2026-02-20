#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main() {
    char *text[] = {"om namah shivaya", "om mani padme hum"};
    FILE *file = fopen("test.bin", "wb");
    if (file == NULL) {
        perror("Ошибка открытия");
        return 1;
    }
    for(uint8_t i = 0; i < sizeof(text)/sizeof(char*); i++){
        fwrite(text[i], sizeof(char), strlen(text[i])+1, file);
    }
    return 0;
}