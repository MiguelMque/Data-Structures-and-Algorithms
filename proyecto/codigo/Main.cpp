#include "BQPT.hpp"
#include <chrono>

void mesureTimeCreation(string fileName){

	double minAcu = 100;
	double maxAcu = 0;
	double min = 10000000;
	double max = 0;
	double r = 0;
	double rAcu = 0;
	double acu = 0;

	DataFrame t;
	t.loadFileCSV("train.csv");
	BQPT tree("roya");
	for(int i = 0; i < 1000; i++){

		chrono::time_point<std::chrono::system_clock> start, end;
		start = chrono::system_clock::now();
		tree.make(t);
		acu = tree.decision(fileName);
		end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end-start;
		time_t end_time = std::chrono::system_clock::to_time_t(end);

		if(acu < minAcu) minAcu = acu;

		if(acu > maxAcu) maxAcu = acu;

		if(elapsed_seconds.count() < min) min = elapsed_seconds.count();

		if(elapsed_seconds.count() > max) max = elapsed_seconds.count();

		r += elapsed_seconds.count();
		rAcu += acu;
	}

	cout << "******" << fileName << "******" << endl;
	cout << "Average Time: " << r/(double)1000 << endl;
	cout << "Min Time: " << min << endl;
	cout << "Max Time: " << max << endl;
	cout << "Average ACURRACY: " << rAcu/1000 << endl;
	cout << "Min ACURRACY: " << minAcu << endl;
	cout << "Max ACCURRACY: " << maxAcu << endl;
}


int main(){
	srand(time(NULL));

	mesureTimeCreation("300.csv");
	mesureTimeCreation("373.csv");
	mesureTimeCreation("457.csv");
	mesureTimeCreation("673.csv");
}
