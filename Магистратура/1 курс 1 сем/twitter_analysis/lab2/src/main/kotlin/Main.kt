import java.util.*
import kotlin.math.*


fun main() {

    val arr = mutableListOf(
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 0.0, 1.0,
            1.0, 1.0, 1.0,
        ),
        doubleArrayOf(
            1.0, 1.0, 1.0,
            1.0, 0.0, 1.0,
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

    val selectedActivationFunc: Sigmoid = BinaryRadiallySymmetric()



    val arrCount = 5

    val multiplierPerceptron = MultiplierPerceptron(arr[0].size, arr[0].size)

    for (i in 0 until arrCount) {
        multiplierPerceptron.updateWeights(arr1.get(i), arr.get(i))
    }

    for (i in 0..99) {
        for (j in 0 until arrCount) {
            multiplierPerceptron.train(arr1.get(j), arr.get(j), selectedActivationFunc)
        }
    }

    var inputs = doubleArrayOf(1.00,1.00,0.00,0.00,0.00)
    var inputs2 = doubleArrayOf(0.00,1.00,0.00,0.00,0.00)
    var inputs3 = doubleArrayOf(0.00,0.00,1.00,0.00,0.00)
    var inputs4 = doubleArrayOf(0.00,0.00,0.00,1.00,0.00)
    var inputs5 = doubleArrayOf(0.00,1.00,0.00,0.00,1.00)
    print("{ ")
    for (i in 0 until inputs.size) {
        print(inputs.get(i))
        print(" ")
    }
    print(" }")
    println()

    print("{ ")
    for (i in 0 until inputs.size) {
        print(inputs2.get(i))
        print(" ")
    }
    print(" }")
    println()

    print("{ ")
    for (i in 0 until inputs.size) {
        print(inputs3.get(i))
        print(" ")
    }
    print(" }")
    println()


    print("{ ")
    for (i in 0 until inputs.size) {
        print(inputs4.get(i))
        print(" ")
    }
    print(" }")
    println()



    print("{ ")
    for (i in 0 until inputs5.size) {
        print(inputs5.get(i))
        print(" ")
    }
    print(" }")
    println()


    println()
    for (i in 0..arrCount){
        var s = multiplierPerceptron.computeS(arr1[i])
       var j =0
            while (j<arrCount) {
                    j++
                s[j] = selectedActivationFunc.invoke(s[j]) / 10
            }
        System.out.format("%.2f %.2f %.2f %.2f %.2f\n", s[0], s[1], s[2], s[3], s[4]);
    }

    System.out.println();

    for (i in 0..arr.size)
    {

        var s = multiplierPerceptron.computeS(arr1[i]);

        var j = 0
            while ( j < s.size){
                j++;
            s[j] = selectedActivationFunc.invoke(s[j]);
        }

        System.out.format("%.2f %.2f %.2f %.2f %.2f\n", s[0], s[1], s[2], s[3], s[4]);
    }


}


class MultiplierPerceptron(private val inputSize: Int, private val outputSize: Int) {
    private val weights: Array<DoubleArray>

    init {
        weights = Array(inputSize) { DoubleArray(outputSize) }
    }


    fun updateWeights(input: DoubleArray, binaryExpected: DoubleArray) {
        val expected = DoubleArray(outputSize)
        for (i in 0 until outputSize) {
            expected[i] = binaryExpected[i]
        }
        for (i in 0 until inputSize) {
            for (j in 0 until outputSize) {
                weights[i][j] += (input[i] - 0.5) * expected[j]
            }
        }
    }

    fun train(input: DoubleArray, binaryExpected: DoubleArray, activationFunc: ActivationFunc) {
        val s = computeS(input)
        for (i in 0 until outputSize) {
            s[i] = activationFunc.invoke(s[i])
        }
        var i: Int
        i = 0
        while (i < outputSize) {
            if (Math.abs(binaryExpected[i] - s[i]) > 0.1) break
            i++
        }
        if (i == outputSize) return
        i = 0
        while (i < outputSize) {
            if (s[i] > 0.1 && binaryExpected[i] <= 0.1) s[i] =
                -0.1 else if (s[i] < 0.9 && binaryExpected[i] >= 0.9) s[i] = 0.1 else s[i] = 0.0
            i++
        }
        i = 0
        while (i < inputSize) {
            for (j in 0 until outputSize) {
                weights[i][j] += input[i] * s[j]
            }
            i++
        }
    }

    fun computeS(input: DoubleArray): DoubleArray {
        val s = DoubleArray(outputSize)
        for (i in 0 until inputSize) {
            for (j in 0 until outputSize) {
                s[j] += input[i] * weights[i][j]
            }
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