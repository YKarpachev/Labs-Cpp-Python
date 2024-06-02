from scipy.optimize import minimize_scalar
import numpy as np


def f(x):
    return x[0] + 5 * x[1] + np.exp(x[0] ** 2 + x[1] ** 2)


def coordinate_descent(f, x0, max_iters=100, tol=1e-6):
    x = np.array(x0)
    n = len(x)
    for _ in range(max_iters):
        for i in range(n):

            def func(alpha):
                x_temp = x.copy()
                x_temp[i] += alpha
                return f(x_temp)

            alpha_opt = minimize_scalar(func).x
            x[i] += alpha_opt
        if np.linalg.norm(x - x0) < tol:
            break
        x0 = x.copy()
    return x


x0 = [0.0, 0.0]  # начальное приближение
optimum = coordinate_descent(f, x0)
print(f"Оптимальное значение функции f: {f(optimum)} при x: {optimum}")
