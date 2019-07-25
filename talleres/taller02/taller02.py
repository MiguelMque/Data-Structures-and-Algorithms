
"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo

Taller02 Estructura datos y algorítmos
"""
#PUNTO 1
def gcd(a, b):
  if b == 0:
    return a
  return gcd(b, a%b) 



#PUNTO 2 v1
def check_w(w, l):

    b = False
    
    for x in l:
    
      remaining = [y for y in l if y!=x]
    
      other = other or check_w(remaining)
    
    return other
#PUNTO 2 v2
def check_w2(n, l, w):
    if n == len(l):
        return (w == 0)
    if check_w2(n+1, l, w) or check_w2(n+1, l, w - l[n]):
        return True
    return False


#PUNTO 3 v1
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


def print_possibilities(l):

    n = combinations(l)
        
    for x in l:
        remaining = [w for w in l if w!=x]
        
        n = n + combinations(remaining)
        
        n = n + [x]
        
    
    n = n + []
    
    return n
        
#PUNTO 3 v2
def comb(prefix, s):
    if len(s) == 0:
        print(prefix)
    else:
        comb(prefix+s[0], s[1:])
        comb(prefix, s[1:])

def combinations(s):
    comb("", s)

print(combinations("abc"))
    
