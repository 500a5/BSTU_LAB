from lab5 import *
def getSimplMatr(matr):
    for i in range(len(matr)):
        matr[i].append(1)
    return matr
def getSimplZ(matr):
    a = [0]
    for i in range(len(matr[0]) - 1):
        a.append(1)
    return a

def printFG(f):
    print("f= ",end="")
    print(f[0], end=" ")
    for i in range(1,len(f)):
        if(f[i] >= 0):
            print("+",end="")
        print(f[i],end="*y")
        print(i, end=" ")
    print("--> max")
def printGtask(matr):
    for i in range(len(matr)):
        for j in range(len(matr[0])-1):
            if (matr[i][j] >= 0):
                print("+", end="")
            print(matr[i][j], end="*y")
            print(j+1, end=" ")
        print("<=",end=" ")
        print(matr[i][len(matr[i]) - 1])

def printSimplTaskG(matr, z):
    printFG(z)
    printGtask(matr)

def print_solution_Game(table):
    m = len(table) - 2
    n = len(table[0]) - 2 - m

    solution = [0 for x in range(m)]
    # solution = [0 for x in range(m)]
    print("P = ", end="")
    for i in range(m):
        solution[i] = table[-1][2 + n + i]/table[len(table) - 1][1]
    print(solution)

    print("Q = ", end="")
    solution = [0 for x in range(len(table[0]) - 2)]
    # solution = [0 for x in range(n)]
    for i in range(1, len(table) - 1):
        solution[int(table[i][0][1]) - 1] = table[i][1] / table[len(table) - 1][1]
    solution = [solution[i] for i in range(n)]
    print(solution)
    print("Fmin =", table[len(table) - 1][1])


def printGameSolution(matr, z):
    matr = putFict(matr)
    table = getFirstTable(matr, z)
    printTable(table)
    while not checkSolution(table):
        table = nextStep(table)
        printTable(table)
    print_solution_Game(table)


if __name__ == "__main__":
    print("Введите платежную матрицу")
    matr_cof = [[8, 5, 7 , 6],
                [9, 8, 10, 7],
                [12, 6, 4, 3],
                [7, 13, 5, 2],]
    matr_g = getSimplMatr(matr_cof)
    z = getSimplZ(matr_g)
    print("Задача для решения двойственным симплекс-методом")
    printSimplTaskG(matr_g, z)

    printGameSolution(matr_g, z)

