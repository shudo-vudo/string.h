#include "tests.h"

START_TEST(s21_memchr_test1) {
  char *str = "21school";
  char to_find = 's';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test2) {
  char *str = "21school";
  char to_find = 'S';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test3) {
  char *str = "21school";
  char to_find = 'x';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test4) {
  char *str = "21school";
  char to_find = ' ';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test5) {
  char *str = "21school";
  char to_find = 'h';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test6) {
  char *str = "21school";
  char to_find = '7';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test7) {
  char *str = "21school";
  char to_find = '0';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test8) {
  char *str = "21school";
  char to_find = '\0';
  void *sys = memchr(str, to_find, 9);
  void *s21 = s21_memchr(str, to_find, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test9) {
  char *str = "21school";
  char to_find = 'o';
  void *sys = memchr(str, to_find, 3);
  void *s21 = s21_memchr(str, to_find, 3);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test10) {
  char *str = " ";
  char *to_find = "";
  void *sys = memchr(str, *to_find, 1);
  void *s21 = s21_memchr(str, *to_find, 1);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

// Наша функция защищена от n большего, чем длина строки
START_TEST(s21_memchr_test11) {
  char *str = " ";
  char *to_find = "";
  void *sys = memchr(str, *to_find, 3);
  void *s21 = s21_memchr(str, *to_find, 2);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

// Наша функция защищена от нулевого указателя вместо строки
START_TEST(s21_memchr_test12) {
  void *s21 = s21_memchr(s21_NULL, 'x', 10);
  ck_assert_ptr_null(s21);
}
END_TEST

START_TEST(s21_memchr_test13) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 98, 2);
  void *s21 = s21_memchr(str, 98, 2);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test14) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 9, sizeof(str));
  void *s21 = s21_memchr(str, 9, sizeof(str));
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test15) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 102, 6);
  void *s21 = s21_memchr(str, 102, 6);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test16) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 102, 4 + 6);
  void *s21 = s21_memchr(str, 102, 4 + 6);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test17) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 10, 60);
  void *s21 = s21_memchr(str, 10, 60);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test18) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str + 20, 33, 7);
  void *s21 = s21_memchr(str + 20, 33, 7);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test19) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 0, 100);
  void *s21 = s21_memchr(str, 0, 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test20) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 'b', 10);
  void *s21 = s21_memchr(str, 'b', 10);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test21) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 'p', 100);
  void *s21 = s21_memchr(str, 'p', 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test22) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 1 + '\e', 100);
  void *s21 = s21_memchr(str, 1 + '\e', 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test23) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, 2 + 'b', 100);
  void *s21 = s21_memchr(str, 2 + 'b', 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test24) {
  char str[100] = "banana found day good!  \n";
  void *sys = memchr(str, '\e' + 'b', 100);  //' a' + '\r' + '\b' + '\a', 100
  void *s21 = s21_memchr(str, '\e' + 'b', 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test25) {
  char str[100] = "banana found day good!  \n";
  char find[100] = "";
  void *sys = memchr(str, *find, 1);
  void *s21 = s21_memchr(str, *find, 1);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

// Наша функция защищена от n большего, чем длина строки
START_TEST(s21_memchr_test26) {
  char str[100] = "banana found day good!  \n";
  char find[100] = "";
  void *sys = memchr(str, *find, 101);
  void *s21 = s21_memchr(str, *find, 102);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

// Наша функция защищена от нулевого указателя вместо строки
START_TEST(s21_memchr_test27) {
  int *x = NULL;
  void *s21 = s21_memchr(x, 'x', 10);
  ck_assert_ptr_null(s21);
}
END_TEST

START_TEST(s21_memchr_test28) {
  char str[100] = "banana found day good!  \n";
  char find[100] = "B";
  void *sys = memchr(str, *find, 100);
  void *s21 = s21_memchr(str, *find, 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test29) {
  char str[100] = "banana found day good!  \n";
  char find[100] = "b";
  void *sys = memchr(str, *find, 100);
  void *s21 = s21_memchr(str, *find, 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test30) {
  char str[100] = "banana found day good!  \n";
  char find[100] = " ";
  void *sys = memchr(str, *find, 100);
  void *s21 = s21_memchr(str, *find, 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test31) {
  char str[100] = "banana found day good!  \n";
  char find[100] = "7";
  void *sys = memchr(str, *find, 100);
  void *s21 = s21_memchr(str, *find, 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memchr_test32) {
  char str[100] = "banana found day good!  \n";
  char find[100] = "\n";
  void *sys = memchr(str, *find, 100);
  void *s21 = s21_memchr(str, *find, 100);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test1) {
  char *str1 = "21school";
  char *str2 = "21school ";
  int sys = memcmp(str1, str2, 8);
  int s21 = s21_memcmp(str1, str2, 8);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test2) {
  char *str1 = "21school";
  char *str2 = "21school ";
  int sys = memcmp(str1, str2, 9);
  int s21 = s21_memcmp(str1, str2, 9);
  ck_assert(sys < 0 && s21 < 0);
}
END_TEST

START_TEST(s21_memcmp_test3) {
  char *str2 = "21school ";
  int sys = memcmp("", str2, 1);
  int s21 = s21_memcmp("", str2, 9);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test4) {
  char *str1 = "21school";
  char *str2 = "21school ";
  int s21 = s21_memcmp(str1, str2, 10);
  ck_assert_int_ne(s21, 0);
}
END_TEST

START_TEST(s21_memcmp_test5) {
  char *str1 = "21school";
  char *str2 = "21school ";
  int sys = memcmp(str1, str2, 10);
  int s21 = s21_memcmp(str1, str2, 10);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test6) {
  char *str1 = "21school";
  char *str3 = "42school";
  int sys = memcmp(str1, str3, 8);
  int s21 = s21_memcmp(str1, str3, 8);
  ck_assert(sys < 0 && s21 < 0);
}
END_TEST

START_TEST(s21_memcmp_test7) {
  char *str1 = "21school";
  char *str3 = "42school";
  int sys = memcmp(str3, str1, 8);
  int s21 = s21_memcmp(str3, str1, 8);
  ck_assert(sys > 0 && s21 > 0);
}
END_TEST

START_TEST(s21_memcmp_test8) {
  char *str1 = "21school";
  char *str3 = "42school";
  int sys = memcmp(str1, str3, 0);
  int s21 = s21_memcmp(str1, str3, 0);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test9) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = memcmp(test1, test2, 11);
  int s21 = s21_memcmp(s21test1, s21test2, 11);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test10) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  int sys = memcmp(test1, test1, 2);
  int s21 = s21_memcmp(s21test1, s21test1, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test11) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = memcmp(test1, test2, 2);
  int s21 = s21_memcmp(s21test1, s21test2, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test12) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  int sys = memcmp(test1, test3, 2);
  int s21 = s21_memcmp(s21test1, s21test3, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test13) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test4[] = " \n\0";  // 32 + 10 + 0 = 42 байт
  char s21test4[] = " \n\0";
  int sys = memcmp(test1, test4, 2);
  int s21 = s21_memcmp(s21test1, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test14) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test5[] = " \0";
  char s21test5[] = " \0";
  int sys = memcmp(test1, test5, 2);
  int s21 = s21_memcmp(s21test1, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test15) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  int sys = memcmp(test1, test6, 2);
  int s21 = s21_memcmp(s21test1, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test16) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = memcmp(test1, test7, 2);
  int s21 = s21_memcmp(s21test1, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test17) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = memcmp(test2, test2, 2);
  int s21 = s21_memcmp(s21test2, s21test2, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test18) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  int sys = memcmp(test2, test3, 2);
  int s21 = s21_memcmp(s21test2, s21test3, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test19) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  char test4[] = " \n\0";  // 32 + 10 + 0 = 42 байт
  char s21test4[] = " \n\0";
  int sys = memcmp(test2, test4, 2);
  int s21 = s21_memcmp(s21test2, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test20) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  char test5[] = " \0";
  char s21test5[] = " \0";
  int sys = memcmp(test2, test5, 2);
  int s21 = s21_memcmp(s21test2, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test21) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  int sys = memcmp(test2, test6, 2);
  int s21 = s21_memcmp(s21test2, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test22) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = memcmp(test2, test7, 2);
  int s21 = s21_memcmp(s21test2, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test23) {
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  int sys = memcmp(test3, test3, 2);
  int s21 = s21_memcmp(s21test3, s21test3, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test24) {
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  char test4[] = " \n\0";  // 32 + 10 + 0 = 42 байт
  char s21test4[] = " \n\0";
  int sys = memcmp(test3, test4, 2);
  int s21 = s21_memcmp(s21test3, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test25) {
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  char test5[] = " \0";
  char s21test5[] = " \0";
  int sys = memcmp(test3, test5, 2);
  int s21 = s21_memcmp(s21test3, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test26) {
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  int sys = memcmp(test3, test6, 2);
  int s21 = s21_memcmp(s21test3, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test27) {
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = memcmp(test3, test7, 2);
  int s21 = s21_memcmp(s21test3, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test28) {
  char test4[] = " \n\0";  // 32 + 10 + 0 = 42 байт
  char s21test4[] = " \n\0";
  int sys = memcmp(test4, test4, 2);
  int s21 = s21_memcmp(s21test4, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test29) {
  char test4[] = " \n\0";  // 32 + 10 + 0 = 42 байт
  char s21test4[] = " \n\0";
  char test5[] = " \0";
  char s21test5[] = " \0";
  int sys = memcmp(test4, test5, 2);
  int s21 = s21_memcmp(s21test4, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test30) {
  char test4[] = " \n\0";  // 32 + 10 + 0 = 42 байт
  char s21test4[] = " \n\0";
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  int sys = memcmp(test4, test6, 2);
  int s21 = s21_memcmp(s21test4, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test31) {
  char test4[] = " \n\0";  // 32 + 10 + 0 = 42 байт
  char s21test4[] = " \n\0";
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = memcmp(test4, test7, 2);
  int s21 = s21_memcmp(s21test4, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test32) {
  char test5[] = " \0";
  char s21test5[] = " \0";
  int sys = memcmp(test5, test5, 2);
  int s21 = s21_memcmp(s21test5, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test33) {
  char test5[] = " \0";
  char s21test5[] = " \0";
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  int sys = memcmp(test5, test6, 2);
  int s21 = s21_memcmp(s21test5, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test34) {
  char test5[] = " \0";
  char s21test5[] = " \0";
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = memcmp(test5, test7, 2);
  int s21 = s21_memcmp(s21test5, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test35) {
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  int sys = memcmp(test6, test6, 2);
  int s21 = s21_memcmp(s21test6, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test36) {
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = memcmp(test6, test7, 2);
  int s21 = s21_memcmp(s21test6, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test37) {
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = memcmp(test7, test7, 2);
  int s21 = s21_memcmp(s21test7, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test38) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = memcmp(test1, test2, 0);
  int s21 = s21_memcmp(s21test1, s21test2, 0);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test39) {
  char test10[] = "\n\n\n\n\0";
  char s21test10[] = "\n\n\n\n\0";
  char test11[] = "(\n";
  char s21test11[] = "(\n";
  int sys = memcmp(test10, test11, 5);
  int s21 = s21_memcmp(s21test10, s21test11, 5);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test40) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = memcmp("", test2, 9);
  int s21 = s21_memcmp("", s21test2, 1);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test41) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = memcmp(test1, test2, 11);
  int s21 = s21_memcmp(s21test1, s21test2, 11);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_memcmp_test42) {
  char s21test1[] = "Hello world\0";
  char s21test2[] = "Hello world\n\0";
  int s21 = s21_memcmp(s21test1, s21test2, 14);
  ck_assert_int_ne(s21, 0);
}
END_TEST

START_TEST(s21_memcmp_test43) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = memcmp(test1, test2, 13);
  int s21 = s21_memcmp(s21test1, s21test2, 13);
  ck_assert(sys < 0 && s21 < 0);
}
END_TEST

// a < b
START_TEST(s21_memcmp_test44) {
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  char test8[] = "b\n\0";
  char s21test8[] = "b\n\0";  // 98 + 10 + 0 = 108 байт
  int sys = memcmp(test3, test8, 3);
  int s21 = s21_memcmp(s21test3, s21test8, 3);
  ck_assert(sys < 0 && s21 < 0);
}
END_TEST

// b > a
START_TEST(s21_memcmp_test45) {
  char test3[] = "a\n\0";  // 97 + 10 + 0 = 107 байт
  char s21test3[] = "a\n\0";
  char test8[] = "b\n\0";
  char s21test8[] = "b\n\0";  // 98 + 10 + 0 = 108 байт
  int sys = memcmp(test8, test3, 3);
  int s21 = s21_memcmp(s21test8, s21test3, 3);
  ck_assert(sys > 0 && s21 > 0);
}
END_TEST

START_TEST(s21_memcmp_test46) {
  char test8[] = "b\n\0";
  char s21test8[] = "b\n\0";  // 98 + 10 + 0 = 108 байт
  char test9[] = "B\n\0";
  char s21test9[] = "B\n\0";
  int sys = memcmp(test8, test9, 3);
  int s21 = s21_memcmp(s21test8, s21test9, 3);
  ck_assert(sys > 0 && s21 > 0);
}
END_TEST

START_TEST(s21_memcmp_test47) {
  char test10[] = "\n\n\n\n\0";
  char s21test10[] = "\n\n\n\n\0";
  char test11[] = "(\n";
  char s21test11[] = "(\n";
  int sys = memcmp(test10, test11, 5);
  int s21 = s21_memcmp(s21test10, s21test11, 5);
  ck_assert(sys && s21);
}
END_TEST

START_TEST(s21_memcmp_test48) {
  char test10[] = "\n\n\n\n\0";
  char s21test10[] = "\n\n\n\n\0";
  char test11[] = "(\n";
  char s21test11[] = "(\n";
  int sys = memcmp(test10, test11, 5);
  int s21 = s21_memcmp(s21test10, s21test11, 5);
  ck_assert(sys == s21);
}
END_TEST

START_TEST(s21_memcpy_test1) {
  char *src = "Deadline is approaching!";
  char str_dst[25] = {0};
  char s21_dst[25] = {0};
  void *str = memcpy(str_dst, src, 8);
  void *s21 = s21_memcpy(s21_dst, src, 8);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test2) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  void *str = memcpy(str_dst, str_src, 0);
  void *s21 = s21_memcpy(s21_dst, s21_src, 0);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test3) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test4) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "    \n\0";
  char s21_src[] = "    \n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test5) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test6) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test7) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test8) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "    \n\0";
  char s21_src[] = "    \n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test9) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test10) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test11) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test12) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test13) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test14) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test15) {
  char str_dst[] = "\0\n";
  char s21_dst[] = "\0\n";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memcpy_test16) {
  char str_dst[] = "\0\n";
  char s21_dst[] = "\0\n";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test17) {
  char str_dst[] = "        !!";
  char s21_dst[] = "        !!";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test18) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "121345678910111213141516171819120212223";
  char s21_src[] = "121345678910111213141516171819120212223";
  void *str = memcpy(str_dst, str_src, 0);
  void *s21 = s21_memcpy(s21_dst, s21_src, 0);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test19) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "121345678910111213141516171819120212223";
  char s21_src[] = "121345678910111213141516171819120212223";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test20) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "121345678910111213141516171819120212223";
  char s21_src[] = "121345678910111213141516171819120212223";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test21) {
  char str_dst[] = "\0\n";
  char s21_dst[] = "\0\n";
  char str_src[] = "121345678910111213141516171819120212223";
  char s21_src[] = "121345678910111213141516171819120212223";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memcpy_test22) {
  char str_dst[] = "        !!";
  char s21_dst[] = "        !!";
  char str_src[] = "121345678910111213141516171819120212223";
  char s21_src[] = "121345678910111213141516171819120212223";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test23) {
  char str_dst[] = "\n\0";
  char s21_dst[] = "\n\0";
  char str_src[] = "121345678910111213141516171819120212223";
  char s21_src[] = "121345678910111213141516171819120212223";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memcpy_test24) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test25) {
  char str_dst[] = "\0\n";
  char s21_dst[] = "\0\n";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memcpy_test26) {
  char str_dst[] = "        !!";
  char s21_dst[] = "        !!";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test27) {
  char str_dst[] = "\n\0";
  char s21_dst[] = "\n\0";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test28) {
  char str_dst[] = "\0\n";
  char s21_dst[] = "\0\n";
  char str_src[] = "    \n\0";
  char s21_src[] = "    \n\0";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memcpy_test29) {
  char str_dst[] = "        !!";
  char s21_dst[] = "        !!";
  char str_src[] = "    \n\0";
  char s21_src[] = "    \n\0";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test30) {
  char str_dst[] = "\n\0";
  char s21_dst[] = "\n\0";
  char str_src[] = "    \n\0";
  char s21_src[] = "    \n\0";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memcpy_test31) {
  char str_dst[] = "        !!";
  char s21_dst[] = "        !!";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memcpy_test32) {
  char str_dst[] = "\n\0";
  char s21_dst[] = "\n\0";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memcpy(str_dst, str_src, 3);
  void *s21 = s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_str_eq(s21, str);
}
END_TEST

// Определено поведение только для копируемых символов, для остальных поведение
// не определено. Поэтому сравниваем только первые 3 символа
START_TEST(s21_memcpy_test33) {
  char str_dst[] = "\n\0";
  char s21_dst[] = "\n\0";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  char *str = (char *)memcpy(str_dst, str_src, 3);
  char *s21 = (char *)s21_memcpy(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memmove_test1) {
  char src[15] = "Hello world!";
  char str_dst[15] = "";
  char s21_dst[15] = "";
  int n = 5;
  void *str = memmove(str_dst, src, n);
  void *s21 = s21_memmove(s21_dst, src, n);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test2) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test3) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "    \n\0";
  char s21_src[] = "    \n\0";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test4) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test5) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test6) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test7) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "    \n\0";
  char s21_src[] = "    \n\0";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test8) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test9) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test10) {
  char str_dst[] = "qwertyuiop";
  char s21_dst[] = "qwertyuiop";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test11) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "\0\n";
  char s21_src[] = "\0\n";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test12) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test13) {
  char str_dst[] = "    \n\0";
  char s21_dst[] = "    \n\0";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test14) {
  char str_dst[] = "\0\n";
  char s21_dst[] = "\0\n";
  char str_src[] = "        !!";
  char s21_src[] = "        !!";
  char *str = (char *)memmove(str_dst, str_src, 3);
  char *s21 = (char *)s21_memmove(s21_dst, s21_src, 3);
  ck_assert_uint_eq(*s21, *str);
  ck_assert_uint_eq(*(s21 + 1), *(str + 1));
  ck_assert_uint_eq(*(s21 + 2), *(str + 2));
}
END_TEST

START_TEST(s21_memmove_test15) {
  char str_dst[] = "\0\n";
  char s21_dst[] = "\0\n";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memmove(str_dst, str_src, 3);
  void *s21 = s21_memmove(s21_dst, s21_src, 3);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test16) {
  char str_dst[] = "        !!";
  char s21_dst[] = "        !!";
  char str_src[] = "\n\0";
  char s21_src[] = "\n\0";
  void *str = memmove(str_dst, str_src, 1);
  void *s21 = s21_memmove(s21_dst, s21_src, 1);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test17) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  void *str = memmove(str_dst, str_src, 0);
  void *s21 = s21_memmove(s21_dst, s21_src, 0);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test18) {
  char str_dst[] = "121345678910111213141516171819120212223";
  char s21_dst[] = "121345678910111213141516171819120212223";
  char str_src[] = "qwertyuiop";
  char s21_src[] = "qwertyuiop";
  void *str = memmove(str_dst, str_src, 5);
  void *s21 = s21_memmove(s21_dst, s21_src, 5);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memmove_test19) {
  char str_dst[] = "\n\0";
  char s21_dst[] = "\n\0";
  char str_src[3] = "\0\0\0";
  char s21_src[3] = "\0\0\0";
  void *str = memmove(str_dst, str_src, 2);
  void *s21 = s21_memmove(s21_dst, s21_src, 2);
  ck_assert_pstr_eq(s21, str);
}
END_TEST

