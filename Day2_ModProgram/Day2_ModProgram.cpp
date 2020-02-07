/*
CSCI 182 - Asssignment 1
Day2_ModProgram.cpp
Manally create a Mod function for use

Kevin Wingert
v1.0 1/29/2020
*/
#include <iostream>

// Get the min value of two input values
/*int GetMinValue(int valueA, int valueB)
{
	if (valueA < valueB)
		return valueA;
	else
		return valueB;
}*/
/// <summary>
/// Finding the Modulus
/// </summary>
/// <param name="ValueA"></param>
/// <param name="ValueB"></param>
/// <returns></returns>
/*int Mod1(int ValueA, int ValueB)
{
	int ValueC = ValueA / ValueB;
	int Mod = ValueA - (ValueC * ValueB);
	return Mod;
}

int Mod2(int a, int b)
//Subtracting second value from first value to find the modulus 

	{
		if (b != 0)
			{
			while (a >= a)
			{
				int c = a - b;
				return c;
			}
		}
	}

*/



#include <Windows.h>
#include <ctime>

	CONST int NO_ITERATIONS = 10000;

	typedef long long int64; typedef unsigned long long uint64;

#include <iostream>
	using namespace std;

	// PUT YOUR TWO MOD FUNCTIONS IN HERE
	int Mod1(int ValueA, int ValueB)
	{
		if (ValueB != 0)
		{
			int ValueC = ValueA / ValueB;
			int Mod = ValueA - (ValueC * ValueB);
			return Mod;
		}
	}
	int Mod2(int a, int b)
		//Subtracting second value from first value to find the modulus 
	{
		if (a != 0)
		{
			while (a >= b)
			{
				int c = a - b;
				return c;
			}
		}
	}

	uint64 GetTimeMs64()
	{
		FILETIME ft;
		LARGE_INTEGER li;
		GetSystemTimeAsFileTime(&ft);
		li.LowPart = ft.dwLowDateTime;
		li.HighPart = ft.dwHighDateTime;

		uint64 ret = li.QuadPart;
		ret -= 116444736000000000LL; /* Convert from file time to UNIX epoch time. */
		ret /= 10000; /* From 100 nano seconds (10^-7) to 1 millisecond (10^-3) intervals */

		return ret;
	}

	int main()
	{

		double firstNo = 0.0;
		double secondNo = 0.0;
		double resultSubMethod = 0.0;
		double resultDivMethod = 0.0;
		uint64 startTime = 0.0;
		uint64 endTime = 0.0;
		uint64 nTickCountFunction1 = 0.0;
		uint64 nTickCountFunction2 = 0.0;

		std::srand(199); // use as seed for random generator

		startTime = GetTimeMs64();

		for (int i = 0; i < NO_ITERATIONS; i++)
		{
			// if (i % 10000 == 0) cout << i << endl;

			// Get random numbers between 1 - 1001 (never want 0)
			firstNo = std::rand() % 1000 + 1;
			secondNo = std::rand() % 1000 + 1;

			// PUT THE CALL TO YOUR FIRST MOD FUNCTION HERE
			Mod1(firstNo, secondNo);
		}
		// Get the End time + add it to our counter
		endTime = GetTimeMs64();
		nTickCountFunction1 = endTime - startTime;


		std::srand(199); // use as seed for random generator
		startTime = GetTimeMs64();
		for (int i = 0; i < NO_ITERATIONS; i++)
		{
			// if (i % 10000 == 0) cout << i << endl;

			// Get random numbers between 1 - 1001 (never want 0)
			firstNo = std::rand() % 1000 + 1;
			secondNo = std::rand() % 1000 + 1;

			// PUT THE CALL TO YOUR SECOND MOD FUNCTION HERE
			Mod2(firstNo, secondNo);
		}
		endTime = GetTimeMs64();
		nTickCountFunction2 = endTime - startTime;

		std::cout << "\t\tMethod 1" << "\tMethod 2" << "\n";
		std::cout << "Total Count:\t" << NO_ITERATIONS << "\t\t" << NO_ITERATIONS << "\n";
		std::cout << "Total Time:\t" << nTickCountFunction1 << "ms\t\t" << nTickCountFunction2 << "ms\n";

		return 0;
	}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// std::cout << "Hello World!\n";

/*int valueA = 400;
int valueB = 220;

int a = 7;
int b = 3;

// find the minimum value and pretty print it to the screen
std::cout << "Min Value: " << GetMinValue(valueA, valueB) << "\n";
std::cout << "Modulus: " << Mod1(valueA, valueB) << "\n";
std::cout << "Mod2: " << Mod2(a, b) << "\n";*/
