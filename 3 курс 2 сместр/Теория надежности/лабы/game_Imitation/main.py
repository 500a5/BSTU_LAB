from random import random
from scipy.stats import chisquare
from math import sqrt
from matplotlib import pyplot as plt

# Последние 3 цифры зачетки
i = 1
j = 10
k = 4

# Вероятности
p_list = [
    i/(2*(i+j+k)),
    (j+k)/(2*(i+j+k)),
    (i+k)/(2*(i+j+k)),
    j/(2*(i+j+k))
]
print("Вероятности")
for i, p in enumerate(p_list):
    print(f"P{i} = {p}")


class Discrete_Random_Variable:
    def __init__(self, p_list):
        self.p_list = p_list
        self.split_segment = self.get_split_segment(p_list)


    @staticmethod
    def get_split_segment(p_list):
        split_segment = p_list.copy()
        for i in range(len(split_segment)-1):
            split_segment[i+1] += split_segment[i]
        return split_segment


    def get_drv_value(self):
        random_value = random()
        segment = 0

        while random_value >= self.split_segment[segment]:
            segment += 1

        return segment


drv = Discrete_Random_Variable(p_list)
n = 100000
generated_p_values = [drv.get_drv_value() for _ in range(n)]
print("Ваша выборка (10000)")
print(generated_p_values)


p = [current_p*n for current_p in p_list]
print("Теоретические частоты")
print(p)


generated_p = [generated_p_values.count(p) for p in range(len(p_list))]
print("Наблюдаемые частоты")
print(generated_p)


K, P = chisquare(generated_p, p)
print(f"Xi^2 K={K}, p={P}\n")
print("Сравнение долей")
i=0
for p_index in range(len(p)):
    i=i+1
    gen_p  = generated_p[p_index] / n
    teor_p = p[p_index] / n
    print(f"Вероятность из полученной выборки {gen_p}\n"
           f"Теоретическая вероятность {teor_p}")
    print(f"K для P{i} = {abs((gen_p - teor_p) / (sqrt(gen_p * (1-gen_p) / n)))}\n")


print("Выборка")
plt.plot(generated_p)
plt.show()

print("Заданное распределение")
plt.plot(p_list)
plt.show()