START_TEST(s21_memset_test1) {
  char array[5] = "ABCD";
  char expected[5] = "000D";
  int n = 3;
  s21_memset(array, '0', n);
  ck_assert_str_eq(expected, array);
}
END_TEST

START_TEST(s21_memset_test2) {
  char array[5] = "ABCD";
  char array2[5] = "ABCD";
  int n = 3;
  s21_memset(array, '0', n);
  ck_assert_str_eq(array, memset(array2, '0', n));
}
END_TEST

START_TEST(s21_memset_test3) {
  double s21_str[2] = {0.5, 0.6};
  double str_str[2] = {0.5, 0.6};
  int n = 3;
  void *s21 = s21_memset(s21_str, '0', n);
  void *str = memset(str_str, '0', n);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memset_test4) {
  int s21_str[5] = {1, 1, 1, 1, 1};
  int str_str[5] = {1, 1, 1, 1, 1};
  int n = 3;
  void *s21 = s21_memset(s21_str, '0', n);
  void *str = memset(str_str, '0', n);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memset_test5) {
  char kek1[30] = "banana found day good";
  char kek2[30] = "banana found day good";
  char *s21 = (char *)s21_memset(kek1, 55, 7);
  char *str = (char *)memset(kek2, 55, 7);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memset_test6) {
  char kek1[30] = "banana found day good";
  char kek2[30] = "banana found day good";
  char *s21 = (char *)s21_memset(kek1, 128, 7);
  char *str = (char *)memset(kek2, 128, 7);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memset_test7) {
  char kek1[30] = "banana found day good";
  char kek2[30] = "banana found day good";
  char *s21 = (char *)s21_memset(kek1, -1, 7);
  char *str = (char *)memset(kek2, -1, 7);
  ck_assert_str_eq(s21, str);
}
END_TEST

