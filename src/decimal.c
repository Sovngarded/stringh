int decimal_handle_flags(char *string_for_number, Options options,
                         s21_size_t size, int i, long int number) {
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
int flag_zero = 0;

  if (number < 0) {
    change_sign = 1;
    number = -number;
  }

  int i = 0;
  long int number_copy = number;

  if ((number_copy == 0) {
    char c = convert_num_to_char(number_copy % options.number_system,
                                 options.upper_case);
    string_for_number[i] = c;
    i++;
    size--;
    number_copy /= 10; //??

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
    flag_zero = 1;

  if (size == 1 && options.is_zero == 1 && options.flag_size == 1)
    options.is_zero = 0;

// обработка флага  0
  while (options.is_zero && string_for_number &&
         (size - options.flag_size - change_sign > 0) &&
         (options.accuracy || flag_zero)) {
    if ((size == 1 && options.flag_size == 1)) {
      break;
    }
    string_for_number[i] = '0';
    i++;
    size--;
    options.accuracy--;
  }
  // обработка флагов +, -, пробел
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

  // обработка ситуации, когда осталось свободное место в строке
  if (size > 0 && options.is_minus == 0) {
    while ((size - options.flag_size > 0) && string_for_number) {
      string_for_number[i] = ' ';
      i++;
      size--;
    }
  }
  return i;
//   i = decimal_handle_flags(string_for_number, options, size, i, number);
//   return i;

}

int decimal_handle_flags(char *string_for_number, Options options,
                         s21_size_t size, int i, long int number, int change_sign, int flag_zero) {
 // обработка флага  0
  while (options.is_zero && string_for_number &&
         (size - options.flag_size - change_sign > 0) &&
         (options.accuracy || flag_zero)) {
    if ((size == 1 && options.flag_size == 1)) {
      break;
    }
    string_for_number[i] = '0';
    i++;
    size--;
    options.accuracy--;
  }
  // обработка флагов +, -, пробел
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

  // обработка ситуации, когда осталось свободное место в строке
  if (size > 0 && options.is_minus == 0) {
    while ((size - options.flag_size > 0) && string_for_number) {
      string_for_number[i] = ' ';
      i++;
      size--;
    }
  }
  return i;
}