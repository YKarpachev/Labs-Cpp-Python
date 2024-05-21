def sum_functional_series(x, tol=1e-6):
    k = 1
    total_sum = 0
    term = float("inf")
    while abs(term) > tol:
        term = (-1) ** k / (np.sin(k * x) + 26 + k**2)
        total_sum += term
        k += 1
    return total_sum


x_value = 1  # замените на нужное значение x
functional_series_sum = sum_functional_series(x_value)

print(f"Сумма функционального ряда при x={x_value}: {functional_series_sum:.7f}")
