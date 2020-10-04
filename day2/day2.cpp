//Day 2 - Advent of Code 2019
/*
	Rules:
	99 - End the program
	1  - Add two numbers together from two positions that follow
	2  - Multiply two numbers togther from two positions that follow
	
	Example:
	[1, 10, 20, 30]
	1. Will add 10 and 20 and store the result in location 30
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void printFancy(vector<int>& codes)
{
	for (int i = 0; i < codes.size(); i++)
	{
		cout << codes[i] << ", ";
		if ((i + 1) % 4 == 0)
		{
			cout << endl << endl;
		}

	}
}
void printNormal(vector<int>& codes)
{
	for (int i = 0; i < codes.size(); i++)
	{
		cout << codes[i] << endl;
	}
}
void getAOCInput(vector<int>& codes)
{
	string input;
	ifstream readFromFile("inputDay2.txt");
	while (getline(readFromFile, input, ','))
	{
		codes.push_back(stoi(input));
	}
}
void getdebugInputs(vector<int>& codes)
{
	codes.push_back(1);
	codes.push_back(9);
	codes.push_back(10);
	codes.push_back(3);
	codes.push_back(2);
	codes.push_back(3);
	codes.push_back(11);
	codes.push_back(0);
	codes.push_back(99);
	codes.push_back(30);
	codes.push_back(40);
	codes.push_back(50);
	//codes.push_back(oof);
}


int main()
{
	vector<int> opcode;

	//getdebugInputs(opcode);		//Get custom inputs I have selected
	getAOCInput(opcode);		//Get the inputs I was given
	
	int firstPos = 0;
	int secondPos = 0;
	int storeResult = 0;
	int result = 0;

	//printFancy(opcode);
	for (int i = 0; i < opcode.size(); i++)
	{
		cout << opcode[i] << endl;
		if (opcode[i] == 1)
		{
			firstPos = opcode[i + 1];
			secondPos = opcode[i + 2];
			storeResult = opcode[i + 3];

			result = opcode[firstPos] + opcode[secondPos];
			opcode[storeResult] = result;
			i += 3;
		}
		else if(opcode[i] == 2)
		{
			firstPos = opcode[i + 1];
			secondPos = opcode[i + 2];
			storeResult = opcode[i + 3];

			result = opcode[firstPos] * opcode[secondPos];
			opcode[storeResult] = result;
			i += 3;
		}
		else if (opcode[i] == 99)
		{
			break;
		}
		else
			cout << "I don't know how we managed to get here." << endl;
	}

	cout << endl;
	//Debug stuff
	printFancy(opcode);
	//printNormal(opcode);

	return 0;
}