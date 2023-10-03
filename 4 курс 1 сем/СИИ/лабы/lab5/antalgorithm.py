# This Python file uses the following encoding: utf-8
from PyQt5.QtCore import qDebug
import random
import math
class AntAlgorithm:
    def __init__(self, n, iterations, antsCount, eliteAntsCount, alpha, beta, rho):
        # Количество итераций алгоритма
        self.iterations = iterations
        # Количество муравьев
        self.antsCount = antsCount

        self.roads = []
        self.sums = []
        self.eliteAntsCount = eliteAntsCount
        # Количество вершин
        self.n = n
        # Вес фермента
        self.alpha = alpha
        # Коэффициент эвристики
        self.beta = beta
        # Коэффициент испраения феромона
        self.rho = rho

        self.eliteAnts = []
        for i in range(eliteAntsCount):
            r = random.randint(0, antsCount)
            while r in self.eliteAnts:
                r = random.randint(0, antsCount)
            self.eliteAnts.append(r)
        #qDebug("{}".format(self.eliteAnts))
        # Индекс - порядковый номер муравья, значение - вершина, в которой находится
        self.antsPositon = []
        # Размещаем каждого муравья в очередной вершине
        for i in range(0, self.antsCount):
            self.antsPositon.append(i % self.n)

        # Уже посещенные муравьями вершины
        self.tabuList = [[] for j in range(self.antsCount)]
        # Cтартовые вершины тоже помечаем как посещенные
        for i in range(0, len(self.antsPositon)):
            self.tabuList[i].append(self.antsPositon[i])
            self.roads.append([i])
            self.sums.append(0)
        # Считаем, что граф полносвязный
        # Матрица расстояний между вершинами графа
        self.distances = [[0 for i in range(n)] for j in range(n)]
        # Количество феромонов на ребре представим как тройку:
        # начальная вершина, конечная вершина и кол-во феромона
        self.ph = []
        self.newPh = []
        # Граф неориентированный, поэтому d[i][j] = d[j][i]
        for i in range (0, n):
            for j in range (i + 1, n):
                # Задаем случайное значение длины пути
                r = random.randint(1, 10)
                self.distances[i][j], self.distances[j][i] = int(r), int(r)
                # Запоминаем вершину, задаем ей значение феромона
                self.ph.append([i, j, 1 / self.n])

        #qDebug("antsPosition {}".format(self.antsPositon))
        #qDebug("tabuList {}".format(self.tabuList))
        #qDebug("distances {}".format(self.distances))

    def getPh(self):
        return self.ph

    def getDistances(self):
        return self.distances

    def perform(self):
        # Создаем копию тех феромонов, которые были изначально
        self.newPh = self.ph.copy()
        # Пока муравьи не посетят все вершины
        for iter in range(self.iterations):
            while len(self.tabuList[0]) != self.n:
                # Для каждого муравья
                for ant in range(self.antsCount):

                    P = [0 for pos in range(self.n)]        # Переходные вероятности
                    taus = []     # Кол-во феромонов на пути к вершине
                    mus = []      # Привлекательность вершины

                    for i in range(self.n):
                        # Если вершина посещена
                        if i in self.tabuList[ant]:
                            # Ничего не добавляем
                            tau = 0
                            mu = 0
                        else:
                            # Иначе вычисляем tau и mu
                            tau = self.tau(i, self.antsPositon[ant])
                            mu = self.mu(i, self.antsPositon[ant])
                        # И сохраняем их
                        taus.append(tau)
                        mus.append(mu)

                    # Вычисляем переходные вероятности
                    '''         tau(i, j)^alpha * mu(i, j)^beta
                    P[i][j] = ------------------------------------
                              sum(tau(i, j)^alpha * mu(i, j)^beta)
                    где tau - количество феромонов на ребре
                        mu - привлекательность ребра (Принимаем за 1/distances[i][j])       '''

                    # sum(tau(i, j)^alpha * mu(i, j)^beta)
                    tmpsum = 0
                    for i in range(len(P)):
                        if taus[i] and mus[i] != 0:
                            tmpsum  += taus[i] ** self.alpha * mus[i] ** self.beta
                    for i in range(len(P)):
                        if taus[i] and mus[i] != 0:
                            P[i] = taus[i] ** self.alpha * mus[i] ** self.beta / tmpsum

                    # Муравей выбирает, куда ползти и стремительно ползет
                    if (ant in self.eliteAnts):
                        newAntPosition = self.chooseBestVertex(P)
                    else:
                        newAntPosition = self.chooseNewVertex(P)
                    self.roads[ant].append(newAntPosition)

                    # Оставляя за собой феромон
                    ''' newTau = (1 - rho) * tau[i][j] + delta(tau[i][j])
                        delta(tau[i][j]) = 1 / distances[i][j]'''
                    # В данном случае дельта равна мю
                    ph = (1 - self.rho) * self.tau(newAntPosition, self.antsPositon[ant]) + self.mu(newAntPosition, self.antsPositon[ant])
                    self.updatePh(self.antsPositon[ant], newAntPosition, ph)
                    # При этом в начальную точку он больше не вернется
                    self.antsPositon[ant] = newAntPosition
                    self.tabuList[ant].append(newAntPosition)

                    self.sums[ant] += ph
                # И ЗАПИСЫВАЕМ НОВЫЕ ЗНАЧЕНИЯ ФЕРОМОНА
                self.ph = self.newPh.copy()
            for currentPh in self.ph:
                currentPh[2] *= self.rho

            best = self.sums.index(min(self.sums))
            qDebug("Epoch {} best route {}, contains: {} with feromone {} and length {}".format(iter, best, self.roads[best], self.sums[best], sum(self.distances[best])))

            self.restore()

    def restore(self):
        self.tabuList = [[] for j in range(self.antsCount)]
        self.sums.clear()
        self.roads.clear()
        for i in range(0, len(self.antsPositon)):
            self.tabuList[i].append(self.antsPositon[i])
            self.roads.append([i])
            self.sums.append(0)

    # Обновляет количество феромона на ребре
    def updatePh(self, start, end, ph):
        if start > end:
            start, end = end, start
        # записываем в ОБНОВЛЕННЫЕ ФЕРОМОНЫ
        for currentPh in self.newPh:
            if currentPh[0] == start and currentPh[1] == end:
                currentPh[2] += ph
                return

    # Возвращает количество феромонов на ребре между вершинами i и j
    def tau(self, start, end):
        if start > end:
            start, end = end, start
        for currentPh in self.ph:
            if currentPh[0] == start and currentPh[1] == end:
                return currentPh[2]

    # Возвращает привлекательность ребра
    def mu(self, start, end):
        if start > end:
            start, end = end, start
        # А привлекательность берем как обратную величину от расстояния
        return 1 / self.distances[start][end]

    # Возвращает индекс вершины, в которую перейдет ЭЛИТНЫЙ муравей при вероятностях перехода Р
    def chooseBestVertex(self, P):
        return P.index(max(P))
    # Возвращает индекс вершины, в которую перейдет муравей при вероятностях перехода Р
    def chooseNewVertex(self, P):
        r = random.random()
        #qDebug("{} {}".format(r, P))
        tmp = 0
        for i in range(len(P)):
            tmp += P[i]
            if tmp > r:
                #qDebug("result is {}".format(i))
                return i
        '''for i in range(len(P)):
            qDebug("{}".format(P[0:i]))

            if sum(P[:i]) >= r:
                #if P[i] == 0:
                    #return i + 1
                qDebug("result is {}".format(i))
                return i + 1'''
