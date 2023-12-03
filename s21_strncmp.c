#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
    int result = 0;



    if(str1 != S21_NULL || str2 != S21_NULL){
    for(s21_size_t i =0;i<n;i++){
    
      while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }


    }
    result = (*str1 - *str2);

    }
    return result;
}