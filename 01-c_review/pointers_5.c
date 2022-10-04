#include <stdio.h>
#include <stdlib.h>

// Matrice as a vector

float summation(int m, int n, float *v) {
    float md = 0.0F;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            md += v[i * n + j];
    return md;
}

int main() {
    int m, n;
    float *mat = (float *)malloc(m * n * sizeof(float *));
    free(mat);

    return 0;
}
