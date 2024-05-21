#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

struct Vector {
  double x, y, z;
};

double vectorLength(const Vector &v) {
  return std::sqrt(v.x * v.x, v.y * v.y, v.z * v.z);
}

double angleBetweenVectors(const Vector &v1, const Vector &v2) {
  double dotProduct = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
  double len1 = vectorLength(v1);
  double len2 = vectorLength(v2);
  return std::acos(dotProduct / (len1 * len2)) * 180 / M_PI;
}

Vector vectorSum(const Vector &v1, const Vector &v2) {
  return {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
}

Vector vectorDifference(const Vector &v1, const Vector &v2) {
  return {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
}

bool areVectorsParallel(const Vector &v1, const Vector &v2) {
  Vector crossProduct = {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
                         v1.x * v2.y - v1.y * v2.x};
  return crossProduct.x == 0 && crossProduct.y == 0 && crossProduct.z == 0;
}

Vector vectorCrossProduct(const Vector &v1, const Vector &v2) {
  return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
          v1.x * v2.y - v1.y * v2.x};
}

int main() {
  std::srand(std::time(0));

  Vector v1 = {std::rand() % 21 - 10, std::rand() % 21 - 10,
               std::rand() % 21 - 10};
  Vector v2 = {std::rand() % 21 - 10, std::rand() % 21 - 10,
               std::rand() % 21 - 10};

  double length1 = vectorLength(v1);
  double length2 = vectorLength(v2);
  double angle = angleBetweenVectors(v1, v2);
  Vector sum = vectorSum(v1, v2);
  Vector diff = vectorDifference(v1, v2);
  bool parallel = areVectorsParallel(v1, v2);
  Vector crossProduct = vectorCrossProduct(v1, v2);

  std::cout << "Длина первого вектора: " << length1 << std::endl;
  std::cout << "Длина второго вектора: " << length2 << std::endl;
  std::cout << "Угол между векторами: " << angle << " градусов" << std::endl;
  std::cout << "Сумма векторов: (" << sum.x << ", " << sum.y << ", " << sum.z
            << ")" << std::endl;
  std::cout << "Разность векторов: (" << diff.x << ", " << diff.y << ", "
            << diff.z << ")" << std::endl;
  std::cout << "Вектора параллельны: " << (parallel ? "да" : "нет")
            << std::endl;
  std::cout << "Векторное произведение: (" << crossProduct.x << ", "
            << crossProduct.y << ", " << crossProduct.z << ")" << std::endl;

  return 0;
}
