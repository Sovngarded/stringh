#include "s21_string.h"

char *s21_strtok(char *str, const char *delim){
  static char *token = S21_NULL;
    if (str != S21_NULL) {
        token = str;
    } else if (token == S21_NULL) {
        return S21_NULL;
    }
    char *address = token;
    while (*token != '\0') {
        int is_delimiter = 0;
        const char *d = delim;
        while (*d != '\0') {
            if (*token == *d) {
                is_delimiter = 1;
                break;
            }
            d++;
        }
        if (is_delimiter) {
            *token = '\0';
            token++;
            return address;
        }
        token++;
    }
    token = S21_NULL;
    return address;

}