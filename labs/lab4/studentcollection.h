#ifndef STUDENTCOLLECTION_H
#define STUDENTCOLLECTION_H

#include<vector>
using namespace std;
#include "profile.h"

//class of StudentCollection
class StudentCollection
{
	private:
	vector<StudentProfile> collection;
	public:
	void PrintCollections();
	void GetInfo();
};
#endif
