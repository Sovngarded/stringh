#include "../test.h"

START_TEST(test_strncat_1) {
  char firstStr[14] = "Hello";
  char secondStr[6] = "World";
  size_t stop = 4;
  ck_assert_str_eq(s21_strncat(firstStr, secondStr, stop),
                   strncat(firstStr, secondStr, stop));
}
END_TEST

START_TEST(test_strncat_2) {
  char firstStr[13] = "21";
  char secondStr[10] = "School";
  size_t stop = 2;
  ck_assert_str_eq(s21_strncat(firstStr, secondStr, stop),
                   strncat(firstStr, secondStr, stop));
}
END_TEST

START_TEST(test_strncat_3) {
  char firstStr[13] = "";
  char secondStr[10] = "qwert";
  size_t stop = 5;
  ck_assert_str_eq(s21_strncat(firstStr, secondStr, stop),
                   strncat(firstStr, secondStr, stop));
}
END_TEST

START_TEST(test_strncat_4) {
  char firstStr[13] = "   ";
  char secondStr[10] = "   s";
  size_t stop = 5;
  ck_assert_str_eq(s21_strncat(firstStr, secondStr, stop),
                   strncat(firstStr, secondStr, stop));
}
END_TEST
Suite *suite_strncat(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mSTRNCAT\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncat_1);
  tcase_add_test(tc_core, test_strncat_2);
  tcase_add_test(tc_core, test_strncat_3);
  tcase_add_test(tc_core, test_strncat_4);

  suite_add_tcase(s, tc_core);

  return s;
}