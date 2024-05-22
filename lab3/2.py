import numpy as np
import scipy.integrate as integrate


def f2(x):
    return np.exp(-2 * x) * np.sin(26 * x)


int2_value, _ = integrate.quad(f2, 0, np.inf)

print(f"Численное значение: {int2_value:.7f}")
