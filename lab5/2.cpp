#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления разделенных разностей
vector<double> dividedDifferences(const vector<double> &x,
                                  const vector<double> &y) {
  int n = x.size();
  vector<double> coef(y);

  for (int j = 1; j < n; ++j) {
    for (int i = n - 1; i >= j; --i) {
      coef[i] = (coef[i] - coef[i - 1]) / (x[i] - x[i - j]);
    }
  }
  return coef;
}

// Функция для вычисления значения интерполяционного многочлена Ньютона
double newtonInterpolation(const vector<double> &x, const vector<double> &coef,
                           double xi) {
  double result = coef.back();
  for (int i = coef.size() - 2; i >= 0; --i) {
    result = result * (xi - x[i]) + coef[i];
  }
  return result;
}

int main() {
  // Заданные узлы интерполяции
  vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
  vector<double> y = {cos(0.1 * M_PI), cos(0.2 * M_PI), cos(0.3 * M_PI),
                      cos(0.4 * M_PI)};

  // Вычисление разделенных разностей
  vector<double> coef = dividedDifferences(x, y);

  // Точка, в которой вычисляем значение интерполяционного многочлена
  double x_star = 0.25 * M_PI;

  // Вычисление значения интерполяционного многочлена в точке x*
  double y_interp = newtonInterpolation(x, coef, x_star);

  // Вычисление истинного значения функции в точке x*
  double y_true = cos(x_star);

  // Вычисление погрешности интерполяции
  double error = abs(y_true - y_interp);

  // Вывод результатов
  cout << "Значение интерполяционного многочлена в точке x* = " << x_star
       << ": " << y_interp << endl;
  cout << "Истинное значение функции в точке x* = " << x_star << ": " << y_true
       << endl;
  cout << "Погрешность интерполяции: " << error << endl;

  return 0;
}
