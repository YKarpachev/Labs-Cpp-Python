#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

// Функция для вычисления правой части дифференциального уравнения
double f(double x, double y) { return -2 * x * y + x * exp(-x * x); }

int main() {
  // Начальные условия
  double x0 = 0.0;
  double y0 = 0.0;
  double h = 0.1;
  double xn = 1.0;

  // Число шагов
  int n = static_cast<int>((xn - x0) / h);

  // Векторы для хранения значений x и y
  std::vector<double> x(n + 1);
  std::vector<double> y(n + 1);
  x[0] = x0;
  y[0] = y0;

  // Реализация метода Эйлера-Коши
  for (int i = 0; i < n; ++i) {
    double k1 = h * f(x[i], y[i]);
    double k2 = h * f(x[i] + h, y[i] + k1);
    y[i + 1] = y[i] + 0.5 * (k1 + k2);
    x[i + 1] = x[i] + h;
  }

  // Вычисление точного решения
  std::vector<double> y_exact(n + 1);
  std::vector<double> errors(n + 1);
  for (int i = 0; i <= n; ++i) {
    y_exact[i] = (exp(-x[i] * x[i]) * x[i] * x[i]) / 2;
    errors[i] = std::abs(y[i] - y_exact[i]);
  }

  // Вывод таблицы
  std::cout << std::setw(10) << "x" << std::setw(15) << "y (Euler-Cauchy)"
            << std::setw(15) << "y (Exact)" << std::setw(15) << "Error"
            << std::endl;
  for (int i = 0; i <= n; ++i) {
    std::cout << std::setw(10) << x[i] << std::setw(15) << y[i] << std::setw(15)
              << y_exact[i] << std::setw(15) << errors[i] << std::endl;
  }

  return 0;
}
