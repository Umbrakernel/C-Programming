#include <stdio.h>
#include <stdlib.h>

void findMin(int lines, int cols, int **matrix, int *minLine, int *minCol) {
    int min = matrix[0][0];
    *minLine = 0;
    *minCol = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                *minLine = i;
                *minCol = j;
            }
        }
    }
}

void createKvadratMatrix(int **matrix, int lines, int cols, int minLine, int minCol, int size, int **KvadratMatrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int Line = minLine + i;
            int col = minCol + j;

            if (Line < lines && col < cols) {
                KvadratMatrix[i][j] = matrix[Line][col];
            } else {
                KvadratMatrix[i][j] = 0;
            }
        }
    }
}

void reverseDiagonal(int **matrix, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[size - 1 - i][size - 1 - i];
        matrix[size - 1 - i][size - 1 - i] = temp;
    }
}

int main() {
    int lines, cols;

    printf("Введите размеры матрицы (строки и столбцы): ");
    scanf("%d %d", &lines, &cols);

    int **matrix = (int **)malloc(lines * sizeof(int *));
    for (int i = 0; i < lines; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int minLine, minCol;
    findMin(lines, cols, matrix, &minLine, &minCol);

    int size = 2;

    int **KvadratMatrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        KvadratMatrix[i] = (int *)malloc(size * sizeof(int));
    }

    createKvadratMatrix(matrix, lines, cols, minLine, minCol, size, KvadratMatrix);

    printf("Квадратная матрица до переворота диагонали:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", KvadratMatrix[i][j]);
        }
        printf("\n");
    }

    reverseDiagonal(KvadratMatrix, size);

    printf("Квадратная матрица после переворота диагонали:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", KvadratMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < lines; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < size; i++) {
        free(KvadratMatrix[i]);
    }
    free(KvadratMatrix);

    return 0;
}