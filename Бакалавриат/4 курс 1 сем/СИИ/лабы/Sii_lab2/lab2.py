# This Python file uses the following encoding: utf-8
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QTableWidgetItem
from PyQt5.uic import loadUi
from PyQt5.QtCore import qDebug
from ART import ART1

class MainWindow(QMainWindow):
    def __init__(self, parent = None):
        QMainWindow.__init__(self)
        loadUi('mainwindow.ui', self)

        self.get_recommendations_button.clicked.connect(self.get_values)

        self.max_items = 11
        self.max_customers = 10
        self.total_prototype_vectors = 5
        self.beta = 1.0
        self.vigilance = 0.9

        self.max_items_edit.setText(str(self.max_items))
        self.max_customers_edit.setText(str(self.max_customers))
        self.total_prototype_vectors_edit.setText(str(self.total_prototype_vectors))
        self.beta_edit.setText(str(self.beta))
        self.vigilance_edit.setText(str(self.vigilance))


        self.art = ART1()
        self.art.set_debug_values()
        self.art.perform()
        database_table = self.art.get_database()
        self.fill_table(self.database_table_widget, database_table)
        self.show_clusters()


    # Перегенерация арт на случайных данных с введенными параметрами
    def setup_art(self):
        self.art = ART1()
        self.art.set_parameters(self.max_items, self.max_customers,
                                self.total_prototype_vectors,
                                self.beta, self.vigilance)
        self.art.set_random_database()
        self.art.perform()
        database_table = []
        database_table = self.art.get_database()

        self.fill_table(self.database_table_widget, database_table)
        self.show_clusters()


    def show_clusters(self):
        self.logs.clear()

        self.logs.setPlainText(self.art.get_clusters())




    def fill_table(self, table, data):
        table.setColumnCount(0)
        table.setRowCount(0)

        table.setColumnCount(len(data[0]))
        table.setRowCount(len(data))
        for i in range(0, len(data)):
            for j in range(0, len(data[0])):
                table.setItem(i, j, QTableWidgetItem(str(data[i][j])))



    # ОШИБКА НОЛЬ НОЛЬ НОЛЬ
    def show_warning(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)

        msg.setText("Сначала введите параметры!")
        msg.exec_()

    # Сделать нормальную валидацию
    def is_valid(self, data):
        return not data == ''

    # Получаем введенные значения
    def get_values(self):
        t = self.max_items_edit.text()
        if self.is_valid(t):
            self.max_items = int(t)
        else:
            self.show_warning()
            return

        t = self.max_customers_edit.text()
        if self.is_valid(t):
            self.max_customers = int(t)
        else:
            self.show_warning()
            return

        t = self.total_prototype_vectors_edit.text()
        if self.is_valid(t):
            self.total_prototype_vectors = int(t)
        else:
            self.show_warning()
            return

        t = self.beta_edit.text()
        if self.is_valid(t):
            self.beta = float(t)
        else:
            self.show_warning()
            return

        t = self.vigilance_edit.text()
        if self.is_valid(t):
            self.vigilance = float(t)
        else:
            self.show_warning()
            return

        self.setup_art()


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
