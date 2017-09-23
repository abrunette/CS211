#include <iostream>
#include "CompSci.h"

using namespace std;

CompSci::CompSci()
{
	name = "Unknown";
	email = "Unknown";
	facultyId = 0;
}

CompSci::CompSci(string n, string e, long ID)
{
	name = n;
	email = e;
	facultyId = ID;
}

void CompSci::getCompSci() const
{
	cout << "Name: " << name << endl
	     << "Email: " << email << endl
	     << "Faculty ID: " << facultyId << endl;
}
