#include "../lib_matrix.h"

void lib_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}