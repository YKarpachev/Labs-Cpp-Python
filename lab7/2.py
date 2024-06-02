import numpy as np
import matplotlib.pyplot as plt


# Функция для вычисления производной dy/dx
def dydx(x, y):
    return -2 * x * y + x * np.exp(-(x**2))


# Функция для вычисления точного решения
def exact_solution(x):
    return (np.exp(-(x**2)) * x**2) / 2


# Метод Эйлера-Коши для численного решения дифференциального уравнения
def euler_cauchy(x0, y0, xn, h):
    x = np.arange(x0, xn + h, h)  # Создание массива значений x
    y = np.zeros_like(x)  # Массив значений y (численное решение)
    y_exact = np.zeros_like(x)  # Массив значений точного решения
    error = np.zeros_like(x)  # Массив значений ошибки

    y[0] = y0  # Начальное значение y
    y_exact[0] = exact_solution(x0)  # Начальное значение точного решения
    error[0] = np.abs(y[0] - y_exact[0])  # Начальная ошибка

    # Основной цикл метода Эйлера-Коши
    for i in range(1, len(x)):
        y_pred = y[i - 1] + h * dydx(x[i - 1], y[i - 1])  # Предсказанное значение y
        y[i] = y[i - 1] + (h / 2) * (
            dydx(x[i - 1], y[i - 1]) + dydx(x[i], y_pred)
        )  # Корректировка y
        y_exact[i] = exact_solution(x[i])  # Вычисление точного решения
        error[i] = np.abs(y[i] - y_exact[i])  # Вычисление ошибки

    return x, y, y_exact, error


# Начальные условия и шаг интегрирования
x0 = 0.0
y0 = 0.0
xn = 1.0
h = 0.1

# Получение численного и точного решений, а также ошибок
x, y, y_exact, error = euler_cauchy(x0, y0, xn, h)

# Вывод результатов
print("x\t\ty (Эйлер-Коши)\ty (Точное)\tРазница")
for i in range(len(x)):
    print(f"{x[i]:.1f}\t\t{y[i]:.6f}\t\t{y_exact[i]:.6f}\t\t{error[i]:.6f}")

# Построение графика численного и точного решений
plt.plot(x, y, "bo-", label="Эйлер-Коши")
plt.plot(x, y_exact, "r--", label="Точное")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("Эйлер-Коши и Точное решение")
plt.grid()
plt.show()
