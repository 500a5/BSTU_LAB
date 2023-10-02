import numpy as np
from math import sin
from math import cos
import scipy.integrate as si
import matplotlib.pyplot as plt


# Правая часть уравнения
def function(args, t):
    # Константы
    g = 9.86
    l = 1
    k = 1000
    m_1 = 10
    m_2 = 5
    # Распаковываем набор переменных
    x, fi, v, w = args
    l = l + x
    iner = m_2*l*l
    return [v,
            w,
            (-k * x + m_2 * g * fi + m_2 * (w*l)**2 / l) / m_1,
            (-m_2 * g * l * fi - 2 * m_2 * w * w * l * l) / iner]


# Правая часть уравнения
def function_2(args, t):
    # Константы
    k_1 = 10_000
    k_2 = 12_000
    m_1 = 12
    m_2 = 1
    l = 1
    n_0 = 1
    j = 8
    g = 9.8
    a = 3.14/3
    # Распаковываем набор переменных
    x, fi, v, w = args
    dp = l * fi

    return [v,
            w,
            (-k_2 * (x - dp) + m_2 * g * sin(a)) / m_1,
            (-k_2 * dp * l - (k_1 * dp * l) / 4 + m_1 * g * sin(fi) * 0.5) / j]


def main():
    # Задаем константы
    first = 0.0
    last = 5.0
    step = 0.02
    # Массив точек, по которым интегрируем
    t = np.arange(first, last, step)
    # Начальное условие, массив, каждый элемент которого - началье значение параметра в точке first
    y0 = [0, 0, -0.2, 0.2]
    solution = si.odeint(function_2, y0, t)
    print(solution)

    plt.plot(t, solution[:, :2])

    plt.plot(t, solution[:, 0], 'g', label='X(t)')
    plt.plot(t, solution[:, 1], 'r', label='FI(t)')
    # plt.plot(t, solution[:, 2], 'g', label='V(t)')
    # plt.plot(t, solution[:, 3], 'b', label='W(t)')
    plt.legend(loc='best')
    plt.xlabel('t')
    plt.grid()
    plt.show()


if __name__ == "__main__":
    main()
