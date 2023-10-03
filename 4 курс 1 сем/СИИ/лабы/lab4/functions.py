# This Python file uses the following encoding: utf-8
import math

class Functions:
    class Sigmoid:
        def  __init__(self):
            pass
        def f(x):
            return 1 / (1 + math.exp(-x))
        def g(self, x):
            return self.f(x) * (1 - self.f(x))
