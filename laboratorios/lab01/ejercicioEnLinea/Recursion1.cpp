#include <bits/stdc++.h>
#include <string>
#include <initializer_list>
#include <iostream>

using namespace std;




string allStar(string str, size_t n){
	if (n == str.size()-1){
	return string{str[n]};

	}

	return string{str[n], '*'} + allStar(str, n+1);

}

string allStar(string str){
	return allStar(str,0);
}


bool array220(int *nums, int index){
	if(index == sizeof(nums)-1 || sizeof(nums) == 0) return false;
	
	if(nums[index]*10 == nums[index+1]) return true;

	else return false || array220(nums, index+1);	
	
	
	
	
}

int main(){

	cout << "''All Star''" << endl;
	cout << "Input: hello" << endl;
	cout << "Output: " << allStar("hello") << endl << endl;

	int nums[] = {1, 2, 3, 4, 40};
	
	cout << "''Array220''" << endl;
	cout << "Input: {1, 2, 3, 4, 40}" << endl;
	cout << "Output: " <<  array220(nums, 0) << endl;


return 0;
}
