#include <stdio.h>

int main () {
    int g = 1;
    int h, i, n;
    scanf ("%d", &h);
    for (i = 0; i != h; i++) {
        for (n = 0; n != h; n++) {
            print("%d", g);
        }
        printf("\n");
    }
}