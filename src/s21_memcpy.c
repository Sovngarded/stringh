#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n){
    unsigned char *buffer_src = (unsigned char*)src; 
    unsigned char *buffer_dest = (unsigned char*)dest;
    unsigned char *address = S21_NULL;

    if(dest != S21_NULL || src != S21_NULL){
        address = buffer_dest;
        for(s21_size_t i = 0; i<n; i++) { 
            *buffer_dest = *buffer_src;
            buffer_dest++;
            buffer_src++;
        }
    }
    return address;
}