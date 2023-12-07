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

    if(!str) *str = '\0';
    return str;
}