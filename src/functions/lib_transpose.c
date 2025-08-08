#include "../lib_matrix.h"

int lib_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A->columns <= 0 || A->rows <= 0)
    error = 1;
  else {
    lib_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return error;
}