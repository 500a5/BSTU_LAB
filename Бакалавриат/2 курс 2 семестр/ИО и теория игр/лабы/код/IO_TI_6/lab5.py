from lab3 import *
def putFictN(matr):
    newMatr = [[ 0.0 for j in range(len(matr[0]) + len(matr))] for i in range(len(matr))]
    for i in range(len(matr)):
        for j in range(len(matr[0]) - 1):
            newMatr[i][j] = matr[i][j]
    for i in range(len(matr)):
        newMatr[i][len(matr[0]) + i - 1] = 1.0
    for i in range(len(matr)):
        newMatr[i][len(newMatr[0]) - 1] = matr[i][len(matr[0]) - 1]
    return newMatr
def getDtask(matr, z):
    matrD = [[-matr[j][i] for j in range(len(matr))] for i in range(len(matr[0]) - 1)]
    for row in range(len(matrD)):
        matrD[row].append(-z[row + 1])
    f = [0 for i in range(len(matr) + 1)]
    f[0] = -z[0]
    for i in range(1, len(matr)+1):
        f[i] = -matr[i - 1][len(matr[0]) - 1]
    return (matrD,f)
def printF(f):
    print("F= ",end="")
    print(f[0], end=" ")
    for i in range(1,len(f)):
        if(-f[i] >= 0):
            print("+",end="")
        print(-f[i],end="*y^")
        print(i, end=" ")
    print("--> min")
def printDtask(matr):
    for i in range(len(matr)):
        for j in range(len(matr[0])-1):
            if (-matr[i][j] >= 0):
                print("+", end="")
            print(-matr[i][j], end="*y")
            print(j+1, end=" ")
        print(">=",end=" ")
        print(-matr[i][len(matr[i]) - 1])

def print_solution_DV(table):
    m = len(table) - 2
    n = len(table[0]) - 2 - m

    print("Оптимальный план исходной задачи")

    solution = [0 for x in range(len(table[0]) - 2)]
    # solution = [0 for x in range(n)]
    for i in range(1, len(table) - 1):
        solution[int(table[i][0][1]) - 1] = table[i][1]
    print(solution)
    print("Значение в  точке максимума")
    print("Zmax =", table[len(table) - 1][1])

    print("Оптимальный план двойственной задачи")
    solution = [0 for x in range(len(table[0]) - 2)]
    # solution = [0 for x in range(m)]
    for i in range(m):
        solution[i] = table[-1][2+n+i]
    for i in range(m,m+n):
        solution[i] = table[-1][2+i-m]
    print(solution)
    print("Значение в  точке минимума")

    print("Zmin =", table[len(table) - 1][1])
def printDVsolution(matr, z):
    matr = putFictN(matr)
    table = getFirstTable(matr, z)
    printTable(table)
    while not checkSolution(table):
        table = nextStep(table)
        printTable(table)
    print_solution_DV(table)
def checkSolutionPsevdo(table):
    for i in range(1, len(table) - 1):
        if(table[i][1] < 0):
            return False
    return True

def getOpStPsevdo(table):
    max = 2
    for i in range(1, len(table) - 1):
        if (table[i][1] < 0):
            if(table[i][1] < table[max][1]):
                max = i
    return max
def nextStepPsevdo(table):
    indexMin = getOpStPsevdo(table)
    indexChange = 0
    min = 9999999
    for i in range(2, len(table[0])):
        if (table[indexMin][i] < 0):
            if(-table[len(table)-1][i]/table[indexMin][i] < min):
                min = -table[len(table)-1][i]/table[indexMin][i]
                indexChange = i
    if indexChange == 0:
        print("Функция не ограничена")
        exit(5)
    tmp = indexMin
    indexMin = indexChange
    indexChange = tmp

    delit = table[indexChange][indexMin]
    for i in range(1, len(table[indexChange])):
        table[indexChange][i] /= delit
    newTable = [[y for y in x] for x in table]
    newTable[indexChange][0] = 'X' + str(indexMin - 1)
    for i in range(1, len(table)):
        if i != indexChange:
            cof = -table[i][indexMin]
            for j in range(1, len(table[i])):
                newTable[i][j] = table[i][j] + table[indexChange][j] * cof
    return newTable

def printPosUsolution(matr, z):
    matr = putFictN(matr)
    table = getFirstTable(matr, z)
    printTable(table)
    while (not checkSolutionPsevdo(table)) | (not checkSolution(table)):
        if checkSolutionPsevdo(table):
            table = nextStep(table)
        else:
            table = nextStepPsevdo(table)
        printTable(table)
    print_solution_DV(table)


if __name__ == "__main__":
    # print("Введите задачу в стандартной форме")
    # matr_cof = readMatr()
    matr_cof = [[2, -1, 3, -1, -20],
                [-1, -2, -4, -2, -32],
                [-3, -4, -2, 3, -2]]

    # z = readFunck()
    z = [-1, -9, -1, -5, 0]
    matr_cof_d, f = getDtask(matr_cof, z)

    print("Двойственная задача")
    printF(f)
    printDtask(matr_cof_d)
    print("1-Решать исходную\n2-Решать двойственную")
    flag = int(input())
    if flag == 1:
        print("1-Двойственный симплекс метод\n2-Метод последовательного уточнения оценок")
        flag = int(input())
        if flag == 1:
            printDVsolution(matr_cof, z)
        else:
            printPosUsolution(matr_cof, z)
    else:
        print("1-Двойственный симплекс метод\n2-Метод последовательного уточнения оценок")
        flag = int(input())
        if flag == 1:
            printDVsolution(matr_cof_d, f)
        else:
            printPosUsolution(matr_cof_d, f)
