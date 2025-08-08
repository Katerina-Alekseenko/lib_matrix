#include "test_lib_matrix.h"

START_TEST(mult_number) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t mtx = {0};
  lib_create_matrix(rows, cols, &mtx);
  matrix_t mtx_check = {0};
  lib_create_matrix(rows, cols, &mtx_check);
  double number = get_rand(-10e5, 10e5);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, 10000);
      mtx_check.matrix[i][j] = mtx.matrix[i][j] * number;
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(lib_mult_number(&mtx, number, &res), OK);
  ck_assert_int_eq(lib_eq_matrix(&mtx_check, &res), SUCCESS);
  lib_remove_matrix(&mtx);
  lib_remove_matrix(&res);
  lib_remove_matrix(&mtx_check);
}
END_TEST

Suite *suite_lib_mult_matrix(void) {
  Suite *s = suite_create("suite_lib_mult_number");
  TCase *tc = tcase_create("lib_mult_number");

  tcase_add_loop_test(tc, mult_number, 0, 100);

  suite_add_tcase(s, tc);
  return s;
}