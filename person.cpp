#include "person.h"

std::string Person::getName () {
	return (firstName + " " + lastName);
}