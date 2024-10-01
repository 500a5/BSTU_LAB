import random
import matplotlib.pyplot as plt
import math

#Функция возвращающая значение СВ
def get_f():
    h = 2 * 1e-6
    i = 0
    res = list()
    x = list()
    b = math.e ** 2 - 1
    while i < 2:
        x.append(i)
        res.append(math.e ** i / b)
        i += h
    return x, res
def get_value(v):
    return math.log((math.e ** 2 - 1) * v + 1)
#Функция генерирующая выборку из N чисел
def get_samp(N):
    samp = list()              #Выборка
    for i in range(N):
        samp.append(get_value(random.random()))     #Добавляем в выборку число полученое по выведенной формуле
    return samp

samp = get_samp(1000)
plt.hist(samp, density=True, bins=30)
x, samp2 = get_f()
plt.plot(x, samp2)
plt.show()
