#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct Point {
  double x, y, z;
};

struct Plane {
  double A, B, C, D;
};

struct Line {
  Point p1, p2;
};

bool isPointOnHyperbolicParaboloid(const Point &point, double a, double b) {
  return std::abs(point.z - (point.x * point.x / (a * a) -
                             point.y * point.y / (b * b))) < 1e-6;
}

bool doesPlaneIntersectHyperbolicParaboloid(const Plane &plane, double a,
                                            double b) {
  for (double x = -10; x <= 10; x += 0.1) {
    for (double y = -10; y <= 10; y += 0.1) {
      double z = x * x / (a * a) - y * y / (b * b);
      if (std::abs(plane.A * x + plane.B * y + plane.C * z + plane.D) < 1e-6) {
        return true;
      }
    }
  }
  return false;
}

bool doesLineIntersectHyperbolicParaboloid(const Line &line, double a,
                                           double b) {
  for (double t = 0; t <= 1; t += 0.01) {
    Point point = {line.p1.x + t * (line.p2.x - line.p1.x),
                   line.p1.y + t * (line.p2.y - line.p1.y),
                   line.p1.z + t * (line.p2.z - line.p1.z)};
    if (isPointOnHyperbolicParaboloid(point, a, b)) {
      return true;
    }
  }
  return false;
}

int main() {
  std::srand(std::time(0));

  double a = std::rand() % 9 + 1;
  double b = std::rand() % 9 + 1;

  Plane plane = {std::rand() % 21 - 10, std::rand() % 21 - 10,
                 std::rand() % 21 - 10, std::rand() % 21 - 10};
  Line line = {
      {std::rand() % 21 - 10, std::rand() % 21 - 10, std::rand() % 21 - 10},
      {std::rand() % 21 - 10, std::rand() % 21 - 10, std::rand() % 21 - 10}};
  Point point = {std::rand() % 21 - 10, std::rand() % 21 - 10,
                 std::rand() % 21 - 10};

  bool pointOnParaboloid = isPointOnHyperbolicParaboloid(point, a, b);
  bool planeIntersects = doesPlaneIntersectHyperbolicParaboloid(plane, a, b);
  bool lineIntersects = doesLineIntersectHyperbolicParaboloid(line, a, b);

  std::cout << "Точка принадлежит гиперболическому параболоиду: "
            << (pointOnParaboloid ? "да" : "нет") << std::endl;
  std::cout << "Плоскость пересекает гиперболический параболоид: "
            << (planeIntersects ? "да" : "нет") << std::endl;
  std::cout << "Прямая пересекает гиперболический параболоид: "
            << (lineIntersects ? "да" : "нет") << std::endl;

  return 0;
}
