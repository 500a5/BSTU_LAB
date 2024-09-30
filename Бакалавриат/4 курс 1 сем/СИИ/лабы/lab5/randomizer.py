# This Python file uses the following encoding: utf-8

import random

class Randomizer:
    @staticmethod
    def get_int_list(size, first_val, last_val):
        result = []
        for i in range(0, size):
            result.append(random.randint(first_val, last_val))
        return result

    @staticmethod
    def get_two_dim_int_list(rows, cols, first_val, last_val):
        result = []
        for i in range (0, rows):
            result.append(Randomizer.get_int_list(cols, first_val, last_val))
        return result

    @staticmethod
    def swap_list_elements(list, errors):
        new_list = list.copy()
        pos1 = random.randint(0, len(list) - 1)
        pos2 = random.randint(0, len(list) - 1)

        new_list[pos1], new_list[pos2] = new_list[pos2], new_list[pos1]
        return new_list
