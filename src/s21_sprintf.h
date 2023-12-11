#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H
#include <stdarg.h>

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
} Options;

const char *set_options(Options *options, const char *format, va_list *arg);
const char *get_options(const char *format, Options *options);
const char *get_width(const char *format, int *width, va_list *arg);
Options set_number_system(Options options, char format);
char *print_u(char *str, Options options, char format, va_list *arg);
int unsigned_decimal_to_string(char *str_buff,Options options, unsigned long int buff, s21_size_t size_num);
char *print_c(char *str, Options options, int symbol);

#endif