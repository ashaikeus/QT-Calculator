#include <check.h>

#include "s21_calc.h"

/**
 * @file test.c
 * @brief Unit tests.
 */

START_TEST(t1) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "2 + 3.5 + 6");
  double answer = 11.5;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t2) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "2 ^ 3 + 6");
  double answer = 14;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t3) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "2 ^ 3");
  double answer = 8;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t4) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "2-4");
  double answer = -2;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t5) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "(sin(4))");
  double answer = -0.7568024953;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t6) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "(sin(4)) - (2 * 9)");
  double answer = -18.7568024953;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t7) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "6 * 7 / 8 + ( 3 - 1 ^ 2 ) + (4 * 5)");
  double answer = 27.25;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t8) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "21 * 12 / 4 + ( 47 + 2 ^ 3 )");
  double answer = 118;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t9) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "21 * 12 / 2 + ( 47 + 2 ^ 3 ) + (6 * 4)");
  double answer = 205;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t10) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "21 * 12 / 2 + ( 47 + 2 ^ 3 ) + (sin(4) - 2* 9)");
  double answer = 162.243197505;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t11) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "21 * 12 / 2 + ( 47 + 2 ^ 3 ) + (sin(4))");
  double answer = 180.243197505;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t12) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "~4 + 95");
  double answer = 91;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t13) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "4 - ~95");
  double answer = 99;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t14) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "-4");
  double answer = -4;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t15) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(
      string,
      "-sqrt(+4 + asin(0.2) / cos(3) * (ln(2) + log(9) ^ tan(0))) + atan(0)");
  double answer = -1.911969;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_double_eq_tol(answer, output, S21_EPS * 10);
  free(string);
}
END_TEST

START_TEST(t16) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "45 + -1 + acos(0)");
  double answer =
      45.570796326794896619231321691639751442098584699687552910487472296;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t17) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "-6-7");
  double answer = -13;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t18) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "-8");
  double answer = -8;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t19) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "-8--7+-19");
  double answer = -20;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t20) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "-8++7+-19");
  double answer = -20;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t21) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "++8--7+-19");
  double answer = -4;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t22) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "-8*9");
  double answer = -72;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t23) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "9*-8");
  double answer = -72;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t24) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "9*(-8)");
  double answer = -72;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t25) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "2^3");
  double answer = 8;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t26) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "2^2^3");
  double answer = 64;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t27) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "2^(2^3)");
  double answer = 256;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(t28) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "(2^2)^3");
  double answer = 64;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 0));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(x1) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "x");
  double answer = 29;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 29));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(x2) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "-x");
  double answer = -29;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 29));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(x3) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "x^2 + 5");
  double answer = 21;

  double output = 0.0;
  ck_assert_int_eq(0, main_function(string, &output, 4));
  ck_assert_ldouble_eq_tol(answer, output, S21_EPS);
  free(string);
}
END_TEST

START_TEST(e1) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "7+3.......5");

  double output = 0.0;
  ck_assert_int_eq(3, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e2) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "(7+4");

  double output = 0.0;
  ck_assert_int_eq(1, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e3) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, ")7+4(");

  double output = 0.0;
  ck_assert_int_eq(2, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e4) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "7*");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e5) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "+");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e6) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "+/-");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e7) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "6+/~-");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e8) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "6-");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e9) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "6(-)");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e10) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "xsin(1)");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e11) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "x8sin(1)");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(e12) {
  char *string = {0};
  string = (char *)malloc(MAX_NUM * sizeof(char));

  strcpy(string, "*7");

  double output = 0.0;
  ck_assert_int_eq(4, main_function(string, &output, 0));
  free(string);
}
END_TEST

START_TEST(c1) {
  double amount = 100000;
  double months = 12;
  double interest = 2.9;
  double differentiated = 0;

  double answer = 8464.82;

  double output = get_total(amount, months, interest, differentiated) / months;
  ck_assert_ldouble_eq_tol(answer, output, 1);
}
END_TEST

