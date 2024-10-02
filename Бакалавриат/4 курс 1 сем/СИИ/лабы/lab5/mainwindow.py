import sys
import pyqtgraph as pg
import numpy as np
import math
from PyQt5.QtWidgets import QApplication, QMainWindow, QTableWidget, QTableWidgetItem, QHeaderView
from PyQt5.uic import loadUi
from PyQt5.QtCore import qDebug

from gen_alg import Gen_alg
class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        loadUi('mainwindow.ui', self)
        self.setParametersButton.clicked.connect(self.getParameters)
        self.win = pg.GraphicsLayoutWidget(show=True)
        pg.setConfigOptions(antialias=True)
        self.graphLayout.addWidget(self.win)
        self.posx = []
        self.posy = []
        self.getParameters()

    def show_changes(self):
        self.posx = []
        self.posy = []
        self.win.clear()
        sol = self.ga.get_best_solutions()

        for i in range(len(sol)):
            s = self.ga.get_distance(sol[i])
            self.posx.append(i)
            self.posy.append(s)
        self.win.addPlot(x=self.posx, y=self.posy, smooth=True)


    def fill_table(self):
        self.table.clear()
        dist = self.ga.get_distances()
        indicies = []
        for i in range(len(dist)):
            for j in range(i + 1, len(dist)):
                indicies.append([i, j])

        self.table.setColumnCount(3)
        self.table.setRowCount(len(indicies))
        header = self.table.horizontalHeader()
        header.setSectionResizeMode(QHeaderView.ResizeToContents)
        header.setSectionResizeMode(0, QHeaderView.Stretch)
        header.setSectionResizeMode(1, QHeaderView.Stretch)
        header.setSectionResizeMode(2, QHeaderView.Stretch)
        self.table.setHorizontalHeaderLabels(["Из", "В", "Стоимость"])

        pos = 0
        for index in indicies:
            self.table.setItem(pos, 0, QTableWidgetItem("{}".format(index[0])))
            self.table.setItem(pos, 1, QTableWidgetItem("{}".format(index[1])))
            self.table.setItem(pos, 2, QTableWidgetItem("{}".format(dist[index[0]][index[1]])))
            pos += 1
        self.table.adjustSize()

    def getParameters(self):
        n = int(self.nEdit.text())
        iterations = int(self.iterationsEdit.text())
        crossing_prob = float(self.crossing_prob_edit.text())
        r_count = int(self.r_count_edit.text())
        self.ga = Gen_alg(n, iterations, r_count, crossing_prob)
        self.ga.perform()
        self.show_changes()
        self.fill_table()


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
