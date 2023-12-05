#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
//#include "s21_sprintf.h"

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

    
}Options;


const char *get_width(const char *format, int *width, va_list *arg){
    *width = 0;

    while(format){
       // printf("%c ",*format);
        if('0' <= *format && *format <= '9'){
            *width *=10;
            *width += *format - '0';
        }else break;
        format++;
    }
    printf("%d",*width);
    return format;
}


const char *set_options(Options *options, const char *format, va_list *arg){
    //format = get_options(format,options);
   
    //s21_sprintf(str1,"hello %14(width).3(accur)d(type)",2);
    format = get_width(format,&options->width,arg);
    switch(*format){
        case '.':{
            options->is_dot = 1;
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
}

// const char *get_options(const char *format, Options *options){
//     while(format){
//         switch(*format){
//             case '+':{
//                 options->is_plus = 1;
//             }
//             case '-':{  
//                 options->is_minus = 1;
//             }
//             case ' ':{
//                 options->is_blank = 1;
//             }
//             case '#':{
//                 options->is_hash = 1;
//             }
//             case '0':{
//                 options->is_zero = 1;
//             }
//             default: break;
//         format++;
//         }



//     }
//     return format;
// }



int s21_sprintf(char *str, const char *format, ...){
    char *copy_str = str;
    char flags[] = "cdieEfgGosuxXpn%";
    Options options = {0};

    va_list arg;
    va_start(arg,format);



    while(*format){
        if(*format == '%'){
            format++;
            options.number_system = 10;
            format = set_options(&options, format, &arg);



            //do parser 
        }else{
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






int main(){

    // char dest[9]="qwerty";
    // char src[6]="12345";
    // char lll[30]="awdada";
   // printf("%d",s21_strlen(src));




//     int len;
//    const char str[] = "https://www.tutorialspoint.com";
//    const char ch = 't';
//    char *ret;

//    ret = s21_strrchr(str, ch);

//    printf("String after |%c| is - |%s|\n", ch, ret);
   // char str1[16]="awdawdbd";
   // char str2[16]="awdawdkp";
  
   // // Сравниваем первые пять символов двух строк
   //    printf("%d",s21_strncmp (str1, str2,9));
     
//    char s[] = "Hello, world!";
//   int ch = 'm';
//   printf("%s",s21_strchr(s,ch));
    char str[10];
    //printf("%d", s21_sprintf(str,"%123"));
    s21_sprintf(str,"%123.321");
    // printf("%d",s21_sprintf(str1))

//  // Массив со строкой для поиска
//    char str [24]="test1/test2/test3/test4";
//    // Набор символов, которые должны входить в искомый сегмент
//    char sep [10]="/";
//    // Переменная, в которую будут заноситься начальные адреса частей
//    // строки str
//    char *istr;

//    printf ("Исходная строка: %s\n", str);
//    printf ("Результат разбиения:\n");
//    // Выделение первой части строки
//    istr = s21_strtok (str,sep);

//    // Выделение последующих частей
//    while (istr != NULL)
//    {
//       // Вывод очередной выделенной части
//       printf ("%s\n",istr);
//       // Выделение очередной части строки
//       istr = s21_strtok (NULL,sep);
//    }



// char str [10]="0123456789";
//    // Набор символов, которые не должны входить в искомый сегмент
//    char sym [10]="9876";
  
//    // Определяем длину начального сегмента, не содержащего символы “9876"
//    printf ("Длина сегмента: %d\n",s21_strcspn (str,sym));











    // for(int i = 0; i<6;i++){
    //     printf("%d - %p \n",src[i],src[i]);
    // }
    // printf ("app:  %s\n",dest);
    // s21_strncat(dest,src,3);
    // printf ("app:  %s\n",dest);
    // printf("%s",s21_memchr(src,'a',5));
    // printf("\n");
    // printf("%s",memchr(src,'a',5));
    // printf("%s - %p", s21_memcpy(dest,src,5));
    // printf("\n");

    // char *i = s21_memcpy(dest,src,5);

    // printf("%s - %p \n",i,i);
    // printf("%p",dest);

    return 0;
}