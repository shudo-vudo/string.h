#include "s21_sprintf.h"

#include <stdarg.h>

int s21_sprintf(char *str, const char *format, ...) {
  *str = '\0';
  va_list ap;
  va_start(ap, format);
  for (int i = 0; i < (int)s21_strlen(format); i++) {
    if (format[i] == '%') {
      i++;
      char wid[5] = "\0";
      struct par flag = {0};
      flag.wid_c = ' ';
      flag.sign_c = '+';
      int flags = 0;
      while (flags != 1) {
        switch (format[i]) {
          case '-': {
            flag.minus = 1;
            if (flag.zero == 1) {
              flag.zero = 0;
              flag.wid_c = ' ';
            }
            i++;
            break;
          }
          case '0': {
            i++;
            if (flag.minus == 0) {
              flag.zero = 1;
              flag.wid_c = '0';
            }
            break;
          }
          case ' ': {
            flag.sign = 1;
            i++;
            if (flag.plus == 0) {
              flag.probel = 1;
              flag.sign_c = ' ';
            }
            break;
          }
          case '+': {
            flag.sign = 1;
            flag.plus = 1;
            if (flag.probel == 1) {
              flag.probel = 0;
              flag.sign_c = '+';
            }
            i++;
            break;
          }
          case '#': {
            flag.hashtag = 1;
            i++;
            break;
          }
          default: {
            flags = 1;
          }
        }
      }
      if (format[i] == '*') {
        flag.width = va_arg(ap, int);
        if (flag.width < 0) {
          flag.width *= -1;
        }
        i++;
      } else if (format[i] >= '0' && format[i] <= '9') {
        int width_counter = 0;
        while (format[i] >= '0' && format[i] <= '9') {
          symbolcat(wid, format[i]);
          i++;
          width_counter++;
          if (width_counter == 4 && format[i] >= '0' && format[i] <= '9') {
            return -1;
          }
        }
        flag.width = atoi(wid);
      }
      if (format[i] == '.') {
        i++;
        flag.prec_flag = 1;
        if (format[i] == '*') {
          flag.precision = va_arg(ap, int);
          if (flag.precision <= 0) {
            flag.precision = 0;
          }
          i++;
        } else {
          char prec[5] = "\0";
          int prec_counter = 0;
          while (format[i] >= '0' && format[i] <= '9') {
            symbolcat(prec, format[i]);
            i++;
            prec_counter++;
            if (prec_counter == 4 && format[i] >= '0' && format[i] <= '9') {
              return -1;
            }
          }
          flag.precision = atoi(prec);
        }
      }
      if (format[i] == 'l') {
        i++;
        flag.long_1 = 1;
      }
      if (format[i] == 'L') {
        i++;
        flag.long_long = 1;
      }
      if (format[i] == 'h') {
        i++;
        flag.short_1 = 1;
      }
      if (format[i] == 'n') {
        int *v;
        v = va_arg(ap, int *);
        *v = (int)s21_strlen(str);
      }
      if (format[i] == '%') {
        if (flag.minus == 0) {
          if (flag.width != 0) {
            for (int i = 1; i < flag.width; i++) {
              symbolcat(str, flag.wid_c);
            }
          }
          symbolcat(str, '%');
        } else {
          symbolcat(str, '%');
          if (flag.width != 0) {
            for (int i = 1; i < flag.width; i++) {
              symbolcat(str, flag.wid_c);
            }
          }
        }
      }
      if (format[i] == 'd' || format[i] == 'i') {
        long long arg;
        if (flag.long_1) {
          arg = va_arg(ap, long long);
        } else if (flag.short_1) {
          int tmp = va_arg(ap, int);
          short int tmp2 = (short int)tmp;
          arg = tmp2;
        } else {
          arg = va_arg(ap, int);
        }
        if (flag.prec_flag == 0) {
          flag.precision = 1;
        }
        char *res = d_to_str(arg, flag);
        res_to_sprintf(res, flag, str);
      }
      if (format[i] == 'c') {
        if (flag.width != 0) {
          if (flag.minus == 0) {
            for (int i = 0; i < flag.width - 1; i++) {
              symbolcat(str, flag.wid_c);
            }
            symbolcat(str, va_arg(ap, int));
          } else if (flag.minus == 1) {
            symbolcat(str, va_arg(ap, int));
            for (int i = 0; i < flag.width - 1; i++) {
              symbolcat(str, flag.wid_c);
            }
          }
        } else {
          symbolcat(str, va_arg(ap, int));
        }
      }
      if (format[i] == 's') {
        char *s = va_arg(ap, char *);
        int length = s21_strlen(s);
        if (length > flag.precision && flag.prec_flag) {
          length -= length - flag.precision;
        }
        if (flag.width != 0) {
          if (flag.minus == 0) {
            for (int i = 0; i < flag.width - (int)length; i++) {
              symbolcat(str, flag.wid_c);
            }
            if (flag.prec_flag == 0) {
              s21_strcat(str, s);
            } else {
              s21_strncat(str, s, flag.precision);
            }
          } else if (flag.minus == 1) {
            if (flag.prec_flag == 0) {
              s21_strcat(str, s);
            } else {
              s21_strncat(str, s, flag.precision);
            }
            for (int i = 0; i < flag.width - (int)length; i++) {
              symbolcat(str, flag.wid_c);
            }
          }
        } else {
          if (flag.prec_flag == 0) {
            s21_strcat(str, s);
          } else {
            s21_strncat(str, s, flag.precision);
          }
        }
      }
      if (format[i] == 'u') {
        unsigned long long arg;
        if (flag.long_1) {
          arg = va_arg(ap, unsigned long long);
        } else if (flag.short_1) {
          unsigned int tmp = va_arg(ap, unsigned int);
          unsigned short tmp2 = (unsigned short)tmp;
          arg = tmp2;
        } else {
          arg = va_arg(ap, unsigned int);
        }
        char *res = u_to_str(arg, flag);
        res_to_sprintf(res, flag, str);
      }
      if (format[i] == 'f' || format[i] == 'F') {
        if (flag.prec_flag == 0) {
          flag.precision = 6;
        }
        long double arg;
        if (flag.long_1) {
          arg = va_arg(ap, double);
        } else if (flag.long_long) {
          arg = va_arg(ap, long double);
        } else {
          arg = va_arg(ap, double);
        }
        char *res = f_to_str(arg, flag);
        res_to_sprintf(res, flag, str);
      }
      if (format[i] == 'p') {
        unsigned long long arg = va_arg(ap, unsigned long long);
        char *res = p_to_str(arg, flag);
        res_to_sprintf(res, flag, str);
      }
      if (format[i] == 'x' || format[i] == 'X') {
        unsigned long long arg;
        if (flag.long_1 == 1) {
          arg = va_arg(ap, unsigned long);
        } else if (flag.long_long == 1) {
          arg = va_arg(ap, unsigned long long);
        } else if (flag.short_1 == 1) {
          arg = va_arg(ap, unsigned int);
          unsigned short int tmp = (unsigned short)arg;
          arg = tmp;
        } else {
          arg = va_arg(ap, unsigned int);
        }
        char *res = x_to_str(arg, flag, format[i], str);
        res_to_sprintf(res, flag, str);
      }
      if (format[i] == 'o') {
        unsigned long long arg;
        if (flag.long_1 == 1) {
          arg = va_arg(ap, unsigned long);
        } else if (flag.long_long == 1) {
          arg = va_arg(ap, unsigned long long);
        } else if (flag.short_1 == 1) {
          arg = va_arg(ap, unsigned int);
          unsigned short int tmp = (unsigned short)arg;
          arg = tmp;
        } else {
          arg = va_arg(ap, unsigned int);
        }
        if (flag.zero && flag.prec_flag) {
          flag.zero = 0;
          flag.wid_c = ' ';
        }
        char *res = o_to_str(arg, flag, str);
        res_to_sprintf(res, flag, str);
      }
      if (format[i] == 'g' || format[i] == 'G') {
        long double arg;
        if (flag.long_1 == 1) {
          arg = va_arg(ap, double);
        } else if (flag.long_long == 1) {
          arg = va_arg(ap, long double);
        } else {
          arg = va_arg(ap, double);
        }
        if (flag.prec_flag == 0) {
          flag.precision = 6;
        }
        char *res = g_to_str(arg, flag, format[i]);
        res_to_sprintf(res, flag, str);
      }
      if (format[i] == 'e' || format[i] == 'E') {
        long double arg;
        if (flag.long_1 == 1) {
          arg = va_arg(ap, double);
        } else if (flag.long_long == 1) {
          arg = va_arg(ap, long double);
        } else {
          arg = va_arg(ap, double);
        }
        if (flag.prec_flag == 0) {
          flag.precision = 6;
        }
        char *res = e_to_str(arg, flag, format[i]);
        res_to_sprintf(res, flag, str);
      }
    } else {
      symbolcat(str, format[i]);
      symbolcat(str, '\0');
    }
  }
  va_end(ap);
  return s21_strlen(str);
}