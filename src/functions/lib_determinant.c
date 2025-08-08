#include "../lib_matrix.h"

void lib_fill_minor_matrix(matrix_t *A, matrix_t *minor, int count,
                           int count_rows) {
  for (int i = 1; i < count_rows; i++) {
    int col_count = 0;
    for (int j = 0; j < count_rows; j++) {
      if (j == count) continue;
      minor->matrix[i - 1][col_count] = A->matrix[i][j];
      col_count++;
    }
  }
}

double lib_helper(matrix_t *A, int *error) {
  int count_rows = A->rows;
  double det = 0;
  if (count_rows == 1) {
    det = A->matrix[0][0];
  } else if (count_rows == 2) {
    det = (A->matrix[0][0] * A->matrix[1][1]) -
          (A->matrix[0][1] * A->matrix[1][0]);
  } else {
    matrix_t minor;
    lib_create_matrix(count_rows - 1, count_rows - 1, &minor);
    for (int f = 0; f < count_rows; f++) {
      lib_fill_minor_matrix(A, &minor, f, count_rows);
      det += (f % 2 ? -1.0 : 1.0) * A->matrix[0][f] * lib_helper(&minor, error);
    }
    lib_remove_matrix(&minor);
  }
  return det;
}

int lib_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (A->columns <= 0 || A->rows <= 0) {
    error = 1;
  }
  if (!error && (A->columns != A->rows)) {
    error = 2;
  }
  if (!error) {
    int inner_res = 0;
    *result = lib_helper(A, &inner_res);
    error = inner_res;
  }
  return error;
}