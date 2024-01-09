#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = S21_NULL;
  s21_size_t len = s21_strlen(str2);
  while (*str1 && !result) {
    for (s21_size_t i = 0; i < len && !result; i++) {
      if (*str1 == str2[i]) {
        result = (char *)str1;
      }
    }
    str1++;
  }
  return result;
}