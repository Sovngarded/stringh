#include "../test.h"

START_TEST(test_sscanf_c1) {
  char strMy;
  char strOrig;
  char *x = "sssss";
  int reternMy = s21_sscanf(x, "%c", &strMy);
  int reternOrig = sscanf(x, "%c", &strOrig);
  ck_assert_int_eq(strMy, strOrig);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_c2) {
  char strMy;
  char strOrig;
  char *x = "421sssss";
  int reternMy = s21_sscanf(x, "%c", &strMy);
  int reternOrig = sscanf(x, "%c", &strOrig);
  ck_assert_int_eq(strMy, strOrig);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_c3) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int reternMy = s21_sscanf(str, format, &c1);
  int reternOrig = sscanf(str, format, &c2);
  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_sscanf_c4) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n   \n  \tafsfsd fs#";
  char c1, c2, c3, c11, c12, c13;
  int reternMy = s21_sscanf(str, format, &c1, &c2, &c3);
  int reternOrig = sscanf(str, format, &c11, &c12, &c13);
  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(c1, c11);
  ck_assert_int_eq(c2, c12);
  ck_assert_int_eq(c3, c13);
}
END_TEST

START_TEST(test_sscanf_c5) {
  char format[] = "%c %*c \t%c";
  char str[] = "\t\n 1    q  2w";
  char c1, c2, c3, c11, c12, c13;
  int reternMy = s21_sscanf(str, format, &c1, &c2, &c3);
  int reternOrig = sscanf(str, format, &c11, &c12, &c13);
  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(c1, c11);
  ck_assert_int_eq(c2, c12);
}
END_TEST

