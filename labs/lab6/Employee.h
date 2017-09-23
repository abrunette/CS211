#ifndef EMPLOYEE_H
#define	EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{
	friend void SetSalary(Employee&);

	private:
		string name;
		const long officeNo;
		const long empId;
		int deptNo;
		char empPosition;
		int yearOfExp;
		float salary;
		static int totalNumofEmployees;
		static int nextEmpId;
		static int nextOfficeNo;

	public:
		Employee();
		~Employee();
		Employee(string theName, int theDeptNo, char theEmpPosition, int theYearOfExp);
		void Print() const;
		void GetInfo();
};

#endif
