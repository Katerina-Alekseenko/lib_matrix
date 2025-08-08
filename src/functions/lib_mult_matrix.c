#include "../lib_matrix.h"

int lib_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A->columns <= 0 || A->rows <= 0 || B->columns <= 0 || B->rows <= 0)
    error = 1;
  if (A->columns != B->rows) error = 2;
  if (error == 0) {
    lib_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int m = 0; m < A->columns; m++)
          result->matrix[i][j] += A->matrix[i][m] * B->matrix[m][j];
      }
    }
  }
  return error;
}