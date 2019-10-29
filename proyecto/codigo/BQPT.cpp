#include "BQPT.hpp"

BQPT::BQPT(string name){
	root = newNode(name); 

}

Node* BQPT::newNode(double prob){
	Node *temp = new Node;
	temp->p = prob;

	return temp;
}
Node* BQPT::newNode(string at){
	Node *temp = new Node;
	temp->attrib = at;
	return temp;
}
void BQPT::make(DataFrame dataFrame){

	quartile = dataFrame.discretize();
	
	for(int i = 0; i < dataFrame.data[0].size()-1; i++){

		(root->child).push_back(newNode(dataFrame.label[i]));			

		double probs[4] = {0};
		int count[4] = {0};

		for(int j = 0; j < dataFrame.data.size(); j++){
			if(dataFrame.data[j][i] == 0){
				count[0] += 1;
				probs[0] = dataFrame.data[j][dataFrame.data[0].size()-1] == 1 ? probs[0] + 1 : probs[0];

			}
			else if(dataFrame.data[j][i] == 1){
				count[1] += 1;	
				probs[1] = dataFrame.data[j][dataFrame.data[0].size()-1] == 1 ? probs[1] + 1 : probs[1];

			}
			else if(dataFrame.data[j][i] == 2){
				count[2] += 1;
				probs[2] = dataFrame.data[j][dataFrame.data[0].size()-1] == 1 ? probs[2] + 1 : probs[2];

			}
			else{
				count[3] += 1;
				probs[3] = dataFrame.data[j][dataFrame.data[0].size()-1] == 1 ? probs[3] + 1 : probs[3];

			}
		}
		for(int j = 0; j < 4; j++){



			probs[j] = count[j] == 0 ? 0 : probs[j]/(double)(count[j]);


			root->child[i]->child.push_back(newNode(probs[j]));

		}


	}

}

int BQPT::whichDiscrete(double x, int column){

	if(x <= quartile[column][0]) return 0;
	else if(x <= quartile[column][1]) return 1;
	else if(x <= quartile[column][2]) return 2;
	else return 3;

}


double BQPT::decision(string fileName){

	DataFrame dataFrame;
	dataFrame.loadFileCSV(fileName);

	int comp = 0;

	for(int i = 0; i < dataFrame.data.size(); i++){

		int prediction = 0;
		int trainLabel;
		int label;


		for(int j = 0; j < dataFrame.data[0].size()-1; j++){

			double ran = ((double)rand() / RAND_MAX);

			int q = whichDiscrete(dataFrame.data[i][j], j);
	
			if(ran <= (root->child[j]->child[q]->p)) prediction = prediction + 1;

		}


		trainLabel = dataFrame.data[i][dataFrame.data[0].size()-1];

		//		if(trainLabel == 1) 
		//			cout << "EXPECTED: YES" << endl;
		//		else 
		//			cout << "EXPECTED: NO " << endl;

		if((root->child).size() % 2 == 0 && prediction == (root->child).size()/2){
			double ran = ((double)rand() / RAND_MAX);
			if(ran <= 0.5){
				label = 1;
				//				cout << "PREDICTION: YES" << endl;
			} else {
				//				cout << "PREDICTION: NO" << endl;
				label = 0;
			}
		} else {

			if(prediction/(double)(root->child.size()) >= 0.6 ){
				//				cout << "PREDICTION: YES" << endl;
				label = 1;

			} else{
				//				cout << "PREDICTION: NO" << endl;
				label = 0;

			}
		}
		if(label == trainLabel) comp++;
	}

	return (((double)(comp)/dataFrame.data.size()))*100;
}

