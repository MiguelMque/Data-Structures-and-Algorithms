import numpy as np




class ArrayList(object):
        

    def __init__(self):
        self.size = 0;
        self.DEFAULT_SIZE = 4
        self.elements = np.empty(self.DEFAULT_SIZE, int)
        

    def size(self):
        return self.size

    def add(self, x):
        self.size = self.size + 1

        if self.DEFAULT_SIZE > self.size:
            self.elements[self.size-1] = x


        else:

            self.DEFAULT_SIZE = self.DEFAULT_SIZE*2

            elements2 = np.empty(self.DEFAULT_SIZE, int)
            


            for i in range(0, self.size):
                elements2[i] = self.elements[i]



            elements2[self.size-1] = x

            self.elements = elements2
            


    
    def addInIndex(self, x, index):
        self.size = self.size + 1


        if self.DEFAULT_SIZE > self.size:

            elements2 = np.empty(self.DEFAULT_SIZE, int)

            for i in range(0, index):
                elements2[i] = self.elements[i]


            elements2[index] = x


            for i in range(index+1, self.size):
                elements2[i] = self.elements[i]

            self.elements = elements2


        else:
            self.DEFAULT_SIZE = self.DEFAULT_SIZE*2

            elements2 = np.empty(self.DEFAULT_SIZE, int)

            for i in range(0, index):
                elements2[i] = self.elements[i]

            elements2[index] = x

            for i in range(index+1, self.size):
                elements2[i] = self.elements[i]

            self.elements = elements2


    def incrementDS(self):
        self.DEFAULT_SIZE = self.DEFAULT_SIZE*2
 


    def toString(self):
        return self.elements


    def getValue(self, index):

        for 


         
    
element = ArrayList()

element.add(2)
element.add(3)
element.add(4)
element.add(5)
element.addInIndex(100, 2)

print(element.toString())





























