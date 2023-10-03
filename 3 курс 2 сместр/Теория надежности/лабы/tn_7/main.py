import random

# Вероятности безотказной работы i-го элемента.
# Задаются с помощью функций init_with_. p1 = p2 = p3 = p4 = p5 = p6 = 0

# Инициализирует вероятности 1-6 одним значением p_value.
def init_with_one(p_value):
    global p1, p2, p3, p4, p5, p6

    p1 = p2 = p3 = p4 = p5 = p6 = p_value

# Инициализирует вероятности 1-5 значением p12345_value, а 6 - p6_value.
def init_with_two(p12345_value, p6_value):
    global p1, p2, p3, p4, p5, p6

    p1 = p2 = p3 = p4 = p5 = p12345_value
    p6 = p6_value

# Инициализирует вероятности 1 - p1_v, 2 - p2_v, ..., p6 - p6_v.
def init_with_all(p1_v, p2_v, p3_v, p4_v, p5_v, p6_v):
    global p1, p2, p3, p4, p5, p6

    p1, p2, p3, p4, p5, p6 = p1_v, p2_v, p3_v, p4_v, p5_v, p6_v

# Выводит теоретические вероятности безотказной работы.
# Выводит результат имитации для n повторений.
def task_and_simulate(n):
    p_t = task()
    p_p = simulate(n)

    print_p_values()
    print('percentage: {0:.4}%\n'.format(abs(p_p - p_t) / p_t * 100.))

# Выводит теоретические вероятности безотказной работы.
def task():
    task_limits()
    p = task_for_p()
    task_for_gp()
    task_for_gq()

    return p

    # Выводит нижнюю и верхнюю оценку вероятности безотказной работы.
def task_limits():
    global p1, p2, p3, p4, p5, p6

    q1, q2, q3, q4, q5, q6 = 1 - p1, 1 - p2, 1 - p3, 1 - p4, 1 - p5, 1- p6



    min_lim = (1 - q1 * q2 * q3 * q4 * q5) * (1 - q6)
    max_lim = 1 - (1 - p1 * p6) * (1 - p2 * p6) * (1 - p3 * p6) * (1 - p4 * p6) * (1 -p5*p6)

    print_p_values()
    print('limits: {0:.4} <= p <= {1:.4}'.format(min_lim, max_lim))

    # Выводит значения вероятностей p1, p2, ..., p6.
def print_p_values():
    global p1, p2, p3, p4, p5, p6

    print('[{0}, {1}, {2}, {3}, {4}, {5}]\t '.format(p1, p2, p3, p4, p5, p6), sep='', end='')

    # Возвращает и выводит теоретическую вероятность безотказной работы,
    # полученную методом, основанным на теоремах теории вероятности.
def task_for_p() -> float:
    global p1, p2, p3, p4, p5, p6

    q1, q2, q3, q4, q5, q6 = 1 - p1, 1 - p2, 1 - p3, 1 - p4, 1 - p5, 1- p6

    p_n12345 = q1 * q2 * q3 * q4 * q5
    p_n6 = q6
    p = (1 - p_n12345) * (1 - p_n6)
    print_p_values()
    print('[t_p ] p={0:.4}'.format(p))

    return p

    # Выводит теоретическую вероятность безотказной работы по минимальным путям.
def task_for_gp():
    global p1, p2, p3, p4, p5, p6

    p45 = p4 + p5
    p345 = p3 + p45
    p2345 = p2 + p345
    p12345 = p1 + p2345


    p_45 = p4 * p5
    p_345 = p3 * p_45
    p_2345 = p2 * p_345
    p_12345 = p1 * p_2345

    pb = p3 * p45 + p_45
    pa = p2 * p345 + pb

    p = p6 * (p12345 - p1 * p2345 - pa + p1 * pa + p2 * pb + p_345 - p1 * (
            p2 * (p3 * p45 + p_45) + p_345) - p_2345 + p_12345)

    print_p_values()
    print('[t_gp ] p={0:.4}'.format(p))


# Выводит теоретическую вероятность безотказной работы по минимальным сечениям.
def task_for_gq():
    global p1, p2, p3, p4, p5, p6


    q1, q2, q3, q4, q5, q6 = 1 - p1, 1 - p2, 1 - p3, 1 - p4, 1 - p5, 1- p6

    p = 1 - q1 * q2 * q3 * q4 * q5 - q6 + q1 * q2 * q3 * q4 * q5 * q6
    print_p_values()
    print('[t_gq ] p={0:.4}'.format(p))


# Возвращает и выводит результат имитации для n повторений.
def simulate(n) -> float:
    global p1, p2, p3, p4, p5, p6


    p = 0.
    for i in range(n):
      p += step()
    p /= n

    print_p_values()
    print('[p	] p={0:.4}'.format(p))

    return p


# Выполняет одно повторение (проход системы):
# Возвращает 1, если система успешно отработала, иначе - 0.
def step() -> int:
    global p1, p2, p3, p4, p5, p6


    if random.random() > p1:
        if random.random() > p2:
         if random.random() > p3:
              if random.random() > p4:
                 if random.random() > p5:
                        return 0

    if random.random() > p6:
     return 0
    return 1

if __name__ == ' main ':
    n_repeats = 1000000

    init_with_one(0.5)
    task_and_simulate(n_repeats)

    init_with_two(0.7, 0.3)
    task_and_simulate(n_repeats)

    init_with_all(0.1, 0.2, 0.3, 0.4, 0.5, 0.6)
    task_and_simulate(n_repeats)
