#include "../lib_matrix.h"

int lib_compare_numbers(double a, double b) { return fabs(a - b) < 0.0000001; }

int lib_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = 1;
  if (A->columns <= 0 || A->rows <= 0 || B->columns <= 0 || B->rows <= 0)
    error = 0;
  if ((A->columns != B->columns) || (A->rows != B->rows)) error = 0;
  if (error) {
    for (int i = 0; error && (i < A->rows); i++) {
      for (int j = 0; error && (j < A->columns); j++) {
        if (!lib_compare_numbers(A->matrix[i][j], B->matrix[i][j])) error = 0;
      }
    }
  }
  return error;
}