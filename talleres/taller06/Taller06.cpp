#include <iostream>
#include <cstdlib>
#include <string>

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

		//The asymptotic complexity for this method is O(n), so using this algorithm on a text editor is not the most suitable option. The asymptotyc 
   		// complexcity to add n characters is O(n^n)
		void add(int x){	
			size += 1;	
		
			if(size >= DEFAULT_SIZE){

				DEFAULT_SIZE = DEFAULT_SIZE*2;

				int *arr2; //Why doesn't work with arr2[DEFAULT_SIZE] (?)

				arr2 = new int[DEFAULT_SIZE];
				
				for(int i = 0; i < size; i++) arr2[i] = arr[i];

				arr2[size-1] = x;

				arr = arr2;
	
			} else arr[size-1] = x;

		}

		//The asymptotic complexity for this method is O(n^2), so using this algorithm on a text editor is not the most suitable option. The asymptotyc 
   		// complexcity to add n characters is O(n^n)
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


		int get(int i){

		return arr[i];

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



class ArrayListString{
	public:
		int DEFAULT_SIZE = 4;
                int size;
                string *arr;


	void Init(){

		size = 0;
		arr = new string[DEFAULT_SIZE];


	}


       	void add(string x){
        	size += 1;

                if(size >= DEFAULT_SIZE){

                	 DEFAULT_SIZE = DEFAULT_SIZE*2;

                         string *arr2; 

                         arr2 = new string[DEFAULT_SIZE];

                         for(int i = 0; i < size; i++) arr2[i] = arr[i];

                         	arr2[size-1] = x;

                                arr = arr2;

                        } else arr[size-1] = x;

                }


	void print(){
	
                        cout << "[ ";

                        for(int i = 0; i < size; i++) cout << arr[i] << "       ";

                        cout << "]" << endl;

	
	}
	



};




//Optional #3 Sequence
void sequence(int n){
	ArrayListString myArray;
	myArray.Init();

	string str;


	for(int i = 1; i <= n; i++){
		str = "";
		for(int j = 1; j<=i; j++){
				
			 str+= to_string(j) + ", ";

		}
		
	myArray.add(str);

	}

	myArray.print();	

}


int main(){


}
