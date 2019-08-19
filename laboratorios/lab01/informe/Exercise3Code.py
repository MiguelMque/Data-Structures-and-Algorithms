"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo
Lab 01 Estructura datos y algorítmos
"""

#Exercise 3.2
import time
import numpy as np
import matplotlib.pyplot as plt

def milli():

    return time.time() * 1000000

def rect(n):
    '''
    Return the number of ways how one can organize 1x2 rectangles in a 2xn rectangle. 
    '''
    if n == 1 or n == 2:
        return n

    arr = [0]

    arr.append(1)
    arr.append(2)

    for i in range(3, n+1):
        arr.append(arr[i-1] + arr[i-2])
    
    return arr[n]

def plots():

    x1 = []
    y1 = []

    for i in range(1,20):

        start = milli()
        rect(i)
        end = milli() - start

        x1.append(i)
        y1.append(end)

    
    print(y1)

    plt.plot(x1, y1, 'ro')
    plt.axis([0, 20, 0, 25])
    plt.title('rect')

    
    plt.show()

plots()
