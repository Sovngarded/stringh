#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *s = str1;
  const char *c;

  while (*str1) {
    for (c = str2; *c; c++) {
      if (*str1 == *c)
        break;
    }
    if (*c)
      break;
    str1++;
  }

  return str1 - s;
}