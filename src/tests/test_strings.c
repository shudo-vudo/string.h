/* ck_assert - используется для логических выражений и операторов сравнения |
(только true проходит)
ck_assert_int_eq - сравнивает между собой два параметра | (==)
ck_assert_int_ne - сравнивает между собой два параметра | (!=)
*/

#include "tests.h"

// STRCAT

START_TEST(s21_strcat_test1) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test2[100] = "qwertyuiop";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test2[100] = "qwertyuiop";
  char* sys = strcat(test1, test2);
  char* s21 = s21_strcat(s21test1, s21test2);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test2) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test3[100] = "    \n\0";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test3[100] = "    \n\0";
  char* sys = strcat(test1, test3);
  char* s21 = s21_strcat(s21test1, s21test3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test3) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test4[100] = "\0\n";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test4[100] = "\0\n";
  char* sys = strcat(test1, test4);
  char* s21 = s21_strcat(s21test1, s21test4);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test4) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test5[100] = "        !!";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test5[100] = "        !!";
  char* sys = strcat(test1, test5);
  char* s21 = s21_strcat(s21test1, s21test5);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test5) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test6[100] = "\n\0";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test6[100] = "\n\0";
  char* sys = strcat(test1, test6);
  char* s21 = s21_strcat(s21test1, s21test6);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test6) {
  char test2[100] = "qwertyuiop";
  char test3[100] = "    \n\0";
  char s21test2[100] = "qwertyuiop";
  char s21test3[100] = "    \n\0";
  char* sys = strcat(test2, test3);
  char* s21 = s21_strcat(s21test2, s21test3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test7) {
  char test2[100] = "qwertyuiop";
  char test4[100] = "\0\n";
  char s21test2[100] = "qwertyuiop";
  char s21test4[100] = "\0\n";
  char* sys = strcat(test2, test4);
  char* s21 = s21_strcat(s21test2, s21test4);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test8) {
  char test2[100] = "qwertyuiop";
  char test5[100] = "        !!";
  char s21test2[100] = "qwertyuiop";
  char s21test5[100] = "        !!";
  char* sys = strcat(test2, test5);
  char* s21 = s21_strcat(s21test2, s21test5);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test9) {
  char test2[100] = "qwertyuiop";
  char test6[100] = "\n\0";
  char s21test2[100] = "qwertyuiop";
  char s21test6[100] = "\n\0";
  char* sys = strcat(test2, test6);
  char* s21 = s21_strcat(s21test2, s21test6);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test10) {
  char test3[100] = "    \n\0";
  char test4[100] = "\0\n";
  char s21test3[100] = "    \n\0";
  char s21test4[100] = "\0\n";
  char* sys = strcat(test3, test4);
  char* s21 = s21_strcat(s21test3, s21test4);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test11) {
  char test3[100] = "    \n\0";
  char test5[100] = "        !!";
  char s21test3[100] = "    \n\0";
  char s21test5[100] = "        !!";
  char* sys = strcat(test3, test5);
  char* s21 = s21_strcat(s21test3, s21test5);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test12) {
  char test3[100] = "    \n\0";
  char test6[100] = "\n\0";
  char s21test3[100] = "    \n\0";
  char s21test6[100] = "\n\0";
  char* sys = strcat(test3, test6);
  char* s21 = s21_strcat(s21test3, s21test6);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test13) {
  char test4[100] = "\0\n";
  char test5[100] = "        !!";
  char s21test4[100] = "\0\n";
  char s21test5[100] = "        !!";
  char* sys = strcat(test4, test5);
  char* s21 = s21_strcat(s21test4, s21test5);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test14) {
  char test4[100] = "\0\n";
  char test6[100] = "\n\0";
  char s21test4[100] = "\0\n";
  char s21test6[100] = "\n\0";
  char* sys = strcat(test4, test6);
  char* s21 = s21_strcat(s21test4, s21test6);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test15) {
  char test5[100] = "        !!";
  char test6[100] = "\n\0";
  char s21test5[100] = "        !!";
  char s21test6[100] = "\n\0";
  char* sys = strcat(test5, test6);
  char* s21 = s21_strcat(s21test5, s21test6);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test16) {
  char test7[100] = "";
  char test2[100] = "qwertyuiop";
  char s21test7[100] = "";
  char s21test2[100] = "qwertyuiop";
  char* sys = strcat(test7, test2);
  char* s21 = s21_strcat(s21test7, s21test2);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test17) {
  char test2[100] = "qwertyuiop";
  char test7[100] = "";
  char s21test2[100] = "qwertyuiop";
  char s21test7[100] = "";
  char* sys = strcat(test2, test7);
  char* s21 = s21_strcat(s21test2, s21test7);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcat_test18) {
  char dst[100] = "Hello";
  char dst2[100] = "Hello";
  char* src = " World!";
  char* sys = strcat(dst2, src);
  char* s21 = s21_strcat(dst, src);

  ck_assert_str_eq(sys, s21);
}
END_TEST

// STRNCAT

START_TEST(s21_strncat_test1) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test2[100] = "qwertyuiop";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test2[100] = "qwertyuiop";
  char* sys = strncat(test1, test2, 3);
  char* s21 = s21_strncat(s21test1, s21test2, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test2) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test3[100] = "    \n\0";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test3[100] = "    \n\0";
  char* sys = strncat(test1, test3, 3);
  char* s21 = s21_strncat(s21test1, s21test3, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test3) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test4[100] = "\0\n";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test4[100] = "\0\n";
  char* sys = strncat(test1, test4, 3);
  char* s21 = s21_strncat(s21test1, s21test4, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test4) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test5[100] = "        !!";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test5[100] = "        !!";
  char* sys = strncat(test1, test5, 3);
  char* s21 = s21_strncat(s21test1, s21test5, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test5) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test6[100] = "\n\0";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test6[100] = "\n\0";
  char* sys = strncat(test1, test6, 3);
  char* s21 = s21_strncat(s21test1, s21test6, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test6) {
  char test2[100] = "qwertyuiop";
  char test3[100] = "    \n\0";
  char s21test2[100] = "qwertyuiop";
  char s21test3[100] = "    \n\0";
  char* sys = strncat(test2, test3, 3);
  char* s21 = s21_strncat(s21test2, s21test3, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test7) {
  char test2[100] = "qwertyuiop";
  char test4[100] = "\0\n";
  char s21test2[100] = "qwertyuiop";
  char s21test4[100] = "\0\n";
  char* sys = strncat(test2, test4, 3);
  char* s21 = s21_strncat(s21test2, s21test4, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test8) {
  char test2[100] = "qwertyuiop";
  char test5[100] = "        !!";
  char s21test2[100] = "qwertyuiop";
  char s21test5[100] = "        !!";
  char* sys = strncat(test2, test5, 3);
  char* s21 = s21_strncat(s21test2, s21test5, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test9) {
  char test2[100] = "qwertyuiop";
  char test6[100] = "\n\0";
  char s21test2[100] = "qwertyuiop";
  char s21test6[100] = "\n\0";
  char* sys = strncat(test2, test6, 3);
  char* s21 = s21_strncat(s21test2, s21test6, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test10) {
  char test3[100] = "    \n\0";
  char test4[100] = "\0\n";
  char s21test3[100] = "    \n\0";
  char s21test4[100] = "\0\n";
  char* sys = strncat(test3, test4, 3);
  char* s21 = s21_strncat(s21test3, s21test4, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test11) {
  char test3[100] = "    \n\0";
  char test5[100] = "        !!";
  char s21test3[100] = "    \n\0";
  char s21test5[100] = "        !!";
  char* sys = strncat(test3, test5, 3);
  char* s21 = s21_strncat(s21test3, s21test5, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test12) {
  char test3[100] = "    \n\0";
  char test6[100] = "\n\0";
  char s21test3[100] = "    \n\0";
  char s21test6[100] = "\n\0";
  char* sys = strncat(test3, test6, 3);
  char* s21 = s21_strncat(s21test3, s21test6, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test13) {
  char test4[100] = "\0\n";
  char test5[100] = "        !!";
  char s21test4[100] = "\0\n";
  char s21test5[100] = "        !!";
  char* sys = strncat(test4, test5, 3);
  char* s21 = s21_strncat(s21test4, s21test5, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test14) {
  char test4[100] = "\0\n";
  char test6[100] = "\n\0";
  char s21test4[100] = "\0\n";
  char s21test6[100] = "\n\0";
  char* sys = strncat(test4, test6, 3);
  char* s21 = s21_strncat(s21test4, s21test6, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test15) {
  char test5[100] = "        !!";
  char test6[100] = "\n\0";
  char s21test5[100] = "        !!";
  char s21test6[100] = "\n\0";
  char* sys = strncat(test5, test6, 3);
  char* s21 = s21_strncat(s21test5, s21test6, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test16) {
  char dst[100] = "Hello";
  char dst2[100] = "Hello";
  char* src = " World!";
  char* sys = strncat(dst2, src, 3);
  char* s21 = s21_strncat(dst, src, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncat_test17) {
  char dst3[100] = "Hello";
  char dst4[100] = "Hello";
  char* src = " World!";
  char* sys = strncat(dst4, src, 3);
  char* s21 = s21_strncat(dst3, src, 3);
  ck_assert_str_eq(sys, s21);
}
END_TEST

// STRCHR

START_TEST(s21_strchr_test1) {
  char kek1[100] =
      "banana found day good!  \n banana found day good!  \n banana found day "
      "good!  \n";
  char* sys = strchr(kek1, 98);
  char* s21 = s21_strchr(kek1, 98);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_strchr_test2) {
  char kek1[100] =
      "banana found day good!  \n banana found day good!  \n banana found day "
      "good!  \n";
  char* sys = strchr(kek1, 9);
  char* s21 = s21_strchr(kek1, 9);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_strchr_test3) {
  char kek1[100] =
      "banana found day good!  \n banana found day good!  \n banana found day "
      "good!  \n";
  char* sys = strchr(kek1, 102);
  char* s21 = s21_strchr(kek1, 102);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_strchr_test4) {
  char kek1[100] =
      "banana found day good!  \n banana found day good!  \n banana found day "
      "good!  \n";
  char* sys = strchr(kek1, 10);
  char* s21 = s21_strchr(kek1, 10);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_strchr_test5) {
  char kek1[100] =
      "banana found day good!  \n banana found day good!  \n banana found day "
      "good!  \n";
  char* sys = strchr(kek1 + 20, 33);
  char* s21 = s21_strchr(kek1 + 20, 33);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_strchr_test6) {
  char kek1[100] =
      "banana found day good!  \n banana found day good!  \n banana found day "
      "good!  \n";
  char* sys = strchr(kek1, 0);
  char* s21 = s21_strchr(kek1, 0);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

START_TEST(s21_strchr_test7) {
  char* string = "Snickersnee";
  char search_for = 'n';
  char* sys = strchr(string, search_for);
  char* s21 = s21_strchr(string, search_for);
  ck_assert_pstr_eq(sys, s21);
}
END_TEST

// STRCMP

START_TEST(s21_strcmp_test1) {
  char test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  int sys = strcmp(test1, test2);
  int s21 = s21_strcmp(test1, test2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test2) {
  char test1[] = "Hello world\0";
  char test3[] = "a\n\0";
  int sys = strcmp(test1, test3);
  int s21 = s21_strcmp(test1, test3);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test3) {
  char test1[] = "Hello world\0";
  char test4[] = " \n\0";
  int sys = strcmp(test1, test4);
  int s21 = s21_strcmp(test1, test4);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test4) {
  char test1[] = "Hello world\0";
  char test5[] = " \0";
  int sys = strcmp(test1, test5);
  int s21 = s21_strcmp(test1, test5);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test5) {
  char test1[] = "Hello world\0";
  char test6[] = "\n\0";
  int sys = strcmp(test1, test6);
  int s21 = s21_strcmp(test1, test6);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test6) {
  char test1[] = "Hello world\0";
  char test7[] = "\0";
  int sys = strcmp(test1, test7);
  int s21 = s21_strcmp(test1, test7);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test7) {
  char test2[] = "Hello world\n\0";
  char test3[] = "a\n\0";
  int sys = strcmp(test2, test3);
  int s21 = s21_strcmp(test2, test3);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test8) {
  char test2[] = "Hello world\n\0";
  char test4[] = " \n\0";
  int sys = strcmp(test2, test4);
  int s21 = s21_strcmp(test2, test4);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test9) {
  char test2[] = "Hello world\n\0";
  char test5[] = " \0";
  int sys = strcmp(test2, test5);
  int s21 = s21_strcmp(test2, test5);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test10) {
  char test2[] = "Hello world\n\0";
  char test6[] = "\n\0";
  int sys = strcmp(test2, test6);
  int s21 = s21_strcmp(test2, test6);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test11) {
  char test2[] = "Hello world\n\0";
  char test7[] = "\0";
  int sys = strcmp(test2, test7);
  int s21 = s21_strcmp(test2, test7);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test12) {
  char test3[] = "a\n\0";
  char test4[] = " \n\0";
  int sys = strcmp(test3, test4);
  int s21 = s21_strcmp(test3, test4);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test13) {
  char test3[] = "a\n\0";
  char test5[] = " \0";
  int sys = strcmp(test3, test5);
  int s21 = s21_strcmp(test3, test5);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test14) {
  char test3[] = "a\n\0";
  char test6[] = "\n\0";
  int sys = strcmp(test3, test6);
  int s21 = s21_strcmp(test3, test6);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test15) {
  char test3[] = "a\n\0";
  char test7[] = "\0";
  int sys = strcmp(test3, test7);
  int s21 = s21_strcmp(test3, test7);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test16) {
  char test4[] = " \n\0";
  char test5[] = " \0";
  int sys = strcmp(test4, test5);
  int s21 = s21_strcmp(test4, test5);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test17) {
  char test4[] = " \n\0";
  char test6[] = "\n\0";
  int sys = strcmp(test4, test6);
  int s21 = s21_strcmp(test4, test6);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test18) {
  char test4[] = " \n\0";
  char test7[] = "\0";
  int sys = strcmp(test4, test7);
  int s21 = s21_strcmp(test4, test7);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test19) {
  char test5[] = " \0";
  char test6[] = "\n\0";
  int sys = strcmp(test5, test6);
  int s21 = s21_strcmp(test5, test6);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test20) {
  char test5[] = " \0";
  char test7[] = "\0";
  int sys = strcmp(test5, test7);
  int s21 = s21_strcmp(test5, test7);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test21) {
  char test6[] = "\n\0";
  char test7[] = "\0";
  int sys = strcmp(test6, test7);
  int s21 = s21_strcmp(test6, test7);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strcmp_test22) {
  char* str1 = "school21";
  char* str2 = "school21";
  int s21 = s21_strcmp(str1, str2);
  ck_assert_int_eq(s21, 0);
}
END_TEST

START_TEST(s21_strcmp_test23) {
  char* str1 = "school21";
  char* str2 = "school21";
  int sys = strcmp(str1, str2);
  int s21 = s21_strcmp(str1, str2);
  ck_assert_int_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcmp_test24) {
  char* str1 = "school21";
  char* str3 = "school211";
  int s21 = s21_strcmp(str1, str3);
  ck_assert_int_lt(s21, 0);
}
END_TEST

START_TEST(s21_strcmp_test25) {
  char* str1 = "school21";
  char* str3 = "school211";
  int sys = strcmp(str1, str3);
  int s21 = s21_strcmp(str1, str3);
  ck_assert(s21 < 0 && sys < 0);
}
END_TEST

// STRNCMP

START_TEST(s21_strncmp_test1) {
  char test1[] = "Hello world\0";
  char s21test1[] = "Hello world\0";
  int sys = strncmp(test1, test1, 2);
  int s21 = s21_strncmp(s21test1, s21test1, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test2) {
  char test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test1[] = "Hello world\0";
  char s21test2[] = "Hello world\n\0";
  int sys = strncmp(test1, test2, 11);
  int s21 = s21_strncmp(s21test1, s21test2, 11);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test3) {
  char test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test1[] = "Hello world\0";
  char s21test2[] = "Hello world\n\0";
  int sys = strncmp(test1, test2, 2);
  int s21 = s21_strncmp(s21test1, s21test2, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test4) {
  char test1[] = "Hello world\0";
  char test3[] = "a\n\0";
  char s21test1[] = "Hello world\0";
  char s21test3[] = "a\n\0";
  int sys = strncmp(test1, test3, 2);
  int s21 = s21_strncmp(s21test1, s21test3, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test5) {
  char test1[] = "Hello world\0";
  char test4[] = " \n\0";
  char s21test1[] = "Hello world\0";
  char s21test4[] = " \n\0";
  int sys = strncmp(test1, test4, 2);
  int s21 = s21_strncmp(s21test1, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test6) {
  char test1[] = "Hello world\0";
  char test5[] = " \0";
  char s21test1[] = "Hello world\0";
  char s21test5[] = " \0";
  int sys = strncmp(test1, test5, 2);
  int s21 = s21_strncmp(s21test1, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test7) {
  char test1[] = "Hello world\0";
  char test6[] = "\n\0";
  char s21test1[] = "Hello world\0";
  char s21test6[] = "\n\0";
  int sys = strncmp(test1, test6, 2);
  int s21 = s21_strncmp(s21test1, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test8) {
  char test1[] = "Hello world\0";
  char test7[] = "\0";
  char s21test1[] = "Hello world\0";
  char s21test7[] = "\0";
  int sys = strncmp(test1, test7, 2);
  int s21 = s21_strncmp(s21test1, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test9) {
  char test2[] = "Hello world\n\0";
  char s21test2[] = "Hello world\n\0";
  int sys = strncmp(test2, test2, 2);
  int s21 = s21_strncmp(s21test2, s21test2, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test10) {
  char test2[] = "Hello world\n\0";
  char test3[] = "a\n\0";
  char s21test2[] = "Hello world\n\0";
  char s21test3[] = "a\n\0";
  int sys = strncmp(test2, test3, 2);
  int s21 = s21_strncmp(s21test2, s21test3, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test11) {
  char test2[] = "Hello world\n\0";
  char test4[] = " \n\0";
  char s21test2[] = "Hello world\n\0";
  char s21test4[] = " \n\0";
  int sys = strncmp(test2, test4, 2);
  int s21 = s21_strncmp(s21test2, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test12) {
  char test2[] = "Hello world\n\0";
  char test5[] = " \0";
  char s21test2[] = "Hello world\n\0";
  char s21test5[] = " \0";
  int sys = strncmp(test2, test5, 2);
  int s21 = s21_strncmp(s21test2, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test13) {
  char test2[] = "Hello world\n\0";
  char test6[] = "\n\0";
  char s21test2[] = "Hello world\n\0";
  char s21test6[] = "\n\0";
  int sys = strncmp(test2, test6, 2);
  int s21 = s21_strncmp(s21test2, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test14) {
  char test2[] = "Hello world\n\0";
  char test7[] = "\0";
  char s21test2[] = "Hello world\n\0";
  char s21test7[] = "\0";
  int sys = strncmp(test2, test7, 2);
  int s21 = s21_strncmp(s21test2, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test15) {
  char test3[] = "a\n\0";
  char s21test3[] = "a\n\0";
  int sys = strncmp(test3, test3, 2);
  int s21 = s21_strncmp(s21test3, s21test3, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test16) {
  char test3[] = "a\n\0";
  char test4[] = " \n\0";
  char s21test3[] = "a\n\0";
  char s21test4[] = " \n\0";
  int sys = strncmp(test3, test4, 2);
  int s21 = s21_strncmp(s21test3, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test17) {
  char test3[] = "a\n\0";
  char test5[] = " \0";
  char s21test3[] = "a\n\0";
  char s21test5[] = " \0";
  int sys = strncmp(test3, test5, 2);
  int s21 = s21_strncmp(s21test3, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test18) {
  char test3[] = "a\n\0";
  char test6[] = "\n\0";
  char s21test3[] = "a\n\0";
  char s21test6[] = "\n\0";
  int sys = strncmp(test3, test6, 2);
  int s21 = s21_strncmp(s21test3, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test19) {
  char test3[] = "a\n\0";
  char test7[] = "\0";
  char s21test3[] = "a\n\0";
  char s21test7[] = "\0";
  int sys = strncmp(test3, test7, 2);
  int s21 = s21_strncmp(s21test3, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test20) {
  char test4[] = " \n\0";
  char s21test4[] = " \n\0";
  int sys = strncmp(test4, test4, 2);
  int s21 = s21_strncmp(s21test4, s21test4, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test21) {
  char test4[] = " \n\0";
  char test5[] = " \0";
  char s21test4[] = " \n\0";
  char s21test5[] = " \0";
  int sys = strncmp(test4, test5, 2);
  int s21 = s21_strncmp(s21test4, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test22) {
  char test4[] = " \n\0";
  char test6[] = "\n\0";
  char s21test4[] = " \n\0";
  char s21test6[] = "\n\0";
  int sys = strncmp(test4, test6, 2);
  int s21 = s21_strncmp(s21test4, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test23) {
  char test4[] = " \n\0";
  char test7[] = "\0";
  char s21test4[] = " \n\0";
  char s21test7[] = "\0";
  int sys = strncmp(test4, test7, 2);
  int s21 = s21_strncmp(s21test4, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test24) {
  char test5[] = " \0";
  char s21test5[] = " \0";
  int sys = strncmp(test5, test5, 2);
  int s21 = s21_strncmp(s21test5, s21test5, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test25) {
  char test5[] = " \0";
  char test6[] = "\n\0";
  char s21test5[] = " \0";
  char s21test6[] = "\n\0";
  int sys = strncmp(test5, test6, 2);
  int s21 = s21_strncmp(s21test5, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test26) {
  char test5[] = " \0";
  char test7[] = "\0";
  char s21test5[] = " \0";
  char s21test7[] = "\0";
  int sys = strncmp(test5, test7, 2);
  int s21 = s21_strncmp(s21test5, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test27) {
  char test6[] = "\n\0";
  char s21test6[] = "\n\0";
  int sys = strncmp(test6, test6, 2);
  int s21 = s21_strncmp(s21test6, s21test6, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test28) {
  char test6[] = "\n\0";
  char test7[] = "\0";
  char s21test6[] = "\n\0";
  char s21test7[] = "\0";
  int sys = strncmp(test6, test7, 2);
  int s21 = s21_strncmp(s21test6, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test29) {
  char test7[] = "\0";
  char s21test7[] = "\0";
  int sys = strncmp(test7, test7, 2);
  int s21 = s21_strncmp(s21test7, s21test7, 2);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test30) {
  char test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test1[] = "Hello world\0";
  char s21test2[] = "Hello world\n\0";
  int sys = strncmp(test1, test2, 0);
  int s21 = s21_strncmp(s21test1, s21test2, 0);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test31) {
  char test1[] = "Hello world\0";
  char test2[] = "Hello world\n\0";
  char s21test1[] = "Hello world\0";
  char s21test2[] = "Hello world\n\0";
  int sys = strncmp(test1, test2, 1);
  int s21 = s21_strncmp(s21test1, s21test2, 1);
  ck_assert_int_eq(sys, s21);
}
END_TEST

START_TEST(s21_strncmp_test32) {
  char* str1 = "1234567890";
  char* str2 = "1234507890";
  int n1 = 5;
  int s21 = s21_strncmp(str1, str2, n1);
  ck_assert_int_eq(s21, 0);
}
END_TEST

START_TEST(s21_strncmp_test33) {
  char* str1 = "1234567890";
  char* str2 = "1234507890";
  int n1 = 5;
  int sys = strncmp(str1, str2, n1);
  int s21 = s21_strncmp(str1, str2, n1);
  ck_assert_int_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncmp_test34) {
  char* str1 = "1234567890";
  char* str2 = "1234507890";
  int n3 = 0;
  int s21 = s21_strncmp(str1, str2, n3);
  ;
  ck_assert_int_eq(s21, 0);
}
END_TEST

START_TEST(s21_strncmp_test35) {
  char* str1 = "1234567890";
  char* str2 = "1234507890";
  int n3 = 0;
  int sys = strncmp(str1, str2, n3);
  int s21 = s21_strncmp(str1, str2, n3);
  ck_assert_int_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncmp_test36) {
  char* str1 = "1234567890";
  char* str2 = "1234507890";
  int n2 = 6;
  int s21 = s21_strncmp(str1, str2, n2);
  ck_assert_int_gt(s21, 0);
}
END_TEST

START_TEST(s21_strncmp_test37) {
  char* str1 = "1234567890";
  char* str2 = "1234507890";
  int n2 = 6;
  int sys = strncmp(str1, str2, n2);
  int s21 = s21_strncmp(str1, str2, n2);
  ck_assert(s21 > 0 && sys > 0);
}
END_TEST

// STRNCPY

START_TEST(s21_strncpy_test1) {
  char test1[] = "121345678910111213141516171819120212223";
  char test2[] = "qwertyuiop";
  char s21test1[] = "121345678910111213141516171819120212223";
  char s21test2[] = "qwertyuiop";
  char* sys = strncpy(test1, test2, 3);
  char* s21 = s21_strncpy(s21test1, s21test2, 3);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test2) {
  char test1[] = "121345678910111213141516171819120212223";
  char test3[] = "    \n\0";
  char s21test1[] = "121345678910111213141516171819120212223";
  char s21test3[] = "    \n\0";
  char* sys = strncpy(test1, test3, 3);
  char* s21 = s21_strncpy(s21test1, s21test3, 3);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test3) {
  char test1[] = "121345678910111213141516171819120212223";
  char test4[] = "\0\n";
  char s21test1[] = "121345678910111213141516171819120212223";
  char s21test4[] = "\0\n";
  char* sys = strncpy(test1, test4, 3);
  char* s21 = s21_strncpy(s21test1, s21test4, 3);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test4) {
  char test1[] = "121345678910111213141516171819120212223";
  char test5[] = "        !!";
  char s21test1[] = "121345678910111213141516171819120212223";
  char s21test5[] = "        !!";
  char* sys = strncpy(test1, test5, 3);
  char* s21 = s21_strncpy(s21test1, s21test5, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test5) {
  char test1[] = "121345678910111213141516171819120212223";
  char test6[] = "\n\0";
  char s21test1[] = "121345678910111213141516171819120212223";
  char s21test6[] = "\n\0";
  char* sys = strncpy(test1, test6, 3);
  char* s21 = s21_strncpy(s21test1, s21test6, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test6) {
  char test2[] = "qwertyuiop";
  char test3[] = "    \n\0";
  char s21test2[] = "qwertyuiop";
  char s21test3[] = "    \n\0";
  char* sys = strncpy(test2, test3, 3);
  char* s21 = s21_strncpy(s21test2, s21test3, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test7) {
  char test2[] = "qwertyuiop";
  char test4[] = "\0\n";
  char s21test2[] = "qwertyuiop";
  char s21test4[] = "\0\n";
  char* sys = strncpy(test2, test4, 3);
  char* s21 = s21_strncpy(s21test2, s21test4, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test8) {
  char test2[] = "qwertyuiop";
  char test5[] = "        !!";
  char s21test2[] = "qwertyuiop";
  char s21test5[] = "        !!";
  char* sys = strncpy(test2, test5, 3);
  char* s21 = s21_strncpy(s21test2, s21test5, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test9) {
  char test2[] = "qwertyuiop";
  char test6[] = "\n\0";
  char s21test2[] = "qwertyuiop";
  char s21test6[] = "\n\0";
  char* sys = strncpy(test2, test6, 3);
  char* s21 = s21_strncpy(s21test2, s21test6, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test10) {
  char test3[] = "    \n\0";
  char test4[] = "\0\n";
  char s21test3[] = "    \n\0";
  char s21test4[] = "\0\n";
  char* sys = strncpy(test3, test4, 3);
  char* s21 = s21_strncpy(s21test3, s21test4, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test11) {
  char test3[] = "    \n\0";
  char test5[] = "        !!";
  char s21test3[] = "    \n\0";
  char s21test5[] = "        !!";
  char* sys = strncpy(test3, test5, 3);
  char* s21 = s21_strncpy(s21test3, s21test5, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test12) {
  char test3[] = "    \n\0";
  char test6[] = "\n\0";
  char s21test3[] = "    \n\0";
  char s21test6[] = "\n\0";
  char* sys = strncpy(test3, test6, 3);
  char* s21 = s21_strncpy(s21test3, s21test6, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test13) {
  char test4[] = "\0\n";
  char test5[] = "        !!";
  char s21test4[] = "\0\n";
  char s21test5[] = "        !!";
  char* sys = strncpy(test4, test5, 3);
  char* s21 = s21_strncpy(s21test4, s21test5, 3);

  ck_assert_uint_eq(*s21, *sys);
  ck_assert_uint_eq(*(s21 + 1), *(sys + 1));
  ck_assert_uint_eq(*(s21 + 2), *(sys + 2));
}
END_TEST

START_TEST(s21_strncpy_test14) {
  char test4[] = "\0\n";
  char test6[] = "\n\0";
  char s21test4[] = "\0\n";
  char s21test6[] = "\n\0";
  char* sys = strncpy(test4, test6, 3);
  char* s21 = s21_strncpy(s21test4, s21test6, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test15) {
  char test5[] = "        !!";
  char test6[] = "\n\0";
  char s21test5[] = "        !!";
  char s21test6[] = "\n\0";
  char* sys = strncpy(test5, test6, 3);
  char* s21 = s21_strncpy(s21test5, s21test6, 3);

  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strncpy_test16) {
  char src[13] = "Hello world!";
  char dest[25] = "aaaaaaaaaaaaaaaaaaaa";
  char res[25] = "aaaaaaaaaaaaaaaaaaaa";
  int n = 25;
  char* sys = strncpy(res, src, n);
  char* s21 = s21_strncpy(dest, src, n);

  ck_assert_str_eq(s21, sys);
}
END_TEST

// STRCPY

START_TEST(s21_strcpy_test1) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test2[100] = "qwertyuiop";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test2[100] = "qwertyuiop";
  char* sys = strcpy(test1, test2);
  char* s21 = s21_strcpy(s21test1, s21test2);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test2) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test3[100] = "    \n\0";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test3[100] = "    \n\0";
  char* sys = strcpy(test1, test3);
  char* s21 = s21_strcpy(s21test1, s21test3);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test3) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test4[100] = "\0\n";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test4[100] = "\0\n";
  char* sys = strcpy(test1, test4);
  char* s21 = s21_strcpy(s21test1, s21test4);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test4) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test5[100] = "        !!";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test5[100] = "        !!";
  char* sys = strcpy(test1, test5);
  char* s21 = s21_strcpy(s21test1, s21test5);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test5) {
  char test1[100] = "121345678910111213141516171819120212223";
  char test6[100] = "\n\0";
  char s21test1[100] = "121345678910111213141516171819120212223";
  char s21test6[100] = "\n\0";
  char* sys = strcpy(test1, test6);
  char* s21 = s21_strcpy(s21test1, s21test6);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test6) {
  char test2[100] = "qwertyuiop";
  char test3[100] = "    \n\0";
  char s21test2[100] = "qwertyuiop";
  char s21test3[100] = "    \n\0";
  char* sys = strcpy(test2, test3);
  char* s21 = s21_strcpy(s21test2, s21test3);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test7) {
  char test2[100] = "qwertyuiop";
  char test4[100] = "\0\n";
  char s21test2[100] = "qwertyuiop";
  char s21test4[100] = "\0\n";
  char* sys = strcpy(test2, test4);
  char* s21 = s21_strcpy(s21test2, s21test4);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test8) {
  char test2[100] = "qwertyuiop";
  char test5[100] = "        !!";
  char s21test2[100] = "qwertyuiop";
  char s21test5[100] = "        !!";
  char* sys = strcpy(test2, test5);
  char* s21 = s21_strcpy(s21test2, s21test5);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test9) {
  char test2[100] = "qwertyuiop";
  char test6[100] = "\n\0";
  char s21test2[100] = "qwertyuiop";
  char s21test6[100] = "\n\0";
  char* sys = strcpy(test2, test6);
  char* s21 = s21_strcpy(s21test2, s21test6);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test10) {
  char test3[100] = "    \n\0";
  char test4[100] = "\0\n";
  char s21test3[100] = "    \n\0";
  char s21test4[100] = "\0\n";
  char* sys = strcpy(test3, test4);
  char* s21 = s21_strcpy(s21test3, s21test4);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test11) {
  char test3[100] = "    \n\0";
  char test5[100] = "        !!";
  char s21test3[100] = "    \n\0";
  char s21test5[100] = "        !!";
  char* sys = strcpy(test3, test5);
  char* s21 = s21_strcpy(s21test3, s21test5);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test12) {
  char test3[100] = "    \n\0";
  char test6[100] = "\n\0";
  char s21test3[100] = "    \n\0";
  char s21test6[100] = "\n\0";
  char* sys = strcpy(test3, test6);
  char* s21 = s21_strcpy(s21test3, s21test6);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test13) {
  char test4[100] = "\0\n";
  char test5[100] = "        !!";
  char s21test4[100] = "\0\n";
  char s21test5[100] = "        !!";
  char* sys = strcpy(test4, test5);
  char* s21 = s21_strcpy(s21test4, s21test5);
  ck_assert_uint_eq(*s21, *sys);
  ck_assert_uint_eq(*(s21 + 1), *(sys + 1));
  ck_assert_uint_eq(*(s21 + 2), *(sys + 2));
}
END_TEST

START_TEST(s21_strcpy_test14) {
  char test4[100] = "\0\n";
  char test6[100] = "\n\0";
  char s21test4[100] = "\0\n";
  char s21test6[100] = "\n\0";
  char* sys = strcpy(test4, test6);
  char* s21 = s21_strcpy(s21test4, s21test6);
  ck_assert_str_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcpy_test15) {
  char test5[100] = "        !!";
  char test6[100] = "\n\0";
  char s21test5[100] = "        !!";
  char s21test6[100] = "\n\0";
  char* sys = strcpy(test6, test5);
  char* s21 = s21_strcpy(s21test6, s21test5);
  ck_assert_str_eq(s21, sys);
}
END_TEST

// STRLEN

START_TEST(s21_strlen_test1) {
  char test1[100] = "121345678910111213141516171819120212223";
  int sys = strlen(test1);
  int s21 = s21_strlen(test1);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strlen_test2) {
  char test2[100] = "qwertyuiop";
  int sys = strlen(test2);
  int s21 = s21_strlen(test2);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strlen_test3) {
  char test3[100] = "    \n\0";
  int sys = strlen(test3);
  int s21 = s21_strlen(test3);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strlen_test4) {
  char test4[100] = "\0\n";
  int sys = strlen(test4);
  int s21 = s21_strlen(test4);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strlen_test5) {
  char test5[100] = "        !!";
  int sys = strlen(test5);
  int s21 = s21_strlen(test5);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strlen_test6) {
  char test6[100] = "\n\0";
  int sys = strlen(test6);
  int s21 = s21_strlen(test6);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strlen_test7) {
  char str[25] = "Hello world!";
  int sys = strlen(str);
  int s21 = s21_strlen(str);
  ck_assert_int_eq(s21, sys);
}
END_TEST

// STRPBRK

START_TEST(s21_strpbrk_test1) {
  char test1[100] = "Once upon a time!!\n\0ok";
  char sep1[100] = " !";
  char* sys = strpbrk(test1, sep1);
  char* s21 = s21_strpbrk(test1, sep1);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strpbrk_test2) {
  char test1[100] = "Once upon a time!!\n\0ok";
  char sep2[100] = "! ";
  char* sys = strpbrk(test1, sep2);
  char* s21 = s21_strpbrk(test1, sep2);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strpbrk_test3) {
  char test1[100] = "Once upon a time!!\n\0ok";
  char sep3[100] = "\n\0";
  char* sys = strpbrk(test1, sep3);
  char* s21 = s21_strpbrk(test1, sep3);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strpbrk_test4) {
  char test1[100] = "Once upon a time!!\n\0ok";
  char sep4[100] = "\\";
  char* sys = strpbrk(test1, sep4);
  char* s21 = s21_strpbrk(test1, sep4);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strpbrk_test5) {
  char test1[100] = "Once upon a time!!\n\0ok";
  char sep5[100] = "  @$^";
  char* sys = strpbrk(test1, sep5);
  char* s21 = s21_strpbrk(test1, sep5);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strpbrk_test6) {
  char string[] = "Functions that will make our lives easier!";
  char chars[] = "";
  char* sys = strpbrk(string, chars);
  char* s21 = s21_strpbrk(string, chars);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strpbrk_test7) {
  char string[] = "Functions that will make our lives easier!";
  char chars2[] = "t";
  char* sys = strpbrk(string, chars2);
  char* s21 = s21_strpbrk(string, chars2);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strpbrk_test8) {
  char string[] = "Functions that will make our lives easier!";
  char chars3[2];
  chars3[0] = '\0';
  char* sys = strpbrk(string, chars3);
  char* s21 = s21_strpbrk(string, chars3);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

// STRRCHR

START_TEST(s21_strrchr_test1) {
  char kek1[100] =
      "banana found day good!  \n banana found 102 10 33 0 day good!  \n "
      "banana found day "
      "good!  \n";
  char* sys = strrchr(kek1, 98);
  char* s21 = s21_strrchr(kek1, 98);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strrchr_test2) {
  char kek1[100] =
      "banana found day good!  \n banana found 102 10 33 0 day good!  \n "
      "banana found day "
      "good!  \n";
  char* sys = strrchr(kek1, 9);
  char* s21 = s21_strrchr(kek1, 9);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strrchr_test3) {
  char kek1[100] =
      "banana found day good!  \n banana found 102 10 33 0 day good!  \n "
      "banana found day "
      "good!  \n";
  char* sys = strrchr(kek1, 102);
  char* s21 = s21_strrchr(kek1, 102);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strrchr_test4) {
  char kek1[100] =
      "banana found day good!  \n banana found 102 10 33 0 day good!  \n "
      "banana found day "
      "good!  \n";
  char* sys = strrchr(kek1, 10);
  char* s21 = s21_strrchr(kek1, 10);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strrchr_test5) {
  char kek1[100] =
      "banana found day good!  \n banana found 102 10 33 0 day good!  \n "
      "banana found day "
      "good!  \n";
  char* sys = strrchr(kek1 + 20, 33);
  char* s21 = s21_strrchr(kek1 + 20, 33);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strrchr_test6) {
  char kek1[100] =
      "banana found day good!  \n banana found 102 10 33 0 day good!  \n "
      "banana found day "
      "good!  \n";
  char* sys = strrchr(kek1, 0);
  char* s21 = s21_strrchr(kek1, 0);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strrchr_test7) {
  char* string = "Snickersnee";
  char search_for = 'n';
  char* sys = strrchr(string, search_for);
  char* s21 = s21_strrchr(string, search_for);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strrchr_test8) {
  char string2[20] = "Snickersnee";
  string2[5] = '\0';
  char* sys = strrchr(string2, '\0');
  char* s21 = s21_strrchr(string2, '\0');
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

// STRSTR

START_TEST(s21_strstr_test1) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned1[] = "ba";
  char* sys = strstr(kek1, ned1);
  char* s21 = s21_strstr(kek1, ned1);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test2) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned2[] = "banna";
  char* sys = strstr(kek1, ned2);
  char* s21 = s21_strstr(kek1, ned2);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test3) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned3[] = " \n ";
  char* sys = strstr(kek1, ned3);
  char* s21 = s21_strstr(kek1, ned3);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test4) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned4[] = "\n";
  char* sys = strstr(kek1, ned4);
  char* s21 = s21_strstr(kek1, ned4);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test5) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned5[] = "\0";
  char* sys = strstr(kek1 + 10, ned5);
  char* s21 = s21_strstr(kek1 + 10, ned5);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test6) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned5[] = "\0";
  char* sys = strstr(kek1, ned5);
  char* s21 = s21_strstr(kek1, ned5);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test7) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned6[] = "\0\n";
  char* sys = strstr(kek1, ned6);
  char* s21 = s21_strstr(kek1, ned6);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test8) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned7[] = "\0bana";
  char* sys = strstr(kek1, ned7);
  char* s21 = s21_strstr(kek1, ned7);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test9) {
  char kek1[100] = "banana found day good!  \n bannana found day good!";
  char ned8[] = "banana found day bad";
  char* sys = strstr(kek1, ned8);
  char* s21 = s21_strstr(kek1, ned8);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test10) {
  char* haystack = "This is Sparta!";
  char* needle = "is S";
  char* sys = strstr(haystack, needle);
  char* s21 = s21_strstr(haystack, needle);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test11) {
  char* haystack = "This is Sparta!";
  char* needle2 = "is S ";
  char* sys = strstr(haystack, needle2);
  char* s21 = s21_strstr(haystack, needle2);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test12) {
  char* haystack = "This is Sparta!";
  char* needle3 = "";
  char* sys = strstr(haystack, needle3);
  char* s21 = s21_strstr(haystack, needle3);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strstr_test13) {
  char* haystack2 = "";
  char* needle = "is S";
  char* sys = strstr(haystack2, needle);
  char* s21 = s21_strstr(haystack2, needle);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

// STRTOK

START_TEST(s21_strtok_test1) {
  char test1[] = "1 11 111 1111 11111 111111";
  char del1[100] = " ";
  char* sys = strtok(test1, del1);
  char* s21 = s21_strtok(test1, del1);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strtok_test2) {
  char test2[] = "It will\0 never happends again";
  char del2[100] = "\0";
  char* sys = strtok(test2, del2);
  char* s21 = s21_strtok(test2, del2);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strtok_test3) {
  char test2[] = "It will\0 never happends again";
  char del3[100] = "";
  char* sys = strtok(test2, del3);
  char* s21 = s21_strtok(test2, del3);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strtok_test4) {
  char test3[] = "";
  char del4[100] = "4";
  char* sys = strtok(test3, del4);
  char* s21 = s21_strtok(test3, del4);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strtok_test5) {
  char test3[] = "";
  char del3[100] = "";
  char* sys = strtok(test3, del3);
  char* s21 = s21_strtok(test3, del3);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

START_TEST(s21_strtok_test6) {
  char test4[] = "444444";
  char del4[100] = "4";
  char* sys = strtok(test4, del4);
  char* s21 = s21_strtok(test4, del4);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

// 1
START_TEST(s21_strtok_test7) {
  char p[15] = "VK is Bad Guy";
  char exp[15] = "VK is Bad Guy";
  char* delim = "Visay";
  char* sys = strtok(exp, delim);
  char* s21 = s21_strtok(p, delim);
  ck_assert_pstr_eq(s21, sys);
}
END_TEST

// STRSPN

START_TEST(s21_strspn_test1) {
  char test1[] = "123456";
  char del1[] = "123";
  int sys = strspn(test1, del1);
  int s21 = s21_strspn(test1, del1);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test2) {
  char test1[] = "123456";
  char del2[] = "5123";
  int sys = strspn(test1, del2);
  int s21 = s21_strspn(test1, del2);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test3) {
  char test1[] = "123456";
  char del3[] = "";
  int sys = strspn(test1, del3);
  int s21 = s21_strspn(test1, del3);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test4) {
  char test1[] = "123456";
  char del4[] = "qwe";
  int sys = strspn(test1, del4);
  int s21 = s21_strspn(test1, del4);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test5) {
  char del3[] = "";
  char del4[] = "qwe";
  int sys = strspn(del3, del4);
  int s21 = s21_strspn(del3, del4);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test6) {
  char test1[] = "123456";
  char del5[] = " ";
  int sys = strspn(test1, del5);
  int s21 = s21_strspn(test1, del5);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test7) {
  char str[25] = "Hello world!";
  char acc[6] = "eollH";
  int sys = strspn(str, acc);
  int s21 = s21_strspn(str, acc);
  ck_assert_int_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test8) {
  char acc[6] = "eollH";
  char empty[] = "";
  int sys = s21_strspn(empty, acc);
  int s21 = strspn(empty, acc);
  ck_assert_int_eq(s21, sys);
}
END_TEST

START_TEST(s21_strspn_test9) {
  char str[25] = "Hello world!";
  char acc[6] = "eollH";
  int sys = strspn(str, acc);
  int s21 = s21_strspn(str, acc);
  ck_assert_int_eq(s21, sys);
}
END_TEST

// STRCSPN

START_TEST(s21_strcspn_test1) {
  char test1[] = "1111    12skjfnv345";
  char del1[] = "123sdfvdfbfg";
  int sys = strcspn(test1, del1);
  int s21 = s21_strcspn(test1, del1);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcspn_test2) {
  char test1[] = "1111    12skjfnv345";
  char del2[] = "";
  int sys = strcspn(test1, del2);
  int s21 = s21_strcspn(test1, del2);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcspn_test3) {
  char test1[] = "1111    12skjfnv345";
  char del3[] = "\n   ";
  int sys = strcspn(test1, del3);
  int s21 = s21_strcspn(test1, del3);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcspn_test4) {
  char test1[] = "1111    12skjfnv345";
  char del4[] = "qwe";
  int sys = strcspn(test1, del4);
  int s21 = s21_strcspn(test1, del4);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcspn_test5) {
  char test1[] = "1111    12skjfnv345";
  char del5[] = " ";
  int sys = strcspn(test1, del5);
  int s21 = s21_strcspn(test1, del5);
  ck_assert_uint_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcspn_test6) {
  char str[25] = "Hello world!";
  char rej[6] = "ab cd";
  int sys = strcspn(str, rej);
  int s21 = s21_strcspn(str, rej);
  ck_assert_int_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcspn_test7) {
  char rej[6] = "ab cd";
  char empty[] = "";
  int sys = strcspn(empty, rej);
  int s21 = s21_strcspn(empty, rej);
  ck_assert_int_eq(s21, sys);
}
END_TEST

START_TEST(s21_strcspn_test8) {
  char str[25] = "Hello world!";
  char empty[] = "";
  int sys = strcspn(str, empty);
  int s21 = s21_strcspn(str, empty);
  ck_assert_int_eq(s21, sys);
}
END_TEST

// STRERROR

START_TEST(s21_strerror_test1) {
  for (int i = 0; i < ERRMAX + 1; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(s21_strerror_test2) {
  int errno = -1;
  int errmax = 150;
  while (errno < errmax) {
    ck_assert_str_eq(s21_strerror(errno), strerror(errno));
    errno++;
  }
}
END_TEST

Suite* str_test(void) {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_string #1 baza (str)");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_strcat_test1);
  tcase_add_test(tc_core, s21_strcat_test2);
  tcase_add_test(tc_core, s21_strcat_test3);
  tcase_add_test(tc_core, s21_strcat_test4);
  tcase_add_test(tc_core, s21_strcat_test5);
  tcase_add_test(tc_core, s21_strcat_test6);
  tcase_add_test(tc_core, s21_strcat_test7);
  tcase_add_test(tc_core, s21_strcat_test8);
  tcase_add_test(tc_core, s21_strcat_test9);
  tcase_add_test(tc_core, s21_strcat_test10);
  tcase_add_test(tc_core, s21_strcat_test11);
  tcase_add_test(tc_core, s21_strcat_test12);
  tcase_add_test(tc_core, s21_strcat_test13);
  tcase_add_test(tc_core, s21_strcat_test14);
  tcase_add_test(tc_core, s21_strcat_test15);
  tcase_add_test(tc_core, s21_strcat_test16);
  tcase_add_test(tc_core, s21_strcat_test17);
  tcase_add_test(tc_core, s21_strcat_test18);

  tcase_add_test(tc_core, s21_strncat_test1);
  tcase_add_test(tc_core, s21_strncat_test2);
  tcase_add_test(tc_core, s21_strncat_test3);
  tcase_add_test(tc_core, s21_strncat_test4);
  tcase_add_test(tc_core, s21_strncat_test5);
  tcase_add_test(tc_core, s21_strncat_test6);
  tcase_add_test(tc_core, s21_strncat_test7);
  tcase_add_test(tc_core, s21_strncat_test8);
  tcase_add_test(tc_core, s21_strncat_test9);
  tcase_add_test(tc_core, s21_strncat_test10);
  tcase_add_test(tc_core, s21_strncat_test11);
  tcase_add_test(tc_core, s21_strncat_test12);
  tcase_add_test(tc_core, s21_strncat_test13);
  tcase_add_test(tc_core, s21_strncat_test14);
  tcase_add_test(tc_core, s21_strncat_test15);
  tcase_add_test(tc_core, s21_strncat_test16);
  tcase_add_test(tc_core, s21_strncat_test17);

  tcase_add_test(tc_core, s21_strchr_test1);
  tcase_add_test(tc_core, s21_strchr_test2);
  tcase_add_test(tc_core, s21_strchr_test3);
  tcase_add_test(tc_core, s21_strchr_test4);
  tcase_add_test(tc_core, s21_strchr_test5);
  tcase_add_test(tc_core, s21_strchr_test6);
  tcase_add_test(tc_core, s21_strchr_test7);

  tcase_add_test(tc_core, s21_strcmp_test1);
  tcase_add_test(tc_core, s21_strcmp_test2);
  tcase_add_test(tc_core, s21_strcmp_test3);
  tcase_add_test(tc_core, s21_strcmp_test4);
  tcase_add_test(tc_core, s21_strcmp_test5);
  tcase_add_test(tc_core, s21_strcmp_test6);
  tcase_add_test(tc_core, s21_strcmp_test7);
  tcase_add_test(tc_core, s21_strcmp_test8);
  tcase_add_test(tc_core, s21_strcmp_test9);
  tcase_add_test(tc_core, s21_strcmp_test10);
  tcase_add_test(tc_core, s21_strcmp_test11);
  tcase_add_test(tc_core, s21_strcmp_test12);
  tcase_add_test(tc_core, s21_strcmp_test13);
  tcase_add_test(tc_core, s21_strcmp_test14);
  tcase_add_test(tc_core, s21_strcmp_test15);
  tcase_add_test(tc_core, s21_strcmp_test16);
  tcase_add_test(tc_core, s21_strcmp_test17);
  tcase_add_test(tc_core, s21_strcmp_test18);
  tcase_add_test(tc_core, s21_strcmp_test19);
  tcase_add_test(tc_core, s21_strcmp_test20);
  tcase_add_test(tc_core, s21_strcmp_test21);
  tcase_add_test(tc_core, s21_strcmp_test22);
  tcase_add_test(tc_core, s21_strcmp_test23);
  tcase_add_test(tc_core, s21_strcmp_test24);
  tcase_add_test(tc_core, s21_strcmp_test25);

  tcase_add_test(tc_core, s21_strncmp_test1);
  tcase_add_test(tc_core, s21_strncmp_test2);
  tcase_add_test(tc_core, s21_strncmp_test3);
  tcase_add_test(tc_core, s21_strncmp_test4);
  tcase_add_test(tc_core, s21_strncmp_test5);
  tcase_add_test(tc_core, s21_strncmp_test6);
  tcase_add_test(tc_core, s21_strncmp_test7);
  tcase_add_test(tc_core, s21_strncmp_test8);
  tcase_add_test(tc_core, s21_strncmp_test9);
  tcase_add_test(tc_core, s21_strncmp_test10);
  tcase_add_test(tc_core, s21_strncmp_test11);
  tcase_add_test(tc_core, s21_strncmp_test12);
  tcase_add_test(tc_core, s21_strncmp_test13);
  tcase_add_test(tc_core, s21_strncmp_test14);
  tcase_add_test(tc_core, s21_strncmp_test15);
  tcase_add_test(tc_core, s21_strncmp_test16);
  tcase_add_test(tc_core, s21_strncmp_test17);
  tcase_add_test(tc_core, s21_strncmp_test18);
  tcase_add_test(tc_core, s21_strncmp_test19);
  tcase_add_test(tc_core, s21_strncmp_test20);
  tcase_add_test(tc_core, s21_strncmp_test21);
  tcase_add_test(tc_core, s21_strncmp_test22);
  tcase_add_test(tc_core, s21_strncmp_test23);
  tcase_add_test(tc_core, s21_strncmp_test24);
  tcase_add_test(tc_core, s21_strncmp_test25);
  tcase_add_test(tc_core, s21_strncmp_test26);
  tcase_add_test(tc_core, s21_strncmp_test27);
  tcase_add_test(tc_core, s21_strncmp_test28);
  tcase_add_test(tc_core, s21_strncmp_test29);
  tcase_add_test(tc_core, s21_strncmp_test30);
  tcase_add_test(tc_core, s21_strncmp_test31);
  tcase_add_test(tc_core, s21_strncmp_test32);
  tcase_add_test(tc_core, s21_strncmp_test33);
  tcase_add_test(tc_core, s21_strncmp_test34);
  tcase_add_test(tc_core, s21_strncmp_test35);
  tcase_add_test(tc_core, s21_strncmp_test36);
  tcase_add_test(tc_core, s21_strncmp_test37);

  tcase_add_test(tc_core, s21_strncpy_test1);
  tcase_add_test(tc_core, s21_strncpy_test2);
  tcase_add_test(tc_core, s21_strncpy_test3);
  tcase_add_test(tc_core, s21_strncpy_test4);
  tcase_add_test(tc_core, s21_strncpy_test5);
  tcase_add_test(tc_core, s21_strncpy_test6);
  tcase_add_test(tc_core, s21_strncpy_test7);
  tcase_add_test(tc_core, s21_strncpy_test8);
  tcase_add_test(tc_core, s21_strncpy_test9);
  tcase_add_test(tc_core, s21_strncpy_test10);
  tcase_add_test(tc_core, s21_strncpy_test11);
  tcase_add_test(tc_core, s21_strncpy_test12);
  tcase_add_test(tc_core, s21_strncpy_test13);
  tcase_add_test(tc_core, s21_strncpy_test14);
  tcase_add_test(tc_core, s21_strncpy_test15);
  tcase_add_test(tc_core, s21_strncpy_test16);

  tcase_add_test(tc_core, s21_strcpy_test1);
  tcase_add_test(tc_core, s21_strcpy_test2);
  tcase_add_test(tc_core, s21_strcpy_test3);
  tcase_add_test(tc_core, s21_strcpy_test4);
  tcase_add_test(tc_core, s21_strcpy_test5);
  tcase_add_test(tc_core, s21_strcpy_test6);
  tcase_add_test(tc_core, s21_strcpy_test7);
  tcase_add_test(tc_core, s21_strcpy_test8);
  tcase_add_test(tc_core, s21_strcpy_test9);
  tcase_add_test(tc_core, s21_strcpy_test10);
  tcase_add_test(tc_core, s21_strcpy_test11);
  tcase_add_test(tc_core, s21_strcpy_test12);
  tcase_add_test(tc_core, s21_strcpy_test13);
  tcase_add_test(tc_core, s21_strcpy_test14);
  tcase_add_test(tc_core, s21_strcpy_test15);
  // tcase_add_test(tc_core, s21_strcpy_test16);
  // tcase_add_test(tc_core, s21_strcpy_test17);

  tcase_add_test(tc_core, s21_strlen_test1);
  tcase_add_test(tc_core, s21_strlen_test2);
  tcase_add_test(tc_core, s21_strlen_test3);
  tcase_add_test(tc_core, s21_strlen_test4);
  tcase_add_test(tc_core, s21_strlen_test5);
  tcase_add_test(tc_core, s21_strlen_test6);
  tcase_add_test(tc_core, s21_strlen_test7);

  tcase_add_test(tc_core, s21_strpbrk_test1);
  tcase_add_test(tc_core, s21_strpbrk_test2);
  tcase_add_test(tc_core, s21_strpbrk_test3);
  tcase_add_test(tc_core, s21_strpbrk_test4);
  tcase_add_test(tc_core, s21_strpbrk_test5);
  tcase_add_test(tc_core, s21_strpbrk_test6);
  tcase_add_test(tc_core, s21_strpbrk_test7);
  tcase_add_test(tc_core, s21_strpbrk_test8);

  tcase_add_test(tc_core, s21_strrchr_test1);
  tcase_add_test(tc_core, s21_strrchr_test2);
  tcase_add_test(tc_core, s21_strrchr_test3);
  tcase_add_test(tc_core, s21_strrchr_test4);
  tcase_add_test(tc_core, s21_strrchr_test5);
  tcase_add_test(tc_core, s21_strrchr_test6);
  tcase_add_test(tc_core, s21_strrchr_test7);
  tcase_add_test(tc_core, s21_strrchr_test8);

  tcase_add_test(tc_core, s21_strstr_test1);
  tcase_add_test(tc_core, s21_strstr_test2);
  tcase_add_test(tc_core, s21_strstr_test3);
  tcase_add_test(tc_core, s21_strstr_test4);
  tcase_add_test(tc_core, s21_strstr_test5);
  tcase_add_test(tc_core, s21_strstr_test6);
  tcase_add_test(tc_core, s21_strstr_test7);
  tcase_add_test(tc_core, s21_strstr_test8);
  tcase_add_test(tc_core, s21_strstr_test9);
  tcase_add_test(tc_core, s21_strstr_test10);
  tcase_add_test(tc_core, s21_strstr_test11);
  tcase_add_test(tc_core, s21_strstr_test12);
  tcase_add_test(tc_core, s21_strstr_test13);

  tcase_add_test(tc_core, s21_strtok_test1);
  tcase_add_test(tc_core, s21_strtok_test2);
  tcase_add_test(tc_core, s21_strtok_test3);
  tcase_add_test(tc_core, s21_strtok_test4);
  tcase_add_test(tc_core, s21_strtok_test5);
  tcase_add_test(tc_core, s21_strtok_test6);
  tcase_add_test(tc_core, s21_strtok_test7);
  //   tcase_add_test(tc_core, s21_strtok_test8);

  tcase_add_test(tc_core, s21_strspn_test1);
  tcase_add_test(tc_core, s21_strspn_test2);
  tcase_add_test(tc_core, s21_strspn_test3);
  tcase_add_test(tc_core, s21_strspn_test4);
  tcase_add_test(tc_core, s21_strspn_test5);
  tcase_add_test(tc_core, s21_strspn_test6);
  tcase_add_test(tc_core, s21_strspn_test7);
  tcase_add_test(tc_core, s21_strspn_test8);
  tcase_add_test(tc_core, s21_strspn_test9);

  tcase_add_test(tc_core, s21_strcspn_test1);
  tcase_add_test(tc_core, s21_strcspn_test2);
  tcase_add_test(tc_core, s21_strcspn_test3);
  tcase_add_test(tc_core, s21_strcspn_test4);
  tcase_add_test(tc_core, s21_strcspn_test5);
  tcase_add_test(tc_core, s21_strcspn_test6);
  tcase_add_test(tc_core, s21_strcspn_test7);
  tcase_add_test(tc_core, s21_strcspn_test8);

  tcase_add_test(tc_core, s21_strerror_test1);
  tcase_add_test(tc_core, s21_strerror_test2);

  suite_add_tcase(s, tc_core);
  return s;
}
