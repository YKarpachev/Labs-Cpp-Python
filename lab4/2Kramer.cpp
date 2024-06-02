#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Функция для вычисления определителя матрицы
double determinant(vector<vector<double>> matrix) {
  int n = matrix.size();
  double det = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double factor = matrix[j][i] / matrix[i][i];
      for (int k = i; k < n; ++k) {
        matrix[j][k] -= factor * matrix[i][k];
      }
    }
    det *= matrix[i][i];
  }
  return det;
}

// Функция для решения системы уравнений методом Крамера
void cramer(vector<vector<double>> matrix, vector<double> constants) {
  int n = matrix.size();
  double detA = determinant(matrix);

  vector<double> result(n);
  for (int i = 0; i < n; ++i) {
    vector<vector<double>> modifiedMatrix = matrix;
    for (int j = 0; j < n; ++j) {
      modifiedMatrix[j][i] = constants[j];
    }
    double detAi = determinant(modifiedMatrix);
    result[i] = detAi / detA;
  }

  for (int i = 0; i < n; ++i) {
    cout << "x" << i + 1 << " = " << result[i] << endl;
  }
}

int main() {
  vector<vector<double>> matrix = {{7, -3, 2}, {1, -8, 1}, {6, -6, 2}};

  vector<double> constants = {1, 1, -1};

  cout << "Решение системы уравнений методом Крамера:" << endl;
  cramer(matrix, constants);

  return 0;
}
