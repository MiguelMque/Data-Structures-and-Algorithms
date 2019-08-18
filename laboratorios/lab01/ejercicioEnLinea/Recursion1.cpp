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

string reverseString(string str){
	int n = str.length();

	for(int i = 0; i< n/2; i++){

	swap(str[i], str[n-1-i]);

	}

	return str;
}

int countHi2(string str){
	int index = str.find("ih");
	if(index == -1) return 0;
	else{
		if(index + 2 >= str.length()) return 1;
		else{
			if(str[index+2] != 'x') return 1 + countHi2(str.substr(index+2));
			else return 0 + countHi2(str.substr(index+3));
		}
	}

}


int main(){

	cout << "''All Star''" << endl;
	cout << "Input: hello" << endl;
	cout << "Output: " << allStar("hello") << endl << endl;

	int nums[] = {1, 2, 3, 4, 40};
	
	cout << "''Array220''" << endl;
	cout << "Input: {1, 2, 3, 4, 40}" << endl;
	cout << "Output: " <<  array220(nums, 0) << endl << endl;
	
	cout << "''CountHi2''" << endl;
	cout << "Input: hixhhi" << endl;
	cout << "Output: " << countHi2(reverseString("hixhhi")) << endl;
return 0;
}
