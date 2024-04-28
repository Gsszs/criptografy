#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

char* get_usb_serial_number() {
    const char *command = "wmic diskdrive where \"MediaType='Removable Media'\" get SerialNumber";
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Erro ao executar comando WMIC");
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    char* serial_number = (char*)malloc(BUFFER_SIZE);
    if (!serial_number) {
        perror("Erro ao alocar memoria para o numero de serie");
        pclose(fp);
        return NULL;
    }

    int first_line = 1;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (first_line) {
            first_line = 0;
            continue;
        }

        char *start = buffer;
        while (*start == ' ') {
            start++;
        }

        strcpy(serial_number, start);
        size_t len = strlen(serial_number);
        while (len > 0 && (serial_number[len - 1] == ' ' || serial_number[len - 1] == '\n')) {
            serial_number[len - 1] = '\0';
            len--;
        }

        break;
    }

    if (pclose(fp) == -1) {
        perror("Erro ao fechar o processo WMIC");
        free(serial_number);
        return NULL;
    }

    return serial_number;
}

const char* encrypt(char input) {
    switch (input) {
        case '0': return "@&$";
        case '1': return "#%*";
        case '2': return "^!()";
        case '3': return "89+";
        case '4': return "23_";
        case '5': return "45^";
        case '6': return "78@";
        case '7': return "!#";
        case '8': return ")(=";
        case '9': return "54&";

        case 'A': return "YD";
        case 'B': return "XT";
        case 'C': return "QW";
        case 'D': return "AO";
        case 'E': return "TY";
        case 'F': return "UI";
        case 'G': return "OP";
        case 'H': return "AS";
        case 'I': return "DF";
        case 'J': return "GH";
        case 'K': return "ZX";
        case 'L': return "CV";
        case 'M': return "KD";
        case 'N': return "QL";
        case 'O': return "TZ";
        case 'P': return "LK";
        case 'Q': return "JH";
        case 'R': return "NM";
        case 'S': return "BG";
        case 'T': return "QS";
        case 'U': return "XC";
        case 'V': return "VF";
        case 'W': return "DC";
        case 'X': return "ER";
        case 'Y': return "XA";
        case 'Z': return "TR";

        default: return "?";
    }
}

void remove_char(char* str, char to_remove) {
    int write_index = 0;
    for (int read_index = 0; read_index < strlen(str); read_index++) {
        if (str[read_index] != to_remove) {
            str[write_index++] = str[read_index];
        }
    }
    str[write_index] = '\0';
}

int main() {
    char* serial_number = get_usb_serial_number();

    if (serial_number) {
        system("cls");
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

    return 0;
}
