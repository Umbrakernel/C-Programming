#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Использование: %s <файл>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r+");

    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 2;
    }

    int number_count = 0;
    int in_number = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (isdigit(ch)) {
            if (!in_number) {
                number_count++;
                in_number = 1;
            }
        } else {
            in_number = 0;
        }
    }

    if (ferror(file)) {
        perror("Ошибка чтения файла");
        fclose(file);
        return 3;
    }

    fprintf(file, "\nКоличество чисел в файле: %d\n", number_count);

    if (ferror(file)) {
        perror("Ошибка записи в файл");
        fclose(file);
        return 4;
    }

    fclose(file);
    printf("Результат успешно записан в файл.\n");
    return 0;
}