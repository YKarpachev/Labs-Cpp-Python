#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

// Структура для хранения координат точки
struct Point {
  double x, y;
};

// Структура для хранения коэффициентов прямой
struct Line {
  double a, b, c;
};

// Функция для вычисления расстояния от точки до прямой
double distancePointToLine(const Line &line, const Point &point) {
  return std::abs(line.a * point.x + line.b * point.y + line.c) /
         std::sqrt(line.a * line.a + line.b * line.b);
}

// Функция для нахождения точки пересечения двух прямых
Point findIntersection(const Line &line1, const Line &line2) {
  Point intersection;
  double det = line1.a * line2.b - line2.a * line1.b;
  intersection.x = (line2.b * -line1.c - line1.b * -line2.c) / det;
  intersection.y = (line1.a * -line2.c - line2.a * -line1.c) / det;
  return intersection;
}

// Функция для нахождения угла между двумя прямыми
double findAngleBetweenLines(const Line &line1, const Line &line2) {
  double cosAngle = (line1.a * line2.a + line1.b * line2.b) /
                    (std::sqrt(line1.a * line1.a + line1.b * line1.b) *
                     std::sqrt(line2.a * line2.a + line2.b * line2.b));
  return std::acos(cosAngle) * 180 / M_PI;
}

int main() {
  std::srand(std::time(0));

  // Генерация случайных коэффициентов для двух прямых и точки
  Line line1 = {static_cast<double>(std::rand() % 21 - 10),
                static_cast<double>(std::rand() % 21 - 10),
                static_cast<double>(std::rand() % 21 - 10)};
  Line line2 = {static_cast<double>(std::rand() % 21 - 10),
                static_cast<double>(std::rand() % 21 - 10),
                static_cast<double>(std::rand() % 21 - 10)};
  Point point = {static_cast<double>(std::rand() % 21 - 10),
                 static_cast<double>(std::rand() % 21 - 10)};

  // Вычисление расстояний от точки до прямых
  double dist1 = distancePointToLine(line1, point);
  double dist2 = distancePointToLine(line2, point);

  // Нахождение точки пересечения прямых
  Point intersection = findIntersection(line1, line2);

  // Вычисление расстояния от точки до точки пересечения прямых
  double distToIntersection = std::sqrt(std::pow(point.x - intersection.x, 2) +
                                        std::pow(point.y - intersection.y, 2));

  // Вычисление угла между прямыми
  double angle = findAngleBetweenLines(line1, line2);

  // Вывод результатов
  std::cout << "Расстояние от точки до первой прямой: " << dist1 << std::endl;
  std::cout << "Расстояние от точки до второй прямой: " << dist2 << std::endl;
  std::cout << "Точка пересечения прямых: (" << intersection.x << ", "
            << intersection.y << ")" << std::endl;
  std::cout << "Расстояние от точки до точки пересечения прямых: "
            << distToIntersection << std::endl;
  std::cout << "Угол между прямыми: " << angle << " градусов" << std::endl;

  return 0;
}
