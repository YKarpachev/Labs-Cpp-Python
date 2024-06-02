#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки диагонального преобладания матрицы
bool isDiagonallyDominant(const vector<vector<double>> &matrix) {
  int n = matrix.size();
  for (int i = 0; i < n; ++i) {
    double sum = 0;
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        sum += fabs(matrix[i][j]);
      }
    }
    if (fabs(matrix[i][i]) < sum) {
      return false;
    }
  }
  return true;
}

bool isConverged(const vector<double> &x_old, const vector<double> &x_new,
                 double tolerance) {
  for (int i = 0; i < x_old.size(); ++i) {
    if (fabs(x_new[i] - x_old[i]) > tolerance) {
      return false;
    }
  }
  return true;
}

// Функция для решения системы уравнений методом Якоби
void jacobi(const vector<vector<double>> &matrix,
            const vector<double> &constants, double tolerance,
            int maxIterations) {
  if (!isDiagonallyDominant(matrix)) {
    throw invalid_argument("Матрица не диагонально доминирующая.");
  }

  int n = matrix.size();
  vector<double> x_old(n, 0);
  vector<double> x_new(n, 0);

  for (int iter = 0; iter < maxIterations; ++iter) {
    for (int i = 0; i < n; ++i) {
      double sum = constants[i];
      for (int j = 0; j < n; ++j) {
        if (i != j) {
          sum -= matrix[i][j] * x_old[j];
        }
      }
      x_new[i] = sum / matrix[i][i];
    }

    if (isConverged(x_old, x_new, tolerance)) {
      break;
    }

    x_old = x_new;
  }

  for (int i = 0; i < n; ++i) {
    cout << "x" << i + 1 << " = " << x_new[i] << endl;
  }
}

int main() {
  vector<vector<double>> matrix = {{7, -3, 2}, {1, -8, 1}, {6, -6, 2}};
  vector<double> constants = {1, 1, -1};
  double tolerance = 0.01;
  int maxIterations = 100;

  try {
    cout << "Решение системы уравнений методом Якоби:" << endl;
    jacobi(matrix, constants, tolerance, maxIterations);
  } catch (const invalid_argument &e) {
    cout << e.what() << endl;
  }

  return 0;
}
