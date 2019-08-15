import time
import numpy as np
import matplotlib.pyplot as plt



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


def milli():

    return time.time() * 1000000


for i in range(1,20):

    x1 = []
    y1 = []

    l = []

    for w in range(0,i):
        l.append(i)

    start = milli()
    insertionSort(l)
    end = milli() - start

    x1.append(i)
    y1.append(end)

    l = []

    for w in range(0,i):
        l.append(i)

    start = milli()
    insertionSort(l)
    end = milli() - start

    x1.append(i)
    y1.append(end)

    l = []

    print(end)

    plt.figure()
    plt.subplot(2,2,1)
    plt.plot(x1, y1, 'ro')
    plt.axis([0, 20, 0, 55])


