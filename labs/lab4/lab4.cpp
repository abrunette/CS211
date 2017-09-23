#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "studentcollection.h"

//calls below functions, and creates a vector "Students"
int main()
{
	StudentCollection The_Students;
	The_Students.GetInfo();
	The_Students.PrintCollections();
	return 0;
}


