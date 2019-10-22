"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo
Lab05 Estructura datos y algorítmos
"""
import urllib.request

class Graph:
    """This class contain the methods to save a city data using graphs"""
    def loadFile_txt_url(url):
        """This method reads a .txt file wich paths the given url"""
        response = urllib.request.urlopen(url)
        data = response.read()
        text = data.decode('utf-8')
        string = text[1]
        arr = []
        for i in range(1, len(text)):
            aux = ""
            while (text[i] != '\n'):
                if(text[i] != ' '):
                    aux += text[i]
                i+=1
            arr.append(aux)
        print(arr)
        print(text)

    def __init__(self):
        """Constructor method"""
        self.vertexList = dict()
        self.weightList = dict()
    
    def addVertex(ID, x, y, name):
        """This method adds a vertex to the structure given an ID, cordinate and name"""
        vertexList[ID] = (x, y, name)

    def addWeigth(IDo, IDf, length, name):
        """This method adds a weigth (street) to the structure given te initial and final vertex, length and name"""
        if IDo and IDf in vertexList:
            weigthList[name] = (IDo, IDf, length)
        else print('Vertex not found')

    

    

    loadFile_txt_url('https://github.com/mauriciotoro/ST0245-Eafit/blob/master/laboratorios/lab05/datasets/medellin_colombia-grande.zip')
    

