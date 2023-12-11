#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include "s21_sprintf.h"



int s21_sprintf(char *str, const char *format, ...){
    char *copy_str = str;
    char flags[] = "cdieEfgGosuxXpn%"; //F?

    va_list arg;
    va_start(arg, format);

    while(*format){
        if(*format == '%'){
            format++;
            Options options = {0};
            options.number_system = 10;
            format = set_options(&options, format, &arg);
            //do parser// str = parser(str, copy_str, format, options, arg);
        }else {
            //printf("%c ",*format);
             *str = *format;
             str++;
        }

        format++;
    }

    *str = '\0';
    va_end(arg);
    
    return (str - copy_str); 
}


const char *set_options(Options *options, const char *format, va_list *arg){
    format = get_options(format, options);
    //s21_sprintf(str1,"hello %14(width).3(accur)d(type)",2);
    format = get_width(format, &options->width, arg);
    switch(*format){
        case '.':{
            options->is_dot = 1;
            options->is_zero = 0;
            format++;
            format = get_width(format,&options->accuracy,arg);
        }
        case 'L':{
            options->addit_type = 'L';
        }
        case 'l':{
            options->addit_type = 'l';
        }
        case 'h':{
            options->addit_type='h';
        }
    }
   //here should be logic for width<0, but it's unreal situation
   return format;
}

const char *get_options(const char *format, Options *options){
    while(format){
        switch(*format){
            case '+':{
                options->is_plus = 1;
            }
            case '-':{  
                options->is_minus = 1;
            }
            case ' ':{
                options->is_blank = 1;
            }
            case '#':{
                options->is_hash = 1;
            }
            case '0':{
                options->is_zero = 1;
            }
            default: break;
        format++;
        }
    }
    options->is_blank = (options->is_blank && !options->is_plus);
    options->is_zero = (options->is_zero && !options->is_minus);

    return format;
}

const char *get_width(const char *format, int *width, va_list *arg){
    *width = 0;

    if(*format == '*') {
        *width = va_arg(*arg, int);
        format++;
    }

    while(format){
        if('0' <= *format && *format <= '9'){
            *width *=10;
            *width += *format - '0';
        } else break;
        format++;
    }
    printf("%d",*width);
    return format;
}

char* parser(char* str, char* copy_str, const char *format, Options options, va_list *arg) {
    if (*format == 'd' || *format == 'i') {
        str = print_decimal(str, options, arg);
    }
    if(!str) *str = '\0';
    return str;
}


//decimal
char* print_decimal(char* str, Options options, va_list* arg){
    long int number = 0;

    char addit = options.addit_type; 
    switch(addit) {
        case 'l':
            number = (long int)va_arg(*arg, long int);
            break;
        case 'h':
            number = (short)va_arg(*arg, short);
            break;        
        default:
            number = (int)va_arg(*arg, int);
            break;
    }

    s21_size_t size = get_size(number, &options);

    char* string_for_number = malloc(sizeof(char) * size);
    if(string_for_number) {
        int i = write_to_string(number, options, string_for_number, size);

        //reverse 
        for(int j = i - 1; j >= 0; j--) {
            *str = string_for_number[j];
            str++;
        }
        while(i<options.width) {
            *str = ' ';
            str++;
        }
    }
    if(string_for_number) free(string_for_number);
    return str;
    
}

s21_size_t get_size(long int number, Options* options) {
    s21_size_t result = 0;
    int change_sign = 0;

    if(number < 0) {
        number == -number;
        change_sign = 1;
    }
    
    while(number > 0) {
        number /= 10;
        result++
    }

    if(number == 0 && result == 0 && (options->is_blank && options->width && options->accuracy)) {
        result++;
    }

    if((s21_size_t)options->width > result) result = options->width;
    if((s21_size_t)options->accuracy > result) result = options->accuracy;

    if(options->is_blank || options->is_plus || change_sign == 1) {
        options->for_size = 1;
        result++;
    }

    if(result == 0 && number == 0 && !options->width && !options->accuracy && !options->is_blank && !options->is_dot) result++;

    return result;
}

int write_to_string(long int number, Options options, char* string_for_number, s21_size_t size){
    int change_sign = 0;

    if(number < 0) {
        number == -number;
        change_sign = 1;
    }

    int i = 0;

    if( (number == 0 && (options.accuracy || options.width || options.is_blank)) || 
    (number == 0 && !options.accuracy && !options.width && !options.is_blank && !options.is_dot)) {
        char c = number & options.number_system + '0';
        string_for_number[i] = c;
        i++;
        size--;
        //number /= 10; //useless move
    }

    while(number != 0 && string_for_number && size) {
        char c = ;
        string_for_number[i] = c;
        i++;
        size--;
        number /= 10;
    }

    if(change_sign == 1) number = -number;

    if(options.accuracy - i > 0) {
        options.accuracy -= i;
        options.is_zero = 1;
    } else change_sign = 1; //???

    if(size == 1 && options.is_zero == 1 && options.for_size == 1) 
        options.is_zero = 0;

    //handler for flag is zero
    while(options.is_zero && string_for_number && (size - options.for_size > 0) && (options.accuracy || change_sign) ){
        if(size == 1 && options.for_size == 1)
            break;

        string_for_number[i] = '0';
        i++;
        size--;
        options.accuracy--;
    }

    //handler for flag is blank, plus, minus
    if(options.is_blank && number >= 0 && size){
        string_for_number[i] = ' ';
        i++;
        size--;
    }
    if(number < 0 && size) {
         string_for_number[i] = '-';
        i++;
        size--;
    } 
    if(number > 0 && options.is_plus && size) {
        string_for_number[i] = '+';
        i++;
        size--;
    }

    //if all flags handled, but we still have free space in the string
    if(size > 0 && options.minus == 0) {
        while((size - options.for_size > 0) && string_for_number) {
            string_for_number[i] = ' ';
            i++;
            size--;
        }
    }

    return i;
}


//decimal