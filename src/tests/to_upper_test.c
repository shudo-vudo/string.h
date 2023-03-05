#include "tests.h"

START_TEST(to_upper_1) {
  char str1[] = "hEllO, WoRLD!";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "HELLO, WORLD!");
  free(str2);
}
END_TEST

START_TEST(to_upper_2) {
  char str1[] = "hEllO, WoRLD! 1177";
  char *str2 = (char *)s21_to_upper(str1);
  ck_assert_pstr_eq(str2, "HELLO, WORLD! 1177");
  free(str2);
}
END_TEST
START_TEST(to_upper_test1) {
  char str[] = "good job";
  char expected[] = "GOOD JOB";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test2) {
  char str[] = "empty";
  char expected[] = "EMPTY";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test4) {
  char str[] = " ";
  char expected[] = " ";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test6) {
  char str[] = "this IS 5parta|";
  char *expected = "THIS IS 5PARTA|";
  char str2[] = "";

  char *res1 = s21_to_upper(str);
  char *res2 = s21_to_upper(str2);
  char *res3 = s21_to_upper(s21_NULL);
  ck_assert_pstr_eq(res1, expected);
  ck_assert_pstr_eq(res2, "");
  ck_assert_pstr_eq(res3, s21_NULL);
  if (res1) free(res1);
  if (res2) free(res2);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *s = suite_create("suite_to_upper");
  TCase *tc = tcase_create("to_upper_tc");
  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_test1);
  tcase_add_test(tc, to_upper_test2);
  tcase_add_test(tc, to_upper_test3);
  tcase_add_test(tc, to_upper_test4);
  tcase_add_test(tc, to_upper_test5);
  tcase_add_test(tc, to_upper_test6);

  suite_add_tcase(s, tc);
  return s;
}
