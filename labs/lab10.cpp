#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Node;
typedef Node* NodePtr;

class CircularDLL;
class Node 
{
	friend class CircularDLL;
	
	private:
      		int stId;
		string stName;
		string stEmail;
		int stAge;
      		NodePtr next;
		NodePtr prev;
	public:
		Node() {next = this; prev = this;};
		Node(int stId, string stName, string stEmail, int stAge);
};

class CircularDLL
{
private:
	NodePtr  top;
	void destroy (NodePtr&);

public:
	CircularDLL();
	CircularDLL(const CircularDLL& source);
	~CircularDLL();
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
CircularDLL::CircularDLL()
{
	top = NULL;
}
//--------------------------------------------
//--------------------------------------------
// the copy constructor
CircularDLL::CircularDLL(const CircularDLL& source)
{
	top = NULL;
	copy(source.top, this->top);
}

//--------------------------------------------
//--------------------------------------------
// the destructor
CircularDLL::~CircularDLL()
{
	//destroy(top);
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

void CircularDLL::insertDataFromFile()
{
	int id, age;
	string name, email;

	ifstream Fin;
	Fin.open ("L10transfile.txt");
	if(!Fin.is_open())
	{
		cout << "Error reading file!\n";
		return;
	}
	while(Fin >> id >> name >> email >> age)
	{
		this->insertAfterLast(id, name, email, age);
	}
	Fin.close();
}
//--------------------------------------------
//--------------------------------------------
// print the linked list
void CircularDLL::print ()
{
	if(top->next == top)
		return;
	
	NodePtr temp = top;
	do
	{
		cout << "\tID: " << temp->stId
	   	     << "\tName: " << temp->stName
		     << "\tEmail: " << temp->stEmail
		     << "\tAge: " << temp->stAge << endl;

		temp = temp->next;
	}while(temp != top);
	cout << endl;
}
//--------------------------------------------
//--------------------------------------------
// search for a particular student id in the list
bool CircularDLL::search (int id)
{

}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list but after the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)/ after inserting 10, we should get:
// list constains 1 <--> 10 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertAfterFirst (int id, string name, string email, int age)
{
	NodePtr p = new Node(id, name, email, age);
	if(top == NULL)
	{
		top = p;
		return;
	}

	if(top == top->next)
	{
		top->next = p;
		p->prev = top;
		top->prev = p;
		p->next = p;
	}

	NodePtr tempnext = top->next;
	top->next = p;
	p->prev = top;
	tempnext->prev = p;
	p->next = tempnext;
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the top of the
// linked list before the first node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 10 <--> 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 10)

void CircularDLL::insertBeforeFirst (int id, string name, string email, int age)
{
	NodePtr p = new Node(id, name, email, age);
	if(top == NULL)
	{
		top = p;
		return;
	}
	if(top->next == top)
	{
		top->next = p;
		p->prev = top;
		top->prev = p;
		p->next = top;
		top = p;
	}

	p->prev = top->prev;
	p->next = top;
	top->prev = p;
	top = p;	
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list after the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> 10 <-->(links to the first node which is 1)

void CircularDLL::insertAfterLast (int id, string name, string email, int age)
{
	Node *newNode = new Node;
	newNode->stId = id;
	newNode->stName = name;
	newNode->stEmail = email;
	newNode->stAge = age;

	if (top == NULL)
	{
		top = newNode;
		return;
	}
	if (top->prev == top) // Only one node in the list
	{
		top->next = newNode;
		top->prev = newNode;
		newNode->next = top;
		newNode->prev = top;
	}
	else // More than one node
	{
		newNode->prev = top->prev;
		top->prev->next = newNode;
		top->prev = newNode;
		newNode->next = top; // Or if you want, top->prev->next..
	}
}
//--------------------------------------------
//--------------------------------------------
// creates a node and insert the node on the bottom of the
// linked list before the last node. For example if the
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 6 <--> (links to the first node which is 1)
// after inserting 10, we should get:
// list constains 1 <--> 20 <-->13 <--> 4 <--> 5 <--> 10 <--> 6 <--> (links to the first node which is 1)

void CircularDLL::insertBeforeLast (int id, string name, string email, int age)
{
	NodePtr p = new Node(id, name, email, age);
	if(top == NULL)
	{
		top = p;
		return;
	}
	NodePtr temp = top;
	
	while(temp->next != top)
		temp = temp->next;

	NodePtr tempprev = temp->prev;
	tempprev->next = p;
	p->prev = tempprev;
	p->next = temp;
	temp->prev = p;
}
//--------------------------------------------
//--------------------------------------------
// removes a node from the list based on the given student id 
void CircularDLL::remove (int id)
{
	if(top == NULL)
		return;

	if(top->next == top)
	{
		delete top;
		top = NULL;
	}

	NodePtr temp = top, tempprev = NULL;
	while(temp->next != top && temp->stId != id)
	{
		tempprev = temp;
		temp = temp->next;
	}
	tempprev->next = temp->next;
	temp->next->prev = tempprev;
	delete temp;	
}
//--------------------------------------------
//--------------------------------------------
// copies one list into another
void CircularDLL::copy (NodePtr atop, NodePtr& btop)
{
	NodePtr acurr, bcurr, bprev;
	//destroy(top2);
	if(atop->next != atop)
	{
		btop = new Node;
		btop->stId = atop->stId;
		btop->stName = atop->stName;
		btop->stEmail = atop->stEmail;
		btop->stAge = atop->stAge;

		acurr = atop;
		bcurr = btop;
		bprev = btop;
		while(acurr->next != atop)
		{
			bcurr->next = new Node;
			acurr = acurr->next;
			bcurr = bcurr->next;
			bcurr->prev = bprev;

			bcurr->stId = acurr->stId;
			bcurr->stName = acurr->stName;
			bcurr->stEmail = acurr->stEmail;
			bcurr->stAge = acurr->stAge;
			bprev = bcurr;
		}
		bcurr->next = btop;
		btop->prev = bcurr;
	}
}       
//--------------------------------------------
// deallocate the nodes in a linked list
void CircularDLL::destroy(NodePtr& top) 
{
	if(top == NULL)
		return;
	if(top->next = top)
		delete top;
	
	NodePtr tempnext = top->next, tempprev = top->prev;
	tempprev->next = tempnext;
	tempnext->prev = tempprev;
	delete top;
	top = tempnext;
}

//--------------------------------------------

int main () 
{
   CircularDLL list1;
   list1.insertDataFromFile();
   list1.print();
   list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
   list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
   list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
   list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
   list1.print();
   /*bool  found = list1.search (12321);
   if (found)
	   cout << "the record was found" << endl;
   else*/
	   cout << "\tThe record was not found" << endl << endl;
   list1.remove (54321);
   list1.print();
   										//cout << "Test" << endl; 
   CircularDLL list2(list1);
   list2.print();
   return 0;
}
//--------------------------------------------
