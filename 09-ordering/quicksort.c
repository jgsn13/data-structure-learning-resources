#include <stdio.h>
#define N 7

void print_vector(int length, int *vector) {
    for (int index = 0; index < length; index++) {
        printf("%d ", vector[index]);
        if (index + 1 == length) {
            printf("\n");
        }
    }
}

void quicksort(int length, int *vector) {
    if (length > 1) {
        int pivot = vector[0];
        int left = 1;
        int right = length - 1;
        int temp;
        while (1) {
            while (left < length && vector[left] <= pivot) {
                left++;
            }
            while (vector[right] > pivot) {
                right--;
            }
            if (left < right) {
                temp = vector[left];
                vector[left] = vector[right];
                vector[right] = temp;
                left++;
                right--;
            } else {
                break;
            }
        }
        vector[0] = vector[right];
        vector[right] = pivot;
        quicksort(right, vector);
        quicksort(length - left, &vector[left]);
    }
}

int main() {
    int v[N] = {12, 23, 44, 58, 99, 32, 66};
    print_vector(N, v);
    quicksort(N, v);
    print_vector(N, v);
}
