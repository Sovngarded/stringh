#include "s21_sprintf.h"
#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define ALPHABET 32 


int s21_sprintf(char *str, const char *format, ...){
    char *copy_str = str;
    char flags[] = "cdieEfgGosuxXpn%"; //F?

    va_list arg;
    va_start(arg, format);

    while(*format){
        if(*format == '%') {
            format++;
            Options options = {0};
            options.number_system = 10;
            format = set_options(&options, format, &arg);
            str = parser(str, copy_str, format, options, &arg);
        } else {
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
    format = get_width(format, &options->width, arg);

    if(*format == '.') {
        options->is_dot = 1;    
        options->is_zero = 0;
        format++;
        format = get_width(format,&options->accuracy,arg);
    } 
    if(*format == 'L') {
        options->addit_type = 'L';
    } else if (*format == 'l') {
        options->addit_type = 'l';
    }  else if (*format == 'h') {
        options->addit_type = 'h';
    } 
    if (options->addit_type != 0) format++;
   
   //here should be logic for width<0, but it's unreal situation
   return format;
}

const char *get_options(const char *format, Options *options){
    int flag = 0;
    while(format){
        switch(*format){
            case '+':{
                options->is_plus = 1;
                break;
            }
            case '-':{  
                options->is_minus = 1;
                break;
            }
            case ' ':{
                options->is_blank = 1;
                break;
            }
            case '#':{
                options->is_hash = 1;
                break;
            }
            case '0':{
                options->is_zero = 1;
                break;
            }
            default: {
                flag = 1; 
                break;
            }
        }
        if(flag == 1) break;
        format++;
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
    return format;
}

char* parser(char* str, char* copy_str, const char *format, Options options, va_list *arg) {
    if (*format == 'd' || *format == 'i') {
        str = print_decimal(str, options, arg);
    } 
    else if (*format == 'u' || *format == 'o' || *format == 'x' || *format == 'X') {
        options = set_number_system(options, *format);
        str = print_u(str, options, *(format-1), arg);
        char* print_u(char *str, Options options, char format, va_list *arg)
    }
    else if(*format == 'c'){
        int symbol = va_arg(*arg, int);
        str = print_c(str, options, symbol);
    } 
    // else if (*format == 'p') {
    //     str = print_p(str, &options, arg);
    // }
    else if(*format == '%'){
        str = print_c(str,options,'%');
    } else if(*format == 's') {
        str = print_s(str,options,arg);
    } else if(*format == 'n'){
        int *n = va_arg(*arg,int *);
        *n = (int)(str - copy_str);
    }
    if(!str) *str = '\0';
    return str;
}


//decimal
s21_size_t get_size_decimal(long int number, Options* options) {
    s21_size_t result = 0;
    long int copy_num = number;

    if(copy_num < 0) {
        copy_num = -number;
    }
    
    while(copy_num > 0) {
        copy_num /= 10;
        result++;
    }

    if(copy_num == 0 && result == 0 && (options->is_blank && options->width && options->accuracy)) {
        result++;
    }

    if((s21_size_t)options->width > result) result = options->width;
    if((s21_size_t)options->accuracy > result) result = options->accuracy;

    if(options->is_blank || options->is_plus || number < 0) {
        options->flag_size = 1;
        result++;
    }

    if(result == 0 && copy_num == 0 && !options->width && !options->accuracy && !options->is_blank && !options->is_dot) result++;

    return result;
}

int write_to_string(long int number, Options options, char* string_for_number, s21_size_t size){
    int change_sign = 0;

    if(number < 0) {
        change_sign = 1;
        number = -number;
    }

    int i = 0;
    long int number_copy = number;

    if( (number_copy == 0 && (options.accuracy || options.width || options.is_blank)) || 
    (number_copy == 0 && !options.accuracy && !options.width && !options.is_blank && !options.is_dot)) {
        char c = convert_num_to_char(number_copy % options.number_system, options.upper_case);
        string_for_number[i] = c;
        i++;
        size--;
    }

    while(number_copy != 0 && string_for_number && size) {
        char c = convert_num_to_char(number_copy % options.number_system, options.upper_case);
        string_for_number[i] = c;
        i++;
        size--;
        number_copy /= 10;
    }

    if(change_sign == 1) number = -number;

    if(options.accuracy - i > 0) {
        options.accuracy -= i;
        options.is_zero = 1;
    } else change_sign = 1; //???

    if(size == 1 && options.is_zero == 1 && options.flag_size == 1) 
        options.is_zero = 0;

    //handler for flag is zero
    while(options.is_zero && string_for_number && (size - options.flag_size > 0) && (options.accuracy || change_sign) ){
        if(size == 1 && options.flag_size == 1)
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
    if(size > 0 && options.is_minus == 0) {
        while((size - options.flag_size > 0) && string_for_number) {
            string_for_number[i] = ' ';
            i++;
            size--;
        }
    }

    return i;
}

char* print_decimal(char* str, Options options, va_list* arg){
    long int number = 0;

    char addit = options.addit_type; 
    switch(addit) {
        case 'l':
            number = (long int)va_arg(*arg, long int);
            break;
        // case 'h':
        //     number = (short)va_arg(*arg, short);
        //     break;        
        default:
            number = (int)va_arg(*arg, int);
            break;
    }

    s21_size_t size = get_size_decimal(number, &options);
    char* string_for_number = malloc(sizeof(char) * size);

    if(string_for_number) {
        int i = write_to_string(number, options, string_for_number, size);

        //reverse 
        for(int j = i - 1; j >= 0; j--) {
            *str = string_for_number[j];
            str++;
        }
        while(i < options.width) {
            *str = ' ';
            str++;
        }
    }
    if(string_for_number) free(string_for_number);
 
    return str;
}
//end decimal

char convert_num_to_char(int num, int upper_case) {
    char flag = '0';
    switch(num){
        case 10:
            flag = (char)('a'- upper_case * ALPHABET);
            break;
        case 11:
            flag = (char)('b'- upper_case * ALPHABET);
            break;
        case 12:
            flag = (char)('c'- upper_case * ALPHABET);
            break;        
        case 13:
            flag = (char)('d'- upper_case * ALPHABET);
            break;       
        case 14:
            flag = (char)('e'- upper_case * ALPHABET);
            break;
        case 15:
            flag = (char)('f'- upper_case * ALPHABET);
            break;
    }

    if (0 <= num && num <= 9) flag = (char) (num + '0');

    return flag;

}

//unsingned + x, o, 
Options set_number_system(Options options, char format){
    switch(format){
        case 'o': {
            options.number_system = 8;
            break;
        }
        case 'x': {
            options.number_system = 16;
            break;
        }
        case 'X': {
            options.number_system = 16; 
            options.upper_case = 1;
            break;
        }
        return options;
    }
}

s21_size_t get_size_unsigned_decimal(unsigned long int number, Options* options) {
}

int unsigned_decimal_to_string(char *str_buff,Options options, unsigned long int number, s21_size_t size){
    int change_sign = 0;

    if((options.is_hash && options.number_system == 8)) options.flag_size = 1;
    else if (options.is_hash && options.number_system == 16) options.flag_size = 2;

    int i = 0;
    unsigned long int number_copy = number;

//надо ли это здесь? 
    // if( (number_copy == 0 && (options.accuracy || options.width || options.is_blank)) || 
    // (number_copy == 0 && !options.accuracy && !options.width && !options.is_blank && !options.is_dot)) {
    //     char c = convert_num_to_char(number_copy % options.number_system, options.upper_case);
    //     string_for_number[i] = c;
    //     i++;
    //     size--;
    // }

    while(number_copy != 0 && string_for_number && size) {
        char c = convert_num_to_char(number_copy % options.number_system, options.upper_case);
        string_for_number[i] = c;
        i++;
        size--;
        number_copy /= 10;
    }

    // if(change_sign == 1) number = -number; //надо ли это здесь? 

    if(options.accuracy - i > 0) {
        options.accuracy -= i;
        options.is_zero = 1;
    } 
    //else change_sign = 1; //надо ли это здесь ???

    if(size == 1 && options.is_zero == 1 && options.flag_size == 1) 
        options.is_zero = 0;

    //handler for flag is zero
    while(options.is_zero && string_for_number && (size - options.flag_size > 0) && (options.accuracy || change_sign) ){
        if(size == 1 && options.flag_size == 1)
            break;
        string_for_number[i] = '0';
        i++;
        size--;
        options.accuracy--;
    }

////////////
    if(options.is_hash && options.number_system == 8){
        string_for_number[i] = '0';
        i++;
        size--;
    } else if (options.is_hash && options.number_system == 16 && options.upper_case){
        string_for_number[i] = 'X';
        i++;
        size--;
        string_for_number='0';
        i++;
        size--;
    } else if (options.is_hash && options.number_system == 16 && !options.upper_case){
        string_for_number[i] = 'x';
        i++;
        size--;
        string_for_number[i] = '0';
        i++;
        size--;
    }

 //if all flags handled, but we still have free space in the string
    if(size > 0 && options.is_minus == 0) {
        while((size - options.flag_size > 0) && string_for_number) {
            string_for_number[i] = ' ';
            i++;
            size--;
        }
    }
    return i;
}

char* print_u(char *str, Options options, char format, va_list *arg) {
    unsigned long int number =0;
    if(format == 'l') number = (unsigned long int)va_arg(*arg, unsigned long int);
    else if(format == 'h') number = (unsigned short)va_arg(*arg, unsigned short);
    else number = (unsigned int)va_arg(*arg, unsigned int);

    s21_size_t size = get_size_unsigned_decimal(number, &options);
    char* string_for_number = malloc(sizeof(char)*size);

    if(string_for_number){
        int i  = unsigned_decimal_to_string(string_for_number, options, number, size);
        
        for(int j = i - 1; j>=0; j--){
            *str = string_for_number([j]);
            str++;
        }
        while(i < options.width){
            *str = ' ';
            str++;
        }
    }

    if(string_for_number) free(string_for_number);

    return str;
}
//end unsingned + x, o, 

char* print_c(char *str, Options options, int symbol){
    char *ptr = S21_NULL;
    int i =0;
    while(options.width -1 >0 && !options.is_minus){
        *str = ' ';
        str++;
        i++;
        options.width--;
    }
    if(symbol <= 127){
        *str = symbol;
        str++;
        i++;
        while(options.width -1 > 0 && options.is_minus){
             *str = ' ';
             str++;
             i++;
             options.width--;
    }
    ptr = str;
        }
        return ptr;
    }

char* print_s(char *str, Options options, va_list *arg){
    char *ptr = str;
    char *string = va_arg(*arg,char *);

    if(string){
        int tmp= options.width, i = 0;

        if((s21_size_t)options.width <s21_strlen(string)) options.width = s21_strlen(string);
        int blank = options.width - s21_strlen(string);

        if(options.accuracy == 0) options.accuracy = options.width;

        if(options.accuracy != 0 && options.accuracy <tmp)blank = tmp-options.accuracy;


        while(blank && !options.is_minus){
            *str = ' ';
            str++;
            blank--;
        }
        while (*string != '\0')
        {
            if(!options.accuracy) break;
            *str = *string;
            str++;
            string++;
            i++;
            options.accuracy--;
        }

        while(blank && options.is_minus){
            *str = ' ';
            str++;
            blank--;
        }
        
    } else  {
        str = s21_memcpy(str,"(null)",6);
        str +=6;

    }

    if(ptr)ptr = str;


    return ptr;
}


Options set_opt_double(Options options, char format){
    if(format == 'g' || format == 'G') options.g = 1;
    else if(format == 'e' || format =='E') options.e = 1;
    if(format == 'E' || format == 'G' || format == 'F') options.upper_case =1;
    return options;
}


// char *print_double(char *str,Options options,char format, va_list *arg){
//     long double num = 0;
//     int e = 0;
//     if(format == "L") num =va_arg(*arg,long double);
//     else num = va_arg(*arg,double);

//     s21_size_t size_double = get
// }

long double normalize(long double *num,Options *options){
    int i = 0;
    if(fabsl(*num)>1){
        while (fabsl(*num)>10){
            *num /= 10;
            i++;
            options->e = 2;
        }
    }else{
        while(fabsl(*num)<0.999999){
            if(*num == 0){
                options->e = 2;
                break;
            }
            *num *=10;
            i++;
            options->e=1;
        }
    }
    return i;
}
