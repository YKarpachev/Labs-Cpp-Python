import numpy as np
import scipy.integrate as integrate


# Определение функции f2(x)
def f2(x):
    return np.exp(-2 * x) * np.sin(26 * x)


# Численное интегрирование с использованием библиотеки scipy
int2_value, _ = integrate.quad(f2, 0, np.inf)  # Интегрирование от 0 до бесконечности

# Вывод результата
print(f"Численное значение: {int2_value:.7f}")
