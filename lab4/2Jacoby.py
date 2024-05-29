import numpy as np


def is_diagonally_dominant(A):
    for i in range(len(A)):
        sum_row = sum(abs(A[i][j]) for j in range(len(A)) if j != i)
        if abs(A[i][i]) < sum_row:
            return False
    return True


def jacobi(A, B, x_init, tol=1e-10, max_iterations=100000):
    if not is_diagonally_dominant(A):
        raise ValueError("Матрица не диагонально доминирующая.")

    n = len(B)
    x = x_init.copy()
    for iteration in range(max_iterations):
        x_new = np.zeros_like(x)
        for i in range(n):
            s = sum(A[i][j] * x[j] for j in range(n) if j != i)
            x_new[i] = (B[i] - s) / A[i][i]

        if np.linalg.norm(x_new - x) < tol:
            return x_new
        x = x_new
    raise ValueError("Не сходится")


A = np.array([[7, -3, 2], [1, -8, 1], [6, -6, 2]], dtype=float)
B = np.array([1, 1, -1], dtype=float)
x_init = np.zeros(len(B))

try:
    solution = jacobi(A, B, x_init)
    print("Метод якоби:")
    print(solution)
except ValueError as e:
    print(e)
