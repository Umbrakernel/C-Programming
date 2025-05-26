#include "sort.h"
#include "student.h"
#include <stdlib.h>
#include <limits.h>

static int getMax(struct Student arr[], int size) {
    if (size <= 0) return 0;
    
    int max = arr[0].total;
    for (int i = 1; i < size; i++) {
        if (arr[i].total > max) {
            max = arr[i].total;
        }
    }
    return max;
}

static void countingSort(struct Student arr[], int size, int exp) {
    if (size <= 0) return;
    
    struct Student *output = malloc(size * sizeof(struct Student));
    if (!output) return;
    
    int count[10] = {0};
    
    for (int i = 0; i < size; i++) {
        count[(arr[i].total / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = size - 1; i >= 0; i--) {
        int index = (arr[i].total / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    
    free(output);
}

void selectionSort(struct Student arr[], int size) {
    if (size <= 0) return;
    
    for (int i = 0; i < size - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].total > arr[maxIndex].total) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            struct Student temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

void radixSort(struct Student arr[], int size) {
    if (size <= 0) return;
    
    int max = getMax(arr, size);
    for (int exp = 1; max / exp > 0 && exp < INT_MAX/10; exp *= 10) {
        countingSort(arr, size, exp);
    }
}