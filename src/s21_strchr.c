#include "s21_string.h"

char* s21_strchr(const char* str, int c) {
    while (*str != '\0') {
        if (*str == (char)c) {
            return (char*)str;
        }
        str++;
    } 
    if(*str == '\0') {
        if (*str == (char)c) {
            return (char*)str;
        }
    }
    return S21_NULL;
}
