#ifndef HUSBAND_H
#define HUSBAND_H

#include "Person.h"
#include "Wife.h"
#include<iostream>
#include<string>
using namespace std;

class Husband;

typedef Husband* Husptr;

//used to hold the pointer and constructors for husband class
class Husband: public Person
{	
	friend class Family;
	protected:
		Husptr nextFamily;
		Wife* myWife;
	public:
		Husband() {SSN = 0; Fname = Lname = " "; nextFamily = NULL;}
		Husband(long id, string Fn, string Ln) {SSN = id; Fname = Fn; Lname = Ln; nextFamily = NULL; myWife = NULL;}
};

#endif
