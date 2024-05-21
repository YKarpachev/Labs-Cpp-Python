#include <cmath>
#include <iostream>

double f1(double x) { return pow(x, 4) / (26 + x * x); }

double rectangleMethod(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n;
  double result = 0.0;
  for (int i = 0; i < n; ++i) {
    result += f(a + i * h);
  }
  return result * h;
}

double trapezoidalMethod(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n;
  double result = (f(a) + f(b)) / 2.0;
  for (int i = 1; i < n; ++i) {
    result += f(a + i * h);
  }
  return result * h;
}

double simpsonMethod(double (*f)(double), double a, double b, int n) {
  if (n % 2 == 1)
    ++n;
  double h = (b - a) / n;
  double result = f(a) + f(b);
  for (int i = 1; i < n; i += 2) {
    result += 4 * f(a + i * h);
  }
  for (int i = 2; i < n - 1; i += 2) {
    result += 2 * f(a + i * h);
  }
  return result * h / 3.0;
}

int main() {
  double a1 = 1.0, b1 = 2.0;
  int n = 100000;

  double int1_rect = rectangleMethod(f1, a1, b1, n);
  double int1_trap = trapezoidalMethod(f1, a1, b1, n);
  double int1_simp = simpsonMethod(f1, a1, b1, n);

  std::cout << "Метод прямоугольников: " << int1_rect << std::endl;
  std::cout << "Метод трапеций: " << int1_trap << std::endl;
  std::cout << "Метод Симпсона: " << int1_simp << std::endl;

  return 0;
}
