import java.util.*


fun main(args: Array<String>) {

    val arr = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 0.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 0.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )
    val arr1 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 0.0,
        ),
        doubleArrayOf(
            1.0, 0.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 0.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val arr2 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            0.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 0.0,
        ),
        doubleArrayOf(
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val arr3 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 0.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val arr4 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            0.0, 1.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            0.0, 1.0, 0.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val arr5 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            0.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            0.0, 1.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 0.0,
            1.0, 0.0, 1.0,
            0.0, 1.0, 0.0,
        ),
        doubleArrayOf(
            1.0, 0.0, 0.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 0.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )



    val gammaPerceptron = GammaPerceptron(16, 8, 2, 0.1)
    gammaPerceptron.randomizeWeights()

    for (j in 0..9) {
        for (i in 0 until arr.size) {
            gammaPerceptron.train(arr.get(i))
        }
    }
    for (i in 0 until arr.size) {
        println(Arrays.toString(gammaPerceptron.compute(arr.get(i))))
    }

}

class GammaPerceptron(
    private val inputSize: Int,
    private val neuronsSize: Int,
    private val outputSize: Int,
    private val learningRate: Double
) {
    private val weights1: Array<DoubleArray>
    private val weights2: Array<DoubleArray>
    private val theta1: Double
    private val theta2: Double

    init {
        weights1 = Array(inputSize) { DoubleArray(neuronsSize) }
        weights2 = Array(neuronsSize) { DoubleArray(outputSize) }
        theta1 = 1.5
        theta2 = 1.3
    }

    fun randomizeWeights() {
        val random = Random(5)
        for (i in 0 until inputSize) {
            for (j in 0 until neuronsSize) {
                weights1[i][j] = randomRange(random, 0.1, 0.9)
            }
        }
        for (i in 0 until neuronsSize) {
            for (j in 0 until outputSize) {
                weights2[i][j] = randomRange(random, 0.1, 0.9)
            }
        }
    }

    fun train(input: DoubleArray) {
        val a = computeA(input)
        var trueNeurons = 0
        for (i in 0 until neuronsSize) {
            a[i] = (if (a[i] >= theta1) 1 else 0).toDouble()
            trueNeurons += a[i].toInt()
        }
        for (i in 0 until neuronsSize) {
            for (j in 0 until outputSize) {
                if (a[i] > 0) {
                    weights2[i][j] += learningRate - trueNeurons * learningRate / neuronsSize
                } else {
                    weights2[i][j] -= trueNeurons * learningRate / neuronsSize
                }
                if (weights2[i][j] > 1) weights2[i][j] = 1.0 else if (weights2[i][j] < 0) weights2[i][j] = 0.0
            }
        }
    }

    fun compute(input: DoubleArray): DoubleArray {
        val a = computeA(input)
        for (i in 0 until neuronsSize) {
            a[i] = (if (a[i] >= theta1) 1 else 0).toDouble()
        }
        val r = computeR(a)
        for (i in 0 until outputSize) {
            r[i] = (if (r[i] >= theta2) 1 else -1).toDouble()
        }
        return r
    }

    fun computeA(input: DoubleArray): DoubleArray {
        val a = DoubleArray(neuronsSize)
        for (i in 0 until neuronsSize) {
            for (j in 0 until inputSize) {
                a[i] += input[j] * weights1[j][i]
            }
        }
        return a
    }

    fun computeR(a: DoubleArray): DoubleArray {
        val r = DoubleArray(outputSize)
        for (i in 0 until outputSize) {
            for (j in 0 until neuronsSize) {
                r[i] += a[j] * weights2[j][i]
            }
        }
        return r
    }

    companion object {
        private fun randomRange(random: Random, min: Double, max: Double): Double {
            return random.nextDouble() * (max - min) + min
        }
    }
}