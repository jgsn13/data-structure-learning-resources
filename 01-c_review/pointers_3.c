#include <stdio.h>
#include <stdlib.h>

float summation(int m, float v[]) {
    float s = 0.0F;
    for (int i = 0; i < m; i++)
        s += v[i];
    return s;
}

int main() {
    int n;
    float *v;
    float s;
    scanf("%d", &n);
    v = (float *)malloc(n * sizeof(float));
    if (v == NULL) {
        printf("Insufficient memory");
        exit(1);
    }
    for (int i = 0; i < n; i++)
        scanf("%f", &v[i]);
    s = summation(n, v);
    printf("summation=%.1f, mean=%.1f", s, s / n);
    free(v);
    return 0;
}
