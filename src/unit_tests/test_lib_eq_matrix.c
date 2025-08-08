#include "test_lib_matrix.h"

START_TEST(eq_matrix) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t tmp = {0};
  lib_create_matrix(rows, columns, &tmp);
  matrix_t next_tmp = {0};
  lib_create_matrix(rows, columns, &next_tmp);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      double value = get_rand(DBL_MIN, DBL_MAX);
      tmp.matrix[i][j] = value;
      next_tmp.matrix[i][j] = value;
    }
  }

  ck_assert_int_eq(lib_eq_matrix(&tmp, &next_tmp), SUCCESS);
  lib_remove_matrix(&tmp);
  lib_remove_matrix(&next_tmp);
}
END_TEST

START_TEST(not_eq_matrix) {
  const int rows = rand() % 100 + 1;
  const int columns = rand() % 100 + 1;
  matrix_t tmp = {0};
  lib_create_matrix(rows, columns, &tmp);
  matrix_t next_tmp = {0};
  lib_create_matrix(rows, columns, &next_tmp);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      tmp.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
      next_tmp.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  ck_assert_int_eq(lib_eq_matrix(&tmp, &next_tmp), FAILURE);
  lib_remove_matrix(&tmp);
  lib_remove_matrix(&next_tmp);
}
END_TEST

Suite *suite_lib_eq_matrix(void) {
  Suite *s = suite_create("suite_lib_eq_matrix");
  TCase *tc = tcase_create("lib_eq_matrix");

  tcase_add_test(tc, not_eq_matrix);
  tcase_add_loop_test(tc, eq_matrix, 0, 100);

  suite_add_tcase(s, tc);
  return s;
}
