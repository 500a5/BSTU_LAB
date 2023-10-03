# This Python file uses the following encoding: utf-8
import matplotlib
matplotlib.use('Qt5Agg')
from PyQt5.QtWidgets import *
from matplotlib.backends.backend_qt5agg import FigureCanvas
from matplotlib.figure import Figure


class MplWidget(QWidget):

    def __init__(self, parent = None):
        QWidget.__init__(self, parent)

        self.canvas = FigureCanvas(Figure())
        self.axes = self.canvas.figure.add_subplot(111)

        vertical_layout = QVBoxLayout()
        vertical_layout.addWidget(self.canvas)
        self.setLayout(vertical_layout)

    def set_title(self, title):
        self.canvas.figure.suptitle(title)

    def add_info(self, x, y):
        self.axes.plot(x, y)
        self.canvas.draw()

    def clear_plot(self):
        self.axes.cla()


