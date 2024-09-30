# This Python file uses the following encoding: utf-8
import random
from randomizer import Randomizer
from PyQt5.QtCore import qDebug
class Gen_alg:
    def __init__(a, n, iterations, r_count, crossing_prob):
        # Количество вершин графа
        a.n = n

        # Вероятность того, что при селекции будет выполнено скрещивание
        a.crossing_prob = crossing_prob

        # Мощность популяции
        a.r_count = r_count

        # Количество итераций алгоритма
        a.iterations = iterations

        # Популяция, т. е. набор решений задачи
        a.r = []
        #self.r.append([i for i in range(n - 1, 0 - 1, -1)])
        a.r.append([i for i in range(0, n)])

        # Инициализируем случайными величинами
        for i in range(1, n):
            a.r.append(Randomizer.swap_list_elements(a.r[i - 1], 5))

        if (n == 10):
            a.distances = [[0, 1, 2, 3, 4, 5, 6, 7, 8, 9],
                           [1, 0, 1, 2, 3, 4, 5, 6, 7, 8],
                           [2, 1, 0, 1, 2, 3, 4, 5, 6, 7],
                           [3, 2, 1, 0, 1, 2, 3, 4, 5, 6],
                           [4, 3, 2, 1, 0, 1, 2, 3, 4, 5],
                           [5, 4, 3, 2, 1, 0, 1, 2, 3, 4],
                           [6, 5, 4, 3, 2, 1, 0, 1, 2, 3],
                           [7, 6, 5, 4, 3, 2, 1, 0, 1, 2],
                           [8, 7, 6, 5, 4, 3, 2, 1, 0, 1],
                           [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]]
        else:
            # Матрица расстояний между вершинами графа
            a.distances = [[0 for i in range(n)] for j in range(n)]
            # Граф неориентированный, поэтому d[i][j] = d[j][i]
            for i in range (0, n):
                for j in range (i + 1, n):
                    # Задаем случайное значение длины пути
                    r = random.randint(1, 50)
                    a.distances[i][j], a.distances[j][i] = r, r#int(r), int(r)

        # Здоровье популяции
        a.health = []
        # Вычисляем здоровье начальной популяции
        for el in a.r:
            a.health.append(a.get_health(el))

        # Позиции, с которых делали мутации
        a.mutation_pos = [1 for i in range(n)]

        # Лучшие решения за каждую итерацию
        a.best_solutions = []


    def perform(a):
        # Для каждой итерации
        for iteration in range(a.iterations):
            # Решаем, что будем делать - скрещивать или мутировать
            newr = []
            for k in range(a.r_count):
                if random.random() < a.crossing_prob:
                    # Скрещиваем
                    pos1, pos2 = a.get_crossing_els()

                    # И сохраняем результат
                    t = a.crossing(a.r[pos1], a.r[pos2])
                    newr.append(t.copy())

                else:
                    # Находим самого слабого
                    pos = a.get_mutating_el()
                    # И даем ему шанс
                    t = a.mutate(self.r[pos], self.mutation_pos[pos])
                    newr.append(t.copy())
                    a.mutation_pos[pos] += 1
                    # А если самый слабый не излечился за положенное число раз,
                    # обнуляем позицию сдвига
                    if a.mutation_pos[pos] >= a.n - 1:
                        a.mutation_pos[pos] = 1

            # Вычисляем здоровье каждого из популяции
            a.health.clear()
            a.r.clear()
            a.r = newr
            while (len(a.mutation_pos) < len(a.r)):
                a.mutation_pos.append(1)

            for el in a.r:
                a.health.append(a.get_health(el))

            self.save_best()

    def get_distances(a):
        return a.distances

    def get_best_solutions(a):
        return a.best_solutions

    def save_best(a):
        index = a.health.index(max(a.health))
        a.best_solutions.append(a.r[index].copy())

    def get_random_best_r(a):
        total_health = sum(a.health)
        troubles = [h / total_health for h in a.health]
        troubl = random.random()
        sum_troubles = 0
        for i in range(len(troubles)):
            sum_troubles += troubles[i]
            if troubl < sum_troubles:
                return i

    def get_crossing_els(a):
        i = a.get_random_best_r();
        j = i
        while (i == j):
            j = a.get_random_best_r()
        return i, j

    def get_mutating_el(a):
        reverse_health = [1 / h for h in a.health]
        total_health = sum(reverse_health)

        troubles = [h / total_health for h in reverse_health]
        troubl = random.random()
        sum_troubles = 0
        for i in range(len(troubles)):
            sum_troubles += troubles[i]
            if troubl < sum_troubles:
                return i

    def mutate(a, r, pos):
        const_part = r[:pos]
        changing_part = r[pos:]
        changing_part.reverse()
        return const_part + changing_part

    def crossing(a, r1, r2):
        cross_factor = 0.3
        free_r1 = set()
        free_r2 = set()
        while len(free_r1) < len(r1) * cross_factor:

            i = random.randint(0, len(r1) - 1)
            if i in free_r1:
                continue
            free_r1.add(i)
            free_r2.add(r2.index(r1[i]))


        new_r1 = [r2[free_r2.pop()] if i in free_r1 else r1[i] for i in range(len(r1))]
        return new_r1

    def get_distance(a, r):
        health = 0
        prev_pos = r[0]
        for i in range(1, len(r)):
            health += a.distances[prev_pos][r[i]]
        return health


    def get_health(a, r):
        health = 0
        prev_pos = r[0]
        for i in range(1, len(r)):
            health += a.distances[prev_pos][r[i]]

        # Поскольку решаем задачу максимизации, а в задаче речь
        # про минимальную стоимость пути, берем обратную величину от стоимости пути
        if health == 0:
            return 0.000000000000001
        return 1 / health

        # Или не переходим
        #return health

    def get_list_distances(a, r):
        prev_pos = r[0]
        dist = []
        for i in range(1, len(r)):
            dist.append(a.distances[prev_pos][r[i]])
        return dist
