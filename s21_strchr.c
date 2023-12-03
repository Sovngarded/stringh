#include "s21_string.h"

char* s21_strchr(const char* str, int c) {
    while (*str) {
        if (*str == (char)c) {
            return (char*)str;
        }
        str++;
    } 
    return S21_NULL;
}
