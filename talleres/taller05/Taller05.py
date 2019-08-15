"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo
Taller05 Estructura datos y algorítmos
"""
import time
import numpy as np
import matplotlib.pyplot as plt


#EXCERCISE 1
def insertionSort(arr):

    for i in range(0, len(arr)):
        temp_pos = i
        for j in reversed(range(0, i)):

            if(arr[temp_pos] < arr[j]):
                temp = arr[j]
                arr[j] = arr[temp_pos]
                arr[temp_pos] = temp
                temp_pos = j
    return arr
    #O(n^2)

#EXCERCISE 2
def ar_sum(arr):
    sum = 0
    for i in range(len(arr)):
        sum += arr[i]
    
    return sum
    #O(n)

def milli():

    return time.time() * 1000000


def plots():

    x1 = []
    y1 = []

    x2 = []
    y2 = []

    for i in range(1,20):
        
        l = []

        for w in range(0,i):
            l.append(i)

        start = milli()
        insertionSort(l)
        end = milli() - start

        x1.append(i)
        y1.append(end)

        start2 = milli()
        ar_sum(l)
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
    plt.axis([0, 20, 0, 28])
    plt.title('insertionSort')

    plt.subplot(2,2,2)
    plt.plot(x2, y2, 'ro')
    plt.axis([0, 20, 0, 5])
    plt.title('arr_sum')
    
    plt.show()
    
    

plots()

