#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <stdarg.h>
#include "s21_string.h"

typedef struct 
{
    int is_minus;
    int is_plus;
    int is_blank;
    int is_hash;
    int is_zero;
    int is_dot;
    int width;
    int accuracy;
    int number_system;
    char addit_type;    
    int upper_case;
    int flag_size;
    int g;
    int e;
} Options;

const char *set_options(Options *options, const char *format, va_list *arg);
const char *get_options(const char *format, Options *options);
const char *get_width(const char *format, int *width, va_list *arg);
Options set_number_system(Options options, char format);
char *print_u(char *str, Options options, char format, va_list *arg);
int unsigned_decimal_to_string(char *str_buff,Options options, unsigned long int buff, s21_size_t size_num);
char* print_decimal(char* str, Options options, va_list* arg);
s21_size_t get_size(long int number, Options* options);
int write_to_string(long int number, Options options, char* string_for_number, s21_size_t size);
char* parser(char* str, char* copy_str, const char *format, Options options, va_list *arg);
char convert_num_to_char(int num, int upper_case);
char *print_c(char *str, Options options, int symbol);
char *print_s(char *str,Options options, va_list *arg);
Options set_opt_double(Options options, char format);
char *print_double(char *str,Options options,char format, va_list *arg);
long double normalize(long double *num,Options *options);

#endif