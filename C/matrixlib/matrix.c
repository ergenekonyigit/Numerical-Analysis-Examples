#include "matrix.h"

matrix init(double * arr, int rows, int cols) {
    assert(rows > 0);
    assert(cols > 0);

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
    assert(mat->rows > 0);
    assert(mat->cols > 0);

    for (int i = 0; i < mat->rows; i++) {
        printf("["); 
        for (int j = 0; j < mat->cols - 1; j++) {
            printf("%2.2lf,", mat->arr[i * mat->cols + j]);
        }
        printf("%2.2lf]\n", mat->arr[i * mat->cols + mat->cols - 1]);
    }
}

matrix add(matrix mat1, matrix mat2) {
    assert(mat1->rows == mat2->rows);
    assert(mat1->cols == mat2->cols);

    double * arr = malloc(mat1->size * sizeof(double));
    for (int i = 0; i < mat1->size; i++)
        arr[i] = mat1->arr[i] + mat2->arr[i];

    matrix mat3 = init(arr, mat1->rows, mat1->cols);
    free(arr);

    return mat3;
}

matrix sub(matrix mat1, matrix mat2) {
    assert(mat1->rows == mat2->rows);
    assert(mat1->cols == mat2->cols);

    double * arr = malloc(mat1->size * sizeof(double));
    for (int i = 0; i < mat1->size; i++)
        arr[i] = mat1->arr[i] - mat2->arr[i];

    matrix mat3 = init(arr, mat1->rows, mat1->cols);
    free(arr);

    return mat3;
}

matrix mul(matrix mat1, matrix mat2) {
    assert(mat1->cols == mat2->rows);

    double * arr = malloc(mat1->rows * mat2->cols * sizeof(double));
    int rows = mat1->rows;
    int cols = mat2->cols;
    int mid = mat1->cols;
    int index;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            index = i * rows + j;
            arr[index] = 0.0;
            for (int k = 0; k < mid; k++) {
                arr[index] += mat1->arr[i * mat1->cols + k] * mat2->arr[k * mat2->cols + j];
            }
        }
    }

    matrix mat3 = init(arr, mat1->rows, mat2->cols);
    free(arr);

    return mat3;

}

matrix transpose(matrix mat) {
    double * arr = malloc(mat->size * sizeof(double));
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            arr[j * mat->rows + i] = mat->arr[i * mat->cols + j];
        }
    }
    matrix mat_transpose = init(arr, mat->cols, mat->rows);
    free(arr);

    return mat_transpose;
}

matrix vectorized(double (*func)(double), matrix mat) {
    double * arr = malloc(mat->size * sizeof(double));
    for (int i = 0; i < mat->size; i++) {
        arr[i] = func(mat->arr[i]);
    }

    matrix new_mat = init(arr, mat->rows, mat->cols);
    free(arr);

    return new_mat;
}

matrix scale(matrix mat, double scalar) {
    double * arr = malloc(mat->size * sizeof(double));
    for (int i = 0; i < mat->size; i++) {
        arr[i] = scalar * mat->arr[i];
    }

    matrix new_mat = init(arr, mat->rows, mat->cols);
    free(arr);

    return new_mat;

}
