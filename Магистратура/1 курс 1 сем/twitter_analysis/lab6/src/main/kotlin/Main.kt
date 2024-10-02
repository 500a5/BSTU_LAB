fun main(args: Array<String>) {
    println("Hello World!")

    // Try adding program arguments via Run/Debug configuration.
    // Learn more about running applications: https://www.jetbrains.com/help/idea/running-applications.html.
    println("Program arguments: ${args.joinToString()}")
}
class HammingNetwork(
    private val m: Int,
    private val n: Int
) {
    private val w: Array<DoubleArray>
    private val b: Double
    private val k1: Double
    private val uMax: Double
    private val eps: Double

    init {
        w = Array(m) { DoubleArray(n) }
        b = m / 2.0
        k1 = 0.01
        uMax = 1.0 / k1
        eps = 1.0 / n
    }

    fun fillW(k: Int, vK: DoubleArray) {
        for (i in 0 until m) {
            w[i][k] = vK[i] / 2.0
        }
    }

    fun calculateZ(s: DoubleArray): DoubleArray {
        val z = DoubleArray(n)
        for (k in 0 until n) {
            z[k] = b
            for (i in 0 until m) {
                z[k] += w[i][k] * s[i]
            }
            if (z[k] <= 0) z[k] = 0.0 else if (z[k] > 0 && z[k] < uMax) z[k] *= k1 else if (z[k] > 0) z[k] = uMax
        }
        return z
    }

    fun iteration(z: DoubleArray): DoubleArray {
        var z = z
        for (i in 0..9) {
            z = iterationStep(z)
        }
        for (i in 0 until n) {
            z[i] = (if (z[i] > 0) 1 else 0).toDouble()
        }
        return z
    }

    fun iterationStep(u: DoubleArray): DoubleArray {
        val uNew = DoubleArray(n)
        for (i in 0 until n) {
            var sum = 0.0
            for (j in 0 until n) {
                if (i == j) continue
                sum += u[j]
            }
            uNew[i] = u[i] - eps * sum
            if (uNew[i] <= 0) uNew[i] = 0.0
        }
        return uNew
    }
}