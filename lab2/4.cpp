#include <iostream>
#include <vector>

// Структура для хранения коэффициентов уравнения эллипса
struct Ellipse {
  double h, k, a, b;
};

// Структура для хранения коэффициентов уравнения прямой
struct Line {
  double A, B, C;
};

// Функция для нахождения точек пересечения эллипса и прямой
std::vector<std::pair<double, double>> findIntersection(const Ellipse &ellipse,
                                                        const Line &line) {
  std::vector<std::pair<double, double>> intersections;

  double h = ellipse.h, k = ellipse.k, a = ellipse.a, b = ellipse.b;
  double A = line.A, B = line.B, C = line.C;

  double A1 = (A * A) / (a * a) + (B * B) / (b * b);
  double B1 =
      2 * A * C / (a * a) + 2 * B * k * B / (b * b) - 2 * h * A * B / (b * b);
  double C1 =
      (C * C) / (a * a) + (B * B) * (h * h) / (b * b) - 2 * h * A * C / (b * b);

  double D = B1 * B1 - 4 * A1 * C1;

  if (D < 0) {
    // Прямая не пересекает эллипс
    return intersections;
  }

  double x1 = (-B1 + std::sqrt(D)) / (2 * A1);
  double x2 = (-B1 - std::sqrt(D)) / (2 * A1);

  double y1 = (-C - A * x1) / B;
  double y2 = (-C - A * x2) / B;

  intersections.push_back({x1, y1});
  intersections.push_back({x2, y2});

  return intersections;
}

int main() {
  // Генерация случайных коэффициентов для эллипса и прямой
  Ellipse ellipse = {static_cast<double>(std::rand() % 21 - 10),
                     static_cast<double>(std::rand() % 21 - 10),
                     static_cast<double>(std::rand() % 10 + 1),
                     static_cast<double>(std::rand() % 10 + 1)};
  Line line = {static_cast<double>(std::rand() % 21 - 10),
               static_cast<double>(std::rand() % 21 - 10),
               static_cast<double>(std::rand() % 21 - 10)};

  // Нахождение точек пересечения эллипса и прямой
  auto intersections = findIntersection(ellipse, line);

  // Вывод результатов
  std::cout << "Центр эллипса: (" << ellipse.h << ", " << ellipse.k
            << "), полуоси: a = " << ellipse.a << ", b = " << ellipse.b
            << std::endl;
  std::cout << "Уравнение прямой: " << line.A << "x + " << line.B << "y + "
            << line.C << " = 0" << std::endl;

  if (intersections.empty()) {
    std::cout << "Прямая не пересекает эллипс." << std::endl;
  } else {
    std::cout << "Точки пересечения эллипса и прямой: " << std::endl;
    for (const auto &point : intersections) {
      std::cout << "(" << point.first << ", " << point.second << ")"
                << std::endl;
    }
  }

  return 0;
}
