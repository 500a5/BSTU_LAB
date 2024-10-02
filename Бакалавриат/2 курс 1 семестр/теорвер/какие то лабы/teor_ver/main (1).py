import numpy as np
from random import uniform
from math import log
from math import sqrt
import matplotlib.pyplot as plt


def get_table_for_first_task(n, i, j, k):
    x = np.array([i + j - k, i - j + k, j + k - i, i + j + k])
    p = np.array([(2*i + k) / (3*(i+j+k)), (2*j + k) / (3*(i+j+k)), k / (3*(i+j+k)), (i + j) / (3*(i+j+k))])
    print(x)
    print(p)
    digits = []
    random_table = []
    for _ in range(n):
        rand = uniform(0, 1)
        digits.append(rand)
        for i in range(len(p)):
            a = sum(p[:i])
            b = a + p[i]
            if a < rand < b:
                random_table.append(x[i])
                break
    for item in x:
        print('{} - {}'.format(item, random_table.count(item)))
    print(np.around(digits, 4))
    return np.array(sorted(random_table), dtype='int')


def get_random_array(array_size, sigma):
    return np.array(sorted([log(uniform(0, 1))*(-1/sigma) for _ in range(array_size)]), dtype='float32')


def get_mx(random_table):
    return sum(random_table)/random_table.shape[0]


def get_dx(random_table):
    # return sum((random_table - get_mx(random_table))**2)/random_table.shape[0]
    return np.var(random_table)


def first_task():
    my_sigma = 4 / 2

    size = 50
    table = get_table_for_first_task(n=size, i=1, j=3, k=2)
    print(table)
    plt.hist(table)
    plt.show()
    print("Sigma = {}".format(my_sigma))

    middle = sum(table)/size
    disp = sum([(x - middle)**2 for x in table])/size
    correct_disp = disp*size/(size-1)
    print("======================================")
    print("Мат ожидание MX = {:10f}      ".format(get_mx(table)))
    print("Дисперсия DX = {:10f}      ".format(get_dx(table)))
    print("Выборочное среднее = {:10f}    ".format(middle))
    print("Выборочная дисперсия = {:10f}  ".format(disp))
    print("Исправленная дисперсия = {:10f}".format(correct_disp))
    print("Показательное = {:10f}      ".format(1/middle))
    print("Равномерное: a={:5f} | b={:5f} ".format(middle-sqrt(3*correct_disp), middle+sqrt(3*correct_disp)))
    print("======================================")
    table = get_random_array(size, my_sigma)
    print(np.around(table, decimals=4))
    plt.hist(table)
    plt.show()
    plt.hist(table)
    plt.show()
    middle = sum(table) / size
    disp = sum([(x - middle) ** 2 for x in table]) / size
    correct_disp = disp * size / (size - 1)
    print("Мат ожидание MX = {:10f}   ".format(get_mx(table)))
    print("Дисперсия DX = {:10f}   ".format(get_dx(table)))
    print("Выборочное среднее = {:10f}    ".format(middle))
    print("Выборочная дисперсия = {:10f}  ".format(disp))
    print("Исправленная дисперсия = {:10f}".format(correct_disp))
    print("======================================")


if __name__ == '__main__':
    first_task()
