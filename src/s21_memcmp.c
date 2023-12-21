#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  // int result = 0;
  const char *first = str1;
  const char *second = str2;
  while (n > 0) {
    if (*first != *second) {
      return *first - *second;
    }
    first++;
    second++;
    n--;
  }
  return 0;
}