//Day 1: Part 1 - Advent of Code 2019
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream readFromFile("inputDay1.txt");
	vector<int> massOfModules;
	int input = 0;
	int totalFuel = 0;
	int fuelOfFuel = 0;
	int tempFuel = 0;

	while (readFromFile >> input) //read through the file until nothing is there anymore
	{
		massOfModules.push_back(input);
	}

	for (int i = 0; i < massOfModules.size(); i++)
	{
		totalFuel += massOfModules[i] / 3 - 2;
		fuelOfFuel = massOfModules[i] / 3 - 2;
		while (fuelOfFuel >= 0)
		{
			cout << "fuelOfFuel: " << fuelOfFuel << endl;
			fuelOfFuel = fuelOfFuel / 3 - 2;
			cout << "fuelOfFuel: " << fuelOfFuel << endl;
			//if (fuelOfFuel >= 0)
				tempFuel += fuelOfFuel;
			cout << "tempFuel: " << tempFuel << endl;

		}
	}

	cout << "Total Fuel Alone: " << totalFuel << endl;
	cout << "Total Fuel Actual: " << totalFuel + tempFuel << endl;


	////Range based for loop: first declare type of thing and then create variable to hold that type, next tell it where to get it
	//for (string masses : massOfModules)
	//{
	//	cout << masses << endl;
	//}
	//
	return 0;
}