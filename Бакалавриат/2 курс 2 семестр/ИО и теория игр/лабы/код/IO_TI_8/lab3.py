from math import fabs

from lab2 import *
def printFict(table, n):
    for i in range(len(table)-1):
        for j in range(len(table[0])):
            print(table[i][j], end=" ")
        print()
def getOpStlog(table):
    max = 2
    for i in range(2, len(table[0])):
        if (table[len(table) - 2][i] < 0):
            if(table[len(table) - 2][i] < table[len(table) - 2][max]):
                max = i
    return max

def nextStepFict(table):
    indexMin = getOpStlog(table)
    indexChange = 0
    min = 9999999
    for i in range(1, len(table) - 2):
        if (table[i][indexMin] > 0):
            if(table[i][1]/table[i][indexMin] < min):
                min = table[i][1]/table[i][indexMin]
                indexChange = i
    if table[indexChange][0][0] != 'Y':
        for i in range(1, len(table) - 2):
            if(table[i][0][0] == 'Y'):
                indexChange = i
                break
        if((table[indexChange][indexMin] == 0) | (indexMin >= len(table[0])- len(table) + 2)):
            for i in range(2, len(table[0])- len(table) + 2):
                if(fabs(table[indexChange][i]) > 1e-5):
                    indexMin = i

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
def putFict(matr):
    newMatr = [[ 0.0 for j in range(len(matr[0]) + len(matr))] for i in range(len(matr))]
    for i in range(len(matr)):
        for j in range(len(matr[0]) - 1):
            if(matr[i][len(matr[0]) - 1] < 0):
                newMatr[i][j] = -matr[i][j]
            else:
                newMatr[i][j] = matr[i][j]
    for i in range(len(matr)):
        newMatr[i][len(matr[0]) + i - 1] = 1.0

    for i in range(len(matr)):
        if (matr[i][len(matr[0]) - 1] < 0):
            newMatr[i][len(newMatr[0]) - 1] = -matr[i][len(matr[0]) - 1]
        else:
            newMatr[i][len(newMatr[0]) - 1] = matr[i][len(matr[0]) - 1]
    return newMatr
def fictZ(matr):
    zf = [0.0 for i in range(len(matr[0]))]
    for j in range(len(matr)):
        zf[0] -= matr[j][len(matr[0]) - 1]
    for i in range(1, len(zf) - len(matr)):
        for j in range(len(matr)):
            zf[i] += matr[j][i - 1]
    return zf

def getFictBasisTable(matr, z):
    newMatr = putFict(matr)
    zf = fictZ(newMatr)
    table = getFirstTable(newMatr, zf)
    table.append([0 for i in range(len(table[0]))])
    table[len(table) - 1][0] = 'Z'
    table[len(table) - 1][1] = z[0]
    for i in range(1,len(z)):
        table[len(table) - 1][i + 1] = -z[i]
    for i in range(1,len(table) - 2):
        table[i][0] = 'Y' + table[i][0][1]
    printFict(table, len(matr[0]) - 1)
    for i in range(len(matr)):
        table = nextStepFict(table)
        printFict(table, len(matr[0]) - 1)
    newTable = [[0 for i in range(len(table[0]) - len(matr))] for i in range(len(table))]
    for i in range(len(newTable)):
        for j in range(len(newTable[0])):
            newTable[i][j] = table[i][j]
    newTable.pop(len(newTable) - 2)
    newTable[len(newTable) - 1][0] = 'Z'
    return newTable
def printFictSolution(matr, z):
    table = getFictBasisTable(matr, z)
    printTable(table)
    while not checkSolution(table):
        table = nextStep(table)
        printTable(table)
    print_solution(table)
    return table
def getMz(matr, z, M):
    zf = [0.0 for i in range(len(matr[0]))]
    for i in range(len(z)):
        zf[i] += z[i]
    for j in range(len(matr)):
        zf[0] -= M*matr[j][len(matr[0]) - 1]
    for i in range(1, len(zf) - len(matr)):
        for j in range(len(matr)):
            zf[i] += M*matr[j][i - 1]

    return zf

def getBigTable(matr, z):
    M = 100
    newMatr = putFict(matr)
    zf = getMz(newMatr, z, M)
    table = getFirstTable(newMatr, zf)
    return table

def printBigSolution(matr, z):
    table = getBigTable(matr, z)
    printTable(table)
    while not checkSolution(table):
        table = nextStep(table)
        printTable(table)
    print_solution(table)


if __name__ == "__main__":
    matr_cof = readMatr()
    z = readFunck()
    print("Искусственный базис")
    printFictSolution(matr_cof, z)
    print("Большие штрафы")
    printBigSolution(matr_cof, z)