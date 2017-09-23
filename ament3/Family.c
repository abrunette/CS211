#include<iostream>
#include<fstream>
#include"Family.h"
using namespace std;

//systematically removes every node in the list
//2016.05.04
bool Family::destroy()
{
	Husptr H = top;
	while(H->nextFamily != NULL)
	{
		RemoveHusband(H->SSN);
		H = H->nextFamily;
	}
}

//searches list for husband with SSN the same as id
//2016.05.02
Husptr Family::Search(long id)
{
	Husptr H = top;
	if(top == NULL)
		return H;
	while(H != NULL)
	{
		if(id == H->SSN)
			return H;
		H = H->nextFamily;
	}
	return NULL;
}

//adds a husband given an id and general info
//2016.05.01
bool Family::AddHusband(long id, string Fname, string Lname)
{
	Husptr q = Search(id);
	if(q != NULL)
	{
		cout << "This family with id: " << id << " already exists!\n";
		return false;
	}	
	Husptr p = new Husband(id, Fname, Lname);
	p->nextFamily = top;
	top = p;
	cout << "The family with id: " << id << " was added successfully!\n";
	return true;
}

//removes a husband given id
//2016.05.04
bool Family::RemoveHusband(long HusId)
{
	Husptr H = Search(HusId);
	if(H == NULL)
	{
		cout << "This husband with id: " << HusId << " does not exist!\n";
		return true;
	}
	Wifeptr W = H->myWife;
	if(W == NULL)
	{
		cout << "This husband does not have a wife!\n";
		return false;
	}
	Childptr C = W->myChildren;
	if(C == NULL)
	{
		cout << "This family does not have any children!\n";
		return false;
	}
	while(C != NULL)
	{
		RemoveAchild(HusId, C->SSN);
		C = C->mySibling;
	}
	delete W;
	delete H;
	return true;

}

//adds a wife given wifeid and husid
//2016.05.01
bool Family::AddWife(long WifeId, string Fname, string Lname, long HusId)
{
	Husptr p = Search(HusId);
	if(p == NULL)
	{
		cout << "This family with id: " << HusId << " does not exist!\n";
		return false;
	}
	if(p->myWife != NULL)
	{
		cout << "This family with id: " << HusId << " is already married!\n";
		return false;
	}
	Wifeptr w = new Wife(WifeId, Fname, Lname);
	p->myWife = w;
	cout << "The family with id: " << HusId << " is now married to " << WifeId << endl;
	return true;
}

//removes a wife from a family after removing all children
//2016.05.04
bool Family::RemoveWife(long HusId)
{
	Husptr H = Search(HusId);
	if(H == NULL)
	{
		cout << "This husband with id: " << HusId << " does not exist!\n";
		return true;
	}
	Wifeptr W = H->myWife;
	if(W == NULL)
	{
		cout << "This husband does not have a wife!\n";
		return false;
	}
	Childptr C = W->myChildren;
	if(C == NULL)
	{
		cout << "This family does not have any children!\n";
		return false;
	}
	while(C != NULL)
	{
		RemoveAchild(HusId, C->SSN);
		C = C->mySibling;
	}
	delete W;
	return true;
}

//adds a child to a family, wife or sibling if there is already a child, using child id
//2016.05.01
bool Family::AddAchild(long ChildId, string Fname, string Lname, long HusId)
{
	Husptr H = Search(HusId);
	if(H == NULL)
	{
		cout << "This father with id: " << HusId << " does not exist!\n";
		return false;
	}
	Wifeptr W = H->myWife;
	if(W == NULL)
	{
		cout << "This child with id: " << ChildId << " does not have a mom!\n";
		return false;
	}
	Childptr C = W->myChildren;
	while(C != NULL)
	{
		if(C->SSN == ChildId)
		{
			cout << "This child with id: " << ChildId  << " already exists!\n";
			return false;
		}
		C = C->mySibling;
	}
	Childptr secondchild = W->myChildren;
	Childptr firstchild = new Child(ChildId, Fname, Lname);
	W->myChildren = firstchild;
	firstchild->mySibling = secondchild;
	cout << "The child with id: " << ChildId << " was added successfully!\n";
	return true;
}

