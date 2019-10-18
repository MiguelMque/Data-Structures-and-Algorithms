#include <iostream>
#include "DigraphAM.hpp"
#include <vector>
using namespace std;

void DigraphAM::addArc(int source, int destination, int weigth){    
    n++;
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


bool DigraphAM::DFS(vector<int> *v, int x, int color){
    (*v)[x] = color;

    bool p = true;
    
    for(int i = 0; i < size; i++){

        if(matrix[x][i] != 0 &&  (*v)[i] != 1 && (*v)[i] != 2 ){

                (*v)[i] = color;

                if(color == 2) p = DFS(v,i, 1);

                else p = DFS(v,i,2);

            } else if(matrix[x][i] != 0 && (*v)[i] == 1  && color == 1) return false;

              else if(matrix[x][i] != 0 && (*v)[i] == 2 && color == 2) return false;
    }
    return p;
}

bool DigraphAM::DFS_helper(int x){
    vector<int> v(size, 0);
    

    return  DFS(&v, x, 1);

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

    int x;


    while(true){

        cin >> x;
        if(x == 0) break;
        int y;
        DigraphAM d(x);
        cin >> y;


         y +=1;
        while(--y){
            int a;
            int b;
            cin >> a >> b;
            d.addArc(a,b,1);

        }


     if(d.DFS_helper(0)) cout << "BICOLORABLE" << endl;

    else cout << "NOT BICOLORABLE" << endl;

    }


}


