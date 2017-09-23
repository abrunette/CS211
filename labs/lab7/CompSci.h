#ifndef COMPSCI_H
#define COMPSCI_H
#include <iostream>
#include <string>
using namespace std;

class CompSci
{
	protected:
	string name;
	string email;
	long facultyId;
	public:
	CompSci();
	CompSci(string name, string email, long facultyId);
	void getCompSci() const;
};
#endif
