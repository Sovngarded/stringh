#include "s21_string.h"
#include <string.h>

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *address = S21_NULL;

  if (dest != S21_NULL || src != S21_NULL) {
    address = dest;

    while (*dest != '\0') {
      dest++;
    }

    for (s21_size_t i = 0; i < n; i++) {
      if (*src == '\0') {
        i = n + 1;
      }
      *dest = *src;
      dest++;
      src++;
    }
    *dest = '\0';
  }

  return address;
}