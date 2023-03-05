#include "s21_string.h"
//Возвращает новую строку, в которой удаляются все начальные и конечные
//вхождения набора заданных символов (trim_chars) из данной строки (src). В
//случае какой-либо ошибки следует вернуть значение NULL

char *mysubstr(char const *src, unsigned int start, s21_size_t len) {
  //Он возвращает подстроку исходной строки, начиная с позиции start и
  //заканчивается на позиции len-1.
  s21_size_t i;
  s21_size_t len_s1;
  char *str;

  if (!src) return s21_NULL;
  len_s1 = s21_strlen(src);

  if (len_s1 < (start + len)) len = len_s1 - start;
  if (len_s1 < start) len = 0;
  str = (char *)calloc(sizeof(*src), (len + 1));
  if (!str) return s21_NULL;
  i = 0;
  while (src[i] && i < len) {
    str[i] = src[i + start];
    i++;
  }
  str[i] = '\0';
  return (str);
}

void *s21_trim(const char *src, const char *trim_chars) {
  int error_flag = 0;
  char *str_trim = s21_NULL;
  if (src != s21_NULL) {
    s21_size_t start = 0;
    s21_size_t end = s21_strlen(src);
    char default_chars[10] = " \t\n\v\r\f\0";
    if (trim_chars == s21_NULL || s21_strlen(trim_chars) == 0)
      trim_chars = default_chars;
    while (src[start] && s21_strchr(trim_chars, src[start])) start++;
    while (end > start && s21_strrchr(trim_chars, src[end - 1])) end--;
    return (mysubstr(src, start, end - start));
  } else {
    error_flag = 1;
  }
  return error_flag ? s21_NULL : (void *)str_trim;
}
