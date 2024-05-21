import numpy as np
from sympy import symbols, Eq, solve

# Генерация случайных параметров гиперболического параболоида
np.random.seed(3)
a, b = np.random.randint(1, 10, 2)

# Уравнение гиперболического параболоида: z = x^2 / a^2 - y^2 / b^2

# Генерация случайной плоскости
A, B, C, D = np.random.randint(-10, 10, 4)

# Генерация случайной прямой
x1, y1, z1 = np.random.randint(-10, 10, 3)
x2, y2, z2 = np.random.randint(-10, 10, 3)

# Генерация случайной точки
x0, y0, z0 = np.random.randint(-10, 10, 3)

# Проверка принадлежности точки гиперболическому параболоиду
def is_point_on_hyperbolic_paraboloid(x, y, z, a, b):
    return z == x**2 / a**2 - y**2 / b**2

point_on_paraboloid = is_point_on_hyperbolic_paraboloid(x0, y0, z0, a, b)

# Проверка пересечения плоскости и гиперболического параболоида
x, y, z = symbols('x y z')
plane_eq = Eq(A*x + B*y + C*z + D, 0)
paraboloid_eq = Eq(z, x**2 / a**2 - y**2 / b**2)
intersection_plane = solve((plane_eq, paraboloid_eq), (x, y, z))

# Проверка пересечения прямой и гиперболического параболоида
t = symbols('t')
line_eq = (x1 + t*(x2 - x1), y1 + t*(y2 - y1), z1 + t*(z2 - z1))
paraboloid_subs = paraboloid_eq.subs({x: line_eq[0], y: line_eq[1], z: line_eq[2]})
intersection_line = solve(paraboloid_subs, t)

print(f"Точка принадлежит гиперболическому параболоиду: {'да' если point_on_paraboloid else 'нет'}")
print(f"Плоскость пересекает гиперболический параболоид: {'да' если intersection_plane else 'нет'}")
print(f"Прямая пересекает гиперболический параболоид: {'да' если intersection_line else 'нет'}")
