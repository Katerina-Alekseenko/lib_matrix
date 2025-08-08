#include "../lib_matrix.h"

int lib_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if ((rows <= 0) || (columns <= 0)) error = 1;
  if (error == 0) {
    result->columns = columns;
    result->rows = rows;
    (result->matrix) = (double **)malloc(sizeof(double) * rows * columns +
                                         rows * sizeof(double *));
    if (result->matrix == NULL)
      error = 2;
    else {
      double *ptr = (double *)(result->matrix + rows);
      for (int i = 0; i < rows; i++) result->matrix[i] = ptr + columns * i;
    }
  }
  return error;
}
