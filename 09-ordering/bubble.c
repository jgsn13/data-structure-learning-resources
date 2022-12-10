#include <stdio.h>

void print_arr(int n, int *v) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void bubble(int n, int *v) {
    int temp, swap;
    print_arr(n, v);
    for (int i = n - 1; i > 0; i--) {
        swap = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j]; // swap
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
        print_arr(n, v);
        if (swap == 0) {
            return;
        }
    }
}

int main() {
    int v[4] = {4, 2, 5, 1};
    bubble(4, v);
}
