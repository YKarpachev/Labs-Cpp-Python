#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

// Функция для вычисления значения целевой функции
double f(const std::vector<double> &x) {
  return x[0] + 5 * x[1] + std::exp(x[0] * x[0] + x[1] * x[1]);
}

// Функция для поиска оптимального шага вдоль направления координаты
double line_search(const std::vector<double> &x, int i,
                   double step_size = 1.0) {
  double alpha = 0.0;
  double min_alpha = std::numeric_limits<double>::infinity();
  double best_f = f(x);
  for (double a = -1.0; a <= 1.0; a += 0.01) {
    std::vector<double> x_temp = x;
    x_temp[i] += a * step_size;
    double f_temp = f(x_temp);
    if (f_temp < best_f) {
      best_f = f_temp;
      alpha = a * step_size;
    }
  }
  return alpha;
}

// Метод покоординатного спуска
std::vector<double> coordinateDescent(std::vector<double> x0, double tol = 1e-6,
                                      int max_iter = 1000) {
  int n = x0.size();          // количество переменных
  std::vector<double> x = x0; // текущие значения переменных

  // Основной цикл метода покоординатного спуска
  for (int iter = 0; iter < max_iter; ++iter) {
    std::vector<double> x_old = x; // сохраняем старые значения переменных
    for (int i = 0; i < n; ++i) {
      double alpha_opt = line_search(x, i);
      x[i] += alpha_opt;
    }
    // Вычисляем норму изменения переменных
    double norm = 0.0;
    for (int i = 0; i < n; ++i) {
      norm += std::pow(x[i] - x_old[i], 2);
    }
    // Если норма изменений меньше заданного порога, выходим из цикла
    if (std::sqrt(norm) < tol) {
      break;
    }
  }
  return x; // возвращаем найденное решение
}

int main() {
  std::vector<double> x0 = {0.0, 0.0}; // начальное приближение
  std::vector<double> solution =
      coordinateDescent(x0); // поиск решения методом покоординатного спуска

  // Вывод найденного решения
  std::cout << "Оптимальное значение функции f: " << f(solution)
            << " при x1: " << solution[0] << ", x2: " << solution[1]
            << std::endl;

  return 0;
}
