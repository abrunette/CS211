#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//finds the maximum value.

int CalculateMax(int g1, int g2, int g3)
{
	int max = 0;

	if(g1 > g2)
	{
		max = g1;
		if(g3 > max)
		{
			max = g3;
		}
	}
	else
	{
		max = g2;
		if(g3 > max)
		{
			max = g3;
		}
	}
	return max;
}

int CalculateMin(int g1, int g2, int g3)	
{
	int min = 0;
	if(g1 < g2)
	{
		min = g1;
		if(g3 < min)
		{
			min = g3;
		}
	}
	else
	{
		min = g2;
		if(g3 < min)
		{
			min = g3;;
		}
	}
	return min;
}

double CalculateAvg(int g1, int g2, int g3)
{
	double avg = 0;
	avg = (g1 + g2 + g3);
	avg /= 3.0;
	return avg;
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
			min = CalculateMin(f1, f2, f3);
			max = CalculateMax(f1, f2, f3);
			avg = CalculateAvg(f1, f2, f3);
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
