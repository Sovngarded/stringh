#include "../test.h"
#include <limits.h>
#include <stdio.h>
START_TEST(test_sprintf_c1) {
  char array1[100];
  char array2[100];
  char *spec = "%c Hello %c Hello %c Hello";
  int num = 19, num2 = 32, num3 = 123;

  int retMy = s21_sprintf(array1, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_c2) {
  char array1[100];
  char array2[100];
  char *spec = "%-5c Hello %c Hello %c Hello";
  int num = -19, num2 = -32, num3 = 42;

  int retMy = s21_sprintf(array1, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_c3) {
  char array1[100];
  char array2[100];
  char *spec = "%c Hello %c Hello %c Hello %c Hello";
  int num = -19, num2 = -32;
  char symbol = 's', symbol2 = '$';

  int retMy = s21_sprintf(array1, spec, num, num2, symbol, symbol2);
  int retOrig = sprintf(array2, spec, num, num2, symbol, symbol2);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_c4) {
  char array1[200];
  char array2[200];
  char *spec = "%c Hello %c Hello %c Hello %0c Hello %c";
  int num = 95, num2 = 123, num3 = 10;
  char symbol = 'q', symbol2 = '+';

  int retMy = s21_sprintf(array1, spec, num, num2, num3, symbol, symbol2);
  int retOrig = sprintf(array2, spec, num, num2, num3, symbol, symbol2);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_c5) {
  char array1[100];
  char array2[100];
  char *spec =
      "%+10.3c Hello % 2.4c Hello %-1c Hello %#c Hello %c Hello %3.10lc";
  unsigned long int num = 70;
  int num2 = 124, num3 = 42;
  char symbol = '\n', symbol2 = '\0', a = 30;

  int retMy = s21_sprintf(array1, spec, num, num2, num3, symbol, symbol2, a);
  int retOrig = sprintf(array2, spec, num, num2, num3, symbol, symbol2, a);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d1) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "hello %d hello";
  int num = -55;
  ck_assert_int_eq(sprintf(array1, spec, num), s21_sprintf(array2, spec, num));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d2) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%d string %d string %d";
  int num = 458;
  int num2 = 0;
  int num3 = 58694;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d3) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%-4d string %-2d string %-6d string";
  int num = 111;
  int num2 = -222;
  int num3 = 33;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d4) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%+d string %+d string % d";
  int num = 5;
  int num2 = -3;
  int num3 = 3435;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d5) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%08d string %07d string %06d";
  int num = 356;
  int num2 = -43;
  int num3 = 5654;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d6) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%0d string %0d string %0d";
  int num = -67;
  int num2 = -43;
  int num3 = 5654;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d7) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%4d string %3d string %7d";
  int num = 4545676;
  int num2 = 234332;
  int num3 = -596;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d8) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%.3d string %.2d string %.6d";
  int num = 43454;
  int num2 = 2332;
  int num3 = 5964;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d9) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%hd string %hd string %hd";
  short int num = 434;
  short int num2 = 23;
  short int num3 = -594;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_d10) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%ld string %ld string %ld";
  long int num = 4344234525;
  long int num2 = 23454363;
  long int num3 = -594656544;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

// START_TEST(test_sprintf_i1) {
//   char array1[100] = "";
//   char array2[100] = "";
//   char *spec = "%i 234 %i hello %i";
//   int num = 5767;
//   int num2 = -45;
//   int num3 = 4499;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
//                    s21_sprintf(array2, spec, num, num2, num3));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

// START_TEST(test_sprintf_i2) {
//   char array1[200] = "";
//   char array2[200] = "";
//   char *spec = "%-1i weer %-4i wer %-7i wrwer %-2i";
//   int num = 4875;
//   int num2 = -7;
//   int num3 = 3499;
//   int num4 = -2529;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2, num3, num4),
//                    s21_sprintf(array2, spec, num, num2, num3, num4));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

