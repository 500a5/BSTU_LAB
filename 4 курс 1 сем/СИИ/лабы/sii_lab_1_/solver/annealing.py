from math import exp
from random import random
from typing import List
from .utils import create_init_vector, tweak_vector, compute_energy


class Solution:
    def __init__(self, init_solution: List[int] = None):
        if init_solution:
            self.solution = init_solution.copy()
        else:
            self.solution = None

    @staticmethod
    def get_init_solution(size: int):
        return Solution(create_init_vector(size))

    def tweak(self):
        self.solution = tweak_vector(self.solution)

    @property
    def energy(self):
        return compute_energy(self.solution)

    def copy(self):
        return Solution(self.solution)


class SimulatedAnnealing:
    def __init__(
            self,
            initial_temperature: float,
            final_temperature: float,
            alfa_for_temperature: float,
            steps_per_change: int,
            count_figures: int
    ):
        self.init_t = initial_temperature
        self.final_t = final_temperature
        self.alpha = alfa_for_temperature
        self.steps_per_change = steps_per_change
        self.count_figures = count_figures

        self.time = 0
        self.t_stats = []
        self.bed_statistic = []
        self.best_stats = []

    def __add_point(self, statistic: List[dict], y: float):
        statistic.append({"x": self.time, "y": y})

    def get_solution(self) -> Solution:
        t = self.init_t
        cur = Solution.get_init_solution(self.count_figures)
        in_work = cur.copy()
        best = cur.copy()

        self.__add_point(self.best_stats, best.energy)
        self.__add_point(self.t_stats, t)

        while t > self.final_t:
            count_bad = 0
            for _ in range(self.steps_per_change):
                in_work.tweak()
                cur_energy = cur.energy
                work_energy = in_work.energy
                p = exp(-(work_energy - cur_energy) / t)
                check_p = p > random()
                if check_p:
                    count_bad += 1
                if work_energy <= cur_energy:
                    cur = in_work.copy()
                if (work_energy > cur_energy) and check_p:
                    cur = in_work.copy()
                if in_work.energy < best.energy:
                    best = in_work.copy()
                    self.__add_point(self.best_stats, best.energy)
                else:
                    in_work = cur.copy()
                self.time += 1
            self.__add_point(self.bed_statistic, count_bad)
            t *= self.alpha
            self.__add_point(self.t_stats, t)
        return best
