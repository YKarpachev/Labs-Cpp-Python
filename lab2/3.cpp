#include <cmath>
#include <iostream>
#include <vector>

// Структура для хранения коэффициентов уравнения окружности
struct Circle {
  double x, y, r;
};

// Структура для хранения коэффициентов уравнения прямой
struct Line {
  double a, b, c;
};

// Функция для вычисления расстояния от центра окружности до прямой
double distanceCircleToLine(const Circle &circle, const Line &line) {
  return std::abs(line.a * circle.x + line.b * circle.y + line.c) /
         std::sqrt(line.a * line.a + line.b * line.b);
}

// Функция для нахождения точек пересечения окружности и прямой
std::vector<std::pair<double, double>> findIntersection(const Circle &circle,
                                                        const Line &line) {
  std::vector<std::pair<double, double>> intersections;
  double x0 = circle.x, y0 = circle.y, r = circle.r;
  double a = line.a, b = line.b, c = line.c;

  double dist = distanceCircleToLine(circle, line);

  if (dist > r) {
    // Прямая не пересекает окружность
    return intersections;
  }

  double x1, x2, y1, y2;

  if (b != 0) {
    double k = -a / b;
    double b0 = -c / b;
    double A = 1 + k * k;
    double B = 2 * (k * b0 - k * y0 - x0);
    double C = x0 * x0 + y0 * y0 + b0 * b0 - 2 * b0 * y0 - r * r;

    double D = B * B - 4 * A * C;

    if (D < 0) {
      // Прямая не пересекает окружность
      return intersections;
    }

    x1 = (-B + std::sqrt(D)) / (2 * A);
    x2 = (-B - std::sqrt(D)) / (2 * A);
    y1 = k * x1 + b0;
    y2 = k * x2 + b0;
  } else {
    x1 = x2 = -c / a;
    y1 = y0 + std::sqrt(r * r - (x1 - x0) * (x1 - x0));
    y2 = y0 - std::sqrt(r * r - (x1 - x0) * (x1 - x0));
  }

  intersections.push_back({x1, y1});
  intersections.push_back({x2, y2});

  return intersections;
}

int main() {
  // Генерация случайных коэффициентов для окружности и прямой
  Circle circle = {static_cast<double>(std::rand() % 21 - 10),
                   static_cast<double>(std::rand() % 21 - 10),
                   static_cast<double>(std::rand() % 10 + 1)};
  Line line = {static_cast<double>(std::rand() % 21 - 10),
               static_cast<double>(std::rand() % 21 - 10),
               static_cast<double>(std::rand() % 21 - 10)};

  // Нахождение точек пересечения окружности и прямой
  auto intersections = findIntersection(circle, line);

  // Вывод результатов
  std::cout << "Центр окружности: (" << circle.x << ", " << circle.y
            << "), радиус: " << circle.r << std::endl;
  std::cout << "Уравнение прямой: " << line.a << "x + " << line.b << "y + "
            << line.c << " = 0" << std::endl;

  if (intersections.empty()) {
    std::cout << "Прямая не пересекает окружность." << std::endl;
  } else {
    std::cout << "Точки пересечения окружности и прямой: " << std::endl;
    for (const auto &point : intersections) {
      std::cout << "(" << point.first << ", " << point.second << ")"
                << std::endl;
    }
  }

  return 0;
}
