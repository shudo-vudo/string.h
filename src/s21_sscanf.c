#include "s21_sscanf.h"

// Считывает форматированный ввод из строки.
int s21_sscanf(const char *str, const char *format, ...) {
  int result = 0;
  if ((str == s21_NULL) || (format == s21_NULL)) {
    result = -1;
  } else {
    int error = 0;
    int max_spec = s21_strlen(format) / 2;
    spec *sarray = calloc(max_spec, sizeof(spec));
    int spec_count = format_to_array(format, &sarray, &error);
    va_list args;
    va_start(args, format);
    char str_copy[1024];
    char *here = str_copy;
    s21_strcpy(here, str);
    const char *start = here;
    for (int i = 0; i < spec_count; i++) {
      char *there = s21_NULL;
      spec s = sarray[i];
      switch (s.type) {
        case 'o':
        case 'x':
        case 'X':
        case 'd':
        case 'i':
        case 'u': {
          error = parse_int(s, &here, there, args, &result);
          break;
        }
        case 'p': {
          error = parse_pointer(s, &here, there, args, &result);
          break;
        }
        case 'f':
        case 'F':
        case 'g':
        case 'G':
        case 'e':
        case 'E': {
          error = parse_double(s, &here, there, args, &result);
          break;
        }
        case 'c': {
          error = parse_char(s, &here, there, args, &result);
          break;
        }
        case 's': {
          error = parse_string(s, &here, there, args, &result);
          break;
        }
        case 'n': {
          error = parse_count(&here, str, args);
          break;
        }
        case '%': {
          error = parse_special(s, start);
          break;
        }
      }
      if (error != 0 || *here == '\0') {
        break;
      }
    }
    va_end(args);
    if (error > 0) {
      result = -1;
    }
    for (int i = 0; i < max_spec; i++) {
      free(sarray[i].str);
    }
    free(sarray);
  }
  return result;
}

// Считывание целого числа (спецификаторы oxXdiu)
int parse_int(spec s, char **here, char *there, va_list args, int *result) {
  int error = 0;
  while (isspace(**here) || **here == '\t') {
    *here += 1;
  }
  int base = 10;
  if (s.type == 'o') {
    base = 8;
  } else if (s.type == 'x' || s.type == 'X') {
    base = 16;
  }
  long _var0 = string_to_long(*here, &there, base, s.width);
  if (is_empty(*here) || (s.width == 1 && (**here == '-' || **here == '+'))) {
    if (*result == 0) {
      error = 1;
    }
    return error;
  }
  // Если мы уже дошли до конца строки, то заносим 0 в параметр функции
  if (**here == '\0' && *there == '\0') {
    if (s.is_star == 0) {
      if (s.length == 'x') {
        *(va_arg(args, long long *)) = (long long)0;
      } else {
        if (s.length == 'l') {
          *(va_arg(args, long *)) = (long)0;
        } else if (s.length == 'h') {
          *(va_arg(args, short *)) = (short)0;
        } else {
          *(va_arg(args, int *)) = (int)0;
        }
      }
    }
    // Пока мы не дошли до конца строки - сохраняем значения в параметр функции
  } else if (*here != there) {
    if (s.is_star == 0) {
      *result += 1;
      if (s.length == 'x') {
        long long _var1 = string_to_long_long(*here, &there, base, s.width);
        *(va_arg(args, long long *)) = (long long)_var1;
      } else if (s.length == 'l') {
        *(va_arg(args, long *)) = (long)_var0;
      } else if (s.length == 'h') {
        *(va_arg(args, short *)) = (short)_var0;
      } else {
        *(va_arg(args, int *)) = (int)_var0;
      }
    }
    if (s.width > s21_strlen(*here)) {
      *here += s21_strlen(*here);
    } else {
      *here = there;
    }
  }
  return error;
}

// Считывание указателя (спецификатор p)
int parse_pointer(spec s, char **here, char *there, va_list args, int *result) {
  int error = 0;
  while (isspace(**here) || **here == '\t') {
    *here += 1;
  }
  long long _var2 = string_to_long_long(*here, &there, 16, s.width);
  if (*here != there) {
    if (s.is_star == 0) {
      *result += 1;
      *(va_arg(args, long long *)) = _var2;
    }
    *here = there;
  } else {
    if (s.is_star == 0) {
      error = 2;
    }
  }
  return error;
}

