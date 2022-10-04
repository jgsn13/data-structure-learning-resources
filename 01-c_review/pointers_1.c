#include <stdio.h>

void sumprod(int x, int y, int *s, int *p) {
    *s = x + y;
    *p = x * y;
}

int main() {
    int s, p;
    sumprod(3, 5, &s, &p);
    printf("sum = %d, prod = %d", s, p);
    return 0;
}
