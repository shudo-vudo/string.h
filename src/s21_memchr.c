#include "s21_string.h"
//Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
//байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n) {
  s21_size_t i;
  unsigned char *ptr;
  void *result = s21_NULL;
  i = 0;
  ptr = (unsigned char *)str;
  if (str != s21_NULL) {
    while (++i <= n) {
      if (*(ptr++) == (unsigned char)c) {
        result = ((void *)--ptr);
        break;
      }
    }
  }
  return result;
}