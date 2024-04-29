#include <cmath>
#include <iostream>
#include <limits>

// Функция и ее производные
double f(double x) {
  if (x <= 1)
    return std::numeric_limits<double>::quiet_NaN();
  return exp(-x) - sqrt(x - 1);
}

double df(double x) {
  if (x <= 1)
    return std::numeric_limits<double>::quiet_NaN();
  return -exp(-x) - 0.5 / sqrt(x - 1);
}

double phi(double x) {
  double lambda = 0.1;
  return x - lambda * (f(x) / (df(x) + std::numeric_limits<double>::epsilon()));
}

// Метод бисекции
double bisectionMethod(double a, double b, double epsilon, int max_iter = 100) {
  if (f(a) * f(b) >= 0 || std::isnan(f(a)) || std::isnan(f(b))) {
    std::cout << "Invalid input or no sign change" << std::endl;
    return std::numeric_limits<double>::quiet_NaN();
  }
  double c = a;
  int iter_count = 0;
  while ((b - a) / 2 > epsilon && iter_count < max_iter) {
    c = (a + b) / 2;
    if (f(c) == 0)
      break;
    if (f(a) * f(c) < 0)
      b = c;
    else
      a = c;
    iter_count++;
  }
  return c;
}

// Метод Ньютона
double newtonMethod(double x0, double epsilon, int max_iter = 50) {
  int iter_count = 0;
  double x1 = x0;
  while (iter_count < max_iter) {
    double deriv = df(x0);
    if (std::abs(deriv) < std::numeric_limits<double>::epsilon()) {
      std::cout << "Derivative too small, potential numerical issues."
                << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }
    x1 = x0 - f(x0) / deriv;
    if (std::abs(x1 - x0) <= epsilon)
      break;
    x0 = x1;
    iter_count++;
  }
  return x1;
}

// Метод секущих
double secantMethod(double a, double b, double epsilon, int max_iter = 50) {
  int iter_count = 0;
  double c;
  while (std::abs(b - a) > epsilon && iter_count < max_iter) {
    double denom = f(b) - f(a);
    if (std::abs(denom) < std::numeric_limits<double>::epsilon()) {
      std::cout << "Denominator too small" << std::endl;
      return std::numeric_limits<double>::quiet_NaN();
    }
    c = a - f(a) * (b - a) / denom;
    a = b;
    b = c;
    iter_count++;
  }
  return c;
}

// Метод итераций
double simpleIteration(double initial_guess, double epsilon,
                       int max_iter = 200) {
  double x0 = initial_guess;
  double x1 = phi(x0);
  int iter_count = 0;
  while (std::abs(x1 - x0) > epsilon && iter_count < max_iter) {
    x0 = x1;
    x1 = phi(x0);
    iter_count++;
  }
  return x1;
}

int main() {
  const double epsilon = 1e-6;
  const double a = 1.01, b = 2.0; // интервал 1.01 чтобы x - a не равнятось 0
  const double initial_guess = 1.1;

  double root_bisection = bisectionMethod(a, b, epsilon);
  double root_newton = newtonMethod(initial_guess, epsilon);
  double root_secant = secantMethod(a, b, epsilon);
  double root_simple_iteration = simpleIteration(initial_guess, epsilon);

  std::cout << "Метод бисекции: " << root_bisection << std::endl;
  std::cout << "Метод Ньютона: " << root_newton << std::endl;
  std::cout << "Метод секущих: " << root_secant << std::endl;
  std::cout << "Метод итераций: " << root_simple_iteration << std::endl;

  return 0;
}
