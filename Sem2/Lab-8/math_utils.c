#include "math_utils.h"
#include <math.h>
#include <stdbool.h>

// Вычисление факториала
unsigned long factorial(unsigned int n) {
    if (n == 0) return 1;
    unsigned long result = 1;
    for (unsigned int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Проверка на простое число
bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Вычисление НОД (алгоритм Евклида)
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Вычисление НОК
int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return abs(a * b) / gcd(a, b);
}

QuadraticSolution solve_quadratic(double a, double b, double c) {
    QuadraticSolution solution;
    double discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) {
        solution.num_roots = 0;
    } 
    else if (discriminant == 0) {
        solution.num_roots = 1;
        solution.root1 = -b / (2 * a);
        solution.root2 = solution.root1;
    } 
    else {
        solution.num_roots = 2;
        solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
        solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
    }
    
    return solution;
}