START_TEST(c2) {
  double amount = 100000;
  double months = 48;
  double interest = 2.9;
  double differentiated = 0;

  double answer = 2209.02;

  double output = get_total(amount, months, interest, differentiated) / months;
  ck_assert_ldouble_eq_tol(answer, output, 1);
}
END_TEST

START_TEST(c3) {
  double amount = 20000;
  double months = 36;
  double interest = 12;
  double differentiated = 0;

  double answer = 664;

  double output = get_total(amount, months, interest, differentiated) / months;
  ck_assert_ldouble_eq_tol(answer, output, 1);
}
END_TEST

START_TEST(c4) {
  double amount = 300000;
  double months = 6;
  double interest = 20;
  double differentiated = 1;

  double answer = 317671.25;

  double output = get_total(amount, months, interest, differentiated);
  ck_assert_ldouble_eq_tol(answer, output, 1200);
}
END_TEST

Suite *test_suite(void) {
  Suite *s;

  TCase *tc_normal;
  TCase *tc_x;
  TCase *tc_edgecases;
  TCase *tc_credit;

  s = suite_create("SmartCalc");

  tc_normal = tcase_create("normal expressions:\n");
  tcase_add_test(tc_normal, t1);
  tcase_add_test(tc_normal, t2);
  tcase_add_test(tc_normal, t3);
  tcase_add_test(tc_normal, t4);
  tcase_add_test(tc_normal, t5);
  tcase_add_test(tc_normal, t6);
  tcase_add_test(tc_normal, t7);
  tcase_add_test(tc_normal, t8);
  tcase_add_test(tc_normal, t9);
  tcase_add_test(tc_normal, t10);
  tcase_add_test(tc_normal, t11);
  tcase_add_test(tc_normal, t12);
  tcase_add_test(tc_normal, t13);
  tcase_add_test(tc_normal, t14);
  tcase_add_test(tc_normal, t15);
  tcase_add_test(tc_normal, t16);
  tcase_add_test(tc_normal, t17);
  tcase_add_test(tc_normal, t18);
  tcase_add_test(tc_normal, t19);
  tcase_add_test(tc_normal, t20);
  tcase_add_test(tc_normal, t21);
  tcase_add_test(tc_normal, t22);
  tcase_add_test(tc_normal, t23);
  tcase_add_test(tc_normal, t24);
  tcase_add_test(tc_normal, t25);
  tcase_add_test(tc_normal, t26);
  tcase_add_test(tc_normal, t27);
  tcase_add_test(tc_normal, t28);
  suite_add_tcase(s, tc_normal);

  tc_x = tcase_create("x:\n");
  tcase_add_test(tc_x, x1);
  tcase_add_test(tc_x, x2);
  tcase_add_test(tc_x, x3);
  suite_add_tcase(s, tc_x);

  tc_edgecases = tcase_create("edge cases:\n");
  tcase_add_test(tc_edgecases, e1);   // too many dots
  tcase_add_test(tc_edgecases, e2);   // bracket number doesn't match
  tcase_add_test(tc_edgecases, e3);   // wrong bracket sequence
  tcase_add_test(tc_edgecases, e4);   // 7*
  tcase_add_test(tc_edgecases, e5);   // +
  tcase_add_test(tc_edgecases, e6);   // +/-
  tcase_add_test(tc_edgecases, e7);   // 6+/-
  tcase_add_test(tc_edgecases, e8);   // 6-
  tcase_add_test(tc_edgecases, e9);   // 6(-)
  tcase_add_test(tc_edgecases, e10);  // xsin(1)
  tcase_add_test(tc_edgecases, e11);  // x8sin(1)
  tcase_add_test(tc_edgecases, e12);  //
  suite_add_tcase(s, tc_edgecases);

  tc_credit = tcase_create("credit calculator:\n");
  tcase_add_test(tc_credit, c1);
  tcase_add_test(tc_credit, c2);
  tcase_add_test(tc_credit, c3);
  tcase_add_test(tc_credit, c4);
  suite_add_tcase(s, tc_credit);

  return s;
}

int main() {
  int success = 0;
  Suite *s;
  SRunner *runner;
  s = test_suite();
  runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  success = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (success == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
