#include <iostream>
#include <stack>
using namespace std;


int main(){

	int n;
	cin >> n;

	while(n--){

	string s;

	cin >> s;

	bool r = true;

	stack<char> x;
	stack<char> x2;
		for(int i = 0; i < s.length() && r; i++){


			switch(s[i]){

				case '{':
				case '(':
				case '[':
					x.push(s[i]);
					break;

				case ')':
					if(!x.empty() && x.top() == '('){
						x.pop();
						break;
					} else {
						r=false;
						break;
					}


				case '}':
					if(!x.empty() && x.top() == '{'){
						x.pop();
						break;
					} else {
						r = false;
						break;
					}

				case ']':
					if(!x.empty() && x.top() == '['){
						x.pop();
						break;
					} else {
						r = false;
						break;	
					}

			}





		}


		if(r&&x.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;

		r = false;

		x=x2;
	}

	
	return 0;

}
