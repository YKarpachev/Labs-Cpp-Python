#include <cmath>
#include <iomanip>
#include <iostream>

double f2(double x) { return exp(-2 * x) * sin(26 * x); }

double integrate(double (*f)(double), double a, double b, double tol = 1e-6) {
  double h = 1.0;
  double integral = 0.0;
  double last_integral = 0.0;

  do {
    last_integral = integral;
    integral = 0.0;
    for (double x = a; x < b; x += h) {
      integral += f(x) * h;
    }
    h /= 2.0;
  } while (fabs(integral - last_integral) > tol);

  return integral;
}

int main() {
  double a2 = 0.0;
  double b2 = 100.0; // большая граница для приближения бесконечности
  double tol = 1e-6;

  double int2_value = integrate(f2, a2, b2, tol);

  std::cout << std::fixed << std::setprecision(7);
  std::cout << "Численное значение: " << int2_value << std::endl;

  return 0;
}
