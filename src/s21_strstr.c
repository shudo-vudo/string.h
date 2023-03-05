
#include "s21_string.h"
// Находит первое вхождение всей строки needle (не включая завершающий нулевой
// символ), которая появляется в строке haystack.
char* s21_strstr(const char* haystack, const char* needle) {
  int flag = 0;
  for (int i = 0; haystack[i] != '\0'; i++) {
    if (haystack[i] == needle[0]) flag = 0;
    for (int j = 0; needle[j] != '\0'; j++) {
      if (haystack[i + j] != needle[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) return (char*)haystack + i;
  }
  return s21_NULL;
}