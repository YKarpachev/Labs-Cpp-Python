import numpy as np

A = np.array([[7, 8, 4, -6], [-1, 6, -2, -6], [2, 9, 6, -4], [5, 9, 1, 1]])
B = np.array([-126, -42, -115, -67])

solution = np.linalg.solve(A, B)

print("Матричный метод:")
print(solution)
