#include<iostream>
#include "profile.h"

void StudentProfile::SetAProfile(long social, string firstN, string lastN, int anos, char yes, long StNo, long c1Num, string c1Name, long c2Num, string c2Name, long c3Num, string c3Name)
{
	PersonalInfo.SetAPerson(social, firstN, lastN, anos, yes);
	StdInfo.SetAStudent(StNo, c1Num, c1Name, c2Num, c2Name, c3Num, c3Name);
}

void StudentProfile::PrintAProfile()
{
	PersonalInfo.PrintAPerson();
	StdInfo.PrintAStudent();
}
