#include "s21_string.h"
//Возвращает новую строку, в которой указанная строка (str) вставлена в
//указанную позицию (start_index) в данной строке (src). В случае какой-либо
//ошибки следует вернуть значение NULL
void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* res = s21_NULL;

  if (src && s21_strlen(src) >= start_index && str) {
    res = (char*)calloc(s21_strlen(str) + s21_strlen(src) + 1, sizeof(char));

    s21_size_t lensrc = s21_strlen(src), lenstr = s21_strlen(str);

    for (s21_size_t i = 0; i < start_index; i++) {
      ((char*)res)[i] =
          src[i];  //в пустую строку res записываем посимвольно все то, что
                   //содержится в строке src до символа под номером start_index
    }

    for (s21_size_t j = 0; j < lenstr; j++) {
      ((char*)res)[j + start_index] = str[j];
    }

    for (s21_size_t g = 0; g < lensrc - start_index; g++) {
      ((char*)res)[g + start_index + lenstr] = src[g + start_index];
    }
    ((char*)res)[lensrc + lenstr] = '\0';
  }
  return res;
}
