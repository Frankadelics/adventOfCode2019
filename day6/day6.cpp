//Day 6 - Advent of Code 2019
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void getInput(vector<string>& orbits, string file)
{
	string input;
	ifstream readFromFile(file);
	while (readFromFile >> input)
		orbits.push_back(input);
}
void printInputs(vector<string>& orbits)
{
	for (int i = 0; i < orbits.size(); i++)
		cout << i << ". " << orbits[i] << endl;
}

int main()
{
	vector<string> orbits;
	getInput(orbits, "day6Inputs.txt");
	printInputs(orbits);
	
	return 0;
}