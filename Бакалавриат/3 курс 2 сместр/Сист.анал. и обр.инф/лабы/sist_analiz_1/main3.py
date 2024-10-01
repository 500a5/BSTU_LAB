
# Подключаем библиотеки.
import random
import math
from matplotlib.pyplot import plot, bar, show

# Получаем ПСЧ, распределенное по нормальному закону с заданными sigma, mat и n.
def my_rand(sigma, mat, n):
    vi = [random.random() for i in range(n)]

    svi = 0
    for i in range(n): svi += vi[i]
    return sigma * (svi - n / 2) / math.sqrt(n / 12) + mat # Генерирует ПСЧ, распределенные по нормальному закону
# с заданными sigma, mat и n:
#	1. N - количество чисел;
#	2. ints - количество отрезков.
def generate(sigma, mat, n, N, ints):
    div = mat * 2 / ints
    values = [i * div for i in range(ints)]
    counts = [0] * ints
    for i in range(N):
        rand = my_rand(sigma, mat, n)
        for j in range(ints):
            if rand > j * div and rand < (j + 1) * div: counts[j] += 1

    return values, counts

# Заданные sigma, mat и n (3 вариант).
sigma = 0.5
mat = 1
n = 8

# Количество чисел.
N = 10000

ints = n

# Отрезки и их частоты.
values, counts = generate(sigma, mat, n, N, ints)

# Получение интенсивности.
for i in range(ints):
    counts[i] /= N / ints

# Вывод гистограммы.
bar(values, counts)

show()
