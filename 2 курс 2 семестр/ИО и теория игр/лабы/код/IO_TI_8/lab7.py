
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
    # matr = putFictN(matr)
    for i in range(30):
        print("Задача номер", i+1)
        if(i):
            table = printPosUsolution(matr, z)
        else:
            table = printFictSolution(matr, z)
        if (isZnumber(table)):
            print("Решение найдено")
            return
        else:
            matr = putUexpr(getMatr(table))
            z = getZ(table)
            z.append(0)

    print("Похоже что решения в целых числах нет, слишком долго")

def putVexpr(matr, index, n, flag):
    newU = [0 for i in range(len(matr[0]))]
    if(flag):
        newU[index] = -1
        newU[-1] = -n + 1
        for i in range(len(matr)):
            if (matr[i][index] == 1):
                for j in range(len(matr[0])):
                    newU[j] += matr[i][j]

    else:
        newU[index] = 1
        newU[-1] = n
        for i in range(len(matr)):
            if (matr[i][index] == 1):
                for j in range(len(matr[0])):
                    newU[j] -= matr[i][j]

    matr.append(newU)
    for i in range(len(matr)):
        matr[i].append(matr[i][-1])
        matr[i][-2] = 0
    matr[-1][-2] = 1

    return matr

def printVetv(matr, z):
    matr = putFictN(matr)
    solutions = []
    listTask = [[matr,z]]
    for i in range(3):
        print("Уровень номер ", i+1)
        nTask = 0
        newList = []
        for i in range(len(listTask)):
            print("Задача номер ", nTask)
            nTask += 1
            matr, z = listTask.pop(0)
            table = printPosUsolution(matr, z)
            if (isZnumber(table)):
                solution = [0 for x in range(len(table[0]) - 2)]
                for i in range(1, len(table) - 1):
                    solution[int(table[i][0][1]) - 1] = table[i][1]
                solutions.append([table[len(table) - 1][1], solution])
            else:
                Cmatr = getMatr(table)
                indexMax = 0
                for i in range(len(Cmatr)):
                    if (not isZ(Cmatr[i][-1] % 1)):
                        if (Cmatr[i][-1] % 1 > Cmatr[indexMax][-1] % 1):
                            indexMax = i
                n = table[indexMax + 1][1] - (table[indexMax + 1][1]%1)
                indexMax = int(table[indexMax + 1][0][1:]) - 1
                newMatr = [[matr[i][j] for j in range(len(matr[0]))] for i in range(len(matr))]
                fz = [i for i in z]
                fz.append(0)
                newList.append([putVexpr(matr.copy(), indexMax,n, 1), fz])
                newList.append([putVexpr(newMatr.copy(), indexMax,n, 0), fz])
        listTask = newList



    print("Итоговое решение")
    print(solutions)

if __name__ == "__main__":
    # matr_cof = readMatr()
    matr_cof = [[10, 3, 1, 0, 0, 80],
                [15,-4, 0,-2, 0, 27],
                [2, -9, 0, 0, 1, 16]
                ]

    # z = readFunck()
    z = [0, 10, -1, 0, 2, 0, 0]
    print("Введите 1 для первого алгоритма Гомори")
    if (int(input())):
        printGomori(matr_cof, z)
    else:
        printVetv(matr_cof, z)

