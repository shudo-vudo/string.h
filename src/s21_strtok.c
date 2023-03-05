#include "s21_string.h"
// Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim) {
  static char *buffer = s21_NULL;
  char *token = s21_NULL;
  if (str) {
    buffer = str;
    while (*buffer && s21_strchr(delim, *buffer)) {
      *buffer++ = '\0';
    }
  }
  if (buffer && *buffer) {
    str = buffer;
    while (*buffer && !s21_strchr(delim, *buffer)) {
      ++buffer;
    }
    while (*buffer && s21_strchr(delim, *buffer)) {
      *buffer++ = '\0';
    }
    token = str;
  }
  return token;
}