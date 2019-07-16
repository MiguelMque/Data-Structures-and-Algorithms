"""
@author Miguel Angel Correa - Pablo Buitrago

Taller 01 estructura datos y algorítmos.
"""

import math 

class Coordinate(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def distance(self, other):
        x_dif_sq = (self.x - other.x)**2
        y_dif_sq = (self.y - other.y)**2
        return (x_dif_sq + y_dif_sq)**0.5
    
    def polarRadio(self):
        return distance(self, Coordinate(0,0))
    
    def polarAngle(self):
        return math.atan(self.y/self.x)
    
    def getX(self):
        return self.x
    
    def getY(self):
        return self.y
    
class Date(object):
    def __init__(self, day, month, year):
        self.day = day
        self.month = month
        self.year = year
        
    def toString(self):
        return year+'-'+month+'-'+day
    
    def compare(self, other):
        d1 = self.toString
        d2 = other.toString
        
        for i in (10):
            if d1[i] < d2[i]:
                return  self.toString+' is before '+other.toString
            elif d1[i] > d2[i]:
                return self.toString+' is after '+other.toString
            
        return self.toString+' is the same as '+other.toString
    
class Counter(object):
    def __init__(self, ID):
        self.ID = ID
        self.c = 0
        
    def increase(self):
        self.c += 1
        
    def getIncreases(self):
        return self.c
    
    def toString(self):
        return self.ID +': '+ self.c
        
