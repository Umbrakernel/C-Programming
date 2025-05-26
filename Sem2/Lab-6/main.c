#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"
#include "sort.h"

#define N 100

int main() {
    struct Student students[N];
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        char name[64];
        snprintf(name, 64, "Student_%d", i + 1);
        students[i] = addStudent(name, rand() % 101, rand() % 101, rand() % 101);
    }

    printf("Before sorting:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    clock_t start, end;
    double time_used;

    start = clock();
    selectionSort(students, N);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort time: %f seconds\n", time_used);

    printf("\nAfter Selection Sort:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    for (int i = 0; i < N; i++) {
        students[i] = addStudent(students[i].name, rand() % 101, rand() % 101, rand() % 101);
    }

    start = clock();
    radixSort(students, N);
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Radix Sort time: %f seconds\n", time_used);

    printf("\nAfter Radix Sort:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    system("cat /proc/cpuinfo | grep 'model name' | head -1");
    system("cat /proc/cpuinfo | grep 'cpu MHz' | head -1");

    return 0;
}