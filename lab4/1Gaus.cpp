#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>> &matrix) {
  for (const auto &row : matrix) {
    for (double val : row) {
      cout << setw(10) << val << " ";
    }
    cout << endl;
  }
}

// Функция для решения системы уравнений методом Гаусса
void gaussianElimination(vector<vector<double>> &matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; ++i) {
    // Прямой ход
    for (int j = i + 1; j < n; ++j) {
      double factor = matrix[j][i] / matrix[i][i];
      for (int k = i; k <= n; ++k) {
        matrix[j][k] -= factor * matrix[i][k];
      }
    }
  }
  // Обратный ход
  vector<double> result(n);
  for (int i = n - 1; i >= 0; --i) {
    result[i] = matrix[i][n] / matrix[i][i];
    for (int j = i - 1; j >= 0; --j) {
      matrix[j][n] -= matrix[j][i] * result[i];
    }
  }
  // Вывод решения
  for (int i = 0; i < n; ++i) {
    cout << "x" << i + 1 << " = " << result[i] << endl;
  }
}

int main() {
  vector<vector<double>> matrix = {{7, 8, 4, -6, -126},
                                   {-1, 6, -2, -6, -42},
                                   {2, 9, 6, -4, -115},
                                   {5, 9, 1, 1, -67}};

  gaussianElimination(matrix);

  return 0;
}
