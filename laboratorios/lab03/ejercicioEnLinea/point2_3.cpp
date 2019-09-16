#include <iostream>
#include <cstring>
using namespace std;

int main(){

	string str;
	cin >> str;
	int n;
	cin >> n;
	int x;
	int y;
	int arr[str.length()];

	memset(arr, 0, sizeof(arr));

	for(int i = 0; i < str.length(); i++){
		if(str[i] == str[i+1]) arr[i+1] = arr[i]+1;
		else arr[i+1] = arr[i];

	}

	while(n--){
		cin >> x >> y;
		cout << arr[y-1] - arr[x-1] << endl;
	}

}
