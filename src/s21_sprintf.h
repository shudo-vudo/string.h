#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include "s21_string.h"

struct par {
  char wid_c;
  char sign_c;
  int hashtag;
  int zero;
  int long_1;
  int long_long;
  int short_1;
  int minus;
  int plus;
  int sign;
  int probel;
  int width;
  int precision;
  int prec_flag;
  int flags;
};

char* itoa(long long i);
void s21_reverse(char s[]);
void symbolcat(char* dest, char cat);
char* d_to_str(long long arg, struct par flag);
char* u_to_str(unsigned long long arg, struct par flag);
char* p_to_str(unsigned long long arg, struct par flag);
char* x_to_str(unsigned long long arg, struct par flag, char specifier,
               char* str);
char* o_to_str(unsigned long long arg, struct par flag, char* str);
char* f_to_str(long double arg, struct par flag);
char* e_to_str(long double num, struct par flag, char specifier);
char* g_to_str(long double num, struct par flag, char specifier);
void res_to_sprintf(char* res, struct par flag, char* str);

#endif  // SRC_S21_SSCANF_H_