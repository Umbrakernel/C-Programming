#include <stdio.h>
#define k 6

int main () {
    int a[k] = {5346, 10, -10, -329, 83, 1239};
    int b[k] = {3724, -1273, -12, -123, 124, -5675};
    int c[k];

    // Вывод массивов а и b
    printf("\nМассив a: ");
    for (int i = 0; i < k; i++) {
        printf("%d, ", a[i]);
    }
    printf("\nМассив b: ");
    for (int i = 0; i < k; i++) {
        printf("%d, ", b[i]);
    }

    // Сложение массивов
    printf("\nРезультат сложения: ");
    for (int i = 0; i < k; i++) {
        c[i] = a[i] + b[i];
        printf("%d, ", c[i]);
    }

    // Поиск максимального реального числа 
    int max_real = a[0];
    for (int i = 0; i < k; i++) {
        if (i % 2 == 0) {
            if (a[i] > max_real) {
                max_real = a[i];
            }
        }
    }
    printf("\nМаксимальное реальное число: %d", max_real);

    // Кол-во мнимых чисел которые меньше 0
    int count_image = 0;
    for (int i = 0; i < k; i++) {
        if (i % 2 != 0) {
            if (b[i] < 0) {
                count_image++
            }
        }
    }
    printf("\nКол-во мнимых чисел которые меньше 0: %d", count_image);

    // Среднее арифметическое мвссива с
    int sr_arif = 0;
    for (int i = 0; i < k; i++) {
        sr_arif = c[i] + sr_arif;
    }
    sr_arif = sr_arif/k;
    printf("\nСреднее арифметическое массива с: %d\n", sr_arif);
}