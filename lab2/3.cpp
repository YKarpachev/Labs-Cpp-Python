#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct Point {
  double x, y;
};

struct Ellipse {
  double h, k, a, b;
};

bool isPointOnEllipse(const Ellipse &ellipse, const Point &point) {
  return std::abs((std::pow(point.x - ellipse.h, 2) / std::pow(ellipse.a, 2)) +
                  (std::pow(point.y - ellipse.k, 2) / std::pow(ellipse.b, 2)) -
                  1) < 1e-6;
}

Point findFoci(const Ellipse &ellipse, bool firstFocus) {
  double c = std::sqrt(std::abs(ellipse.a * ellipse.a - ellipse.b * ellipse.b));
  if (ellipse.a > ellipse.b) {
    return {ellipse.h + (firstFocus ? c : -c), ellipse.k};
  } else {
    return {ellipse.h, ellipse.k + (firstFocus ? c : -c)};
  }
}

double findEccentricity(const Ellipse &ellipse) {
  double c = std::sqrt(std::abs(ellipse.a * ellipse.a - ellipse.b * ellipse.b));
  return c / std::max(ellipse.a, ellipse.b);
}

double findDirectrixDistance(const Ellipse &ellipse) {
  double c = std::sqrt(std::abs(ellipse.a * ellipse.a - ellipse.b * ellipse.b));
  return ellipse.a * ellipse.a / c;
}

int main() {
  std::srand(std::time(0));

  Ellipse ellipse = {std::rand() % 21 - 10, std::rand() % 21 - 10,
                     std::rand() % 9 + 1, std::rand() % 9 + 1};
  Point point = {std::rand() % 21 - 10, std::rand() % 21 - 10};

  bool pointOnEllipse = isPointOnEllipse(ellipse, point);
  Point focus1 = findFoci(ellipse, true);
  Point focus2 = findFoci(ellipse, false);
  double eccentricity = findEccentricity(ellipse);
  double directrixDistance = findDirectrixDistance(ellipse);

  std::cout << "Точка принадлежит эллипсу: " << (pointOnEllipse ? "да" : "нет")
            << std::endl;
  std::cout << "Координаты фокусов эллипса: (" << focus1.x << ", " << focus1.y
            << "), (" << focus2.x << ", " << focus2.y << ")" << std::endl;
  std::cout << "Длины полуосей эллипса: " << ellipse.a << ", " << ellipse.b
            << std::endl;
  std::cout << "Эксцентриситет эллипса: " << eccentricity << std::endl;
  std::cout << "Расстояние от директрис до центра: " << directrixDistance
            << std::endl;

  return 0;
}
