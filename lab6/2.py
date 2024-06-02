import numpy as np


# Функция для вычисления значения целевой функции
def f(x):
    return x[0] + 2 * x[1] + 4 * np.sqrt(1 + x[0] ** 2 + x[1] ** 2)


# Функция для вычисления градиента целевой функции
def gradient(x):
    df_dx1 = 1 + (4 * x[0]) / np.sqrt(1 + x[0] ** 2 + x[1] ** 2)  # производная по x1
    df_dx2 = 2 + (4 * x[1]) / np.sqrt(1 + x[0] ** 2 + x[1] ** 2)  # производная по x2
    return np.array([df_dx1, df_dx2])


# Метод градиентного спуска
def gradient_descent(x0, lr=0.01, tol=1e-6, max_iter=1000):
    x = np.array(x0)  # начальное приближение
    for _ in range(max_iter):
        grad = gradient(x)  # вычисляем градиент в текущей точке
        x_new = x - lr * grad  # обновляем значение переменных
        if np.linalg.norm(x_new - x) < tol:  # проверяем условие остановки
            break
        x = x_new  # обновляем текущую точку
    return x


# Начальное приближение
x0 = [0.0, 0.0]
solution = gradient_descent(x0)  # поиск решения методом градиентного спуска

# Вывод найденного решения
optimal_value = f(solution)
print(
    "Оптимальное значение функции f:",
    optimal_value,
    "при x1:",
    solution[0],
    ", x2:",
    solution[1],
)
