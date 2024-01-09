#include "../test.h"

START_TEST(test_strchr_1) {
  char x[] = "123456";
  char y = '1';
  ck_assert_pstr_eq(s21_strchr(x, y), strchr(x, y));
}
END_TEST

START_TEST(test_strchr_2) {
  char x[] = "123456789";
  char y = '9';
  ck_assert_pstr_eq(s21_strchr(x, y), strchr(x, y));
}
END_TEST

START_TEST(test_strchr_3) {
  char x[] = "";
  char y = '9';
  ck_assert_pstr_eq(s21_strchr(x, y), strchr(x, y));
}
END_TEST

START_TEST(test_strchr_4) {
  char x[] = "123";
  char y = 'a';
  ck_assert_pstr_eq(s21_strchr(x, y), strchr(x, y));
}
END_TEST

START_TEST(test_strchr_5) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_6) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_7) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_8) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_9) {
  char s[] = "Hello, Kayle!";
  int ch = 'K';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_10) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_11) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

START_TEST(test_strchr_12) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strchr(s, ch), s21_strchr(s, ch));
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[102mSTRCHR\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strchr_1);
  tcase_add_test(tc_core, test_strchr_2);
  tcase_add_test(tc_core, test_strchr_3);
  tcase_add_test(tc_core, test_strchr_4);
  tcase_add_test(tc_core, test_strchr_5);
  tcase_add_test(tc_core, test_strchr_6);
  tcase_add_test(tc_core, test_strchr_7);
  tcase_add_test(tc_core, test_strchr_8);
  tcase_add_test(tc_core, test_strchr_9);
  tcase_add_test(tc_core, test_strchr_10);
  tcase_add_test(tc_core, test_strchr_11);
  tcase_add_test(tc_core, test_strchr_12);

  suite_add_tcase(s, tc_core);

  return s;
}
