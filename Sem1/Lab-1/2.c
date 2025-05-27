#include <stdio.h>

int main () {
    float temp;
    char fc;
    printf("enter temp:");
    scanf("%f %c", &temp);
    printf("enter c or C or f or F:");
    scanf("%c", &fc);
    if (fc == 'c' || fc == 'C') {
        printf("Far: %f\n", (temp*9/5)+32);
    } else if (fc == 'f' || fc == 'F') {
        printf("Cel: %f\n", (temp-32)*5/9);
    } else {
        printf("ERROR\n");
    }
}