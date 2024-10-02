import kotlin.math.*

fun main() {

    val arr = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, -1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )
    val arr1 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, -1.0,
        ), doubleArrayOf(
            1.0, -1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val arr2 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            -1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, -1.0,
        ), doubleArrayOf(
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val arr3 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, -1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val arr4 = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            -1.0, 1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            -1.0, 1.0, -1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
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
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        ), doubleArrayOf(
            1.0, 1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            -1.0, 1.0, 1.0,
        ), doubleArrayOf(
            -1.0, 1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, -1.0,
            1.0, -1.0, 1.0,
            -1.0, 1.0, -1.0,
        ), doubleArrayOf(
            1.0, -1.0, -1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, -1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, -1.0,
        ), doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, -1.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 1.0, 1.0,
        )

    )

    val selectedActivationFunc: Sigmoid = BipolarRadiallySymmetric()


    val arrCount = 5

    val deltaPerceptron = DeltaPerceptron(arr[0].size, arr[0].size, 0.5)

    for (i in 0 until arrCount) {
        deltaPerceptron.updateWeights(arr1.get(i), arr.get(i))
    }

    for (i in 0..99) {
        for (j in 0 until arrCount) {
            deltaPerceptron.train(arr1.get(j), arr.get(j), selectedActivationFunc)
        }
    }

    for (i in 0..arrCount) {
        var s = deltaPerceptron.computeS(arr1[i])
        var j = 0
        while (j < arrCount) {
            s[j] = selectedActivationFunc.invoke(s[j])
            j++
        }
        System.out.format("%.2f %.2f %.2f %.2f %.2f\n", s[0], s[1], s[2], s[3], s[4]);
    }

    System.out.println();

    for (i in 0..arr.size) {

        var s = deltaPerceptron.computeS(arr3[i]);

        var j = 0
        while (j < s.size) {
            s[j] = selectedActivationFunc.invoke(s[j]);
            j++
        }

        System.out.format("%.2f %.2f %.2f %.2f %.2f\n", s[0], s[1], s[2], s[3], s[4]);
    }


}


class DeltaPerceptron(private val inputSize: Int, private val outputSize: Int, private val learningRate: Double) {
    private val weights: Array<DoubleArray>
    private val basis: DoubleArray

    init {
        weights = Array(inputSize) { DoubleArray(outputSize) }
        basis = DoubleArray(outputSize)
    }

    fun updateWeights(input: DoubleArray, expected: DoubleArray) {
        for (i in 0 until inputSize) {
            for (j in 0 until outputSize) {
                weights[i][j] += input[i] * expected[j]
            }
        }
    }

    fun train(input: DoubleArray, expected: DoubleArray, activationFunc: ActivationFunc) {
        val s = computeS(input)
        for (i in 0 until outputSize) {
            s[i] = activationFunc.invoke(s[i])
        }
        for (i in 0 until outputSize) {
            s[i] = expected[i] - s[i]
            basis[i] += s[i]
        }
        for (i in 0 until inputSize) {
            for (j in 0 until outputSize) {
                weights[i][j] += learningRate * input[i] * s[j]
            }
        }
    }

    fun computeS(input: DoubleArray): DoubleArray {
        val s = DoubleArray(outputSize)
        for (i in 0 until inputSize) {
            for (j in 0 until outputSize) {
                s[j] += input[i] * weights[i][j]
            }
        }
        for (i in 0 until outputSize) {
            s[i] += basis[i]
        }
        return s
    }
}


abstract class ActivationFunc {
    abstract operator fun invoke(x: Double): Double
    abstract fun fromBinary(x: Double): Double
}

abstract class Sigmoid : ActivationFunc() {
    var t = 0.0
    abstract fun remap(averageS: Double)
}

class BipolarRadiallySymmetric : Sigmoid() {
    override fun invoke(x: Double): Double {
        return exp(-abs(x).pow(2) / 2 * t.pow(2)) - 1.0
    }


    override fun fromBinary(x: Double): Double {
        return 2 * (x - 0.5)
    }

    override fun remap(averageS: Double) {
        t = averageS / sqrt(log(10.0, exp(1.0)))
    }
}

fun div(a: Double, b: Double, part: Double): Double {
    return (a + b * part) / (1 + part)
}
