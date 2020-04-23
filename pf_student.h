#ifndef _PF_STUDENT_H_
#define _PF_STUDENT_H_

#include "person.h"

class PF_Student : public Person {

public:
	int exam1;
	int exam2;
	int exam3;

	PF_Student(std::string, std::string, int, int, int);
	double getStudentAvg();
	char getGrade();
	std::string getStatus(double);
};

#endif