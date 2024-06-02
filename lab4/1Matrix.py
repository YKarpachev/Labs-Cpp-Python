import numpy as np

# Коэффициенты матрицы A и вектора B
A = np.array([[7, 8, 4, -6], [-1, 6, -2, -6], [2, 9, 6, -4], [5, 9, 1, 1]])
B = np.array([-126, -42, -115, -67])

# Решение системы линейных уравнений матричным методом (с использованием функции numpy.linalg.solve)
solution = np.linalg.solve(A, B)

print("Матричный метод:")
print(solution)
