from random import random
# Последние 3 цифры зачетки
i = 1
j = 10
k = 10

class Drinkard:
    def __init__(self, start_state):
        self.start_state = start_state
        self.state = start_state

    # шаг пьяницы возвращает следующее состояние
    def step(self):
        random_value = random()

        if self.state == "Р":
            return self.state

        if self.state == "К":
            return self.state

        if self.state == "Л":
            if random_value < (1. / 7.):
                self.state = "Р"
            else:
                self.state = "О"

            return self.state

        if self.state == "О":
            if random_value < (1. / 10.):
                self.state = "Л"
            elif random_value < (7. / 10.):
                self.state = "О"
            else:
                self.state = "П"

            return self.state

        if self.state == "П":
            if random_value < (6. / 9.):
                self.state = "К"
            else:
                self.state = "О"

            return self.state

    # возвращает пару (время жизни, в какое состояние канул)
    def run_to_die(self):
        self.state = self.start_state
        count_step = 0

        while True:
            count_step += 1
            self.step()
            if ((self.state == "Р") or (self.state == "К")):
                return count_step, self.state





# создаем пьяницу с начальным состоянием Л(стоит на левой ноге)
pianino = Drinkard("Л")
n = 10000
generate_result = [pianino.run_to_die() for _ in range(n)]

generate_last_states = [state for _, state in generate_result]
generate_time_life = [time for time, _ in generate_result]

print(generate_last_states)
print(generate_time_life)


avg_die_time = sum(generate_time_life) / len(generate_time_life)
p_die_in_river = generate_last_states.count("Р") / len(generate_last_states)

print(f"Среднее время жизни: {avg_die_time}")
print(f"Вероятность помереть в реке: {p_die_in_river}")


# сравнение долей
from math import sqrt

gen_p = p_die_in_river
# теоритическая вероятность из расчетов ручками
teor_p = 1. / 5.
print(f"|K| = {abs((gen_p - teor_p) / (sqrt(gen_p * (1 - gen_p) / n)))} < 1.96\n"
      "как мы видим гипотеза верна")




