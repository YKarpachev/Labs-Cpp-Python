#include <iostream>
#include <vector>

// Функция для решения системы линейных уравнений методом прогонки (метод
// Томаса)
std::vector<double> thomasAlgorithm(const std::vector<double> &a,
                                    const std::vector<double> &b,
                                    const std::vector<double> &c,
                                    const std::vector<double> &d) {
  int n = d.size();
  std::vector<double> c_prime(n - 1);
  std::vector<double> d_prime(n);

  // Прямой ход метода прогонки
  c_prime[0] = c[0] / b[0];
  d_prime

      [0] = d[0] / b[0];

  for (int i = 1; i < n - 1; ++i) {
    c_prime[i] = c[i] / (b[i] - a[i] * c_prime[i - 1]);
  }
  for (int i = 1; i < n; ++i) {
    d_prime[i] =
        (d[i] - a[i] * d_prime[i - 1]) / (b[i] - a[i] * c_prime[i - 1]);
  }

  // Обратный ход метода прогонки
  std::vector<double> x(n);
  x[n - 1] = d_prime[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    x[i] = d_prime[i] - c_prime[i] * x[i + 1];
  }

  return x;
}

int main() {
  // Коэффициенты матрицы A и вектора B
  std::vector<double> a = {0, 2, -8, -6, 9}; // нижняя диагональ
  std::vector<double> b = {-6, 10, 18, 17, 14}; // главная диагональ
  std::vector<double> c = {6, -7, 9, -6, 0}; // верхняя диагональ
  std::vector<double> d = {30, -31, 108, -114, 124}; // вектор правой части

  // Решение системы методом Томаса
  std::vector<double> solution = thomasAlgorithm(a, b, c, d);

  // Вывод решения
  std::cout << "Solution using Thomas method:\n";
  for (double xi : solution) {
    std::cout << xi << " ";
  }
  std::cout << std::endl;

  return 0;
}
