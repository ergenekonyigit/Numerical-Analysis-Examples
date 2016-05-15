#include "matrix.h"

matrix * init(double * arr, int rows, int cols) {
    matrix * mat = malloc(sizeof(matrix));
    if (mat != NULL) {
        mat->arr = malloc(rows * cols * sizeof(double));
        if (mat->arr != NULL) {
            memcpy(mat->arr, arr, rows * cols);
            mat->rows = rows;
            mat->cols = cols;
        }
    }
    return mat;
}

int del(matrix * mat) {
    free(mat->arr);
    //free(mat);
    return EXIT_SUCCESS;
}

void print(matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
       printf("["); 
        for (int j = 0; j < mat.cols - 1; j++) {
            printf("%2.2lf,", mat.arr[i * mat.cols + j]);
        }
        printf("%2.2lf]\n", mat.arr[i * mat.cols + mat.rows - 1]);
    }

}
