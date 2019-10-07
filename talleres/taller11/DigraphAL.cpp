#include "DigraphAL.hpp"
#include <vector>
using namespace std;

void DigraphAL::addArc(int source, int destination, int weigth){
    Point p;

    p.x = destination;
    p.y = weigth;
    

    list[source][destination] = p;

}



vector<int> DigraphAL::getSuccessors(int v){


    vector<int> s;

    for(int i = 0; i < list[v].size(); i++){
        s.push_back(list[v][i].x);

    }

    return s;    
}



int DigraphAL::getWeigth(int source, int destination){

    return list[source][destination].y;
}
