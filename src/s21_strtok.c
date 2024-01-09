#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = S21_NULL;
  char *token_start = S21_NULL;

  if (str != S21_NULL) {
    last_token = str;
  } else if (last_token == S21_NULL || *last_token == '\0') {
    return S21_NULL;
  }

  while (*last_token != '\0' && s21_strchr(delim, *last_token) != S21_NULL) {
    last_token++;
  }

  if (*last_token == '\0') {
    last_token = S21_NULL;
    return S21_NULL;
  }

  token_start = last_token;

  while (*last_token != '\0' && s21_strchr(delim, *last_token) == S21_NULL) {
    last_token++;
  }

  if (*last_token != '\0') {
    *last_token = '\0';
    last_token++;
  }

  return token_start;
}