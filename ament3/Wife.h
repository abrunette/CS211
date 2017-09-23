#ifndef WIFE_H
#define WIFE_H
#include "Person.h"
#include "Child.h"
#include<iostream>
using namespace std;

class Wife;

typedef Wife* Wifeptr;

//used to hold the pointer and constructors for wife class
class Wife: public Person
{
	friend class Family;
	protected:
		Childptr myChildren;
	public:
		Wife() {SSN = 0; Fname = Lname = " "; myChildren = NULL;}
		Wife(long id, string Fn, string Ln) {SSN = id; Fname = Fn; Lname = Ln; myChildren = NULL;}
};

#endif
