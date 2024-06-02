#include <cmath>
#include <iostream>
#include <limits>

// Функция для вычисления значения целевой функции
double f(double x1, double x2) {
  return x1 + 2 * x2 + 4 * std::sqrt(1 + x1 * x1 + x2 * x2);
}

// Градиент функции
void gradient(double x1, double x2, double &grad1, double &grad2) {
  double denominator = std::sqrt(1 + x1 * x1 + x2 * x2);
  grad1 = 1 + 4 * x1 / denominator;
  grad2 = 2 + 4 * x2 / denominator;
}

// Метод наискорейшего спуска
void steepest_descent(double x1, double x2, int max_iters = 1000,
                      double tol = 1e-6) {
  double grad1, grad2, alpha, x1_new, x2_new;
  for (int iter = 0; iter < max_iters; ++iter) {
    gradient(x1, x2, grad1, grad2);
    alpha = 0.1; // начальный шаг (можно улучшить с помощью поиска на отрезке)
    x1_new = x1 - alpha * grad1;
    x2_new = x2 - alpha * grad2;

    if (std::sqrt((x1_new - x1) * (x1_new - x1) +
                  (x2_new - x2) * (x2_new - x2)) < tol) {
      break;
    }

    x1 = x1_new;
    x2 = x2_new;
  }
  std::cout << "Оптимальное значение функции f: " << f(x1, x2)
            << " при x1: " << x1 << ", x2: " << x2 << std::endl;
}

int main() {
  double x1 = 0.0, x2 = 0.0; // начальное приближение
  steepest_descent(x1, x2);
  return 0;
}
