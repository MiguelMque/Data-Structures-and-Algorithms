#include<bits/stdc++.h>

using namespace std;

#define D(x) cout << "DEBUG: " << #x " = " << x << endl
#define fore(i,a,b) for(int i = a;i<b;++i)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const double PI = acos(-1.0);
template <class T> string toStr(const T &x){stringstream s;s<<x;return s.str();}

template <class T> int toInt(const T &x){stringstream s;s<<x;int r;s>>r;return r;}


struct Node{

	int data;
	Node *right;
	Node *left;

};


class BinaryTree{
	public:
		Node *root;
	
		BinaryTree(){

			root = NULL;

		}

	void add(int x){
		Node *temp = new Node;
    
    		temp->data = x;
    		temp->right = NULL;
    		temp->left= NULL;
    
   		 if(root == NULL){
		root = temp;
    		return;

    		}

    		Node *temp2 = root;
   
   		while(temp2->data != x){

			if(temp2->left != NULL && x < temp2->data){
				temp2 = temp2->left;
			} else if(temp2->right != NULL && x > temp2->data){
				temp2 = temp2->right;
			} else if(x < temp2->data){
				temp2->left = temp;
				return;
			} else {
				temp2->right = temp;
				return;
			}
		}	
    }

};



void postorder(Node *n){

	if(n==NULL) return;
	postorder(n->left);
	postorder(n->right);
	cout << n->data << " ";

}

void preorder(Node *n){

	if(n==NULL) return;

	cout << n->data << " ";
	preorder(n->left);
	preorder(n->right);


}


int main(){


	BinaryTree t;

	int x;

	while(cin >> x) t.add(x);		

	postorder(t.root);

}