//removes a child from a family given the dadid and childid
//2016.05.04
bool Family::RemoveAchild(long DadId, long ChildId)
{
	Husptr H = Search(DadId);
	if(H == NULL)
	{
		cout << "This father with id: " << DadId << " does not exist!\n";
		return false;
	}
	Wifeptr W = H->myWife;
	if(W == NULL)
	{
		cout << "This child with id: " << ChildId << " does not have a mom!\n";
		return false;
	}
	Childptr C = W->myChildren;
	if(C == NULL)
	{
		cout << "This family does not have any children!\n";
		return false;
	}
	while(C != NULL)
	{
		if(C->SSN == ChildId)
		{
			Childptr T = C->mySibling;
			W->myChildren = T;
			delete C;
			return true;
		}
		C = C->mySibling;
	}
	cout << "This child with id: " << ChildId << " does not exist!\n";
	return false;
}

//prints every member of a family given the husbands id
//2016.05.02
void Family::PrintAFamily(long HusId)
{
	Husptr p = Search(HusId);
	if(p == NULL)
	{
		cout << "Husband with id: " << HusId << " does not exist!\n";
		return;
	}	
	cout << "Husband name: " << p->Fname << " " << p->Lname << endl
	     << "Husband ID: " << p->SSN << endl << endl;
	Wifeptr W = p->myWife;
	if(W == NULL)
	{
		cout << "This husband does not have a wife!\n\n";
		return;
	}
	cout << "Wife name: " << W->Fname << " " << W->Lname << endl
	     << "Wife ID: " << W->SSN << endl << endl;
	Childptr C = W->myChildren;
	if(C == NULL)
	{
		cout << "This family does not have any children!\n";
		return;
	}
	while(C != NULL)
	{
		cout << "Child name: " << C->Fname << " " << C->Lname << endl
		     << "Child ID: " << C->SSN << endl << endl;
		C = C->mySibling;
	}	
}

//systematically prints out all families in the list starting from top
//2016.05.02
void Family::PrintAllFamilies()
{
	Husptr H = top;
	while(H != NULL)
	{
		PrintAFamily(H->SSN);
		H = H->nextFamily;
	}
}
//reads commands and general information into the relevant function
//2016.04.30
void Family::ReadTransactionFile()
{
	//variables hold all information that can be held in trans file
	string command, Fname, Lname;
	long HusId, WifeId, ChildId;
	bool result;

	ifstream Fin;
	Fin.open("A3TranFile.txt");
	if(!Fin)
	{
		cout << "Error reading transaction file! Ending program!\n";
		return;
	}
	while(Fin >> command)
	{
		cout << endl;
		if(command == "PrintAFamily")
		{
			Fin >> HusId;
			cout << "Attempting to print family...\n";
			PrintAFamily(HusId);
		}
		else if(command == "PrintAllFamilies")
		{
			cout << "Attempting to print all families...\n";
			PrintAllFamilies();
		}
		else if(command == "AddHusband")
		{
			Fin >> HusId >> Fname >> Lname;
			cout << "Attempting to add husband to list of families...\n";
			AddHusband(HusId, Fname, Lname);
		}
		else if(command == "AddWife")
		{
			Fin >> WifeId >> Fname >> Lname >> HusId;
			cout << "Attempting to add wife to husband...\n";
			AddWife(WifeId, Fname, Lname, HusId);
		}
		else if(command == "AddAchild")
		{
			Fin >> ChildId >> Fname >> Lname >> HusId;
			cout << "Attempting to add child to wife...\n";
			AddAchild(ChildId, Fname, Lname, HusId);
		}
		else if(command == "RemoveAchild")
		{
			Fin >> HusId >> ChildId;
			cout << "Attempting to remove child...\n";
			RemoveAchild(HusId, ChildId);
		}
		else
		{
			cout << "Invalid command in transaction file!\n";
			return;
		}
	}
}

















