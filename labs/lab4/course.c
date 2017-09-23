#include <iostream>
using namespace std;
#include "course.h"

void Course::SetACourse(long cNum, string cName)
{
	CourseNum = cNum;
	CourseName = cName;
}

void Course::PrintACourse()
{
	cout << "Course Number:\t" << CourseNum << endl;
	cout << "Course Name:\t" << CourseName << endl;
}
