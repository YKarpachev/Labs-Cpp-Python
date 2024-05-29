import numpy as np


def cramer_rule(A, B):
    det_A = np.linalg.det(A)
    if det_A == 0:
        raise ValueError("Det = 0")
    n = len(B)
    x = np.zeros(n)
    for i in range(n):
        A_temp = np.copy(A)
        A_temp[:, i] = B
        x[i] = np.linalg.det(A_temp) / det_A
    return x


A = np.array([[7, -3, 2], [1, -8, 1], [6, -6, 2]])
B = np.array([1, 1, -1])

solution = cramer_rule(A, B)
print("Крамер:")
print(solution)
