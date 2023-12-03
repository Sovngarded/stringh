#include "s21_string.h"

char *s21_strtok(char *str, const char *delim){
    static char* last_token = NULL;
    char* token_start;

    if (str != NULL) {
        last_token = str;
    } else if (last_token == NULL || *last_token == '\0') {
        return NULL;
    }

    while (*last_token != '\0' && s21_strchr(delim, *last_token) != NULL) {
        last_token++;
    }

    if (*last_token == '\0') {
        last_token = NULL;
        return NULL;
    }

    token_start = last_token;

    while (*last_token != '\0' && s21_strchr(delim, *last_token) == NULL) {
        last_token++;
    }

    if (*last_token != '\0') {
        *last_token = '\0';
        last_token++;
    }

    return token_start;
}