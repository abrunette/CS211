#include <iostream>
#include "Employee.h"

int Employee::totalNumofEmployees = 0;
int Employee::nextEmpId = 1000;
int Employee::nextOfficeNo = 10;

Employee::Employee(): officeNo(nextOfficeNo), empId(nextEmpId), empPosition('E')
{
	name = "Unknown";
	deptNo = 0;
	yearOfExp = 0;
	salary = 0;
	totalNumofEmployees++;
	nextEmpId++;
	nextOfficeNo++;
}

Employee::Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp):officeNo(nextOfficeNo), empId(nextEmpId)
{
	name = theName;
	deptNo = theDeptNo;
	empPosition = theEmpPosition;
	yearOfExp = theYearOfExp;
	salary = 0;
	totalNumofEmployees++;
	nextEmpId++;
	nextOfficeNo++;
}

Employee::~Employee()
{
	totalNumofEmployees--;
	nextEmpId--;
	nextOfficeNo--;
}

void Employee::Print() const
{
	cout << "Here is employee number: " << empId
	     << "\nName:\t\t\t" << name
	     << "\nOffice Number:\t\t" << officeNo
	     << "\nDepartment Number:\t" << deptNo
	     << "\nEmployee Position:\t" << empPosition
	     << "\nYears of Experience:\t" << yearOfExp
	     << "\nSalary:\t\t\t" << salary
	     << "\nTotal Number of Employees:\t" << totalNumofEmployees
	     << "\nNext Employee ID:\t\t" << nextEmpId
	     << "\nNext Office Number:\t\t" << nextOfficeNo << "\n\n";
}

void Employee::GetInfo()
{
	cout << "Please enter the employees name:\t";
	getline(cin, name);
	cout << "\nPlease enter the employees position:\t";
	cin >> empPosition;
	cout << "\nPlease enter the employees years of experience:\t";
	cin >> yearOfExp;
}
