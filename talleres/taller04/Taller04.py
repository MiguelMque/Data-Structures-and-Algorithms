"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo
Taller03 Estructura datos y algorítmos
"""
import time
import numpy as np
import matplotlib.pyplot as plt

def milli():

    return time.time() * 1000000


#EXCERCISE 1
def ar_sum(arr, arr_sum):

  arr_sum += arr[0]

  if len(arr) == 1:
    return arr_sum

  return ar_sum(arr[1:], arr_sum)

  #c_2*n + T(n-1) 


#EXCERCISE 2
def check_w2(n, l, w):
    if n == len(l):
        return (w == 0)
    if check_w2(n+1, l, w) or check_w2(n+1, l, w - l[n]):
        return True
    return False

  # 2*T(n-1) + c_2

#PLOTS
def plots():
    x1 = []
    x2 = []

    y1 = []
    y2 = []


    for i in range(1,20):
        
        

        l = []

        for w in range(0,i):
            l.append(i)

        start = milli()
        ar_sum(l,0)
        end = milli() - start

        x1.append(i)
        y1.append(end)

        start2 = milli()
        check_w2(0, l, i)
        end2 = milli() - start2

        x2.append(i)
        y2.append(end2)

    print(y1)
    print()
    print(y2)

    l = []

    plt.figure()
    plt.subplot(2,2,1)
    plt.plot(x1, y1, 'ro')
    plt.axis([0, 20, 0, 15])
    plt.title('EXCERCISE 1')

    plt.subplot(2,2,2)
    plt.plot(x2, y2, 'ro')
    plt.axis([0, 20, 0, 15])
    plt.title('EXCERCISE 2')

    plt.show()

plots()
