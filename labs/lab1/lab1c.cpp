#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 10; //global size variable for both arrays

//function prototype for passing information to an array
void fillArr(int arr[SIZE]);

//function prototype for copying array backwards
void copyR(const int arra[SIZE], int arrb[SIZE]);

//function prototype for printing any array with any size
void printArr(const int arra[SIZE], const int arrb[SIZE]);

//function prototype for finding numbers between 80 and 100
int f80100(const int arr[SIZE]);

//function prototype for finding numbers divisible by 5
int fby5(const int arr[SIZE]);

//function prototype for finding the index of numbers divisible by 5
void iby5(const int arr[SIZE]);

//function prototype for finding the average of the array
int avgArr(const int arr[SIZE]);

//function prototype for finding min value in an array
int minArr(const int arr[SIZE]);

//function prototype for finding array key
bool findKey(const int arr[SIZE]);

//Calls Functions
int main()
{
	int arr1[SIZE];
	int arr2[SIZE];

	ifstream iFile;
	iFile.open("data.txt");

	if(!iFile)
	{
		cout << "That file does not exist." << endl;
	}
	else
	{
		fillArr(arr1);
		copyR(arr1, arr2);
		printArr(arr1, arr2);
		int b2 = f80100(arr1);
		int by5 = fby5(arr1);
		iby5(arr1);
		int avg = avgArr(arr1);
		int min = minArr(arr1);
		bool find = findKey(arr1);
		
		if(find == true)
			cout << "Number found." << endl;
		else
			cout << "Number not found." << endl;
	}

	//function def findmin(const int a[]) for not altering orginal array
	//function call copyatob(const int A[], int b[]) in main for calling function to copy

	return 0;
}

//function fillArr
void fillArr(int arr[SIZE])
{
	ifstream dFile;
	dFile.open("nums.txt");

	if(!dFile)
	{
		cout << "This file does not exist." << endl;
	}
	else
	{
		for(int q = 0; q < SIZE; q++)
		{
			dFile >> arr[q];
		}
	}
	dFile.close();
}

//function copyR
void copyR(const int arra[SIZE], int arrb[SIZE])
{
	for(int k = 0, m = 9; k < SIZE; k++, m--)
	{
		arrb[m] = arra[k];
	}
}

//function printArr
void printArr(const int arra[SIZE], const int arrb[SIZE])
{
	for(int l = 0; l < SIZE; l++)
	{
		cout << arra[l] << " ";
	}
	cout << endl;
	
	for(int v = 0; v < SIZE; v++)
	{
		cout << arrb[v] << " ";
	}
	cout << endl;
}

//function f80100
int f80100(const int arr[SIZE])
{
	int count = 0;	

	for(int b = 0; b < SIZE; b++)
	{
		if(arr[b] < 101 && arr[b] > 79)
		{
			count++;
		}
	}
	return count;
}

//function fby5
int fby5(const int arr[SIZE])
{
	int count = 0;	

	for(int b = 0; b < SIZE; b++)
	{
		if(arr[b] % 5 == 0)
		{
			count++;
		}
	}
	return count;
}

//function iby5
void iby5(const int arr[SIZE])
{
	int temp;
	for(int f = 0; f < SIZE; f++)
	{
		if(arr[f] % 5 == 0)
		{
			cout << "The value at index " << f << " is divisible by 5." << endl;
		}
	}
}

//function avgArr
int avgArr(const int arr[SIZE])
{
	int sum = 0;

	for(int b = 0; b < SIZE; b++)
	{
		sum += arr[b];
	}
	sum /= SIZE;
	return sum;
}

//function minArr
int minArr(const int arr[SIZE])
{
	int min = arr[0];
	
	for(int b = 0; b < SIZE-1; b++)
	{
		if(arr[b] > arr[b+1])
		{
			min = arr[b+1];
		}
	}
	return min;
}

//function findKey
bool findKey(const int arr[SIZE])
{
	bool yes = false;
	int val;	

	cout << "Please enter a value and I will see if it exists in an array." << endl;
	cin >> val;

	if(val < SIZE)
	{
		yes = true;
	}
	return yes;
}
