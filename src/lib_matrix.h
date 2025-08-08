#ifndef LIB_MATRIX_H
#define LIB_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int lib_create_matrix(int rows, int columns, matrix_t *result);
void lib_remove_matrix(matrix_t *A);
int lib_eq_matrix(matrix_t *A, matrix_t *B);
int lib_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int lib_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int lib_mult_number(matrix_t *A, double number, matrix_t *result);
int lib_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int lib_transpose(matrix_t *A, matrix_t *result);
int lib_calc_complements(matrix_t *A, matrix_t *result);
int lib_determinant(matrix_t *A, double *result);
int lib_inverse_matrix(matrix_t *A, matrix_t *result);

int lib_compare_numbers(double a, double b);
int lib_check_matrix_size(matrix_t *A);
void lib_get_minor(matrix_t *A, matrix_t *minor, int skip_row, int skip_col);
void lib_fill_complements(matrix_t *A, matrix_t *result);
double lib_helper(matrix_t *A, int *error);
void lib_fill_minor_matrix(matrix_t *A, matrix_t *minor, int f, int count_rows);

#endif