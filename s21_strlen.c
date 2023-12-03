#include "s21_string.h"

s21_size_t s21_strlen(const char *str){
    s21_size_t length = -1;
    if(str!= S21_NULL){
        length = 0;
        while (str[length] != '\0') {
        length++;
    }

    }



    return length;
}