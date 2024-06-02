#include <cmath>
#include <iostream>
#include <vector>

// Функция для вычисления производной dy/dx
double dydx(double y, double x) { return -y + std::exp(x); }

// Функция для вычисления точного решения
double exactSolution(double x) { return 0.5 * std::exp(x) + std::exp(-x); }

int main() {
  double h = 0.1;  // Шаг интегрирования
  double x0 = 0.0; // Начальное значение x
  double y0 = 1.5; // Начальное значение y
  double xn = 1.0; // Конечное значение x

  // Векторы для хранения значений x, y, точного решения и ошибки
  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> y_exact;
  std::vector<double> error;

  // Инициализация начальных значений
  x.push_back(x0);
  y.push_back(y0);
  y_exact.push_back(exactSolution(x0));
  error.push_back(std::abs(y0 - y_exact.back()));

  int n = static_cast<int>((xn - x0) / h); // Количество шагов

  // Основной цикл метода Эйлера
  for (int i = 0; i < n; ++i) {
    double x_next = x[i] + h;
    double y_next = y[i] + h * dydx(y[i], x[i]);

    x.push_back(x_next);
    y.push_back(y_next);
    y_exact.push_back(exactSolution(x_next));
    error.push_back(std::abs(y_next - y_exact.back()));
  }

  // Вывод результатов
  std::cout << "x\ty (Эйлер)\ty (Точное)\tРазница\n";
  for (int i = 0; i < x.size(); ++i) {
    std::cout << x[i] << "\t" << y[i] << "\t" << y_exact[i] << "\t" << error[i]
              << "\n";
  }

  return 0;
}
