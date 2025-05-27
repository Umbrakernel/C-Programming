#include <stdio.h>

// Функция для вычисления определителя 2x2
double opr2x2(double a, double b, double c, double d) {
    return a * d - b * c;
}

// Функция для вычисления определителя 3x3
double opr3x3(double matrix[3][3]) {
    return ((matrix[0][0] * matrix[1][1] * matrix[2][2]) + (matrix[1][0] * matrix[2][1] * matrix[0][2]) + (matrix[0][1] * matrix[1][2] * matrix[2][0]) - (matrix[0][2] * matrix[1][1] * matrix[2][0]) + (matrix[0][1] * matrix[1][0] * matrix[2][2]) + (matrix[1][2] * matrix[0][0] * matrix[2][1]));
}

// Функция для решения СЛАУ 2x2 методом Крамера
void solve2x2(double matrix[2][2], double ravno[2]) {
    double opr_main = opr2x2(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
    if (opr_main == 0) {
        printf("Система не имеет единственного решения\n");
        return;
    }

    double x1 = opr2x2(ravno[0], matrix[0][1], ravno[1], matrix[1][1]) / opr_main;
    double x2 = opr2x2(matrix[0][0], ravno[0], matrix[1][0], ravno[1]) / opr_main;

    printf("Решение: x1 = %lf, x2 = %lf\n", x1, x2);
}

// Функция для решения СЛАУ 3x3 методом Крамера
void solve3x3(double matrix[3][3], double ravno[3]) {
    double opr_main = opr3x3(matrix);
    if (opr_main == 0) {
        printf("Система не имеет единственного решения\n");
        return;
    }

    double matrix_x1[3][3] = {{ravno[0], matrix[0][1], matrix[0][2]},
                              {ravno[1], matrix[1][1], matrix[1][2]},
                              {ravno[2], matrix[2][1], matrix[2][2]}};
    double matrix_x2[3][3] = {{matrix[0][0], ravno[0], matrix[0][2]},
                              {matrix[1][0], ravno[1], matrix[1][2]},
                              {matrix[2][0], ravno[2], matrix[2][2]}};
    double matrix_x3[3][3] = {{matrix[0][0], matrix[0][1],ravno[0]},
                              {matrix[1][0], matrix[1][1],ravno[1]},
                              {matrix[2][0], matrix[2][1],ravno[2]}};

    double x1 = opr3x3(matrix_x1) / opr_main;
    double x2 = opr3x3(matrix_x2) / opr_main;
    double x3 = opr3x3(matrix_x3) / opr_main;

    printf("Решение: x1 = %lf, x2 = %lf, x3 = %lf\n", x1, x2, x3);
}

int main() {
    int N;
    printf("Введите размер системы (2 или 3): ");
    scanf("%d", &N);

    if (N == 2) {
        double matrix[2][2], ravno[2];
        printf("Введите коэффициенты матрицы 2x2 начиная с первого уравненияи с лева на право:\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%lf", &matrix[i][j]);
            }
            scanf("%lf", & ravno[i]);
        }
        solve2x2(matrix, ravno);
    } else if (N == 3) {
        double matrix[3][3], ravno[3];
        printf("Введите коэффициенты матрицы 3x3 начиная с первого уравнения с лева на право:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%lf", &matrix[i][j]);
            }
            scanf("%lf", &ravno[i]);
        }
        solve3x3(matrix, ravno);
    } else {
        printf("Размер системы должен быть 2 или 3.\n");
    }

}