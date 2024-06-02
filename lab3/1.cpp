#include <cmath>
#include <iostream>

// Определение функции f1(x)
double f1(double x) { return pow(x, 4) / (26 + x * x); }

// Метод прямоугольников для численного интегрирования
double rectangleMethod(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n; // Шаг разбиения
  double result = 0.0; // Переменная для хранения результата
  for (int i = 0; i < n; ++i) {
    result += f(a + i * h); // Суммируем значения функции в разбиениях
  }
  return result * h; // Умножаем на шаг разбиения
}

// Метод трапеций для численного интегрирования
double trapezoidalMethod(double (*f)(double), double a, double b, int n) {
  double h = (b - a) / n; // Шаг разбиения
  double result =
      (f(a) + f(b)) /
      2.0; // Переменная для хранения результата с учетом крайних значений
  for (int i = 1; i < n; ++i) {
    result += f(a + i * h); // Суммируем значения функции в разбиениях
  }
  return result * h; // Умножаем на шаг разбиения
}

// Метод Симпсона для численного интегрирования
double simpsonMethod(double (*f)(double), double a, double b, int n) {
  if (n % 2 == 1)
    ++n; // Увеличиваем n, если оно нечетное, так как метод Симпсона требует
         // четное количество разбиений
  double h = (b - a) / n; // Шаг разбиения
  double result =
      f(a) +
      f(b); // Переменная для хранения результата с учетом крайних значений
  for (int i = 1; i < n; i += 2) {
    result += 4 * f(a + i * h); // Учет значений в нечетных разбиениях
  }
  for (int i = 2; i < n - 1; i += 2) {
    result += 2 * f(a + i * h); // Учет значений в четных разбиениях
  }
  return result * h / 3.0; // Умножаем на шаг разбиения и делим на 3
}

int main() {
  double a1 = 1.0, b1 = 2.0; // Нижний и верхний пределы интегрирования
  int n = 100000; // Количество разбиений

  // Вычисление интегралов методами прямоугольников, трапеций и Симпсона
  double int1_rect = rectangleMethod(f1, a1, b1, n);
  double int1_trap = trapezoidalMethod(f1, a1, b1, n);
  double int1_simp = simpsonMethod(f1, a1, b1, n);

  // Вывод результатов
  std::cout << "Метод прямоугольников: " << int1_rect << std::endl;
  std::cout << "Метод трапеций: " << int1_trap << std::endl;
  std::cout << "Метод Симпсона: " << int1_simp << std::endl;

  return 0;
}
