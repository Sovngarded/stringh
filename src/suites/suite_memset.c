#include "../test.h"

START_TEST(test_memset_1) {
  unsigned char src[10] = "123456789";
  int n = 6;
  fail_unless(s21_memset(src, 't', n) == memset(src, 't', n));
}
END_TEST

START_TEST(test_memset_2) {
  unsigned char src[10] = "123456789";
  int n = 1;
  fail_unless(s21_memset(src, '\n', n) == memset(src, '\n', n));
}
END_TEST

START_TEST(test_memset_3) {
  unsigned char src[10] = "123456789";
  int n = 3;
  fail_unless(s21_memset(src, '7', n) == memset(src, '7', n));
}
END_TEST

START_TEST(test_memset_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_memset_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_memset_7) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_memset_8) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  int ch = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_memset_9) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

Suite *suite_memset(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mMEMSET\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_memset_1);
  tcase_add_test(tc_core, test_memset_2);
  tcase_add_test(tc_core, test_memset_3);
  tcase_add_test(tc_core, test_memset_4);
  tcase_add_test(tc_core, test_memset_5);
  tcase_add_test(tc_core, test_memset_6);
  tcase_add_test(tc_core, test_memset_7);
  tcase_add_test(tc_core, test_memset_8);
  tcase_add_test(tc_core, test_memset_9);

  suite_add_tcase(s, tc_core);

  return s;
}
