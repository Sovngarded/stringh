#include "../test.h"

START_TEST(test_memchr_1) {
  char x[] = "123456";
  char y = '1';
  ck_assert_pstr_eq(s21_memchr(x, y, 6), memchr(x, y, 6));
}
END_TEST

START_TEST(test_memchr_2) {
  char x[] = "123456789";
  char y = '9';
  ck_assert_pstr_eq(s21_memchr(x, y, 9), memchr(x, y, 9));
}
END_TEST

START_TEST(test_memchr_3) {
  char x[] = "";
  char y = '9';
  ck_assert_pstr_eq(s21_memchr(x, y, 9), memchr(x, y, 9));
}
END_TEST

START_TEST(test_memchr_4) {
  char x[] = "123";
  char y = 'a';
  ck_assert_pstr_eq(s21_memchr(x, y, 0), memchr(x, y, 0));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[102mMEMCHR\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memchr_1);
  tcase_add_test(tc_core, test_memchr_2);
  tcase_add_test(tc_core, test_memchr_3);
  tcase_add_test(tc_core, test_memchr_4);

  suite_add_tcase(s, tc_core);

  return s;
}
