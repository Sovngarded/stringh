#include "s21_string.h"

char *s21_strrchr(const char *str, int c){
    char *address = S21_NULL;
    char *first_byte = (char*) str;

    if(str!=S21_NULL){

        while(*str != '\0'){
            str++;
        }

        while (*str != *first_byte && *str != c) {
        str--;
        }

        if(*str == c){
            address = (char *)str;
        }



        




    }






    return address;
}