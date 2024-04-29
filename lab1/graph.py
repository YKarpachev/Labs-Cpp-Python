import numpy as np
import matplotlib.pyplot as plt


def f(x):
    if x <= 1:
        return np.nan
    else:
        return np.exp(-x) - np.sqrt(x - 1)


x = np.linspace(1, 3, 400)
y = np.array([f(xi) for xi in x])

plt.figure(figsize=(8, 4))
plt.plot(x, y, label="f(x) = exp(-x) - sqrt(x - 1)")
plt.axhline(0, color="gray", lw=0.5)
plt.axvline(0, color="gray", lw=0.5)
plt.title("График функции f(x) = exp(-x) - sqrt(x - 1)")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.show()
