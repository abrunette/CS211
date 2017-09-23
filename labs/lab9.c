#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node;
typedef Node* NodePtr;

class LL;
class Node 
{
	friend class LL;
	private:
		int stId;
		string stName;
		string stEmail;
		int stAge;
		NodePtr next;
	public:
		Node();
		Node(int id, string name, string email, int age);
};

class LL
{
	private:
		NodePtr  top;
		void destroy (NodePtr&);

	public:
		LL();
		LL(const LL& source);
		~LL();
		void insertDataFromFile();
		void print ();
		bool search (int);
		void insertAfterFirst (int id, string name, string email, int age);
		void insertBeforeFirst (int id, string name, string email, int age);
		void insertAfterLast (int id, string name, string email, int age);
		void insertBeforeLast (int id, string name, string email, int age);
		void remove (int);
		void copy (NodePtr top1, NodePtr& top2);
};

Node::Node()
{
	stId = 0;
	stName = stEmail = " ";
	stAge = 0;
}

Node::Node(int id, string name, string email, int age)
{
	stId = id;
	stName = name;
	stEmail = email;
	stAge = age;
}
//--------------------------------------------
//--------------------------------------------
// the default constructor
LL::LL()
{
	top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
LL::LL(const LL& source)
{
	copy(source.top, top);
}

//--------------------------------------------
//--------------------------------------------
// the destructor
LL::~LL()
{
	destroy(top);
}

//--------------------------------------------
//--------------------------------------------
// Read a transaction file and insert the data into it
// after reading a set of data you can call any of the 
// insert functions to insert the node into the linked list 
/* use the following data to test your program
	76543	Mary	mary@csusm.edu		19
	98765	Kathy	kathy@csusm.edu		30
	16438	Flora	flora@csusm.edu		25
	43260	Peter	peter@csusm.edu		29
	87590	kim	kim@csusm.edu		31
*/
void LL::insertDataFromFile()
{
	ifstream fin("lab9.txt");

	if(!fin)
		cout << "Error reading file!\n";

	int stId;
	string stName, stEmail;
	int stAge;

	while(fin >> stId >>stName >> stEmail >> stAge)
	{
		this->insertAfterLast(stId, stName, stEmail, stAge);
	}
	fin.close();
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void LL::print ()
{
	NodePtr p = top;
	if(top == NULL)
	{
		cout << endl << "There is nothing in the list!\n" << endl;
		return;
	}

	cout << endl << "Printing the list..." << endl << "-------------------------------------------------------" << endl;

	while(p != NULL)
	{
		cout <<	"ID: " << p->stId
		     << "\tName: " << p->stName
		     << "\tEmail: " << p->stEmail
		     << "\tAge: " << p->stAge << endl;
		p = p->next;
	}
	cout << "-------------------------------------------------------" << endl;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool LL::search (int id)
{
	if(top == NULL)
		return false;
	NodePtr p = top;
	while(p->next != NULL)
	{
		if(id == p->stId)
			return true;
		p = p->next;
	}
	return false;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 10 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertAfterFirst (int id, string name, string email, int age)
{
	if(search(id))
	{
		cout << "Already in the linked list.\n";
		return;
	}
	NodePtr p = new Node(id, name, email, age);
	if(top == NULL)
	{
		top = p;
		top->next = NULL;
		return;
	}
	if(top->next == NULL)
	{
		top->next = p;
		return;
	}
	p->next = top->next;
	top->next = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 10 --> 1 --> 20 -->13 --> 4 --> 5 --> 6

void LL::insertBeforeFirst (int id, string name, string email, int age)
{
	if(search(id))
	{
		cout << "Already in the linked list.\n";
		return;
	}
	NodePtr p = new Node(id, name, email, age);
	NodePtr q = top;
	top = p;
	p->next = q;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6 --> 10

void LL::insertAfterLast (int id, string name, string email, int age)
{
	if(search(id))
	{
		cout << "Already in the linked list.\n";
		return;
	}
	NodePtr p = new Node(id, name, email, age);
	if(top == NULL)
	{
		top = p;
		return;
	}
	NodePtr q = top;
	while(q->next != NULL)
	{
		q = q->next;
	}
	q->next = p;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 6
// after inserting 10, we should get:
// list constains 1 --> 20 -->13 --> 4 --> 5 --> 10 --> 6

void LL::insertBeforeLast (int id, string name, string email, int age)
{
	if(search(id))
	{
		cout << "Already in the linked list.\n";
		return;
	}
	NodePtr p = new Node(id, name, email, age);
	if(top == NULL)
	{
		top = p;
		top->next = NULL;
		return;
	}
	NodePtr q = top->next;
	NodePtr r = top;
	while(q->next != NULL)
	{
		r = q;
		q = q->next;
	}
	r->next = p;
	p->next = q;
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void LL::remove (int id)
{
	if(top == NULL)
		return;
	if(top->stId == id && top->next == NULL)
	{
	 	delete top;
		top = NULL;
		return;
	}
	NodePtr k = NULL;
	NodePtr p = top;
	NodePtr q = top;
	while(p != NULL)
	{
		if(p->stId == id)
		{
			k = p->next;
			q->next = k;
			delete p;
			return;
		}
		q = p;
		p = p->next;
	}
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void LL::copy (NodePtr top1, NodePtr& top2)
{
	NodePtr acurr, bcurr;
	//destroy(top2);
	if(top1 != NULL)
	{
		top2 = new Node;
		top2->stId = top1->stId;
		top2->stName = top1->stName;
		top2->stEmail = top1->stEmail;
		top2->stAge = top1->stAge;

		acurr = top1;
		bcurr = top2;
		while(acurr->next != NULL)
		{
			bcurr->next = new Node;
			acurr = acurr->next;
			bcurr = bcurr->next;
			bcurr->stId = acurr->stId;
			bcurr->stName = acurr->stName;
			bcurr->stEmail = acurr->stEmail;
			bcurr->stAge = acurr->stAge;
		}
		bcurr->next = NULL;
	}
}       
//--------------------------------------------
// deallocate the nodes in a linked list
void LL::destroy(NodePtr& top) 
{	NodePtr p = top;
	while(top != NULL)
	{
		top = top->next;
		delete p;
		p = top;
	}
	return;
}

//--------------------------------------------

int main () 
{
   LL list1;
   list1.insertDataFromFile();
   list1.print();
   list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
   list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
   list1.print();
   bool found = list1.search (12321);
   if(found)
	   cout << "the record was found" << endl;
   else
	   cout << endl << "the record was not found" << endl;
   list1.remove (54321);
   list1.print();
   
   LL list2(list1);
   list2.print();
   return 0;

}
//--------------------------------------------
