# Функция для суммирования числового ряда с заданной точностью
def sum_numerical_series(tol=1e-6):
    k = 1  # Счетчик членов ряда
    total_sum = 0  # Переменная для хранения суммы ряда
    term = float("inf")  # Переменная для хранения текущего члена ряда

    while abs(term) > tol:
        term = 26 / 2 ** (k - 1) + (-1) ** (k - 1) / (
            2 * 3 ** (k - 1)
        )  # Вычисляем текущий член ряда
        total_sum += term  # Добавляем текущий член к сумме
        k += 1  # Увеличиваем счетчик
    return total_sum


# Вычисление суммы числового ряда
numerical_series_sum = sum_numerical_series()

# Вывод результата
print(f"Сумма числового ряда: {numerical_series_sum:.7f}")
