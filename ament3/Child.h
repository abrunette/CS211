#ifndef CHILD_H
#define CHILD_H
#include "Person.h"
#include<iostream>
using namespace std;
class Child;

typedef Child* Childptr;

//used to hold pointer and constructors for child in family
class Child: public Person 
{
	friend class Family;
	protected:
		Childptr mySibling;
	public:
		Child() {SSN = 0; Fname = Lname = " "; mySibling = NULL;}
		Child(long id, string Fn, string Ln) {SSN = id; Fname = Fn; Lname = Ln; mySibling = NULL;}
};

#endif

