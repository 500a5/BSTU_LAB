from itertools import *
import numpy as np
import matplotlib.pyplot as plt
import math
import scipy
import scipy.optimize as opt
import scipy.integrate as integrate

def r0(x1,x2):
  return 0
def r1(x1,x2):
  return 1
def rx1(x1,x2):
  return x1
def rx2(x1,x2):
  return x2
def rx1_2(x1,x2):
  return x1*x1
def rx2_2(x1,x2):
  return x2*x2
def rx2x1(x1,x2):
  return x2*x1

arm=[rx1,rx2,rx2_2,rx2x1]

def Get_F(i:int,RRR):#возвр.матр. F
  count_r=len(RRR[i])
  F=np.zeros((n1,count_r  ))#M: 12 x кол-во регрессоров
  for it in range(n1):
    for j in range(count_r):
      F[it][j]=RRR[i][j](X1[it][0],X2[it][0])
  return F

def Get_res_s(it:int,A):
  xx0=[]
  xx1=[]
  xx2=[]
  yy0=[]
  yynew=[]
  for i in range(n1):
    xx0.append(i)
    xx1.append(X1[i][0])
    xx2.append(X2[i][0])
    yy0.append(Y0[i][0])
    tmp=0.0
    for j in range(len(A)):
      tmp+=A[j][0]*RRR[it][j](X1[i][0],X2[i][0])
    yynew.append(tmp)
  return xx0,xx1,xx2,yy0,yynew

def Get_Grafic(xx0,yy0,yynew):
  fig, ax = plt.subplots()
  ax.scatter(xx0, yy0)
  ax.plot(xx0, yy0, 'r', lw=2, label="Theoretical")
  ax.plot(xx0, yynew, 'b', lw=2, label="Fit")
  ax.legend()
  ax.set_xlim(0, 13)
  ax.set_xlabel(r"$x$", fontsize=18)
  ax.set_ylabel(r"$y$", fontsize=18)
  plt.show()
  return

n1=12
n2=10
##вектор x1,x2,y
X1=np.array([
   [12.0],
   [8.0],
   [11.0],
   [10.0],
   [8.0],
   [12.0],
   [6.0],
   [16.0],
   [13.0],
   [13.0],
   [11.0],
   [10.0],
   [10.0]
])

X2=np.array([
   [4.0],
   [2.0],
   [14.0],
   [1.0],
   [10.0],
   [1.0],
   [9.0],
   [16.0],
   [9.0],
   [7.0],
   [16.0],
   [13.0],
   [11.0]
])

Y0=np.array([
   [88.3647155],
   [38.9171776],
   [214.6755189],
   [41.2421623],
   [122.1004938],
   [50.8180019],
   [91.4007504],
   [337.5613222],
   [174.0631677],
   [154.9927891],
   [244.7164725],
   [188.6239540]
])

Y=np.array([
   159.8463314,
   162.4726812,
   161.2448375,
   163.1571826,
   164.5559629,
   164.9874791,
   159.9388978,
   159.9696550,
   165.5718658,
   163.6270751
])


def Get_Qo(yy0,yynew):
  Qo=0.0 #Q остаток
  for i in range(n1):
    Qo+=(yy0[i]-yynew[i])**2
  return Qo

def Get_RRR():
  tf=[]
  for i in range(2, len(arm)):
    j = combinations(arm, i)
    tf+=list(j)
  return tf


global r_min
r_min=999999.9
global r_num
r_num=0
RRR=Get_RRR()
for iterat in range(len(RRR)):
  F=Get_F(iterat,RRR)
  A=(np.linalg.inv(((F.transpose()).dot(F))).dot(F.transpose())).dot(Y0)
  #print('A=',A)
  xx0,xx1,xx2,yy0,yynew=Get_res_s(iterat,A)
  #print(yy0,yynew)
  Qoo=Get_Qo(yy0,yynew)
  print('i=',iterat,'Q ост=',Qoo)
  if(r_min>Qoo):
    r_min=Qoo
    r_num=iterat

F=Get_F(r_num,RRR)
print('F=',F)
A=(np.linalg.inv(((F.transpose()).dot(F))).dot(F.transpose())).dot(Y0)
print('A=',A)
xx0,xx1,xx2,yy0,yynew=Get_res_s(r_num,A)

print('i=',r_num,'func=',RRR[r_num])#STR_RRR
Get_Grafic(xx0,yy0,yynew)