// Считывание дробного числа (спецификаторы fFgGeE)
int parse_double(spec s, char **here, char *there, va_list args, int *result) {
  int error = 0;
  long double _var3 = string_to_long_double(*here, &there);
  if (*here != there) {
    if (s.length == 'L') {
      if (s.is_star == 0) {
        *result += (**here != '.');
        *(va_arg(args, long double *)) = _var3;
      }
    } else if (s.length == 'l') {
      if (s.is_star == 0) {
        *result += (**here != '.');
        *(va_arg(args, double *)) = _var3;
      }
    } else {
      if (s.is_star == 0) {
        *result += (**here != '.');
        *(va_arg(args, float *)) = _var3;
      }
    }
    *here = there;
  } else {
    if (s.is_star == 0) {
      error = 3;
    }
  }
  return error;
}

// Считывание символа (спецификатор c)
int parse_char(spec s, char **here, char *there, va_list args, int *result) {
  int error = 0;
  s21_size_t count = s.width ? s.width : 1;
  if (s21_strlen(*here) >= count) {
    if (s.is_star == 0) {
      there = va_arg(args, char *);
      s21_strncpy(there, *here, count);
      *result += 1;
      there[count] = '\0';
    }
    *here += count;
  } else {
    if (s.is_star == 0) {
      error = 4;
    }
  }
  while (**here == ' ') {
    *here += 1;
  }
  return error;
}

// Считывание строки (спецификатор s)
int parse_string(spec s, char **here, char *there, va_list args, int *result) {
  int error = 0;
  while (isspace(**here) || **here == '\t') {
    *here += 1;
  }
  s21_size_t non_space_count = s21_strcspn(*here, " \t");
  s21_size_t count = 0;
  if (s.width == 0) {
    count = non_space_count;
  } else if (non_space_count < s.width) {
    count = non_space_count;
  } else {
    count = s.width;
  }
  if (s.is_star == 0) {
    there = va_arg(args, char *);
    s21_strncpy(there, *here, count);
    there[count] = '\0';
    *result += 1;
  }
  *here += count;
  return error;
}

// Подсчет количества обработанных символов (спецификатор n)
int parse_count(char **here, const char *str, va_list args) {
  int error = 0;
  int len = (s21_strlen(str) - s21_strlen(*here));
  if (len > 0) {
    *(va_arg(args, int *)) = (s21_strlen(str) - s21_strlen(*here)) + 1;
  } else {
    *(va_arg(args, int *)) = 0;
  }
  return error;
}

// Обработка символа % и конца строки
int parse_special(spec s, const char *start) {
  int error = 0;
  char *string = (s.type == '%') ? "%" : s.str;
  if (s.is_space) {
    s21_size_t space_count = s21_strspn(start, " ");
    start += space_count;
  } else {
    s21_size_t str_len = s21_strlen(string);
    if (s21_strncmp(start, string, str_len)) {
      error = 5;
    } else {
      start += str_len;
    }
  }
  return error;
}

// Проверка строки на пустоту:
// 1 - пустая строка, 0 - не пустая строка
int is_empty(char *string) {
  int result = 1;
  if (string == s21_NULL) {
    result = 1;
  } else {
    char *new_string = string;
    while (*new_string != '\0') {
      if (isspace(*string)) {
        string++;
      } else {
        result = 0;
        break;
      }
    }
  }
  return result;
}

// Преобразование строки в int
int string_to_int(char *string) {
  int result = -1;
  int sign = 1;
  if (string) {
    result = 0;
    if (*string == '+') {
      string++;
    } else if (*string == '-') {
      sign = -1;
      string++;
    }
    while (*string) {
      if (*string < '0' || *string > '9') {
        break;
      } else {
        result = result * 10 + *string - '0';
        string++;
      }
    }
  }
  return sign * result;
}

