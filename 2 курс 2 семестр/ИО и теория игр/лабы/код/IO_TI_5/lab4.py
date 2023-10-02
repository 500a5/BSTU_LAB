def inputArr():
    return [float(x) for x in input().split()]

def inputC(n, m):
    return [[float(x) for x in input().split()] for i in range(n)]

def checkEmpty(check):
    for i in check:
        if (i[0] == False):
            return False
    return True

def step(A, B, map, i_index, j_index):
    if (A[i_index][1] > B[j_index][1]):
        map[i_index][j_index] = B[j_index][1]
        B[j_index][0] = True
        A[i_index][1] -= B[j_index][1]
    elif (A[i_index][1] < B[j_index][1]):
        map[i_index][j_index] = A[i_index][1]
        A[i_index][0] = True
        B[j_index][1] -= A[i_index][1]
    else:
        map[i_index][j_index] = A[i_index][1]
        A[i_index][0] = True
        B[j_index][1] = 0.

def stepSever(A, B, map):
    i_index = 0
    j_index = 0
    for i in range(len(A)):
        if (A[i][0] == False):
            i_index = i
            break
    for i in range(len(B)):
        if (B[i][0] == False):
            j_index = i
            break

    step(A, B, map, i_index, j_index)
def minCost(A, B, C):
    a_check = [[False, A[i]] for i in range(len(A))]
    b_check = [[False, B[i]] for i in range(len(B))]
    map = [['d' for i in range(len(B))] for j in range(len(A))]
    while not (checkEmpty(a_check) | checkEmpty(b_check)):
        i_index = 0
        j_index = 0
        min = 999999
        for i in range(len(C)):
            for j in range(len(C[0])):
                if (C[i][j] < min) & (not a_check[i][0]) & (not b_check[j][0]):
                    i_index = i
                    j_index = j
                    min = C[i][j]
        step(a_check, b_check, map, i_index, j_index)

    return map
def severozapad(A, B):
    a_check = [[False, A[i]] for i in range(len(A))]
    b_check = [[False, B[i]] for i in range(len(B))]
    map = [['d' for i in range(len(B))] for j in range(len(A))]
    while not (checkEmpty(a_check) | checkEmpty(b_check)):
        stepSever(a_check, b_check, map)

    return map

def checkResh(omega):
    for om in omega:
        if om < 0:
            return True
    return False
def getCircle(map, pred, circl):
    if   (pred == 's'):
        for i in range(len(map)):
            if (circl[-1][0] != i) & (map[i][circl[-1][1]] != 'd'):
                cpC = circl.copy()
                cpC.append((i, circl[-1][1]))
                cpC = getCircle(map, 'v', cpC)
                if (cpC[0][0] == cpC[-1][0]) & (cpC[0][1] == cpC[-1][1]):
                    circl = cpC
                    return circl
    elif (pred == 'v'):
        for j in range(len(map[0])):
            if (map[circl[-1][0]][j] == 'd'):
                if (j == circl[0][1]) &  (circl[-1][0] == circl[0][0]):
                    circl.append(circl[0])
                    return circl
            if (circl[-1][1] != j) & (map[circl[-1][0]][j] != 'd'):
                cpC = circl.copy()
                cpC.append((circl[-1][0], j))
                cpC = getCircle(map, 'h', cpC)
                if (cpC[0][0] == cpC[-1][0]) & (cpC[0][1] == cpC[-1][1]):
                    circl = cpC
                    return circl
    elif (pred == 'h'):
        for i in range(len(map)):
            if (map[i][circl[-1][1]] == 'd'):
                if (i == circl[0][0]) &  (circl[-1][1] == circl[0][1]):
                    cpC = circl.append(circl[0])
                    return circl
            if (circl[-1][0] != i) & (map[i][circl[-1][1]] != 'd'):
                cpC = circl.copy()
                cpC.append((i, circl[-1][1]))
                cpC = getCircle(map, 'v', cpC)
                if (cpC[0][0] == cpC[-1][0]) & (cpC[0][1] == cpC[-1][1]):
                    circl = cpC
                    return circl
    return circl
def getCostC(C, circl):
    cost = 0
    sign = 1
    for i in range(len(circl) - 1):
        cost += sign * C[circl[i][0]][circl[i][1]]
        sign *= -1
    return cost
def getCostCircle(C, map, i, j, circls):
    circl = [(i,j)]
    circls.append(getCircle(map, 's', circl))
    return getCostC(C, circls[-1])
def getOmega(C, map):
    omega = []
    circls = []
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] == 'd':
                omega.append(getCostCircle(C, map, i, j, circls))
    return (omega, circls)
def getStepCircle(C, map, circle):
    min = 99999
    pos = 0
    sign = -1
    for i in range(1, len(circle) - 1):
        if (sign < 0) & (map[circle[i][0]][circle[i][1]] < min):
            min = map[circle[i][0]][circle[i][1]]
            pos = circle[i]
        sign *= -1
    sign = -1
    for i in range(1, len(circle) - 1):
        if(sign<0):
            map[circle[i][0]][circle[i][1]] -= min
        else:
            map[circle[i][0]][circle[i][1]] += min
        sign *= -1
    map[circle[0][0]][circle[0][1]] = min
    map[pos[0]][pos[1]] = 'd'
