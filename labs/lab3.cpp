#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//class of Course
class Course
{
	public:
	long CourseNum;
	string CourseName;
};

//class of Person
class Person
{
	public:
	long SSN;
	string Fname;
	string Lname;
	int Age;
	char Gender;
};

//class of Student
class Student
{
	public:
	long StNo;
	Course Course1;
	Course Course2;
	Course Course3;
};

//class of StudentProfile
class StudentProfile
{
	public:
	Person PersonalInfo;
	Student StdInfo;
};

//function prototypes
int GetInfo(vector<StudentProfile> &Students);
void PrintInfo(const vector<StudentProfile> Students, const int count);

//calls below functions, and creates a vector "Students"
int main()
{
	vector<StudentProfile>Students;
	int count = GetInfo(Students);
	PrintInfo(Students, count);
	return 0;
}

//Reads info from input file into class, then puts class in vector
int GetInfo(vector<StudentProfile> &Students)
{
	StudentProfile new_entry;
	ifstream iFile;
	iFile.open("students.txt");
	int count = 0;
	iFile >> new_entry.PersonalInfo.SSN 
		>> new_entry.PersonalInfo.Fname
		>> new_entry.PersonalInfo.Lname
		>> new_entry.PersonalInfo.Age
		>> new_entry.PersonalInfo.Gender
		>> new_entry.StdInfo.StNo
		>> new_entry.StdInfo.Course1.CourseNum
		>> new_entry.StdInfo.Course1.CourseName
		>> new_entry.StdInfo.Course2.CourseNum
		>> new_entry.StdInfo.Course2.CourseName
		>> new_entry.StdInfo.Course3.CourseNum
		>> new_entry.StdInfo.Course3.CourseName;

	while(iFile)
	{
		Students.push_back(new_entry);
		count++;
		iFile >> new_entry.PersonalInfo.SSN 
			>> new_entry.PersonalInfo.Fname
			>> new_entry.PersonalInfo.Lname
			>> new_entry.PersonalInfo.Age
			>> new_entry.PersonalInfo.Gender
			>> new_entry.StdInfo.StNo
			>> new_entry.StdInfo.Course1.CourseNum
			>> new_entry.StdInfo.Course1.CourseName
			>> new_entry.StdInfo.Course2.CourseNum
			>> new_entry.StdInfo.Course2.CourseName
			>> new_entry.StdInfo.Course3.CourseNum
			>> new_entry.StdInfo.Course3.CourseName;
	}
	iFile.close();
	return(count);
}

//Print our the relevent info from the attributes of a class that was put into a vector
void PrintInfo(const vector<StudentProfile> Students, const int count)
{
	for(int i = 0; i < count; i++)
	{
		cout << "\nHere is the personal info for student " << (i + 1) << ":" << endl
			<< "SSN:\t\t " << Students[i].PersonalInfo.SSN << endl
			<< "First Name:\t " << Students[i].PersonalInfo.Fname << endl
			<< "Last Name:\t " << Students[i].PersonalInfo.Lname << endl
			<< "Age:\t\t " << Students[i].PersonalInfo.Age << endl
			<< "Gender:\t\t " << Students[i].PersonalInfo.Gender << endl
			<< "Student ID #:\t " << Students[i].StdInfo.StNo << endl
			<< "Course 1 #:\t " << Students[i].StdInfo.Course1.CourseNum << endl
			<< "Course 1 Name:\t " << Students[i].StdInfo.Course1.CourseName << endl
			<< "Course 2 #:\t " << Students[i].StdInfo.Course2.CourseNum << endl
			<< "Course 2 Name:\t " << Students[i].StdInfo.Course2.CourseName << endl
			<< "Course 3 #:\t " << Students[i].StdInfo.Course3.CourseNum << endl
 			<< "Course 3 Name:\t " << Students[i].StdInfo.Course3.CourseName << endl << endl;
	}
}
