#include <iostream>
#include <vector>

// Структура для хранения коэффициентов сплайна и узла x
struct SplineSegment {
  double a, b, c, d, x;
};

// Функция для построения кубического сплайна
std::vector<SplineSegment> constructCubicSpline(const std::vector<double> &x,
                                                const std::vector<double> &y) {
  int n = x.size() - 1;
  std::vector<double> h(n);
  std::vector<double> alpha(n);
  std::vector<double> l(n + 1, 1.0);
  std::vector<double> mu(n, 0.0);
  std::vector<double> z(n + 1, 0.0);

  // Вычисление шагов и альфа-коэффициентов
  for (int i = 0; i < n; ++i) {
    h[i] = x[i + 1] - x[i];
  }
  for (int i = 1; i < n; ++i) {
    alpha[i] =
        (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
  }

  // Прогоночный метод для системы уравнений
  for (int i = 1; i < n; ++i) {
    l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
    mu[i] = h[i] / l[i];
    z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
  }

  std::vector<double> b(n), c(n + 1), d(n);
  c[n] = 0.0; // Boundary condition
  c[0] = 0.0; // Boundary condition

  // Вычисление коэффициентов c, b и d
  for (int j = n - 1; j >= 0; --j) {
    c[j] = z[j] - mu[j] * c[j + 1];
    b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
    d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
  }

  // Создание сегментов сплайна
  std::vector<SplineSegment> spline(n);
  for (int i = 0; i < n; ++i) {
    spline[i] = {y[i], b[i], c[i], d[i], x[i]};
  }

  return spline;
}

// Функция для вычисления значения сплайна в точке x
double evaluateSpline(const std::vector<SplineSegment> &spline, double x) {
  int n = spline.size();
  for (int i = 0; i < n; ++i) {
    if (x >= spline[i].x && x <= spline[i + 1].x) {
      double dx = x - spline[i].x;
      return spline[i].a + spline[i].b * dx + spline[i].c * dx * dx +
             spline[i].d * dx * dx * dx;
    }
  }
  return 0.0; // Return 0.0 if x is out of bounds (optional)
}

int main() {
  // Входные данные для сплайна
  std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
  std::vector<double> y = {0.0, 0.5, 0.86603, 1.0, 0.86603};

  // Построение сплайна
  std::vector<SplineSegment> spline = constructCubicSpline(x, y);

  // Точка для вычисления значения сплайна
  double x_star = 1.5;
  double y_star = evaluateSpline(spline, x_star);

  // Вывод результата
  std::cout << "Сплайн в x* = " << x_star << " равен y* = " << y_star
            << std::endl;

  return 0;
}