// START_TEST(test_sprintf_i3) {
//   char array1[200] = "";
//   char array2[200] = "";
//   char *spec = "%+i suite %+6i suite %+3.6i school %+i";
//   int num = 4875;
//   int num2 = -7;
//   int num3 = 3499;
//   int num4 = -2529;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2, num3, num4),
//                    s21_sprintf(array2, spec, num, num2, num3, num4));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

// START_TEST(test_sprintf_i4) {
//   char array1[100] = "";
//   char array2[100] = "";
//   char *spec = "%4i hello %5i hello %12i";
//   int num = -436;
//   int num2 = -3556547;
//   int num3 = 48534;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
//                    s21_sprintf(array2, spec, num, num2, num3));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

// START_TEST(test_sprintf_i5) {
//   char array1[200] = "";
//   char array2[200] = "";
//   char *spec = "%04i school %02i %08i wer %010i";
//   int num = -3654;
//   int num2 = 74512;
//   int num3 = -99;
//   int val4 = 3465;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2, num3, val4),
//                    s21_sprintf(array2, spec, num, num2, num3, val4));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

// START_TEST(test_sprintf_i6) {
//   char array1[200] = "";
//   char array2[200] = "";
//   char *spec = "%.4i school %.2i %08i wer %.10i";
//   int num = -3654;
//   int num2 = 74512;
//   int num3 = -99;
//   int num4 = 3587;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2, num3, num4),
//                    s21_sprintf(array2, spec, num, num2, num3, num4));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

// START_TEST(test_sprintf_i7) {
//   char array1[200] = "";
//   char array2[200] = "";
//   char *spec = "%hi school %hi";
//   short int num = -364;
//   short int num2 = 51;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2),
//                    s21_sprintf(array2, spec, num, num2));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

// START_TEST(test_sprintf_i8) {
//   char array1[200] = "";
//   char array2[200] = "";
//   char *spec = "%li school %li";
//   long int num = -435364;
//   long int num2 = 34551;
//   ck_assert_int_eq(sprintf(array1, spec, num, num2),
//                    s21_sprintf(array2, spec, num, num2));
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

