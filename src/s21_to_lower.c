#include "s21_string.h"
//Возвращает копию строки (str), преобразованной в нижний регистр. В случае
//какой-либо ошибки следует вернуть значение NULL
void* s21_to_lower(const char* str) {
  void* res = s21_NULL;
  if (str) {
    res = calloc(s21_strlen(str) + 1, sizeof(char));
    for (s21_size_t i = 0; i < s21_strlen(str); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        ((char*)res)[i] = str[i] + 32;
      } else {
        ((char*)res)[i] = str[i];
      }
    }
    ((char*)res)[s21_strlen(str)] = '\0';
  }
  return res;
}