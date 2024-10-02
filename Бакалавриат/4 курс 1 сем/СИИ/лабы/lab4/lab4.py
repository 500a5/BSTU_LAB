# This Python file uses the following encoding: utf-8
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QMessageBox, QLabel, QWidget, QGridLayout, QVBoxLayout, QPushButton
from PyQt5.uic import loadUi
from PyQt5.QtCore import qDebug
from functions import Functions
from nn import NN
from data import Data
class MainWindow(QMainWindow):
    def __init__(self):
        QMainWindow.__init__(self)
        loadUi('mainwindow.ui', self)
        self.inputLetter.clicked.connect(self.showInputWidget)
        # Сколько строк и столбцов в поле ввода
        self.inputSize = 5

        self.hiddenLayerSize = 12

        self.outputSize = 5

        self.iterations = 1000
        self.lr = 0.3
        self.data = Data()
        self.data.generate_symbols(4, 1)

        self.inputtedLetter = [0 for i in range(self.inputSize ** 2)]

        self.nn = NN(self.inputSize ** 2,
                     self.outputSize,
                     self.hiddenLayerSize,
                     self.iterations,
                     self.data,
                     self.lr
                     )

#        qDebug('{}'.format(self.nn.recognize_letter(self.inputtedLetter)))
 #       qDebug('{}'.format(self.nn.recognize_letter(self.data.symbols[0])))
        #self.nn.test(self.data)
        #TODO нейрон смещения во всех слоях


    def showInputWidget(self):
        self.input = QWidget()
        grid = QGridLayout()
        self.input.setFixedSize(40 * self.inputSize, 40 * self.inputSize)
        mainLayout = QVBoxLayout()
        self.input.saveButton = QPushButton('Сохранить')
        self.input.saveButton.clicked.connect(self.getLetter)
        mainLayout.addLayout(grid)
        mainLayout.addWidget(self.input.saveButton)
        self.input.setLayout(mainLayout)
        self.labels = []
        for i in range(self.inputSize):
            for j in range(self.inputSize):
                tmp = Cell(self.input, i, j)
                grid.addWidget(tmp, i, j)
                self.labels.append(tmp)
        self.input.saveButton.clicked.connect(self.getLetter)
        self.input.show()

    def getLetter(self):
        pos = 0
        for label in self.labels:
            if label.isBlack():
                self.inputtedLetter[pos] = 1
            else:
                self.inputtedLetter[pos] = 0
            pos += 1
        result = self.nn.recognize_letter(self.inputtedLetter)
        self.showLog(result)

    def showLog(self, result):
        self.logs.setText('')
        msg = ''
        for i in range(len(result)):
            msg += '{} - {}\n'.format(self.data.labels[i], result[i])
        self.logs.setText(msg)

    def showWarning(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setWindowTitle("Ну вот не надо!")
        msg.setText("Сначала введите параметры!")
        msg.exec_()

class Cell(QLabel):
    def __init__(self, parent, i, j):
        QLabel.__init__(self, parent)
        self.resize(30, 30)
        self.x = i
        self.y = j
        self.mousePressEvent = self.changeColor
        self.color = 'white'
        self.setStyleSheet("QLabel { background-color : white;  }")

    def changeColor(self, args):
        if self.color == 'black':
            self.color = 'white'
            self.setStyleSheet("QLabel { background-color : white;  }")
        else:
            self.color = 'black'
            self.setStyleSheet("QLabel { background-color : black;  }")

    def isBlack(self):
        return self.color == 'black'

if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
