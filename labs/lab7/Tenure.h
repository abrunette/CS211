#ifndef TENURE_H
#define TENURE_H

#include "CompSci.h"
using namespace std;

class Tenure:public CompSci
{
	protected:
	char rank;
	int YearOfExp;
	public:
	Tenure();
	Tenure(string name, string email, long facultyId, char r, int Exp);
	void getInfo(char rank, int YearOfExp);
	void setInfo(char rank, int YearOfExp);
	void print() const;
	float findSalary() const;
};
#endif
