#include <stdio.h>
#include <stdlib.h>

float summation(int m, float v[][3]) {
    float md = 0.0F;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 3; j++)
            md += v[i][j];
    return md;
}

int main() {
    int m, n;
    // Dynamic memory allocation for matrices
    float **mat = (float**)malloc(m*sizeof(float*));
    for (int i = 0; i < m; i++)
        mat[i] = (float*)malloc(n*sizeof(float));

    // To free memory
    for (int i = 0; i < m; i++)
        free(mat[i]);
    free(mat);

    return 0;
}
