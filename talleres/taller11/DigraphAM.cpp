#include "DigraphAM.hpp"
#include <vector>
using namespace std;

void DigraphAM::addArc(int source, int destination, int weigth){

    matrix[source][destination] = weigth;
}


vector<int> DigraphAM::getSuccessors(int v){

    vector<int> s;
    
    for(int i = 0; i < size; i++) 
        if(matrix[v][i] != 0) s.push_back(i);

    return s; 
}


int DigraphAM::getWeigth(int source, int destination){

    return matrix[source][destination];

}
