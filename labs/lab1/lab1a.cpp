#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//finds the min, max, and average value of values.

void ProcessARow(int g1, int g2, int g3, double &avgO, int &minO, int &maxO)
{
	//find max
	if(g1 > g2)
	{
		maxO = g1;
		if(g3 > maxO)
		{
			maxO = g3;
		}
	}
	else
	{
		maxO = g2;
		if(g3 > maxO)
		{
			maxO = g3;
		}
	}
	
	//find min
	if(g1 < g2)
	{
		minO = g1;
		if(g3 < minO)
		{
			minO = g3;
		}
	}
	else
	{
		minO = g2;
		if(g3 < minO)
		{
			minO = g3;;
		}
	}
	
	//find avg
	double hold = (g1 + g2 + g3);
	avgO = hold / 3.0;
}



//Opens file and reads data to values. Calls function, displays information from function.

int main()
{
	int id, f1, f2, f3;
	int min = 0;
	int max = 0;
	double avg = 0.0;

	ifstream gFile;
	gFile.open("grades.txt");	

	if(!gFile)
	{
		cout << "This file does not exist." << endl;
	}
	else
	{
		gFile >> id >> f1 >> f2 >> f3;
		
		cout << "Std-Id" << setw(10) << "A1" << setw(7) << "A2" << setw(7) << "A3" << setw(7) << "Min" << setw(7) << "Max" << setw(10) << "Average"<< setw(7)  << endl;
		cout << "----------------------------------------------------------------------" << endl;

		while(gFile)
		{
			ProcessARow(f1, f2, f3, avg, min, max);
			cout << id << setw(10) << f1 
			     << setw(7) << f2 
			     << setw(7) << f3 
			     << setw(7) << min 
			     << setw(7) << max 
			     << setw(7) << setprecision(1) << fixed << avg << endl;

			gFile >> id >> f1 >> f2 >> f3;	
		}
	}

	return 0;
}
