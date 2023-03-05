#include "s21_string.h"
// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char* s21_strchr(const char* source,
                 int ch) {  // ch - КОД искомого символа по аски
  int count = 0;
  while (source[count] != '\0' && source[count] != ch) {
    count++;
  }
  if (source[count] == ch) {
    return (char*)source + count;
  } else {
    return s21_NULL;
  }
  return s21_NULL;
}
