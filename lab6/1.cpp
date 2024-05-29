#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

double f(const std::vector<double> &x) {
  return x[0] + 5 * x[1] + std::exp(x[0] * x[0] + x[1] * x[1]);
}

std::vector<double> coordinateDescent(std::vector<double> x0, double tol = 1e-6,
                                      int max_iter = 1000) {
  int n = x0.size();
  std::vector<double> x = x0;
  double step_size = 1.0;

  for (int iter = 0; iter < max_iter; ++iter) {
    std::vector<double> x_old = x;
    for (int i = 0; i < n; ++i) {
      std::vector<double> x_temp = x;
      x_temp[i] += step_size;
      if (f(x_temp) < f(x)) {
        x[i] += step_size;
      } else {
        x_temp[i] -= 2 * step_size;
        if (f(x_temp) < f(x)) {
          x[i] -= step_size;
        }
      }
    }
    double norm = 0.0;
    for (int i = 0; i < n; ++i) {
      norm += std::pow(x[i] - x_old[i], 2);
    }
    if (std::sqrt(norm) < tol) {
      break;
    }
  }
  return x;
}

int main() {
  std::vector<double> x0 = {0.0, 0.0}; // yfxfkmyjt ghb,kb;tybt
  std::vector<double> solution = coordinateDescent(x0);

  std::cout << "Решение найдено в: ";
  for (double xi : solution) {
    std::cout << xi << " ";
  }
  std::cout << std::endl;

  return 0;
}
