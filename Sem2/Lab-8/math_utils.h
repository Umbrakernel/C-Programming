#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <stdbool.h>

typedef struct {
    int num_roots;
    double root1;
    double root2;
} QuadraticSolution;

unsigned long factorial(unsigned int n);
bool is_prime(int num);
int gcd(int a, int b);
int lcm(int a, int b);
QuadraticSolution solve_quadratic(double a, double b, double c);

#endif