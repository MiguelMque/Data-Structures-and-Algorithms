"""
@author Miguel Angel Correa Manrique - Pablo Buitrago Jaramillo
Taller09 Estructura datos y algorítmos
"""
#EXERCISE 1 v1
directory = dict()

def addPhoneContact(name, phoneNumber):
    directory[name] = phoneNumber

def getPhoneContact(name):
    try:
        if 'name' in directory:
            print(name+': '+directory[name])
    except:
        print(name+ 'is not a contact')
    
#EXERCISE 1 v2
def phoneContact():
    directory = dict()
    keyIn = ""
    print("add your contacts in the directory. Type \"yes\" to finish")
    while keyIn != "yes":
        directory[input("Contact Name: ",)] = input("Contact Phone Number: ",)
        keyIn = input("Are you Done?",)
    print(directory.items())

#EXERCISE 2
def companys():
    company = dict()
    keyIn = ""
    print("add the companys with their respective countries. Tipe \"yes\" to finish")
    while keyIn != "yes":
        directory[input("Company Name: ",)] = input("Company country: ",)
        keyIn = input("Are you Done?",)
    print(company.items())


