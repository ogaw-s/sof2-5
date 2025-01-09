#include <stdio.h>
#include <math.h>
#include <limits.h> //LONG_MAXがある
#include <assert.h>

typedef struct matrix {
    long a,b,c,d;
} Matrix;

Matrix mul(Matrix m1, Matrix m2) {
    Matrix m = {.a = m1.a*m2.a + m1.b*m2.c,
                .b = m1.a*m2.b + m1.b*m2.d,
                .c = m1.c*m2.a + m1.d*m2.c,
                .d = m1.c*m2.b + m1.d*m2.d};
    return m;
}

Matrix npower(Matrix m, int n) {
    Matrix m1 = {.a = 1, .b = 1, .c = 1, .d = 0};
    if (n == 1) {
        return m1;
    }else if (n % 2 == 0) {
        return mul(npower(m, n/2), npower(m, n/2));
    }else {
        return mul(mul(npower(m,(n-1)/2), npower(m,(n-1)/2)), m1);
    }
}

long fibo(int n) {
    assert(n < 90);
    if (n == 0) {
        return 0;
    }else if (n == 1) {
        return 1;
    }

    Matrix a = {.a = 1, .b = 1, .c = 1, .d = 0};
    Matrix an = npower(a, n-1);
    
    return an.a;
}

int main() {
    printf("%ld\n", fibo(1));
    printf("%ld\n", fibo(2));
    printf("%ld\n", fibo(3));
    printf("%ld\n", fibo(4));
    printf("%ld\n", fibo(5));
    printf("%ld\n", fibo(6));
    printf("%ld\n", fibo(7));
    printf("%ld\n", fibo(8));
    printf("%ld\n", fibo(9));
    
}