#include <iostream>
#include <map>
using namespace std;

//Hi monitor, this data structure consist in the semester as primary key
//after that each semester contains students stored in a Map Table data structure
//and each student contains another Map that stores their subject grades in that respective semester.
struct Semester{
	string data;
	map<string, map<string, double>> student;
	Semester *next;

};

//Linked list data structure used to store different semesters.
class LinkedList{
		Semester *head;
	public:


		LinkedList(){
			head = NULL;
		}
		
		//These are the methods of the worksheet
		void requestTwo(string semester, string name);		
		void requestOne(string semester, string subject);

		//Other methods that could be needed for future applications
		void insert(string, map<string, map<string, double>>, int);
		void remove(int);
		string get(int);
		int size();
		bool contains(string);
		Semester getSemester(int);
};

void LinkedList::insert(string x, map<string, map<string, double>> student, int index){


	Semester *temp = new Semester;

	Semester *temp2 = new Semester;

	temp->data = x;
	temp->student = student;


	if(index == 0 && head == NULL){
		head = temp;
		head->next = NULL;

	} else if (index == 0 && head != NULL) {
		temp2 = head;
		head = temp;
		head->next = temp2;

	} else {
		Semester *s = new Semester;

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

	Semester *s = head;
	Semester *temp = new Semester;
	Semester *temp2 = new Semester;
	
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

Semester LinkedList::getSemester(int index){
	Semester *s = head;

	for(int i = 0; i < index; i++){

		s = s->next;
	}

	return *s;



}


string LinkedList::get(int index){
        Semester *s = head;

        for(int i = 0; i < index; i++){

                s = s->next;

        }

        return s->data;

}

int LinkedList::size(){

        Semester *s = head;

        int i = 0;

        while(s!=NULL){
                i++;
                s = s->next;

        }

        return i;

}

bool LinkedList::contains(string data){


	Semester *s = head;

	while(s!=NULL){

	if(data == s->data) return true;

	s = s->next;

	}	


	return false;

}

//REQUEST ONE WORKSHEET
void LinkedList::requestOne(string semester, string subject){

	Semester *s = head;
	
	
	while(s->data != semester) s = s->next;
	map<string, map<string, double>> student = s->student;

	map<string, map<string, double>>::iterator it;
	
	cout << "=>" << subject << endl;

	for(it = student.begin(); it!=student.end(); it++){
		
		map<string, double> myMap = it->second;
		
		if(myMap[subject] != 0) cout << it->first << myMap[subject] << endl;

	}

}


//REQUEST TWO WORKSHEET
void LinkedList::requestTwo(string semester, string name){

	Semester *s = head;

	while(s->data != semester) s= s->next;

	map<string, map<string, double>> student = s->student;

	map<string, double> myMap = student[name];

	map<string, double>::iterator it;

	cout << name << "INFORMATION" << "- SEMESTER: " << semester << endl;

	for(it = myMap.begin(); it != myMap.end(); it++) cout << it->first << "=>" << it->second << endl;

}


int main(){








}
