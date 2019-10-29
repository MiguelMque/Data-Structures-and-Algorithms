#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "DataFrame.hpp"

using namespace std;


struct Node{
	vector<Node *> child;
	string attrib;
	double p;

};


class BQPT{

public:	
	Node *root;
	BQPT(string);
	double** quartile;
	
	Node *newNode(string);
	Node *newNode(double);	
	void make(DataFrame);
	int whichDiscrete(double, int);
	double decision(string);


};

