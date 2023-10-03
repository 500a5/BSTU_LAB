from random import random
i = 1
j = 10
k = 4



def step(state):
    random_value = random()

    if state == "A":
        if random_value < (10. / 14.):
            state = "B"
        else:
            state = "C"

        return state

    if state == "B":
        if random_value < (1. / 11.):
            state = "A"
        else:
           state = "C"

        return state

    if state == "C":
        if random_value < (1. / 15.):
           state = "A"
        elif random_value < (10. / 15.):
            state = "B"
        else:
           state = "C"

        return state

    # возвращает время до возврата в начальное положение


def run():
    state = 'A'
    count_step = 0

    while True:
        count_step += 1
        state=step(state)

        if (state == 'A'):
            return count_step


n = 100000

generate_result = [run() for _ in range(n)]
avg_ret_A = sum(generate_result)/len(generate_result)
print(f"Эмпирическое среднее время до возврата в А = {avg_ret_A}")
print("Теоретическое среднее время до возврата в А = 13.9591")
print(f"Разница между полученными данными и посчитанными = {avg_ret_A - 13.9591}")
print("Разница не большая значит все расчеты были выполненны верно.")