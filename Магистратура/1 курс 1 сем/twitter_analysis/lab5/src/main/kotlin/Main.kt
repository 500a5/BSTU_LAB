fun main(args: Array<String>) {
    val neuralNetwork = NeuralNetwork(12, 12, 12, 5)
    neuralNetwork.learningRate = 0.2

    neuralNetwork.randomizeWeights(-0.5, 0.5)

    // Обучение сети.
    // Обучение сети.
    for (i in 0..9999) {
        for (sample in samples) {
            neuralNetwork.feedForward(sample.input)
            neuralNetwork.feedBackward(sample.expected)
            neuralNetwork.updateWeights()
        }
    }

    // Распознавание.
    // Распознавание.
    val inputs: Unit = imagesLoader.loadTests()
    val inputsCount: Unit = inputs.length

    for (i in 0 until inputsCount) {
        println(neuralNetwork.feedForward(inputs.get(i)))
    }
    println()

}
private fun println(array: DoubleArray) {
    print("{ ")
    for (element in array) {
        System.out.format("%.2f ", element)
    }
    println("}")
}

class NeuralNetwork(vararg layersSizes: Int) {
    private val layersSize: Int
    private val layers: Array<Layer?>
    var learningRate = 0.1

    init {
        layersSize = layersSizes.size
        layers = arrayOfNulls<Layer>(layersSize)
        for (i in 0 until layersSize - 1) {
            layers[i] = Layer(layersSizes[i], layersSizes[i + 1])
        }
        layers[layersSize - 1] = Layer(layersSizes[layersSize - 1], 0)
    }

    fun randomizeWeights(min: Double, max: Double) {
        for (l in 0 until layersSize - 1) {
            val layer: Layer? = layers[l]
            for (i in 0 until layer.size) {
                for (j in 0 until layer.nextSize) {
                    layer.weights.get(i).get(j) = randomRange(min, max)
                }
            }
        }
    }

    fun feedForward(input: DoubleArray): DoubleArray {
        layers[0].neurons = input

        // По слоям.
        for (l in 0 until layersSize - 1) {
            // По нейронам.
            for (j in 0 until layers[l].nextSize) {
                layers[l + 1].neurons.get(j) = 0
                for (i in 0 until layers[l].size) {
                    layers[l + 1].neurons.get(j) += layers[l].neurons.get(i) * layers[l].weights.get(i).get(j)
                }
                layers[l + 1].neurons.get(j) = sigmoid(layers[l + 1].neurons.get(j))
            }
        }
        return layers[layersSize - 1].neurons
    }

    fun feedBackward(expected: DoubleArray) {
        // Последний слой.
        val lastLayer: Layer? = layers[layersSize - 1]
        for (i in 0 until lastLayer.size) {
            lastLayer.error.get(i) =
                lastLayer.neurons.get(i) * (1 - lastLayer.neurons.get(i)) * (expected[i] - lastLayer.neurons.get(i))
        }

        // С предпоследнего по 2.
        for (l in layersSize - 2 downTo 1) {
            val layer: Layer? = layers[l]
            val nextLayer: Layer? = layers[l + 1]
            for (i in 0 until layer.size) {
                layer.error.get(i) = 0
                for (j in 0 until layer.nextSize) {
                    layer.error.get(i) += nextLayer.error.get(j) * layer.weights.get(i).get(j)
                }
                layer.error.get(i) *= layer.neurons.get(i) * (1 - layer.neurons.get(i))
            }
        }
    }

    fun updateWeights() {
        for (l in 0 until layersSize - 1) {
            val layer: Layer? = layers[l]
            for (i in 0 until layer.size) {
                for (j in 0 until layer.nextSize) {
                    layer.weights.get(i).get(j) += learningRate * layers[l + 1].error.get(j) * layer.neurons.get(i)
                }
            }
        }
    }

    companion object {
        private fun sigmoid(x: Double): Double {
            return 1 / (1 + Math.exp(-x))
        }

        private fun randomRange(min: Double, max: Double): Double {
            return Math.random() * (max - min) + min
        }
    }
}

class Layer(var size: Int, var nextSize: Int) {
    var neurons: DoubleArray
    var weights: Array<DoubleArray>
    var error: DoubleArray

    init {
        neurons = DoubleArray(size)
        weights = Array(size) { DoubleArray(nextSize) }
        error = DoubleArray(size)
    }
}