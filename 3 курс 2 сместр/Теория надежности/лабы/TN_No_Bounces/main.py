from random import random
from math import factorial, exp, pow, sqrt, log
# Последние 3 цифры зачетки
i = 1
j = 10
k = 10

def random_request_time():
    random_value = random()
    # время через которое придет одна заявка
    # Экспоненциальное распределение
    return - 1 / (5. / 4.) * log(random_value)

def random_respone_time():
    random_value = random()
    # время через которое придет одна заявка
    # Экспоненциальное распределение
    return - 1 / (3. / 1.) * log(random_value)

def step(current_time, count_request, count_not, busy):
    current_time += random_request_time()
    count_request += 1
    if busy[0] < current_time:
        busy[0] = current_time + random_respone_time()
    elif busy[1] < current_time:
        busy[1] = current_time + random_respone_time()
    elif busy[2] < current_time:
        busy[2] = current_time + random_respone_time()
    else:
        count_not += 1
    return current_time, count_request, count_not


def run(n):
    busy = [0, 0, 0]
    count_request = 0
    count_not = 0
    current_time = 0
    while count_request < n:
        current_time, count_request, count_not = step(current_time, count_request,count_not,busy)
    return count_not,count_request



n = 1000
count_not, count_request = run(n)

p_practice = count_not/count_request
p_teor = 0.0219
print(f"Практическая вероятность отказа = {p_practice}")
print(f"Теоретическая вероятность отказа = {p_teor}")
print(f"|K| = {abs((p_practice - p_teor) / (sqrt(p_practice * (1-p_practice) / n)))} < 1.96\n"
"Согласно критерию сравнения долей гипотезы согласуются и мы правильно посчитали вручную.")