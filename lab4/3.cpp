#include <cmath>
#include <iostream>
#include <vector>

std::vector<double> seidel(const std::vector<std::vector<double>> &A,
                           const std::vector<double> &B, double tol = 1e-2,
                           int max_iterations = 1000) {
  int n = B.size();
  std::vector<double> x(n, 0.0);
  for (int it = 0; it < max_iterations; ++it) {
    std::vector<double> x_new = x;
    for (int i = 0; i < n; ++i) {
      double s1 = 0.0;
      for (int j = 0; j < i; ++j) {
        s1 += A[i][j] * x_new[j];
      }
      double s2 = 0.0;
      for (int j = i + 1; j < n; ++j) {
        s2 += A[i][j] * x[j];
      }
      x_new[i] = (B[i] - s1 - s2) / A[i][i];
    }
    double norm = 0.0;
    for (int i = 0; i < n; ++i) {
      norm += std::pow(x_new[i] - x[i], 2);
    }
    if (std::sqrt(norm) < tol) {
      return x_new;
    }
    x = x_new;
  }
  throw std::runtime_error("Не сходится");
}

int main() {
  std::vector<std::vector<double>> A = {
      {10, -1, -2, 5}, {4, 28, 7, 9}, {6, 5, -23, 4}, {1, 4, 5, -15}};
  std::vector<double> B = {-99, 0, 67, 58};

  std::vector<double> solution = seidel(A, B);

  std::cout << "Зейдель:\n";
  for (double xi : solution) {
    std::cout << xi << " ";
  }
  std::cout << std::endl;

  return 0;
}
