#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main () {
    printf("hello git\n");
    int a[] = {4, 0};
    int n = 3;
    sort(a, n);
    return 0;
}
// Этот код сортирует массив методом пузырька
// Comment