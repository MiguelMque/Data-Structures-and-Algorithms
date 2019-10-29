#include  <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

template <class T> double toDouble(const T &x) {double r; return atof(x.c_str()); }

class DataFrame{

public:
	vector<string> label;
	vector<vector<double>> data;
	void loadFileCSV(string);
	void concat(vector<DataFrame>);
	void merge(vector<double>*, vector<double>*, vector<double>*);
	void mergeSort(vector<double>*);
	double* quartile(vector<double>);
	double** discretize();

};

