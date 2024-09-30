import random


# Агент - Муравей
class Ant:
    def __init__(self, current_spot):
        self.current_spot = current_spot         # Текущий узел
        self.path = [current_spot]          # Текущий путь агента
        self.travel_len = 0                 # Длина текущего пути
        self.tabu = []                      # Пройденные узлы

    # Добавление узла к текущему пути
    def add_spot_to_path(self, spot, length, traveled_path):
        self.path.append(spot)
        self.current_spot = spot
        self.travel_len += length
        self.tabu.append(traveled_path)

    # Поиск нового узла
    def find_new_spot(self, spots_n, travel_map, alpha, beta):
        available_paths = []
        for i in range(spots_n):
            if i not in self.path:
                available_paths.append([self.current_spot, i])

        if len(available_paths) == 0:
            return None

        p_sum = 0
        for path in available_paths:
            path_attributes = travel_map[frozenset(path)]
            p_sum += path_attributes[1] ** alpha * (1/path_attributes[0]) ** beta

        new_spot = None
        while new_spot is None:
            for path in available_paths:
                path_attributes = travel_map[frozenset(path)]
                p = path_attributes[1] ** alpha * (1/path_attributes[0]) ** beta
                p = p / p_sum
                move_p = random.random()
                if move_p < p:
                    new_spot = path[1]
                    break
        return new_spot

    # Гетер текущего узла
    def get_current_spot(self):
        return self.current_spot

    # Гетер ткущего пути
    def get_current_path(self):
        return self.path

    # Гетер длины текущего пути
    def get_travel_length(self):
        return self.travel_len

    # Гетер пройденных агентом узлов
    def get_tabu_list(self):
        return self.tabu


# Колония муравьев
class Colony:
    def __init__(self, ants, spots, alpha, beta, rho, q_value, max_distance):
        self.ants_n = ants                      # Число муравьев-агентов в колонии
        self.spots_n = spots                    # Число узлов
        self.alpha = alpha                      # Важность параметра интенсивности фермента
        self.beta = beta                        # Важность параметра веса ребра
        self.rho = rho                          # Коэффициент испарения фермента
        self.q = q_value                        # Коэф-константа количества фермента на грани
        self.max_distance = max_distance        # Максимальная длина пути

        self.ants = self.init_ants()            # Муравьи - агенты
        self.travel_map = self.init_map()       # Граф, по которому будут двигаться агенты

        # Условие выхода - лучшая дистанция не должна меняться на протяжении 5 ходов
        self.best_ants = []                     # Лучшие муравьи (т.е. прошедшие наименьшее расстояние
                                                # по сравнению с другими)
        same_best = 0
        old_best = self.max_distance * self.spots_n
        while same_best != 5:
            while self.sim_ants() != 0:
                pass
            self.update_paths()
            self.return_ants_to_start()

            best_ant = None
            best_length = self.max_distance * self.spots_n
            for ant in self.ants:
                if ant.get_travel_length() < best_length:
                    best_length = ant.get_travel_length()
                    best_ant = ant

            if best_length == old_best:
                same_best += 1
            else:
                same_best = 0
            old_best = best_length
            self.best_ants.append(best_ant)
            self.ants = self.init_ants()

    # Инициализация муравьев в колонии
    # с равным распределением между узлами
    def init_ants(self):
        ants = []
        curr_spot = 0
        for i in range(self.ants_n):
            ant = Ant(curr_spot)
            ants.append(ant)
            curr_spot += 1
            if curr_spot == self.spots_n:
                curr_spot = 0
        return ants

    # Инициализация узлов и длины граней
    def init_map(self):
        travel_map = dict()
        for i in range(self.spots_n - 1):
            for j in range(i, self.spots_n):
                if i != j:
                    # Индекс - номера, соединяемых узлов
                    path = frozenset([i, j])
                    # Значение - длина соединительной грани и вероятность перехода
                    travel_map[path] = [random.randint(1, self.max_distance), 1/self.spots_n]
        return travel_map

    # Проход муравьев-агентов
    def sim_ants(self):
        moved_ants = 0
        for ant in self.ants:
            if len(ant.get_current_path()) < self.spots_n:
                new_spot = ant.find_new_spot(self.spots_n, self.travel_map, self.alpha, self.beta)
                if new_spot is not None:
                    ant_current = ant.get_current_spot()
                    current_path = frozenset([ant_current, new_spot])
                    ant.add_spot_to_path(new_spot, self.travel_map[current_path][0], current_path)
                    moved_ants += 1
        return moved_ants

    def update_paths(self):
        for path in self.travel_map:
            self.travel_map[path][1] *= (1 - self.rho)

        for ant in self.ants:
            for path in ant.get_tabu_list():
                self.travel_map[path][1] += (self.q/ant.get_travel_length())

    def return_ants_to_start(self):
        for ant in self.ants:
            start_spot = ant.get_current_path()[0]
            ant_current = ant.get_current_spot()
            path_to_start = frozenset([ant_current, start_spot])
            ant.add_spot_to_path(start_spot, self.travel_map[path_to_start][0], path_to_start)

    def get_generated_spots(self):
        return self.travel_map

    def get_best_ants(self):
        return self.best_ants


col = Colony(40, 20, 3, 2, 0.1, 50, 20)
print('')
