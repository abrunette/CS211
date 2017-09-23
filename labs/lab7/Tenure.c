#include "Tenure.h"
#include <iostream>
using namespace std;

Tenure::Tenure()
{
	rank = ' ';
	YearOfExp = 0;
}

Tenure::Tenure(string name, string email, long facultyId, char r, int Exp ): CompSci(name, email, facultyId)
{
	rank = r;
	YearOfExp = Exp;
}

void Tenure::getInfo(char r, int Exp)
{
	
}

void Tenure::setInfo(char r, int Exp)
{
	rank = r;
	YearOfExp = Exp;
}

void Tenure::print() const
{
	cout << "Name: " << CompSci::name << endl
	     << "Email: " << CompSci::email << endl
	     << "Faculty ID: " << CompSci::facultyId << endl
	     << "Rank: " << Tenure::rank << endl
	     << "Years of Experience: " << Tenure::YearOfExp << endl;
}

float Tenure::findSalary() const
{
	int salary = 0;
	int BSal = 0;

	if(Tenure::rank == 'A')
		BSal = 65000;
	else if(Tenure::rank == 'S')
		BSal = 80000;
	else
		BSal = 90000;

	return salary = (BSal * Tenure::YearOfExp);
}

