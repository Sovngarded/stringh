
#include <stdarg.h>
#define S21_NULL (void *)0
#include <stdio.h>
#include <stdlib.h>
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
} Options;

typedef unsigned long s21_size_t;
const char *set_options(Options *options, const char *format, va_list *arg);
const char *get_options(const char *format, Options *options);
const char *get_width(const char *format, int *width, va_list *arg);
Options set_number_system(Options options, char format);
char *print_u(char *str, Options options, char format, va_list *arg);
int unsigned_decimal_to_string(char *str_buff,Options options, unsigned long int buff, s21_size_t size_num);
char *print_c(char *str, Options options, int symbol);
char* print_decimal(char* str, Options options, va_list* arg);
s21_size_t get_size(long int number, Options* options);
int write_to_string(long int number, Options options, char* string_for_number, s21_size_t size);
char* parser(char* str, char* copy_str, const char *format, Options options, va_list *arg);



s21_size_t s21_strlen(const char *str){
    s21_size_t length = -1;
    if(str!= S21_NULL){
        length = 0;
        while (str[length] != '\0') {
        length++;
    }

    }



    return length;
}


// void *s21_to_upper(const char *str){
    

// char *str_copy = NULL;
//   if (str != NULL) {
//     int len = s21_strlen(str);
//     str_copy = malloc(sizeof(char) * (len + 1));
//     if (str_copy) {
//       for (int i = 0; i <= len; i++) {
//         if (str[i] >= 'a' && str[i] <= 'z') {
//           str_copy[i] = (str[i] - 'a') + 'A';
//         } else {
//           str_copy[i] = str[i];
//         }
//       }
//       str_copy[len] = '\0';
//     }
//   }
//   return str_copy;




// }

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
            //do parser// 
            str = parser(str, copy_str, format, options, &arg);
        }else {
            //printf("%c ",*format);
             *str = *format;
             str++;
        }
        
        format++;
    }

    *str = '\0';
   // printf("%s",str);
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
            default: {flag = 1; break;};
        }
        if(flag) break;
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
   // printf("%d",*width);
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
        // case 'h':
        //     number = (short)va_arg(*arg, short);
        //     break;        
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
        result++;
    }

    if(number == 0 && result == 0 && (options->is_blank && options->width && options->accuracy)) {
        result++;
    }

    if((s21_size_t)options->width > result) result = options->width;
    if((s21_size_t)options->accuracy > result) result = options->accuracy;

    if(options->is_blank || options->is_plus || change_sign == 1) {
        options->flag_size = 1;
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
        char c = number % options.number_system + '0';
        string_for_number[i] = c;
        i++;
        size--;
        //number /= 10; //useless move
    }

    while(number != 0 && string_for_number && size) {
        char c = number % options.number_system + '0'; //>????
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
    //number always zero ?
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


//decimal


Options set_number_system(Options options, char format){
    switch(format){
        case 'o': options.number_system = 8;
        case 'x':options.number_system = 16;
        case 'X':{options.number_system = 16; options.upper_case = 1;}
        return options;
    }
}

// char *print_u(char *str, Options options, char format, va_list *arg){
//     unsigned long int buff =0;
//     if(format == 'l') buff = (unsigned long int)va_arg(*arg,unsigned long int);
//     else if(format == 'h') buff = (unsigned short int)va_arg(*arg,unsigned short int);
//     else buff = (unsigned int)va_arg(*arg,unsigned int);


//     s21_size_t size_num = get_size_unsigned_decimal(options,buff);
//     char *str_buff = malloc(sizeof(char)*size_num);

//     if(str_buff){
//         int i  = unsigned_decimal_to_string(str_buff,options,buff,size_num);
//         for(int j = i - 1; j>=0;j--){
//             *str = str_num([j]);
//             str++;
//         }
//         while(i < options.width){
//             *str = ' ';
//             str++;
//         }
        
//     }

//     if(str_buff) free(str_buff);


//     return str;
// }

// WTF IS SIZE_TO_DECIMAL?????????
// int unsigned_decimal_to_string(char *str_buff,Options options, unsigned long int buff, s21_size_t size_num){
//     int i = 0, flag =0;
//     unsigned long int copy_buff = buff;


//     // ********************************************************************** //
//     if((options.is_hash && options.number_system == 8)) options.flag_size = 1;
//     else if (options.is_hash && options.number_system == 16) options.flag_size = 2;


//     // ********************************************************************** //

//     while (copy_buff && size_num 
//     //&& size_decimal//
//     )
//     {
//        char sym = get_num_char(copy_buff % options.number_system, options.upper_case);
//        size_num[i] = sym;
//         i++;
//         size_num--;
//         copy_buff /= 10;
//     }
//     if(flag) buff = -buff;
//     if(options.accuracy - i > 0){
//         options.accuracy -=1;
//         options.is_zero = 1;
//     }else flag = 1;

//     if(size_decimal == 1 && options.is_zero == 1 && options.flag_size = 1) options.is_zero = 0;



//     // ********************************************************************** //
//     if(options.is_hash && options.number_system == 8){
//         str_buff[i] = '0';
//         i++;
//         size_num--;
//     } else if (options.is_hash && options.number_system == 16 && options.upper_case){
//         str_buff[i] = 'X';
//         i++;
//         size_num--;
//         str_buff='0';
//         i++;
//         size_num--;
//     }else if (options.is_hash && options.number_system == 16 && !options.upper_case){
//         str_buff[i] = 'x';
//         i++;
//         size_num--;
//         str_buff[i] = '0';
//         i++;
//         size_num--;
//     }

//     // ********************************************************************** //

//     // if(size_num > 0 && options.is_minus == 0){
//         // while((size_decimal - options.flag_size >0) && str_num){
//         //     str_num[i] = ' ';
//         //     i++;
//         //     size_decimal--;
//         // }
//     // }


//     return i;

// }



char *print_c(char *str, Options options, int symbol){
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


int main(){



    char str[10] = "ABCD";
    //printf("%d", s21_sprintf(str,"%123"));
    printf("%s",s21_to_lower(str));
    printf("%s",str);


    return 0;
}