#include "../test.h"

START_TEST(test_memcpy_1) {
  unsigned char src[10] = "2546789";
  unsigned char dest[128] = "";
  int n = 6;
  fail_unless(s21_memcpy(src, dest, n) == memcpy(src, dest, n));
}
END_TEST

START_TEST(test_memcpy_2) {
  unsigned char src[10] = "13789";
  unsigned char dest[128] = "";
  int n = 1;
  fail_unless(s21_memcpy(src, dest, n) == memcpy(src, dest, n));
}
END_TEST

START_TEST(test_memcpy_3) {
  unsigned char src[10] = "3789";
  unsigned char dest[128] = "";
  int n = 3;
  fail_unless(s21_memcpy(src, dest, n) == memcpy(src, dest, n));
}
END_TEST

START_TEST(test_memcpy_4) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  char s3[] = ", world!";
  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_6) {
  char s1[] = "Press!";
  char s2[] = "Press!";
  char s3[] = "f";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_7) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "-Salam";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_8) {
  char s1[] = "Ku";
  char s2[] = "Ku";
  char s3[] = "Hi";
  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_9) {
  char s1[] = "Make";
  char s2[] = "Make";
  char s3[] = "love";
  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_10) {
  char s1[] = "string";
  char s2[] = "string";
  char s3[] = ".h";
  s21_size_t n = strlen(s3);
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_11) {
  char s1[] = "911";
  char s2[] = "911";
  char s3[] = "twins";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_12) {
  char s1[] = "a";
  char s2[] = "a";
  char s3[] = "c";
  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

START_TEST(test_memcpy_13) {
  char s1[] = "Leo";
  char s2[] = "Leo";
  char s3[] = "Messi";
  s21_size_t n = 3;
  ck_assert_str_eq(memcpy(s1, s3, n), s21_memcpy(s2, s3, n));
}
END_TEST

Suite *suite_memcpy(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mMEMCPY\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memcpy_1);
  tcase_add_test(tc_core, test_memcpy_2);
  tcase_add_test(tc_core, test_memcpy_3);
  tcase_add_test(tc_core, test_memcpy_4);
  tcase_add_test(tc_core, test_memcpy_5);
  tcase_add_test(tc_core, test_memcpy_6);
  tcase_add_test(tc_core, test_memcpy_7);
  tcase_add_test(tc_core, test_memcpy_8);
  tcase_add_test(tc_core, test_memcpy_9);
  tcase_add_test(tc_core, test_memcpy_10);
  tcase_add_test(tc_core, test_memcpy_11);
  tcase_add_test(tc_core, test_memcpy_12);
  tcase_add_test(tc_core, test_memcpy_13);

  suite_add_tcase(s, tc_core);

  return s;
}
