from typing import List
from random import randint


def tweak_vector(vector: List[int]) -> List[int]:
    tweaked_vector = vector.copy()
    tweaked_vector_last_index = len(tweaked_vector) - 1

    def _get_random_index():
        return randint(0, tweaked_vector_last_index)

    first_index = _get_random_index()

    second_index = _get_random_index()
    while first_index == second_index:
        second_index = _get_random_index()

    tweaked_vector[first_index], tweaked_vector[second_index] = \
        tweaked_vector[second_index], tweaked_vector[first_index]

    return tweaked_vector


def create_init_vector(size: int) -> List[int]:
    vector = [el for el in range(size)]

    for _ in range(size):
        vector = tweak_vector(vector)

    return vector


def compute_energy(solution: [int]) -> int:
    conflicts = 0

    for index, figure in enumerate(solution):
        for testing_index, testing_figure in enumerate(solution):
            if index == testing_index:
                continue

            diff_index = abs(testing_index - index)

            # тут два случая не разделяются потому что в одной колонне не может быть двух ферзей одновременно
            if figure in [testing_figure + diff_index, testing_figure - diff_index]:
                conflicts += 1

    return conflicts
