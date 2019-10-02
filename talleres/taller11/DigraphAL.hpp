#include "Digraph.hpp"
#include <vector>



class DigraphAL: public Digraph{

    public:
        vector<vector<Point>> list;
        void addArc(int, int, int);
        vector<int> getSuccessors(int);
        int getWeigth(int, int);

};
