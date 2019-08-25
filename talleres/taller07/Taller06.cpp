#include <iostream>
using namespace std;




class LinkedList{
	private:

		struct Node{
			int data;
			Node *next;
		};

		Node *head;
		Node *tail;

	public:


		LinkedList(){
			head = NULL;
			tail = NULL;
		}

		void insert(int, int);
		void insertOneValue(int);
		void print();
			
};

void LinkedList::insertOneValue(int x){

	Node *temp = new Node;

	temp->data = x;
	temp->next = NULL;

	if(head==NULL){

		head = temp;
		tail = temp;
		temp = NULL;	

	} else {
		tail->next = temp;
		tail = temp;
		temp = NULL;

	}

}

void LinkedList::insert(int x, int index){

	int counter = 0;

	Node *temp = new Node;

	Node *s = new Node;

	Node *temp2 = new Node;

	s = head;

	temp->data = x;

	while(s != NULL){
		s = s->next;
		counter++;
	}

	if(index == 0 && head == NULL){
		head = temp;
		head->next = NULL;

	} else if (index == 0 && head != NULL) {
		temp2 = head;
		head = temp;
		head->next = temp2;

	} else {

		s = head;

		for(int i = 0; i < index; i++){
			temp2 = s;
			s = s->next;

		}

		temp2->next = temp;
		temp->next = s;

	}

}

void LinkedList::print(){


	Node *temp = head;

	while(temp != NULL){
		cout<<temp->data<<endl;
		temp = temp->next;

	}



}


int main(){




	LinkedList List;

	for(int i = 1; i <= 10; i++){

		List.insertOneValue(i);
	}

	List.insert(1000, 3);


	List.print();

	return 0;
}
