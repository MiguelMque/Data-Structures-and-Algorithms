#include <bits/stdc++.h>
#include <string>
#include <initializer_list>
#include <iostream>

using namespace std;

bool groupSum6(int start, int *nums, int target){
	if(sizeof(nums)-1 < start){
		if(target == 0) return true;
		else return false;

	}

	if(nums[start] == 6) return groupSum6(start+1, nums, target-nums[start]);
	return groupSum6(start+1, nums, target-nums[start]) || groupSum6(start+1, nums, target);

}

int main(){

	cout << "''GroupSum6''" << endl;
	cout << "Input: {5, 6, 2}, 9" << endl;

	int nums[] = {5,6,2};
		
	cout << "Output: " << groupSum6(0, nums, 9) << endl;

	


return 0;
}