START_TEST(s21_memset_test8) {
  char kek1[30] = "banana found day good";
  char *s21 = (char *)s21_memset(kek1 + 20, 65, 7);
  char *str = (char *)memset(kek1 + 20, 65, 7);
  ck_assert_str_eq(s21, str);
}
END_TEST

Suite *mem_test(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("s21_string #1 baza (mem)");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memchr_test1);
  tcase_add_test(tc_core, s21_memchr_test2);
  tcase_add_test(tc_core, s21_memchr_test3);
  tcase_add_test(tc_core, s21_memchr_test4);
  tcase_add_test(tc_core, s21_memchr_test5);
  tcase_add_test(tc_core, s21_memchr_test6);
  tcase_add_test(tc_core, s21_memchr_test7);
  tcase_add_test(tc_core, s21_memchr_test8);
  tcase_add_test(tc_core, s21_memchr_test9);
  tcase_add_test(tc_core, s21_memchr_test10);
  tcase_add_test(tc_core, s21_memchr_test11);
  tcase_add_test(tc_core, s21_memchr_test12);
  tcase_add_test(tc_core, s21_memchr_test13);
  tcase_add_test(tc_core, s21_memchr_test14);
  tcase_add_test(tc_core, s21_memchr_test15);
  tcase_add_test(tc_core, s21_memchr_test16);
  tcase_add_test(tc_core, s21_memchr_test17);
  tcase_add_test(tc_core, s21_memchr_test18);
  tcase_add_test(tc_core, s21_memchr_test19);
  tcase_add_test(tc_core, s21_memchr_test20);
  tcase_add_test(tc_core, s21_memchr_test21);
  tcase_add_test(tc_core, s21_memchr_test22);
  tcase_add_test(tc_core, s21_memchr_test23);
  tcase_add_test(tc_core, s21_memchr_test24);
  tcase_add_test(tc_core, s21_memchr_test25);
  tcase_add_test(tc_core, s21_memchr_test26);
  tcase_add_test(tc_core, s21_memchr_test27);
  tcase_add_test(tc_core, s21_memchr_test28);
  tcase_add_test(tc_core, s21_memchr_test29);
  tcase_add_test(tc_core, s21_memchr_test30);
  tcase_add_test(tc_core, s21_memchr_test31);
  tcase_add_test(tc_core, s21_memchr_test32);

  tcase_add_test(tc_core, s21_memcmp_test1);
  tcase_add_test(tc_core, s21_memcmp_test2);
  tcase_add_test(tc_core, s21_memcmp_test3);
  tcase_add_test(tc_core, s21_memcmp_test4);
  tcase_add_test(tc_core, s21_memcmp_test5);
  tcase_add_test(tc_core, s21_memcmp_test6);
  tcase_add_test(tc_core, s21_memcmp_test7);
  tcase_add_test(tc_core, s21_memcmp_test8);
  tcase_add_test(tc_core, s21_memcmp_test9);
  tcase_add_test(tc_core, s21_memcmp_test10);
  tcase_add_test(tc_core, s21_memcmp_test11);
  tcase_add_test(tc_core, s21_memcmp_test12);
  tcase_add_test(tc_core, s21_memcmp_test13);
  tcase_add_test(tc_core, s21_memcmp_test14);
  tcase_add_test(tc_core, s21_memcmp_test15);
  tcase_add_test(tc_core, s21_memcmp_test16);
  tcase_add_test(tc_core, s21_memcmp_test17);
  tcase_add_test(tc_core, s21_memcmp_test18);
  tcase_add_test(tc_core, s21_memcmp_test19);
  tcase_add_test(tc_core, s21_memcmp_test20);
  tcase_add_test(tc_core, s21_memcmp_test21);
  tcase_add_test(tc_core, s21_memcmp_test22);
  tcase_add_test(tc_core, s21_memcmp_test23);
  tcase_add_test(tc_core, s21_memcmp_test24);
  tcase_add_test(tc_core, s21_memcmp_test25);
  tcase_add_test(tc_core, s21_memcmp_test26);
  tcase_add_test(tc_core, s21_memcmp_test27);
  tcase_add_test(tc_core, s21_memcmp_test28);
  tcase_add_test(tc_core, s21_memcmp_test29);
  tcase_add_test(tc_core, s21_memcmp_test30);
  tcase_add_test(tc_core, s21_memcmp_test31);
  tcase_add_test(tc_core, s21_memcmp_test32);
  tcase_add_test(tc_core, s21_memcmp_test33);
  tcase_add_test(tc_core, s21_memcmp_test34);
  tcase_add_test(tc_core, s21_memcmp_test35);
  tcase_add_test(tc_core, s21_memcmp_test36);
  tcase_add_test(tc_core, s21_memcmp_test37);
  tcase_add_test(tc_core, s21_memcmp_test38);
  tcase_add_test(tc_core, s21_memcmp_test39);
  tcase_add_test(tc_core, s21_memcmp_test40);
  tcase_add_test(tc_core, s21_memcmp_test41);
  tcase_add_test(tc_core, s21_memcmp_test42);
  tcase_add_test(tc_core, s21_memcmp_test43);
  tcase_add_test(tc_core, s21_memcmp_test44);
  tcase_add_test(tc_core, s21_memcmp_test45);
  tcase_add_test(tc_core, s21_memcmp_test46);
  tcase_add_test(tc_core, s21_memcmp_test47);
  tcase_add_test(tc_core, s21_memcmp_test48);

  tcase_add_test(tc_core, s21_memcpy_test1);
  tcase_add_test(tc_core, s21_memcpy_test2);
  tcase_add_test(tc_core, s21_memcpy_test3);
  tcase_add_test(tc_core, s21_memcpy_test4);
  tcase_add_test(tc_core, s21_memcpy_test5);
  tcase_add_test(tc_core, s21_memcpy_test6);
  tcase_add_test(tc_core, s21_memcpy_test7);
  tcase_add_test(tc_core, s21_memcpy_test8);
  tcase_add_test(tc_core, s21_memcpy_test9);
  tcase_add_test(tc_core, s21_memcpy_test10);
  tcase_add_test(tc_core, s21_memcpy_test11);
  tcase_add_test(tc_core, s21_memcpy_test12);
  tcase_add_test(tc_core, s21_memcpy_test13);
  tcase_add_test(tc_core, s21_memcpy_test14);
  tcase_add_test(tc_core, s21_memcpy_test15);
  tcase_add_test(tc_core, s21_memcpy_test16);
  tcase_add_test(tc_core, s21_memcpy_test17);
  tcase_add_test(tc_core, s21_memcpy_test18);
  tcase_add_test(tc_core, s21_memcpy_test19);
  tcase_add_test(tc_core, s21_memcpy_test20);
  tcase_add_test(tc_core, s21_memcpy_test21);
  tcase_add_test(tc_core, s21_memcpy_test22);
  tcase_add_test(tc_core, s21_memcpy_test23);
  tcase_add_test(tc_core, s21_memcpy_test24);
  tcase_add_test(tc_core, s21_memcpy_test25);
  tcase_add_test(tc_core, s21_memcpy_test26);
  tcase_add_test(tc_core, s21_memcpy_test27);
  tcase_add_test(tc_core, s21_memcpy_test28);
  tcase_add_test(tc_core, s21_memcpy_test29);
  tcase_add_test(tc_core, s21_memcpy_test30);
  tcase_add_test(tc_core, s21_memcpy_test31);
  tcase_add_test(tc_core, s21_memcpy_test32);
  tcase_add_test(tc_core, s21_memcpy_test33);

  tcase_add_test(tc_core, s21_memmove_test1);
  tcase_add_test(tc_core, s21_memmove_test2);
  tcase_add_test(tc_core, s21_memmove_test3);
  tcase_add_test(tc_core, s21_memmove_test4);
  tcase_add_test(tc_core, s21_memmove_test5);
  tcase_add_test(tc_core, s21_memmove_test6);
  tcase_add_test(tc_core, s21_memmove_test7);
  tcase_add_test(tc_core, s21_memmove_test8);
  tcase_add_test(tc_core, s21_memmove_test9);
  tcase_add_test(tc_core, s21_memmove_test10);
  tcase_add_test(tc_core, s21_memmove_test11);
  tcase_add_test(tc_core, s21_memmove_test12);
  tcase_add_test(tc_core, s21_memmove_test13);
  tcase_add_test(tc_core, s21_memmove_test14);
  tcase_add_test(tc_core, s21_memmove_test15);
  tcase_add_test(tc_core, s21_memmove_test16);
  tcase_add_test(tc_core, s21_memmove_test17);
  tcase_add_test(tc_core, s21_memmove_test18);
  tcase_add_test(tc_core, s21_memmove_test19);

  tcase_add_test(tc_core, s21_memset_test1);
  tcase_add_test(tc_core, s21_memset_test2);
  tcase_add_test(tc_core, s21_memset_test3);
  tcase_add_test(tc_core, s21_memset_test4);
  tcase_add_test(tc_core, s21_memset_test5);
  tcase_add_test(tc_core, s21_memset_test6);
  tcase_add_test(tc_core, s21_memset_test7);
  tcase_add_test(tc_core, s21_memset_test8);

  suite_add_tcase(s, tc_core);
  return s;
}