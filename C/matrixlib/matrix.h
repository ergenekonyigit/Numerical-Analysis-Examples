#ifndef MATRIXLIB_H
#define MATRIXLIB_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct matrix_t {
    double * arr;
    int rows;
    int cols;
} matrix;

matrix * init(double * arr, int rows, int cols);
int del(matrix * mat);

void print(matrix mat);

matrix add(matrix mat1, matrix mat2);
matrix sub(matrix mat1, matrix mat2);

matrix mul(matrix mat1, matrix mat2);
matrix transpose(matrix mat);
double det(matrix mat);


#endif
