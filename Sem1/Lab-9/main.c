#include "time.h"

int main() {
    int n;

    printf("Введите количество этапов: ");
    scanf("%d", &n);

    Time stages[n];

    for (int i = 0; i < n; i++) {
        int hours, minutes;
        printf("Введите часы и минуты для этапа %d (через пробел): ", i + 1);
        scanf("%d %d", &hours, &minutes);
        stages[i] = initialize_time(hours, minutes);
    }

    Time total_time = calculate_total_time(stages, n);
    Time min_time = find_min_time(stages, n);

    printf("Общее время процесса: %d часов и %d минут\n", total_time.hours, total_time.minutes);
    printf("Минимальное время этапа: %d часов и %d минут\n", min_time.hours, min_time.minutes);

}