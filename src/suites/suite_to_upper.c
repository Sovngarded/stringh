#include "../test.h"

START_TEST(test_to_upper_1) {
  char *res = s21_to_upper("hello!");
  ck_assert_str_eq(res, "HELLO!");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_2) {
  char *res = s21_to_upper("aBcD!");
  ck_assert_str_eq(res, "ABCD!");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_3) {
  char *res = s21_to_upper("123?!");
  ck_assert_str_eq(res, "123?!");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_4) {
  char *res = s21_to_upper("");
  ck_assert_str_eq(res, "");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_upper_5) {
  char *res = s21_to_upper(S21_NULL);
  ck_assert_ptr_null(res);
  if (res) free(res);
}
END_TEST

Suite *suite_to_upper(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[102mTO_UPPER\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_upper_1);
  tcase_add_test(tc_core, test_to_upper_2);
  tcase_add_test(tc_core, test_to_upper_3);
  tcase_add_test(tc_core, test_to_upper_4);
  tcase_add_test(tc_core, test_to_upper_5);

  suite_add_tcase(suite, tc_core);

  return suite;
}