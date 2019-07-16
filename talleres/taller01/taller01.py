#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jul 15 22:10:31 2019

@author: miguelmque
"""

import math


class Coordinate(object):
    
    
    def __init__(self, x, y):
        self.x = x
        self.y = y
        
    def distance(self, other):
        x_diff_sq = (self.x-other.x)**2
        y_diff_sq = (self.x-other.x)**2
        
        return (x_diff_sq + y_diff_sq)**0.5
    
    
    def radio(self):
        
        ori = Coordinate(0,0)
        
        r = self.distance(ori)
        
        return r
    
    def angle(self):
        
        return math.acos(self.x/self.radio)
    
    
    
    
class Date(object):
    
    def __init__(self, d, m, y):
        self.d = d
        self.m = m
        self.y = y
    
    def __str__(self):
        
        return y + '-' + m + '-' + d
    
    def compare(self, other):
        
       date1 = self.__str__
       date2 = other.__str__
        
        for i in range(0,11):
            
            if int(date1[i]) > int(date2[i]):
                
                return 'After'
            
            elif int(date2[i]) > int(date1[i]):
                
                return 'Before'
            
            
            
        return 'Equal'
    
    
class Counter(object):
    
    def __init__(self, ide):
        self.ide = ide
    
    
    def increment:
        self.ide += 1
        
    def sinceCreation:
        
        return self.ide
    
    def __str__(self):
        
        return self.ide
        
            
        