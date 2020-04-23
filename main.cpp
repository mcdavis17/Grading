#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "person.h"

using namespace std;

std::vector<Person*> *readFromFile(string file) {
	vector<Person*> *list =  new vector<Person*>;
	string line;
	ifstream myfile(file);
	if (myfile.is_open()) {
    	while ( getline (myfile,line) ) {
    		istringstream ss(line);
    		do {
    			Person *newPerson;
    			string type, fName, lName;
    			int exam1, exam2, exam3;
    			ss >> type >> fName >> lName >> exam1 >> exam2 >> exam3;
    			if ( type == "pf" ) {
    				newPerson = new PF_Student(fName, lName, exam1, exam2, exam3);
    				list->push_back(newPerson);
    			}
    			else if ( type == "std") {
    				newPerson = new STD_Student(fName, lName, exam1, exam2, exam3);
    				list->push_back(newPerson);
    			}
    		} while (ss);
    	}
    myfile.close();
	}
	else {
		cout << "Unable to open file" << endl;
		exit(1);
	}
	return list;
}

void printStudents(vector<Person*> *students, double avg) {
	for (size_t i = 0; i < students->size(); i++) {
		cout << students->at(i)->getName() << " " << students->at(i)->getGrade() << " " << students->at(i)->getStatus(avg) << endl;
	}
}

double computeAvg(vector<Person*> *students) {
	unsigned int total = 0;
	for (size_t i = 0; i < students->size(); i++) {
		total += students->at(i)->getStudentAvg();
	}
	return (total / students->size());
}

int main(int argc, char *argv[]) {
	vector<Person*> *students = readFromFile(argv[1]);
	if (students->size() == 0) {
		cout << "There are no employees" << endl;
		return 1;
	}
	double avg = computeAvg(students);
	printStudents(students, avg);

	return 0;
}