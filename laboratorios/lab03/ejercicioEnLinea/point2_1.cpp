#include <iostream>
#include <list>
using namespace std;

void point1(string str){

	list<char> myList;
	bool start = 0;
	myList.erase(myList.begin(), myList.end());
	list<char>::iterator it = myList.begin();

	for(char& c : str){

		if(c == '['){
			it = myList.begin();
		       	start = 1;
		}

		else if (c == ']') start = 0;

		else {
			if(start){
				myList.insert(it, c);
			} else {
				myList.push_back(c);
			}
		}
	}

	for(it = myList.begin(); it!=myList.end(); ++it){
		cout << *it;

	}

	cout << endl;

}

int main(){
	
	string x;

	while(cin >> x){


	point1(x);


	}

}
