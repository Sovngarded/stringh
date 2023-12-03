#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n){
    unsigned char *buffer = (unsigned char*)str; 
    unsigned char *address = S21_NULL;

    for(s21_size_t i = 0;i<n;i++){
        if(*buffer == c){
            address = buffer;
            i = n+1;
        }
        buffer++;
    }
    

    return address;
}