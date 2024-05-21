import numpy as np


def f1(x):
    return x**4 / (26 + x**2)


def rectangle_method(f, a, b, n):
    h = (b - a) / n
    result = sum(f(a + i * h) for i in range(n)) * h
    return result


def trapezoidal_method(f, a, b, n):
    h = (b - a) / n
    result = (f(a) + f(b)) / 2 + sum(f(a + i * h) for i in range(1, n))
    return result * h


def simpson_method(f, a, b, n):
    if n % 2 == 1:
        n += 1
    h = (b - a) / n
    result = (
        f(a)
        + f(b)
        + 4 * sum(f(a + i * h) for i in range(1, n, 2))
        + 2 * sum(f(a + i * h) for i in range(2, n - 1, 2))
    )
    return result * h / 3


a1, b1 = 1, 2
n = 100000

int1_rect = rectangle_method(f1, a1, b1, n)
int1_trap = trapezoidal_method(f1, a1, b1, n)
int1_simp = simpson_method(f1, a1, b1, n)

print(f"Метод прямоугольников: {int1_rect:.7f}")
print(f"Метод трапеций: {int1_trap:.7f}")
print(f"Метод Симпсона: {int1_simp:.7f}")
