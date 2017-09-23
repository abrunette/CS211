//Purpose: Read in family members to a linked list
//Input: Input file
//Output: Requested information on input file
//Date: 2016.05.05
//Author: Aaron Brunette
//Email: brune010@cougars.csusm.edu

#include<iostream>
#include<string>
#include"Family.h"
using namespace std;

int main()
{
	Family USAFamilies;
	USAFamilies.ReadTransactionFile();
	return 0;
}
