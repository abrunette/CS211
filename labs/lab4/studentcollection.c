#include<iostream>
#include<fstream>
using namespace std;

#include "studentcollection.h"

void StudentCollection::PrintCollections()
{
	for(int i = 0; i<collection.size();i++)
	{
		cout << "Informantion about Student: " << i << endl;
		cout << "-------------------------------------" << endl;
		collection[i].PrintAProfile();
		cout << endl << endl;
	}
}

void StudentCollection::GetInfo()
{
	long social, StNo, c1Num, c2Num, c3Num;
	int anos;
	char yes;
	string firstN, lastN, c1Name, c2Name, c3Name;
	ifstream iFile;
	iFile.open("students.txt");
	iFile >> social >> firstN >> lastN >> anos >> yes >> StNo  >> c1Num >> c1Name >> c2Num >> c2Name >> c3Num >> c3Name;
	while(iFile)
	{
		StudentProfile new_entry;
		new_entry.SetAProfile(social, firstN, lastN, anos, yes, StNo, c1Num, c1Name, c2Num, c2Name, c3Num, c3Name);
		collection.push_back(new_entry);
		iFile >> social >> firstN >> lastN >> anos >> yes >> StNo  >>c1Num >> c1Name >> c2Num >> c2Name >> c3Num >> c3Name;
	}
	iFile.close();
}
