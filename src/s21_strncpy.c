#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  // 0
  //  size_t i;
  //  for (i = 0; i < n && src[i] != '\0'; i++)
  //      dest[i] = src[i];
  //  for ( ; i < n; i++)
  //      dest[i] = '\0';
  //  return dest;

  // 2
  // s21_size_t i;
  // for (i = 0; i < n && src[i] != '\0'; i++)
  //     dest[i] = src[i];
  // dest[i] = '\0';
  // return dest;

  // 1
  // char* output = dest;
  // while (n > 0) {
  //     if (*src != '\0') {
  //         *dest = *src;
  //         src++;
  //     } else {
  //         *dest = 'x';
  //     }
  //     dest++;
  //     n--;
  // }
  // *output = '\0';
  // return output;

  // 4
  s21_size_t i = 0;
  for (i = 0; i < n; i++) {
    if (src[i] != '\0') {
      dest[i] = src[i];
    } else {
      dest[i] = '\0';
    }
  }
  return dest;
}