def checkExistUV(U, V):
    for i in U:
        if i == 'd':
            return True
    for i in V:
        if i =='d':
            return True
    return False
def getUV(C, map):
    U = ['d' for i in range(len(map))]
    U[0] = 0
    V = ['d' for i in range(len(map[0]))]
    urav = []
    for i in range(len(map)):
        for j in range(len(map[0])):
            if (map[i][j] != 'd'):
                urav.append([i,j,C[i][j]])
    for i in urav:
        print("u" + str(i[0]+1) + " + v"+str(i[1]+1) + " = "+ str(i[2]))
    for i in range(len(urav)):
        if urav[i][0] == 0:
            V[urav[i][1]] = urav[i][2]
    while(checkExistUV(U,V)):
        for i in range(len(urav)):
            if (U[urav[i][0]] == 'd') & (V[urav[i][1]]!='d'):
                U[urav[i][0]] = urav[i][2] - V[urav[i][1]]
        for j in range(len(urav)):
            if (V[urav[j][1]] == 'd') & (U[urav[j][0]]!='d'):
                V[urav[j][1]] = urav[j][2] - U[urav[j][0]]
    return (U, V)
def getOmegaPot(U, V, C, map):
    omega = []
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j]=='d':
                omega.append([C[i][j] - (U[i]+V[j]), i, j])
    return omega
def potential(A, B, C, map):
    printTable(A,B,C,map)
    printZ(C,map)
    U,V = getUV(C, map)
    omega = getOmegaPot(U, V, C, map)
    for i in range(len(U)):
        print("u" + str(i+1) + "=" + str(U[i]))
    for i in range(len(V)):
        print("v" + str(i+1) + "=" + str(V[i]))
    printOmegaPot(map, omega)
    while checkResh([x[0] for x in omega]):
        i_index = 0
        min = [999999]
        for i in range(len(omega)):
            if omega[i][0] < min[0]:
                i_index = i
                min = omega[i]
        getStepCircle(C, map, getCircle(map,'s',[[omega[i_index][1],omega[i_index][2]]]))
        printTable(A, B, C, map)
        printZ(C, map)
        U, V = getUV(C, map)
        omega = getOmegaPot(U, V, C, map)
        for i in range(len(U)):
            print("u" + str(i + 1) + "=" + str(U[i]))
        for i in range(len(V)):
            print("v" + str(i + 1) + "=" + str(V[i]))
        printOmegaPot(map, omega)
def raspred(A, B, C , map):
    omega, circls = getOmega(C, map)
    printTable(A, B, C, map)
    printOmega(map, omega, circls)
    printZ(C, map)
    while checkResh(omega):
        i_index = 0
        min = 99999
        for i in range(len(omega)):
            if omega[i] < min:
                i_index = i
                min = omega[i]
        getStepCircle(C, map, circls[i_index])
        omega, circls = getOmega(C, map)
        printTable(A, B, C, map)
        printOmega(map, omega,circls)
        printZ(C, map)

def printOmega(map, omega, circls):
    k = 0
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] == 'd':
                print("omg("+str(i)+","+str(j)+")="+str(omega[k]))
                print(circls[k])
                k+=1
def printOmegaPot(map, omega):
    k = 0
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] == 'd':
                print("omg("+str(i+1)+","+str(j+1)+")="+str(omega[k][0]))
                k+=1
def printTable(A,B,C,map):
    print("   ",end=" ")
    for i in B:
        print(i, end=" ")
    print()
    for i in range(len(A)):
        print(A[i], end=" ")
        for j in range(len(C[i])):
            print("("+ str(C[i][j]) + "," + str(map[i][j])+")", end="")
        print()

def printZ(C, map):
    count = 0
    for i in range(len(map)):
        for j in range(len(map[0])):
            if map[i][j] != 'd':
                count+=C[i][j]*map[i][j]
    print("Z="+str(count))

print("Введите А")
A = inputArr()
A1 = [160, 140, 170]
A2 = [180, 40, 80]
A3 = [180, 350, 20]


print("Введите В")
B = inputArr()
B1 = [120,50,190,110]
B2 = [120,40,60,80]
B3 = [110, 90, 120,80, 150]


print("Введите С")
C = inputC(len(A), len(B))
C1 = [[7,8,1,2],
      [4,5,9,8],
      [9,2,3,6]]
C2 = [[2,3,4,3],
      [5,3,1,2],
      [2,1,4,2]]
C3 = [[7,12,4,6,5],
      [1,8,6,5,3],
      [6,13,8,7,4]]


print("Введите 1 для метода северозападного угла: ")
flag = int(input())
if flag == 1:
    map = severozapad(A, B)
else:
    map = minCost(A, B, C)
print("Введите 1 для распределительного метода: ")
flag = int(input())
if flag == 1:
    raspred(A, B, C, map)
else:
    potential(A, B, C, map)