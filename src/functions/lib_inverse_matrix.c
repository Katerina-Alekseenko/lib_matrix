#include "../lib_matrix.h"

int lib_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  if (A->columns <= 0 || A->rows <= 0) error = 1;
  if (A->columns != A->rows) error = 2;
  if (!error && A->columns == 1) {
    if (lib_compare_numbers(A->matrix[0][0], 0))
      error = 2;
    else {
      lib_create_matrix(1, 1, result);
      result->matrix[0][0] = 1.0 / A->matrix[0][0];
    }
  }
  if (!error && A->columns > 1) {
    double det = 0;
    error = lib_determinant(A, &det);
    if (!error && lib_compare_numbers(0, det)) error = 2;
    if (!error) {
      matrix_t tmp;
      error = lib_calc_complements(A, &tmp);
      if (!error) {
        matrix_t tmp2;
        lib_transpose(&tmp, &tmp2);
        lib_remove_matrix(&tmp);
        lib_mult_number(&tmp2, 1 / det, result);
        lib_remove_matrix(&tmp2);
      }
    }
  }
  return error;
}