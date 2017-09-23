/*********************Program Header*****************************/
/*Purpose: To initialize a class and call the first function.   */
/*Input: Uses the Dictionary.h file				*/
/*Output: None							*/
/*Date: 2016.03.29						*/
/*Author: Aaron Brunette					*/
/****************************************************************/

#include "Dictionary.h"
using namespace std;

int main()
{
	Dictionary  DictForCS211;		//initializes a new class called DictForCS211
	DictForCS211.ProcessTransactionFile();	//calls method of class Dictionary
	return 0;
}
