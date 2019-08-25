#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;




int polishNotationCalculator(string str){

	stack <int> n;
	bool wasN;
	string num = "";

	for(int i = 0; i < str.size(); i++){


		 if(str.at(i) == ' ' && wasN){
                        stringstream g(num);
                        int value;
                        g >> value;
                        n.push(value);
                        num = "";
                        wasN = false;
                } else if (isdigit(str.at(i))) {
                        
                        wasN = true;
                        num += str.at(i);
                
                } else if (str.at(i)!=' '){
		 		int r = 0;
                                int b = n.top();
                                n.pop();
                                int a = n.top();
                                n.pop();

                	switch(str.at(i)){

				case '*':
					r = a*b;
					n.push(r);
					break;

				case '+':
					r = a+b;
					n.push(r);
					break;

				case '-':
					r = a-b;
					n.push(r);
					break;
					
				case '/':
					r = a/b;
					n.push(r);
					break;

			}
                
                }



	}

		


	return n.top();

}




class Fridge{

	int code;
	string descrip;

	public:
		void setCode(int c){
		       	code = c; 
		}
		int getCode(){
		       	return code; 
		}

		void setDescrip(string d){
			descrip = d;
		}

		string getDescrip(){

			return descrip;
		}

};




class Store{

	queue <Fridge> fridgeList;

	string name;

	int soli;

	public:
		void setName(string n){
			name = n;
		}

		string getName() {
			return name;
		}

		void addFridge(Fridge f){
			fridgeList.push(f);
			
		}

		queue<Fridge> getFridgeList(){

			return fridgeList;
		}

		void popFridge(){
			fridgeList.pop();

		}

		void setSoli(int s){
			soli = s;
		}

		int getSoli(){

			return soli;
		}

};

void printListStores(vector <Store> solicitudList){

        for(int i = 0; i < solicitudList.size(); i++){

        cout << "For store " << solicitudList[i].getName() << endl;

        if(solicitudList[i].getSoli() == solicitudList[i].getFridgeList().size()) cout << "Supplies satisfied: " << solicitudList[i].getFridgeList().size() << " of " << solicitudList[i].getFridgeList().size() << endl;

        else cout << "Warehouse out of fridges, we could get just: " << solicitudList[i].getFridgeList().size() << " of " << solicitudList[i].getSoli() << endl;

        }

}


void point2(vector <Store> solicitudList, Store warehouse){
	Store temp;
	Fridge f;

	queue<Fridge> wareFridges;

	warehouse.setName("Almacen");

	int size = warehouse.getFridgeList().size();
	
	int size2 = solicitudList.size();

	for(int i = 0; i < size2 && size!= 0; i++){

		temp = solicitudList[i];

		for(int j = 0; j < temp.getSoli() && size!= 0; j++){
			f = warehouse.getFridgeList().front();

			solicitudList[i].addFridge(f);
			
			warehouse.popFridge();

			size--;
		}

	}
	printListStores(solicitudList);


}



//Recursive method to reverse a stack

stack <int> reverseStackHelper(stack<int>s, stack <int> s2){

	if(s.empty()){
	return s2;
	}

	int a = s.top();
	s.pop();
	s2.push(a);

		
	return reverseStackHelper(s, s2);

}


stack <int> reverseStack(stack <int> s){
        stack<int> s2;

        return reverseStackHelper(s, s2);

}





//Optional #4
void service(queue <string> list){
	cout << "Service method" << endl;

	while(!list.empty()){
		cout << "Serving " << list.front() << endl;
		list.pop();
	}




}


int main(){

	cout << "POLISH CALCULATOR" << endl;
	cout << "Result of 6 5 - 4 + = " << polishNotationCalculator("6 5 - 4 +") << endl << endl; 


	vector <Store> solicitudList;
	Store warehouse;

	Fridge f;

	for(int i = 0; i <= 10; i++){
		
		f.setCode(i);

		f.setDescrip((to_string(i)));

		warehouse.addFridge(f);

	}


	Store eafit;

	eafit.setName("EAFIT");

	eafit.setSoli(10);

	solicitudList.push_back(eafit);

	Store eafit2;

	eafit2.setName("EAFIT2");

	eafit2.setSoli(2);

	solicitudList.push_back(eafit2);

	point2(solicitudList, warehouse);
	
	cout << endl << endl;
		

	stack <int> s;

	for(int i = 0; i <= 9; i++){

		s.push(i);



	}

	cout << "Original stack" << endl;

	stack <int> s2 = s;

	while(!s2.empty()){

        cout << s2.top();
        s2.pop();


        }

	cout << endl;
       s =  reverseStack(s);
	
      	cout << "Reverse stack" << endl;

	while(!s.empty()){

	cout << s.top();
	s.pop();


	}

	cout << endl << endl;


	queue <string> friends;

	friends.push("Pablo");
	friends.push("Jesús");
	friends.push("David");

	service(friends);


	return 0;

}
