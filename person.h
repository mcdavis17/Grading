#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>

class Person {

public:
	//virtual ~Person();
	//Person(std::string, std::string);
	virtual double getStudentAvg() = 0;
	virtual char getGrade() { return 'E'; };
	virtual std::string getStatus(double) { return "error"; } ;
	std::string getName();

//protected:
	std::string firstName;
	std::string lastName;

};

#include "std_student.h"
#include "pf_student.h"

#endif