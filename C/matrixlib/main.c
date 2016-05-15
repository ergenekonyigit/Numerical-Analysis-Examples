#include "matrix.h"

int main(void) {
    double arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    matrix * m;
    m = init(arr, 3, 3);
    printf("%d,%d\n", m->rows, m->cols);
    print(*m);

    return 0;
    

}
