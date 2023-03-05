#include "s21_string.h"
// Копирует строку, на которую указывает src, в dest.
char* s21_strcpy(char* dest, const char* src) {
  int count = 0;
  while (*(src + count) != '\0') {
    *(dest + count) = *(src + count);
    count++;
  }
  *(dest + count) = '\0';
  return dest;
}
