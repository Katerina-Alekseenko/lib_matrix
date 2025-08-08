#include "test_lib_matrix.h"

START_TEST(sub_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  lib_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  lib_create_matrix(rows, cols, &mtx);
  matrix_t check = {0};
  lib_create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] - mtx.matrix[i][j];
    }
  }
  matrix_t res = {0};
  ck_assert_int_eq(lib_sub_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(lib_eq_matrix(&check, &res), SUCCESS);

  lib_remove_matrix(&m);
  lib_remove_matrix(&mtx);
  lib_remove_matrix(&res);
  lib_remove_matrix(&check);
}
END_TEST

Suite *suite_lib_sub_matrix(void) {
  Suite *s = suite_create("suite_lib_sub_matrix");
  TCase *tc = tcase_create("lib_sub_matrix");

  tcase_add_loop_test(tc, sub_matrix, 0, 100);

  suite_add_tcase(s, tc);
  return s;
}
