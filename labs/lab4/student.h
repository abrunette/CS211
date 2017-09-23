//class of Student
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;
#include "course.h"

class Student
{
	private:
	long StNo;
	Course Course1;
	Course Course2;
	Course Course3;
	
	public:
	void SetAStudent(long stuNum, long c1Num, string c1Name, long c2Num, string c2Name, long c3Num, string c3Name);
	void PrintAStudent();
};

#endif
