import sys
import pyqtgraph as pg
import numpy as np
import math
from PyQt5.QtWidgets import QApplication, QMainWindow, QTableWidget, QTableWidgetItem, QHeaderView
from PyQt5.uic import loadUi
from PyQt5.QtCore import qDebug

from antalgorithm import AntAlgorithm
class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        loadUi('mainwindow.ui', self)
        self.aa = None
        self.setParametersButton.clicked.connect(self.getParameters)
        self.win = pg.GraphicsLayoutWidget(show=True)
        pg.setConfigOptions(antialias=True)
        self.getParameters()
        self.graphLayout.addWidget(self.win)

        self.posx = []
        self.posy = []

    def showPlot(self):
        self.win.clear()
        pos = []
        r = int(self.nEdit.text())
        angle = 0
        delta = 360 / r
        v = self.aa.getPh()
        self.posx = []
        self.posy = []
        for i in range (r):
            #pos.append([r * math.cos(angle), r * math.sin(angle)])
            self.posx.append(r * math.cos(angle))
            self.posy.append(r * math.sin(angle))
            angle += delta
            pass


        self.win.addPlot(x=self.posx, y=self.posy, symbolBrush=(255,0,0), symbolPen='w')



    def fillTable(self):
        self.table.clear()

        ph = self.aa.getPh()

        self.table.setColumnCount(4)
        self.table.setRowCount(len(ph))

        header = self.table.horizontalHeader()
        header.setSectionResizeMode(QHeaderView.ResizeToContents)
        header.setSectionResizeMode(0, QHeaderView.Stretch)

        self.table.setHorizontalHeaderLabels(["Из", "В", "Стоимость", "Феромоны"])


        costs = self.aa.getDistances()
        pos = 0
        for currentPh in ph:
            self.table.setItem(pos, 0, QTableWidgetItem("{}".format(currentPh[0])))
            self.table.setItem(pos, 1, QTableWidgetItem("{}".format(currentPh[1])))
            self.table.setItem(pos, 2, QTableWidgetItem("{}".format(costs[currentPh[0]][currentPh[1]])))
            self.table.setItem(pos, 3, QTableWidgetItem("{}".format(round(currentPh[2], 4))))
            pos += 1
        #self.table.adjustSize()



    def getParameters(self):
        n = int(self.nEdit.text())
        iterations = int(self.iterationsEdit.text())
        antsCount = int(self.antsEdit.text())
        eliteAntsCount = int(self.eliteAntsEdit.text())
        alpha = float(self.alphaEdit.text())
        beta = float(self.betaEdit.text())
        rho = float(self.rhoEdit.text())
        self.aa = AntAlgorithm(n, iterations, antsCount, eliteAntsCount, alpha, beta, rho)
        self.aa.perform()
        self.showPlot()
        self.fillTable()


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
