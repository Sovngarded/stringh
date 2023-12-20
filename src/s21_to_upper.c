#include "s21_string.h"
#include <stdlib.h>

void *s21_to_upper(const char *str){
  char *str_copy = S21_NULL;
  if (str != S21_NULL) {
    int len = s21_strlen(str);
    str_copy = malloc(sizeof(char) * (len + 1));
    if (str_copy) {
      for (int i = 0; i <= len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          str_copy[i] = (str[i] - 'a') + 'A';
        } else {
          str_copy[i] = str[i];
        }
      }
      str_copy[len] = '\0';
    }
  }
  return str_copy;





}