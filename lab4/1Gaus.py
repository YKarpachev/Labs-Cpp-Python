import numpy as np


def gauss_elimination(A, B):
    n = len(B)
    for i in range(n):
        max_row = i
        for k in range(i + 1, n):
            if abs(A[k][i]) > abs(A[max_row][i]):
                max_row = k
        A[[i, max_row]] = A[[max_row, i]]
        B[i], B[max_row] = B[max_row], B[i]

        for k in range(i + 1, n):
            factor = A[k][i] / A[i][i]
            A[k, i:] -= factor * A[i, i:]
            B[k] -= factor * B[i]

    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (B[i] - np.dot(A[i, i + 1 :], x[i + 1 :])) / A[i, i]
    return x


A = np.array([[7, 8, 4, -6], [-1, 6, -2, -6], [2, 9, 6, -4], [5, 9, 1, 1]], dtype=float)
B = np.array([-126, -42, -115, -67], dtype=float)

solution = gauss_elimination(A, B)
print("Метод Гауса:")
print(solution)
