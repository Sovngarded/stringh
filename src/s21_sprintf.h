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

int s21_sprintf(char *str, const char *format, ...); 
const char *set_options(Options *options, const char *format, va_list *arg); 
const char *get_options(const char *format, Options *options);
const char *get_width(const char *format, int *width, va_list *arg);
char* parser(char* str, char* copy_str, const char *format, Options options, va_list *arg);

char* print_decimal(char* str, Options options, va_list* arg);
s21_size_t get_size_decimal(long int number, Options* options);
int decimal_to_string(long int number, Options options, char* string_for_number, s21_size_t size);
char convert_num_to_char(int num, int upper_case);

Options set_number_system(Options options, char format);
s21_size_t get_size_unsigned_decimal(unsigned long int number, Options* options);
char *print_u(char *str, Options options, char format, va_list *arg);
int unsigned_decimal_to_string(char *str_buff,Options options, unsigned long int number, s21_size_t size);


char *print_c(char *str, Options options, int symbol);
char *print_s(char *str,Options options, va_list *arg);

Options set_opt_double(Options options, char format);
s21_size_t get_size_double(Options* options, long double number);
int double_to_string(long double number, Options options, char* string_for_number, s21_size_t size, int e);
char *print_double(char *str,Options options,char format, va_list *arg);

s21_size_t get_size_eg(Options* options, long double number);
Options shrtst(Options options, long double number);
long double normalize(long double *num,Options *options);
char* print_eg(char *str, Options options,char format, va_list *arg);

char* print_p(char* str, Options* options, va_list* arg);

#endif