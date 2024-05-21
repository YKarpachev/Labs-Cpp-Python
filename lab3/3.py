def sum_numerical_series(tol=1e-6):
    k = 1
    total_sum = 0
    term = float("inf")
    while abs(term) > tol:
        term = 26 / 2 ** (k - 1) + (-1) ** (k - 1) / (2 * 3 ** (k - 1))
        total_sum += term
        k += 1
    return total_sum


numerical_series_sum = sum_numerical_series()

print(f"Сумма числового ряда: {numerical_series_sum:.7f}")