START_TEST(test_sprintf_e) {
  char array1[500];
  char array2[500];
  char *spec = "One %e Two %E";
  double num = NAN;

  int retMy = s21_sprintf(array1, spec, num, num);
  int retOrig = sprintf(array2, spec, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_e2) {
  char array1[500];
  char array2[500];
  char *spec = "%#.e Hello %#e \nHello %#0.0e Hello % e!";
  double num = -19242145242., num2 = 256457547532.;

  int retMy = s21_sprintf(array1, spec, num, num2, num, num);
  int retOrig = sprintf(array2, spec, num, num2, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_e3) {
  char array1[500];
  char array2[500];
  char *spec = "%#.e Hello %#e \nHello %#0.0e Hello %Le";
  double num = -19242145242., num2 = 256457547532.;
  long double num3 = 3213123.;

  int retMy = s21_sprintf(array1, spec, num, num2, num, num3);
  int retOrig = sprintf(array2, spec, num, num2, num, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_e4) {
  char array1[500];
  char array2[500];
  char *spec = "%#+20.e Hello %#e Hello %#44.2e Hello %-Le";
  double num = -19242145242., num2 = 25645754.7532;
  long double num3 = 3231321312.321;

  int retMy = s21_sprintf(array1, spec, num, num2, num, num3);
  int retOrig = sprintf(array2, spec, num, num2, num, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_e5) {
  char array1[500];
  char array2[500];
  char *spec = "%#0.e Hello %.15e Hello";
  double num = -192.;
  int retMy = s21_sprintf(array1, spec, num, num);
  int retOrig = sprintf(array2, spec, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_e6) {
  char array1[500];
  char array2[500];
  char *spec = "% e %e";
  double num = 0.99;
  double num2 = 0;
  int retMy = s21_sprintf(array1, spec, num, num2);
  int retOrig = sprintf(array2, spec, num, num2);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E1) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%E school %E";
  double num = -1;
  double num2 = 30;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E2) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%-3E school %-6E";
  double num = -24;
  double num2 = 435;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E3) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%+E hello %+E";
  double num = -24;
  double num2 = 435;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E4) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%+E hello %+E";
  double num = -24;
  double num2 = 435;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E5) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "% E hello % E hay % E";
  double num = -46;
  double num2 = 357;
  double num3 = 3532;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E6) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%#E hello %#E world %#E";
  double num = 435;
  double num2 = -32524;
  double num3 = -2735324;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E7) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%.2E hello %.1E world %.4E";
  double num = 435;
  double num2 = -32524;
  double num3 = -2735324;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_E8) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%LE hello %LE world %LE";
  long double num = 363;
  long double num2 = 4634968;
  long double num3 = -2321;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_f) {
  char array1[500];
  char array2[500];
  char *spec = "%f Hello %3f Hello %.f Hello %3.4f";
  double num = -1924.21452428556;
  int retMy = s21_sprintf(array1, spec, num, num, num, num);
  int retOrig = sprintf(array2, spec, num, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_f2) {
  char array1[500];
  char array2[500];
  char *spec = "% f Hello %3Lf Hello %.Lf Hello %+-#.f";
  long double num = -1924.214524556;
  double num2 = -1924.214524556;
  int retMy = s21_sprintf(array1, spec, num2, num, num, num2);
  int retOrig = sprintf(array2, spec, num2, num, num, num2);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_f3) {
  char array1[500];
  char array2[500];
  char *spec = "%f Hello %21.10f\n Hello %-21.10Lf Hello %+-#.f";
  double num = -1.214524556;
  long double numL = -132924.242342324556;
  int retMy = s21_sprintf(array1, spec, num, num, numL, num);
  int retOrig = sprintf(array2, spec, num, num, numL, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_f4) {
  char array1[500];
  char array2[500];
  char *spec = "%+-Lf Hello %21.10f\n Hello %-21.10Lf Hello %+-#.f";
  long double numL = -14363463.3253252356;
  double num = 363412.504853945;
  int retMy = s21_sprintf(array1, spec, numL, num, numL, num);
  int retOrig = sprintf(array2, spec, numL, num, numL, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

// START_TEST(test_sprintf_f5) {
//   char array1[500];
//   char array2[500];
//   char *spec = "%+ 36.17LfHello % +40.15Lf";
//   long double num = -0000.0000000000;
//   int retMy = s21_sprintf(array1, spec, num, num, num, num);
//   int retOrig = sprintf(array2, spec, num, num, num, num);

//   ck_assert_int_eq(retMy, retOrig);
//   ck_assert_pstr_eq(array1, array2);
// }
// END_TEST

START_TEST(test_sprintf_g) {
  char array1[500];
  char array2[500];
  char *spec = "%11g Hello %3g Hello %g Hello %4g";
  double num = -1924.21452428556;
  int retMy = s21_sprintf(array1, spec, num, num, num, num);
  int retOrig = sprintf(array2, spec, num, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_g2) {
  char array1[500];
  char array2[500];
  char *spec = "Hello %3g";
  double num = 200.214524556;
  int retMy = s21_sprintf(array1, spec, num, num, num, num);
  int retOrig = sprintf(array2, spec, num, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_g3) {
  char array1[500];
  char array2[500];
  char *spec = "%+g";
  double num = -1924.214524556;
  int retMy = s21_sprintf(array1, spec, num, num, num, num);
  int retOrig = sprintf(array2, spec, num, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_g4) {
  char array1[500];
  char array2[500];
  char *spec = "%-g";
  double num = -143634634636346376769697434.3253252356;
  int retMy = s21_sprintf(array1, spec, num, num, num, num);
  int retOrig = sprintf(array2, spec, num, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_g5) {
  char array1[500];
  char array2[500];
  char *spec = "%4g";
  double num = 5.6;
  int retMy = s21_sprintf(array1, spec, num, num, num);
  int retOrig = sprintf(array2, spec, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G1) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%G school %G";
  float num = -36.5;
  float num2 = 51.3;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G2) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%4G";
  double num = 5.6;
  ck_assert_int_eq(sprintf(array1, spec, num), s21_sprintf(array2, spec, num));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G3) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%.4G school %.5G twenty one %.3G";
  float num = 5.63;
  float num2 = -547.8;
  float num3 = -3.954;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G4) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%LG school %LG twenty one %LG";
  long double num = 4.634;
  long double num2 = -5547.58;
  long double num3 = -23.94;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G5) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%-4G school %-8G twenty one %-3G";
  double num = 4.56;
  double num2 = -2.4;
  double num3 = 323.4;
  ck_assert_int_eq(sprintf(array1, spec, num, num2, num3),
                   s21_sprintf(array2, spec, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G6) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%+G school";
  float num = -32.5;
  ck_assert_int_eq(sprintf(array1, spec, num), s21_sprintf(array2, spec, num));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G7) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "% G";
  float num = -5.785;
  ck_assert_int_eq(sprintf(array1, spec, num), s21_sprintf(array2, spec, num));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G8) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "%G";
  float num = 45.6;
  ck_assert_int_eq(sprintf(array1, spec, num), s21_sprintf(array2, spec, num));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_G9) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%08G";
  float num = -34.5;
  ck_assert_int_eq(sprintf(array1, spec, num), s21_sprintf(array2, spec, num));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_n1) {
  char array1[100] = "";
  char array2[100] = "";
  char *spec = "suite er%n suite";
  int num1 = 0;
  int num2 = 0;
  ck_assert_int_eq(sprintf(array1, spec, &num1),
                   s21_sprintf(array2, spec, &num2));
  ck_assert_pstr_eq(array1, array2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_sprintf_o_n1) {
  char arrayMy[100] = "";
  char arrayOrig[100] = "";
  char *spec = "Hello %o Wor%nld %o%n";
  int num = 021, num2 = 012;
  int numMyN = 0, numMyN2 = 0, numOrigN = 0, numOrigN2 = 0;

  int retMy = s21_sprintf(arrayMy, spec, num, &numMyN, num2, &numMyN2);
  int retOrig = sprintf(arrayOrig, spec, num, &numOrigN, num2, &numOrigN2);

  ck_assert_pstr_eq(arrayMy, arrayOrig);
  ck_assert_int_eq(retMy, retOrig);
  ck_assert_int_eq(numMyN, numOrigN);
  ck_assert_int_eq(numMyN2, numOrigN2);
}
END_TEST

START_TEST(test_sprintf_o1) {
  char arrayMy[100] = "";
  char arrayOrig[100] = "";
  char *spec = "Test %o Test";
  int num = 012;

  int retMy = s21_sprintf(arrayMy, spec, num);
  int retOrig = sprintf(arrayOrig, spec, num);

  ck_assert_pstr_eq(arrayMy, arrayOrig);
  ck_assert_int_eq(retMy, retOrig);
}
END_TEST

START_TEST(test_sprintf_o2) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "Hello %o %o world %o";
  int num = 01, num2 = 012, num3 = 0123;
  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);
  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o3) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%oHello %o world %o";
  int num = 2452, num2 = 123, num3 = 42;
  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);
  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_lo_ho) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "Hello%lo World %lo Hel %ho lol %ho";
  long int num = -1234567891234;
  unsigned long int num2 = 123432521412;
  short int num3 = -12345;
  unsigned short num4 = 412;
  int retMy = s21_sprintf(array, spec, num, num2, num3, num4);
  int retOrig = sprintf(array2, spec, num, num2, num3, num4);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_width) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%2oHello %4o world %9o";
  int num = 1252, num2 = 04124, num3 = 132;

  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_width2) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%2.3oHello %.4o world %9.o";
  int num = 1252, num2 = 04124, num3 = 132;

  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_minus) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%-2.3oHello %-.4o world %-9.o";
  int num = 1252, num2 = 04124, num3 = 132;

  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_zero) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%0.oHello %0o world %0.2o";
  int num = -1252, num2 = 04124, num3 = 132;

  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_plus) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%+2.3oHello %+.4o world %+9.o";
  int num = 1252, num2 = 04124, num3 = 132;

  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_combo) {
  char array[300] = "";
  char array2[300] = "";
  char *spec = "%o Hello %3.o  %7oWorld %5.7o Hello %#o %-o %+o %.o % .o";
  int num = 0;
  int retMy =
      s21_sprintf(array, spec, num, num, num, num, num, num, num, num, num);
  int retOrig =
      sprintf(array2, spec, num, num, num, num, num, num, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_space) {
  char array[300] = "";
  char array2[300] = "";
  char *spec = "% o Hello % 3.o  %7oWorld % 5.7o Hello % #o % -o %+o % .o % .o";
  int num = 0;
  int retMy =
      s21_sprintf(array, spec, num, num, num, num, num, num, num, num, num);
  int retOrig =
      sprintf(array2, spec, num, num, num, num, num, num, num, num, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_hash) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%#oHello %#.4o world %#9.o";
  int num = 1252, num2 = 04124, num3 = 132;

  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_star) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%*oHello %.*o world %-*o";
  int num = 1252, num2 = 04124, num3 = 132;
  int star1 = 1, star2 = 3, star3 = 4;

  int retMy = s21_sprintf(array, spec, star1, num, star2, num2, star3, num3);
  int retOrig = sprintf(array2, spec, star1, num, star2, num2, star3, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_space2) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "%- oHello %- 14o world %- o";
  int num = -1252, num2 = 04124, num3 = 132;

  int retMy = s21_sprintf(array, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_lmax) {
  char array[200] = "";
  char array2[200] = "";
  char *spec = "Hello %lo world";
  long int num = ULONG_MAX;

  int retMy = s21_sprintf(array, spec, num);
  int retOrig = sprintf(array2, spec, num);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_o_proc) {
  char array[100] = "";
  char array2[100] = "";
  char *spec = "Hello %o World%%%% %o";
  int num = 026, num2 = 014;

  int retMy = s21_sprintf(array, spec, num, num2);
  int retOrig = sprintf(array2, spec, num, num2);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array, array2);
}
END_TEST

