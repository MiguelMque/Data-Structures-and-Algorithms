#include<bits/stdc++.h>
/**
* @file point1
* @version 1.0
* @author Miguel Ángel Correa Manrique && Pablo Buitrago
* @title Point 1
*/

using namespace std;

#define D(x) cout << "DEBUG: " << #x " = " << x << endl
#define fore(i,a,b) for(int i = a;i<b;++i)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double PI = acos(-1.0);
template <class T> string toStr(const T &x){stringstream s;s<<x;return s.str();}

template <class T> int toInt(const T &x){stringstream s;s<<x;int r;s>>r;return r;}

/**
* A struct to represent a File
*/
struct File{
    /*@{*/
    double w;/**<the weigth of the file */
    string name;/**<the name of the file*/      
    /*@}*/

};

/**
* class Directory
* brief Implementation of a directory 
* 
* details This implementation of directory has different attributes such as which files it contains and other directories as Map Tables, also each directoy
*       has a name and a weigth.
*/
class Directory{

    public:

        map<string, vector<File>> files;
        map<string, Directory> directories;
        string name;
        string owner;
        double w;


/**
* @brief It splits a route into a vector of strings every '/' character
* @param[d] The given route
* @return Vector of strings of the given route
*/
vector<string> splitDirectory(string d){
    
            vector<string> splited;

            string temp = "";

            for(int i = 0; i < d.size(); i++){
    
                if(d[i] == '/'){
                    splited.push_back(temp);
                    temp =    "";
                }

                else temp.push_back(d[i]);

            }

                return splited;
        }


/**
* @brief It finds the directory given the route
* @param[d] The given route
* @return Directory
*/
        Directory findDirectory(string d){

            vector<string> input = splitDirectory(d);

            Directory tempD;

            if(name != input[0]){

                cout << "No such file or directory" << endl;

                return tempD;
            }
            
            tempD.name = name;
            tempD.directories = directories;
            tempD.files = files;
            tempD.w = w;

            if(input.size() == 1) return tempD;



           for(int i = 1; i < input.size(); i++){
                tempD = tempD.directories[input[i]]; 

                if(tempD.name == ""){
                cout << "No such file or directory" << endl;
                return tempD;

                }

            }

            return tempD;

        }

        
/**
* @brief Given a directory route it prints out all the directories and files on that directory route
* @param[d] The given route
* @return Void
*/
    void query1(string d){
            
        Directory tempDirectory = findDirectory(d);


        if(tempDirectory.name == "") return; 
        
        map<string, Directory> myDirectory = tempDirectory.directories;
        map<string, vector<File>> myFiles = tempDirectory.files;

        
        for(map<string, Directory>::iterator it = myDirectory.begin(); it!=myDirectory.end(); it++) cout << it->first << endl;
    
        for(map<string, vector<File>>::iterator it = myFiles.begin(); it != myFiles.end(); it++)
              for(int i = 0; i < (it->second).size(); i++) cout << (it->second)[i].name << endl; 

    }

/**
* @brief Helper method to print out all the files in certein directory that belongs to a given user.
* @param[user] Given user.
* @param[tempD] Given directory.
* @return Void
*/
    void printFilesUser(string user, Directory tempD){

        vector<File> myFiles = tempD.files[user];

        for(int i = 0; i < myFiles.size(); i++) cout << myFiles[i].name << endl;


    }

/**
* @brief Helper method to print out all the directories and files that belongs to a given user, it searchs recursively into every directory found
* @param[user] Given user
* @param[tempD] Given directory
* @return Void
*/ 
    void printDirectoriesUser(string user, Directory tempD){

        if(tempD.name == "") return;

        map<string, Directory> myDirectories = tempD.directories;
        
        printFilesUser(user, tempD);
        
        for(map<string, Directory>::iterator it = myDirectories.begin(); it != myDirectories.end(); it++){

            if((it->second).owner == user) cout << (it->second).name << endl;

            if((it->second).directories.size() > 0) printDirectoriesUser(user, it->second);            

        }

    }

/**
* @brief Helper method to print out all the files in certein directory that are greater than a weigth given
* @param[tempD] Given directory
* @param[wg] Given weigth
* @return Void
*/
    void printFilesWeigth(Directory tempD, double wg){

        map<string, vector<File>> myFiles = tempD.files;
        
            for(map<string, vector<File>>::iterator it = myFiles.begin(); it != myFiles.end(); it++)
                fore(i, 0, (it->second).size()) if((it->second)[i].w > wg) cout << (it->second)[i].name << endl;

    }

/**
* @brief Helper method to print out all the directories and files that are greater than a weigth given, it searchs recursively into every directory found
* @param[tempD] Given directory
* @param[wg] Given weigth
* @return Void
*/
    void printDirectoriesWeigth(Directory tempD, double wg){

        if(tempD.name == "") return;

        map<string, Directory> myDirectories = tempD.directories;

        printFilesWeigth(tempD, wg);


        for(map<string, Directory>::iterator it = myDirectories.begin(); it != myDirectories.end(); it++){


            if((it->second).w > wg) cout << (it->second).name << endl;
    
            if((it->second).directories.size() > 0) printDirectoriesWeigth(it->second, wg);


        }

    }

/*
* @brief Given a route and a user it prints out all the directories and files that belongs to the respective user.
* @param[d] Given route
* @param[user] Given user
* @return Void
*/
    void query2(string d, string user){

        Directory tempD = findDirectory(d);
    
        printDirectoriesUser(user, tempD);

    }

/*
* @brief Given a route and a weigth it prints out all the directories and files are greater than the weigth given.
* @param[d] Given route
* @param[wg] Given weigth
* @return Void
*/
    void query3(string d, double wg){

        Directory tempD = findDirectory(d);
        
        printDirectoriesWeigth(tempD, wg);

    }

        

};


int main(){

    File file1;
    file1.w = 46;
    file1.name = "file1.txt";

    File file2;
    file2.w = 40;
    file2.name = "file2.txt";

    File file3;
    file3.w = 46;
    file3.name = "file3.txt";
    
    File file4;
    file4.w = 40;
    file4.name = "file4.txt";

    Directory main;
    main.name = "main";
    main.w = 60;
    
    Directory calculus;
    calculus.name = "calculus";
    calculus.w = 60;
    calculus.owner = "miguel";
    calculus.files["miguel"] = {file1, file2};
    
    Directory integrals;
    integrals.name = "integrals";
    integrals.w = 46;
    integrals.owner = "pablo";
    integrals.files["pablo"] = {file3, file4};

    calculus.directories["integrals"] = integrals;
    
    main.directories["calculus"] = calculus;

    cout << "*********QUERY 1*********" << endl;
    main.query1("main/calculus/");
    cout << endl << endl;

    cout << "*********QUERY 2*********" << endl;
    main.query2("main/", "pablo");
    cout << endl << endl;

    cout << "*********QUERY 3*********" << endl;
    main.query3("main/", 0);
    cout << endl << endl;
    
}








