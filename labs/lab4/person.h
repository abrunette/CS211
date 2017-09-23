#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

//class of Person
class Person
{
	private:
	long SSN;
	string Fname;
	string Lname;
	int Age;
	char Gender;
	
	public:
	void SetAPerson(long social, string firstN, string lastN, int anos, char yes);
	void PrintAPerson();
};

#endif
