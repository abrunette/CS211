#ifndef ADJUNCT_H
#define ADJUNCT_H

#include "CompSci.h"
using namespace std;

class Adjunct : public CompSci
{
	protected:
	char degree;
	int NoOfTA;
	int NoOfCourses;
	public:
	Adjunct();
	Adjunct(string name, string email, long facultyId, char d, int TA, int Courses);
	void getAdjunct(char degree, int NoOfTA, int NoOfCourses);
	void setAdjunct(char degree, int NoOfTA, int NoOfCourses);
	void print() const;
	float findSalary() const;
};

#endif
