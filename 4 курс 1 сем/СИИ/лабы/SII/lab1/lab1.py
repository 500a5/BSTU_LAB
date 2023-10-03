# This Python file uses the following encoding: utf-8
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QHeaderView, QTableWidget, QTableWidgetItem
from PyQt5.uic import loadUi
from PyQt5.QtGui import QColor
from annealing import Annealing
class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        loadUi('mainwindow.ui', self)
        self.bboard = QTableWidget()
        self.sboard = QTableWidget()
        loadUi('board.ui', self.bboard)
        loadUi('board.ui', self.sboard)

        self.t_min = 1
        self.t_max = 30
        self.n = 20
        self.iterations = 100
        self.alpha = 0.98
        self.t_min_edit.setText(str(self.t_min))
        self.t_max_edit.setText(str(self.t_max))
        self.n_edit.setText(str(self.n))
        self.iterations_edit.setText(str(self.iterations))
        self.alpha_edit.setText(str(self.alpha))

        self.MplWidget_temp.set_title("Температура")
        self.MplWidget_bs.set_title("Количество плохих решений")
        self.MplWidget_en.set_title("Энергия")
        self.save_button.clicked.connect(self.get_values)
        self.show_button_best.clicked.connect(self.show_board_best)
        self.show_button_start.clicked.connect(self.show_board_start)

        self.start_solution = []
        self.best_solution = []

        self.calculate_and_show()


    def show_board_start(self):
        self.sboard.setWindowTitle("Начальное решение")
        self.sboard.setColumnCount(0)
        self.sboard.setRowCount(0)

        wsize = self.n * 50 + 20
        hsize = wsize - 95
        self.sboard.setFixedSize(wsize, hsize)
        header = self.sboard.horizontalHeader()

        self.sboard.setColumnCount(self.n)
        self.sboard.setRowCount(self.n)

        for i in self.start_solution:
            self.sboard.setItem(i, self.start_solution[i], QTableWidgetItem())
            self.sboard.item(i, self.start_solution[i]).setBackground(QColor(255, 0, 255))

        header.setSectionResizeMode(QHeaderView.ResizeToContents)
        header.setSectionResizeMode(0, QHeaderView.Stretch)
        self.sboard.show()


    def show_board_best(self):
        self.bboard.setWindowTitle("Лучшее решение")
        self.bboard.setColumnCount(0)
        self.bboard.setRowCount(0)

        wsize = self.n * 50 + 20
        hsize = wsize - 95
        self.bboard.setFixedSize(wsize, hsize)
        header = self.bboard.horizontalHeader()

        self.bboard.setColumnCount(self.n)
        self.bboard.setRowCount(self.n)

        for i in self.best_solution:
            self.bboard.setItem(i, self.best_solution[i], QTableWidgetItem())
            self.bboard.item(i, self.best_solution[i]).setBackground(QColor(255, 0, 255))

        header.setSectionResizeMode(QHeaderView.ResizeToContents)
        header.setSectionResizeMode(0, QHeaderView.Stretch)
        self.bboard.show()


    def calculate_and_show(self):
        anl = Annealing(self.t_min, self.t_max, self.alpha, self.n, self.iterations)
        anl.calculate()
        self.logs.setPlainText(
            '''Начальное решение: {}, количество конфликтов: {};
            Конечное решение: {},
            Энергия: {}, температура: {}, количество итераций: {}
            '''
            .format(anl.start_solution, anl.start_energy,
                    anl.best_solution,
                    anl.best_energy, anl.t_current, len(anl.stats['iterations']),
                    )
        )
        self.start_solution = anl.start_solution
        self.best_solution = anl.best_solution
        self.MplWidget_temp.add_info(anl.stats['iterations'], anl.stats['temperature'])
        self.MplWidget_bs.add_info(anl.stats['iterations'], anl.stats['bad_solutions'])
        self.MplWidget_en.add_info(anl.stats['iterations'], anl.stats['energy'])

    def show_warning(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setWindowTitle("Ну вот не надо!")
        msg.setText("Сначала введите параметры!")
        msg.exec_()


    def get_values(self):
        self.MplWidget_temp.clear_plot()
        self.MplWidget_bs.clear_plot()
        self.MplWidget_en.clear_plot()

        if self.iterations_edit.text() != "":
            self.iterations = int(self.iterations_edit.text())
        else:
            self.show_warning()
            return

        if self.n_edit.text() != "":
            self.n = int(self.n_edit.text())
        else:
            self.show_warning()
            return

        if self.t_min_edit.text() != "":
            self.t_min = float(self.t_min_edit.text())
        else:
            self.show_warning()
            return

        if self.t_max_edit.text() != "":
            self.t_max = float(self.t_max_edit.text())
        else:
            self.show_warning()
            return

        if self.alpha_edit.text() != "":
            self.alpha =float(self.alpha_edit.text())
        else:
            self.show_warning()
            return

        self.calculate_and_show()



if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.setFixedSize(850, 850)
    window.show()
    sys.exit(app.exec_())
