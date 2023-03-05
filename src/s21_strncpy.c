#include "s21_string.h"
// Копирует строку, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  unsigned int i = 0;
  while (src[i] != '\0' && i < n - 1) {
    dest[i] = src[i];
    i++;
  }
  dest[i] = src[i];
  return dest;
}