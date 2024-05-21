#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct Point {
  double x, y;
};

struct Line {
  double a, b, c;
};

double distancePointToLine(const Line &line, const Point &point) {
  return std::abs(line.a * point.x + line.b * point.y + line.c) /
         std::sqrt(line.a * line.a + line.b * line.b);
}

Point findIntersection(const Line &line1, const Line &line2) {
  Point intersection;
  double det = line1.a * line2.b - line2.a * line1.b;
  intersection.x = (line2.b * -line1.c - line1.b * -line2.c) / det;
  intersection.y = (line1.a * -line2.c - line2.a * -line1.c) / det;
  return intersection;
}

double findAngleBetweenLines(const Line &line1, const Line &line2) {
  double cosAngle = (line1.a * line2.a + line1.b * line2.b) /
                    (std::sqrt(line1.a * line1.a + line1.b * line1.b) *
                     std::sqrt(line2.a * line2.a + line2.b * line2.b));
  return std::acos(cosAngle) * 180 / M_PI;
}

int main() {
  std::srand(std::time(0));

  Line line1 = {std::rand() % 21 - 10, std::rand() % 21 - 10,
                std::rand() % 21 - 10};
  Line line2 = {std::rand() % 21 - 10, std::rand() % 21 - 10,
                std::rand() % 21 - 10};
  Point point = {std::rand() % 21 - 10, std::rand() % 21 - 10};

  double dist1 = distancePointToLine(line1, point);
  double dist2 = distancePointToLine(line2, point);
  Point intersection = findIntersection(line1, line2);
  double distToIntersection = std::sqrt(std::pow(point.x - intersection.x, 2) +
                                        std::pow(point.y - intersection.y, 2));
  double angle = findAngleBetweenLines(line1, line2);

  std::cout << "Расстояние от точки до первой прямой: " << dist1 << std::endl;
  std::cout << "Расстояние от точки до второй прямой: " << dist2 << std::endl;
  std::cout << "Точка пересечения прямых: (" << intersection.x << ", "
            << intersection.y << ")" << std::endl;
  std::cout << "Расстояние от точки до точки пересечения прямых: "
            << distToIntersection << std::endl;
  std::cout << "Угол между прямыми: " << angle << " градусов" << std::endl;

  return 0;
}
