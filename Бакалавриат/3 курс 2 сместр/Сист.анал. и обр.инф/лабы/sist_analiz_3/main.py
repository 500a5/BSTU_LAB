# Импорт нужных библиотек.
from math import cos, log, e, floor,sin,pow
from random import normalvariate
from numpy.linalg import solve
from matplotlib.pyplot import subplots, plot, scatter, legend, show


# Исходная функция.
def source_func(x: float) -> float:
    return (sin(cos(x)+x)-x*x)

# Аппроксимирующий полином.
def approximating_func(x: float, i: float) -> float:
    return (cos(i*x)+pow(x,i))


# Фунция вывода матрицы matrix с заголовком header.
def print_matrix(header: str, matrix: list) -> None:
    print(header, '{', sep='')
    for row in matrix:
        print('\t', sep='', end='')
        for element in row:
            print('{0:7.4}'.format(element), end=' ')
        print()
    print('}')


# Возвращает транспонированную к матрице matrix.
def transpose_matrix(matrix: list) -> list:
    return [[matrix[i][j] for i in range(len(matrix))] for j in
range(len(matrix[0]))]


# Возвращает диагольную матрицу, элементами которой являются array[i] ^power.
def diagonal_powered_matrix(array: list, power: float) -> list:
    size = len(array)
    matrix = [[0. for j in range(size)] for i in range(size)]
    for i in range(size):
        matrix[i][i] = array[i] ** power
    return matrix


# Возвращает произведение матриц a и b.
def matrix_product(a: list, b: list) -> list:
    l_size = len(a)
    m_size = len(b)
    n_size = len(b[0])

    if m_size != len(a[0]):
        raise Exception('Sizes error.')

    matrix = [[0. for j in range(n_size)] for i in range(l_size)]
    for i in range(l_size):
        for j in range(n_size):
            for k in range(m_size):
                matrix[i][j] += a[i][k] * b[k][j]
    return matrix


# Возвращает значение в точке по вектору z с n точками в пределах [a, b].
def get_approximate_value(approximate_matr: list, x: float, a: float, b: float, n: int) -> float:
    dn = (b - a) / (n - 1)
    index_x = (x - a) / dn
    floor_x = int(floor(index_x))
    frac_x = index_x - floor_x
    if abs(frac_x) < 0.0000000001:
        return approximate_matr[0][floor_x]
    else:
        return frac_x * (approximate_matr[0][floor_x] + approximate_matr[0][floor_x + 1])


if __name__ == '__main__':
    # Диапозон значений.
    a_limit = 1.
    b_limit = 10.
    # Количество значений.
    n = 11
    # Количество аппроксимирующих функций.
    k = 4
    # Находим длину каждого отрезка.
    dn = (b_limit - a_limit) / (n - 1)
    # Вектор точек (аргументов).
    x = [[a_limit + dn * i for i in range(n)]]
    # Вектор значений функции.
    y = [[source_func(x) for x in x[0]]]
    # Математическое ожидание и среднеквадратическое отклонение.
    mu = 0
    sigma = 5
    # Вектор среднеквадратических погрешностей измерений.
    s = [[normalvariate(mu, sigma) for i in range(n)]]
    # Вектор измерений.
    w = [[y[0][i] + s[0][i] for i in range(n)]]
    # W^T.
    wt = transpose_matrix(w)
    # Матрица M.

    m = [[approximating_func(x[0][i], j + 1) for j in range(k)] for i in range(n)]
    # M^T.
    mt = transpose_matrix(m)
    # Диагональная матрцица D.
    d = diagonal_powered_matrix(s[0], -2)
    # Произведение M^T * D.
    mt_d = matrix_product(mt, d)
    # Левая часть: M^T * D * M.
    left = matrix_product(mt_d, m)
    # Правая часть: M^T * D * W^T.
    right = matrix_product(mt_d, wt)
    # Вектора A получаем решением полученной системы.
    a = solve(left, right)
    # Z = M * A.
    z = matrix_product(m, a)
    # Z^T.
    zt = transpose_matrix(z)
    if 1:
        print_matrix('X: ', x)
        print_matrix('S: ', s)
        print_matrix('W: ', w)
        print_matrix('W**T: ', wt)
        print_matrix('M: ', m)
        print_matrix('M**T: ', mt)
        print_matrix('D: ', d)
        print_matrix('Left: ', left)
        print_matrix('Right: ', right)
        print_matrix('A: ', a)
        print_matrix('Z: ', z)
        print_matrix('X: ', x)
        print_matrix('Y: ', y)
        print_matrix('Z**T: ', zt)

    print('Y(4.5)=', source_func(4.5))
    print('Z(4.5)=', get_approximate_value(zt, 4.5, a_limit, b_limit,n))
    print('Y(9.5)=', source_func(9.5))
    print('Z(9.5)=', get_approximate_value(zt, 9.5, a_limit, b_limit,n))
    fig, ax = subplots()
    ax.scatter(x[0], w[0], label='W', color='gray', s=15)
    ax.plot(x[0], zt[0], label='Z')
    ax.legend()
    show()