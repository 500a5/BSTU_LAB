import tkinter as tk
from tkinter import ttk
from solver import solve
from typing import Optional
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import matplotlib.pyplot as plt
import matplotlib


class Main(tk.Frame):
    def __init__(self, root):
        super().__init__(root)
        self.parent = root
        self.tree: Optional[ttk.Treeview] = None
        self.plot_widget = None

        toolbar = tk.Frame(bg='#d7d8e0')
        toolbar.pack(side=tk.TOP, fill=tk.X)
        btn_solve = tk.Button(
            toolbar, text='Рассчитать', bg='#d7d8e0',
            compound=tk.TOP, command=self.solve, padx=10)
        btn_solve.pack(side=tk.LEFT)

        label_init_t = tk.Label(self, text='Начальная температура')
        label_init_t.place(x=50, y=45)

        label_final_t = tk.Label(self, text='Конечная температура')
        label_final_t.place(x=50, y=80)

        label_alpha = tk.Label(self, text='Альфа')
        label_alpha.place(x=50, y=115)

        label_step = tk.Label(self, text='Размер шага')
        label_step.place(x=50, y=150)

        label_count = tk.Label(self, text='Количество фигур')
        label_count.place(x=50, y=185)

        self.entry_init_t = ttk.Entry(self, width=20)
        self.entry_init_t.place(x=250, y=45)

        self.entry_final_t = ttk.Entry(self, width=20)
        self.entry_final_t.place(x=250, y=80)

        self.entry_alpha = ttk.Entry(self, width=20)
        self.entry_alpha.place(x=250, y=115)

        self.entry_step = ttk.Entry(self, width=20)
        self.entry_step.place(x=250, y=150)

        self.entry_count = ttk.Entry(self, width=20)
        self.entry_count.place(x=250, y=185)

        # Определяем рабочее пространство
        self.main_workplace = tk.Frame()
        self.main_workplace.pack(side=tk.BOTTOM, fill=tk.X)

    @staticmethod
    def __get_or_none(obj, typing):
        value = obj.get()
        try:
            return typing(value)
        except:
            return None

    def solve(self):
        init_t = self.__get_or_none(self.entry_init_t, float)
        final_t = self.__get_or_none(self.entry_final_t, float)
        alpha = self.__get_or_none(self.entry_alpha, float)
        steps = self.__get_or_none(self.entry_step, int)
        count = self.__get_or_none(self.entry_count, int)

        # Если таблица уже была - уничтожаем её
        if self.tree is not None:
            self.tree.destroy()
        if self.plot_widget is not None:
            self.plot_widget.destroy()
        if any(map(lambda x: x is None, [init_t, final_t, alpha, steps, count])):
            return
        solution, graphics = solve(
            init_t=init_t,
            final_t=final_t,
            alpha=alpha,
            step_per_change=steps,
            count_figures=count
        )
        self.__show_chess_table(solution)
        self.__show_graphics(graphics)

    @staticmethod
    def __create_row(index: int, value: int, size: int):
        row = [f'{index}']
        for x in range(0, size + 1):
            if x != value:
                row.append(' ')
            else:
                row.append('X')
        return row

    def __show_graphics(self, graphics):
        plt.clf()
        fig = plt.figure(1)
        canvas = FigureCanvasTkAgg(fig, master=self)
        y_min, y_max = 0, 0
        for d in graphics:
            print(d)
            print('=' * 80)
            x = [x['x'] for x in d['data']]
            y = [x['y'] for x in d['data']]
            y_loc_min = min(y)
            y_loc_max = max(y)
            if y_loc_max > y_max:
                y_max = y_loc_max
            if y_loc_min < y_min:
                y_min = y_loc_min
            plt.plot(x, y, label=d['name'])
            plt.legend(loc='center left', bbox_to_anchor=(1, 0.5))
            plt.grid()
        plt.ylim(y_min, y_max)
        fig.tight_layout()

        self.plot_widget = canvas.get_tk_widget()
        self.plot_widget.pack(side=tk.TOP)

    def __show_chess_table(self, solution):
        columns = ['№'] + [str(x) for x in range(1, len(solution) + 1)]

        # Создаём новую таблицу
        self.tree = ttk.Treeview(self.main_workplace, columns=columns, height=25, show='headings')

        # Заполняем каждый столбец именами столбцов
        for column in columns:
            self.tree.column(column, width=25, anchor=tk.CENTER)
            self.tree.heading(column, text=column)
        self.tree.pack(side=tk.TOP)

        # Заполняем таблицу данными
        for index, value in enumerate(solution, 0):
            self.tree.insert('', 'end', values=self.__create_row(index, value, len(solution)))


