#include <iostream>
#include <vector>

struct SplineSegment {
  double a, b, c, d, x;
};

std::vector<SplineSegment> constructCubicSpline(const std::vector<double> &x,
                                                const std::vector<double> &y) {
  int n = x.size() - 1;
  std::vector<double> h(n);
  std::vector<double> alpha(n);
  std::vector<double> l(n + 1, 1.0);
  std::vector<double> mu(n, 0.0);
  std::vector<double> z(n + 1, 0.0);

  for (int i = 0; i < n; ++i) {
    h[i] = x[i + 1] - x[i];
    alpha[i] =
        (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
  }

  for (int i = 1; i < n; ++i) {
    l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
    mu[i] = h[i] / l[i];
    z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
  }

  std::vector<double> b(n), c(n + 1), d(n);

  for (int j = n - 1; j >= 0; --j) {
    c[j] = z[j] - mu[j] * c[j + 1];
    b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
    d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
  }

  std::vector<SplineSegment> spline(n);
  for (int i = 0; i < n; ++i) {
    spline[i] = {y[i], b[i], c[i], d[i], x[i]};
  }

  return spline;
}

double evaluateSpline(const std::vector<SplineSegment> &spline, double x) {
  int n = spline.size();
  for (int i = 0; i < n; ++i) {
    if (x >= spline[i].x && x <= spline[i + 1].x) {
      double dx = x - spline[i].x;
      return spline[i].a + spline[i].b * dx + spline[i].c * dx * dx +
             spline[i].d * dx * dx * dx;
    }
  }
  return 0.0;
}

int main() {
  std::vector<double> x = {0.0, 1.0, 2.0, 3.0, 4.0};
  std::vector<double> y = {0.0, 0.5, 0.86603, 1.0, 0.86603};

  std::vector<SplineSegment> spline = constructCubicSpline(x, y);

  double x_star = 1.5;
  double y_star = evaluateSpline(spline, x_star);

  std::cout << "Сплайн в x* = " << x_star << " равен y* = " << y_star
            << std::endl;

  return 0;
}
