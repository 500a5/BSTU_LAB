import kotlin.math.*

fun main() {

    val arrA1 = doubleArrayOf(

            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 0.0,
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,

    )
    val arrA1Rez = 1

    val arrA2 = doubleArrayOf(
        1.0, 1.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 1.0, 1.0,
    )
    val arrA2Rez = 1


    val arrB1 = doubleArrayOf(
        1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 0.0, 0.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
        1.0, 1.0, 1.0,
    )

    val arrB1Rez = -1

    val arrB2 = doubleArrayOf(
        0.0, 1.0, 0.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        1.0, 0.0, 1.0,
        0.0, 1.0, 0.0,
    )

    val arrB2Rez = -1
    val samplesCount = 16
    val selectedActivationFunc: Sigmoid = BipolarRadiallySymmetric()


    val simplePerceptron = SimplePerceptron(arrA1.size, selectedActivationFunc)


    simplePerceptron.updateWeights(arrA1, arrA1Rez.toDouble())
    simplePerceptron.updateWeights(arrA2, arrA2Rez.toDouble())
    simplePerceptron.updateWeights(arrB1, arrB1Rez.toDouble())
    simplePerceptron.updateWeights(arrB2, arrB2Rez.toDouble())

    val samplesS = DoubleArray(samplesCount)

    samplesS[0] = simplePerceptron.computeS(arrA1)
    samplesS[1] = simplePerceptron.computeS(arrA2)
    samplesS[2] = simplePerceptron.computeS(arrB1)
    samplesS[3] = simplePerceptron.computeS(arrB2)

    val classesS = DoubleArray(samplesCount / 2)
    for (i in 0 until samplesCount / 2) {
        classesS[i] = average(samplesS[2 * i], samplesS[2 * i + 1])
    }

    val averageS: Double = average(classesS[0], classesS[1])
    val remappedAverage: Double = average(
        remap(classesS[0], classesS[1], 1.0 / 3),
        remap(classesS[0], classesS[1], 2.0 / 3)
    )

    selectedActivationFunc.remap(remappedAverage)

    val s: Double = simplePerceptron.computeS(arrA1) - averageS
    System.out.format("%5s: %s\n", s, selectedActivationFunc.invoke(s))

    val s2: Double = simplePerceptron.computeS(arrB2) - averageS
    System.out.format("%5s: %s\n", s, selectedActivationFunc.invoke(s))

    val s3: Double = simplePerceptron.computeS(arrB2) - averageS
    System.out.format("%5s: %s\n", s, selectedActivationFunc.invoke(s))

    val s4: Double = simplePerceptron.computeS(arrB2) - averageS
    System.out.format("%5s: %s\n", s, selectedActivationFunc.invoke(s))

}

abstract class ActivationFunc {
    abstract operator fun invoke(x: Double): Double
    abstract fun fromBinary(x: Double): Double
}

abstract class Sigmoid : ActivationFunc() {
    var t = 0.0
    abstract fun remap(averageS: Double)
}

class SimplePerceptron(private val inputSize: Int, activationFunc: ActivationFunc) {
    private val weights: DoubleArray = DoubleArray(inputSize)
    private val activationFunc: ActivationFunc

    init {
        this.activationFunc = activationFunc
    }

    fun updateWeights(input: DoubleArray, binaryExpected: Double) {
        val expected = sign(binaryExpected - 0.5)
        for (i in 0 until inputSize) {
            weights[i] += input[i] * expected
        }


    }

    fun computeS(input: DoubleArray): Double {
        var s = 0.0
        for (i in 0 until inputSize) {
            s += input[i] * weights[i]
        }
        return s
    }
}

private fun average(a: Double, b: Double): Double {
    return (a + b) / 2
}

private fun remap(a: Double, b: Double, part: Double): Double {
    return (a + b * part) / (1 + part)
}

class BinaryRadiallySymmetric : Sigmoid() {
    override fun invoke(x: Double): Double {
        return exp(-abs(x).pow(2) / 2 * t.pow(2))
    }


    override fun fromBinary(x: Double): Double {
        return x
    }

    override fun remap(averageS: Double) {
        t = averageS / sqrt(log(10.0, exp(1.0)))
    }
}


class BipolarRadiallySymmetric : Sigmoid() {
    override fun invoke(x: Double): Double {
        return 1.0 / (1.0 + Math.exp(-t * x));//exp(-abs(x).pow(2) / 2 * t.pow(2)) - 1.0
    }


    override fun fromBinary(x: Double): Double {
        return 2 * (x - 0.5)
    }

    override fun remap(averageS: Double) {
        t = -Math.log((1 - 0.9) / 0.9) / averageS
    }
}

fun div(a: Double, b: Double, part: Double): Double {
    return (a + b * part) / (1 + part)
}



