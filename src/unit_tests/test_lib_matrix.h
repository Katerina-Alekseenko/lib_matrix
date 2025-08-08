#ifndef TEST
#define TEST

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../lib_matrix.h"

#define FAILURE 0
#define SUCCESS 1

enum {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALC_ERROR = 2,
};

Suite *suite_lib_create_matrix(void);
Suite *suite_lib_eq_matrix(void);
Suite *suite_lib_sum_matrix(void);
Suite *suite_lib_sub_matrix(void);
Suite *suite_lib_mult_number(void);
Suite *suite_lib_mult_matrix(void);
Suite *suite_lib_transpose(void);
Suite *suite_lib_calc_complements(void);
Suite *suite_lib_determinant(void);
Suite *suite_lib_inverse_matrix(void);

void run_tests(void);
void run_testcase(Suite *testcase);

double get_rand(double min, double max);

#endif