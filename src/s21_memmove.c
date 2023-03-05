#include "s21_string.h"
//Еще одна функция для копирования n символов из src в dest.
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  if (dest <= src) {
    dest = s21_memcpy(dest, src, n);
  } else {
    unsigned char *d = (unsigned char *)dest + n;
    unsigned char *s = (unsigned char *)src + n;
    while (n--) {
      *(--d) = *(--s);
    }
  }
  return (void *)(dest);
}