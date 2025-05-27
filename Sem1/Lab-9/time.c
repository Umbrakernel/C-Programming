#include "time.h"

struct Time{
    int hours;
    int minutes;
}

Time initialize_time(int hours, int minutes) {
    Time t;
    t.hours = hours;
    t.minutes = minutes;
    return t;
}

Time total_time(Time stages[], int n) {
    Time total = {0, 0};

    for (int i = 0; i < n; i++) {
        total.hours += stages[i].hours;
        total.minutes += stages[i].minutes;

        if (total.minutes >= 60) {
            total.hours += total.minutes / 60;
            total.minutes %= 60;
        }
    }
    return total;
}

Time find_min_time(Time stages[], int n) {
    Time min_time = stages[0];
    for (int i = 1; i < n; i++) {
        int min_total_minutes = min_time.hours * 60 + min_time.minutes;
        int current_total_minutes = stages[i].hours * 60 + stages[i].minutes;

        if (current_total_minutes < min_total_minutes) {
            min_time = stages[i];
        }
    }
    return min_time;
}