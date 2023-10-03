# This Python file uses the following encoding: utf-8

import random

from PyQt5.QtCore import qDebug

class randomizer:
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
            result.append(randomizer.get_int_list(cols, first_val, last_val))
        return result