START_TEST(test_sscanf_d1) {
  int myVarible;
  int origVarible;
  char *x = "12345";

  int reternMy = s21_sscanf(x, "%d", &myVarible);
  int reternOrig = sscanf(x, "%d", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_d_width1) {
  int myVarible;
  int origVarible;
  char *x = "12345";

  int reternMy = s21_sscanf(x, "%2d", &myVarible);
  int reternOrig = sscanf(x, "%2d", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_d_width2) {
  int myVarible;
  int origVarible;
  char *x = "-12345";

  int reternMy = s21_sscanf(x, "%7d", &myVarible);
  int reternOrig = sscanf(x, "%7d", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_d_width3) {
  int origVarible;
  int myVarible;
  char *x = "s12345";

  int reternMy = s21_sscanf(x, "%7d", &myVarible);
  int reternOrig = sscanf(x, "%7d", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_d_width4) {
  int myVarible;
  int origVarible;
  char *x = "1.2345";

  int reternMy = s21_sscanf(x, "%7d", &myVarible);
  int reternOrig = sscanf(x, "%7d", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_d_width5) {
  int myVarible;
  int origVarible;
  char *x = "#2345";

  int reternMy = s21_sscanf(x, "%3d", &myVarible);
  int reternOrig = sscanf(x, "%3d", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_hd) {
  short myVarible = 0, origVarible = 0;
  char x[] = "-23434353555";

  int reternMy = s21_sscanf(x, "%hd", &myVarible);
  int reternOrig = sscanf(x, "%hd", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_hd_width) {
  short myVarible = 0, origVarible = 0;
  char x[] = "23434353555";

  int reternMy = s21_sscanf(x, "%3hd", &myVarible);
  int reternOrig = sscanf(x, "%3hd", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_hd_width2) {
  short myVarible = 0, origVarible = 0;
  char x[] = "+23434353555";

  int reternMy = s21_sscanf(x, "%7hd", &myVarible);
  int reternOrig = sscanf(x, "%7hd", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_hd_width3) {
  short myVarible1 = 0, origVarible1 = 0;
  char x[] = "+2343 4353 555";

  int reternMy = s21_sscanf(x, "%7hd", &myVarible1);
  int reternOrig = sscanf(x, "%7hd", &origVarible1);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible1, origVarible1);
}
END_TEST

START_TEST(test_sscanf_ld) {
  long myVarible = 0, origVarible = 0;
  char x[] = "-23434353555";

  int reternMy = s21_sscanf(x, "%ld", &myVarible);
  int reternOrig = sscanf(x, "%ld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_ld_width) {
  long myVarible = 0, origVarible = 0;
  char x[] = "23434353555";

  int reternMy = s21_sscanf(x, "%3ld", &myVarible);
  int reternOrig = sscanf(x, "%3ld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_ld_width2) {
  long myVarible = 0, origVarible = 0;
  char x[] = "+23434353555";

  int reternMy = s21_sscanf(x, "%7hd", &myVarible);
  int reternOrig = sscanf(x, "%7ld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_ld_width3) {
  long int myVarible = 0, origVarible = 0;
  char x[] = "+2343 4353 555";

  int reternMy = s21_sscanf(x, "%7ld", &myVarible);
  int reternOrig = sscanf(x, "%7ld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_lld) {
  long long myVarible = 0, origVarible = 0;
  char x[] = "-23434353555";

  int reternMy = s21_sscanf(x, "%lld", &myVarible);
  int reternOrig = sscanf(x, "%lld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_lld_width) {
  long long myVarible = 0, origVarible = 0;
  char x[] = "23434353555";

  int reternMy = s21_sscanf(x, "%3lld", &myVarible);
  int reternOrig = sscanf(x, "%3lld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_lld_width2) {
  long long myVarible = 0, origVarible = 0;
  char x[] = "+23434353555";

  int reternMy = s21_sscanf(x, "%7lld", &myVarible);
  int reternOrig = sscanf(x, "%7lld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_lld_width3) {
  long long myVarible = 0, origVarible = 0;
  char x[] = "+2343 4353 555";

  int reternMy = s21_sscanf(x, "%7lld", &myVarible);
  int reternOrig = sscanf(x, "%7lld", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_i1) {
  int myVarible;
  int origVarible;
  char *x = "12345";

  int reternMy = s21_sscanf(x, "%i", &myVarible);
  int reternOrig = sscanf(x, "%i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_i_width1) {
  int myVarible;
  int origVarible;
  char *x = "12345";

  int reternMy = s21_sscanf(x, "%2i", &myVarible);
  int reternOrig = sscanf(x, "%2i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_i_width2) {
  int myVarible;
  int origVarible;
  char *x = "12345";

  int reternMy = s21_sscanf(x, "%7i", &myVarible);
  int reternOrig = sscanf(x, "%7i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_i_width3) {
  int myVarible;
  int origVarible;
  char *x = "s12345";

  int reternMy = s21_sscanf(x, "%7i", &myVarible);
  int reternOrig = sscanf(x, "%7i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_i_width4) {
  int myVarible;
  int origVarible;
  char *x = "1.2345";

  int reternMy = s21_sscanf(x, "%7i", &myVarible);
  int reternOrig = sscanf(x, "%7i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_i_width5) {
  int myVarible;
  int origVarible;
  char *x = "#2345";

  int reternMy = s21_sscanf(x, "%3i", &myVarible);
  int reternOrig = sscanf(x, "%3i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_i_16) {
  int myVarible;
  int origVarible;
  char *x = "0xfff";

  int reternMy = s21_sscanf(x, "%i", &myVarible);
  int reternOrig = sscanf(x, "%i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_i_8) {
  int myVarible;
  int origVarible;
  char *x = "0366";

  int reternMy = s21_sscanf(x, "%i", &myVarible);
  int reternOrig = sscanf(x, "%i", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_i_hex1) {
  int myVarible, myVarible2, myVarible3;
  int origVarible, origVarible2, origVarible3;
  char x[] = "0x196 0x211 0x123";

  int reternMy = s21_sscanf(x, "%i%i%i", &myVarible, &myVarible2, &myVarible3);
  int reternOrig =
      sscanf(x, "%i%i%i", &origVarible, &origVarible2, &origVarible3);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
  ck_assert_int_eq(myVarible2, origVarible2);
  ck_assert_int_eq(myVarible3, origVarible3);
}
END_TEST

START_TEST(test_sscanf_f) {
  float myVarible;
  float origVarible;
  char *x = "123.45";

  int reternMy = s21_sscanf(x, "%f", &myVarible);
  int reternOrig = sscanf(x, "%f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_f_width1) {
  float myVarible;
  float origVarible;
  char *x = "123.45";

  int reternMy = s21_sscanf(x, "%2f", &myVarible);
  int reternOrig = sscanf(x, "%2f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_float_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_f_width2) {
  float myVarible;
  float origVarible;
  char *x = "12345";

  int reternMy = s21_sscanf(x, "%7f", &myVarible);
  int reternOrig = sscanf(x, "%7f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_f_width3) {
  float myVarible;
  float origVarible;
  char *x = "s12345";

  int reternMy = s21_sscanf(x, "%7f", &myVarible);
  int reternOrig = sscanf(x, "%7f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_f_width4) {
  float myVarible;
  float origVarible;
  char *x = "1.2345";

  int reternMy = s21_sscanf(x, "%7f", &myVarible);
  int reternOrig = sscanf(x, "%7f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_f_width5) {
  float myVarible;
  float origVarible;
  char *x = "#2345";

  int reternMy = s21_sscanf(x, "%3f", &myVarible);
  int reternOrig = sscanf(x, "%3f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_f_16) {
  float myVarible;
  float origVarible;
  char *x = "0xfff";

  int reternMy = s21_sscanf(x, "%f", &myVarible);
  int reternOrig = sscanf(x, "%f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_f_8) {
  float myVarible;
  float origVarible;
  char *x = "0366";

  int reternMy = s21_sscanf(x, "%f", &myVarible);
  int reternOrig = sscanf(x, "%f", &origVarible);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
}
END_TEST

START_TEST(test_sscanf_s1) {
  char strMy[100];
  char strOrig[100];
  char *x = "hello";
  int reternMy = s21_sscanf(x, "%s", strMy);
  int reternOrig = sscanf(x, "%s", strOrig);
  ck_assert_str_eq(strMy, strOrig);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_s3) {
  char strMy[100];
  char strOrig[100];
  char *x = "wearethechampions";
  int reternMy = s21_sscanf(x, "%3s", strMy);
  int reternOrig = sscanf(x, "%3s", strOrig);
  ck_assert_str_eq(strMy, strOrig);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_s4) {
  char strMy[100];
  char strOrig[100];
  char *x = "whoami";
  int reternMy = s21_sscanf(x, "%12s", strMy);
  int reternOrig = sscanf(x, "%12s", strOrig);
  ck_assert_str_eq(strMy, strOrig);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_s5) {
  char strMy[100];
  char strOrig[100];
  char *x = "whoami";
  int reternMy = s21_sscanf(x, "%12s", strMy);
  int reternOrig = sscanf(x, "%12s", strOrig);
  ck_assert_str_eq(strMy, strOrig);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_u1) {
  int myInt;
  int origInt;
  char *x = "231";

  int reternMy = s21_sscanf(x, "%u", &myInt);
  int reternOrig = sscanf(x, "%u", &origInt);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myInt, origInt);
}
END_TEST

START_TEST(test_sscanf_u2) {
  int myInt;
  int origInt;
  char *x = "-34";

  int reternMy = s21_sscanf(x, "%u", &myInt);
  int reternOrig = sscanf(x, "%u", &origInt);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myInt, origInt);
}
END_TEST

START_TEST(test_sscanf_u4) {
  int myInt;
  int origInt;
  char *x = "-0";

  int reternMy = s21_sscanf(x, "%u", &myInt);
  int reternOrig = sscanf(x, "%u", &origInt);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myInt, origInt);
}
END_TEST

START_TEST(test_sscanf_u5) {
  int myInt;
  int origInt;
  char *x = "123434";

  int reternMy = s21_sscanf(x, "%4u", &myInt);
  int reternOrig = sscanf(x, "%4u", &origInt);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myInt, origInt);
}
END_TEST

START_TEST(test_sscanf_u6) {
  int myInt;
  int origInt;
  char *x = "123";

  int reternMy = s21_sscanf(x, "%5u", &myInt);
  int reternOrig = sscanf(x, "%5u", &origInt);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myInt, origInt);
}
END_TEST

START_TEST(test_sscanf_u9) {
  unsigned long int myInt;
  unsigned long int origInt;
  char *x = "7777";

  int reternMy = s21_sscanf(x, "%lu", &myInt);
  int reternOrig = sscanf(x, "%lu", &origInt);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myInt, origInt);
}
END_TEST

START_TEST(test_sscanf_x1) {
  int MyInt;
  int origInt;
  char *x = "e";

  int returnMy = s21_sscanf(x, "%x", &MyInt);
  int returnOrig = sscanf(x, "%x", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_x2) {
  int MyInt;
  int origInt;
  char *x = "hello";

  int returnMy = s21_sscanf(x, "%x", &MyInt);
  int returnOrig = sscanf(x, "%x", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_x3) {
  int MyInt;
  int origInt;
  char *x = "HI";

  int returnMy = s21_sscanf(x, "%x", &MyInt);
  int returnOrig = sscanf(x, "%x", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_x4) {
  int MyInt;
  int origInt;
  char *x = "hello";

  int returnMy = s21_sscanf(x, "%2x", &MyInt);
  int returnOrig = sscanf(x, "%2x", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_x5) {
  int MyInt;
  int origInt;
  char *x = "hello";

  int returnMy = s21_sscanf(x, "%20x", &MyInt);
  int returnOrig = sscanf(x, "%20x", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_x6) {
  int MyInt;
  short unsigned int origInt;
  char *x = "erkjewknff";

  int returnMy = s21_sscanf(x, "%hx", &MyInt);
  int returnOrig = sscanf(x, "%hx", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_x8) {
  long unsigned int MyInt;
  long unsigned int origInt;
  char *x = "skdjs";

  int returnMy = s21_sscanf(x, "%lx", &MyInt);
  int returnOrig = sscanf(x, "%lx", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_X1) {
  int MyInt;
  int origInt;
  char *X = "e";

  int returnMy = s21_sscanf(X, "%X", &MyInt);
  int returnOrig = sscanf(X, "%X", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_X2) {
  int MyInt;
  int origInt;
  char *X = "hello";

  int returnMy = s21_sscanf(X, "%X", &MyInt);
  int returnOrig = sscanf(X, "%X", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_X3) {
  int MyInt;
  int origInt;
  char *X = "HI";

  int returnMy = s21_sscanf(X, "%X", &MyInt);
  int returnOrig = sscanf(X, "%X", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_X4) {
  int MyInt;
  int origInt;
  char *X = "hello";

  int returnMy = s21_sscanf(X, "%2X", &MyInt);
  int returnOrig = sscanf(X, "%2X", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_X5) {
  int MyInt;
  int origInt;
  char *X = "hello";

  int returnMy = s21_sscanf(X, "%20X", &MyInt);
  int returnOrig = sscanf(X, "%20X", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_X6) {
  int MyInt;
  short unsigned int origInt;
  char *X = "erkjewknff";

  int returnMy = s21_sscanf(X, "%hX", &MyInt);
  int returnOrig = sscanf(X, "%hX", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_X8) {
  long unsigned int MyInt;
  long unsigned int origInt;
  char *X = "skdjs";

  int returnMy = s21_sscanf(X, "%lX", &MyInt);
  int returnOrig = sscanf(X, "%lX", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_G1) {
  float MyInt;
  float origInt;
  char *X = "2134";

  int returnMy = s21_sscanf(X, "%G", &MyInt);
  int returnOrig = sscanf(X, "%G", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_G2) {
  float MyInt;
  float origInt;
  char *X = "34.5672";

  int returnMy = s21_sscanf(X, "%G", &MyInt);
  int returnOrig = sscanf(X, "%G", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_G3) {
  float MyInt;
  float origInt;
  char *X = "-34.5672";

  int returnMy = s21_sscanf(X, "%G", &MyInt);
  int returnOrig = sscanf(X, "%G", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_G4) {
  float MyInt;
  float origInt;
  char *X = "rjkdfr";

  int returnMy = s21_sscanf(X, "%G", &MyInt);
  int returnOrig = sscanf(X, "%G", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_G6) {
  float MyInt;
  float origInt;
  char *X = "493.45";

  int returnMy = s21_sscanf(X, "%4G", &MyInt);
  int returnOrig = sscanf(X, "%4G", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_g1) {
  float MyInt;
  float origInt;
  char *X = "2134";

  int returnMy = s21_sscanf(X, "%g", &MyInt);
  int returnOrig = sscanf(X, "%g", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_g2) {
  float MyInt;
  float origInt;
  char *X = "34.5672";

  int returnMy = s21_sscanf(X, "%g", &MyInt);
  int returnOrig = sscanf(X, "%g", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_g3) {
  float MyInt;
  float origInt;
  char *X = "-34.5672";

  int returnMy = s21_sscanf(X, "%g", &MyInt);
  int returnOrig = sscanf(X, "%g", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_g4) {
  float MyInt;
  float origInt;
  char *X = "rjkdfr";

  int returnMy = s21_sscanf(X, "%g", &MyInt);
  int returnOrig = sscanf(X, "%g", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_g6) {
  float MyInt;
  float origInt;
  char *X = "493.45";

  int returnMy = s21_sscanf(X, "%4g", &MyInt);
  int returnOrig = sscanf(X, "%4g", &origInt);

  ck_assert_float_eq(returnMy, returnOrig);
  ck_assert_float_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_o1) {
  int MyInt;
  int origInt;
  char *X = "0x9340";

  int returnMy = s21_sscanf(X, "%o", &MyInt);
  int returnOrig = sscanf(X, "%o", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_o3) {
  int MyInt;
  int origInt;
  char *X = "0x9340.43";

  int returnMy = s21_sscanf(X, "%o", &MyInt);
  int returnOrig = sscanf(X, "%o", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_o4) {
  int MyInt;
  int origInt;
  char *X = "wqekrj";

  int returnMy = s21_sscanf(X, "%o", &MyInt);
  int returnOrig = sscanf(X, "%o", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
}
END_TEST

START_TEST(test_sscanf_o6) {
  int MyInt;
  int origInt;
  char *X = "2342";

  int returnMy = s21_sscanf(X, "%3o", &MyInt);
  int returnOrig = sscanf(X, "%3o", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_o7) {
  int MyInt;
  int origInt;
  char *X = "2342";

  int returnMy = s21_sscanf(X, "%10o", &MyInt);
  int returnOrig = sscanf(X, "%10o", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_o9) {
  int MyInt;
  int origInt;
  char *X = "2342";

  int returnMy = s21_sscanf(X, "%3o", &MyInt);
  int returnOrig = sscanf(X, "%3o", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_o10) {
  short unsigned int MyInt;
  short unsigned int origInt;
  char *X = "2342";

  int returnMy = s21_sscanf(X, "%ho", &MyInt);
  int returnOrig = sscanf(X, "%ho", &origInt);

  ck_assert_int_eq(returnMy, returnOrig);
  ck_assert_int_eq(MyInt, origInt);
}
END_TEST

START_TEST(test_sscanf_some_spec) {
  float myVarible;
  float origVarible;
  float myVarible2;
  float origVarible2;
  int myVarible3;
  int origVarible3;
  char *x = "12.3 4.5 67777777.8";
  char strMy;
  char strOrig;

  int reternMy = s21_sscanf(x, "%3f%3f%4d%c", &myVarible, &myVarible2,
                            &myVarible3, &strMy);
  int reternOrig = sscanf(x, "%3f%3f%4d%c", &origVarible, &origVarible2,
                          &origVarible3, &strOrig);

  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(myVarible, origVarible);
  ck_assert_int_eq(myVarible2, origVarible2);
  ck_assert_int_eq(myVarible3, origVarible3);
  ck_assert_int_eq(strMy, strOrig);
}
END_TEST

START_TEST(test_sscanf_some_spec1) {
  char x[] = "";
  int origVarible, myVarible;
  int reternMy = s21_sscanf(x, "%d", &myVarible);
  int reternOrig = sscanf(x, "%d", &origVarible);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_some_spec2) {
  char x[] = "\n";
  int origVarible, myVarible;
  int reternMy = s21_sscanf(x, "%d", &myVarible);
  int reternOrig = sscanf(x, "%d", &origVarible);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_some_spec3) {
  char x[] = "              ";
  int origVarible, myVarible;
  int reternMy = s21_sscanf(x, "%d", &myVarible);
  int reternOrig = sscanf(x, "%d", &origVarible);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_some_spec4) {
  char x[] = " \n\t";
  int origVarible, myVarible;
  int reternMy = s21_sscanf(x, "%d", &myVarible);
  int reternOrig = sscanf(x, "%d", &origVarible);
  ck_assert_int_eq(reternMy, reternOrig);
}
END_TEST

START_TEST(test_sscanf_for_coverage1) {
  char x[] = "0xF2f 3.0e+03 3e-03 0x3.1234";
  float origVarible, myVarible;
  float origVarible1, myVarible1;
  float origVarible2, myVarible2;
  float origVarible3, myVarible3;

  int reternMy = s21_sscanf(x, "%f%f%f%f", &myVarible, &myVarible1, &myVarible2,
                            &myVarible3);
  int reternOrig = sscanf(x, "%f%f%f%f", &origVarible, &origVarible1,
                          &origVarible2, &origVarible3);
  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_float_eq(myVarible, origVarible);
  ck_assert_float_eq(myVarible1, origVarible1);
  ck_assert_float_eq(myVarible2, origVarible2);
  ck_assert_float_eq(myVarible3, origVarible3);
}
END_TEST

START_TEST(test_sscanf_for_coverage2) {
  char x[] = "123.123e+02 123.123e+02 123.123e-02 123.123e-02";
  float origVarible, myVarible;
  float origVarible1, myVarible1;
  float origVarible2, myVarible2;
  float origVarible3, myVarible3;
  int reternMy = s21_sscanf(x, "%e%E%e%E", &myVarible, &myVarible1, &myVarible2,
                            &myVarible3);
  int reternOrig = sscanf(x, "%e%E%e%E", &origVarible, &origVarible1,
                          &origVarible2, &origVarible3);
  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_float_eq(myVarible, origVarible);
  ck_assert_float_eq(myVarible1, origVarible1);
  ck_assert_float_eq(myVarible2, origVarible2);
  ck_assert_float_eq(myVarible3, origVarible3);
}
END_TEST

START_TEST(test_sscanf_for_coverage3) {
  char x[] = "123.123e+02 123.123e+02 123.123e-02 123.123e-02";
  float origVarible, myVarible;
  float origVarible1, myVarible1;
  float origVarible2, myVarible2;
  float origVarible3, myVarible3;
  int reternMy = s21_sscanf(x, "%g%G%g%G", &myVarible, &myVarible1, &myVarible2,
                            &myVarible3);
  int reternOrig = sscanf(x, "%g%G%g%G", &origVarible, &origVarible1,
                          &origVarible2, &origVarible3);
  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_float_eq(myVarible, origVarible);
  ck_assert_float_eq(myVarible1, origVarible1);
  ck_assert_float_eq(myVarible2, origVarible2);
  ck_assert_float_eq(myVarible3, origVarible3);
}
END_TEST

START_TEST(test_sscanf_for_coverage4) {
  char x[] = "hello";
  char origVarible[20], myVarible[20];
  int NOrigVarible, NMyVarible;
  int reternMy = s21_sscanf(x, "%s %n", myVarible, &NMyVarible);
  int reternOrig = sscanf(x, "%s %n", origVarible, &NOrigVarible);
  ck_assert_int_eq(reternMy, reternOrig);
  ck_assert_int_eq(NMyVarible, NOrigVarible);
}
END_TEST

Suite *suite_sscanf(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mSSCANF\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sscanf_c1);
  tcase_add_test(tc_core, test_sscanf_c2);
  tcase_add_test(tc_core, test_sscanf_c3);
  tcase_add_test(tc_core, test_sscanf_c4);
  tcase_add_test(tc_core, test_sscanf_c5);
  tcase_add_test(tc_core, test_sscanf_d1);
  tcase_add_test(tc_core, test_sscanf_d_width1);
  tcase_add_test(tc_core, test_sscanf_d_width2);
  tcase_add_test(tc_core, test_sscanf_d_width3);
  tcase_add_test(tc_core, test_sscanf_d_width4);
  tcase_add_test(tc_core, test_sscanf_d_width5);
  tcase_add_test(tc_core, test_sscanf_hd);
  tcase_add_test(tc_core, test_sscanf_hd_width);
  tcase_add_test(tc_core, test_sscanf_hd_width2);
  tcase_add_test(tc_core, test_sscanf_hd_width3);
  tcase_add_test(tc_core, test_sscanf_ld);
  tcase_add_test(tc_core, test_sscanf_ld_width);
  tcase_add_test(tc_core, test_sscanf_ld_width2);
  tcase_add_test(tc_core, test_sscanf_ld_width3);
  tcase_add_test(tc_core, test_sscanf_lld);
  tcase_add_test(tc_core, test_sscanf_lld_width);
  tcase_add_test(tc_core, test_sscanf_lld_width2);
  tcase_add_test(tc_core, test_sscanf_lld_width3);

  tcase_add_test(tc_core, test_sscanf_i1);
  tcase_add_test(tc_core, test_sscanf_i_width1);
  tcase_add_test(tc_core, test_sscanf_i_width2);
  tcase_add_test(tc_core, test_sscanf_i_width3);
  tcase_add_test(tc_core, test_sscanf_i_width4);
  tcase_add_test(tc_core, test_sscanf_i_width5);
  tcase_add_test(tc_core, test_sscanf_i_16);
  tcase_add_test(tc_core, test_sscanf_i_8);
  tcase_add_test(tc_core, test_sscanf_i_hex1);

  tcase_add_test(tc_core, test_sscanf_f);
  tcase_add_test(tc_core, test_sscanf_f_width1);
  tcase_add_test(tc_core, test_sscanf_f_width2);
  tcase_add_test(tc_core, test_sscanf_f_width3);
  tcase_add_test(tc_core, test_sscanf_f_width4);
  tcase_add_test(tc_core, test_sscanf_f_width5);
  tcase_add_test(tc_core, test_sscanf_f_16);
  tcase_add_test(tc_core, test_sscanf_f_8);

  tcase_add_test(tc_core, test_sscanf_s1);
  tcase_add_test(tc_core, test_sscanf_s3);
  tcase_add_test(tc_core, test_sscanf_s4);
  tcase_add_test(tc_core, test_sscanf_s5);
  tcase_add_test(tc_core, test_sscanf_u1);
  tcase_add_test(tc_core, test_sscanf_u2);
  tcase_add_test(tc_core, test_sscanf_u4);
  tcase_add_test(tc_core, test_sscanf_u5);
  tcase_add_test(tc_core, test_sscanf_u6);
  tcase_add_test(tc_core, test_sscanf_u9);
  tcase_add_test(tc_core, test_sscanf_x1);
  tcase_add_test(tc_core, test_sscanf_x2);
  tcase_add_test(tc_core, test_sscanf_x3);
  tcase_add_test(tc_core, test_sscanf_x4);
  tcase_add_test(tc_core, test_sscanf_x5);
  tcase_add_test(tc_core, test_sscanf_x6);
  tcase_add_test(tc_core, test_sscanf_x8);
  tcase_add_test(tc_core, test_sscanf_X1);
  tcase_add_test(tc_core, test_sscanf_X2);
  tcase_add_test(tc_core, test_sscanf_X3);
  tcase_add_test(tc_core, test_sscanf_X4);
  tcase_add_test(tc_core, test_sscanf_X5);
  tcase_add_test(tc_core, test_sscanf_X6);
  tcase_add_test(tc_core, test_sscanf_X8);
  tcase_add_test(tc_core, test_sscanf_G1);
  tcase_add_test(tc_core, test_sscanf_G2);
  tcase_add_test(tc_core, test_sscanf_G3);
  tcase_add_test(tc_core, test_sscanf_G4);
  tcase_add_test(tc_core, test_sscanf_G6);
  tcase_add_test(tc_core, test_sscanf_g1);
  tcase_add_test(tc_core, test_sscanf_g2);
  tcase_add_test(tc_core, test_sscanf_g3);
  tcase_add_test(tc_core, test_sscanf_g4);
  tcase_add_test(tc_core, test_sscanf_g6);
  tcase_add_test(tc_core, test_sscanf_o1);
  tcase_add_test(tc_core, test_sscanf_o3);
  tcase_add_test(tc_core, test_sscanf_o4);
  tcase_add_test(tc_core, test_sscanf_o6);
  tcase_add_test(tc_core, test_sscanf_o7);
  tcase_add_test(tc_core, test_sscanf_o9);
  tcase_add_test(tc_core, test_sscanf_o10);

  tcase_add_test(tc_core, test_sscanf_some_spec);
  tcase_add_test(tc_core, test_sscanf_some_spec1);
  tcase_add_test(tc_core, test_sscanf_some_spec2);
  tcase_add_test(tc_core, test_sscanf_some_spec3);
  tcase_add_test(tc_core, test_sscanf_some_spec4);

  tcase_add_test(tc_core, test_sscanf_for_coverage1);
  tcase_add_test(tc_core, test_sscanf_for_coverage2);
  tcase_add_test(tc_core, test_sscanf_for_coverage3);
  tcase_add_test(tc_core, test_sscanf_for_coverage4);

  suite_add_tcase(s, tc_core);

  return s;
}
