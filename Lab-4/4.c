#include <stdio.h>

int main () {
    int x;
    scanf("%d", &x);
    if ((x >> 4) << 4 == x) {
        printf("Число кратно 16\n")
    } else {
        prinf("Число не кратно 16\n")
    }
}