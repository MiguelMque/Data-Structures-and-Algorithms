#include <bits/stdc++.h>
#include <string>
#include <initializer_list>
#include <iostream>
#include <array>
using namespace std;

bool groupSum6(size_t start, vector<int> nums, int target){
	if(nums.size()-1 < start){
		if(target == 0) return true;
		else return false;

	}

	if(nums[start] == 6) return groupSum6(start+1, nums, target-nums[start]);
	return groupSum6(start+1, nums, target-nums[start]) || groupSum6(start+1, nums, target);

}


bool groupSum5(size_t start, vector<int> nums, int target){

	if(nums.size()-1 < start) return target == 0;


	if(nums[start]%5 == 0 && nums.size()-1 >=  start+1 && nums[start+1] == 1) return groupSum5(start+2, nums, target-nums[start]);

	else if (nums[start]%5 == 0) return groupSum5(start+1, nums, target-nums[start]);

	return groupSum5(start+1, nums, target-nums[start]) || groupSum5(start+1, nums, target);






}

int main(){

	cout << "''GroupSum6''" << endl;
	cout << "Input: {5, 6, 2}, 9" << endl;

	vector <int> vect {5,6,2};
		
	cout << "Output: " << groupSum6(0, vect, 9) << endl << endl;

	cout << "''GroupSum5''" << endl;
	cout << "Input: {2, 5, 10, 4}, 15" << endl;
	
	vector<int> vect2 {2, 5, 10, 4};
	
	cout << "Output: " << groupSum5(0, vect2, 15) << endl << endl;	


return 0;
}


