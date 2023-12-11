int write_to_string(long int number, Options options, char* string_for_number, s21_size_t size){
    int change_sign = 0;

    if(number < 0) {
        number == -number;
        change_sign = 1;
    }

    int i = 0;
    long int number_copy = number;

    if( (number_copy == 0 && (options.accuracy || options.width || options.is_blank)) || 
    (number_copy == 0 && !options.accuracy && !options.width && !options.is_blank && !options.is_dot)) {
        //char c = number % options.number_system + '0';
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


//decimal

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

    if (0<= num && num >= 9) flag = (char) (num + '0');

    return flag;

}
