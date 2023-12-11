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


Options set_number_system(Options options, char format){
    switch(format){
        case 'o': options.number_system = 8;
        case 'x':options.number_system = 16;
        case 'X':{options.number_system = 16; options.upper_case = 1;}
        return options;
    }
}

char *print_u(char *str, Options options, char format, va_list *arg){
    unsigned long int buff =0;
    if(format == 'l') buff = (unsigned long int)va_arg(*arg,unsigned long int);
    else if(format == 'h') buff = (unsigned short int)va_arg(*arg,unsigned short int);
    else buff = (unsigned int)va_arg(*arg,unsigned int);


    s21_size_t size_num = get_size_unsigned_decimal(options,buff);
    char *str_buff = malloc(sizeof(char)*size_num);

    if(str_buff){
        int i  = unsigned_decimal_to_string(str_buff,options,buff,size_num);
        for(int j = i - 1; j>=0;j--){
            *str = str_num([j]);
            str++;
        }
        while(i < options.width){
            *str = ' ';
            str++;
        }
        
    }

    if(str_buff) free(str_buff);


    return str;
}

// WTF IS SIZE_TO_DECIMAL?????????
int unsigned_decimal_to_string(char *str_buff,Options options, unsigned long int buff, s21_size_t size_num){
    int i = 0, flag =0;
    unsigned long int copy_buff = buff;


    // ********************************************************************** //
    if((options.is_hash && options.number_system == 8)) options.flag_size = 1;
    else if (options.is_hash && options.number_system == 16) options.flag_size = 2;


    // ********************************************************************** //

    while (copy_buff && size_num 
    //&& size_decimal//
    )
    {
       char sym = get_num_char(copy_buff % options.number_system, options.upper_case);
       size_num[i] = sym;
        i++;
        size_num--;
        copy_buff /= 10;
    }
    if(flag) buff = -buff;
    if(options.accuracy - i > 0){
        options.accuracy -=1;
        options.is_zero = 1;
    }else flag = 1;

    if(size_decimal == 1 && options.is_zero == 1 && options.flag_size = 1) options.is_zero = 0;



    // ********************************************************************** //
    if(options.is_hash && options.number_system == 8){
        str_buff[i] = '0';
        i++;
        size_num--;
    } else if (options.is_hash && options.number_system == 16 && options.upper_case){
        str_buff[i] = 'X';
        i++;
        size_num--;
        str_buff='0';
        i++;
        size_num--;
    }else if (options.is_hash && options.number_system == 16 && !options.upper_case){
        str_buff[i] = 'x';
        i++;
        size_num--;
        str_buff[i] = '0';
        i++;
        size_num--;
    }

    // ********************************************************************** //

    // if(size_num > 0 && options.is_minus == 0){
        // while((size_decimal - options.flag_size >0) && str_num){
        //     str_num[i] = ' ';
        //     i++;
        //     size_decimal--;
        // }
    // }


    return i;

}