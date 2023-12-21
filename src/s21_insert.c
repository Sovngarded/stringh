#include "s21_string.h"
#include <stdlib.h>

void *s21_insert(const char *src, const char *str, s21_size_t start_index){
char *new_str = S21_NULL;
  if (src && str) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);
    s21_size_t new_len = src_len + str_len;
    if (start_index <= new_len) {
      new_str = malloc((new_len + 1) * sizeof(char));
      if (str == S21_NULL && start_index == 0) {
        s21_strcpy(new_str, src);
      } else {
        for (s21_size_t i = 0, m = 0, n = 0; i < new_len; i++) {
          if (i < start_index || i >= start_index + str_len) {
            new_str[i] = src[n];
            n++;
          } else {
            new_str[i] = str[m];
            m++;
          }
        }
      }
      new_str[new_len] = '\0';
    }
  } else if (str) {
    if ((int)s21_strlen(str) > 0) {
      new_str = malloc(s21_strlen(str) * sizeof(char));
      s21_strcpy(new_str, str);
    }
  }
  return new_str;
}