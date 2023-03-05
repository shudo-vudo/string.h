#include "s21_string.h"
//Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
//указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *simbol;
  simbol = (unsigned char *)str;
  while (n--) {
    *(simbol++) = (unsigned char)c;
  }
  return str;
}