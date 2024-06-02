#include <cmath>
#include <iostream>

// Функция для суммирования числового ряда с заданной точностью
double sum_numerical_series(double tol = 1e-6) {
  int k = 1;              // Счетчик членов ряда
  double total_sum = 0.0; // Переменная для хранения суммы ряда
  double term = INFINITY; // Переменная для хранения текущего члена ряда

  while (fabs(term) > tol) {
    term = 26 / pow(2, k - 1) +
           pow(-1, k - 1) / (2 * pow(3, k - 1)); // Вычисляем текущий член ряда
    total_sum += term; // Добавляем текущий член к сумме
    k++;               // Увеличиваем счетчик
  }
  return total_sum;
}

int main() {
  double tol = 1e-6; // Заданная точность
                     // Вычисление суммы числового ряда
  double numerical_series_sum = sum_numerical_series(tol);

  // Вывод результата
  std::cout << "Сумма числового ряда: " << numerical_series_sum << std::endl;

  return 0;
}
