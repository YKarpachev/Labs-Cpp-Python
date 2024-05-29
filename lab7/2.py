import numpy as np
import matplotlib.pyplot as plt


# Function to compute the derivative y'
def dydx(x, y):
    return -2 * x * y + x * np.exp(x**2)


# Exact solution function
def exact_solution(x):
    return (np.exp(-(x**2)) * x**2) / 2


# Euler-Cauchy method
def euler_cauchy(x0, y0, xn, h):
    x = np.arange(x0, xn + h, h)
    y = np.zeros_like(x)
    y_exact = np.zeros_like(x)
    error = np.zeros_like(x)

    y[0] = y0
    y_exact[0] = exact_solution(x0)
    error[0] = np.abs(y[0] - y_exact[0])

    for i in range(1, len(x)):
        y_pred = y[i - 1] + h * dydx(x[i - 1], y[i - 1])
        y[i] = y[i - 1] + (h / 2) * (dydx(x[i - 1], y[i - 1]) + dydx(x[i], y_pred))
        y_exact[i] = exact_solution(x[i])
        error[i] = np.abs(y[i] - y_exact[i])

    return x, y, y_exact, error


# Initial conditions and step size
x0 = 0.0
y0 = 0.0
xn = 1.0
h = 0.1

# Solve the ODE
x, y, y_exact, error = euler_cauchy(x0, y0, xn, h)

# Print results
print("x\t\ty (Эйлер-Коши)\ty (Точное)\tРазница")
for i in range(len(x)):
    print(f"{x[i]:.1f}\t\t{y[i]:.6f}\t\t{y_exact[i]:.6f}\t\t{error[i]:.6f}")

# Plot the results
plt.plot(x, y, "bo-", label="Эйлер-Коши")
plt.plot(x, y_exact, "r--", label="Точное")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("Эйлер-Коши и Точное решение")
plt.grid()
plt.show()
