#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;



class Robot{

	public:
		list<stack<int>> myList;

		Robot(int n){

			list<stack<int>> myList;

        		for(int i = 0; i < n; i++){
               			stack<int> st;
              			st.push(i);
                		myList.push_back(st);

		        }

		}


		void moveOnTo(int a, int b){
			

			


		}


		void moveOver(int a, int b){


		}


		void pileOnTo(int a, int b){


		}

		void pileOver(int a, int b){


		}

};




void printStackList(list<stack<int>> myList){


	list<stack<int>>::iterator it;

	for(it=myList.begin(); it!=myList.end(); ++it){

		while(!(*it).empty()){
		       	cout << (*it).top() << endl;
			(*it).pop();
		}

	}
	


}





void moveOnto(int a, int b){






}



int main(){



	
}
