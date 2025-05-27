#include <stdio.h>

int amin () {
    short a, b;
    printf("Your number: ");
    scanf("%hd", &a);
    short last_byte = a & 0xff; // выделяю последний байт
    short first_byte = a & 0xff00; // выделяю младший байт
    b = (last_byte << 8)|(first_byte >> 8); // сдвигаю последний байт на место младшего, а младший байт на место последнего

    printf("%d\n", b)
}