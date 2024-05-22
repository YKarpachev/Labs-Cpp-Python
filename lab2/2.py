import numpy as np

# Генерация случайных координат векторов
np.random.seed(1)
v1 = np.random.randint(-10, 10, 3)
v2 = np.random.randint(-10, 10, 3)

# Длины векторов
length_v1 = np.linalg.norm(v1)
length_v2 = np.linalg.norm(v2)

# Угол между векторами
cos_angle = np.dot(v1, v2) / (length_v1 * length_v2)
angle = np.arccos(cos_angle) * 180 / np.pi

# Сумма и разность векторов
sum_vectors = v1 + v2
diff_vectors = v1 - v2

# Проверка параллельности
parallel = np.allclose(np.cross(v1, v2), 0)

# Векторное произведение
cross_product = np.cross(v1, v2)

print(f"Длина первого вектора: {length_v1}")
print(f"Длина второго вектора: {length_v2}")
print(f"Угол между векторами: {angle} градусов")
print(f"Сумма векторов: {sum_vectors}")
print(f"Разность векторов: {diff_vectors}")
print(f"Вектора параллельны: {'да' if parallel else 'нет'}")
print(f"Векторное произведение: {cross_product}")
