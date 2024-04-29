import numpy as np


# Функция и ее производная
def f(x):
    if x <= 1:
        return np.nan
    else:
        return np.exp(-x) - np.sqrt(x - 1)


def df(x):
    if x <= 1:
        return np.nan
    else:
        return -np.exp(-x) - 0.5 / np.sqrt(x - 1)


def phi(x, lambda_value=0.1):
    return x - lambda_value * (f(x) / (df(x) + np.finfo(float).eps))


# Метод бисекции
def bisection_method(f, a, b, epsilon, max_iter=100):
    if np.isnan(f(a)) or np.isnan(f(b)) or f(a) * f(b) >= 0:
        print("Invalid input or no sign change")
        return None
    c = a
    iter_count = 0
    while (b - a) / 2.0 > epsilon and iter_count < max_iter:
        c = (a + b) / 2.0
        if f(c) == 0:
            break
        if f(a) * f(c) < 0:
            b = c
        else:
            a = c
        iter_count += 1
    return c


# Метод Ньютона
def newton_method(f, df, x0, epsilon, max_iter=50):
    x1 = x0 - f(x0) / (df(x0) + np.finfo(float).eps)
    iter_count = 0
    while abs(x1 - x0) > epsilon and iter_count < max_iter:
        x0 = x1
        x1 = x0 - f(x0) / (df(x0) + np.finfo(float).eps)
        iter_count += 1
    return x1


# Метод секущих
def secant_method(f, a, b, epsilon, max_iter=50):
    iter_count = 0
    while abs(b - a) > epsilon and iter_count < max_iter:
        denom = f(b) - f(a)
        if abs(denom) < np.finfo(float).eps:
            print("Denominator too small")
            return None
        c = a - f(a) * (b - a) / denom
        a, b = b, c
        iter_count += 1
    return c


# Метод итераций
def simple_iteration(phi, initial_guess, epsilon, max_iter=100):
    x0 = initial_guess
    x1 = phi(x0)
    iter_count = 0
    while not np.isnan(x1) and abs(x1 - x0) > epsilon and iter_count < max_iter:
        x0 = x1
        x1 = phi(x0)
        iter_count += 1
    return x1


epsilon = 1e-6
a, b = 1.01, 2.0
initial_guess = 1.1

root_bisection = bisection_method(f, a, b, epsilon)
root_newton = newton_method(f, df, initial_guess, epsilon)
root_secant = secant_method(f, a, b, epsilon)
root_simple_iteration = simple_iteration(lambda x: phi(x), initial_guess, epsilon)

print("Метод бисекции:", root_bisection)
print("Метод Ньютона:", root_newton)
print("Метод секущих:", root_secant)
print("Метод итераций:", root_simple_iteration)
