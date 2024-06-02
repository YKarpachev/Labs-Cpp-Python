import numpy as np


# Функция для суммирования функционального ряда при заданном значении x и точности
def sum_functional_series(x, tol=1e-6):
    k = 1  # Счетчик членов ряда
    total_sum = 0  # Переменная для хранения суммы ряда
    term = float("inf")  # Переменная для хранения текущего члена ряда

    while abs(term) > tol:
        term = (-1) ** k / (np.sin(k * x) + 26 + k**2)  # Вычисляем текущий член ряда
        total_sum += term  # Добавляем текущий член к сумме
        k += 1
    return total_sum


x_value = 1  # Значение x для вычисления функционального ряда

functional_series_sum = sum_functional_series(x_value)

# Вывод результата
print(f"Сумма функционального ряда при x={x_value}: {functional_series_sum:.7f}")
