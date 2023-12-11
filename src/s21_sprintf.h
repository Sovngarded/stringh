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
    int for_size;  
} Options;

const char *set_options(Options *options, const char *format, va_list *arg);
const char *get_options(const char *format, Options *options);
const char *get_width(const char *format, int *width, va_list *arg);

#endif