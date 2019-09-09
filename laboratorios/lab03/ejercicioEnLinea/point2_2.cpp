#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

void reverseVector(vector<int> *val){

	for(int i = 0; i < (*val).size()/2; i++){
		int j = (*val).size()-1-i;
		int temp = (*val)[i];
		(*val)[i] = (*val)[j];
		(*val)[j] = temp;


	}	
	
}


void printStacks(list<stack<int>> myList){


	list<stack<int>>::iterator it;
	vector<int> v;
	int index = 0;
	for(it=myList.begin(); it!=myList.end(); ++it){

		cout << index << ":";
		while(!(*it).empty()){
			v.push_back((*it).top());	
			(*it).pop();
		}

		for(int i = 0; i < v.size(); i++) cout << " " << v[i];

		v.clear();
		index++;	
		cout << endl;
	}
	


}

void cleanAbove(list<stack<int>> *myList, int *pos, int a){
	
	list<stack<int>>::iterator it;
	list<stack<int>>::iterator it2;

	it2 = (*myList).begin();
	it = (*myList).begin();
	
	//It goes until the stack where the value is
	for(int i = 0; i < pos[a]; i++)	it++;

	while((*it).top()!=a){

		int x = (*it).top();

		(*it).pop();

		pos[x] = x;

		for(int j = 0; j < x; j++) it2++;

		(*it2).push(x);
		
		it2 = ((*myList).begin());

	}
}

void putBlock(list<stack<int>> *myList, int *pos, int a, int b){
	
	list<stack<int>>::iterator it = (*myList).begin();
	
	for(int i = 0; i < pos[a]; i++) it++;

	(*it).pop();

	it = (*myList).begin();

	for(int i = 0; i < pos[b]; i++) it++;

	(*it).push(a);
	
	pos[a] = pos[b];

}


vector<int> reverseStack(stack<int> s){
	
	vector<int> v;

	while(!s.empty()){
		v.push_back(s.top());
		s.pop();
	}


	return v;

}

void pile(list<stack<int>> *myList, int *pos, int a, int b){

	list<stack<int>>::iterator it = (*myList).begin();

	vector<int> val;

	for(int i = 0; i < pos[a]; i++) it++;
	
	while(1){

		int x = (*it).top();
		
		//Changing blocks over a and block a to position b
		pos[x] = pos[b];

		(*it).pop();
		val.push_back(x);

		if(x == a) break;
	}

	reverseVector(&val);

	it = (*myList).begin();

	for(int i = 0; i < pos[b]; i++) it++;

	for(int i = 0; i < val.size(); i++) (*it).push(val[i]);


}





int main(){

	//Input variables
	int n;
	int a;
	int b;
	string command;
	string option;

	cin >> n;

	int pos[n];
		
	list<stack<int>> myList;

	//Creates the list of stacks and also stores the position of the blocks
		for(int i = 0; i < n; i++){
               		stack<int> st;
              		st.push(i);
			pos[i] = i;
                	myList.push_back(st);

		}



	while(cin >> command){

		if(command == "quit") break;

		cin >> a >> option >> b;

		if(a==b){

		} else if (command == "move" && option == "onto"){
			cleanAbove(&myList, pos, a);
			cleanAbove(&myList, pos, b);			
			putBlock(&myList, pos, a, b);	

		} else if (command == "move" && option == "over"){
			cleanAbove(&myList, pos, a);
			putBlock(&myList, pos, a, b);			

		} else if(command == "pile" && option == "onto"){
			cleanAbove(&myList, pos, b);
			pile(&myList, pos, a, b);

		} else if(command =="pile" && option == "over"){
			pile(&myList, pos, a, b);	
		}


	}

	printStacks(myList);

}
