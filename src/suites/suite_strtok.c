#include "../test.h"

START_TEST(test_strtok_1) {
  char firstStr[] = "one,two,three,four,five";
  char delim[] = ",";
  char firstStr2[] = "one,two,three,four,five";
  char delim2[] = ",";
  char *my_strtok = s21_strtok(firstStr, delim);
  char *origin_strtok = strtok(firstStr2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}
END_TEST

START_TEST(test_strtok_2) {
  char firstStr[] = "School.21/edu.ru";
  char delim[] = "/.";
  char firstStr2[] = "School.21/edu.ru";
  char delim2[] = "/.";
  char *my_strtok = s21_strtok(firstStr, delim);
  char *origin_strtok = strtok(firstStr2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}
END_TEST

START_TEST(test_strtok_3) {
  char firstStr[] = "one, two, three, four, five";
  char delim[] = ", ";
  char firstStr2[] = "one, two, three, four, five";
  char delim2[] = ", ";
  char *my_strtok = s21_strtok(firstStr, delim);
  char *origin_strtok = strtok(firstStr2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}
END_TEST

START_TEST(test_strtok_4) {
  char firstStr[] = "   /   s";
  char delim[] = "/";
  char firstStr2[] = "   /   s";
  char delim2[] = "/";
  char *my_strtok = s21_strtok(firstStr, delim);
  char *origin_strtok = strtok(firstStr2, delim2);
  while (my_strtok != S21_NULL) {
    ck_assert_str_eq(my_strtok, origin_strtok);
    my_strtok = s21_strtok(S21_NULL, delim);
    origin_strtok = strtok(S21_NULL, delim2);
  }
}
END_TEST

START_TEST(test_strtok_5) {
  char s1[] = "GHed!";
  char s2[] = "GHed!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_6) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_7) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_8) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_9) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = ",";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_10) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Love it";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_11) {
  char s1[] = "Press F";
  char s2[] = "Press F";
  char s3[] = "F";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_12) {
  char s1[] = "\0Press F";
  char s2[] = "\0Press F";
  char s3[] = "F";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_13) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_14) {
  char s1[] = "\0Dindon!";
  char s2[] = "\0Dindon";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_15) {
  char s1[] = "havhahav";
  char s2[] = "havhahav";
  char s3[] = "ha";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(test_strtok_16) {
  char s1[] = "Hello, ggs";
  char s2[] = "Hello, ggs";
  char s3[] = "\0Look";
  char s4[] = "\0Look";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

START_TEST(test_strtok_17) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
  ck_assert_pstr_eq(strtok(S21_NULL, s5), s21_strtok(S21_NULL, s5));
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mSTRTOK\033[0m");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_strtok_1);
  tcase_add_test(tc_core, test_strtok_2);
  tcase_add_test(tc_core, test_strtok_3);
  tcase_add_test(tc_core, test_strtok_4);
  tcase_add_test(tc_core, test_strtok_5);
  tcase_add_test(tc_core, test_strtok_6);
  tcase_add_test(tc_core, test_strtok_7);
  tcase_add_test(tc_core, test_strtok_8);
  tcase_add_test(tc_core, test_strtok_9);
  tcase_add_test(tc_core, test_strtok_10);
  tcase_add_test(tc_core, test_strtok_11);
  tcase_add_test(tc_core, test_strtok_12);
  tcase_add_test(tc_core, test_strtok_13);
  tcase_add_test(tc_core, test_strtok_14);
  tcase_add_test(tc_core, test_strtok_15);
  tcase_add_test(tc_core, test_strtok_16);
  tcase_add_test(tc_core, test_strtok_17);

  suite_add_tcase(s, tc_core);

  return s;
}