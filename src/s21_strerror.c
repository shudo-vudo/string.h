#include "s21_string.h"

// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.

#define MAX_MESSAGE 200
char message[MAX_MESSAGE];
const char *errors[ERRMAX + 2] = ERRORS;

char *s21_strerror(int errnum) {
  if ((errnum >= -1) && (errnum < ERRMAX)) {
    s21_strcpy(message, errors[errnum + 1]);
  } else {
#if (defined(UBUNTU) || defined(__APPLE__) || defined(__MACH__))
    sprintf(message, "%s %d", errors[ERRMAX + 1], errnum);
#else  // other linux
    s21_strcpy(message, errors[ERRMAX + 1]);
#endif
  }
  return message;
}