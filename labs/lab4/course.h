//class of Course
#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
	private:
	long CourseNum;
	string CourseName;

	public:
	void SetACourse(long CourseNum, string CourseName);
	void PrintACourse();
};

#endif
