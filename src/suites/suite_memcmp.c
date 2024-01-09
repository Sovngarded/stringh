#include "../test.h"

START_TEST(test_memcmp_1) {
  unsigned char a[11] = "4";
  unsigned char b[11] = "3";
  ck_assert_int_eq(s21_memcmp(a, b, 5), memcmp(a, b, 5));
}
END_TEST

START_TEST(test_memcmp_2) {
  unsigned char a[10] = "School21";
  unsigned char b[10] = "School21";
  ck_assert_int_eq(s21_memcmp(a, b, 7), memcmp(a, b, 7));
}
END_TEST

START_TEST(test_memcmp_3) {
  unsigned char a[] = "Hello, world";
  unsigned char b[] = "School_21";
  ck_assert_int_eq(s21_memcmp(a, b, 10), memcmp(a, b, 10));
}
END_TEST

START_TEST(test_memcmp_4) {
  unsigned char a[30] = "abcdefgHIJKL1234567890";
  unsigned char b[30] = "abcdefgHIJKL1234567890";
  ck_assert_int_eq(s21_memcmp(a, b, 30), memcmp(a, b, 30));
}
END_TEST

START_TEST(test_memcmp_5) {
  unsigned char a[] = "";
  unsigned char b[] = "";
  ck_assert_int_eq(s21_memcmp(a, b, 0), memcmp(a, b, 0));
}
END_TEST

START_TEST(test_memcmp_6) {
  unsigned char a[] = "Hello";
  unsigned char b[] = "Hello";
  ck_assert_int_eq(s21_memcmp(a, b, 10), memcmp(a, b, 10));
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s;
  TCase *tc6;

  s = suite_create("\033[102mMEMCMP\033[0m");
  tc6 = tcase_create("Core");

  tcase_add_test(tc6, test_memcmp_1);
  tcase_add_test(tc6, test_memcmp_2);
  tcase_add_test(tc6, test_memcmp_3);
  tcase_add_test(tc6, test_memcmp_4);
  tcase_add_test(tc6, test_memcmp_5);
  tcase_add_test(tc6, test_memcmp_6);

  suite_add_tcase(s, tc6);

  return s;
}
