import numpy as np
import matplotlib.pyplot as plt
import pandas as pd


# Функция для вычисления правой части дифференциального уравнения
def f(x, y):
    return -y + np.exp(x)


# Начальные условия
x0 = 0
y0 = 1.5
h = 0.1
xn = 1

# Число шагов
n = int((xn - x0) / h)

# Массивы для хранения значений x и y
x = np.zeros(n + 1)
y = np.zeros(n + 1)
x[0] = x0
y[0] = y0

# Реализация метода Эйлера
for i in range(n):
    y[i + 1] = y[i] + h * f(x[i], y[i])
    x[i + 1] = x[i] + h

# Точное решение
y_exact = (np.exp(x) / 2) + np.exp(-x)

# Расчёт погрешности
errors = np.abs(y - y_exact)

# Создание таблицы
data = {"x": x, "y (Euler)": y, "y (Exact)": y_exact, "Error": errors}
df = pd.DataFrame(data)

# Вывод таблицы
print(df)

# Построение графиков
plt.plot(x, y, "o-", label="Метод Эйлера")
plt.plot(x, y_exact, "-", label="Точное решение")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("Решение задачи Коши методом Эйлера")
plt.show()
