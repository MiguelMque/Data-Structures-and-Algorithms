#include <iostream>
#include <string>

using namespace std;

string str1 = "STRONGEST";
string str2 = "LONGEST";

int memo[9][7] = {}; //Array size declared since has to be constant


//Memoized function
int lcs(string A, string  B, int i, int j){

	if(memo[i][j] != 0){  
		
		return memo[i][j];
	}

	if(j == 0 || i == 0){ //Base case
		
		return 0;
	}


	else if(A[i-1]==B[j-1]){

		return 1 + lcs(A, B, i-1, j-1);
	} else {
	int r = max(lcs(A, B, i-1, j), lcs(A, B, i, j-1));
	memo[i][j] = r;

	return r;
	}
	
}




int main(){

	printf("Largest Common Subsequence: %d", lcs(str1, str2, n, m));


}














