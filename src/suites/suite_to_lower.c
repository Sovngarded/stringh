#include "../test.h"

START_TEST(test_to_lower_1) {
  char *res = s21_to_lower("HELLO!");
  ck_assert_str_eq(res, "hello!");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_2) {
  char *res = s21_to_lower("AbCd!");
  ck_assert_str_eq(res, "abcd!");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_3) {
  char *res = s21_to_lower("12345?!");
  ck_assert_str_eq(res, "12345?!");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_4) {
  char *res = s21_to_lower("");
  ck_assert_str_eq(res, "");
  if (res) free(res);
}
END_TEST

START_TEST(test_to_lower_5) {
  char *res = s21_to_lower(S21_NULL);
  ck_assert_ptr_null(res);
  if (res) free(res);
}
END_TEST

Suite *suite_to_lower(void) {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("\033[102mTO_LOWER\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_to_lower_1);
  tcase_add_test(tc_core, test_to_lower_2);
  tcase_add_test(tc_core, test_to_lower_3);
  tcase_add_test(tc_core, test_to_lower_4);
  tcase_add_test(tc_core, test_to_lower_5);

  suite_add_tcase(suite, tc_core);

  return suite;
}