#include "tests.h"

int main(void) {
  SRunner *runner = srunner_create(suite_create(""));

  // srunner_add_suite(runner, mem_test());
  // srunner_add_suite(runner, strerror_test());
  // srunner_add_suite(runner, str_test());
  // srunner_add_suite(runner, suite_trim());
  // srunner_add_suite(runner, suite_insert());
  // srunner_add_suite(runner, suite_to_lower());
  // srunner_add_suite(runner, suite_to_upper());
  srunner_add_suite(runner, sprintf_test());
  // srunner_add_suite(runner, sscanf_test());

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_set_log(runner, "test.log");
  srunner_run_all(runner, CK_NORMAL);
  srunner_free(runner);

  return 0;
}
