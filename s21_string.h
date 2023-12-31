#ifndef S21_STRING_H
#define S21_STRING_H


typedef unsigned long s21_size_t;
#define S21_NULL (void *)0

void *s21_memchr(const void *str, int c, s21_size_t n);

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);  

void *s21_memcpy(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);  

char *s21_strncat(char *dest, const char *src, s21_size_t n);

char *s21_strchr(const char *str, int c);  

int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strcspn(const char *str1, const char *str2);

char *strerror(int errnum);  // in progress 

s21_size_t s21_strlen(const char *str);

char *strpbrk(const char *str1, const char *str2);  // in progress 

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);

char *s21_strtok(char *str, const char *delim);

#endif
