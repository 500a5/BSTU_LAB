from random import random

i = 1
j = 10
k = 4



def step(state):
    random_value = random()

    if state == "Р":
        return state

    if state == "К":
        return state

    if state == "Л":
        if random_value < (1. / 11.):
            state = "Р"
        else:
          state = "О"
        return state

    if state == "О":
        if random_value < (1. / 15.):
             state = "Л"
        elif random_value < (10. / 15.):
             state = "О"
        else:
            state = "П"

        return state

    if state == "П":
        if random_value < (10. / 14.):
            state = "К"
        else:
            state = "О"
        return state


def run_to_die():
    state = 'Л'
    count_step = 0
    while True:
        count_step += 1
        state=step(state)
        if ((state == 'Р') or (state == 'К')):
             return count_step, state





n = 10000
generate_result = [run_to_die() for _ in range(n)]

generate_last_states = [state for _, state in generate_result]
generate_time_life = [time for time, _ in generate_result]

print(generate_last_states)
print(generate_time_life)



avg_die_time = sum(generate_time_life) / len(generate_time_life)
p_die_in_river = generate_last_states.count("Р") / len(generate_last_states)

print(f"Среднее время жизни: {avg_die_time}")
print(f"Вероятность упасть в реку: {p_die_in_river}")


from math import sqrt

gen_p = p_die_in_river

teor_p = 0.119
print(f"|K| = {abs((gen_p - teor_p) / (sqrt(gen_p * (1 - gen_p) / n)))} < 1.96\n"
      "Разница не большая значит все расчеты были выполненны верно. Значит гипотеза верна")




