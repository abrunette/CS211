#include <iostream>

#include "person.h"

void Person::SetAPerson(long social, string firstN, string lastN, int anos, char yes)
{
	SSN = social;
	Fname = firstN;
	Lname = lastN;
	Age = anos;
	Gender = yes;
}

void Person::PrintAPerson()
{
	cout << "SSN: " << SSN << endl
		<< "First Name: " << Fname << endl
		<< "Last Name: " << Lname << endl
		<< "Age: " << Age << endl
		<< "Gender: " << Gender << endl;	
}
