#include <stdio.h>
#include <ctype.h>

int main() {
    char text[500];
    int sum = 0;
    int hasDigits = 0;

    printf("Введите текст: ");
    fgets(text, sizeof(sentence), stdin);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isdigit(text[i])) {
            sum += text[i] - '0';
            hasDigits = 1;
        }
    }

    if (hasDigits) {
        printf("Сумма цифр: %d\n", sum);
    } else {
        printf("Цифр не найдено в предложении.\n");
    }

    return 0;
}