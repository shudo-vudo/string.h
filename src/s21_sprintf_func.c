#include "s21_sprintf.h"

void symbolcat(char *dest, char cat) {
  s21_size_t len = s21_strlen(dest);
  dest[len] = cat;
  dest[len + 1] = '\0';
}

void s21_reverse(char s[]) {
  int i, j;
  char c;
  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

char *itoa(long long i) {
  long long arg = i;
  // int dig;
  char *res = (char *)malloc(sizeof(char) * 2);
  if (res && i != 0) {
    int len = 1;
    int k = 0;
    do {
      char *res_tmp = realloc(res, sizeof(char) * (len + 1));
      if (res_tmp) {
        res = res_tmp;
      }
      len++;
      int dig = arg % 10;
      if (dig < 0) dig *= -1;
      res[k] = dig + '0';
      k++;
      arg /= 10;
    } while (arg != 0);

    res[k] = '\0';

    for (k = 0; k < (int)s21_strlen(res) / 2; k++) {
      char tmp = res[k];
      res[k] = res[(int)s21_strlen(res) - k - 1];
      res[(int)s21_strlen(res) - k - 1] = tmp;
    }
    // if (i < 0) {
    //   char *tmp = s21_insert(res, "-", 0);
    //   free(res);
    //   res = tmp;
    // }
  } else if (res && i == 0) {
    s21_strcpy(res, "0\0");
  }
  return res;
}

char *d_to_str(long long arg, struct par flag) {
  char *res = s21_NULL;
  if (arg == 0 && flag.precision == 0) {
    res = malloc(sizeof(char));
    // if (res) free(res);
  } else {
    char *chislo = itoa(arg);
    long long len = (long long)s21_strlen(chislo);
    if (flag.precision > len) {
      len = len + (flag.precision - len);
    }
    if ((arg >= 0 && (flag.sign)) || arg < 0) {
      len++;
    }
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (res) {
      *res = '\0';
      if (arg < 0) {
        s21_strcat(res, "-");
      } else {
        if (flag.sign) {
          symbolcat(res, flag.sign_c);
        }
      }
      if (flag.precision > (long long)s21_strlen(chislo)) {
        // Можно было бы использовать memset, но потом ещё терминатор
        // придётся дописывать

        for (long unsigned int i = 0; i < flag.precision - s21_strlen(chislo);
             i++)
          s21_strcat(res, "0");
      }
      s21_strcat(res, chislo);
    }
    free(chislo);
  }
  return res;
}

char *u_to_str(unsigned long long arg, struct par flag) {
  char *res = s21_NULL;
  char *chislo = (char *)malloc(sizeof(char) * 2);
  s21_memset(chislo, '\0', 2);
  if (chislo) {
    int l = 1;
    s21_size_t k = 0;
    do {
      char *str_tmp = realloc(chislo, sizeof(char) * (l + 1));
      if (str_tmp) {
        chislo = str_tmp;
      }
      l++;
      int dig = arg % 10;
      if (dig < 0) dig *= -1;
      chislo[k] = dig + '0';
      k++;
      arg /= 10;
    } while (arg != 0);

    chislo[k] = '\0';

    for (k = 0; k < s21_strlen(chislo) / 2; k++) {
      char tmp = chislo[k];
      chislo[k] = chislo[s21_strlen(chislo) - k - 1];
      chislo[s21_strlen(chislo) - k - 1] = tmp;
    }
    s21_size_t len = s21_strlen(chislo);
    if (flag.precision > (int)len) {
      len = len + (flag.precision - len);
    }
    res = (char *)malloc(sizeof(char) * (len + 1));
    if (res) {
      s21_memset(res, '\0', len + 1);
      if (flag.precision > (int)s21_strlen(chislo)) {
        for (long unsigned int i = 0; i < flag.precision - s21_strlen(chislo);
             i++)
          s21_strcat(res, "0");
      }
      s21_strcat(res, chislo);
    }
    free(chislo);
  }
  return res;
}

char *p_to_str(unsigned long long arg, struct par flag) {
  char *res;
  if (arg == 0) {
#if defined(UBUNTU)
    res = (char *)malloc(sizeof(char) * 6);
    s21_memset(res, 0, 5);
    s21_strcat(res, "(nil)");
    res[5] = '\0';
#else
    res = (char *)malloc(sizeof(char) * 4);
    s21_memset(res, 0, 3);
    s21_strcat(res, "0x0\0");
    res[3] = '\0';
#endif
  } else {
    res = (char *)malloc(sizeof(char));
    int i = 0;
    char *p_res = "0123456789abcdef";
    do {
      res = (char *)realloc(res, sizeof(char) * (i + 1));
      res[i++] = p_res[arg % 16];
      arg /= 16;
    } while (arg > 0);
    while (i < 1) {
      res = (char *)realloc(res, sizeof(char) * (i + 1));
      res[i++] = '0';
    }
    // if (hashtag == 1 && is_zero == 0 && specifier != 'p') {
    //   str = (char *)realloc(str, sizeof(char) * (i + 2));
    //   str[i++] = specifier;
    //   str[i++] = '0';
    // }
    res = (char *)realloc(res, sizeof(char) * (i + 1));
    res[i] = '\0';
    if (flag.zero == 1 && flag.minus == 0 &&
        (s21_size_t)flag.width > s21_strlen(res) + 2) {
      s21_reverse(res);
      s21_size_t to_append_len = s21_strlen(res);
      int spaces_len = (s21_size_t)flag.width - to_append_len;
      char *to_append_ext = (char *)realloc(
          res, sizeof(char) * (spaces_len + 1 + (int)to_append_len));
      s21_memset(to_append_ext + to_append_len, '\0', spaces_len + 1);
      res = to_append_ext;
      s21_memmove(res + spaces_len, res, to_append_len);
      s21_memset(res, flag.wid_c, spaces_len);
      *(res + s21_strlen(res) + to_append_len + spaces_len) = '\0';
      res[0] = '0';
      res[1] = 'x';
      flag.width = 0;
    } else {
      res = (char *)realloc(res, sizeof(char) * (i + 3));
      res[i] = 'x';
      res[i + 1] = '0';
      res[i + 2] = '\0';
      s21_reverse(res);
    }
  }
  return res;
}

char *x_to_str(unsigned long long arg, struct par flag, char specifier,
               char *str) {
  char *res;
  if (arg == 0) {
    if (flag.hashtag == 1) {
      res = (char *)malloc(sizeof(char) * 4);
      s21_memset(res, 0, 3);
      if (specifier == 'x') {
        s21_strcat(res, "0x0");
      } else {
        s21_strcat(res, "0X0");
      }
      res[3] = '\0';
    } else {
      res = (char *)malloc(sizeof(char) * 2);
      s21_memset(res, 0, 1);
      res[0] = '0';
      res[1] = '\0';
    }
  } else {
    res = (char *)malloc(sizeof(char));
    int i = 0;
    char *p_res;
    if (specifier == 'x') {
      p_res = "0123456789abcdef";
    } else {
      p_res = "0123456789ABCDEF";
    }
    do {
      res = (char *)realloc(res, sizeof(char) * (i + 1));
      res[i++] = p_res[arg % 16];
      arg /= 16;
    } while (arg > 0);
    while (i < flag.precision) {
      res = (char *)realloc(res, sizeof(char) * (i + 1));
      res[i++] = '0';
    }
    res = (char *)realloc(res, sizeof(char) * (i + 1));
    res[i] = '\0';
    if (flag.zero == 1 && flag.minus == 0 &&
        (s21_size_t)flag.width > s21_strlen(res) + 2) {
      s21_reverse(res);
      s21_size_t to_append_len = s21_strlen(res);
      int spaces_len = (s21_size_t)flag.width - to_append_len;
      char *to_append_ext = (char *)realloc(
          res, sizeof(char) * (spaces_len + 1 + (int)to_append_len));
      s21_memset(to_append_ext + to_append_len, '\0', spaces_len + 1);
      res = to_append_ext;
      s21_memmove(res + spaces_len, res, to_append_len);
      s21_memset(res, flag.wid_c, spaces_len);
      *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
      if (flag.hashtag == 1) {
        res[1] = specifier;
      }
      flag.width = 0;
    } else if (flag.hashtag == 1) {
      res = (char *)realloc(res, sizeof(char) * (i + 3));
      res[i] = specifier;
      res[i + 1] = '0';
      res[i + 2] = '\0';
      s21_reverse(res);
    } else {
      res = (char *)realloc(res, sizeof(char) * (i + 1));
      res[i] = '\0';
      s21_reverse(res);
    }
  }
  return res;
}

char *o_to_str(unsigned long long arg, struct par flag, char *str) {
  char *res;
  if (arg == 0) {
    res = (char *)malloc(sizeof(char) * 2);
    s21_memset(res, 0, 1);
    s21_strcat(res, "0\0");
    res[1] = '\0';
  } else {
    res = (char *)malloc(sizeof(char));
    int i = 0;
    char *p_res = "012345678";
    do {
      res = (char *)realloc(res, sizeof(char) * (i + 1));
      res[i++] = p_res[arg % 8];
      arg /= 8;
    } while (arg > 0);
    if (flag.hashtag == 1) {
      flag.precision--;
      // 123344566 rand.zero size of 34
    }
    while (i < flag.precision) {
      res = (char *)realloc(res, sizeof(char) * (i + 1));
      res[i++] = '0';
    }
    res = (char *)realloc(res, sizeof(char) * (i + 1));
    res[i] = '\0';
    if (flag.zero == 1 && flag.minus == 0 &&
        (s21_size_t)flag.width > s21_strlen(res) + 1) {
      s21_reverse(res);
      s21_size_t to_append_len = s21_strlen(res);
      int spaces_len = (s21_size_t)flag.width - to_append_len;
      char *to_append_ext = (char *)realloc(
          res, sizeof(char) * (spaces_len + 1 + (int)to_append_len));
      s21_memset(to_append_ext + to_append_len, '\0', spaces_len + 1);
      res = to_append_ext;
      s21_memmove(res + spaces_len, res, to_append_len);
      s21_memset(res, flag.wid_c, spaces_len);
      *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
      flag.width = 0;
    } else if (flag.hashtag == 1) {
      res = (char *)realloc(res, sizeof(char) * (i + 2));
      res[i] = '0';
      res[i + 1] = '\0';
      s21_reverse(res);
    } else {
      res = (char *)realloc(res, sizeof(char) * (i + 2));
      res[i] = '\0';
      s21_reverse(res);
    }
  }
  return res;
}

char *f_to_str(long double arg, struct par flag) {
  char *res = s21_NULL;
  char *float_part_str = s21_NULL;
  int _sign = 0;
  if (arg < 0) {
    _sign = -1;
    arg = -1 * arg;
  }
  long int_part = (long)arg;
  long double float_part_pow = (arg - int_part) * pow(10, flag.precision);
  long long float_part = (long long)float_part_pow;
  long double diff = float_part_pow - float_part;
  s21_size_t len = 1;
  if (diff > 0.5) {
    float_part++;
    if (float_part >= pow(10, flag.precision)) {
      float_part = 0;
      int_part++;
    }
  }
  if (flag.precision == 0) {
    diff = arg - (long double)int_part;
    // Если дробная часть 0.5 или более И число нечётное
    if (diff >= 0.5 && (int_part & 1)) {
      // округляем в большую сторону
      int_part++;
    }
  } else {
    float_part_str = itoa(float_part);
  }
  char *int_part_str = itoa(int_part);

  len = s21_strlen(int_part_str) +
        ((float_part_str) ? s21_strlen(float_part_str) : 0);
  res = (char *)malloc(sizeof(char) * ((int)len + 13 + flag.precision));

  if (res) {
    *res = '\0';
    if (_sign == -1) {
      s21_strcat(res, "-");
    } else if (flag.sign) {
      symbolcat(res, flag.sign_c);
    }

    s21_strcat(res, int_part_str);

    if (float_part_str) {
      s21_strcat(res, ".");
      // Пробуем пофиксить одну десятитысячную
      s21_size_t fp_len = s21_strlen(float_part_str);
      while ((int)fp_len < flag.precision) {
        s21_strcat(res, "0");
        fp_len++;
      }
      // Конец фикса
      s21_strcat(res, float_part_str);
    }
    if (flag.precision == 0 && flag.hashtag == 1) {
      s21_strcat(res, ".");
    }

    free(float_part_str);
    if (int_part_str) free(int_part_str);
  }
  return res;
}

char *e_to_str(long double num, struct par flag, char specifier) {
  int i = 0;
  int pow_count = 0;
  char *str = (char *)malloc(sizeof(char));
  int sign = 1;
  int is_zero = 0;
  if (num == 0.0) {
    is_zero = 1;
  }
  if (num < 0) {
    sign = -1;
    num = -num;
  }
  //  -0.0012003 = -1.200300e-03
  // 120.0025 = 1.200025e+02
  if (num < 1 && is_zero == 0) {
    do {
      num *= 10;
      pow_count--;
    } while (num < 1);
  } else if (num > 10) {
    do {
      num /= 10;
      pow_count++;
    } while (num > 10);
  }
  long integer_part = (long)num;
  double float_part = num - (double)integer_part;
  if (specifier == 'g' || specifier == 'G') {
    if (integer_part != 0) {
      flag.precision--;
    }
  }
  if (flag.precision != 0) {
    for (int j = 0; j < flag.precision; j++) {  //   1.00001 false result
      float_part *= 10;
    }
    long current_part =
        (long)(float_part + 0.5);  // for successful round    check 1.9999996
    long powed = pow(10, flag.precision);
    if (current_part >= powed) {
      current_part = current_part - powed;
      integer_part++;
      // printf("my %c %ld\n", specifier, integer_part);
      if (integer_part >= 10) {
        integer_part /= 10;
        pow_count++;
      }
    }

    int pow_sign = 1;
    if (pow_count < 0) {
      pow_sign = -1;
      pow_count = -pow_count;
    }
    if (pow_count < 10) {
      str = (char *)realloc(str, sizeof(char) * (i + 2));
      str[i++] = pow_count + 48;
      str[i++] = '0';
    } else {
      do {
        str = (char *)realloc(str, sizeof(char) * (i + 1));
        str[i++] = pow_count % 10 + 48;
        pow_count /= 10;
      } while (pow_count > 0);
    }
    if (specifier == 'g' || specifier == 'G') {
      specifier = (specifier == 'g') ? 'e' : 'E';
    }
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = (pow_sign == 1) ? '+' : '-';
    str[i++] = specifier;
    int temp_accuracy_num = flag.precision;
    while (temp_accuracy_num > 0 && current_part > 0) {
      temp_accuracy_num--;
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = current_part % 10 + 48;
      current_part /= 10;
    }
    while (temp_accuracy_num > 0) {
      str = (char *)realloc(str, sizeof(char) * (i + 1));
      str[i++] = '0';
      temp_accuracy_num--;
    }
  } else {
    if (float_part > 0.5) {
      integer_part++;
      if (integer_part >= 10) {
        integer_part /= 10;
        pow_count++;
      }
    }
    int pow_sign = 1;
    if (pow_count < 0) {
      pow_sign = -1;
      pow_count = -pow_count;
    }
    if (pow_count < 10) {
      str = (char *)realloc(str, sizeof(char) * (i + 2));
      str[i++] = pow_count + 48;
      str[i++] = '0';
    } else {
      do {
        str = (char *)realloc(str, sizeof(char) * (i + 1));
        str[i++] = pow_count % 10 + 48;
        pow_count /= 10;
      } while (pow_count > 0);
    }
    if (specifier == 'g' || specifier == 'G') {
      specifier = (specifier == 'g') ? 'e' : 'E';
    }
    str = (char *)realloc(str, sizeof(char) * (i + 2));
    str[i++] = (pow_sign == 1) ? '+' : '-';
    str[i++] = specifier;
  }

  if (!(flag.precision == 0 && flag.hashtag == 0)) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '.';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i++] = integer_part + 48;  // '48' = 0
  if (sign < 0) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '-';
  } else if (flag.plus == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = '+';
  } else if (flag.probel == 1) {
    str = (char *)realloc(str, sizeof(char) * (i + 1));
    str[i++] = ' ';
  }
  str = (char *)realloc(str, sizeof(char) * (i + 1));
  str[i] = '\0';
  s21_reverse(str);
  return str;
}

