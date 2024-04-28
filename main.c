#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modules/encrypt.h"
#include "modules/serial_number.h"

int main() {
    char* serial_number = get_usb_serial_number();

    if (serial_number) {
        printf("[+] Numero de serie do pendrive: %s\n", serial_number);
        printf("[+]\n");

        size_t serial_length = strlen(serial_number);
        size_t encrypted_size = serial_length * 3 + 1;

        char* encrypted = (char*)malloc(encrypted_size);
        if (!encrypted) {
            perror("Erro ao alocar memoria para a string criptografada");
            free(serial_number);
            return 1;
        }

        encrypted[0] = '\0';

        for (size_t i = 0; i < serial_length; i++) {
            const char* encrypted_char = encrypt(serial_number[i]);
            strcat(encrypted, encrypted_char);
        }

        remove_char(encrypted, '?');

        printf("[+] Numero de serie criptografado: %s\n\n", encrypted);

        free(encrypted);
        free(serial_number);
    } else {
        printf("Erro ao obter o numero de serie.\n");
    }

    system("pause");

    return 0;
}
