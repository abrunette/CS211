#ifndef FAMILY_H
#define FAMILY_H

#include<iostream>
#include "Husband.h"
using namespace std;

class Family
{
	protected:
		Husptr top;
	public:
		Family() {top = NULL;}
		bool destroy();
		~Family() {destroy();}
		Husptr Search(long SSN);
		bool AddHusband(long SSN, string Fname, string Lname);
		bool RemoveHusband(long SSN);
		bool AddWife(long SSN, string Fname, string Lname, long husbandSSN);
		bool RemoveWife(long husbandSSN);
		bool AddAchild(long SSN, string Fname, string Lname, long fatherSSN);
		bool RemoveAchild(long fatherSSN, long childSSN);
		void PrintAFamily(long fatherSSN);
		void PrintAllFamilies();
		void ReadTransactionFile();
};

#endif
