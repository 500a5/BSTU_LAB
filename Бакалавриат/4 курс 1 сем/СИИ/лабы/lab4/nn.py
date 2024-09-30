# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets
from PyQt5.QtCore import qDebug

from functions import Functions
import random
class NN:
    def __init__(self, inputSize, outputSize, hiddenLayerSize, iterations, learningData, lr):

        self.inputSize = inputSize
        self.outputSize = outputSize
        self.hiddenLayerSize = hiddenLayerSize
        self.outputLayer = Layer(outputSize, hiddenLayerSize, Functions.Sigmoid)
        self.hiddenLayer = Layer(hiddenLayerSize, inputSize, Functions.Sigmoid)
        # Количество эпох
        self.iterations = iterations
        self.lr = lr

        self.reverse_error(learningData)


    def reverse_error(self, learningData):
        # Для всех эпох
        for iteration in range(self.iterations):
            # Для каждого обучающего образа
            pos = 0
            for data in learningData.symbols:
                # Исходный образ якобы прошел через входной слой

                # Узнаем, какого типа символ пришел
                symbolType = [0 for i in range(self.outputSize)]
                symbolType[learningData.types[pos]] = 1
                #qDebug('{}'.format(symbolType))
                # Читаем скрытым слоем образ
                self.hiddenLayer.read(data)
                # Реагируем на него
                self.hiddenLayer.react()
                # И запоминаем реакцию
                react_h = self.hiddenLayer.get_out()

                # Читаем выходным слоем выходы скрытого слоя
                self.outputLayer.read(react_h)
                # Реагируем на них
                self.outputLayer.react()
                # И запоминаем реакцию
                react_o = self.outputLayer.get_out()


                # Вычисляем вектор ошибки
                errors = [symbolType[i] - react_o[i] for i in range(self.outputSize)]
                #qDebug('{}'.format(errors))
                sigma_o = [react_o[i] * (1 - react_o[i]) * errors[i] for i in range(self.outputSize)]
                #qDebug('{}'.format(sigma_o))

                self.outputLayer.adjust_w(self.lr, sigma_o, react_h)
                #qDebug('{}'.format(self.outputLayer.w))

                sigma_g = [react_h[j] * (1 - react_h[j]) for j in range(self.hiddenLayerSize)]


                j = 0
                for w in self.outputLayer.w:
                    sum = 0
                    for k in range(len(sigma_o)):
                        sum += sigma_o[k] * w[k]
                    sigma_g[j] *= sum
                    j += 1

                self.hiddenLayer.adjust_w(self.lr, sigma_g, data)

                pos += 1

    def test(self, data):
        for d in data.dsymbols:
            self.hiddenLayer.read(d)
            self.hiddenLayer.react()
            react_h = self.hiddenLayer.get_out()

            self.outputLayer.read(react_h)
            self.outputLayer.react()
            react_o = self.outputLayer.get_out()

            qDebug('{}'.format(react_o))

    def recognize_letter(self, data):
        self.hiddenLayer.read(data)
        self.hiddenLayer.react()
        react_h = self.hiddenLayer.get_out()

        self.outputLayer.read(react_h)
        self.outputLayer.react()
        react_o = self.outputLayer.get_out()

        return react_o


class Layer:
    def __init__(self, neuronSize, inputSize, activationFunction):
        self.inputSize = inputSize
        self.neuronSize = neuronSize
        self.w = [[random.random() for i in range(inputSize)] for j in range(neuronSize)]
        self.x = [0 for i in range(inputSize)]
        self.activationFunction = activationFunction
        self.out = [0 for i in range(neuronSize)]

    def read(self, data):
        self.x = data.copy()

    def adjust_w(self, lr, sigma, prev_out):
        for neuron in range (self.neuronSize):
            for link in range(self.inputSize):
                w = self.w[neuron][link]
                self.w[neuron][link] = w + lr * sigma[neuron] * prev_out[link]

    def react(self):

        for currentNeuron in range(self.neuronSize):
            sum = 0
            for currentLink in range(self.inputSize):
                sum += self.x[currentLink] * self.w[currentNeuron][currentLink]
            self.out[currentNeuron] = self.activationFunction.f(sum)


    def get_out(self):
        return self.out