// Преобразование строки в long
long string_to_long(const char *nptr, char **endptr, int base, int width) {
  const char *start = nptr;
  unsigned long acc;
  int c;
  unsigned long cutoff;
  int neg = 0, any, cutlim;

  do {
    c = *start++;
  } while (isspace(c));
  if (c == '+' || c == '-') {
    if (c == '-') {
      neg = 1;
    }
    c = *start++;
  }

  if (base == 16 && c == '0' && (*start == 'x' || *start == 'X')) {
    c = start[1];
    start += 2;
  }

  cutoff = neg ? -(unsigned long)LONG_MIN : LONG_MAX;
  cutlim = cutoff % (unsigned long)base;
  cutoff /= (unsigned long)base;
  int i = 0;
  if (c == '\0') {
    acc = 0;
    any = 1;
  } else {
    for (acc = 0, any = 0; (width == 0 || i < width); c = *start++, i++) {
      if (isdigit(c)) {
        c -= '0';
      } else if (isalpha(c)) {
        c -= isupper(c) ? 'A' - 10 : 'a' - 10;
      } else {
        break;
      }
      if (c >= base) {
        break;
      }
      if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) {
        any = -1;
      } else {
        any = 1;
        acc *= base;
        acc += c;
      }
    }
  }
  if (any < 0) {
    acc = neg ? LONG_MIN : LONG_MAX;
  } else if (neg) {
    acc = -acc;
  }
  if (endptr != 0) {
    *endptr = (char *)(any ? start - 1 : nptr);
  }
  return (acc);
}

// Преобразование строки в long long
long long string_to_long_long(const char *nptr, char **endptr, int base,
                              int width) {
  const char *start = nptr;
  long long acc = 0;
  int c;
  long long cutoff;
  int neg = 0, any = 0, cutlim;

  do {
    c = *start++;
  } while (isspace(c));
  if (c == '+' || c == '-') {
    if (c == '-') {
      neg = 1;
    }
    c = *start++;
  }

  if ((base == 0 || base == 16) && c == '0' &&
      (*start == 'x' || *start == 'X')) {
    c = start[1];
    start += 2;
    base = 16;
  }
  if (base == 0) base = c == '0' ? 8 : 10;

  cutoff = neg ? -(unsigned long long)LLONG_MIN : LLONG_MAX;
  cutlim = cutoff % (unsigned long long)base;
  cutoff /= (unsigned long long)base;
  int i = 0;
  while (width == 0 || i < width) {
    if (isdigit(c))
      c -= '0';
    else if (isalpha(c))
      c -= isupper(c) ? 'A' - 10 : 'a' - 10;
    else
      break;
    if (c >= base) break;
    if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim)) {
      any = -1;
    } else {
      any = 1;
      acc *= base;
      acc += c;
    }
    c = *start++;
    i++;
  }
  if (any < 0) {
    acc = neg ? LLONG_MIN : LLONG_MAX;
  } else if (neg) {
    acc = -acc;
  }
  if (endptr != 0) {
    *endptr = (char *)(any ? start - 1 : nptr);
  }
  return (acc);
}

// Преобразование строки в double
long double string_to_double(const char *s) {
  long double a = 0.0;
  int e = 0;
  int c;
  int sign = 1;
  c = *s++;
  while (isspace(c)) {
    c = *s++;
  }
  if (c == '+' || c == '-') {
    if (c == '-') {
      sign = -1;
    }
    c = *s++;
  }

  while (c != '\0' && isdigit(c)) {
    a = a * 10.0 + (c - '0');
    c = *s++;
  }
  if (c == '.') {
    while ((c = *s++) != '\0' && isdigit(c)) {
      a = a * 10.0 + (c - '0');
      e = e - 1;
    }
  }
  a = a * sign;
  if (c == 'e' || c == 'E') {
    int esign = 1;
    int ei = 0;
    c = *s++;
    if (c == '+') {
      c = *s++;
    } else if (c == '-') {
      c = *s++;
      esign = -1;
    }
    while (isdigit(c)) {
      ei = ei * 10 + (c - '0');
      c = *s++;
    }
    e += ei * esign;
  }
  while (e > 0) {
    a *= 10.0;
    e--;
  }
  while (e < 0) {
    a *= 0.1;
    e++;
  }
  return a;
}

