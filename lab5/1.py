class SplineSegment:
    def __init__(self, a, b, c, d, x):
        self.a = a  # Коэффициент a
        self.b = b  # Коэффициент b
        self.c = c  # Коэффициент c
        self.d = d  # Коэффициент d
        self.x = x  # Узел x


def construct_cubic_spline(x, y):
    n = len(x) - 1
    h = [x[i + 1] - x[i] for i in range(n)]  # Вычисление шагов h
    alpha = [
        (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1])
        for i in range(1, n)
    ]  # Вычисление альфа-коэффициентов

    l = [1.0] * (n + 1)  # Инициализация l
    mu = [0.0] * n  # Инициализация mu
    z = [0.0] * (n + 1)  # Инициализация z

    # Прогоночный метод для системы уравнений
    for i in range(1, n):
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1]
        mu[i] = h[i] / l[i]
        z[i] = (alpha[i - 1] - h[i - 1] * z[i - 1]) / l[i]

    b = [0.0] * n  # Инициализация b
    c = [0.0] * (n + 1)  # Инициализация c
    d = [0.0] * n  # Инициализация d

    # Вычисление коэффициентов c, b и d
    for j in range(n - 1, -1, -1):
        c[j] = z[j] - mu[j] * c[j + 1]
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0
        d[j] = (c[j + 1] - c[j]) / (3.0 * h[j])

    # Создание сегментов сплайна
    spline = [SplineSegment(y[i], b[i], c[i], d[i], x[i]) for i in range(n)]
    return spline


def evaluate_spline(spline, x):
    # Вычисление значения сплайна в точке x
    for i in range(len(spline)):
        if x >= spline[i].x and x <= spline[i + 1].x:
            dx = x - spline[i].x
            return (
                spline[i].a
                + spline[i].b * dx
                + spline[i].c * dx**2
                + spline[i].d * dx**3
            )
    return 0.0  # Возвращаем 0.0, если x вне пределов (необязательно)


# Входные данные
x = [0.0, 1.0, 2.0, 3.0, 4.0]
y = [0.0, 0.5, 0.86603, 1.0, 0.86603]

# Построение кубического сплайна
spline = construct_cubic_spline(x, y)

# Точка для вычисления значения сплайна
x_star = 1.5
y_star = evaluate_spline(spline, x_star)

# Вывод результата
print("Сплайн в x* =", x_star, "равен y* =", y_star)
