#include <stdio.h>

int main () {
    int a=1234;
    int s;
    int n;
    int k;
    for (n=a, s=0; n!=0; n=n/10) {
        k=n%10, s=s+k
        printf("%d %d %d\n", n, k, s);
    }
}