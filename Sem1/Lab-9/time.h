#include <stdio.h>

struct Time{
    int hours;
    int minutes;
}

Time initialize_time(int hours, int minutes);
Time total_time(Time stages[], int n);
Time find_min_time(Time stages[], int n);