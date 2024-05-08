#include "encrypt.h"
#include <string.h>

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

        case 'a': return "LMN";
        case 'b': return "JKL";
        case 'c': return "FGH";
        case 'd': return "BCD";
        case 'e': return "RST";
        case 'f': return "OPQ";
        case 'g': return "XYZ";
        case 'h': return "UVW";
        case 'i': return "NOP";
        case 'j': return "MNO";
        case 'k': return "HIJ";
        case 'l': return "EFG";
        case 'm': return "WXY";
        case 'n': return "KLM";
        case 'o': return "ABC";
        case 'p': return "QRS";
        case 'q': return "TUV";
        case 'r': return "STU";
        case 's': return "UVW";
        case 't': return "YZA";
        case 'u': return "BCD";
        case 'v': return "CDE";
        case 'w': return "FGH";
        case 'x': return "IJK";
        case 'y': return "LMN";
        case 'z': return "OPQ";

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
