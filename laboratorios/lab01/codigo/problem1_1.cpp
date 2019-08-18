/**
 * @file lcs
 * @version 1.1
 * @date 18/08/2019
 * @author Miguel Ángel Correa Manrique
 * @title Largest Common Subsequence
 */


#include <bits/stdc++.h> 
#include <string>


using namespace std;

const int cons = 10000;

int r;

/**
 *@brief Indicates the largest common subsequence given two sequences.
 *@param[A] First given subsequence.
 *@param[B] Second given subsequence.
 *@param[i] Initializator, must start in 0.
 *@param[j] Initializator, must start in 0.
 *@param[memo] To do memoization, needed, must be initialized for rows the size of A and columns a constant defined as 10000.
 *@return Returns the largest common subsequence of A and B (does not have to be contiguos).
 */
int lcs(string A, string  B, int i, int j, int memo[][cons]){
	
 	if(memo[i][j] != -1){ 
	       	return	memo[i][j];
	}


	if(A[i] == '.' || B[j] == '.'){ //Base case
		r = 0;

	}
	
	else if (A[i]==B[j]){
		r =  1 + lcs(A, B, i+1, j+1, memo);
	}

        else { 
		r = max(lcs(A, B, i+1, j, memo), lcs(A, B, i, j+1, memo));
	}

	memo[i][j] = r;

	return r;
}




int main(){
	
	string str1;
	string str2;

	cout << "Enter your first sequence: ";
	cin >> str1;

	cout << "Enter your second sequence: ";
	cin >> str2;
	
	str1 = str1 + ".";
	str2 = str2 + ".";

	int i = str1.length();
	int j = str2.length();
	
	cout << "Length str1 : " << i << endl;
	cout << "Length str2 : " << j << endl;
		
	int memo[i+1][cons];

	memset(memo, -1, sizeof(memo));
	
	cout << "Size of your Largest Common Sequence: " << lcs(str1, str2, 0, 0, memo) << endl;


	return 0;
	

}









		




		





















	


















