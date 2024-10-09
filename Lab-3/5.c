#include <stdio.h>

int main () {
    int a, i, n;
    scanf("%d", &a);
    for (i = 0; i <= a; i++) {
        for (n = 0; n < i; n++) {
            printf(" ");
        }
        for (n; n < (a*2)-i-1; n++){
            printf("V");
        }
        printf("\n")
    }
}