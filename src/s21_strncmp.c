#include "s21_string.h"
#include <stdio.h>


int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
    int result = 0;

<<<<<<< HEAD:s21_strncmp.c
    if(n != 0){
=======
    if (n == 0) return 0;
>>>>>>> lisichka:src/s21_strncmp.c
    if(str1 != S21_NULL || str2 != S21_NULL){
      for(s21_size_t i = 0;i<n-1;i++){
    //    printf("-%d-",i);
      if(*str1 != '\0' && *str2 != '\0' && *str1 == *str2){
       // printf("-%c-",*str2);
        str1++;
        str2++;
      }
    }

   // printf("\n %c - %c", *str1,*str2);

    result = (*str1 - *str2);
    // printf("\n %d \n",result);
    }
    }
    return result;
}