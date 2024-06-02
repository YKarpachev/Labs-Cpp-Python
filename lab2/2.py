import numpy as np
from sympy import symbols, Eq, solve

# Генерация случайных коэффициентов для плоскости и двух точек
np.random.seed(42)
A, B, C, D = np.random.randint(-10, 10, 4)
x1, y1, z1 = np.random.randint(-10, 10, 3)
x2, y2, z2 = np.random.randint(-10, 10, 3)

# Уравнение плоскости: Ax + By + Cz + D = 0
# Уравнение прямой: (x, y, z) = (x1, y1, z1) + t * ((x2 - x1), (y2 - y1), (z2 - z1))


# Проверка принадлежности точки плоскости
def is_point_on_plane(A, B, C, D, x, y, z):
    return A * x + B * y + C * z + D == 0


# Проверка пересечения прямой и плоскости
x, y, z = symbols("x y z")
plane_eq = Eq(A * x + B * y + C * z + D, 0)
line_eq = (
    x1 + (x2 - x1) * symbols("t"),
    y1 + (y2 - y1) * symbols("t"),
    z1 + (z2 - z1) * symbols("t"),
)
intersection_line_plane = solve(
    plane_eq.subs({x: line_eq[0], y: line_eq[1], z: line_eq[2]}), symbols("t")
)

# Вывод результатов
print(f"Уравнение плоскости: {A}x + {B}y + {C}z + {D} = 0")
print(
    f"Уравнение прямой: (x, y, z) = ({x1}, {y1}, {z1}) + t * (({x2 - x1}), ({y2 - y1}), ({z2 - z1}))"
)
print(
    f"Точка пересечения прямой и плоскости: {'существует' if intersection_line_plane else 'не существует'}"
)

# Координаты точки пересечения (если существует)
if intersection_line_plane:
    t_val = intersection_line_plane[0]
    intersection_point = (
        line_eq[0].subs(symbols("t"), t_val),
        line_eq[1].subs(symbols("t"), t_val),
        line_eq[2].subs(symbols("t"), t_val),
    )
    print(f"Координаты точки пересечения: {intersection_point}")
