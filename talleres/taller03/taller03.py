"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo

Estructura datos y algorítmos taller 03
"""

#EXCERCISE 1
def hanoi_recursively(n, fr, to, aux):

  if n == 1:
    print("Move from " + fr + " to " + to)

  else:
    hanoi_recursively(n-1, fr, aux, to)
    hanoi_recursively(1, fr, to, aux)
    hanoi_recursively(n-1, aux, to, fr)

def hanoi(m):
  hanoi_recursively(m, fr, to, aux)

#EXCERCISE 2
def combinations(sequence):
    
    if len(sequence) == 1:
        return [sequence,]
       
    l = []
   
    for x in sequence:
        remaining = [w for w in sequence if w!=x]
        other = combinations(remaining)
       
        for z in other:
            l.append([x] + z)
           
    return l

def printCombinations(str):
  combinations(str)
  print(combinations.l)
