#include <iostream>
using namespace std;


struct Node{
	int data;
	Node *next;

};


class LinkedList{

		Node *head;
		Node *tail;

	public:


		LinkedList(){
			head = NULL;
			tail = NULL;
		}

		void insert(int, int);
		void insertTop(int);
		void print();
		void remove(int);
		int get(int);
		int size();
		Node getNode(int);	
};

void LinkedList::insertTop(int x){

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



void LinkedList::remove(int index){

	Node *s = head;
	Node *temp = new Node;
	Node *temp2 = new Node;
	
	if(index == 0){
	head = s->next;
	s = NULL;

	} else	{

		for(int i = 0; i < index; i++){
			temp = s;
			s = s->next;
			temp2 = s->next;
		}

		s = NULL;
		temp->next = temp2;

	}
}



void LinkedList::print(){



	Node *temp = head;

	while(temp != NULL){
		cout<<temp->data<<endl;
		temp = temp->next;

	}



}

Node LinkedList::getNode(int index){

	Node *s = head;

	for(int i = 0; i < index; i++){

		s = s->next;

	}


	return *s;



}


int LinkedList::get(int index){


        Node *s = head;

        for(int i = 0; i < index; i++){

                s = s->next;

        }


        return s->data;



}

bool constains(int data){


	Node 


}


int LinkedList::size(){

	Node *s = head;

	int i = 0;

	while(s!=NULL){
		i++;
		s = s->next;

	}

	return i;

}





int main(){

	LinkedList List;

	for(int i = 1; i <= 10; i++){

		List.insertTop(i);
	}

	List.insert(1000, 3);

	
	
	List.remove(0);


	List.print();


	 cout << List.get(9) << endl;

	 cout << List.size() << endl;

	return 0;
}
