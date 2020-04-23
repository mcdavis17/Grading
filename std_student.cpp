#include "std_student.h"
#include <iostream>

STD_Student::STD_Student(std::string f, std::string l, int one, int two, int three) {
	firstName = f;
	lastName = l;
	exam1 = one;
	exam2 = two;
	exam3 = three;
}

double STD_Student::getStudentAvg() {
	return (0.25*exam1 + 0.25*exam2 + 0.5*exam3);
}

char STD_Student::getGrade() {
	if (getStudentAvg() >= 90) return 'A';
	else if (getStudentAvg() >= 80 ) return 'B';
	else if (getStudentAvg() >= 70 ) return 'C';
	else if (getStudentAvg() >= 60 ) return 'D';
	else return 'F';
}

std::string STD_Student::getStatus (double threshold) {
	if (getStudentAvg() == threshold) return ("Equal");
	else if (getStudentAvg() < threshold) return ("Below");
	else return ("Above");
}