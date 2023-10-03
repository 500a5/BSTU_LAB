# This Python file uses the following encoding: utf-8
from randomizer import randomizer as rnd

class ART1:
    '''Как использовать:
       set_parameters -> set_random_database -> perform'''

    def __init__(self):
        # Количество типов товаров
        self.max_items = 0
        # Количество покупателей
        self.max_customers = 0
        # Количество векторов-прототипов
        self.total_prototype_vectors = 0
        # Параметр бета
        self.beta = 0
        # Параметр внимательности
        self.vigilance = 0
        # Векторы-прототипы для каждого кластера
        self.prototype_vectors = []
        # База данных покупок
        self.database = []
        # Кластеры, в которых хранятся схожие векторы-признаки
        self.clusters = [[]]

        self.membership = []

        self.recomendations = []

    def get_clusters(self):
        clusters_str = ''
        pos = 1
        for cluster in self.clusters:
            clusters_str += 'Вектор-прототип:\n{}\nКластер {} :\n'.format(self.prototype_vectors[pos - 1], pos)
            for row in cluster:
                clusters_str += '{}\n'.format(row)
            pos += 1
        return clusters_str


    def perform(self):
        # Проверяем на схожесть все векторы признаков с векторами-прототипами
        pos = 0
        is_changed = True
        old_clusters = []
        while is_changed:
            old_clusters = self.clusters
            for E in self.database:
                is_complete = False
                i = 0
                for P in self.prototype_vectors:
                    ''' || P_i and E||    ||E||
                        -------------- > --------
                        beta + ||P_i||   beta + d   '''
                    a = self.get_vector_magnitude(self.and_vectors(P, E))
                    b = self.beta + self.get_vector_magnitude(P)
                    c = self.get_vector_magnitude(E)
                    d = self.beta + len(E)
                    is_similar = (a / b) > (c / d)
                    # Проверяем на внимательность
                    if is_similar:

                        '''||P_i and E||
                           ------------- < ρ
                               ||E||          '''
                        a = self.get_vector_magnitude(self.and_vectors(P, E))
                        b = self.get_vector_magnitude(E)
                        is_vigilante = (a / b) <= self.vigilance
                        # Если вектор признаков прошел все проверки
                        if is_vigilante:
                            ''' P_i = P_i and E '''
                            self.prototype_vectors[i] = self.and_vectors(P, E)
                            self.clusters[i].append(E)
                            is_complete = True
                            break
                    i += 1
                # Все прототипы были пройдены, но вектор не был помещен в кластер
                if not is_complete:
                    # Создаем новый вектор-прототип
                    self.prototype_vectors.append(E.copy())
                    self.clusters.append([])
                    self.clusters[len(self.clusters) -1].append(E.copy())
                pos += 1
            if old_clusters == self.clusters:
                is_changed = False
        return

    def get_recommendation(self, customer):
        pass

    # Установка входных параметров алгоритма
    def set_parameters(self, max_items, max_customers, total_prototype_vectors, beta, vigilance):
        self.max_items = max_items
        self.max_customers = max_customers
        self.total_prototype_vectors = total_prototype_vectors
        self.beta = beta
        self.vigilance = vigilance

    # Сгенерировать случайную базу данных покупок
    def set_random_database(self):
        for i in range(0, self.max_customers):
            self.database.append(rnd.get_int_list(self.max_items, 0, 1))
        # Инициализируем первый вектор-прототип
        self.prototype_vectors.append(self.database[0].copy())
        return

    # Возвращает базу данных покупок
    def get_database(self):
        return self.database

    # Возвращает количество ненулевых объектов
    def get_vector_magnitude(self, vector):
        magnitude = vector.count(1)
        return magnitude

    # Побитовое умножение векторов v и w
    def and_vectors(self, v, w):
        result = [x and y for x, y in zip(v, w)]
        return result

    # Устанавливает бд как в методичке (ПРОГРАММИРОВАНИЕ)
    def set_debug_values(self):
        self.database = [[ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0],
                         [ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1],
                         [ 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0],
                         [ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1],
                         [ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0],
                         [ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                         [ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
                         [ 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0],
                         [ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0],
                         [ 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0]]
        self.prototype_vectors.append(self.database[0].copy())
        self.set_parameters(11, 10, 5, 1.0, 0.9)


