#include "Digraph.hpp"
#include <vector>

class DigraphAM: public Digraph{
    public:
        int** matrix;

        int getWeigth(int, int);
        void addArc(int,int,int);
        vector<int> getSuccessors(int);
};
