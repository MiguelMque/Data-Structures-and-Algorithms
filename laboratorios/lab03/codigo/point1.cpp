/**
 * @file point1
 * @version 2.0
 * @author Miguel Ángel Correa Manrique
 * @title Point 1
 */

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/**
 * A structure to represent a Semester.
 */
struct Semester{

	/*@{*/
	string data; /**<the semester */ 
	map<string, map<string, int>> student; /**<the student information*/
	Semester *next; /**<the next node on the list*/
       /*@}*/	

};


/**
 * class LinkedList
 * brief Implementation of a runtime database for a University using LinkedList
 *
 * details Is based on a single linked list, where each item of the list represents a
 *	   semester, which saves each student data on HashMap Tables on the respective semester
 *	   the HashMap table has as key, the student, that stores another HashMap Table for all
 *         their subjects as key with their respective grade.
 */
class LinkedList{

		Semester *head;
	public:

		LinkedList(){
			head = NULL;
		}
		
		void requestTwo(string semester, string name);		
		void requestOne(string semester, string subject);

		void insert(string, int);
		void remove(int);
		string get(int);
		int size();
		int contains(string);
		Semester getSemester(int);
		void insertStudentData(string,string,string,int);
};



/**
 *@brief Inserts a new semester at some given index in the LinkedList
 *@param[x] Given semester
 *@param[index] Index of the LinkedList to put the semester
 *@return Void
 **/
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


/**
 *@brief remove some Semester on the LinkedList.
 *@param[index] Position of the node to delete.
 *@return Void.
 **/
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


/**
 *@brief Get a Semester at some given index
 *@param[index] Index of the Semester to get.
 *@return Semester
 **/
Semester LinkedList::getSemester(int index){
	Semester *s = head;

	for(int i = 0; i < index; i++){
		s = s->next;
	}

	return *s;
}


/**
 *@brief Get the semester yearnumber at some given index.
 *@param[index] Index of the Semester to get.
 *@return string yearnumber semester
 **/
string LinkedList::get(int index){
        Semester *s = head;

        for(int i = 0; i < index; i++){

                s = s->next;

        }

        return s->data;

}


/**
 *@brief Gets the size of the LinkedList.
 *@return The size of the LinkedList.
 **/
int LinkedList::size(){

        Semester *s = head;

        int i = 0;

        while(s!=NULL){
                i++;
                s = s->next;

        }

        return i;

}


/**
 *@brief Returns the index where the semester is stored.
 *@param[data] Semester to find index.
 *@return The index of the semester.
 **/
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


/**
 *@brief Insert the student data given on the list.
 *@param[semester] Given semester.
 *@param[name] Given name.
 *@param[subject] Given subject.
 *@param[grade] Given grade of the subject.
 *@return Void.
 **/
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

/**
 *@brief Given a semester and a subject prints out all the students with their grade on that respective semester and subject.
 *@param[semester] Given semester.
 *@param[subject] Given subject.
 *@return Void.
 **/
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


/**
 *@brief Given a semester and name, prints out all the subjects with their grade of a student on that respective semester.
 *@param[semester] Given semester.
 *@param[name] Given name.
 *@return Void.
 **/
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
