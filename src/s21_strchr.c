#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  int i = 0;
  char *result = S21_NULL;
  while (str[i] && str[i] != c) {
    i++;
  }
  if (c == str[i]) {
    result = (char *)str + i;
  } else {
    result = S21_NULL;
  }
  return result;
}

// char *s21_strchr(const char *str, int c) {
//   char *result = S21_NULL;
//   while (*str != '\0' && result == S21_NULL) {
//     if (*str == (char)c) {
//       result = (char *)str;
//     }
//     str++;
//   }
//   if (*str == '\0' && result == S21_NULL) {
//     if (*str == (char)c) {
//       result = (char *)str;
//     }
//   }

//   return result;
// }

// char* s21_strchr(const char* str, int c) {
//     while (*str) {
//         if (*str == (char)c) {
//             return (char*)str;
//         }
//         str++;
//     } 
//     return S21_NULL;
// }
