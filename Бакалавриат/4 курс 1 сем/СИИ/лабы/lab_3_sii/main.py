from antAlgorithm import *
import tkinter as tk
import time


# Запись в окно вывода
def print_textbox(text_box, message):
    text_box.delete('1.0', tk.END)
    text_box.insert(1.0, message)
    message = str()


# Считывание целочисленного числа
def get_int_value(entry):
    value = entry.get()
    try:
        return int(value)
    except ValueError:
        return None


# Считывание вещественного числа
def get_float_value(entry):
    value = entry.get()
    try:
        return float(value)
    except ValueError:
        return None


# Запуск алгоритма
def start_alg(entries, text_box):
    (entry_ants, entry_spots, entry_alpha, entry_beta,
     entry_rho, entry_q, entry_max_distance) = entries

    ants = get_int_value(entry_ants)
    spots = get_int_value(entry_spots)
    alpha = get_float_value(entry_alpha)
    beta = get_float_value(entry_beta)
    rho = get_float_value(entry_rho)
    q = get_int_value(entry_q)
    max_dist = get_int_value(entry_max_distance)

    text_msg = str()
    try:
        start_time = time.time()
        global colony
        colony = Colony(ants, spots, alpha, beta, rho, q, max_dist)

        text_msg = 'Производится решение задачи коммивояжера для '
        text_msg += str(spots)
        text_msg += ' узлов(-а) и '
        text_msg += str(ants)
        text_msg += ' агента(-ов)\n'

        text_msg += 'Сгенерирован граф:\n'
        travel_map = colony.get_generated_spots()
        for path in travel_map:
            text_msg += str(sorted(list(path)))
            text_msg += '\t- '
            text_msg += str(travel_map[path][0])
            text_msg += '\n'

        best_ants = colony.get_best_ants()
        text_msg += '\nВо время работы алгоритма, было обнаружено '
        text_msg += str(len(best_ants))
        text_msg += ' лучших путей:\n'

        counter = 1
        for ant in best_ants:
            text_msg += 'Путь '
            text_msg += str(counter)
            counter += 1
            text_msg += ':\n'
            text_msg += str(ant.get_current_path())
            text_msg += '\nДлина пути: '
            text_msg += str(ant.get_travel_length())
            text_msg += '\n\n'

        text_msg += 'Время решения задачи: '
        text_msg += str(time.time() - start_time)
        print_textbox(text_box, text_msg)

    except TypeError:
        text_msg = 'Запись не удовлетворяет условиям задачи\nВведите данные заново.'
        print_textbox(text_box, text_msg)


if __name__ == '__main__':
    # Создаем окно
    window = tk.Tk()
    window.title('Ant Colony Optimization')
    window.geometry('1200x450')

    # Разделим окно на два фрейма
    frame_left = tk.LabelFrame(master=window, text='Исходные данные')
    frame_left.grid(column=0, row=0, padx=5)
    frame_right = tk.LabelFrame(master=window, text='Вывод приложения')
    frame_right.grid(column=1, row=0, padx=5, pady=5)

    # Окно вывода в правом фрейме
    msg = 'Решение задачи коммивояжера с использованием муравьиного алгоритма.'
    result_text_box = tk.Text(master=frame_right, width=80, height=20, wrap=tk.WORD)
    result_text_box.grid(column=0, row=0, padx=20, pady=5)
    result_text_box.insert(1.0, msg)

    # Ввод данных в левом фрейме
    frame_input = tk.Frame(master=frame_left)
    frame_input.grid(column=0, row=0)

    lbl_ants = tk.Label(master=frame_input, text='Число муравьев-агентов')
    lbl_ants.grid(column=0, row=0, padx=5, pady=5)
    ent_ants = tk.Entry(master=frame_input, width=25)
    ent_ants.grid(column=0, row=1, padx=5, pady=5)

    lbl_spots = tk.Label(master=frame_input, text='Число узлов')
    lbl_spots.grid(column=0, row=2, padx=5, pady=5)
    ent_spots = tk.Entry(master=frame_input, width=25)
    ent_spots.grid(column=0, row=3, padx=5, pady=5)

    lbl_max_dist = tk.Label(master=frame_input, text='Макс. дистанция между узлами')
    lbl_max_dist.grid(column=0, row=4, padx=5, pady=5)
    ent_max_dist = tk.Entry(master=frame_input, width=25)
    ent_max_dist.grid(column=0, row=5, padx=5, pady=5)

    lbl_alpha = tk.Label(master=frame_input, text='Alpha')
    lbl_alpha.grid(column=1, row=0, padx=5, pady=5)
    ent_alpha = tk.Entry(master=frame_input, width=25)
    ent_alpha.grid(column=1, row=1, padx=5, pady=5)

    lbl_beta = tk.Label(master=frame_input, text='Beta')
    lbl_beta.grid(column=1, row=2, padx=5, pady=5)
    ent_beta = tk.Entry(master=frame_input, width=25)
    ent_beta.grid(column=1, row=3, padx=5, pady=5)

    lbl_rho = tk.Label(master=frame_input, text='Rho')
    lbl_rho.grid(column=1, row=4, padx=5, pady=5)
    ent_rho = tk.Entry(master=frame_input, width=25)
    ent_rho.grid(column=1, row=5, padx=5, pady=5)

    frame_input_button = tk.Frame(master=frame_left)
    frame_input_button.grid(column=0, row=1)

    lbl_q = tk.Label(master=frame_input_button, text='Коэффициент Q')
    lbl_q.grid(column=0, row=0, padx=5, pady=5)
    ent_q = tk.Entry(master=frame_input_button, width=25)
    ent_q.grid(column=0, row=1, padx=5, pady=5)

    entries = (ent_ants, ent_spots, ent_alpha,
               ent_beta, ent_rho, ent_q, ent_max_dist)
    btn_start_alg = tk.Button(master=frame_input_button, width=18, height=1,
                              text='Запуск алгоритма',
                              command=lambda: start_alg(entries, result_text_box))
    btn_start_alg.grid(column=0, row=2, pady=10)

    frame_left.mainloop()
    frame_right.mainloop()
    window.mainloop()


