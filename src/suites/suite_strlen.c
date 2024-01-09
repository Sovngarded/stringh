#include "../test.h"

START_TEST(test_strlen_1) {
  char x[] = "123";
  ck_assert_int_eq(s21_strlen(x), strlen(x));
}
END_TEST

START_TEST(test_strlen_2) {
  char x[] = "";
  ck_assert_int_eq(s21_strlen(x), strlen(x));
}
END_TEST

START_TEST(test_strlen_3) {
  char x[] = "ashfiuhasfaosfgjaofjoa";
  ck_assert_int_eq(s21_strlen(x), strlen(x));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mSTRLEN\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strlen_1);
  tcase_add_test(tc_core, test_strlen_2);
  tcase_add_test(tc_core, test_strlen_3);

  suite_add_tcase(s, tc_core);

  return s;
}