int g_decision(double num,
               struct par flag) {  // result = 1 is 'e', result = 0 is 'f'
  int result = 0;
  int pow_count = 0;
  int is_zero = 0;
  if (num == 0.0) {
    is_zero = 1;
  }
  if (num < 0) {
    num = -num;
  }
  if (num < 1 && is_zero == 0) {
    do {
      num *= 10;
      pow_count--;
    } while (num < 1);
  } else if (num > 10) {
    do {
      num /= 10;
      pow_count++;
    } while (num > 10);
  }
  if (pow_count < -4 || pow_count >= flag.precision) {
    result = 1;
  }
  return result;
}

char *g_to_str(long double num, struct par flag, char specifier) {
  char *str;

  if (flag.precision == 0) {
    flag.precision = 1;
  }
  if (g_decision(num, flag) == 1) {
    str = e_to_str(num, flag, specifier);
    specifier = (specifier == 'g') ? 'e' : 'E';
    if (flag.hashtag == 0) {
      int j = 0;
      char *str_exp = (char *)malloc(sizeof(char));
      int i = s21_strlen(str) - 1;
      while (str[i] != specifier) {
        str_exp = (char *)realloc(str_exp, sizeof(char) * (j + 1));
        str_exp[j++] = str[i];
        i--;
      }
      str_exp = (char *)realloc(str_exp, sizeof(char) * (j + 2));
      str_exp[j++] = str[i];
      //
      str[i] = '\0';
      str_exp[j] = '\0';
      s21_reverse(str_exp);
      i--;
      if (str[i] == '0') {
        while (str[i] == '0') {
          i--;
        }
        if (str[i] == '.') {
          str[i] = '\0';
        } else {
          str[i + 1] = '\0';
        }
      }
      str = (char *)realloc(
          str, sizeof(char) * (s21_strlen(str) + s21_strlen(str_exp) + 1));
      s21_strcat(str, str_exp);
      free(str_exp);
    }
  } else {
    long int_part = (long)num;
    int counter = 0;
    while (int_part != 0) {
      counter++;
      int_part /= 10;
    }
    if (flag.precision > counter) {
      flag.precision -= counter;
      str = f_to_str(num, flag);
      flag.precision += counter;
    } else {
      str = f_to_str(num, flag);
    }
    if (s21_strlen(str) > (long unsigned)flag.precision) {
      int significant_num_count = 0;
      int i = 0;
      while ((long unsigned)i < s21_strlen(str) - 1 &&
             (str[i] < '1' || str[i] > '9')) {
        i++;
      }
      while ((long unsigned)i < s21_strlen(str)) {
        if (str[i] >= '0' && str[i] <= '9') {
          significant_num_count++;
        }
        if (significant_num_count > flag.precision) {
          str[i] = '\0';
        }
        i++;
      }
    }
    if (flag.hashtag == 0) {
      int i = s21_strlen(str) - 1;
      while (str[i] == '0') {
        i--;
      }
      if (str[i] == '.') {
        str[i] = '\0';
      } else {
        str[i + 1] = '\0';
      }
    }
  }
  return str;
}

void res_to_sprintf(char *res, struct par flag, char *str) {
  if (flag.width != 0 && (s21_size_t)flag.width > s21_strlen(res)) {
    // Добавить пробелы слева или справа
    s21_size_t to_append_len = s21_strlen(res);
    int spaces_len = (s21_size_t)flag.width - to_append_len;
    char *to_append_ext = (char *)realloc(
        res, sizeof(char) * (spaces_len + 1 + (int)to_append_len));
    s21_memset(to_append_ext + to_append_len, '\0', spaces_len + 1);
    if (to_append_ext) {
      res = to_append_ext;
      if (flag.minus) {
        s21_memset(res + to_append_len, flag.wid_c, spaces_len);
        *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
      } else {
        s21_memmove(res + spaces_len, res, to_append_len);
        s21_memset(res, flag.wid_c, spaces_len);
        *(str + s21_strlen(str) + to_append_len + spaces_len) = '\0';
      }
      s21_strcat(str, res);
      free(res);
    }
  } else {
    s21_strcat(str, res);
    free(res);
  }
}