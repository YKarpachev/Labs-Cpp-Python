import numpy as np

# Задаем коэффициенты системы
A = np.array([[10, -1, -2, 5], [4, 28, 7, 9], [6, 5, -23, 4], [1, 4, 5, -15]])

# Задаем правую часть уравнений
b = np.array([-99, 0, 67, 58])

# Начальное приближение
x = np.zeros_like(b)

# Допустимая погрешность
tolerance = 0.01

# Максимальное количество итераций
max_iterations = 1000


# Метод Зейделя
def seidel(A, b, x, tolerance, max_iterations):
    n = len(A)
    for k in range(max_iterations):
        x_new = np.copy(x)
        for i in range(n):
            s1 = np.dot(A[i, :i], x_new[:i])
            s2 = np.dot(A[i, i + 1 :], x[i + 1 :])
            x_new[i] = (b[i] - s1 - s2) / A[i, i]
        # Проверка сходимости
        if np.linalg.norm(x_new - x, ord=np.inf) < tolerance:
            return x_new
        x = x_new
    raise Exception("Метод не сошелся")


# Решение системы
solution = seidel(A, b, x, tolerance, max_iterations)
print("Решение системы методом Зейделя:", solution)
