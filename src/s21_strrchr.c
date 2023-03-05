#include "s21_string.h"
// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
  char *ch = s21_NULL;
  for (int i = s21_strlen(str); i >= 0; i--) {
    if (str[i] == c) {
      ch = (char *)(str + i);
      break;
    }
  }
  return ch;
}