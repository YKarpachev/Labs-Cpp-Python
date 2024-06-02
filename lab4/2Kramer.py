import numpy as np


# Функция для вычисления определителя матрицы
def determinant(A):
    return np.linalg.det(A)


# Функция для решения системы линейных уравнений методом Крамера
def kramer(A, B):
    n = len(B)
    det_A = determinant(A)
    if det_A == 0:
        raise ValueError("Матрица вырождена, решение невозможно.")

    x = np.zeros(n)
    for i in range(n):
        A_copy = A.copy()
        A_copy[:, i] = B
        x[i] = determinant(A_copy) / det_A
    return x


# Коэффициенты матрицы A и вектора B
A = np.array([[7, -3, 2], [1, -8, 1], [6, -6, 2]], dtype=float)
B = np.array([1, 1, -1], dtype=float)

# Решение системы методом Крамера
solution = kramer(A, B)
print("Метод Крамера:")
print(solution)
