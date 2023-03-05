#include "s21_string.h"
// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  s21_size_t i = 0;
  char *ptr;
  while (*(str1 + i) && s21_strchr(str2, *(str1 + i)) == s21_NULL) i++;
  ptr = *(str1 + i) ? (char *)(str1 + i) : s21_NULL;
  return (ptr);
}