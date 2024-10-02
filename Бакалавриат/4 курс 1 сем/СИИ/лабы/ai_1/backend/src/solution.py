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
