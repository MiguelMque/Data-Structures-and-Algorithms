#include <iostream>
#include <list>
#include <stack>
#include <vector>


using namespace std;

void returnAbove(stack<int> *v, int x, int *pos){
	
	while(v[pos[x]].top() != x){
		int val = v[pos[x]].top();
		v[val].push(val);
		pos[val] = val;
		v[pos[x]].pop();
	}	


}

int main(){

	int n;
	int a;
	int b;
	string command;
	string option;
	cin >> n;
	int pos[n];
	stack<int> v [n];

		for(int i = 0; i < n; i++){
			stack<int> s;
			s.push(i);
			v[i] = s;
			pos[i] = i;
		}


	while(cin >> command){

		int temp;

		if(command == "quit") break;

		cin >> a >> option >> b;

		if(a==b || pos[a] == pos[b]){

		} else if (command == "move" && option == "onto"){
			returnAbove(v, a, pos);
			returnAbove(v, b, pos);

			v[pos[a]].pop();
			v[pos[b]].push(a);
			pos[a] = pos[b];
	
		} else if (command == "move" && option == "over"){
			returnAbove(v, a, pos);	

			v[pos[a]].pop();
			v[pos[b]].push(a);
			pos[a] = pos[b];

		} else if(command == "pile" && option == "onto"){
			returnAbove(v, b, pos);

			while(v[pos[a]].top() != a){
				int val = v[pos[a]].top();
				v[pos[b]].push(val);
				pos[val] = pos[b];
				v[pos[a]].pop();
			}

			v[pos[a]].pop();
			v[pos[b]].push(a);
			pos[a] = pos[b];
				

		} else if(command =="pile" && option == "over"){
			stack<int> helper;

			while(v[pos[a]].top() != a){
				int val = v[pos[a]].top();
				helper.push(val);
				pos[val] = pos[b];
				v[pos[a]].pop();
			}

			helper.push(a);

			while(!helper.empty()){

				int val = helper.top();

				v[pos[b]].push(val);

				helper.pop();
			}

		}


	}

	stack<int> helper;
	
	for(int i = 0; i < n; i++){
		cout << i << ":";
		while(!v[i].empty()){
			helper.push(v[i].top());
			v[i].pop();
		}


		while(!helper.empty()){
			cout << " " << helper.top();
			helper.pop();
		}

		cout << endl;

	}	


}
