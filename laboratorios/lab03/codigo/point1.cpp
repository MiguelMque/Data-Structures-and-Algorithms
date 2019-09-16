#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Semester{
	string data;
	map<string, map<string, int>> student;
	Semester *next;

};

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
		void insert(string, int);
		void remove(int);
		string get(int);
		int size();
		int contains(string);
		Semester getSemester(int);
		void insertStudentData(string,string,string,int);
};

void LinkedList::insert(string x, int index){


	Semester *temp = new Semester;

	Semester *temp2 = new Semester;

	temp->data = x;

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


int LinkedList::contains(string data){

	Semester *s = head;

	int index = 0;

	while(s!=NULL){

	if(data == s->data) return index;

	s = s->next;
	index++;

	}	

	return -1;
}


void LinkedList::insertStudentData(string semester, string name, string subject, int grade){
	
	
	int index = contains(semester);
	if(index == -1) insert(semester, 0);

	index = 0;

	Semester *s= head;

	for(int i = 0; i < index; i++){
		s->next;
	}

	(s->student)[name][subject] = grade;

}

//REQUEST ONE WORKSHEET
void LinkedList::requestOne(string semester, string subject){

	string str = "\"";
	string str2 = str;
	str.append(subject);
	subject = str;
	subject.append(str2);	

	Semester *s = head;	
	
	while(s->data != semester) s = s->next;
	map<string, map<string, int>> student = s->student;

	map<string, map<string, int>>::iterator it;
	
	cout << semester << " => " << subject << endl;

	for(it = student.begin(); it!=student.end(); it++){
		
		map<string, int> myMap = it->second;
		
		if(myMap.find(subject) != myMap.end()) cout << it->first << "  :  " << myMap[subject] << endl;

	}

}


//REQUEST TWO WORKSHEET
void LinkedList::requestTwo(string semester, string name){

	Semester *s = head;

	while(s->data != semester) s = s->next;

	map<string, map<string, int>> student = s->student;

	map<string, int> myMap = student[name];

	map<string, int>::iterator it;

	cout << name << " - SEMESTER: " << semester << endl;

	for(it = myMap.begin(); it != myMap.end(); it++) cout << it->first << "  :  " << it->second << endl;

}


int main(){

	LinkedList list;

	ifstream fin;

	fin.open("data.csv", ios::in);
		
	if(!fin.is_open()) cout << "ERROR FILE";

	string student, semester, grade, subject, temp;
	int g;

	while(fin.good()){
		
		getline(fin, student, ',');
		
		for(int i = 0; i < 3; i++) getline(fin, semester, ',');
		
		for(int i = 0; i < 7; i++) getline(fin, subject, ',');

		getline(fin, grade, '\n');

		grade = grade.substr(grade.length()-2, grade.length());
		
		if(grade[0] == ',') grade = grade.substr(grade.length()-1, grade.length());	
		
		istringstream iss (grade);

		iss >> g;
		
		student = student.substr(1, student.length());

		if(student.length() != 0 && subject.find('"') == 0) {
			list.insertStudentData(semester, student, subject, g);
		}




	}

	list.requestOne("20152", "FUNDAMENTOS DE PROGRAMACIÓN");
	list.requestTwo("20152", "Esdras");

}
