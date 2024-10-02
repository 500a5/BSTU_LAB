import random
import matplotlib.pyplot as plt
import math
import numpy as np


def get_f(sigm, m, N):
    h = 35 / N
    i = -10
    res = list()
    x = list()
    a = 1 / (sigm * math.sqrt(math.pi * 2))
    while i < 30:
        x.append(i)
        res.append(a * math.exp(-(i - m) ** 2 / (2 * sigm ** 2)))
        i += h
    return x, res


# Функция возвращающая eps
def get_eps(N):
    sum = 0
    for i in range(N):
        sum += random.random()
    return sum


# функция генерирующая выборку
def get_nsamp(sg_eps, m_eps, sg, m, N, samp_sz):
    samp = list()
    for i in range(samp_sz):
        eps = get_eps(N)
        samp.append((eps - m_eps) / sg_eps * sg + m)
    return samp


samp = get_nsamp(0.82, 4, 1, 0.5, 8, 10000)
plt.hist(samp, density=True, bins=30)
x, samp2 = get_f(1, 0.5, 1000)
plt.plot(x, samp2)
plt.show()
