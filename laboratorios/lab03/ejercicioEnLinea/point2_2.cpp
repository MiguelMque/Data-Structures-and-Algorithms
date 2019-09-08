#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

void printStackList(list<stack<int>> myList){


	list<stack<int>>::iterator it;

	for(it=myList.begin(); it!=myList.end(); ++it){
		int q = -1;

		while(!(*it).empty()){
		       	cout << (*it).top();
			
			q = (*it).top();

			(*it).pop();
		}

		 if(!(q==-1)) cout << endl;

	}
	


}


//goingTo variable indicates if its a or b.
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

void moveOnto(list<stack<int>> *myList, int *pos, int a, int b){

	list<stack<int>>::iterator it = (*myList).begin();
	
	for(int i = 0; i < pos[a]; i++) it++;

	(*it).pop();

	it = (*myList).begin();

	for(int i = 0; i < pos[b]; i++) it++;

	(*it).push(a);

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


		cout << "A: " << a << "B: " << b << "OPTION: " << option
			<< "COMMAND: " << command << endl;	

		if(command == "move" && option == "onto"){


			cleanAbove(&myList, pos, a);
			cleanAbove(&myList, pos, b);			
			moveOnto(&myList, pos, a, b);	

		}


	}

	
	printStackList(myList);
}
