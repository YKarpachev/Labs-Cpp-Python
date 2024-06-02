#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Функция для умножения матриц
vector<vector<double>> multiplyMatrices(const vector<vector<double>> &a,
                                        const vector<vector<double>> &b) {
  int rows = a.size();
  int cols = b[0].size();
  int inner = b.size();
  vector<vector<double>> result(rows, vector<double>(cols, 0));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      for (int k = 0; k < inner; ++k) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  return result;
}

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>> &matrix) {
  for (const auto &row : matrix) {
    for (double val : row) {
      cout << setw(10) << val << " ";
    }
    cout << endl;
  }
}

// Функция для вычисления обратной матрицы (метод Гаусса-Жордана)
vector<vector<double>> inverseMatrix(vector<vector<double>> matrix) {
  int n = matrix.size();
  vector<vector<double>> inverse(n, vector<double>(n, 0));

  // Создание расширенной матрицы (исходная матрица | единичная матрица)
  for (int i = 0; i < n; ++i) {
    inverse[i][i] = 1;
  }

  // Прямой ход
  for (int i = 0; i < n; ++i) {
    double pivot = matrix[i][i];
    for (int j = 0; j < n; ++j) {
      matrix[i][j] /= pivot;
      inverse[i][j] /= pivot;
    }
    for (int k = 0; k < n; ++k) {
      if (k != i) {
        double factor = matrix[k][i];
        for (int j = 0; j < n; ++j) {
          matrix[k][j] -= factor * matrix[i][j];
          inverse[k][j] -= factor * inverse[i][j];
        }
      }
    }
  }

  return inverse;
}

int main() {
  vector<vector<double>> matrix = {
      {7, 8, 4, -6}, {-1, 6, -2, -6}, {2, 9, 6, -4}, {5, 9, 1, 1}};

  vector<vector<double>> constants = {{-126}, {-42}, {-115}, {-67}};

  vector<vector<double>> invMatrix = inverseMatrix(matrix);

  cout << "Решение системы уравнений:" << endl;
  vector<vector<double>> result = multiplyMatrices(invMatrix, constants);
  printMatrix(result);

  return 0;
}
