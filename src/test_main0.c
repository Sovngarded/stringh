#include <math.h>
#include "s21_sprintf.h"
#include "s21_string.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_NULL (void *)0
#define ALPHABET 32
typedef unsigned long s21_size_t;

int s21_sprintf(char *str, const char *format, ...) {
  char *copy_str = str;
  char flags[] = "cdieEfgGosuxXpn%"; //F?

  va_list arg;
  va_start(arg, format);

  while (*format) {
    if (*format == '%') {
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

const char *set_options(Options *options, const char *format, va_list *arg) {
  format = get_options(format, options);
  format = get_width(format, &options->width, arg);

  if (*format == '.') {
    options->is_dot = 1;
    options->is_zero = 0;
    format++;
    format = get_width(format, &options->accuracy, arg);
  }
  if (*format == 'L') {
    options->addit_type = 'L';
  } else if (*format == 'l') {
    options->addit_type = 'l';
  } else if (*format == 'h') {
    options->addit_type = 'h';
  }
  if (options->addit_type != 0)
    format++;

  // here should be logic for width<0, but it's unreal situation
  return format;
}

const char *get_options(const char *format, Options *options) {
  int flag = 0;
  while (format) {
    switch (*format) {
    case '+': {
      options->is_plus = 1;
      break;
    }
    case '-': {
      options->is_minus = 1;
      break;
    }
    case ' ': {
      options->is_blank = 1;
      break;
    }
    case '#': {
      options->is_hash = 1;
      break;
    }
    case '0': {
      options->is_zero = 1;
      break;
    }
    default: {
      flag = 1;
      break;
    }
    }
    if (flag == 1)
      break;
    format++;
  }
  options->is_blank = (options->is_blank && !options->is_plus);
  options->is_zero = (options->is_zero && !options->is_minus);

  return format;
}

const char *get_width(const char *format, int *width, va_list *arg) {
  *width = 0;

  if (*format == '*') {
    *width = va_arg(*arg, int);
    format++;
  }

  while (format) {
    if ('0' <= *format && *format <= '9') {
      *width *= 10;
      *width += *format - '0';
    } else
      break;
    format++;
  }
  return format;
}

char *parser(char *str, char *copy_str, const char *format, Options options,
             va_list *arg) {
  if (*format == 'd' || *format == 'i') {
    str = print_decimal(str, options, arg);
  } else if (*format == 'u' || *format == 'o' || *format == 'x' ||
             *format == 'X') {
    options = set_number_system(options, *format);
    str = print_u(str, options, *(format - 1), arg);
  } else if (*format == 'c') {
    int symbol = va_arg(*arg, int);
    str = print_c(str, options, symbol);
  } else if (*format == 'p') {
    str = print_p(str, &options, arg);
  } else if (*format == 'F' || *format == 'f') {
    options = set_opt_double(options, *format);
    str = print_double(str, options, *(format - 1), arg);
  } else if (*format == 'e' || *format == 'E' || *format == 'g' ||
             *format == 'G') {
    options = set_opt_double(options, *format);
    str = print_eg(str, options, *(format - 1), arg);
  } else if (*format == '%') {
    str = print_c(str, options, '%');
  } else if (*format == 's') {
    str = print_s(str, options, arg);
  } else if (*format == 'n') {
    int *n = va_arg(*arg, int *);
    *n = (int)(str - copy_str);
  } else
    str = S21_NULL;

  if (!str)
    *str = '\0';
  return str;
}

// decimal
s21_size_t get_size_decimal(long int number, Options *options) {
  s21_size_t result = 0;
  long int copy_num = number;

  if (copy_num < 0) {
    copy_num = -number;
  }

  while (copy_num > 0) {
    copy_num /= 10;
    result++;
  }

  if (copy_num == 0 && result == 0 &&
      (options->is_blank && options->width && options->accuracy)) {
    result++;
  }

  if ((s21_size_t)options->width > result)
    result = options->width;
  if ((s21_size_t)options->accuracy > result)
    result = options->accuracy;

  if (options->is_blank || options->is_plus || number < 0) {
    options->flag_size = 1;
    result++;
  }

  if (result == 0 && copy_num == 0 && !options->width && !options->accuracy &&
      !options->is_blank && !options->is_dot)
    result++;

  return result;
}

int decimal_handle_flags(char *string_for_number, Options options,
                         s21_size_t size, int i, long int number,
                         char data_type) {
  while (options.is_zero && string_for_number &&
         (size - options.flag_size > 0) && (options.accuracy || number < 0)) {
    if (size == 1 && options.flag_size == 1)
      break;
    string_for_number[i] = '0';
    i++;
    size--;
    options.accuracy--;
  }

  if (data_type == 'u') {
    if (options.is_hash && options.number_system == 8) {
      string_for_number[i] = '0';
      i++;
      size--;
    } else if (options.is_hash && options.number_system == 16 &&
               options.upper_case) {
      string_for_number[i] = 'X';
      i++;
      size--;
      string_for_number[i] = '0';
      i++;
      size--;
    } else if (options.is_hash && options.number_system == 16 &&
               !options.upper_case) {
      string_for_number[i] = 'x';
      i++;
      size--;
      string_for_number[i] = '0';
      i++;
      size--;
    }

  } else if (data_type == 'd') {
    if (options.is_blank && number >= 0 && size) {
      string_for_number[i] = ' ';
      i++;
      size--;
    }

    if (number < 0 && size) {
      string_for_number[i] = '-';
      i++;
      size--;
    }
    if (number > 0 && options.is_plus && size) {
      string_for_number[i] = '+';
      i++;
      size--;
    }
  }

  if (size > 0 && !options.is_minus) {
    while ((size - options.flag_size > 0) && string_for_number) {
      string_for_number[i] = ' ';
      i++;
      size--;
    }
  }
  return i;
}

int decimal_to_string(long int number, Options options, char *string_for_number,
                      s21_size_t size) {
  int change_sign = 0;

  if (number < 0) {
    change_sign = 1;
    number = -number;
  }

  int i = 0;
  long int number_copy = number;

  if ((number_copy == 0 &&
       (options.accuracy || options.width || options.is_blank)) ||
      (number_copy == 0 && !options.accuracy && !options.width &&
       !options.is_blank && !options.is_dot)) {
    char c = convert_num_to_char(number_copy % options.number_system,
                                 options.upper_case);
    string_for_number[i] = c;
    i++;
    size--;
  }

  while (number_copy != 0 && string_for_number && size) {
    char c = convert_num_to_char(number_copy % options.number_system,
                                 options.upper_case);
    string_for_number[i] = c;
    i++;
    size--;
    number_copy /= 10;
  }

  if (change_sign == 1)
    number = -number;

  if (options.accuracy - i > 0) {
    options.accuracy -= i;
    options.is_zero = 1;
  } else
    change_sign = 1; //???

  if (size == 1 && options.is_zero == 1 && options.flag_size == 1)
    options.is_zero = 0;

  i = decimal_handle_flags(string_for_number, options, size, i, number, 'd');
  return i;
}

char *print_decimal(char *str, Options options, va_list *arg) {
  long int number = 0;

  char addit = options.addit_type;
  if (addit == 'l')
    number = (long int)va_arg(*arg, long int);
  else if (addit == 'h')
    number = (short)va_arg(*arg, int);
  else
    number = (int)va_arg(*arg, int);

  s21_size_t size = get_size_decimal(number, &options);
  char *string_for_number = malloc(sizeof(char) * size);

  if (string_for_number) {
    int i = decimal_to_string(number, options, string_for_number, size);
    // reverse
    str = reverse_and_pad(str, string_for_number, i, options.width);
  }
  if (string_for_number)
    free(string_for_number);

  return str;
}
// end decimal

char convert_num_to_char(int num, int upper_case) {
  char flag = '0';
  switch (num) {
  case 10:
    flag = (char)('a' - upper_case * ALPHABET);
    break;
  case 11:
    flag = (char)('b' - upper_case * ALPHABET);
    break;
  case 12:
    flag = (char)('c' - upper_case * ALPHABET);
    break;
  case 13:
    flag = (char)('d' - upper_case * ALPHABET);
    break;
  case 14:
    flag = (char)('e' - upper_case * ALPHABET);
    break;
  case 15:
    flag = (char)('f' - upper_case * ALPHABET);
    break;
  }

  if (0 <= num && num <= 9)
    flag = (char)(num + '0');

  return flag;
}

char* reverse_and_pad(char *str, const char *string_for_number, int length, int width) {
  for (int j = length - 1; j >= 0; j--) {
    *str = string_for_number[j];
    str++;
  }

  while (length < width) {
    *str = ' ';
    str++;
  }
  return str;
}

// unsingned + x, o,
Options set_number_system(Options options, char format) {
  switch (format) {
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
  }
  return options;
}

s21_size_t get_size_unsigned_decimal(unsigned long int number,
                                     Options *options) {
  s21_size_t result = 0;
  unsigned long int copy_num = number;

  while (copy_num > 0) {
    copy_num /= 10;
    result++;
  }

  if (copy_num == 0 && result == 0 &&
      (options->is_blank && options->width && options->accuracy)) {
    result++;
  }

  if ((s21_size_t)options->width > result)
    result = options->width;
  if ((s21_size_t)options->accuracy > result)
    result = options->accuracy;

  if (result == 0 && copy_num == 0 && !options->width && !options->accuracy &&
      !options->is_blank && !options->is_dot)
    result++;

  return result;
}

int unsigned_decimal_to_string(char *string_for_number, Options options,
                               unsigned long int number, s21_size_t size) {
  if ((options.is_hash && options.number_system == 8))
    options.flag_size = 1;
  else if (options.is_hash && options.number_system == 16)
    options.flag_size = 2;

  int i = 0;
  unsigned long int number_copy = number;

  if ((number_copy == 0 &&
       (options.accuracy || options.width || options.is_blank)) ||
      (number_copy == 0 && !options.accuracy && !options.width &&
       !options.is_blank && !options.is_dot)) {
    char c = convert_num_to_char(number_copy % options.number_system,
                                 options.upper_case);
    string_for_number[i] = c;
    i++;
    size--;
  }

  while (number_copy != 0 && string_for_number && size) {
    char c = convert_num_to_char(number_copy % options.number_system,
                                 options.upper_case);
    string_for_number[i] = c;
    i++;
    size--;
    number_copy /= 10;
  }

  if (options.accuracy - i > 0) {
    options.accuracy -= i;
    options.is_zero = 1;
  }

  if (size == 1 && options.is_zero == 1 && options.flag_size == 1)
    options.is_zero = 0;

  i = decimal_handle_flags(string_for_number, options, size, i, number, 'u');
  return i;
}

char *print_u(char *str, Options options, char format, va_list *arg) {
  unsigned long int number = 0;
  if (format == 'l')
    number = (unsigned long int)va_arg(*arg, unsigned long int);
  else if (format == 'h')
    number = (unsigned short)va_arg(*arg, unsigned int);
  else
    number = (unsigned int)va_arg(*arg, unsigned int);

  s21_size_t size = get_size_unsigned_decimal(number, &options);
  char *string_for_number = malloc(sizeof(char) * size);

  if (string_for_number) {
    int i = unsigned_decimal_to_string(string_for_number, options, number, size);
    str = reverse_and_pad(str, string_for_number, i, options.width);
  }

  if (string_for_number)
    free(string_for_number);

  return str;
}
// end unsingned + x, o,

char *print_c(char *str, Options options, int symbol) {
  char *ptr = S21_NULL;
  int i = 0;
  while (options.width - 1 > 0 && !options.is_minus) {
    *str = ' ';
    str++;
    i++;
    options.width--;
  }
  if (symbol <= 127) {
    *str = symbol;
    str++;
    i++;
    while (options.width - 1 > 0 && options.is_minus) {
      *str = ' ';
      str++;
      i++;
      options.width--;
    }
    ptr = str;
  }
  return ptr;
}

char *print_s(char *str, Options options, va_list *arg) {
  char *ptr = str;
  char *string = va_arg(*arg, char *);
  if (string) {
    int tmp = options.width, i = 0;
    if ((s21_size_t)options.width < s21_strlen(string))
      options.width = s21_strlen(string);
    int blank = options.width - s21_strlen(string);

    if (options.accuracy == 0)
      options.accuracy = options.width;

    if (options.accuracy != 0 && options.accuracy < tmp)
      blank = tmp - options.accuracy;

    while (blank && !options.is_minus) {
      *str = ' ';
      str++;
      blank--;
    }
    while (*string != '\0') {
      if (!options.accuracy)
        break;
      *str = *string;
      str++;
      string++;
      i++;
      options.accuracy--;
    }
    while (blank && options.is_minus) {
      *str = ' ';
      str++;
      blank--;
    }
  } else {
    str = s21_memcpy(str, "(null)", 6);
    str += 6;
  }
  if (ptr)
    ptr = str;

  return ptr;
}

// double f F
Options set_opt_double(Options options, char format) {
  if (format == 'g' || format == 'G')
    options.g = 1;
  else if (format == 'e' || format == 'E')
    options.e = 1;
  if (format == 'E' || format == 'G' || format == 'F')
    options.upper_case = 1;
  return options;
}

s21_size_t get_size_double(Options *options, long double number) {
  ///
  number = options->accuracy;
  number--;

  return 0;
  //разбиваем на две части (целая6 дробная) + место под точку
  //если асс или видтх больше6 то добавляем
}

int print_e(int e, s21_size_t *size, char *string_for_number, Options options,
            int *i) {
  int copy_e = e;
  if (copy_e == 0) {
    // *size -= add_to(string_for_number + *i, i,
    //                 convert_num_to_char(copy_e % options.number_system,
    //                                     options.upper_case));
  }
  while (copy_e) {
    // *size -= add_to(string_for_number + *i, i,
    //                 convert_num_to_char(copy_e % options.number_system,
    //                                     options.upper_case));
    copy_e /= 10;
  }
  // if (e < 10)
  //   *size -= add_to(string_for_number + *i, i, '0');
  // if (options.e == 2 || e == 0)
  //   *size -= add_to(string_for_number + *i, i, '+');
  // else
  //   *size -= add_to(string_for_number + *i, i, '-');
  // if (options.upper_case)
  //   *size -= add_to(string_for_number + *i, i, 'E');
  // else
  //   *size -= add_to(string_for_number + *i, i, 'e');

  return 0;
}

// void pad_zeros(char* string, Options options, s21_size_t size, int* i) {
//     while (options.is_zero && string && (size - options.flag_size > 0) &&
//     (options.accuracy || flag)) {
//         if (size == 1 && options.flag_size == 1)
//             break;
//         string[*i] = '0';
//         (*i)++;
//         size--;
//         options.accuracy--;
//     }
// }

// void add_space_or_sign(char* string, Options options, long double number,
// s21_size_t size, int* i) {
//     if (options.is_blank && number >= 0 && size) {
//         string[*i] = ' ';
//         (*i)++;
//         size--;
//     }

//     if (number < 0 && size) {
//         string[*i] = '-';
//         (*i)++;
//         size--;
//     }

//     if (number > 0 && options.is_plus && size) {
//         string[*i] = '+';
//         (*i)++;
//         size--;
//     }

//     if (size > 0 && options.is_minus == 0) {
//         while ((size - options.flag_size > 0) && string) {
//             if (options.g && options.width < options.accuracy) break;
//             string[*i] = ' ';
//             (*i)++;
//             size--;
//         }
//     }
// }

s21_size_t add_parts_to_string(char *string, Options options, int accuracy,
                               s21_size_t size, int *i,
                               long double fractional_part,
                               long double integer_part) {
  long double copy_fractional_part = fractional_part;

  if (fractional_part + 0.000000000000001 >= 1) {
    fractional_part = 0;
    integer_part += 1;
  }

  for (int j = 0; j < 15; j++) {
    copy_fractional_part *= 10;
    if ((long)copy_fractional_part != 0)
      break;
  }

  if ((long)copy_fractional_part == 0 && options.g)
    accuracy = 0;
  if (!accuracy && fractional_part * 10 > 4)
    integer_part += 1;

  while (accuracy > 0) {
    fractional_part *= 10;
    accuracy--;
  }

  // if (fmodl(fabsl(fractional_part) * 10, 10.0) > 4)
    // fractional_part = roundl(fractional_part);

  if (options.g) {
    while ((long)fractional_part % 10 == 0 && options.accuracy > 0 &&
           (long)fractional_part != 0) {
      fractional_part /= 10;
      accuracy++;
    }
  }

  int dot = 0;
  if ((long)fractional_part == 0)
    dot = 1;

  return 0;
  // return add_s_from_d_to_str(string, options, accuracy, dot, size, i,
  //                            fractional_part, integer_part);
}

int double_handle_flags(char *string_for_number, Options options,
                        s21_size_t size, int i, long double number) {
  while (options.is_zero && string_for_number &&
         (size - options.flag_size > 0) && (options.accuracy || number < 0)) {
    if (size == 1 && options.flag_size == 1)
      break;
    string_for_number[i] = '0';
    i++;
    size--;
    options.accuracy--;
  }

  if (options.is_blank && number >= 0 && size) {
    string_for_number[i] = ' ';
    i++;
    size--;
  }

  if (number < 0 && size) {
    string_for_number[i] = '-';
    i++;
    size--;
  }
  if (number > 0 && options.is_plus && size) {
    string_for_number[i] = '+';
    i++;
    size--;
  }

  if (size > 0 && options.is_minus == 0) {
    while ((size - options.flag_size > 0) && string_for_number) {
      if (options.g && options.width < options.accuracy)
        break;
      string_for_number[i] = ' ';
      i++;
      size--;
    }
  }
  return i;
}

int double_to_string(long double number, Options options,
                     char *string_for_number, s21_size_t size, int e) {
  int i = 0;
  // int i = is_nan_of_inf(string_for_number, number, options);
  if (!i) {
    if (options.e)
      print_e(e, &size, string_for_number, options, &i);
    int flag = 0;
    if (number < 0) {
      flag = 1;
      number = -number;
    }

    long double integer_part = 0;
    long double fractional_part = modfl(number, &integer_part);

    int accuracy = options.accuracy;
    size = add_parts_to_string(string_for_number, options, accuracy, size, &i,
                               fractional_part, integer_part);
    // size = add_s_from_d_to_str(string_for_number, options, accuracy, dot,
    // size, &i, fractional_part, integer_part);
    if (flag)
      number = -number;

    i = double_handle_flags(string_for_number, options, size, i, number);
    // pad_zeros(string_for_number, options, size, &i);
    // add_space_or_sign(string_for_number, options, number, size, &i);
  }
  return i;
}

char *print_double(char *str, Options options, char format, va_list *arg) {
  long double number = 0;
  int e = 0;
  if (format == 'L')
    number = va_arg(*arg, long double);
  else
    number = va_arg(*arg, double);

  s21_size_t size = get_size_double(&options, number);
  char *string_for_number = malloc(sizeof(char) * size);

  if (string_for_number) {
    int i = double_to_string(number, options, string_for_number, size, e);

    // reverse
    str = reverse_and_pad(str, string_for_number, i, options.width);
  }
  if (string_for_number)
    free(string_for_number);

  return str;
}
// end double f F

// e E g G
s21_size_t get_size_eg(Options *options, long double number) {
  number = options->accuracy;
  number--;

  return 0;
  //разбиваем на две части (целая6 дробная) + место под точку
  //место под е и + под 0n
  //если асс или видтх больше6 то добавляем
}

char *print_eg(char *str, Options options, char format, va_list *arg) {
  long double number = 0;
  int e = 0;
  if (format == 'L')
    number = va_arg(*arg, long double);
  else
    number = va_arg(*arg, double);

  s21_size_t size = 0;
  if (options.g) {
    options = shrtst(options, number);
  }
  if (options.e) {
    e = normalize(&number, &options);
    if (e < 100)
      size += 2;
    else
      size += 3;
  }
  size += get_size_eg(&options, number);
  if ((int)size < options.accuracy)
    size = options.accuracy;
  if ((int)size < options.width)
    size = options.width;

  char *string_for_number = malloc(sizeof(char) * size);
  if (string_for_number) {
    int i = double_to_string(number, options, string_for_number, size, e);
    // reverse
    str = reverse_and_pad(str, string_for_number, i, options.width);
  }
  if (string_for_number)
    free(string_for_number);

  return str;
}

Options shrtst(Options options, long double number) {
  Options copy_opt = options;
  long double copy_number = number;
  int e = normalize(&copy_number, &copy_opt);
  if (copy_opt.accuracy == 0 && !copy_opt.is_dot)
    copy_opt.accuracy = 6;
  if ((e <= 4 && copy_opt.e == 1) || (copy_opt.e == 2 && e < 6)) {
    copy_opt.e = 0;
  }
  return copy_opt;
}

long double normalize(long double *num, Options *options) {
  int i = 0;
  if (fabsl(*num) > 1) {
    while (fabsl(*num) > 10) {
      *num /= 10;
      i++;
      options->e = 2;
    }
  } else {
    while (fabsl(*num) < 0.999999) {
      if (*num == 0) {
        options->e = 2;
        break;
      }
      *num *= 10;
      i++;
      options->e = 1;
    }
  }
  return i;
}

// end e E g G

char *print_p(char *str, Options *options, va_list *arg) {
  unsigned long int ptr = (unsigned long int)va_arg(*arg, unsigned long int);
  options->number_system = 16;
  options->is_hash = 1;
  options->upper_case = 0;

  s21_size_t size = get_size_unsigned_decimal(ptr, options);
  char *string_for_ptr = malloc(sizeof(char) * size);

  if (string_for_ptr) {
    int i = unsigned_decimal_to_string(string_for_ptr, *options, ptr, size);
    //возмоэно тут что-то другое должно быть ниже...
    str = reverse_and_pad(str, string_for_ptr, i, options->width);
  } //возмоэно тут что-то другое должно быть выще...

  if (string_for_ptr)
    free(string_for_ptr);

  return str;
}

int main() {
      char buffer[100];

    // Specifier: c
    // char charValue = 'A';
    // s21_sprintf(buffer, "Specifier: %%c - Character: %c", charValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Specifier: %%c - Character: %c", charValue);
    // printf("Formatted string: %s\n", buffer);

    // // Specifier: d
    // int intValue = -42;
    // s21_sprintf(buffer, "Specifier: %%d - Integer: %d", intValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Specifier: %%d - Integer: %d", intValue);
    // printf("Formatted string: %s\n", buffer);
    
    // // Specifier: f
    // float floatValue = 3.14159;
    // s21_sprintf(buffer, "Specifier: %%f - Float: %f", floatValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Specifier: %%f - Float: %f", floatValue);
    // printf("Formatted string: %s\n", buffer);

    // // Specifier: s
    // char stringValue[] = "Hello, World!";
    // s21_sprintf(buffer, "Specifier: %%s - String: %s", stringValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Specifier: %%s - String: %s", stringValue);
    // printf("Formatted string: %s\n", buffer);

    // Specifier: u
    unsigned int uintValue = 99;
    s21_sprintf(buffer, "Specifier: %%u - Unsigned Integer: %  u", uintValue);
    printf("Formatted string: %s\n", buffer);

    sprintf(buffer, "Specifier: %%u - Unsigned Integer: %  u", uintValue);
    printf("Formatted string: %s\n", buffer);
    
        // Specifier: x (hexadecimal)
    int hexValue = 0x2A;  // Hex representation of 42 in decimal
    s21_sprintf(buffer, "Specifier: %%x - Hexadecimal (lowercase): %x", hexValue);
    printf("Formatted string: %s\n", buffer);

 sprintf(buffer, "Specifier: %%x - Hexadecimal (lowercase): %x", hexValue);
    printf("Formatted string: %s\n", buffer);

    // Specifier: X (hexadecimal, uppercase)
    s21_sprintf(buffer, "Specifier: %%X - Hexadecimal (uppercase): %X", hexValue);
    printf("Formatted string: %s\n", buffer);

    sprintf(buffer, "Specifier: %%X - Hexadecimal (uppercase): %X", hexValue);
    printf("Formatted string: %s\n", buffer);

    // Specifier: o (octal)
    unsigned int octalValue = 077;  // Octal representation of 63 in decimal
    s21_sprintf(buffer, "Specifier: %%o - Octal: %o", octalValue);
    printf("Formatted string: %s\n", buffer);

sprintf(buffer, "Specifier: %%o - Octal: %o", octalValue);
    printf("Formatted string: %s\n", buffer);

    // Flags: -
    s21_sprintf(buffer, "Flags: %%-8x - Left-justified Hexadecimal: %-8x", hexValue);
    printf("Formatted string: %s\n", buffer);

     sprintf(buffer, "Flags: %%-8x - Left-justified Hexadecimal: %-8x", hexValue);
    printf("Formatted string: %s\n", buffer);

    // Flags: #
    s21_sprintf(buffer, "Flags: %%#x - Hexadecimal with '0x' prefix: %#x", hexValue);
    printf("Formatted string: %s\n", buffer);
    
     sprintf(buffer, "Flags: %%#x - Hexadecimal with '0x' prefix: %#x", hexValue);
    printf("Formatted string: %s\n", buffer);


    // Width description: (number)
    s21_sprintf(buffer, "Width: %%10x - Width of 10 for Hexadecimal: %10x", hexValue);
    printf("Formatted string: %s\n", buffer);

     sprintf(buffer, "Width: %%10x - Width of 10 for Hexadecimal: %10x", hexValue);
    printf("Formatted string: %s\n", buffer);

    // Precision and Width combined
    s21_sprintf(buffer, "Width and Precision: %%#08.4o - Width 8, Precision 4 for Octal: %#08.4o", octalValue);
    printf("Formatted string: %s\n", buffer);

    sprintf(buffer, "Width and Precision: %%#08.4o - Width 8, Precision 4 for Octal: %#08.4o", octalValue);
    printf("Formatted string: %s\n", buffer);
    // // Specifier: %
    // s21_sprintf(buffer, "Specifier: %%%% - Literal Percent Sign: %%");
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Specifier: %%%% - Literal Percent Sign: %%");
    // printf("Formatted string: %s\n", buffer);

    // // Flags: -
    // s21_sprintf(buffer, "Flags: %%-10s - Left-justified String: %-10s", stringValue);
    // printf("Formatted string: %s\n", buffer);

    //  sprintf(buffer, "Flags: %%-10s - Left-justified String: %-10s", stringValue);
    // printf("Formatted string: %s\n", buffer);

    // // Flags: +
    // s21_sprintf(buffer, "Flags: %%+d - Plus sign for positive Integer: %+d", intValue);
    // printf("Formatted string: %s\n", buffer);

    //  sprintf(buffer, "Flags: %%+d - Plus sign for positive Integer: %+d", intValue);
    // printf("Formatted string: %s\n", buffer);

    // // Flags: (space)
    // s21_sprintf(buffer, "Flags: %% d - Space for positive Integer: % d", intValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Flags: %% d - Space for positive Integer: % d", intValue);
    // printf("Formatted string: %s\n", buffer);

    // // Width description: (number)
    // s21_sprintf(buffer, "Width: %%10s - Width of 10 for String: %10s", stringValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Width: %%10s - Width of 10 for String: %10s", stringValue);
    // printf("Formatted string: %s\n", buffer);

    // // Precision description: .(number)
    // s21_sprintf(buffer, "Precision: %%.*f - Precision of 2 for Float: %.*f", 2, floatValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Precision: %%.*f - Precision of 2 for Float: %.*f", 2, floatValue);
    // printf("Formatted string: %s\n", buffer);

    // // Length description: h
    // short shortValue = 42;
    // s21_sprintf(buffer, "Length: %%hd - Short Integer: %hd", shortValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Length: %%hd - Short Integer: %hd", shortValue);
    // printf("Formatted string: %s\n", buffer);

    // // Length description: l
    // long long longValue = 9876543210;
    // s21_sprintf(buffer, "Length: %%ld - Long Integer: %ld", longValue);
    // printf("Formatted string: %s\n", buffer);

    // sprintf(buffer, "Length: %%ld - Long Integer: %ld", longValue);
    // printf("Formatted string: %s\n", buffer);


  return 0;
}

//если О и # - число вместе с 0
//если x и # - число вместе с 0x
//если x и # - число вместе с 0X

// s21_size_t get_size_unsigned_decimal(long int number, Options* options) {
//     s21_size_t result = 0;
//     long int copy_num = number;

//     if(copy_num < 0) {
//         copy_num = -number;
//     }

//     while(copy_num > 0) {
//         copy_num /= 10;
//         result++;
//     }

//     if(copy_num == 0 && result == 0 && (options->is_blank && options->width
//     && options->accuracy)) {
//         result++;
//     }

//     if((s21_size_t)options->width > result) result = options->width;
//     if((s21_size_t)options->accuracy > result) result = options->accuracy;

//     if(options->is_blank || options->is_plus || number < 0) {
//         options->flag_size = 1;
//         result++;
//     }

//     if(result == 0 && copy_num == 0 && !options->width && !options->accuracy
//     && !options->is_blank && !options->is_dot) result++;

//     return result;
// }