#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

template <class T> string toStr(const T &x)
{ stringstream s; s << x; return s.str(); }
template <class T> double toDouble(const T &x)
{double r; return atof(x.c_str()); }



/**
*       class Table
*       brief Representation of data as matrice, these already discretized or to be it.
*       
*       details It stores the attributes that are going to be present on the data set,
*               the mentioned as a vector and the corresponding data on a matrices made
*               with vector data structure, as well another attribute will store every
*               category present on each column of the matrice.
*     
**/

class Table{
    public:
        vector<string> attribs;
        vector<vector<string>> data;

        vector<vector<string>> attribValueList;
/**
*@brief Acquires categories of each column present on the data set.
*@return Void
*
*/
    void attribValues(){
        attribValueList.resize(attribs.size());
        for(int i = 0; i < attribs.size(); i++){
            map<string, int> value;

            for(int j = 0; j < data.size(); j++) value[data[i][j]] = 1;
            for(map<string, int>::iterator it = value.begin(); it != value.end(); it++) attribValueList[i].push_back(it->first);

        }

    }

    void readData(string);
    void discretizeData(vector<vector<double>>);

};


/**
* A structure to represent each node of the DesicionTree.
*
**/
struct Node{

        /*@{*/
        string question; /**<question*/
        bool isLeaf; /**<If true labels the data already*/
        string label; /**<Label*/ 
        Node *left; /**<Left node*/
        Node *right; /**<Right node*/
};



/**
*       class DecisionTree
*       brief Desicion Tree to label the data
*       
*       details It has a table that is going to be partitioned as the nodes from the root grow.
*/
class DecisionTree{

    public:
        Table table;
        Node *root;

};


/**
*@brief Counts the amount of labels, amount of yes and no 's on the table given.
*@param[table] Table to be analized.
*@return Vector with amount of yes on the first column and no on the sencond column.
**/
vector<int> classCounts(Table table){

    int r = table.data.size();

    int yesCount = 0;

    for(int i = 0; i < r; i++){

        yesCount += table.data[i][table.attribs.size()-1] == "y" ? 1 : 0;
    }

    vector<int> counts;

    counts.push_back(yesCount);

    counts.push_back(r-yesCount);

    return counts;

}

/**
*@brief Calcules the gini impurity of a table
*@param[table] Given table.
*@return The gini impurity of the table.
**/
int gini(Table table){

    vector<int> counts = classCounts(table);
    int impurity = 1;

    for(int i = 0; i < counts.size(); i++){

        int probLabel = counts[i]/table.data.size();
        impurity -= pow(probLabel,2);

    }

    return impurity;

}


/**
*@brief Discretized data as intervals to put them on the table given continuous data.
*@param[dataMatrice] recieves a matrice made of vectors with continuous.
@return Void.
**/
void Table::discretizeData(vector<vector<double>> dataMatrice){





}

/**
*@brief Reads the data present on a data file and discretized the data to put them on the table.
*@param[fileName] File to be analized, this has to have only continous data.
*@return Void.
**/
void Table::readData(string fileName){

    vector<vector<double>> dataMatrice;

    ifstream fin;

    fin.open(fileName, ios::in);

    string temp;        

    for(int i = 0; i < 6; i++){

        getline(fin,temp,',');

        attribs.push_back(temp);    


    }

    getline(fin, temp, '\n');

    attribs.push_back(temp);

    while(fin.good()){

        vector<double> data;

        for(int j = 0; j < 6; j++){

            getline(fin, temp, ',');

            if(temp=="") break;

            data.push_back(toDouble(temp)); 
        }

        if(temp=="") break;

        getline(fin, temp, '\n');



        data.push_back(temp[0] == 'y'  ? 1 : 0);
        

        dataMatrice.push_back(data);

         
    }

    discretizeData(dataMatrice);
}


/**
*@brief Mesures the time to read the data of the table data structure as continous.
*@param[fileName] Given file.
*@return Void.
**/
void mesureTimeCreation(string fileName){
    
    double min = 10000000;
    double max = 0;
    double r = 0;

    for(int i = 0; i < 100; i++){
        Table t;
        chrono::time_point<std::chrono::system_clock> start, end;
        start = chrono::system_clock::now();
        t.readData(fileName);
        end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        time_t end_time = std::chrono::system_clock::to_time_t(end);
        
        if(elapsed_seconds.count() < min) min = elapsed_seconds.count();

        if(elapsed_seconds.count() > max) max = elapsed_seconds.count();

        r += elapsed_seconds.count();
    }

        cout <<  "Creation with " << fileName << " => " << r/(double)100 << endl;
        cout << "Min => " << min << endl;
        cout << "Max => " << max << endl;
}


int main(){
    Table t;

    mesureTimeCreation("300.csv");
    mesureTimeCreation("373.csv");
    mesureTimeCreation("457.csv");
    mesureTimeCreation("673.csv");
    

    }
