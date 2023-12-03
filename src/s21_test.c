#include <string.h>
#include "s21_string.h"
#include <stdio.h>
#include <string.h>

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



char str [10]="0123456789";
   // Набор символов, которые не должны входить в искомый сегмент
   char sym [10]="9876";
  
   // Определяем длину начального сегмента, не содержащего символы “9876”
   printf ("Длина сегмента: %d\n",s21_strcspn (str,sym));











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