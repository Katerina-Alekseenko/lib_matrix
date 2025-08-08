#include "test_lib_matrix.h"

START_TEST(mult_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t mtx = {0};
  lib_create_matrix(rows, cols, &mtx);
  matrix_t mtx_check = {0};
  lib_create_matrix(cols, rows, &mtx_check);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) mtx.matrix[i][j] = get_rand(-10e10, 10e10);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++)
      mtx_check.matrix[i][j] = get_rand(-10e10, 10e10);

  matrix_t check = {0};
  lib_create_matrix(mtx.rows, mtx_check.columns, &check);

  for (int i = 0; i < mtx.rows; i++) {
    for (int j = 0; j < mtx_check.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < mtx.columns; k++)
        check.matrix[i][j] += mtx.matrix[i][k] * mtx_check.matrix[k][j];
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(lib_mult_matrix(&mtx, &mtx_check, &res), OK);
  ck_assert_int_eq(lib_eq_matrix(&check, &res), SUCCESS);

  lib_remove_matrix(&mtx);
  lib_remove_matrix(&mtx_check);
  lib_remove_matrix(&res);
  lib_remove_matrix(&check);
}
END_TEST

Suite *suite_lib_mult_number(void) {
  Suite *s = suite_create("suite_lib_mult_matrix");
  TCase *tc = tcase_create("lib_mult_matrix");

  tcase_add_loop_test(tc, mult_matrix, 0, 1000);

  suite_add_tcase(s, tc);
  return s;
}