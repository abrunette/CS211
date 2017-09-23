#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	string act, dat;
	int loc;

	vector<string>V;

	ifstream iFile;
	iFile.open("data2.txt");
	
	if(!iFile)
	{
		cout << "This file does not exist.\n";
	}
	else
	{
		iFile >> act;
		while(iFile)
		{	

			if(act == "Insert")
			{
				iFile >> dat >> loc;
				if(loc > (V.size()))
				{
					cout << "Error inserting at " << loc << endl;
				}
				else				
				{
					V.insert(V.begin()+loc, dat);
				}
			}
			else if(act == "Delete")
			{
				iFile >> loc;
				if(loc > (V.size()-1))
				{
					cout << "Error deleting at " << loc << endl;
				}
				else
				{
					V.erase(V.begin()+loc);
				}
			}	
			else if(act == "Print")
			{
				for(int i  = 0; i < V.size(); i++)
				{
					cout << V[i] << endl;
				}
			}
			iFile >> act;
		}
	}
}
