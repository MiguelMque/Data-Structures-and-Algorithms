#include <iostream>
using namespace std;

void merge(int L[], int R[], int arr[], int nL, int nR){

	int i = 0, j = 0, k = 0;

	while( i < nL && j < nR ){
		
		if(L[i] < R[j]){
			arr[k] = L[i];
			i++;
		} else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}


	while(i < nL){
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < nR){
		arr[k] = R[j];
		j++;
		k++;
	}

}


void mergeSort(int arr[], int n){	
	
	if(n < 2) return;

	int mid = n/2;

	int L[mid];
	int R[n-mid];

	for(int i = 0; i < mid-1; i++){
	       
		L[i] = arr[i];
	
		cout << "Metiendo elemento " << arr[i]; "en L[i] de tamaño " << mid;
	
	}

	for(int i = mid-1; i < n-1; i++){       
	
	
		R[i] = arr[i];
		cout << "Metiendo elemento " << arr[i]; "en R[i] de tamaño " << n-mid;
	
	
	
	}
	
	

	mergeSort(L, mid;
	mergeSort(R, n-mid);
	merge(L, R,  arr, mid, n-mid);


}






int main(){


	int arr[] = {500,600,33,45,45,70,100};

	cout << sizeof(arr)/sizeof(arr[0]) << endl;
	
		
	mergeSort(arr, 7);


	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]) ; i++){
	
		cout << arr[i] << endl;



	}



}
