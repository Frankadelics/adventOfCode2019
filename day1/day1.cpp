//Day 1 - Advent of Code 2019
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

	while (readFromFile >> input)
	{
		massOfModules.push_back(input);
	}

	for (int i = 0; i < massOfModules.size(); i++)
	{
		totalFuel += massOfModules[i] / 3 - 2;
		fuelOfFuel = massOfModules[i] / 3 - 2;
		while (fuelOfFuel >= 0)
		{
			fuelOfFuel = fuelOfFuel / 3 - 2;
			if (fuelOfFuel >= 0)
				tempFuel += fuelOfFuel;
		}
	}

	cout << "Total Fuel:" << totalFuel + tempFuel << endl;
	return 0;
}