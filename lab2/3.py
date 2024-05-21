import numpy as np

# Генерация случайных параметров эллипса
np.random.seed(2)
a = np.random.randint(1, 10)
b = np.random.randint(1, 10)
h, k = np.random.randint(-10, 10, 2)

# Генерация случайной точки
x, y = np.random.randint(-10, 10, 2)

# Уравнение эллипса: ((x-h)^2 / a^2) + ((y-k)^2 / b^2) = 1
def is_point_on_ellipse(x, y, h, k, a, b):
    return ((x - h)**2 / a**2) + ((y - k)**2 / b**2) == 1

# Координаты фокусов
c = np.sqrt(abs(a**2 - b**2))
focus1 = (h + c, k) if a > b else (h, k + c)
focus2 = (h - c, k) if a > b else (h, k - c)

# Эксцентриситет
eccentricity = c / max(a, b)

# Расстояние от директрис до центра
directrix_distance = a**2 / c if a > b else b**2 / c

point_on_ellipse = is_point_on_ellipse(x, y, h, k, a, b)

print(f"Точка принадлежит эллипсу: {'да' если point_on_ellipse else 'нет'}")
print(f"Координаты фокусов эллипса: {focus1}, {focus2}")
print(f"Длины полуосей эллипса: {a}, {b}")
print(f"Эксцентриситет эллипса: {eccentricity}")
print(f"Расстояние от директрис до центра: {directrix_distance}")
