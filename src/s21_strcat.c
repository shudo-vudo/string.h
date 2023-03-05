#include "s21_string.h"
// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest.
char* s21_strcat(char* dest, const char* src) {
  int count = s21_strlen(dest);
  while (*src != '\0') {
    *(dest + count) = *src++;
    count++;
  }
  *(dest + count) = '\0';  // добавление символа конца строки
  return dest;
}
