#include "Adjunct.h"
#include <iostream>
using namespace std;

Adjunct::Adjunct()
{
	degree = ' ';
	NoOfTA = 0;
	NoOfCourses = 0;
}

Adjunct::Adjunct(string name, string email, long facultyId, char d, int TA, int Courses): CompSci(name, email, facultyId)
{
	degree = d;
	NoOfTA = TA;
	NoOfCourses = Courses;
}

void Adjunct::getAdjunct(char d, int TA, int C)
{
	degree = d;
	NoOfTA = TA;
	NoOfCourses = C;
}

void Adjunct::setAdjunct(char d, int TA, int C)
{
	degree = d;
	NoOfTA = TA;
	NoOfCourses = C;
}

void Adjunct::print() const
{
	CompSci::getCompSci();
	cout << "Degree: " << Adjunct::degree << endl
	     << "No of TA: " << Adjunct::NoOfTA << endl
	     << "No of Courses: " << Adjunct::NoOfCourses << endl
	     << "Salary: " << Adjunct::findSalary() << endl;
}

float Adjunct::findSalary() const
{
	int salary = 0;
	int TASal = 0;
	int CSal = 0;

	if(Adjunct::degree == 'B')
	{
		TASal = 1500;
		CSal = 3000;
	}
	else if(Adjunct::degree == 'M')
	{
		TASal = 2000;
		CSal = 4000;
	}
	else
	{
		TASal = 2500;
		CSal = 5000;
	}

	return salary = (Adjunct::NoOfTA * TASal) + (Adjunct::NoOfTA * CSal);
}
