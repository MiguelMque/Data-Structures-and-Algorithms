#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;


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


int main(){

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
	
}
