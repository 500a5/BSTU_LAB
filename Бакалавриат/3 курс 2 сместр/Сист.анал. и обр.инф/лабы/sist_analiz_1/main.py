import random
import math
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors
import numpy as np


def generate(rand, mat, N, ints):
    div = mat * 2 / ints
    values = [i * div + div / 2 for i in range(ints)]
    counts = [0] * ints

    for i in range(N):
        r = rand()
        for j in range(ints):
            if r > j * div and r < (j + 1) * div:
                counts[j] += 1

    return values, counts

def newton(f, f_prime, x0, eps = 1e-7, kmax = 1e3):
    x, x_prev, i = x0, x0 + 2 * eps, 0

    while abs(x - x_prev) >= eps and i < kmax:
        x, x_prev, i = x - f(x) / f_prime(x), x, i + 1
    return x

# Нормированная функция плотности вероятности.
def f(x):
    return 0.25 * x ** 3 - 1.115 * x ** 2 + 1.875 * x # Первая производная от f(x).
def f_prime(x):
    return 0.75 * x ** 2 - 2.25 * x + 1.875

# Исходная функция плотности вероятности.
def fe(x):
    return 2 * x ** 2 - 6 * x + 5

# Получаем ПСЧ по заданной плотности вероятности.
def my_rand():
    return newton(lambda x: f(x) - random.random(), f_prime, 0.45)

# Количество ПСЧ.
N = 10000
# Количество отрезков.
ints = 8
# Отрезки и их частоты.
values, counts = generate(my_rand, 0.5, N, ints)

# Получение интенсивности.
for i in range(ints):
    counts[i] /= (N / ints)

# Вывод графиков.
t = np.linspace(0, 1, ints)
plt.plot(t, fe(t), color='r')
plt.bar(values, counts, width=1/ints)

plt.show()
