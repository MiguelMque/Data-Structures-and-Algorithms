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



print("Input: ", end ="")

n = int(input())

print("The number of ways one can organize", n, "rectangles is", rect(n))







        

