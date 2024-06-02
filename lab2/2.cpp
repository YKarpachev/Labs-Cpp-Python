#include <cmath>
#include <iostream>
#include <vector>

// Структура для хранения координат точки в 3D пространстве
struct Point3D {
  double x, y, z;
};

// Структура для хранения коэффициентов плоскости
struct Plane {
  double a, b, c, d;
};

// Функция для вычисления расстояния от точки до плоскости
double distancePointToPlane(const Plane &plane, const Point3D &point) {
  return std::abs(plane.a * point.x + plane.b * point.y + plane.c * point.z +
                  plane.d) /
         std::sqrt(plane.a * plane.a + plane.b * plane.b + plane.c * plane.c);
}

// Функция для нахождения точки пересечения прямой и плоскости
Point3D findLinePlaneIntersection(const Plane &plane, const Point3D &point1,
                                  const Point3D &point2) {
  Point3D intersection;
  double t =
      -(plane.a * point1.x + plane.b * point1.y + plane.c * point1.z +
        plane.d) /
      (plane.a * (point2.x - point1.x) + plane.b * (point2.y - point1.y) +
       plane.c * (point2.z - point1.z));
  intersection.x = point1.x + t * (point2.x - point1.x);
  intersection.y = point1.y + t * (point2.y - point1.y);
  intersection.z = point1.z + t * (point2.z - point1.z);
  return intersection;
}

int main() {
  // Генерация случайных коэффициентов для плоскости и двух точек
  Plane plane = {static_cast<double>(std::rand() % 21 - 10),
                 static_cast<double>(std::rand() % 21 - 10),
                 static_cast<double>(std::rand() % 21 - 10),
                 static_cast<double>(std::rand() % 21 - 10)};
  Point3D point1 = {static_cast<double>(std::rand() % 21 - 10),
                    static_cast<double>(std::rand() % 21 - 10),
                    static_cast<double>(std::rand() % 21 - 10)};
  Point3D point2 = {static_cast<double>(std::rand() % 21 - 10),
                    static_cast<double>(std::rand() % 21 - 10),
                    static_cast<double>(std::rand() % 21 - 10)};

  // Вычисление расстояния от первой точки до плоскости
  double distance1 = distancePointToPlane(plane, point1);

  // Вычисление расстояния от второй точки до плоскости
  double distance2 = distancePointToPlane(plane, point2);

  // Нахождение точки пересечения прямой, проходящей через две точки, и
  // плоскости
  Point3D intersection = findLinePlaneIntersection(plane, point1, point2);

  // Вывод результатов
  std::cout << "Расстояние от первой точки до плоскости: " << distance1
            << std::endl;
  std::cout << "Расстояние от второй точки до плоскости: " << distance2
            << std::endl;
  std::cout << "Точка пересечения прямой и плоскости: (" << intersection.x
            << ", " << intersection.y << ", " << intersection.z << ")"
            << std::endl;

  return 0;
}
