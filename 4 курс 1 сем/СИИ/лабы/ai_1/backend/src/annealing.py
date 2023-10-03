from math import exp
from typing import List
from .solution import Solution
from random import random


class SimulatedAnnealing:
    def __init__(
            self,
            init_t: float,
            final_t: float,
            alpha: float,
            spc: int,
            count_f: int
    ):
        self.init_t = init_t
        self.final_t = final_t
        self.alpha = alpha
        self.spc = spc
        self.count_f = count_f

        self.time = 0
        self.temperature_statistic = []
        self.worst_statistic = []
        self.best_statistic = []

    def _append_statistic_point(self, statistic: List[dict], y: float):
        statistic.append({"x": self.time, "y": y})

    def get_solution(self) -> Solution:
        temperature = self.init_t

        current = Solution.get_init_solution(self.count_f)
        working = current.copy()
        best = current.copy()

        self._append_statistic_point(self.best_statistic, best.energy)
        self._append_statistic_point(self.temperature_statistic, temperature)

        while temperature > self.final_t:
            bads = 0

            for _ in range(self.spc):

                working.tweak()

                working_energy = working.energy
                current_energy = current.energy

                p = exp(-(working_energy - current_energy) / temperature)
                check_p = p > random()

                if check_p:
                    bads += 1

                if working_energy <= current_energy:
                    current = working.copy()

                if (working_energy > current_energy) and check_p:
                    current = working.copy()

                if working.energy < best.energy:
                    best = working.copy()
                    self._append_statistic_point(self.best_statistic, best.energy)
                else:
                    working = current.copy()

                self.time += 1

            self._append_statistic_point(self.worst_statistic, bads)

            temperature *= self.alpha
            self._append_statistic_point(self.temperature_statistic, temperature)

        return best
