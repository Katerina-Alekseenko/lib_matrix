#include "../lib_matrix.h"

int lib_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if (A->columns <= 0 || A->rows <= 0)
    error = 1;
  else {
    lib_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return error;
}