START_TEST(test_sprintf_s1) {
  char array1[100];
  char array2[100];
  char *spec = "%s Hello %s Hello %s Hello";
  char *num = "GIVE", *num2 = "ME", *num3 = "MONEY";

  int retMy = s21_sprintf(array1, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_s2) {
  char array1[100];
  char array2[100];
  char *spec = "%-3s Hello %-8s Hello %-2s Hello";
  char *num = "GIVE", *num2 = "ME", *num3 = "MONEY";

  int retMy = s21_sprintf(array1, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_s3) {
  char array1[100];
  char array2[100];
  char *spec = "%3s Hello %8s Hello %2s Hello";
  char *num = "123", *num2 = NULL, *num3 = "MONEY";

  int retMy = s21_sprintf(array1, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_s4) {
  char array1[100];
  char array2[100];
  char *spec = "%3s Hello %8s Hello %2s Hello";
  char *num = "GIVE", *num2 = "ME", *num3 = "MONEY";

  int retMy = s21_sprintf(array1, spec, num, num2, num3);
  int retOrig = sprintf(array2, spec, num, num2, num3);

  ck_assert_int_eq(retMy, retOrig);
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u1) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%u school %u";
  int num = 33764523;
  int num2 = 253334;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u2) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%-6u hi %-4u friend %-2u";
  int num = 325546;
  int num2 = 34224;
  int num3 = 252345.6;
  ck_assert_int_eq(sprintf(array1, str3, num, num2, num3),
                   s21_sprintf(array2, str3, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u3) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%u hi %u friend %u";
  int num = 325;
  int num2 = 899.9;
  int num3 = -23;
  ck_assert_int_eq(sprintf(array1, str3, num, num2, num3),
                   s21_sprintf(array2, str3, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u4) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%4u hi %5u friend %3.2u";
  int num = 325;
  int num2 = 899.9;
  int num3 = 23;
  ck_assert_int_eq(sprintf(array1, str3, num, num2, num3),
                   s21_sprintf(array2, str3, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u5) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%08u hi %05u friend %02u";
  int num = 325;
  int num2 = 899.9;
  int num3 = 23;
  ck_assert_int_eq(sprintf(array1, str3, num, num2, num3),
                   s21_sprintf(array2, str3, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u6) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%.8u hello %.5u friend %.2u";
  int num = 345;
  int num2 = 0;
  int num3 = 352.777;
  ck_assert_int_eq(sprintf(array1, str3, num, num2, num3),
                   s21_sprintf(array2, str3, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u7) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%hu hi %hu friend %hu";
  short int num = 325;
  short int num2 = 899.9;
  short int num3 = 23;
  ck_assert_int_eq(sprintf(array1, str3, num, num2, num3),
                   s21_sprintf(array2, str3, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_u8) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%hu bye %hu friend %hu";
  long int num = 47547456.6;
  long int num2 = 34557654;
  long int num3 = 243546.53;
  ck_assert_int_eq(sprintf(array1, str3, num, num2, num3),
                   s21_sprintf(array2, str3, num, num2, num3));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x1) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%x school %x";
  int num = -364;
  int num2 = 51;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x2) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%-2x school %4x";
  int num = -34;
  int num2 = 5;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x3) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%+x school %+x";
  int num = -364;
  int num2 = 51;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x4) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "% x school % x";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x5) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%08x school %03x";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x6) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%08x school %03x";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x7) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%08x school %03x";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x8) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%#x school %#x";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x9) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%4x school %6x";
  int num = 323563;
  int num2 = -23;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x10) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%hx school %hx";
  short int num = -35;
  short int num2 = 254;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x11) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%lx school %lx";
  long int num = -33764523;
  long int num2 = 253334;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_x12) {
  char array1[200] = "";
  char array2[200] = "";
  char *spec = "%.3x school %.4x";
  int num = 3495;
  int num2 = 245454;
  ck_assert_int_eq(sprintf(array1, spec, num, num2),
                   s21_sprintf(array2, spec, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X1) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%X school %X";
  int num = -364;
  int num2 = 51;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X2) {
  char array1[300] = "";
  char array2[300] = "";
  char *str3 = "%-5X school %4X";
  int num = -364;
  int num2 = 51;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X3) {
  char array1[50] = "";
  char array2[50] = "";
  char *str3 = "%+X school %+X";
  int num = -364;
  int num2 = 51;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X4) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "% X school % X";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X5) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%08X school %03X";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X6) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%08X school %03X";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X7) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%08X school %03X";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X8) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%#X school %#X";
  int num = 435973;
  int num2 = -514;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X9) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%4X school %6X";
  int num = 323563;
  int num2 = -23;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X10) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%.3X school %.4X";
  int num = 3495;
  int num2 = 245454;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X11) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%hX school %hX";
  short int num = -35;
  short int num2 = 254;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_X12) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%lX school %lX";
  long int num = -33764523;
  long int num2 = 253334;
  ck_assert_int_eq(sprintf(array1, str3, num, num2),
                   s21_sprintf(array2, str3, num, num2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_p1) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%p school %p";
  char *pointer1 = "etw3";
  char *pointer2 = "3456et";
  ck_assert_int_eq(sprintf(array1, str3, pointer1, pointer2),
                   s21_sprintf(array2, str3, pointer1, pointer2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_p2) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%-3p my school21 %-7p";
  char *pointer1 = "ere";
  char *pointer2 = "yuoiyu";
  ck_assert_int_eq(sprintf(array1, str3, pointer1, pointer2),
                   s21_sprintf(array2, str3, pointer1, pointer2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

START_TEST(test_sprintf_p3) {
  char array1[200] = "";
  char array2[200] = "";
  char *str3 = "%5p my school21 %2p";
  char *pointer1 = "ere";
  char *pointer2 = "yuoiyu";
  ck_assert_int_eq(sprintf(array1, str3, pointer1, pointer2),
                   s21_sprintf(array2, str3, pointer1, pointer2));
  ck_assert_pstr_eq(array1, array2);
}
END_TEST

Suite *suite_sprintf(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[102mSPRINTF\033[0m");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_sprintf_c1);
  tcase_add_test(tc_core, test_sprintf_c2);
  tcase_add_test(tc_core, test_sprintf_c3);
  tcase_add_test(tc_core, test_sprintf_c4);
  tcase_add_test(tc_core, test_sprintf_c5);

  tcase_add_test(tc_core, test_sprintf_d1);
  tcase_add_test(tc_core, test_sprintf_d2);
  tcase_add_test(tc_core, test_sprintf_d3);
  tcase_add_test(tc_core, test_sprintf_d4);
  tcase_add_test(tc_core, test_sprintf_d5);
  tcase_add_test(tc_core, test_sprintf_d6);
  tcase_add_test(tc_core, test_sprintf_d7);
  tcase_add_test(tc_core, test_sprintf_d8);
  tcase_add_test(tc_core, test_sprintf_d9);
  tcase_add_test(tc_core, test_sprintf_d10);

  // tcase_add_test(tc_core, test_sprintf_i1);
  // tcase_add_test(tc_core, test_sprintf_i2);
  // tcase_add_test(tc_core, test_sprintf_i3);
  // tcase_add_test(tc_core, test_sprintf_i4);
  // tcase_add_test(tc_core, test_sprintf_i5);
  // tcase_add_test(tc_core, test_sprintf_i6);
  // tcase_add_test(tc_core, test_sprintf_i7);
  // tcase_add_test(tc_core, test_sprintf_i8);

  tcase_add_test(tc_core, test_sprintf_e);
  tcase_add_test(tc_core, test_sprintf_e2);
  tcase_add_test(tc_core, test_sprintf_e3);
  tcase_add_test(tc_core, test_sprintf_e4);
  tcase_add_test(tc_core, test_sprintf_e5);
  tcase_add_test(tc_core, test_sprintf_e6);

  tcase_add_test(tc_core, test_sprintf_E1);
  tcase_add_test(tc_core, test_sprintf_E2);
  tcase_add_test(tc_core, test_sprintf_E3);
  tcase_add_test(tc_core, test_sprintf_E4);
  tcase_add_test(tc_core, test_sprintf_E5);
  tcase_add_test(tc_core, test_sprintf_E6);
  tcase_add_test(tc_core, test_sprintf_E7);
  tcase_add_test(tc_core, test_sprintf_E8);

  tcase_add_test(tc_core, test_sprintf_f);
  tcase_add_test(tc_core, test_sprintf_f2);
  tcase_add_test(tc_core, test_sprintf_f3);
  tcase_add_test(tc_core, test_sprintf_f4);
  // tcase_add_test(tc_core, test_sprintf_f5);

  tcase_add_test(tc_core, test_sprintf_g);
  tcase_add_test(tc_core, test_sprintf_g2);
  tcase_add_test(tc_core, test_sprintf_g3);
  tcase_add_test(tc_core, test_sprintf_g4);
  tcase_add_test(tc_core, test_sprintf_g5);

  tcase_add_test(tc_core, test_sprintf_G1);
  tcase_add_test(tc_core, test_sprintf_G2);
  tcase_add_test(tc_core, test_sprintf_G3);
  tcase_add_test(tc_core, test_sprintf_G4);
  tcase_add_test(tc_core, test_sprintf_G5);
  tcase_add_test(tc_core, test_sprintf_G6);
  tcase_add_test(tc_core, test_sprintf_G7);
  tcase_add_test(tc_core, test_sprintf_G8);
  tcase_add_test(tc_core, test_sprintf_G9);

  tcase_add_test(tc_core, test_sprintf_o_n1);
  tcase_add_test(tc_core, test_sprintf_o1);
  tcase_add_test(tc_core, test_sprintf_o2);
  tcase_add_test(tc_core, test_sprintf_o3);
  tcase_add_test(tc_core, test_sprintf_lo_ho);
  tcase_add_test(tc_core, test_sprintf_o_width);
  tcase_add_test(tc_core, test_sprintf_o_width2);
  tcase_add_test(tc_core, test_sprintf_o_minus);
  tcase_add_test(tc_core, test_sprintf_o_zero);
  tcase_add_test(tc_core, test_sprintf_o_plus);
  tcase_add_test(tc_core, test_sprintf_o_combo);
  tcase_add_test(tc_core, test_sprintf_o_space);
  tcase_add_test(tc_core, test_sprintf_o_hash);
  tcase_add_test(tc_core, test_sprintf_o_star);
  tcase_add_test(tc_core, test_sprintf_o_space2);
  tcase_add_test(tc_core, test_sprintf_o_lmax);
  tcase_add_test(tc_core, test_sprintf_o_proc);

  tcase_add_test(tc_core, test_sprintf_s1);
  tcase_add_test(tc_core, test_sprintf_s2);
  tcase_add_test(tc_core, test_sprintf_s3);
  tcase_add_test(tc_core, test_sprintf_s4);

  tcase_add_test(tc_core, test_sprintf_u1);
  tcase_add_test(tc_core, test_sprintf_u2);
  tcase_add_test(tc_core, test_sprintf_u3);
  tcase_add_test(tc_core, test_sprintf_u4);
  tcase_add_test(tc_core, test_sprintf_u5);
  tcase_add_test(tc_core, test_sprintf_u6);
  tcase_add_test(tc_core, test_sprintf_u7);
  tcase_add_test(tc_core, test_sprintf_u8);

  tcase_add_test(tc_core, test_sprintf_n1);
  tcase_add_test(tc_core, test_sprintf_x1);
  tcase_add_test(tc_core, test_sprintf_x2);
  tcase_add_test(tc_core, test_sprintf_x3);
  tcase_add_test(tc_core, test_sprintf_x4);
  tcase_add_test(tc_core, test_sprintf_x5);
  tcase_add_test(tc_core, test_sprintf_x6);
  tcase_add_test(tc_core, test_sprintf_x7);
  tcase_add_test(tc_core, test_sprintf_x8);
  tcase_add_test(tc_core, test_sprintf_x9);
  tcase_add_test(tc_core, test_sprintf_x10);
  tcase_add_test(tc_core, test_sprintf_x11);
  tcase_add_test(tc_core, test_sprintf_x12);

  tcase_add_test(tc_core, test_sprintf_X1);
  tcase_add_test(tc_core, test_sprintf_X2);
  tcase_add_test(tc_core, test_sprintf_X3);
  tcase_add_test(tc_core, test_sprintf_X4);
  tcase_add_test(tc_core, test_sprintf_X5);
  tcase_add_test(tc_core, test_sprintf_X6);
  tcase_add_test(tc_core, test_sprintf_X7);
  tcase_add_test(tc_core, test_sprintf_X8);
  tcase_add_test(tc_core, test_sprintf_X9);
  tcase_add_test(tc_core, test_sprintf_X10);
  tcase_add_test(tc_core, test_sprintf_X11);
  tcase_add_test(tc_core, test_sprintf_X12);

  tcase_add_test(tc_core, test_sprintf_p1);
  tcase_add_test(tc_core, test_sprintf_p2);
  tcase_add_test(tc_core, test_sprintf_p3);

  suite_add_tcase(s, tc_core);

  return s;
}
