#include <cmath>
#include <iomanip>
#include <iostream>

double sumFunctionalSeries(double x, double tol = 1e-6) {
  int k = 1;
  double total_sum = 0.0;
  double term = std::numeric_limits<double>::infinity();
  while (fabs(term) > tol) {
    term = pow(-1, k) / (sin(k * x) + 26 + k * k);
    total_sum += term;
    ++k;
  }
  return total_sum;
}

int main() {
  double x_value = 1.0; // замените на нужное значение x
  double tol = 1e-6;
  double functional_series_sum = sumFunctionalSeries(x_value, tol);

  std::cout << std::fixed << std::setprecision(7);
  std::cout << "Сумма функционального ряда при x=" << x_value << ": "
            << functional_series_sum << std::endl;

  return 0;
}
