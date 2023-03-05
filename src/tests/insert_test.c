#include "tests.h"
// проверка на параметр "до <индекс символа> не осущетсвлчется"

START_TEST(insert1) {
  char *string = "diary";
  char *string2;
  string2 = s21_insert(string, "ction", 2);
  ck_assert_pstr_eq(string2, "dictionary");
  free(string2);
}
END_TEST

START_TEST(insert2) {
  char *string = "diary";
  char *string2;
  string2 = s21_insert(string, "ction", 8);
  ck_assert_pstr_eq(string2, s21_NULL);
  free(string2);
}
END_TEST

START_TEST(insert3) {
  char *string = s21_NULL;
  char *string2;
  string2 = s21_insert(string, "ction", 2);
  ck_assert_pstr_eq(string2, s21_NULL);
  free(string2);
}
END_TEST

START_TEST(insert_test1) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  s21_size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test2) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  s21_size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test3) {
  char str[] = "";
  char src[] = "";
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_pstr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test4) {
  char *src = s21_NULL;
  char *str = s21_NULL;
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test5) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_test6) {
  char string[41] = "Error. Press F1 to continue";
  char to_insert[20] = "No keyboard. ";
  char expected[100] = "Error. No keyboard. Press F1 to continue";

  char *res = s21_insert(string, to_insert, 7);
  ck_assert_str_eq(expected, res);
  if (res) free(res);

  res = s21_insert(s21_NULL, to_insert, 7);
  ck_assert_pstr_eq(s21_NULL, res);
  if (res) free(res);

  res = s21_insert(string, s21_NULL, 7);
  ck_assert_pstr_eq(s21_NULL, res);
  if (res) free(res);

  res = s21_insert(string, to_insert, 100);
  ck_assert_pstr_eq(s21_NULL, res);
  if (res) free(res);
}
END_TEST

// START_TEST(insert_str_null) {
//   char *str = s21_NULL;
//   char src[] = "Space  ";
//   s21_size_t index = 0;
//   char expected[] = "Space  ";
//   char *got = (char *)s21_insert(src, str, index);
//   ck_assert_str_eq(got, expected);
//   if (got) free(got);
// }
// END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc");
  tcase_add_test(tc, insert1);
  tcase_add_test(tc, insert2);
  tcase_add_test(tc, insert3);
  tcase_add_test(tc, insert_test1);
  tcase_add_test(tc, insert_test2);
  tcase_add_test(tc, insert_test3);
  tcase_add_test(tc, insert_test4);
  tcase_add_test(tc, insert_test5);
  tcase_add_test(tc, insert_test6);
  // tcase_add_test(tc, insert_str_null);

  suite_add_tcase(s, tc);
  return s;
}
