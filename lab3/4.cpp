#include <cmath>
#include <iostream>

// Функция для суммирования функционального ряда при заданном значении x и
// точности
double sum_functional_series(double x, double tol = 1e-6) {
  int k = 1;              // Счетчик членов ряда
  double total_sum = 0.0; // Переменная для хранения суммы ряда
  double term = INFINITY; // Переменная для хранения текущего члена ряда

  while (fabs(term) > tol) {
    term =
        pow(-1, k) / (sin(k * x) + 26 + k * k); // Вычисляем текущий член ряда
    total_sum += term; // Добавляем текущий член к сумме
    k++;               // Увеличиваем счетчик
  }
  return total_sum;
}

int main() {
  double x = 1.0; // Значение x для вычисления функционального ряда
  double tol = 1e-6; // Заданная точность

  // Вычисление суммы функционального ряда
  double functional_series_sum = sum_functional_series(x, tol);

  // Вывод результата
  std::cout << "Сумма функционального ряда при x=" << x << ": "
            << functional_series_sum << std::endl;

  return 0;
}
