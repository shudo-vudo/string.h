#ifndef SRC_S21_SSCANF_H_
#define SRC_S21_SSCANF_H_

#include "s21_string.h"

#define LONG_MAX 0xFFFFFFFF
#define LONG_MIN 0x80000000
#define LLONG_MAX 0xFFFFFFFFFFFFFFFF
#define LLONG_MIN 0x8000000000000000

typedef struct Spec {
  // Спецификатор: c, d, i, e, E, f, g, G, o, s, u, x, X, p, n, %
  char type;
  // Ширина
  s21_size_t width;
  // Длина: h, l, L, ll(x)
  char length;
  // Указана ли звезда после %: 0 - не указана, 1 - указана
  int is_star;
  // Состоит ли этот блок только из пробелов
  int is_space;
  // Указатель на блок строки, относящейся к этому спецификатору
  char *str;
} spec;

int is_empty(char *string);
int string_to_int(char *string);
long string_to_long(const char *nptr, char **endptr, int base, int width);
long long string_to_long_long(const char *nptr, char **endptr, int base,
                              int width);
long double string_to_double(const char *s);
long double string_to_long_double(char *str, char **ptr);
s21_size_t save_spaces(char *from, spec *s);
void parse_spec(char *from, int size, spec *s, int *error);
int format_to_array(const char *format, spec **sarray, int *error);

int parse_int(spec s, char **here, char *there, va_list args, int *result);
int parse_pointer(spec s, char **here, char *there, va_list args, int *result);
int parse_double(spec s, char **here, char *there, va_list args, int *result);
int parse_char(spec s, char **here, char *there, va_list args, int *result);
int parse_string(spec s, char **here, char *there, va_list args, int *result);

int parse_count(char **here, const char *str, va_list args);
int parse_special(spec s, const char *start);

#endif  // SRC_S21_SSCANF_H_
