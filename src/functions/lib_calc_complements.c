#include "../lib_matrix.h"

int lib_check_matrix_size(matrix_t *A) {
  int error = 0;
  if (A->columns <= 0 || A->rows <= 0) error = 1;
  if (A->columns != A->rows) error = 2;
  return error;
}

void lib_get_minor(matrix_t *A, matrix_t *minor, int skip_row, int skip_col) {
  int minor_row = 0;
  for (int m = 0; m < A->rows; m++) {
    if (m == skip_row) continue;
    int minor_col = 0;
    for (int n = 0; n < A->columns; n++) {
      if (n == skip_col) continue;
      minor->matrix[minor_row][minor_col] = A->matrix[m][n];
      minor_col++;
    }
    minor_row++;
  }
}

void lib_fill_complements(matrix_t *A, matrix_t *result) {
  matrix_t minor = {0};
  lib_create_matrix(A->rows - 1, A->columns - 1, &minor);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      lib_get_minor(A, &minor, i, j);
      double minor_det = 0;
      int error = lib_determinant(&minor, &minor_det);
      if (!error) {
        result->matrix[i][j] = (i + j) % 2 == 0 ? minor_det : -minor_det;
      }
    }
  }
  lib_remove_matrix(&minor);
}

int lib_calc_complements(matrix_t *A, matrix_t *result) {
  int error = lib_check_matrix_size(A);
  if (!error) {
    lib_create_matrix(A->rows, A->columns, result);
    lib_fill_complements(A, result);
  }
  return error;
}