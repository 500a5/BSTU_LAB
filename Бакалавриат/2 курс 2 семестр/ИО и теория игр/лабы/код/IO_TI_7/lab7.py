
from lab6 import *
def isZ(number):
    n = fabs(number)
    if(n%1) < 0.5:
        return (n%1) < 1e-5
    else:
        return (n%1) > 0.99999999
def isZnumber(table):
    for i in range(1,len(table)-1):
        if(not isZ(table[i][1])):
            return False
    return True

def getMatr(table):
    matr = [[table[i][j] for j in range(2, len(table[0]))] for i in range(1,len(table) - 1)]
    for i in range(1,len(table)-1):
        matr[i-1].append(table[i][1])
    return matr

def getZ(table):
    newZ = [-table[-1][j] for j in range(1, len(table[-1]))]
    newZ[0] = -newZ[0]
    return newZ

def putUexpr(matr):
    indexMax = 0
    for i in range(len(matr)):
        if(not isZ(matr[i][-1]%1)):
            if(matr[i][-1]%1 > matr[indexMax][-1]%1):
                indexMax = i

    newU = []
    for j in range(len(matr[0])):
        if(not isZ(matr[indexMax][j])):
            newU.append(-(fabs(matr[indexMax][j])%1))
        else:
            newU.append(0)
    matr.append(newU)
    for i in range(len(matr)):
        matr[i].append(matr[i][-1])
        matr[i][-2] = 0
    matr[-1][-2] = 1

    return matr


def printGomori(matr, z):
    matr = putFictN(matr)
    for i in range(30):
        print("Задача номер", i+1)
        table = printPosUsolution(matr, z)
        if (isZnumber(table)):
            print("Решение найдено")
            return
        else:
            matr = putUexpr(getMatr(table))
            z = getZ(table)
            z.append(0)

    print("Похоже что решения в целых числах нет, слишком долго")


if __name__ == "__main__":
    # matr_cof = readMatr()
    matr_cof = [[7, 5, 1, 0, 0, 28],
                [4, -6, 0, 3, 0, 14],
                [-3, 4, 0, 0, 1, 6]
                ]
    z = [0, -3, 1, 0, 0, 1]
    printGomori(matr_cof, z)

