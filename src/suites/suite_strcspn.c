#include "../test.h"

START_TEST(test_strcspn_1) {
  char x[] = "123";
  char y[] = "231";
  ck_assert_int_eq(s21_strcspn(x, y), strcspn(x, y));
}
END_TEST

START_TEST(test_strcspn_2) {
  char x[] = "LOST: 4-8-15-16-23-42";
  char y[] = "1234567890";
  ck_assert_int_eq(s21_strcspn(x, y), strcspn(x, y));
}
END_TEST

START_TEST(test_strcspn_3) {
  char x[] = "asgsagsahgashgsahgoasguashgoasgo2";
  char y[] = "1234567890";
  ck_assert_int_eq(s21_strcspn(x, y), strcspn(x, y));
}
END_TEST

START_TEST(test_strcspn_4) {
  char x[] = "asgsagsahgashgsa7papsgasgasgasgp";
  char y[] = "oooooooo7ooooooo";
  ck_assert_int_eq(s21_strcspn(x, y), strcspn(x, y));
}
END_TEST

Suite *suite_strcspn(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[102mSTRCSPN\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strcspn_1);
  tcase_add_test(tc_core, test_strcspn_2);
  tcase_add_test(tc_core, test_strcspn_3);
  tcase_add_test(tc_core, test_strcspn_4);

  suite_add_tcase(s, tc_core);

  return s;
}
