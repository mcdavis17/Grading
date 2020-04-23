#include "pf_student.h"

PF_Student::PF_Student(std::string f, std::string l, int one, int two, int three) {
	firstName = f;
	lastName = l;
	exam1 = one;
	exam2 = two;
	exam3 = three;
}

double PF_Student::getStudentAvg() {
	return (0.25*exam1 + 0.25*exam2 + 0.5*exam3);
}

char PF_Student::getGrade() {
	if (getStudentAvg() >= 60) return 'P';
	else return 'F';
}

std::string PF_Student::getStatus (double threshold) {
	if (getStudentAvg() == threshold) return ("Equal");
	else if (getStudentAvg() < threshold) return ("Below");
	else return ("Above");
}