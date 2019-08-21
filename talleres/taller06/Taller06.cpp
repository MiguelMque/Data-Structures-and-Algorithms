#include <iostream>
#include <cstdlib>

using namespace std;

// #1
class ArrayList{	
	public:
		int DEFAULT_SIZE = 4;
		int size;
		int *arr;


		void Init(){
			size = 0;
			arr = new int[DEFAULT_SIZE];
		}


		void add(int x){	
			size += 1;	
		
			if(size >= DEFAULT_SIZE){

				DEFAULT_SIZE = DEFAULT_SIZE*2;

				int *arr2; //Why doesn't work with arr2[DEFAULT_SIZE]

				arr2 = new int[DEFAULT_SIZE];
				
				for(int i = 0; i < size; i++) arr2[i] = arr[i];

				arr2[size-1] = x;

				arr = arr2;
	
			} else arr[size-1] = x;

		}


		void addInIndex(int x, int index){

			size += 1;

			if(size >= DEFAULT_SIZE){
				DEFAULT_SIZE = DEFAULT_SIZE*2;

				int *arr2;

				arr2 = new int[DEFAULT_SIZE];

				int i; 

				for(i = 0; i < index; i++) arr2[i] = arr[i];

				arr2[index] = x;

				for(i = index; i < size; i++) arr2[i+1] = arr[i];

				arr = arr2;	

			} else {
			   	//Since there's no new size, no second array needed, elements are moved one place and then index is added to the array.
				for(int i = size; i >= index; i--) arr[i] = arr[i-1];
			
				arr[index] = x;
			}
		}


		void del(int index){
			size -= 1;		
			
			arr[size+1] = 0;

			int temp;

			for(int i = index; i <= size;i ++)  arr[i] = arr[i+1];
				
		}


		void print(){

			cout << "[ ";

			for(int i = 0; i < size; i++) cout << arr[i] << " ";
			

			cout << "]" << endl;	

		}



		//Optional #2 addReverse Algorithm
		void addReverse(int x){
			size += 1;


			if(size < DEFAULT_SIZE) arr[DEFAULT_SIZE-size] = x;

			else {

				DEFAULT_SIZE = DEFAULT_SIZE*2;

				int *arr2;

				arr2 = new int[DEFAULT_SIZE];
			
				arr2[DEFAULT_SIZE-size] = x;

				for(int i = 1; i < DEFAULT_SIZE/2; i++) arr2[DEFAULT_SIZE-size+i] = arr[i];

				arr = arr2;

			}

			
		}

		


		void printReversed(){

			cout << "[ ";

                        for(int i = DEFAULT_SIZE-size; i < DEFAULT_SIZE ; i++)  cout << arr[i] << " ";
                        

                        cout << "]" << endl;

		}

};



//Optional #2 Reader
void readArray(ArrayList myArray){
	int x;
	while(true){


		cout << "Put integer value: ";

		cin >> x;
	

		if(x==-1) break;

		myArray.addReverse(x);
	}

	myArray.printReversed();




}


int main(){

	ArrayList myArray;
	myArray.Init();



	readArray(myArray);






}
