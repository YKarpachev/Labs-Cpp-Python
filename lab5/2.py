import numpy as np


# Функция для вычисления коэффициентов интерполяционного многочлена Ньютона
def newton_interpolating_polynomial(x, y):
    n = len(x)
    coef = np.zeros([n, n])
    coef[:, 0] = y

    for j in range(1, n):
        for i in range(n - j):
            coef[i, j] = (coef[i + 1, j - 1] - coef[i, j - 1]) / (x[i + j] - x[i])

    return coef[0, :]


# Функция для вычисления значения многочлена Ньютона в точке x
def newton_polynomial(x_data, coef, x):
    n = len(x_data) - 1
    p = coef[n]
    for k in range(1, n + 1):
        p = coef[n - k] + (x - x_data[n - k]) * p
    return p


# Входные данные
x_data = np.array([0.1 * np.pi, 0.2 * np.pi, 0.3 * np.pi, 0.4 * np.pi])
y_data = np.cos(x_data)

# Вычисление коэффициентов интерполяционного многочлена
coef = newton_interpolating_polynomial(x_data, y_data)

# Точка для вычисления значения многочлена
x_star = 0.25 * np.pi
y_star = newton_polynomial(x_data, coef, x_star)
exact_y_star = np.cos(x_star)

# Вычисление погрешности
error = np.abs(y_star - exact_y_star)

# Вывод результата
print(f"Интерполяционный многочлен в x* = {x_star} равен y* = {y_star}")
print(f"Точное значение в x* = {x_star} равно y* = {exact_y_star}")
print(f"Погрешность = {error}")