// Преобразование строки в long dobule
long double string_to_long_double(char *str, char **ptr) {
  char *p;
  if (ptr == (char **)0) {
    return string_to_double(str);
  }
  p = str;
  while (isspace(*p)) {
    p++;
  }
  if (*p == '+' || *p == '-') {
    p++;
  }

  // INF or INFINITY
  if ((p[0] == 'i' || p[0] == 'I') && (p[1] == 'n' || p[1] == 'N') &&
      (p[2] == 'f' || p[2] == 'F')) {
    if ((p[3] == 'i' || p[3] == 'I') && (p[4] == 'n' || p[4] == 'N') &&
        (p[5] == 'i' || p[5] == 'I') && (p[6] == 't' || p[6] == 'T') &&
        (p[7] == 'y' || p[7] == 'Y')) {
      *ptr = p + 8;
      return INFINITY;
    } else {
      *ptr = p + 3;
      return INFINITY;
    }
  }
  // NAN
  if ((p[0] == 'n' || p[0] == 'N') && (p[1] == 'a' || p[1] == 'A') &&
      (p[2] == 'n' || p[2] == 'N')) {
    p += 3;
    if (*p == '(') {
      ++p;
      while (*p != '\0' && *p != ')') {
        ++p;
      }
      if (*p == ')') {
        ++p;
      }
    }
    *ptr = p;
    return NAN;
  }
  if (isdigit(*p) || *p == '.') {
    int got_dot = 0;
    while (isdigit(*p) || (!got_dot && *p == '.')) {
      if (*p == '.') {
        got_dot = 1;
      }
      ++p;
    }
    if (*p == 'e' || *p == 'E') {
      int i;
      i = 1;
      if (p[i] == '+' || p[i] == '-') {
        ++i;
      }
      if (isdigit(p[i])) {
        while (isdigit(p[i])) {
          ++i;
        }
        *ptr = p + i;
        return string_to_double(str);
      }
    }
    while (isspace(*p)) {
      p++;
    }
    *ptr = p;
    return string_to_double(str);
  }
  *ptr = str;
  return 0.0;
}

// Подсчет и сохранение пробелов
s21_size_t save_spaces(char *from, spec *s) {
  s21_size_t space_count = s21_strspn(from, " ");
  if (space_count) {
    char str_static[1024];
    char *str = str_static;
    s21_strncpy(str, from, space_count);
    str[space_count] = '\0';
    s->str = str;
    s->is_space = 1;
    *from += space_count;
  }
  return space_count;
}

// Парсим спецификатор из строки from определенного количества символов size
void parse_spec(char *from, int size, spec *s, int *error) {
  s->str = (char *)calloc((size + 1), sizeof(char));
  s21_strncpy(s->str, from, size);
  s->str[size] = '\0';
  s->type = ' ';
  s->width = 0;
  s->length = ' ';
  s->is_star = 0;
  s->is_space = 0;

  char *this = s->str;
  if (s21_strlen(this) > 1) {
    this ++;
  }
  if (*this == '%' || *this == '\0') {
    s->is_star = 0;
    s->type = '%';
  } else {
    if (*this == '*') {
      s->is_star = 1;
      this ++;
    } else {
      s->is_star = 0;
      if (isdigit(*this)) {
        s->width = string_to_int(this);
        // TODO: Проверить, заходят ли в цикл тесты
        while (isdigit(*this)) {
          this ++;
        }
      }
      if (*this == 'h' || *this == 'l' || *this == 'L') {
        s->length = *this;
        this ++;
        if (*this == 'l') {
          s->length = 'x';
          this ++;
        }
      }
    }
    if (s21_strchr("cdieEfgGosuxXpn%", *this) != s21_NULL) {
      s->type = *this;
    } else {
      *error = 6;
    }
  }
  return;
}

// Форматную строку раскладываем в массив спецификаторов
int format_to_array(const char *format, spec **sarray, int *error) {
  int result = 0;
  char from_static[1024];
  char *from = from_static;
  char *next = s21_NULL;
  s21_strcpy(from, format);
  while (*from) {
    int spaces = save_spaces(from, *sarray + result);
    if (spaces) {
      from += spaces;
    } else {
      from = s21_strchr(from, '%');
      if (from == s21_NULL) {
        break;
      } else {
        next = s21_strchr(from + 1, '%');
        if (next == s21_NULL) {
          next = from + s21_strlen(from);
        }
        *error = 0;
        parse_spec(from, next - from, *sarray + result, error);
        result++;
        from++;
      }
    }
  }
  if (!sarray) {
    result = 0;
  }
  return result;
}
