#include <stdio.h>
#include <stdlib.h>

// Matrice represented as a vector of pointers

float summation(int m, int n, float **v) {
    float md = 0.0F;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            md += v[i][j];
    return md;
}

int main() {
    int m, n;

    // Allocate
    float **mat = (float **)malloc(m * sizeof(float *));
    for (int i = 0; i < m; i++)
        mat[i] = (float *)malloc(n * sizeof(float));

    // Free
    for (int i = 0; i < m; i++)
        free(mat[i]);
    free(mat);

    return 0;
}
