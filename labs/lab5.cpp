#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

//******************************Function prototypes************************/

void SetSalary(Employee&);

/*************************************Main********************************/
int main()
{
	Employee emp1;
	emp1.Print();
	Employee emp2("Unknown",10,'?',0);
	emp2.GetInfo();
	SetSalary(emp2);
	emp2.Print();

	return 0;
}

void SetSalary(Employee& a)
{
	if(a.empPosition == 'E' && a.yearOfExp < 2)
		a.salary = 50000;

	else if(a.empPosition == 'E' && a.yearOfExp >= 2)
		a.salary = 55000;

	else if(a.empPosition == 'P' && a.yearOfExp < 4)
		a.salary = 60000;

	else if(a.empPosition == 'P' && a.yearOfExp >= 4)
		a.salary = 65000;

	else if(a.empPosition == 'M')
		a.salary = 70000;

	else if(a.empPosition == 'D')
		a.salary = 80000;
}

















