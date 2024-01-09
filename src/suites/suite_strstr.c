#include "../test.h"

START_TEST(test_strstr_1) {
  char x[] = "123456";
  char y[] = "123";
  ck_assert_pstr_eq(s21_strstr(x, y), strstr(x, y));
}
END_TEST

START_TEST(test_strstr_2) {
  char x[] = "123456789";
  char y[] = "987654321";
  ck_assert_pstr_eq(s21_strstr(x, y), strstr(x, y));
}
END_TEST

START_TEST(test_strstr_3) {
  char x[] = "";
  char y[] = "";
  ck_assert_pstr_eq(s21_strstr(x, y), strstr(x, y));
}
END_TEST

START_TEST(test_strstr_4) {
  char x[] = "123";
  char y[] = "";
  ck_assert_pstr_eq(s21_strstr(x, y), strstr(x, y));
}
END_TEST

START_TEST(test_strstr_5) {
  char x[] = "";
  char y[] = "123";
  ck_assert_pstr_eq(s21_strstr(x, y), strstr(x, y));
}
END_TEST

START_TEST(test_strstr_6) {
  char x[] = "123456";
  char y[] = "123456";
  ck_assert_pstr_eq(s21_strstr(x, y), strstr(x, y));
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[102mSTRSTR\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strstr_1);
  tcase_add_test(tc_core, test_strstr_2);
  tcase_add_test(tc_core, test_strstr_3);
  tcase_add_test(tc_core, test_strstr_4);
  tcase_add_test(tc_core, test_strstr_5);
  tcase_add_test(tc_core, test_strstr_6);

  suite_add_tcase(s, tc_core);

  return s;
}
