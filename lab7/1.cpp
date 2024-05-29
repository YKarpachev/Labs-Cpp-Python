#include <cmath>
#include <iostream>
#include <vector>

double dydx(double y, double x) { return -y + std::exp(x); }

double exactSolution(double x) { return 0.5 * std::exp(x) + std::exp(-x); }

int main() {
  double h = 0.1;
  double x0 = 0.0;
  double y0 = 1.5;
  double xn = 1.0;

  std::vector<double> x;
  std::vector<double> y;
  std::vector<double> y_exact;
  std::vector<double> error;

  x.push_back(x0);
  y.push_back(y0);
  y_exact.push_back(exactSolution(x0));
  error.push_back(std::abs(y0 - y_exact.back()));

  int n = static_cast<int>((xn - x0) / h);

  for (int i = 0; i < n; ++i) {
    double x_next = x[i] + h;
    double y_next = y[i] + h * dydx(y[i], x[i]);

    x.push_back(x_next);
    y.push_back(y_next);
    y_exact.push_back(exactSolution(x_next));
    error.push_back(std::abs(y_next - y_exact.back()));
  }

  std::cout << "x\ty (Эйлер)\ty (Точное)\tРазница\n";
  for (int i = 0; i < x.size(); ++i) {
    std::cout << x[i] << "\t" << y[i] << "\t" << y_exact[i] << "\t" << error[i]
              << "\n";
  }

  return 0;
}
