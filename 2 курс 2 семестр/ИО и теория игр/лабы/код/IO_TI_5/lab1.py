
from math import factorial
from itertools import *
def print_matr(matr):
    if (matr == None) | (matr == []):
        return
    print("Your solution:")
    basic_List, basic_string = getBasicList(matr)
    for x in range(len(basic_List)):
        print('x' + str(basic_List[x] + 1) + '=', end='')
        print("%+5.4f" % (matr[basic_string[x]][len(matr[basic_string[x]]) - 1]), end =' ')
        for i in range(len(matr[basic_string[x]]) - 1):
            if (i != basic_List[x]) & (-matr[basic_string[x]][i] != 0):
                print("%+5.4f" % (-matr[basic_string[x]][i]) + '*x' + str(i+1), end=' ')
        print()
def printMatrArr(arrMatr):
    for matr in arrMatr:
        print_matr(matr)
def readMatr():
    print("Input count string: ")
    count_string = int(input())
    print("Input matr: ")
    matr = [[float(x) for x in input().split()] for y in range(count_string)]
    return matr

def basic_collumn(matr_cof, number_string, number_x):
    cof = matr_cof[number_string][number_x]
    for i in range(len(matr_cof[number_string])):
        matr_cof[number_string][i] /= cof

    for i in range(len(matr_cof)):
        if i != number_string:
            cof = matr_cof[i][number_x]
            for j in range(len(matr_cof[i])):
                matr_cof[i][j] -= matr_cof[number_string][j] * cof
    return matr_cof

def delZeroOrNesov(matr_cof):
    for i in range(len(matr_cof)):
        flag = True
        for j in range(len(matr_cof[i])):
            if(matr_cof[i][j] != 0):
                flag = False
        if flag & (matr_cof[i][-1] == 0):
            matr_cof.pop(i)
        elif flag:
            print("Your system is incompatible")
            exit(6)

def getBasicList(matr_cof):
    basicList = []
    usage_string = []
    for i in range(len(matr_cof[0])):
        count_one = 0
        count_another = 0
        one_index = 0
        for j in range(len(matr_cof)):
            if matr_cof[j][i] == 1:
                count_one += 1
                one_index = j
            elif matr_cof[j][i] != 0:
                count_another += 1
        if((count_one == 1) & (count_another == 0)):
            basicList.append(i)
            usage_string.append(one_index)
    return [basicList, usage_string]

def checkEqual(arr, basic, comb):
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            if (arr[i] == arr[j]) & (basic[i] in comb) & (basic[j] in comb):
                return True
    return False

def getBasicMatr(matr_cof, comb):
    new_matr = [[el for el in row] for row in matr_cof]
    basic_list, basic_string = getBasicList(new_matr)
    usage_strings = []
    for el in comb:
        if (el not in basic_list):
            for i in range(len(new_matr)):
                if ((new_matr[i][el] != 0) & (i not in usage_strings)):
                    basic_collumn(new_matr, i, el)
                    usage_strings.append(i)
                    break
            delZeroOrNesov(new_matr)
            basic_list, basic_string = getBasicList(new_matr)
            if checkEqual(basic_string, basic_list, comb):
                return []
        else:
            usage_strings.append(basic_string[basic_list.index(el)])

    return new_matr

def getAllBasicMAtr(matr_cof):
    comb_list  = [i for i in range(len(matr_cof[0]) - 1)]
    for comb in combinations(comb_list, len(matr_cof)):
        new_matr = getBasicMatr(matr_cof, comb)
        if new_matr != []:
            break
    comb_list  = [i for i in range(len(new_matr[0]) - 1)]
    allBasic = []
    for comb in combinations(comb_list, len(new_matr)):
        mtr = getBasicMatr(new_matr, comb)
        if mtr not in allBasic:
            allBasic.append(mtr)
    return allBasic
def setZero(matr):
    basic_list, basic_string = getBasicList(matr)
    for i in range(len(matr)):
        for j in range(len(matr[i]) - 1):
            if not ((i in basic_string) & (j in basic_list)):
                matr[i][j] = 0
    return matr
def getOporPlan(arrMatr):
    result = []
    for matr in arrMatr:
        flag = True
        for row in matr:
            if (row[-1] < 0):
                flag = False
                break
        if flag:
            result.append(setZero(matr))
    return result
def getOptim(arrMatr):
    maxMatr = arrMatr[0]
    maxS = 0
    for matr in arrMatr:
        s = 0
        for row in matr:
            s += row[-1]
        if s > maxS:
            maxS = s
            maxMatr = matr
    return maxMatr

if __name__ == "__main__":
    matr_cof = readMatr()

    allBasicMatr = getAllBasicMAtr(matr_cof)
    printMatrArr(allBasicMatr)
    opor_plan = getOporPlan(allBasicMatr)
    print("Ваши опорные планы")
    printMatrArr(opor_plan)
    optim_pal = []
    if opor_plan != []:
        optim_pal = getOptim(opor_plan)
    print("Ваш оптимальный опроный план")
    print_matr(optim_pal)
