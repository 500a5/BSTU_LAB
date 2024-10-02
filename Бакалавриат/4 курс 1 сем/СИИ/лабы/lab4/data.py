# This Python file uses the following encoding: utf-8
from PySide2 import QtWidgets

from random import randint

class Data:
    def __init__(self):
        self.symbols = [
            [0, 0, 1, 0, 0,
             0, 1, 0, 1, 0,
             1, 1, 1, 1, 1,
             1, 0, 0, 0, 1,
             1, 0, 0, 0, 1],

            [1, 1, 1, 0, 0,
             1, 0, 0, 0, 0,
             1, 1, 1, 0, 0,
             1, 0, 1, 0, 0,
             1, 1, 1, 0, 0],

            [1, 0, 0, 0, 1,
             1, 1, 0, 1, 1,
             1, 0, 1, 0, 1,
             1, 0, 0, 0, 1,
             1, 0, 0, 0, 1],

            [0, 0, 1, 0, 0,
             0, 1, 0, 1, 0,
             0, 1, 0, 1, 0,
             1, 1, 1, 1, 1,
             1, 0, 0, 0, 1],

            [1, 1, 1, 0, 0,
             1, 0, 0, 0, 0,
             1, 1, 1, 0, 0,
             1, 0, 0, 0, 0,
             1, 1, 1, 0, 0],
        ]
        self.types = [0, 1, 2, 3, 4]
        self.labels = ['А', 'Б', 'М', 'Д', 'Е' ]

    def generate_similar_symbol(self, index, errors):
        symbol = self.symbols[index].copy()
        for s in range(errors):
            i = randint(0, len(self.symbols[index]) - 1)
            if symbol[i] == 1:
                symbol[i] = 0
            else:
                symbol[i] = 1
        return symbol

    def generate_symbols(self, size, errors):
        types = self.types.copy()
        for i in range(size):
            for index in types:
                self.symbols.append(self.generate_similar_symbol(index, errors))
                self.types.append(index)

    def get_data(self):
        return self.symbols
