#include "matrix.h"

int main(void) {
    double arr[6] = { 4, 5, 6, 7, 8, 9 };
    matrix m = init(arr, 2, 3);
    printf("%d,%d\n", m->rows, m->cols);
    print(m);
    del(m);


    return 0;
}
