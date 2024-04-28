#include "serial_number.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

char* get_usb_serial_number() {
    const char *command = "wmic diskdrive where \"MediaType='Removable Media'\" get SerialNumber";
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error executing WMIC command");
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    char* serial_number = (char*)malloc(BUFFER_SIZE);
    if (!serial_number) {
        perror("Error allocating memory for serial number");
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
        perror("Error closing WMIC process");
        free(serial_number);
        return NULL;
    }

    return serial_number;
}
