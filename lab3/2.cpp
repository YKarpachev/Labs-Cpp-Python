#include <cmath>
#include <iomanip>
#include <iostream>

// Определение функции f2(x)
double f2(double x) { return exp(-2 * x) * sin(26 * x); }

// Функция для численного интегрирования с адаптивным шагом
double integrate(double (*f)(double), double a, double b, double tol = 1e-6) {
  double h = 1.0; // Начальный шаг
  double integral = 0.0; // Переменная для хранения интеграла
  double last_integral =
      0.0; // Переменная для хранения предыдущего значения интеграла

  do {
    last_integral = integral;
    integral = 0.0;
    for (double x = a; x < b; x += h) {
      integral += f(x) * h; // Суммируем значения функции на разбиениях
    }
    h /= 2.0; // Уменьшаем шаг вдвое
  } while (fabs(integral - last_integral) >
           tol); // Повторяем, пока разница не станет меньше заданной точности

  return integral;
}

int main() {
  double a2 = 0.0; // Нижний предел интегрирования
  double b2 =
      100.0; // Верхний предел интегрирования, приближающийся к бесконечности
  double tol = 1e-6; // Заданная точность

  // Вычисление интеграла
  double int2_value = integrate(f2, a2, b2, tol);

  // Вывод результата
  std::cout << std::fixed << std::setprecision(7);
  std::cout << "Численное значение: " << int2_value << std::endl;

  return 0;
}
