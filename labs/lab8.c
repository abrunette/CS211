#include <iostream>
#include <vector>
using namespace std;

bool gcd(int);
int getN();
int fibonacci(int);

int main()
{
	int num = 0;
	bool result = false;
	
	while(num > -1)
	{
	int num = getN();
	if (num < 0)
	{
		cout << "(*Thanks - Have a good Day*)\n";
		return 0;
	}
	else if((isdigit(num)))
	{
		cout << "You have entered an invalid value! Ending program!\n";
	}
	else
	{
		result = gcd(num);
	}

	if(result == true)
	{
		cout << "Yes, you got it, " << num << " is a Fibonacci number\n";
	}
	else
		cout << "!!!!! Sorry " << num << " is not a Fibonacci number\n";
	}
	return 0;
}

bool gcd(int num)
{
	int n = 0;
	while(true)
	{
		int z = fibonacci(n);
		if(z == num)
			return true;
		
		else if(z > num)
			return false;

		n++;
	}	
}

int getN()
{
	int n;
	cout << "Enter a number (enter a negative number to quit): ";
	cin >> n;
	cout << endl;
	return n;
}

int fibonacci(int n)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	
	int a = fibonacci(n - 1);
	int b = fibonacci(n - 2);

	return (a + b);
}
