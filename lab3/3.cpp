#include <cmath>
#include <iomanip>
#include <iostream>

double sumNumericalSeries(double tol = 1e-6) {
  int k = 1;
  double total_sum = 0.0;
  double term = std::numeric_limits<double>::infinity();
  while (fabs(term) > tol) {
    term = 26 / pow(2, k - 1) + pow(-1, k - 1) / (2 * pow(3, k - 1));
    total_sum += term;
    ++k;
  }
  return total_sum;
}

int main() {
  double tol = 1e-6;
  double numerical_series_sum = sumNumericalSeries(tol);

  std::cout << std::fixed << std::setprecision(7);
  std::cout << "Сумма числового ряда: " << numerical_series_sum << std::endl;

  return 0;
}
