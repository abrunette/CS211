#include <iostream>
#include "student.h"

void Student::SetAStudent(long stuNum, long c1Num, string c1Name, long c2Num, string c2Name, long c3Num, string c3Name)
{
	StNo = stuNum;
	Course1.SetACourse(c1Num, c1Name);
	Course2.SetACourse(c2Num, c2Name);
	Course3.SetACourse(c3Num, c3Name);
}

void Student::PrintAStudent()
{
	cout << "Student Number: " << StNo << endl;
	Course1.PrintACourse();
	Course2.PrintACourse();
	Course3.PrintACourse();
		//<< "Course 1: " << Course1.PrintACourse() << endl
		//<< "Course 2: " << Course2.PrintACourse() << endl
		//<< "Course 3: " << Course3.PrintACourse() << endl;
}
