#include "../test.h"

START_TEST(test_strrchr_1) {
  char x[] = "123456";
  char y = '1';
  ck_assert_pstr_eq(s21_strrchr(x, y), strrchr(x, y));
}
END_TEST

START_TEST(test_strrchr_2) {
  char x[] = "123456789";
  char y = '9';
  ck_assert_pstr_eq(s21_strrchr(x, y), strrchr(x, y));
}
END_TEST

START_TEST(test_strrchr_3) {
  char x[] = "";
  char y = '9';
  ck_assert_pstr_eq(s21_strrchr(x, y), strrchr(x, y));
}
END_TEST

START_TEST(test_strrchr_4) {
  char x[] = "123";
  char y = 'a';
  ck_assert_pstr_eq(s21_strrchr(x, y), strrchr(x, y));
}
END_TEST

START_TEST(test_strrchr_5) {
  char s[] = "Hi, folks!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strrchr_6) {
  char s[] = "kavabanga!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strrchr_7) {
  char s[] = "Hell no, bro!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strrchr_8) {
  char s[] = "Bugaga!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strrchr_9) {
  char s[] = "Hello, Chel!";
  int ch = 'C';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strrchr_10) {
  char s[] = "Wow";
  int ch = 'o';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strrchr_11) {
  char s[] = "18880!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_strrchr_12) {
  char s[] = "Merda!!!";
  int ch = 'M';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[102mSTRRCHR\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strrchr_1);
  tcase_add_test(tc_core, test_strrchr_2);
  tcase_add_test(tc_core, test_strrchr_3);
  tcase_add_test(tc_core, test_strrchr_4);
  tcase_add_test(tc_core, test_strrchr_5);
  tcase_add_test(tc_core, test_strrchr_6);
  tcase_add_test(tc_core, test_strrchr_7);
  tcase_add_test(tc_core, test_strrchr_8);
  tcase_add_test(tc_core, test_strrchr_9);
  tcase_add_test(tc_core, test_strrchr_10);
  tcase_add_test(tc_core, test_strrchr_11);
  tcase_add_test(tc_core, test_strrchr_12);

  suite_add_tcase(s, tc_core);

  return s;
}
