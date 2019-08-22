"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo
Taller06 Estructura datos y algorítmos
"""
import numpy as np

#Exercise 1
class ArrayList:

    def __init__(self):
        self.size = 0
        self.DEFAULT_CAPACITY = 4
        self.elements = np.empty(self.DEFAULT_CAPACITY, int)

    def incrementDEFAULT_CAPACITY(self):
        self.DEFAULT_CAPACITY = self.DEFAULT_CAPACITY*2

    def size(self):
        return self.size

    def getValue(self, index):
        try:
            return self.elements[index]
        except ValueError:
            print('Value not found')
    
    #The asymptotic complexity for this method is O(n), so using this algorithm on a text editor is not the most suitable option. The asymptotyc 
    # complexcity to add n characters is O(n^n)
    def add(self, x):
        self.size = self.size+1
        if self.DEFAULT_CAPACITY > self.size:
            self.elements[self.size-1] = x
        
        else:
            ArrayList.incrementDEFAULT_CAPACITY(self)
            elements2 = np.empty(self.DEFAULT_CAPACITY, int)
            
            for i in range(0, self.size):
                elements2[i] = self.elements[i]
            
            elements2[self.size-1] = x
            self.elements = elements2

    #The asymptotic complexity for this method is O(n^2), so using this algorithm on a text editor is not the most suitable option. The asymptotyc 
    # complexcity to add n characters is O(n^n)
    def addInIndex(self, index, x):
        self.size = self.size+1
        if self.DEFAULT_CAPACITY > self.size:
            elements2 = np.empty(self.DEFAULT_CAPACITY, int)
            
            for i in range(0, index):
                elements2[i] = self.elements[i]
            
            elements2[index] = x
            
            for i in range(index+1, self.size):
                elements2[i] = self.elements[i]
            
            self.elements = elements2
        
        else:
            ArrayList.incrementDEFAULT_CAPACITY(self)
            elements2 = np.empty(self.DEFAULT_CAPACITY, int)

            for i in range(0, index):
                elements2[i] = self.elements[i]

            elements2[index] = x

            for i in range(index+1, self.size):
                elements2[i] = self.elements[i]

            self.elements = elements2

    def deleteChar(self, index):
        self.size = self.size-1
        self.elements[self.size+1] = 0

        for i in range(index, self.size+1):
            self.elements[i] = self.elements[i+1]


    def toString(self):
        return self.elements



























