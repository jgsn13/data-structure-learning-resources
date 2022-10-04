#include <stdio.h>

float summation(int m, float v[]) {
    float s = 0.0F;
    for (int i = 0; i < m; i++)
        s += v[i];
    return s;
}

int main() {
    float v[] = {2.0, 3.0, 4.0};
    float s = summation(3, v);
    printf("summation=%.1f, mean=%.1f", s, s / 3);
    return 0;
}
