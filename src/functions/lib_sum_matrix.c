#include "../lib_matrix.h"

int lib_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if ((A->columns != B->columns) || (A->rows != B->rows)) {
    error = 2;
  }
  if (!error &&
      (A->columns <= 0 || A->rows <= 0 || B->columns <= 0 || B->rows <= 0))
    error = 1;
  if (error == 0) {
    lib_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return error;
}