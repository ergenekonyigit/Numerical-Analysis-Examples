#include "matrix.h"

matrix init(double * arr, int rows, int cols) {
    matrix mat = malloc(sizeof(matrix));
    assert(mat != NULL);
    int size = rows * cols;
    mat->arr = malloc(size * sizeof(double));
    assert(mat->arr != NULL);

    for(int i = 0; i < size; i++) 
        mat->arr[i] = arr[i];

    mat->rows = rows;
    mat->cols = cols;
    mat->size = size;

    return mat;
}

int del(matrix mat) {
    free(mat->arr);
    free(mat);
    return EXIT_SUCCESS;
}

void print(matrix mat) {
    for (int i = 0; i < mat->rows; i++) {
        printf("["); 
        for (int j = 0; j < mat->cols - 1; j++) {
            printf("%2.2lf,", mat->arr[i * mat->cols + j]);
        }
        printf("%2.2lf]\n", mat->arr[i * mat->cols + mat->rows - 1]);
    }
}

matrix add(matrix mat1, matrix mat2) {
    assert(mat1->rows == mat2->rows);
    assert(mat1->cols == mat2->cols);
    double * arr = malloc(mat1->rows * mat1->cols * sizeof(double));
    for (int i = 0; i < mat1->rows * mat1->cols; i++)
        arr[i] = mat1->arr[i] + mat2->arr[i];

    return init(arr, mat1->rows, mat1->cols);
}

matrix sub(matrix mat1, matrix mat2) {
    assert(mat1->rows == mat2->rows);
    assert(mat1->cols == mat2->cols);
    double * arr = malloc(mat1->rows * mat1->cols * sizeof(double));
    for (int i = 0; i < mat1->rows * mat1->cols; i++)
        arr[i] = mat1->arr[i] - mat2->arr[i];

    return init(arr, mat1->rows, mat1->cols);
}

matrix transpose(matrix mat) {
    assert(mat->rows > 0);
    assert(mat->cols > 0);

    double * arr = malloc(mat->rows * mat->cols * sizeof(double));
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            arr[j * mat->rows + i] = mat->arr[i * mat->cols + j];
        }
    }
    return init(arr, mat->cols, mat->rows);
}
