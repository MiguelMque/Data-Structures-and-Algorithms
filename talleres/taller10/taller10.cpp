#include <iostream>
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    
};

class BinaryTree{
    Node *root;
    
    public:
    
        BinaryTree(){
            root = NULL;
        }
    
    bool search(int);
    void add(int);
    
    
    
};


//The time complexity for this algorithm is O(n) for worst case scenario.
void BinaryTree::add(int x){
    
    Node *temp = new Node;
    
    temp->data = x;
    temp->right = NULL;
    temp->left= NULL;
    
    if(root == NULL){
        root = temp;
        root->left = NULL;
        root->right = NULL;
        
        return;
    }
    
    Node *s = root;
    Node *temp2 = new Node;
    
    while(s->data != x){
        
        if (s->data > x && s->left == NULL){
          s->left = temp;
          return;
        } else if (s->data > x && s->left != NULL) s = s->left;
        
        else if(s->data < x && s->right == NULL){
          s->right = temp;
          return; 
        } else if (s->data < x && s->right != NULL) s = s->right;
        
        
    }

}

//The time complexity for this algorithm is O(n) for worst case scenario.
bool BinaryTree::search(int x){
    
    Node *s = root;
    
    while(s != NULL){
        
        if(s->data == x) return true;
        
        
        if(s->data > x) s = s->left;
        
        else s = s->right;
        
    }
    
    
}


int main() {
    
    BinaryTree tree;
    
    tree.add(2);
    tree.add(3);
    tree.add(1);
    tree.add(4);
    
    cout << tree.search(4);
    
}
