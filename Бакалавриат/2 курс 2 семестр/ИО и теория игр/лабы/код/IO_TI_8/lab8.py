from lab3 import *


def getMz(matr, z, M):
    zf = [0.0 for i in range(len(matr[0]))]
    for i in range(len(z)):
        zf[i] -= z[i]
    for i in range(1, len(matr[0])-1):
        zf[i] -= matr[-1][i - 1]*(M)
        zf[i] *= -1
    zf[0] += (-M)
    return zf


def get_big_table(matr, z):
    M = 100
    for i in range(len(matr)):
        matr[i].append(matr[i][-1])
        matr[i][-2] = 0
    matr[-1][-2] = 1
    zf = getMz(matr, z, M)
    table = getFirstTable(matr, zf)
    return table


def print_DLP_solution(table, z, zf):
    solution = [0 for x in range(len(table[0]) - 2)]

    for i in range(1, len(table) - 1):
        print(int(table[i][0][1]))
        solution[int(table[i][0][1]) - 1] = table[i][1]
    solution = [solution[i]/solution[-2] for i in range(len(solution)-2)]
    print([round(x, 4) for x in solution])
    zUp = 0
    zDown = 0
    for i in range(1, len(z)):
        zUp += solution[i-1]*z[i]
        zDown += solution[i-1]*zf[i]
    zUp += z[0]
    zDown += zf[0]
    print("Значение в  точке максимума")
    print(f"Zmax = {round(zUp/zDown, 4)}")


def printBigSolution(matr, z, zf):
    table = get_big_table(matr, z)
    printTable(table)
    while not checkSolution(table):
        table = nextStep(table)
        printTable(table)
    print_solution(table)
    print('='*160)
    print('Решение задачи дискретного программирования:')
    print_DLP_solution(table, z, zf)


def makeNewTable(matr, z):
    for i in range(len(matr)):
        matr[i][-1] *= -1
        matr[i].append(0)

    matr.append([0 for _ in range(len(matr[0]))])
    for i in range(1, len(z)):
        matr[-1][i - 1] = z[i]
    matr[-1][-1] = 1
    return matr


if __name__ == "__main__":
    # matr_cof = readMatr()
    matr_cof = [[5, 1, 1, 4, 240],
                [1, 0, 3, 1, 80],
                [1, 3, 1, 0, 350]
                ]
    # matr_cof = [[1, 4, 1, 0, 0, 18],
    #             [-2, -3, 0, 1, 0, -12],
    #             [3, -2, 0, 0, 1, 20]]
    # z = readFunck()
    z = [0, 10, 3, 2, 1]
    # z = [0, -7, 2]

    # downZ = readFunck()
    downZ = [0, 1, 1, 1, 1]
    # downZ = [0, 3, 4, 0, 0, 0]
    matr_cof = makeNewTable(matr_cof, downZ)
    printBigSolution(matr_cof, z, downZ)
