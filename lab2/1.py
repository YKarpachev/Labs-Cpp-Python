import numpy as np

# Генерация случайных параметров прямых
np.random.seed(0)
a1, b1, c1 = np.random.randint(-10, 10, 3)
a2, b2, c2 = np.random.randint(-10, 10, 3)

# Генерация случайной точки
x0, y0 = np.random.randint(-10, 10, 2)


# Функция для нахождения расстояния от точки до прямой
def distance_point_to_line(a, b, c, x0, y0):
    return abs(a * x0 + b * y0 + c) / np.sqrt(a**2 + b**2)


# Расстояния от точки до каждой прямой
dist1 = distance_point_to_line(a1, b1, c1, x0, y0)
dist2 = distance_point_to_line(a2, b2, c2, x0, y0)

# Точка пересечения прямых
A = np.array([[a1, b1], [a2, b2]])
B = np.array([-c1, -c2])
intersection_point = np.linalg.solve(A, B)

# Расстояние от заданной точки до точки пересечения прямых
dist_to_intersection = np.sqrt(
    (x0 - intersection_point[0]) ** 2 + (y0 - intersection_point[1]) ** 2
)

# Угол между прямыми
cos_angle = (a1 * a2 + b1 * b2) / (np.sqrt(a1**2 + b1**2) * np.sqrt(a2**2 + b2**2))
angle = np.arccos(cos_angle) * 180 / np.pi

print(f"Расстояние от точки до первой прямой: {dist1}")
print(f"Расстояние от точки до второй прямой: {dist2}")
print(f"Точка пересечения прямых: {intersection_point}")
print(f"Расстояние от точки до точки пересечения прямых: {dist_to_intersection}")
print(f"Угол между прямыми: {angle} градусов")
