#include "../test.h"

START_TEST(test_strncpy_1) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Salam";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_strncpy_2) {
  char s1[20] = "Make daddy happy";
  char s2[20] = "Make daddy happy";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_strncpy_3) {
  char s1[30] = "And mommy too";
  char s2[30] = "And mommy too";
  char s3[] = "Lalala";
  s21_size_t n = 7;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_strncpy_4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_strncpy_5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] = "I love C language";
  s21_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_strncpy_6) {
  char s1[50] = "Yeah, I'm victim of Stockholm syndrome";
  char s2[50] = "Yeah, I'm victim of Stockholm syndrome";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_strncpy_7) {
  const char src[13] = "Zamir";
  char dest1[10] = "0000000";
  fail_unless(s21_strncpy(dest1, src, 4) == strncpy(dest1, src, 4));
}
END_TEST

START_TEST(test_strncpy_8) {
  char s1[5];
  char s2[5];
  char s3[] = "";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

Suite *suite_strncpy(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mSTRNCPY\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strncpy_1);
  tcase_add_test(tc_core, test_strncpy_2);
  tcase_add_test(tc_core, test_strncpy_3);
  tcase_add_test(tc_core, test_strncpy_4);
  tcase_add_test(tc_core, test_strncpy_5);
  tcase_add_test(tc_core, test_strncpy_6);
  tcase_add_test(tc_core, test_strncpy_7);
  tcase_add_test(tc_core, test_strncpy_8);

  suite_add_tcase(s, tc_core);

  return s;
}
