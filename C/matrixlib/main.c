#include "matrix.h"

void print_arr(double * arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%lf,", arr[i]);
    printf("\n");
}

int main(void) {
    double arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    matrix m = init(arr, 3, 3);
    print(m);
    printf("\n");
    matrix n = transpose(m);
    print(n);
    printf("\n");

    matrix asdf = mul(m, n);
    matrix fdsa = mul(n, m);

    print(asdf);
    printf("\n");

    print(fdsa);
    printf("\n");


    del(m);
    del(n);
    del(asdf);


    return 0;
}
