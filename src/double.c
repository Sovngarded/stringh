s21_size_t get_size_double(Options *options, long double number) {
  //разбиваем на две части (целая6 дробная) + место под точку
  //если асс или видтх больше6 то добавляем
  if (!options->accuracy && !options->is_dot) {
    options->accuracy = 6;
  }
  s21_size_t result = 0;
  long double copy_num = number;
  if ((int)copy_num == 0) result++;
  if (copy_num < 0) {
    copy_num = -copy_num;
    result++;
  }
  while (copy_num >= 1) {
    copy_num /= 10;
    result++;
  }
  if (!options->is_dot || options->accuracy) result += options->accuracy + 1;
  if (options->is_dot && !options->accuracy && options->is_hash) result++;
  if (!copy_num && !result &&
      (options->accuracy || options->width || options->is_blank)) {
    result++;
  }
  if ((s21_size_t)options->width > result) {
    result = options->width;
  }
  if ((s21_size_t)options->accuracy > result) {
    result += options->accuracy;
  }
 
  if (result == 0 && copy_num == 0 && !options->accuracy && !options->width &&
      !options->is_blank && !options->is_dot) {
    result++;
  }
   if (options->is_blank || options->is_plus || number < 0.0000000000001) {
    options->flag_size = 1;
    if(!options->width)
        result++;
  }
  return result;
}

int print_e(int e, s21_size_t *size, char *string_for_number, Options options,
            int *i) {
  int copy_e = e;
  if (copy_e == 0) {
    *size -= add_char_to_str(string_for_number + *i, i,
                    convert_num_to_char(copy_e % options.number_system,
                                        options.upper_case));
  }
  while (copy_e) {
    *size -= add_char_to_str(string_for_number + *i, i,
                    convert_num_to_char(copy_e % options.number_system,
                                        options.upper_case));
    copy_e /= 10;
  }
  if (e < 10)
    *size -= add_char_to_str(string_for_number + *i, i, '0');
  if (options.e == 2 || e == 0)
    *size -= add_char_to_str(string_for_number + *i, i, '+');
  else
    *size -= add_char_to_str(string_for_number + *i, i, '-');
  if (options.upper_case)
    *size -= add_char_to_str(string_for_number + *i, i, 'E');
  else
    *size -= add_char_to_str(string_for_number + *i, i, 'e');

  return 0;
}

int add_char_to_str(char *str, int *i, char symbol) {
  *str = symbol;
  *i += 1;
  return 1;
}

s21_size_t add_parts_of_num_to_string(char *string, Options options, int accuracy,
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

  if (fmodl(fabsl(fractional_part) * 10, 10.0) > 4)
    fractional_part = roundl(fractional_part);

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

  return add_sym_from_double_to_str(string, options, accuracy, dot, size, i,
                             fractional_part, integer_part);
}

int add_sym_from_double_to_str(char *str_to_double, Options options, int accurancy,
                               int flag_to_dot, s21_size_t size_to_double,
                               int *i, long double frac, long double integer) {
  while (str_to_double && (accurancy != options.accuracy) && options.accuracy > 0) {
    if (options.g && flag_to_dot) {
      size_to_double--;
      break;
    }
    size_to_double -= add_char_to_str(
        str_to_double + *i, i,
        convert_num_to_char((long)frac % options.number_system, options.upper_case));
    frac /= options.number_system;
    accurancy++;
  }
  if (options.accuracy) {
    if (flag_to_dot && options.g) {
      size_to_double--;
    } else {
      size_to_double -= add_char_to_str(str_to_double + *i, i, '.');
    }
  }
  if (options.is_hash && !options.accuracy) {
    size_to_double -= add_char_to_str(str_to_double + *i, i, '.');
  }
  if ((long)integer == 0) {
    size_to_double -= add_char_to_str(
        str_to_double + *i, i,
        convert_num_to_char((long)integer % options.number_system, options.upper_case));
    integer /= options.number_system;
  }
  while ((long)integer && str_to_double && size_to_double) {
    size_to_double -= add_char_to_str(
        str_to_double + *i, i,
        convert_num_to_char((long)integer % options.number_system, options.upper_case));
    integer /= options.number_system;
  }
  return size_to_double;
}

int double_handle_flags(char *string_for_number, Options options,
                        s21_size_t size, int i, long double number) {
    while (options.is_zero && string_for_number &&
           (size - options.flag_size > 0))  {
    if (size == 1 && options.flag_size == 1)
      break;
    string_for_number[i] = '0';
    i++;
    size--;
    options.accuracy--;
  }

  if (options.is_blank && number >= 0.0000000000001 && size) {
    string_for_number[i] = ' ';
    i++;
    size--;
  }
  if (number < 0.0000000000001 && size && !options.e) {
    string_for_number[i] = '-';
    if (options.e && options.flag_size && options.width) options.flag_size = 0;
    i++;
    size--;
  }
  if (number < 0 && size && options.e) {
    string_for_number[i] = '-';
    if (options.e && options.flag_size && options.width) options.flag_size = 0;
    i++;
    size--;
  }
  if (number > 0.0000000000001 && options.is_plus && size) {
    string_for_number[i] = '+';
    i++;
    size--;
  }

  int flag_g = 0;
    if (options.g && options.width > 8) {
      flag_g = 1;
    }

  if (size > 0 && options.is_minus == 0) {
    while ((size - options.flag_size + flag_g > 0) && string_for_number) {
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
  int i = is_nan_or_inf(string_for_number, number, options);
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
    size = add_parts_of_num_to_string(string_for_number, options, accuracy, size, &i,
                               fractional_part, integer_part);

    if (flag)
      number = -number;

    if (options.accuracy - i > 0) {  // если точность больше чем ширина
      options.accuracy -= i;
      options.is_zero = 1;
    } else
      flag = 1;

    if (size == 1 && options.is_zero == 1 && options.flag_size == 1)
      options.is_zero = 0;

    i = double_handle_flags(string_for_number, options, size, i, number);
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

  *str = '\0';
  return str;
}
// end double f F