#ifndef PROFILE_H
#define PROFILE_H

#include <string>
using namespace std;
#include "student.h"
#include "person.h"

class StudentProfile
{
	private:
	Person PersonalInfo;
	Student StdInfo;	
	public:
	void SetAProfile(long social, string firstN, string lastN, int anos, char yes, long StNo, long c1Num, string c1Name, long c2Num, string c2Name, long c3Num, string c3Name);
	void PrintAProfile();
};

#endif
