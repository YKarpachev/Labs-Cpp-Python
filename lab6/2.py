import numpy as np


def f(x):
    return x[0] + 2 * x[1] + 4 * np.sqrt(1 + x[0] ** 2 + x[1] ** 2)


def gradient(x):
    df_dx1 = 1 + (4 * x[0]) / np.sqrt(1 + x[0] ** 2 + x[1] ** 2)
    df_dx2 = 2 + (4 * x[1]) / np.sqrt(1 + x[0] ** 2 + x[1] ** 2)
    return np.array([df_dx1, df_dx2])


def gradient_descent(x0, lr=0.01, tol=1e-6, max_iter=1000):
    x = np.array(x0)
    for _ in range(max_iter):
        grad = gradient(x)
        x_new = x - lr * grad
        if np.linalg.norm(x_new - x) < tol:
            break
        x = x_new
    return x


x0 = [0.0, 0.0]  # начальное приблидение
solution = gradient_descent(x0)

print("решение найдено в:", solution)
