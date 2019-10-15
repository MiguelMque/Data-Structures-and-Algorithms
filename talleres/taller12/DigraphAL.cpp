#include "DigraphAL.hpp"
#include <vector>
#include <list>
using namespace std;

void DigraphAL::addArc(int source, int destination, int weigth){
    

    Point p;
    p.x = destination;
    p.y = weigth;
    

    l[source].push_back(p);

}



vector<int> DigraphAL::getSuccessors(int v){

    vector<int> s;

    for(list<Point>::iterator it = l[v].begin(); it != l[v].end(); it++) s.push_back((*it).x);

    return s;
    
}



int DigraphAL::getWeigth(int source, int destination){

    
    for(list<Point>::iterator it = l[source].begin(); it != l[source].end(); it++){

        if((*it).x == destination) return (*it).y;

    }

    return 0;
}


void DigraphAL::DFS_helper(vector<bool> *v, int x){
    (*v)[x] = true;

    cout << x << " ";

    for(list<Point>::iterator it = l[x].begin();  it != l[x].end();it++){

        if(!(*v)[(*it).x]){
            (*v)[(*it).x] = true;

            DFS_helper(v, (*it).x);

        }

    }
    

}



void DigraphAL::DFS(int x){
    vector<bool> v(size, false);
    DFS_helper(&v, x);
    


}


void DigraphAL::BFS(int s){
    vector<bool> v(size,false);
    vector<int> queue;

    v[s] = true;
    queue.push_back(s);

    int vi;

    while(!queue.empty()){

        vi = queue[0];

        cout << vi << " ";

        queue.erase(queue.begin());

        for(list<Point>::iterator it = l[vi].begin();  it != l[vi].end();it++){

            if(!v[(*it).x]){
                v[(*it).x] = true;
                queue.push_back((*it).x);
            
            }

        }


    }       

}



int main(){



    DigraphAL g(4);
    
    g.addArc(0, 1, 1); 
    g.addArc(0, 2, 1); 
    g.addArc(1, 2, 1); 
    g.addArc(2, 0, 1); 
    g.addArc(2, 3, 1); 
    g.addArc(3, 3, 1); 
  

    g.DFS(2);
}
