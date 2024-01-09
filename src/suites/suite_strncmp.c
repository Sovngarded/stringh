#include "../test.h"

START_TEST(test_strncmp_1) {
  char str1[] = "";
  char str2[] = "";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_strncmp_2) {
  char str1[] = "floor";
  char str2[] = "";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_strncmp_3) {
  char str1[] = "";
  char str2[] = "GigaChad";
  s21_size_t n_byte = 0;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_strncmp_4) {
  char str1[] = "Gogogo";
  char str2[] = "Gogogo";
  s21_size_t n_byte = 6;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_strncmp_5) {
  char str1[] = "helloworld";
  char str2[] = "hello";
  s21_size_t n_byte = 10;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

START_TEST(test_strncmp_6) {
  char str1[] = "huhuhuh";
  char str2[] = "huhuhuh";
  s21_size_t n_byte = 1;

  int got = s21_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s;
  TCase *tc8;
  s = suite_create("\033[102mSTRNCMP\033[0m");
  tc8 = tcase_create("Core");

  tcase_add_test(tc8, test_strncmp_1);
  tcase_add_test(tc8, test_strncmp_2);
  tcase_add_test(tc8, test_strncmp_3);
  tcase_add_test(tc8, test_strncmp_4);
  tcase_add_test(tc8, test_strncmp_5);
  tcase_add_test(tc8, test_strncmp_6);

  suite_add_tcase(s, tc8);

  return s;
}
