#include "Digraph.hpp"
#include <list>
#include <vector>


class DigraphAL: public Digraph{

    public:
    
        list<Point> *l;

        DigraphAL(int s){

            size = s;
            l = new list<Point>[size];

        }
        void DFS_helper(vector<bool>*, int);
        void DFS(int);
        void BFS(int);
        void addArc(int, int, int);
        vector<int> getSuccessors(int);
        int getWeigth(int, int);

};
