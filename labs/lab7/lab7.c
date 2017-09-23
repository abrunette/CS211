#include <iostream>
#include "CompSci.h"
#include "Adjunct.h"
#include "Tenure.h"
using namespace std;

int main()
{
	Adjunct prof1("Adam Smith", "asmith@csusm.edu", 12345, 'M', 2, 1);
	prof1.findSalary();
	prof1.print();	

	Tenure prof2("Jim Anderson", "janderson@csusm.edu", 54321, 'A', 8);
	prof2.findSalary();
	prof2.print();

	return 0;
}
