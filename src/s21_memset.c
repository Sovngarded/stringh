#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *string = str;

  while (n > 0) {
    *string = (unsigned char)c;
    string++;
    n--;
  }
  return str;
}
