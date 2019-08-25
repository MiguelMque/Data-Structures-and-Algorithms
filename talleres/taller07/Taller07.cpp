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
		}

		void insert(int, int);
		void remove(int);
		int get(int);
		int size();
		bool contains(int);
		Node getNode(int);	
};

/*void LinkedList::insertTop(int x){

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
*/

//The time complexity for this method is O(n), meaning that if it is used n times, then its complexity is O(n²)
void LinkedList::insert(int x, int index){


	Node *temp = new Node;

	Node *temp2 = new Node;

	temp->data = x;


	if(index == 0 && head == NULL){
		head = temp;
		head->next = NULL;

	} else if (index == 0 && head != NULL) {
		temp2 = head;
		head = temp;
		head->next = temp2;

	} else {
		Node *s = new Node;

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

int LinkedList::size(){

        Node *s = head;

        int i = 0;

        while(s!=NULL){
                i++;
                s = s->next;

        }

        return i;

}

//######Optional #2#######
bool LinkedList::contains(int data){


	Node *s = head;

	while(s!=NULL){

	if(data == s->data) return true;

	s = s->next;

	}	


	return false;

}

int helperMaximum(LinkedList list, int size){
	int a = list.get(0);

	if(size==1) return list.get(0);

	list.remove(0);

	return max(a, helperMaximum(list, size-1));

}


int maximumValue(LinkedList list){
	LinkedList newList = list;

        return helperMaximum(newList, list.size());


}

void print(LinkedList list){


	for(int i = 0; i < list.size(); i++){

	cout <<"[" << i <<  "] "  << list.get(i) << endl;

	}

}




int main(){

	LinkedList list;

	for(int i = 1; i <= 10; i++){

		list.insert(i, 0);
	}

	cout << "''''Original list''''" << endl;

	print(list);

	cout << "Inserting 3000, on position 3..." << endl;
		
	list.insert(3000, 3);

	cout << "'''New List'''" << endl;

	print(list);

	cout << "Removing item from position 3..." <<endl;

	list.remove(3);


	cout << "'''New List'''" << endl;

	print(list);

	list.remove(0);

	cout << "Removing item from position 0..." << endl;
	
	cout << "'''New List'''" << endl;

	print(list);

	cout << "Inserting 400, on position 5..." << endl;
	
	list.insert(400, 5);

	cout << "'''New List'''" << endl;

	print(list);

	cout << "''Analysis''" << endl;

	cout << "Maximum value: " << maximumValue(list) << endl;

	cout << "Does exist the number 4 in the list?: " << list.contains(4) << endl;


	return 0;
}
