#ifndef MATRIXLIB_H
#define MATRIXLIB_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

/*
 * The matrix_t struct. This includes a double array pointer which serves as the
 * underlying machine representation of the matrix. The two integers indicate
 * the shape of the matrix.
 */
struct matrix_t {
    double * arr;
    int rows;
    int cols;
    int size;
};

/*
 * So you don't have to shove a whole matrix through a function call...
 */
typedef struct matrix_t * matrix;

matrix init(double * arr, int rows, int cols);
int del(matrix mat);

void print(matrix mat);

matrix add(matrix mat1, matrix mat2);
matrix sub(matrix mat1, matrix mat2);

matrix mul(matrix mat1, matrix mat2);
matrix transpose(matrix mat);
double det(matrix mat);


#endif
