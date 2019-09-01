/**
 *@file point1
 *@version 1.3
 *@date 28/08/2019
 *@author Miguel Ángel Correa Manrique
 *@title Point 1
 */

#include <iostream>
#include <chrono>
using namespace std;

/**
 *@brief Arranges an array, given the array and its size.
 *@param[arr] Given array.
 *@param[n] Array length.
 *@return Void.
 * */
void insertionSort(int arr[], int n){
	for(int i = 0; i < n; i++){

		for(int j = i; j > 0 && arr[j-1] > arr[j]; j--){

			int temp = arr[j];

			arr[j] = arr[j-1];

			arr[j-1] = temp;


		}		
	
	}

}


/**
 *@brief Arranges two arrays already sorted into a new big one array cointer of both arranged.
 *@param[L] First array sorted.
 *@param[R] Second array sorted.
 *@param[arr] The array that is going to contain the values of L and R sorted.
 *@param[nL] Length of the first array.
 *@param[nR] Length of the second array.
 *@return Void.
 */
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



/**
 *@brief Arranges an array, given the array and its size. 
 *@param[arr] Given array.
 *@param[n] Array Length.
 *@return Void.
 */
void mergeSort(int arr[], int n){	

	if(n < 2) return;

	int mid = n/2;

	int L[mid];
	int R[n-mid];

	for(int i = 0; i < mid; i++){
		L[i] = arr[i];

	}

	for(int i = 0; i < n-mid; i++){       
		R[i] = arr[mid+i];
	}

	mergeSort(L, mid);
	mergeSort(R, n-mid);
	merge(L, R,  arr, mid, n-mid);
}


int main(){

	for(int i = 5; i < 105; i = i + 5){

		int temp[i];
		int temp2[i];

		for(int j = 0; j < i;j++){

			int val = rand()%100;
			temp[j] = val;
			temp2[j] = val;
			

		}

		chrono::time_point<std::chrono::system_clock> start, end;
		start = chrono::system_clock::now();
		mergeSort(temp, i);
		end = chrono::system_clock::now();
		chrono::duration<double> elapsed_seconds = end-start;
		time_t end_time = std::chrono::system_clock::to_time_t(end);
	
		cout <<  "'MERGE SORT' Array with [" << i << "] elements elapsed time: " << elapsed_seconds.count()*1000000 << endl;

	
		start = chrono::system_clock::now();
		insertionSort(temp2, i);
		end = chrono::system_clock::now();
		elapsed_seconds = end-start;
		end_time = std::chrono::system_clock::to_time_t(end);
		

		cout << "'INSERT SORT' Array with [" << i << "] elements elapsed time: " << elapsed_seconds.count()*1000000 << endl;


	}



}


