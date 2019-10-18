#include <iostream>
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


void DigraphAM::DFS(vector<bool> *v, int x){
    (*v)[x] = true;


    cout << x << " ";
    
    for(int i = 0; i < size; i++){

        if(matrix[x][i] != 0 && (!(*v)[i])){
                (*v)[i] = true;

                
                DFS(v, i);
            }


    }


}

void DigraphAM::DFS_helper(int x){
    vector<bool> v(size, false);
    

    DFS(&v, x);

}


void DigraphAM::BFS(int x){

    
    vector<bool> v(size, false);
    vector<int> queue;
    
    queue.push_back(x);

    v[x] = true;


    int vi;

    while(!queue.empty()){

        vi = queue[0];


        cout << vi << " ";
        queue.erase(queue.begin());


        for(int i = 0; i < size; i++){

            if(matrix[vi][i] != 0 && (!v[i])){

                queue.push_back(i);

                v[i] = true;


            }


        }

    }

}


int main(){

    DigraphAM d(4);

    d.addArc(0,1,1);
    d.addArc(0,2,1);
    d.addArc(1,3,1);

    d.BFS(0);

    cout << endl;

    d.DFS_helper(0);





}


