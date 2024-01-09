#include "../test.h"

START_TEST(test_strerror_1) {
  int error = 23;
  ck_assert_int_eq(*s21_strerror(error), *strerror(error));
}
END_TEST

START_TEST(test_strerror_2) {
  int error = 0;
  ck_assert_int_eq(*s21_strerror(error), *strerror(error));
}
END_TEST

START_TEST(test_strerror_3) {
  int error = 32532;
  ck_assert_int_eq(*s21_strerror(error), *strerror(error));
}
END_TEST

START_TEST(test_strerror_4) {
  int error = -2342112;
  ck_assert_int_eq(*s21_strerror(error), *strerror(error));
}
END_TEST

START_TEST(test_strerror_5) {
  int error = 23;
  ck_assert_int_eq(*s21_strerror(error), *strerror(error));
}
END_TEST

START_TEST(test_strerror_6) {
  int error = 0.0 / 0.0;
  ck_assert_int_eq(*s21_strerror(error), *strerror(error));
}
END_TEST

START_TEST(test_strerror_7) {
  int error = 1.0 / 0.0;
  ck_assert_int_eq(*s21_strerror(error), *strerror(error));
}
END_TEST

Suite *suite_strerror(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mSTRERROR\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strerror_1);
  tcase_add_test(tc_core, test_strerror_2);
  tcase_add_test(tc_core, test_strerror_3);
  tcase_add_test(tc_core, test_strerror_4);
  tcase_add_test(tc_core, test_strerror_5);
  tcase_add_test(tc_core, test_strerror_6);
  tcase_add_test(tc_core, test_strerror_7);

  suite_add_tcase(s, tc_core);

  return s;
}
