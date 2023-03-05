#ifndef SRC_TESTS_TESTS_H_
#define SRC_TESTS_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

#define TOL 0.000001

Suite *mem_test(void);
Suite *strerror_test(void);
Suite *str_test(void);
Suite *suite_trim(void);
Suite *suite_insert(void);
Suite *suite_to_lower(void);
Suite *suite_to_upper(void);
Suite *sprintf_test(void);
Suite *sscanf_test(void);

#endif  // SRC_TESTS_TESTS_H_
