#ifndef MATRIXLIB_H
#define MATRIXLIB_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

/*
 * The matrix_t struct. This includes a double array pointer which serves as the
 * underlying machine representation of the matrix. The two integers rows and
 * cols indicate the shape of the matrix. For convenience, size is just the
 * product of rows and cols.
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

/*
 * Procedure:
 *   init
 * Purpose:
 *   this procedure takes a primitive array of doubles and shape parameters and
 *   returns a pointer to a matrix_t which stores the array and the shape inside
 *   the struct.
 * Parameters:
 *   arr, an array of type double
 *   rows, an int
 *   cols, an int
 * Produces:
 *   mat, a matrix
 * Preconditions:
 *   rows > 0 (this is checked)
 *   cols > 0 (this is checked)
 *   the length of arr must equal rows * cols (this is NOT checked)
 * Postconditions:
 *   if all preconditions are met, and malloc succeeds in initializing a matrix
 *   and a new array, then we have
 *     mat->arr[i] = arr[i] for all i (mat->arr is a copy of arr)
 *     mat->rows = rows
 *     mat->cols = cols
 *     mat->size = rows * cols
 * Notes:
 *   this procedure fails if:
 *     rows <= 0
 *     cols <= 0
 *     malloc fails to allocate space for a matrix_t
 *     malloc fails to allocate space for an array of size rows*cols
 *   this procedure has undefined behavior if:
 *     length of arr != rows * cols
 *   in a perfect world, you should avoid calling init and build matrices using
 *   other built-ins
 */
matrix init(double * arr, int rows, int cols);

/* WARNING: UNIMPLEMENTED
 * Procedure:
 *   del
 * Purpose:
 *   this procedure takes an initialized matrix and frees the memory
 * Parameters:
 *   mat, a matrix
 * Produces:
 *   success, an int
 * Preconditions:
 *   mat must be previously initialized (this is not checked)
 * Postconditions:
 *   mat no longer is associated with any data, and the previous data in mat has
 *   been freed
 *   if deletion is successful, success is EXIT_SUCCESS
 * Notes:
 *   for every malloc, you need a free. the model in this library is simplified
 *   so that for every matrix, you simply need an init call and a del call. this
 *   ensures that there are no leaks.
 */
int del(matrix mat);

/*
 * Procedure:
 *   print
 * Purpose:
 *   prints a string representation of a matrix into stdout
 * Parameters:
 *   mat, a matrix
 * Produces:
 *   [Called for side effects]
 * Preconditions:
 *   mat must be initialized
 * Postconditions:
 *   the string displayed is formatted according to the shape information in mat
 */
void print(matrix mat);

/* 
 * Procedure:
 *   add
 * Purpose:
 *   adds two matrices
 * Parameters:
 *   mat1, a matrix
 *   mat2, a matrix
 * Produces:
 *   mat3, a matrix
 * Preconditions:
 *   mat1 and mat2 are initialized matrices
 *   mat1->rows == mat2->rows (this is checked)
 *   mat1->cols == mat2->cols (this is checked)
 * Postconditions:
 *   mat3->arr[i] == mat1->arr[i] + mat2->arr[i] for all i
 *   mat3->rows == mat1->rows == mat2->rows
 *   mat3->cols == mat1->cols == mat2->cols
 */
matrix add(matrix mat1, matrix mat2);

/* 
 * Procedure:
 *   sub
 * Purpose:
 *   subtracts two matrices
 * Parameters:
 *   mat1, a matrix
 *   mat2, a matrix
 * Produces:
 *   mat3, a matrix
 * Preconditions:
 *   mat1 and mat2 are initialized matrices
 *   mat1->rows == mat2->rows (this is checked)
 *   mat1->cols == mat2->cols (this is checked)
 * Postconditions:
 *   mat3->arr[i] == mat1->arr[i] - mat2->arr[i] for all i
 *   mat3->rows == mat1->rows == mat2->rows
 *   mat3->cols == mat1->cols == mat2->cols
 */
 matrix sub(matrix mat1, matrix mat2);

/* 
 * Procedure:
 *   mul 
 * Purpose:
 *   multiplies two matrices
 * Parameters:
 *   mat1, a matrix
 *   mat2, a matrix
 * Produces:
 *   mat3, a matrix
 * Preconditions:
 *   mat1 and mat2 are initialized matrices
 *   mat1->cols == mat2->rows (this is checked)
 * Postconditions:
 *   mat3->rows == mat1->rows
 *   mat3->cols == mat2->cols
 *   mat3->arr is the result of the matrix product of mat1 and mat2
 */
matrix mul(matrix mat1, matrix mat2);

/* 
 * Procedure:
 *   transpose
 * Purpose:
 *   transposes a matrix
 * Parameters:
 *   mat, a matrix
 * Produces:
 *   mat_transpose, a matrix
 * Preconditions:
 *   mat is an initialized matrix
 * Postconditions:
 *   the "ij"th entry of mat_transpose corresponds to the "ji"th entry of mat
 *   mat_transpose->rows = mat->cols
 *   mat_transpose->cols = mat->rows
 */
matrix transpose(matrix mat);

/*
 * Procedure:
 *   det
 * Purpose:
 *   computes the determinant of a matrix
 * Parameters:
 *   mat, a matrix
 * Produces:
 *   det, a double
 * Preconditions:
 *   mat is an initialized matrix
 * Postconditions:
 *   det has all sorts of properties that are hard to verify in C. The Wikipedia
 *   entry is useful.
 */
double det(matrix mat);

/*
 * Procedure:
 *   vectorized
 * Purpose:
 *   applies a unary function to each entry of a matrix
 * Parameters:
 *   func, a unary function pointer
 *   mat, a matrix
 * Produces:
 *   new_mat, a matrix
 * Preconditions:
 *   mat is an initialized matrix
 *   func is actually pointing to a valid function
 * Postconditions:
 *   new_mat->arr[i] == f(mat->arr[i]) for all i
 *   new_mat->rows == mat->rows
 *   new_mat->cols == mat->cols
 */
matrix vectorized(double (*func)(double), matrix mat);

/*
 * Procedure:
 *   scale
 * Purpose:
 *   applies a scalar to each entry of a matrix
 * Parameters:
 *   mat, a matrix
 *   scalar, a double
 * Produces:
 *   new_mat, a matrix
 * Preconditions:
 *   mat is an initialized matrix
 * Postconditions:
 *   new_mat->arr[i] == scalar * mat->arr[i] for all i
 *   new_mat->rows == mat->rows
 *   new_mat->cols == mat->cols
 */
matrix scale(matrix mat, double scalar);

#endif
