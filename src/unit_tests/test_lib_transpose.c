#include "test_lib_matrix.h"

START_TEST(transpose_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t mtx = {0};
  lib_create_matrix(rows, cols, &mtx);

  matrix_t mtx_check = {0};
  lib_create_matrix(cols, rows, &mtx_check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(-10e10, 10e10);
      mtx.matrix[i][j] = rand_val;
      mtx_check.matrix[j][i] = rand_val;
    }
  }

  matrix_t res = {0};
  ck_assert_int_eq(lib_transpose(&mtx, &res), OK);
  ck_assert_int_eq(lib_eq_matrix(&mtx_check, &res), SUCCESS);

  lib_remove_matrix(&mtx);
  lib_remove_matrix(&res);
  lib_remove_matrix(&mtx_check);
}
END_TEST

Suite *suite_lib_transpose(void) {
  Suite *s = suite_create("suite_lib_transpose");
  TCase *tc = tcase_create("lib_transpose");

  tcase_add_loop_test(tc, transpose_matrix, 0, 100);

  suite_add_tcase(s, tc);
  return s;
}