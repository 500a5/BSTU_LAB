# This Python file uses the following encoding: utf-8
import random
import math
import numpy as np
from PyQt5.QtWidgets import QMessageBox
from PyQt5.QtCore import qDebug
class Annealing:
    def __init__(self, t_min, t_max, alpha, n, iterations):
        # Входные параметры
        self.t_min = t_min
        self.t_max = t_max
        self.t_current = t_max
        self.alpha = alpha
        self.n = n
        self.iterations = iterations

        self.start_solution = self.initialize_solution()                # Начальное решение
        self.start_energy = self.check_conflicts(self.start_solution)   # Начальная энергия

        self.current_solution = self.start_solution.copy()                     # Рабочее решение
        self.current_energy = self.start_energy                         # Рабочая энергия

        self.best_solution = self.start_solution.copy()                        # Лучшее решение
        self.best_energy = self.start_energy                            # Лучшая энергия

        self.stats = {
            "iterations": [0],
            "bad_solutions": [0],
            "temperature": [self.t_max],
            "energy": [self.start_energy]

        }

    def check_conflicts(self, solution):
        dx = [-1, 1, -1, 1]
        dy = [-1, 1, 1, -1]
        board = []
        for i in range(0, self.n):
            str = []
            for j in range (0, self.n):
                if solution[i] == j:
                    str.append(1)
                else:
                    str.append(0)
            board.append(str)
        conflicts = 0
        for i in range(0, len(solution) - 1):
            x = i
            y = solution[i]
            for j in range(0, 3):
                tmpx = x
                tmpy = y
                while 1:
                    tmpx = tmpx + dx[j]
                    tmpy = tmpy + dy[j]
                    if tmpx < 0 or tmpx >= self.n or tmpy < 0 or tmpy >= self.n:
                        break
                    if board[tmpx][tmpy] == 1:
                        conflicts += 1
        return conflicts

    def initialize_solution(self):
        solution = []
        for i in range (0, self.n):
            #r = random.randint(0, self.n-1)
            #while r in solution:
             #   r = random.randint(0, self.n-1)
            solution.append(i)
          #  solution.append(r)
        return solution

    def generate_swappos(self):
        v = random.sample(range(0, self.n - 1), 2)
        return v[0], v[1]

    def calculate(self):

        total_iterations = 0
        while self.t_current > self.t_min:
            bad_solutions = 0
            for current_iteration in range(self.iterations - 1):
                usenew = 0
                # Берем рабочее решение
                solution = self.current_solution.copy()
                # Аналогично для энергии
                energy = self.current_energy
                # Получаем два случайных неодинаковых числа:
                x, y = self.generate_swappos()
                # И обмениваем элементы в рабочем решении с индексами х и у:
                solution[x], solution[y] = solution[y], solution[x]
                # Проверяем, хорошее ли решение получилось
                energy = self.check_conflicts(solution)

                # Если рабочее решение оказалось лучше ЛУЧШЕГО
                if energy < self.current_energy:
                    usenew = 1
                    # Сохраняем его
                    #self.current_solution = solution.copy()
                  #  self.current_energy = energy
                    # И понижаем температуру ?
                    #self.t_current *= self.alpha # Проверить на большой выборке

                # А иначе
                else:
                    # Вычисляем коэффициент допуска
                    p = math.exp( -(energy - self.current_energy)/self.t_current)
                    # И если повезло, то
                    if p > random.random():
                        # Сохраняем заведомо плохое решение
                       # self.t_current *= self.alpha
                        #self.current_solution = solution.copy()
                        #self.current_energy = energy
                        bad_solutions += 1
                        usenew = 1
                # И проверяем, лучше ли рабочее решение оптимального
                if usenew:
                    usenew = 0
                    self.current_solution = solution.copy()
                    self.current_energy = energy

                if (self.current_energy < self.best_energy):
                    # Если да, то сохраняем как новое оптимальное
                    qDebug('!!! {} {}'.format(self.best_solution, self.current_solution))
                    self.best_solution = self.current_solution.copy()
                    self.best_energy = self.current_energy
                else:
                    solution=self.current_solution.copy
                    energy = self.current_energy
                # Сохраняем статистику для графиков:
            self.stats['iterations'].append(total_iterations)
            self.stats['bad_solutions'].append(bad_solutions/self.iterations)
            self.stats['temperature'].append(self.t_current)
            self.stats['energy'].append(self.best_energy)
            total_iterations += 1
            self.t_current *= self.alpha
            if self.current_energy == 0:
                msg = QMessageBox()
                msg.setIcon(QMessageBox.Information)
                return



























